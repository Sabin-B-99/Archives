/*
	Author: Niranjan Pandey
			Sabin Badal

	Description:
		The restaurnt class is a representation of a restaurant.
		The private data members of a this class represents different information related to
		a restaurant. These information includes restaurnat name, its address, city and coutry
		country_code, dishes(cuisines) available, various features or services like wether a 
		restaurant has a table booking option, online delivery option, or different menu services.
		This class will help user to perform different functionalities like rating and reviewing
		resstaurants as well as storing and loading different restaurant related information
		to the database.
*/
#pragma once
#include <iostream>
#include <string>
#include "cuisines.h"
#include <sqlite3.h>
#include <stdlib.h>
#include "sqlite_wrapper.h"
#include <Windows.h>
#include "basic_functions.h"
#include <algorithm>
#include <chrono>
#include <sstream>

class restaurants {
private:
	/*
		restaurant_id is the id for each restaurant as assigned in the database.
	*/
	int resturant_id;
	/*
		name is the name of the individual restaurant
	*/
	std::string name;
	/*
		address is the location of the restaurant
	*/
	std::string	address;
	/*
		city represents the real world city in which the restaurant is located
	*/
	std::string city;
	/*
		country represents the real world country where the restaurant is loacted
	*/
	std::string country;
	/*
		country code for a restaurant is the phone code of the country where the 
		restaurant is loacted
	*/
	int country_code;

	/*
		dishes is the list of avalabe cuisines in a certain restaurant
	*/
	cuisines* dishes;
	
	/*
		ford_price_range represents the range of food prices in a certain restaurant
		It ranges form 1 to 5 where 1 means the price range is low and the restaurant is cheap 
		while 5 means the restaurant is expensive to visit. This price range is dependent in 
		local currency
	*/
	int food_price_range;
	
	/*
		three string variables below i.e,
		has_table_booking, has_oniline_delivery and has_switch_to_order_menu all 
		represents different features of a certain restaurant. They all are stored 
		in form of either yes or no in the database. 
		has_table booking represents wether a restaurant has table booking service or not.
		has_online_delivery represents wether a restaurant has online delivery service or not
		abnd has_switch to order_menu represents wether a restaurant has switch to order menu or
		not.
	*/
	std::string has_table_booking;
	std::string has_online_delivery;
	std::string has_switch_to_order_menu;
	
	/*
		avg_rating indicates the the overall average rating of the restaurant.
		It ranges from 1-5 where 5 is high and 1 is low rating
	*/
	double avg_rating;
	/*
		votes represents the total number of people who rated a ceratin restaurant.
		i.e, total number of ratings for a given restaurant is its vote. Sum of all 
		rating divided by the votes will give the avg_rating for the restaurant.
	*/
	int votes;

	/*
		reviews_and_ratings represents list of all review, review time, user id for user who rated and 
		reviewed a certain restaurant.
		This reviews_and_ratings is a vector of pair whose both elements are a pair.
		Among these two pair;
		
		The first pair is a pair whose both element is a string.
		The first string represents the restaurant review which cannot be more than 90 characters.
		And the second string represnents the string which represents the timestamp for the review.

		The second pair is a pair whose first element is an integer and the second element is a double.
		The first element an integer whic represents the user id for the user whose review represented
		by the first string in first pair(as describe above).
		The second element is a double which represents the average rating for the certain restaurant.
	*/
	std::vector <std::pair<std::pair<std::string, std::string>, std::pair<int, double>>> reviews_and_ratings;

public:
	/*
		Default constructor for the class that will initialize the class with default 
		values for its member variables. All the numeric types of the class will be
		by default initialized to 0, all the string members will be by default 
		initialized to "" (\n) and all other custom types like vector will be by 
		default initialzied to NULL.
	*/
	restaurants();

	/*
		A parameterized constructor that initializes the restaurant object accordigly to the 
		values passed into the constructor either by a user of from the database
	*/
	restaurants(int, const std::string&, const std::string&, const std::string&, const std::string&, int, std::vector<std::string>&, int, const std::string&, const std::string&, const std::string&, double, int);
	/*
		Destructor for the restaurant object
	*/
	~restaurants();
	
	/*
		set_rest_info is a setter that will initialize the following member variables of the restaurant class.
		id, name, address, city, country and country code.
		In this setter 6 arguments are passed:
		First argument is a integer which will initalize the member variable id.
		Second argument is a string which will initailze the member variable name.
		Third argument is a string which will initalize the memeber variable address
		Fourth argument is a string which will initalize the member varaible city
		Fifth argument is a string which will initalize the member varaible country
		Sixth argument is a integer which will initalize the member variable country_code.
	*/
	void set_rest_info(int, const std::string&, const std::string&, const std::string&, const std::string&, int);
	
