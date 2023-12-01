#include "restaurants.h"

//constrctors
restaurants::restaurants()
	:resturant_id(0), name(""), address(""), city(""), country(""), country_code(0),
	dishes(new cuisines()), food_price_range(0), has_table_booking("no"), has_online_delivery("no"), has_switch_to_order_menu("no"),
	avg_rating(0.0), votes(0)
{
}

restaurants::restaurants(int id, const std::string& name, const std::string& address, const std::string& city, const std::string& country, int country_code, std::vector<std::string>& cuisine_list, int price_range, const std::string& table_book, const std::string& online_del, const std::string& switch_menu, double avg_rate, int votes)
	:resturant_id(id), name(name), address(address), city(city), country(country), country_code(country_code), 
	 dishes(new cuisines(cuisine_list)), food_price_range(price_range), has_table_booking(table_book), has_online_delivery(online_del), has_switch_to_order_menu(switch_menu),
	 avg_rating(avg_rate), votes(votes)
{
}
restaurants::~restaurants()
{
}
//constructors ends

//setter
void restaurants::set_rest_info(int id, const std::string& name, const std::string& address, const std::string& city, const std::string& country, int country_code)
{
	this->resturant_id = id;
	this->name = name;
	this->address = address;
	this->city = city;
	this->country = country;
	this->country_code = country_code;
}

void restaurants::set_rest_perf_cuisines(const std::vector<std::string>& food_list)
{
	this->dishes->add_cuisine_list(food_list);
}

void restaurants::set_rest_price_range(int price_range)
{
	this->food_price_range = price_range;
}

void restaurants::set_rest_features(const std::string& table_book, const std::string& online_delivery, const std::string& switch_to_order)
{
	this->has_table_booking = table_book;
	this->has_online_delivery = online_delivery;
	this->has_switch_to_order_menu = switch_to_order;
}

void restaurants::load_rating(double avg_rate, int votes)
{
	this->avg_rating = avg_rate;
	this->votes = votes;
}
void restaurants::set_review_and_rating(std::vector <std::pair<std::pair<std::string, std::string>, std::pair<int, double>>>& all_reviews_and_ratings)
{
	this->reviews_and_ratings = all_reviews_and_ratings;
}
//setter end


bool restaurants::update_avg_rating(sqlite3* db, double added_rate)
{
	

	if (!(added_rate >= 0 && added_rate <= 5)) {
		return false;
	}
	int newVotes = this->votes + 1;
	double newRating = ((this->avg_rating * this->votes) + added_rate) / newVotes;
	

	char* err_msg;
	std::string sql_cmd = "UPDATE restRatings SET avgRate = '" + std::to_string(newRating) + "', votes = " + std::to_string(newVotes) + " WHERE rest_id = " + std::to_string(this->resturant_id) + ";";
	int err_code = sqlite3_exec(db, sql_cmd.c_str(), NULL, NULL, &err_msg);
	
	if (err_code != SQLITE_OK) {
		std::cerr << err_msg << std::endl;
		return false;
	}

	return true;
}

int restaurants::get_id()
{
	return this->resturant_id;
}

std::string restaurants::get_name()
{
	return this->name;
}

double restaurants::get_avg_rate()
{
	return this->avg_rating;
}

std::string restaurants::get_has_table_booking()
{
	return this->has_table_booking;
}

std::string restaurants::get_has_online_delivery()
{
	return this->has_online_delivery;
}

std::string restaurants::get_has_switch_menu()
{
	return this->has_switch_to_order_menu;
}

std::vector<std::pair<std::pair<std::string, std::string>, std::pair<int, double>>> restaurants::get_reviews()
{
	return this->reviews_and_ratings;
}


