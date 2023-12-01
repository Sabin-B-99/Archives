#pragma once
#include <iostream>
#include <vector>
#include "restaurants.h"
#include "basic_functions.h"

class recommend {
private:
	std::vector<std::pair<std::string, std::string>> user_fav_list;
public:
	recommend(std::vector<std::pair<std::string, std::string>> user_fav_rest_list);
	std::vector<std::pair<std::string, std::string>> give_recommendations();
	std::vector< std::pair < std::string, std::string>>give_recommendations(std::string user_table_pref, std::string user_online_pref, std::string user_menu_pref);


private:
    restaurants user_fav_top_rest();

	void sort_rest_by_rate(std::vector<restaurants>& fav_restaurants);

	static int recommend_callback(void* memory_to_store_recommendations, int argc, char** argv, char** azColName);

};