	/*
		set_rest_perf_cuisines is a setter that will initalize the list of cuisine availabe to a certain restaurant.
		This function takes in a single argument of type vector that will initalize the member varaible dishes(cuisine type).
	*/
	void set_rest_perf_cuisines(const std::vector<std::string>& food_list);
	
	/*
		set_rest_price_range is a setter function that will initalize the food_price_range variable of 
		the classs. It takes in a single string argmnent that will set(initalize) the member variable
		food_price range as that value.
	*/
	void set_rest_price_range(int);
	
	/*
		set_rest_features is setter function that will initalize features of restaurants.
		These features include online table booking service, online delivery service and
		menu services. This function will set wether a restaurant has aforementioned services
		or not. It will take three string variables and and will respectively initalize
		has_table_booking, has_online_delivery, and has_switch_to_order_menu member 
		variables of this class. These strings should be either yes or no.
	*/
	void set_rest_features(const std::string&, const std::string&, const std::string&);

	/*
		load_rating is a setter function that will initalize the member variables avg_rating and votes.
		This function takes in two argument.
		First argument is a double type which will initialize the member varaible avg_rating
		Second argument is a double type which will initialize the member variable votes
	*/
	void load_rating(double, int);
	/*
		set_review_and_rating is a function that will initialze the list of all reviews and 
		rating of a restaurant. This function takes in a single argument of a vector type
		of a pair that contains review, review time, user id for the user who reviewed and
		rating by that user.And this passed vector will initailze the member function reviews_and_ratings
	*/
	void set_review_and_rating(std::vector <std::pair<std::pair<std::string, std::string>, std::pair<int, double>>>&);

	/*
		This function will update a average restaurant for the given restaurant.
		This function will take in two argument. 
		First argument is a sqlite3* type which is a database that contains all the information 
		regarding a certain restaurant.
		Second argument is the rating given by a user to a certain restaurant. 

		If for a certain restaurant in the database, current_avg_rating = 4 and total votes = 3; 
		If a new user_rate(added_rate as function parameter) for that restaurant with 3.5 then function will work as below:
		new_rating = (current_avg_rating * votes) + user_rate / (votes + 1)
		This new average rating will then be stored(updated) in the same database.
	*/
	bool update_avg_rating(sqlite3* db, double added_rate);

	/*
		This is a getter function that will return the id for a certain restaurant in a database.
	*/
	int get_id();
	std::string get_name();
	double get_avg_rate();
	std::string get_has_table_booking();
	std::string get_has_online_delivery();
	std::string get_has_switch_menu();

	
	/*
		This is a getter function that will return the list of reviews and ratings of a certain 
		restaurant.
	*/
	std::vector <std::pair<std::pair<std::string, std::string>, std::pair<int, double>>> get_reviews();

	/*
		The static function search_rest_and will search first search wether a given restaurant exists in the
		database or not. If the restaurant exists in the database then it will perform task according
		to the for_what flag provided as the third argument in the function parameter.
		
		This function takes in three arguments
		
		The first argument is a HANDLE  to the console screen (to read more on handle see comments in menu and
		user class or refer to win32 api documentation).This handle will be used to display search menu in the 
		console screen. This handle contains all the information of a console window like its dimensions, cursor
		positions etc.

		The second argument is a refrence to a restaurant object which wil be initalized according to 
		the information availabe in the database. This information is about the restaurant being searched.
		So, This refrence object will have all its variables initialized according to information about them
		in the database.

		the third argument is a string flag that will instruct the function on what task to perform on the 
		intialized restaurant object passed as the second argument to the function.

		These flags and task performed are as follows;

		-di  : If this flag is passed then every information like restaurant name, cuisine available etc 
			   will be displayed to the screen for the searched restaurant. Internally the function will 
			   accomplish this task by calling the private static member function display_resturant_info of 
			   this class

		-rvrt : It this flag is passed then the function will let a user rate and review the searched 
				restaurant object(in the second argument). Internally this will only load the restaurant 
				information to the second argumnet in this function. Then this initalized restaurant
				can be used while reviewing and rating the restaurant. 

		-ci   : If this flag is set then the function will load information about the searched restaurant
				to the restaurant refrence in the second argumnet. This restaurant refrence then will
				be used to add a restaurant in the user checked in list

		-fv   : If this flag is set then the function will load information about the searched restaurant
				to the restaurant refrence in the second argumnet. This restaurant refrence then will
				be used to add a restaurant in the user favourite in list 

		-vr   : If this flag is passed then the function will display all the reviews of the searched 
				restaurant to the screen.
	*/
	static void search_rest_and(const HANDLE& hout, restaurants& rest, const std::string& for_what);