void restaurants::search_rest_and(const HANDLE& hout, restaurants& rest, const std::string& for_what)
{
	
	bool for_info_display = (to_lower_case(for_what).compare("-di") == 0); //displaying restaurant info
	bool for_review_and_rating = (to_lower_case(for_what).compare("-rvrt") == 0);   //review and rating
	bool for_check_in = (to_lower_case(for_what).compare("-ci") == 0); //check in
	bool for_favourite = (to_lower_case(for_what).compare("-fv") == 0); //add favourites
	bool for_view_review = (to_lower_case(for_what).compare("-vr") == 0); //view review

	if (for_info_display) {
		cls_and_draw_outline(hout, 15, 11, "Search Restaurant", "*", 15);
	}
	else if (for_review_and_rating) {
		cls_and_draw_outline(hout, 15, 11, "Rate and Review Restaurant", "*", 15);
	}
	else if (for_check_in) {
		cls_and_draw_outline(hout, 15, 11, "Check In", "*", 15);
	}
	else if (for_favourite) {
		cls_and_draw_outline(hout, 15, 11, "Add to Favourites", "*", 15);
	}
	else if (for_view_review) {
		cls_and_draw_outline(hout, 15, 11, "Reviews", "*", 15);
	}
	else {
		clear_screen(hout);
		std::cerr << "Restaurant Search: Flag Error" << std::endl;
	}
	show_cursor(hout, TRUE);

	center_allign_text_print(hout, "******INSTRUCTIONS******\n", 15);

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hout, &csbi);
	std::string rest_name;
	int no_of_try = 0;

	sqlite3* db = open_db("restaurants_info.db");
	while (true) {
		move_cursor_off_left_edge_and_print(hout, "Restaurant Name? ", (no_of_try >= 1) ? 4 : 15);
		clear_current_line(hout);
		std::getline(std::cin, rest_name);

		if (does_resturant_exist(db, rest_name) || to_lower_case(rest_name).compare("back") == 0) {
			break;
		}
		no_of_try++;
		goto_xy(hout, csbi.dwCursorPosition.X, csbi.dwCursorPosition.Y);
	}

	if (to_lower_case(rest_name).compare("back") != 0) {
		if (for_info_display) {
			display_resturant_info(hout, db, rest, rest_name);
		}
		else if (for_view_review) {
			display_resturant_reviews(hout, db, rest, rest_name);
		}
		else {
			load_restaurant_info(db, rest_name, rest);
		}
	}
	
	sqlite3_close(db);

}

void restaurants::display_resturant_info(const HANDLE& hout, sqlite3* db, restaurants& rest, const std::string& rest_name)
{

	if (!load_restaurant_info(db, rest_name, rest)) {
		move_cursor_off_left_edge_and_print(hout, "Restaurant Not Found In Our Record\n", 4);
	}
	cls_and_draw_outline(hout, 15, 11, "Restaurant Info", "*", 15);

	move_cursor_off_left_edge_and_print(hout, "Restaurant Name: " + rest.name + "\n", 15);
	move_cursor_off_left_edge_and_print(hout, "Address: " + rest.address + "\n", 15);
	move_cursor_off_left_edge_and_print(hout, "City: " + rest.city + "\n", 15);
	move_cursor_off_left_edge_and_print(hout, "Country: " + rest.country + "\n", 15);
	move_cursor_off_left_edge_and_print(hout, "Has online table booking?: " + rest.has_table_booking + "\n", 15);
	move_cursor_off_left_edge_and_print(hout, "Has online delivery?: " + rest.has_online_delivery + "\n", 15);
	move_cursor_off_left_edge_and_print(hout, "Has switch to order menu?:: " + rest.has_switch_to_order_menu + "\n", 15);

	move_cursor_off_left_edge(hout);
	print_line_with_color(hout, "Average Rating: ", 15);
	std::cout << std::fixed;
	std::cout << std::setprecision(2);
	std::cout << rest.avg_rating << std::endl;

	move_cursor_off_left_edge_and_print(hout, "Votes: " + std::to_string(rest.votes), 15);
	std::cout << std::endl;

	std::vector<std::string> rest_cuisine_list = rest.dishes->get_cuisines();
	center_allign_text_print(hout, "***************Available Cuisines*********************\n", 15);
	for (size_t i = 0; i < rest_cuisine_list.size(); i++) {
		center_allign_text_print(hout, rest_cuisine_list[i], 15);
		std::cout << std::endl;
	}
	freeze_display(hout);
}

