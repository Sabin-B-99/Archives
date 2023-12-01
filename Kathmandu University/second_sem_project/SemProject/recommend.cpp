#include "recommend.h"


recommend::recommend(std::vector<std::pair<std::string, std::string>> user_fav_rests_list)
    :user_fav_list(user_fav_rests_list)
{
}

std::vector<std::pair<std::string, std::string>> recommend::give_recommendations()
{

    sqlite3* db = open_db("restaurants_info.db");
    std::vector<std::pair<std::string, std::string>> recommendations;
    restaurants top_restaurant = user_fav_top_rest();

    int err_code;
    char* err_msg;
    std::string sql_cmd = "SELECT restName, city FROM restAddressInfo INNER JOIN restFeatures ON restAddressInfo.rest_id = restFeatures.rest_id "
        "INNER JOIN restRatings ON restFeatures.rest_id = restRatings.rest_id "
        "WHERE restFeatures.hasOnlineDelivery = \"" + top_restaurant.get_has_online_delivery() + "\" AND restFeatures.hasTableBookingooking = \"" + top_restaurant.get_has_table_booking() +
        "\" AND restFeatures.switchToOrderMenu = \"" + top_restaurant.get_has_switch_menu() +
        "\" AND restAddressInfo.rest_id <> " + std::to_string(top_restaurant.get_id()) + " AND restRatings.avgRate >= " + std::to_string(top_restaurant.get_avg_rate() - 1) +
        " ORDER BY restRatings.avgRate COLLATE NOCASE DESC LIMIT 18;";

    err_code = sqlite3_exec(db, sql_cmd.c_str(), recommend_callback, &recommendations, &err_msg);

    if (err_code != SQLITE_OK) {
        std::cerr << err_msg << std::endl;
        exit(0);
    }

    sqlite3_close(db);
    return recommendations;
}

std::vector<std::pair<std::string, std::string>> recommend::give_recommendations(std::string user_table_pref, std::string user_online_pref, std::string user_menu_pref)
{
    sqlite3* db = open_db("restaurants_info.db");
    std::vector<std::pair<std::string, std::string>> recommendations;

    int err_code;
    char* err_msg;
    std::string sql_cmd = "SELECT restName, city FROM restAddressInfo INNER JOIN restFeatures ON restAddressInfo.rest_id = restFeatures.rest_id "
        "INNER JOIN restRatings ON restFeatures.rest_id = restRatings.rest_id "
        "WHERE restFeatures.hasOnlineDelivery = \"" + yes_no_to_Yes_No(user_online_pref) + "\" AND restFeatures.hasTableBookingooking = \"" + yes_no_to_Yes_No(user_table_pref) +
        "\" AND restFeatures.switchToOrderMenu = \"" + yes_no_to_Yes_No(user_menu_pref) +
        "\" ORDER BY restRatings.avgRate COLLATE NOCASE DESC LIMIT 18;";

    err_code = sqlite3_exec(db, sql_cmd.c_str(), recommend_callback, &recommendations, &err_msg);

    if (err_code != SQLITE_OK) {
        std::cerr << err_msg << std::endl;
        exit(0);
    }

    sqlite3_close(db);
    return recommendations;
}

restaurants recommend::user_fav_top_rest()
{
    std::vector<restaurants> fav_restuarnts_sorted;

    

    sqlite3* db = open_db("restaurants_info.db");
    for (size_t i = 0; i < user_fav_list.size(); i++)
    {
        restaurants rest;
        restaurants::load_restaurant_info(db, user_fav_list[i].first, rest);
        fav_restuarnts_sorted.push_back(rest);
        rest.~restaurants();
    }
    sort_rest_by_rate(fav_restuarnts_sorted);
    sqlite3_close(db);
    return fav_restuarnts_sorted[0];
}

void recommend::sort_rest_by_rate(std::vector<restaurants>& fav_restaurants)
{
    restaurants temp;
    int j;
    for (size_t i = 1; i < fav_restaurants.size(); i++) {
        temp = fav_restaurants.at(i);
        j = i - 1;
        while (j >= 0 && fav_restaurants[j].get_avg_rate() > temp.get_avg_rate()) {
            fav_restaurants.at(j + 1) = fav_restaurants.at(j);
            j = j - 1;
        }
        fav_restaurants.at(j + 1) = temp;
    }
}

int recommend::recommend_callback(void* memory_to_store_recommendations, int argc, char** argv, char** azColName)
{
    std::vector<std::pair<std::string, std::string>>* recommendations = static_cast<std::vector<std::pair<std::string, std::string>>*>(memory_to_store_recommendations);
    std::pair<std::string, std::string> recommended_rest_info;
    recommended_rest_info.first = argv[0];
    recommended_rest_info.second = argv[1];
    recommendations->emplace_back(recommended_rest_info);
    return 0;
}