	/*
		display_top_k function will display to the screen the top k restaurant from the database based on their 
		average rating. 
		
		This function takes in two argument: 
		First argument is a database that contains all the information about the restaurants
		Second argument is a positive integer which will be the number of top restaurants to 
		be dispalyed. If this number is 15 then top 15 restaurants will be displayed
		If this number is 7 then top 7 restaurants will be dispalyed.
	*/
	static void display_top_k(sqlite3*, unsigned int);

	/*
	The function load_restaurant_info will load all the information associated with a given restaurant
	from the database an initialize a restaurant object pass as refrence in the third argument of this function.

	This function takes in three arguments:
	First argument is a refrence to sqilte database which contains all the information about the given restaurant.
	Second argument is the name of a whose infromation will be loaded from the database into the restaurant object.
	Third argument is a refrence to a restaurant object where all the infroma tion about the given restaurant will be
	loaded
*/
	static bool load_restaurant_info(sqlite3* db, const std::string& rest_name, restaurants& rest_to_load);

	
	
private:

	/*
		display_restaurant function will display all the inforamtion about a restaurant to the console screen.
		
		The function takes is 4 arguments.

		The first argument is a HANDLE to the console screen on which the restaurant info is to be displayed.
		
		The second argument is a sqlite3* database in which the restaurant information exists.
		
		The third argument is a refrence to the resstaurant object in which the information about 
		restaurant will be loaded from the database.

		The fourth argument is a string which should be the name of the restaurant whose infromation
		will be loaded into the restaurant refrence passed in to the second argument.
	*/
	static void display_resturant_info(const HANDLE& hout, sqlite3* db, restaurants& rest, const std::string& restaurant_name);

	/*
		display_resturant_reviews function will display all reviews and ratings about a restaurant to the console screen.

		The function takes is 4 arguments.

		The first argument is a HANDLE to the console screen on which the restaurant reviews and rating is to be displayed.

		The second argument is a sqlite3* database in which the restaurant reviews exists.

		The third argument is a refrence to the resstaurant object in which the information about
		restaurant will be loaded from the database.

		The fourth argument is a string which should be the name of the restaurant whose infromation
		will be loaded into the restaurant refrence passed in to the second argument.
	*/
	static void display_resturant_reviews(const HANDLE& hout, sqlite3* db, restaurants& rest, const std::string& restaurant_name);

	/*
		This does_resturant_exist function checks wether a resturants exists or not in a given database.
		If the restaurant exists then the function will return true or else it will
		return false.
	*/
	static bool does_resturant_exist(sqlite3* db, const std::string& restaurant_name);

	/*
		The function display_top_k_callback is a callback function that will be used
		by the sqlite c++ interface function sqlite3_exec used inside of the 
		public member function display_top_k inorder to display top rated k number of 
		restaurants from the database
		For information about the arguments passed in the callback function refer to the 
		sqlite c/c++ interface documentation at https://sqlite.org/c3ref/exec.html
	*/
	static int display_top_k_callback(void* not_used, int argc, char** argv, char** azColName);

	/*
		The get_reviewer_name function will return the name of a user who reviewed a certain restaurant.

		This Function will take in two argument:
		First argument is a sqlite database in which user infromation is stored
		Second argument is an integer which will represent a user id in the database.
	*/
	static std::string get_reviewer_name(sqlite3* db, int reviewer_id);
	/*
		The function get_reviewer_name_callback is a callback function that will be used
		by the sqlite c++ interface function sqlite3_exec used inside of the 
		private member function get_reviewer_name get the reviewr name from the database.

		For information about the arguments passed in the callback function refer to the 
		sqlite c/c++ interface documentation at https://sqlite.org/c3ref/exec.html
	*/
	static int get_reviewer_name_callback(void* memory_to_hold_name, int argc, char** argv, char** azColName);