void restaurants::display_resturant_reviews(const HANDLE& hout, sqlite3* db, restaurants& rest, const std::string& rest_name)
{
	if (!load_restaurant_info(db, rest_name, rest)) {
		move_cursor_off_left_edge_and_print(hout, "Restaurant Not Found In Our Record\n", 4);
	}

	clear_screen(hout, 15, 11);
	create_screen_outline(hout, "Lastest Reviews at most 8", "*", 15);
	goto_xy(hout, 0, 3);

	std::vector <std::pair<std::pair<std::string, std::string>, std::pair<int, double>>> rating_reviews = rest.get_reviews();

	std::string user_who_rated;
	
	for (size_t i = 0; i < rating_reviews.size(); i++) {
		user_who_rated = get_reviewer_name(db, rating_reviews[i].second.first);
		std::string user_rating(std::to_string(rating_reviews[i].second.second), 0, 4);
		center_allign_text_print(hout, to_upper_case(user_who_rated) + " on " + rating_reviews[i].first.second + " ,Rated " +  user_rating + " and Reviewed:\n", 15);
		center_allign_text_print(hout, rating_reviews[i].first.first + "\n", 7);
		std::cout << std::endl;
	}
	freeze_display(hout);
}

//method and helper to display k resturant
void restaurants::display_top_k(sqlite3* db, unsigned int k)
{

	char* err_msg;
	std::string sql_cmd = "SELECT restName, city, avgRate FROM restAddressInfo \
						   INNER JOIN restRatings ON restAddressInfo.rest_id = restRatings.rest_id \
						   WHERE avgRate > 4.5 AND votes > 2000 \
						   ORDER BY avgRate DESC LIMIT "  + std::to_string(k) + ";";

	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	
	//creating the top kresturants table column names
	std::cout << std:: endl;

	move_cursor_off_left_edge_and_print(hout, "***************************** Highly Rated Restaurants ************************\n", (0 + 9 * 16));
	move_cursor_off_left_edge_and_print(hout, "Retaurant Name", (0 + 15 * 16));
	set_cursor_at_middle_and_print(hout, "Location", (0 + 12 * 16));
	set_cursor_near_right_and_print(hout, "Rating\n", (0 + 15 * 16));
	std::cout << std::endl;
	//top k resturant table column creation completed
	
	SetConsoleTextAttribute(hout, 15);
	int err_code = sqlite3_exec(db, sql_cmd.c_str(), display_top_k_callback, NULL, &err_msg);
	if (err_code != SQLITE_OK) {
		std::cerr << err_msg << std::endl;
	}
}
int restaurants::display_top_k_callback(void* not_used, int argc, char** argv, char** azColName)
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	
	for (int i = 0; i < argc; i++)
	{
		if (i == 0) {
			move_cursor_off_left_edge_and_print(hout, (std::string)argv[i], (0 + 15 * 16));
		}
		else if (i == 1) {
			set_cursor_at_middle_and_print(hout, (std::string)argv[i], (0 + 12 * 16));
		}
		else{
			std::string user_rating(argv[i], 0, 4);
			set_cursor_near_right_and_print(hout, user_rating, (0 + 15 * 16));
		}
	}
	std::cout << std::endl;
	SetConsoleTextAttribute(hout, 15);
	return 0;
}
//method and helper to display k resturant ends
std::string restaurants::get_reviewer_name(sqlite3* db, int reviewer_id)
{
	char* err_msg;
	std::string reviewer_full_name;
	std::string sql_cmd = "SELECT first_name, last_name FROM user_info INNER JOIN restReviews ON user_info.id = restReviews.userId WHERE userId = " + std::to_string(reviewer_id) + ";";
	int err_code = sqlite3_exec(db, sql_cmd.c_str(), get_reviewer_name_callback, &reviewer_full_name, &err_msg);
	if (err_msg != SQLITE_OK) {
		std::cerr << err_msg << std::endl;
	}
	return reviewer_full_name;
}
int restaurants::get_reviewer_name_callback(void* memory_to_hold_name, int argc, char** argv, char** azColName)
{
	std::string* name = static_cast<std::string*>(memory_to_hold_name);
	std::stringstream full_name;
	full_name << argv[0] << " " << argv[1];
	*name = full_name.str();

	return 0;
}