	/*
		This function will return the total number of restaurant available in database with same name as 
		provided as the second argument in this function.

		This function will take two arguments:
		The first argument is a sqlite database in which restaurant information is stored.
		The second argumnet is a string which reprsents the name of restaurant name.
		The total number of restaurants with the same name as the restaurant passed in 
		as the second argument in this function will be returned by this function.
	*/
	static unsigned int number_of_rest(sqlite3* db, const std::string& restaurant_name);
	/*
		The function rest_no_callback is a callback function that will be used
		by the sqlite c++ interface function sqlite3_exec used inside of the
		private member function number_of_rest get the total number of restaurant 
		that with similar name to a given restaurant. 

		For information about the arguments passed in the callback function refer to the
		sqlite c/c++ interface documentation at https://sqlite.org/c3ref/exec.html
	*/
	static int rest_no_callback(void* memory_to_store_rest_no, int argc, char** argv, char** azColName);

	/*
		This function will return a vector with all the cities in which a restarurants with similar name exists.

		This function will take two arguments:
		The first argument is a sqlite database in which restaurant information is stored.
		The second argumnet is a string which reprsents the name of restaurant name.
		
		A vector conatining name of all the cities which as a resturant with a given name will 
		be returned by this function.
		
	*/
	static std::vector<std::string> get_city_list(sqlite3* db, const std::string& restaurant_name);
	/*
		The function rest_no_callback is a callback function that will be used
		by the sqlite c++ interface function sqlite3_exec used inside of the
		private member function get_city_list to get name of all the cities
		in which a given restaurant exists.

		For information about the arguments passed in the callback function refer to the
		sqlite c/c++ interface documentation at https://sqlite.org/c3ref/exec.html
	*/
	static int city_list_callback(void* memory_to_store_list, int argc, char** argv, char** azColName);


	/*
		The function load_rest_info_callback is a callback function that will be used
		by the sqlite c++ interface function sqlite3_exec used inside of the
		private member function load_restaurant_info to information like restaurant id,
		name of the restaurant, address, city, country and country code of the restaurant
		from the database.

		For information about the arguments passed in the callback function refer to the
		sqlite c/c++ interface documentation at https://sqlite.org/c3ref/exec.html
	*/
	static int load_rest_info_callback(void* memory_to_store_rest_obj, int argc, char** argv, char** azColName);

	/*
		The function load_cuisines_callback is a callback function that will be used
		by the sqlite c++ interface function sqlite3_exec used inside of the
		private member function load_restaurant_info to load list of availabe cuisines
		in a given restaurant from the database.

		For information about the arguments passed in the callback function refer to the
		sqlite c/c++ interface documentation at https://sqlite.org/c3ref/exec.html
	*/
	static int load_cuisines_callback(void* memory_to_store_cuisine, int argc, char** argv, char** azColName);

	/*
		The function load_rest_price_range_callback is a callback function that will be used
		by the sqlite c++ interface function sqlite3_exec used inside of the
		private member function load_restaurant_info to load price range of a restaurnat 
		from the database.

		For information about the arguments passed in the callback function refer to the
		sqlite c/c++ interface documentation at https://sqlite.org/c3ref/exec.html
	*/
	static int load_rest_price_range_callback(void* memory_to_store_rest_obj, int argc, char** argv, char** azColName);
	/*
		The function load_rest_features_callback is a callback function that will be used
		by the sqlite c++ interface function sqlite3_exec used inside of the
		private member function load_restaurant_info to load features of a restaurnat
		from the database.

		For information about the arguments passed in the callback function refer to the
		sqlite c/c++ interface documentation at https://sqlite.org/c3ref/exec.html
	*/
	static int load_rest_features_callback(void* memory_to_store_rest_obj, int argc, char** argv, char** azColName);
	/*
		The function load_rest_rating_callback is a callback function that will be used
		by the sqlite c++ interface function sqlite3_exec used inside of the
		private member function load_restaurant_info to load average rating of a restaurnat
		from the database.

		For information about the arguments passed in the callback function refer to the
		sqlite c/c++ interface documentation at https://sqlite.org/c3ref/exec.html
	*/
	static int load_rest_rating_callback(void* memory_to_store_rest_obj, int argc, char** argv, char** azColName);
	/*
	The function load_rest_review_callback is a callback function that will be used
	by the sqlite c++ interface function sqlite3_exec used inside of the
	private member function load_restaurant_info to load reviews of a restaurnat
	from the database.

	For information about the arguments passed in the callback function refer to the
	sqlite c/c++ interface documentation at https://sqlite.org/c3ref/exec.html
*/
	static int load_rest_review_callback(void* memory_to_store_reviews, int argc, char** argv, char** azColName);
};