//method and helper to find the no of retaurant with the given name in db
unsigned int restaurants::number_of_rest(sqlite3* db, const std::string& restaurant_name)
{
	unsigned int no_of_rest;
	char* err_msg;
	int err_code;

	std::string sql_cmd = "SELECT count(rest_id) FROM restAddressInfo WHERE restName = \"" + restaurant_name + "\";";

	err_code = sqlite3_exec(db, sql_cmd.c_str(), rest_no_callback, &no_of_rest, &err_msg);
	if (err_msg != SQLITE_OK) {
		std::cerr << err_msg << std::endl;
	}

	return no_of_rest;
}
int restaurants::rest_no_callback(void* memory_to_store_rest_no, int argc, char** argv, char** azColName)
{
	int* rest_no = static_cast<int*>(memory_to_store_rest_no);
	*rest_no = std::stoi(argv[0]);
	return 0;
}
std::vector<std::string> restaurants::get_city_list(sqlite3* db, const std::string& restaurant_name)
{
	std::vector<std::string> city_list;
	char* err_msg;
	int err_code;

	std::string sql_cmd = "SELECT city FROM restAddressInfo WHERE restName = \"" + restaurant_name + "\";";

	err_code = sqlite3_exec(db, sql_cmd.c_str(), city_list_callback, &city_list, &err_msg);
	if (err_msg != SQLITE_OK) {
		std::cerr << err_msg << std::endl;
	}
	return city_list;
}

int restaurants::city_list_callback(void* memory_to_store_list, int argc, char** argv, char** azColName)
{
	std::vector<std::string>* city_list = static_cast<std::vector<std::string>*>(memory_to_store_list);
	city_list->emplace_back(argv[0]);
	return 0;
}

//method to know wether a resturant exists
bool restaurants::does_resturant_exist(sqlite3* db, const std::string& restaurant_name)
{
	std::string sql_search_cmd = "SELECT rest_id FROM restAddressInfo WHERE restName = \"" + restaurant_name + "\";";
	return does_entity_exist(db,sql_search_cmd);
}

//methods and helpers that loads the given resturant into a resturants object 
bool restaurants::load_restaurant_info(sqlite3* db, const std::string& rest_name, restaurants& rest_to_load)
{
	if (!does_resturant_exist(db, rest_name)) {
		return false;
	}
	
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	char* err_msg;
	int err_code;

	std::string load_rest_info;

	load_rest_info = "SELECT rest_id, restName, address, city, country.name, restAddressInfo.countryCode FROM restAddressInfo "
						 "INNER JOIN country ON country.countryCode = restAddressInfo.countryCode "
						 "WHERE restName = \"" + rest_name + "\";";

	err_code = sqlite3_exec(db, load_rest_info.c_str(), load_rest_info_callback, &rest_to_load, &err_msg);
	if (err_code != SQLITE_OK) {
		std::cerr << err_msg << std::endl;
	}


	std::string load_rest_cuisine_list;
	load_rest_cuisine_list = "SELECT cuisine FROM restFoodTypes WHERE rest_id = " + std::to_string(rest_to_load.resturant_id) + ";";
	std::vector<std::string> cuisine_list;
	err_code = sqlite3_exec(db, load_rest_cuisine_list.c_str(), load_cuisines_callback, &cuisine_list, &err_msg);
	if (err_code != SQLITE_OK) {
		std::cerr << err_msg << std::endl;
	}
	rest_to_load.set_rest_perf_cuisines(cuisine_list);

	std::string load_price_range;
	load_price_range = "SELECT priceRange FROM restPriceRange WHERE rest_id = " + std::to_string(rest_to_load.resturant_id) + ";";
	err_code = sqlite3_exec(db, load_price_range.c_str(), load_rest_price_range_callback, &rest_to_load, &err_msg);
	if (err_code != SQLITE_OK) {
		std::cerr << err_msg << std::endl;
	}

	std::string load_rest_feat;load_rest_feat = "SELECT hasTableBookingooking, hasOnlineDelivery, switchToOrderMenu FROM restFeatures WHERE rest_id = " + std::to_string(rest_to_load.resturant_id) + ";";
	err_code = sqlite3_exec(db, load_rest_feat.c_str(), load_rest_features_callback, &rest_to_load, &err_msg);
	if (err_code != SQLITE_OK) {
		std::cerr << err_msg << std::endl;
	}

	std::string load_rest_rate;
	load_rest_rate = "SELECT avgRate, votes FROM restRatings WHERE rest_id = " + std::to_string(rest_to_load.resturant_id) + ";";
	err_code = sqlite3_exec(db, load_rest_rate.c_str(), load_rest_rating_callback, &rest_to_load, &err_msg);
	if (err_code != SQLITE_OK) {
		std::cerr << err_msg << std::endl;
	}	
	
	std::vector <std::pair<std::pair<std::string, std::string>, std::pair<int, double>>> all_reviews;
	std::string load_reviews_and_rate;
	load_reviews_and_rate = "SELECT review, reviewTime, userId, userRate FROM restReviews WHERE rest_id = " + std::to_string(rest_to_load.resturant_id) + " "
								"ORDER BY reviewTime DESC LIMIT 5;";
	err_code = sqlite3_exec(db, load_reviews_and_rate.c_str(), load_rest_review_callback, &all_reviews, &err_msg);
	rest_to_load.set_review_and_rating(all_reviews);

	return true;
}

int restaurants::load_rest_info_callback(void* memory_to_store_rest_obj, int argc, char** argv, char** azColName)
{
	restaurants* rest_to_load = static_cast<restaurants*>(memory_to_store_rest_obj);
	rest_to_load->set_rest_info(std::stoi(argv[0]), argv[1], argv[2], argv[3], argv[4], std::stoi(argv[5]));
	return 0;
}

int restaurants::load_cuisines_callback(void* memory_to_store_cuisine, int argc, char** argv, char** azColName)
{
	std::vector<std::string>* cuisine_list = static_cast<std::vector<std::string>*>(memory_to_store_cuisine);
	cuisine_list->emplace_back(argv[0]);
	return 0;
}

int restaurants::load_rest_price_range_callback(void* memory_to_store_rest_obj, int argc, char** argv, char** azColName)
{
	restaurants* rest_to_load = static_cast<restaurants*>(memory_to_store_rest_obj);
	rest_to_load->set_rest_price_range(std::stoi(argv[0]));
	return 0;
}

int restaurants::load_rest_features_callback(void* memory_to_store_rest_obj, int argc, char** argv, char** azColName)
{
	restaurants* rest_to_load = static_cast<restaurants*>(memory_to_store_rest_obj);
	rest_to_load->set_rest_features(argv[0], argv[1], argv[2]);
	return 0;
}

int restaurants::load_rest_rating_callback(void* memory_to_store_rest_obj, int argc, char** argv, char** azColName)
{
	restaurants* rest_to_load = static_cast<restaurants*>(memory_to_store_rest_obj);
	rest_to_load->load_rating(std::stod(argv[0]), std::stoi(argv[1]));
	return 0;
}

int restaurants::load_rest_review_callback(void* memory_to_store_reviews, int argc, char** argv, char** azColName)
{

	
	std::vector <std::pair<std::pair<std::string, std::string>, std::pair<int, double>>>* reviews_list = static_cast<std::vector<std::pair<std::pair<std::string, std::string>, std::pair<int, double>>>*>(memory_to_store_reviews);
	
	std::pair<std::string, std::string> time_and_review;
	std::pair<int, double> user_id_and_rate;

	time_and_review.first = argv[0];
	time_and_review.second = argv[1];
	user_id_and_rate.first = std::stoi(argv[2]);
	user_id_and_rate.second = std::stod(argv[3]);


	std::pair<std::pair<std::string, std::string>, std::pair<int, double>> review_total_info;
	review_total_info.first = time_and_review;
	review_total_info.second = user_id_and_rate;

	reviews_list->emplace_back(review_total_info);
	return 0;
}
//methods and helpers that loads the given resturant into a resturants object ends