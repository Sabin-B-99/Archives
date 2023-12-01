/*
	Author: Aditya Chaudary
			Shyarnis Ghising
	Description:
		This class contains information about a user of the 
		app. With the help of member functions of this class 
		personal infromation of users' can be manipulated. Also,
		Various functionalities like rating and reviewing
		a resturant, adding resturant to favourites etc., 
		within the app with which a user can interact can be performed 
		with the help of this class. This class can also be used to load
		users' information from the database as initialize the object.
	File: user.h
*/
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "cuisines.h"
#include "menu.h"
#include "sqlite_wrapper.h"
#include "restaurants.h"
#include "recommend.h"

class user {

protected:
	int id; //variable to hold user id as stored in database
	std::string first_name; //variable to hold user first name as stored in database
	std::string last_name; //variable to hold user last name as stored in database
	std::string address; //variable to hold user address as stored in database
	std::string city; //variable to hold user city as stored in database
	std::string country; //variable to hold user country as stored in database
	int country_code; //variable to hold user country code as stored in database
	std::string online_book; //variable to hold wether a user preference of online table booking in resturants as represented in database
	std::string online_delivery; //variable to hold wether a user preference of online delivery in resturants as represented in database
	std::string switch_menu; //variable to hold wether a user preference of resturants' menu services as represented in database
	cuisines* user_pref_cuisine; //variable that holds all the user preffered cuisines list, like Indian, Chinese, etc, as stored in database 

	/*
		This member variable below is a 
		vector(array) of a pair of strings. The first of the string on the pair
		will represent the favourite restaurant name while the second one will 
		represent that restaurant address. This vector will make the users' favourite 
		restaurant list
	*/
	std::vector<std::pair<std::string, std::string>> favourite_rest_list; 


	/*
		This member variable below is a
		vector(array) of a pair of strings. The first of the string on the pair
		will represent the checked in restaurant name while the second one will
		represent that restaurant address. This vector will make the users' checked-in 
		restaurant list
	*/
	std::vector<std::pair<std::string, std::string>> checked_In_list;

public:
	/*
		default constructor that initializes a user with 
		default values of 0 for all integer member variables,
		and default values of " " (whitespace) for all string member variables
		while NULL values for other object types like vector and cuisines
	*/
	user();

	/*
		parameterized constructor that initializes objects of the user class accordingly to the infromations passed as the parameter.
		Mostly these informations will come all the user infromation available in the database. This constructor will not initialize the
		id member variable of this class. This constructor can be mainly used while a registered user tries to login to the service
	*/
	user(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, int, const std::string&, const std::string&, 
		const std::string&, std::vector<std::string>&, const std::vector<std::pair<std::string, std::string>>&, const std::vector<std::pair<std::string, std::string>>&);

	/*
		parameterized constructor that will initalize the object of the class with every variables as passed. Some varaibles that will not be initialized
		by this constructor are id, favourite_rest_list and checked_In_list. This is because some user may not have any favourite resturant as well as 
		may not have checked into any restaurnats. The reason behind not initializing the id variable is becuase when a user first register himself
		he will only give his perosnal info. The user id will later be decided by the database itself before storing that user into the database.
		This id will be automatically given by the database i.e, automatically increaes by 1 than that of other users who registered before him/her.
		This constructor can be mainly used while user is registering for service.
	*/
	user(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, int, const std::string&, const std::string&,
		const std::string&, std::vector<std::string>&);

	~user(); //destructor for the user class
	
	/*
		Function set_personal_info will be used to load and initialize personal user info ,like id, first_name, last_name, address, city, country and country code,
		from the database once the user login. This can also be used to initialize above mentioned variables before storing user information in the 
		database after his/her registration. The first argument of this function will be an integer which will initialzie the id varaiable of the class.
		The first argument is followed by 5 consecutive string that will initialize users' frist_name, last_name, address, city, country respectively.
		These five arguments is then followed by a integer value that will be used to initialize the country_code member variable of the class.
	*/
	void set_personal_info(int id, const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, int);

	/*
		Function set_preference will be used to load and initialize user preferences like online_booking, online_delivery, and restaurants menu services(switch_menu)
		from the database once the user login. This can also be used to initialize above mentioned variables before storing user information in the
		database after his/her registration. This function will take three string arguments which initialize user perfernce of online booking, online 
		delivery and restaurant menu services respectively. The string should be in form of 'Yes' or 'No' as represented in the database.
	*/
	void set_preference(const std::string&, const std::string&, const std::string&);

	/*
		Function build_user_perf_cuisines will be used to load and initialize user preffered cuisine list, ex: Indian foods, Chinese foods, Thakali etc., 
		from the database once the user login. This function will take in a vector of string that where those string will store the 
		cuisine name while the vector will be used to initialize the cuisine object.
	*/
	void build_user_perf_cuisines(const std::vector<std::string>& food_list);
	
	/*
		Function build_user_fav_list will be used to load and initialize user favourite restaurants 
		from the database once the user login. This function will take in a 
		vector(array) of a pair of strings. The first of the string on the pair
		will represent the favourite restaurant name while the second one will 
		represent that restaurant address.
	*/
	void build_user_fav_list(const std::vector<std::pair<std::string, std::string>>& fav_list);
	
	/*
		Function build_user_checkIn_list will be used to load and initialize user favourite restaurants
		from the database once the user login. This function will take in a 
		vector(array) of a pair of strings. The first of the string on the pair
		will represent the checked in restaurant name while the second one will 
		represent that restaurant address.
	*/
	void build_user_checkIn_list(const std::vector<std::pair<std::string, std::string>>& checkIn_list);
	/*
		Function set_id will set id of a user. This function takes a single int argument and use it to initializes the id
		member variable of the class.
	*/
	void set_id(int id);

	/*
		Function get_id will return the user object(currently used user) id. 
	*/
	int get_id();

	/*
		Member function display_home_page_and_process_choice displays the homepage i.e, all the options that a user can interact with once 
		he/she has successfully logged-in. These options include rating and reviewing a restaurant,
		getting recommendation for the best restaurant to visit. This function will take a single argument.
		This argument will be a HANDLE to the screen that whose information will be used to display the 
		homepage menu options and outile patterns as well.
		This function will use the private static member function 'display_home_page_and_get_choice' that will 
		display the homepage options and prompt user to enter a choice. It is static because all users will have the same homepage. 
		This private member function will then return the user selected choice. This returned choice will be the used by the function below to process
		user selcted choice from homepage i.e, the function will call other function that performs operation related to choice selected 
		by the user in the homepage.
	*/
	void display_home_page_and_process_choice(const HANDLE& hout);
	
	/*
		Function does_user_name_exists will check if a user with a given user name exists in the database or not.
		If the username exists in the database then it will return true otherwise it will return false.
		This function will take in two arguments first one being the sqlite3* type which is the pointer
		to the sqlite database where user infromation is stored and the second one is a string which will
		be username to be checked.
	*/
	static bool does_user_name_exists(sqlite3* db, const std::string& userName);

private:
	/*
		Function display_home_page_and_get_choice will display the homepage a user will see once he/she logs in successfully.
		The functiom below will take a single argument which is a HANDLE to the consle screen whose 
		information will be user by this function to display the homepage menu.
		Moreover, Internally this function will use the menu class to display the homepage and 
		get choice from the user.
	*/
	static unsigned int display_home_page_and_get_choice(const HANDLE& hout);

	/*
		Function review_and_rate will display the menu which lets a user to rate and review a restaurant. This function will 
		prompt the user to enter the name of the restaurnat he/she wants to review and then will enter a new review as
		well as rating(number from 1 to 5). Then if the review is successful, this function will call the store_review_rate_in_db
		function to store the rating and review for that restaurant in the database. To  review and rate, user should first 
		enter the name of restaurant that is actually present in the database.
		The function below will take a single argument which is a HANDLE to the consle screen whose
		information will be user by this function to display the rate and review menu.
	*/
	void review_and_rate(const HANDLE& hout);

	/*
		Function add_to_favourites will display the menu which will let a user to add a restuarnt to their favourites. This function will 
		prompt the user to enter the name of the restaurnat he/she wants to add to his/her favourites. Then if the restaurant 
		is present in the database then it will be added to users' favourite restaurant list.
		The function below will take a single argument which is a HANDLE to the consle screen whose
		information will be user by this function to display the add to favourites menu.
	*/
	void add_to_favourites(const HANDLE& hout);
	/*
		Function check_in will display the menu which will let a user to add a restuarnt to their checked-in(visited) list. This function will 
		prompt the user to enter the name of the restaurnat he/she wants to add to his/her checked-in(visited) list. Then if the restaurant 
		is present in the database then it will be added to users' checked-in(visited) restaurant list.
		The function below will take a single argument which is a HANDLE to the consle screen whose
		information will be user by this function to display the check-ins menu.
	*/
	void check_in(const HANDLE& hout);

	/*
		Function display_user_profile will display the users' profile i.e, his/her first_name, last_name, address, favourite 
		restaurants etc in the screen. 
		
		The functiom below will take a single argument which is a HANDLE to the consle screen whose information will be 
		user by this function to display the user profile.
	*/
	void display_user_profile(const HANDLE& hout);

	/*
		Function display_reviews will display the menu which will let a user to see reviews and ratings for  a restuarnt. 
		This function will prompt the user to enter the name of the restaurnat whose review and rating is to be seen. 
		Then if the restaurant is present in the database then latest 8 reviews will be displayed in the screen.
		
		The function below will take a single argument which is a HANDLE to the consle screen whose information will be 
		user by this function to display the review menu menu.
	*/
	void display_reviews(const HANDLE& hout);
	
	/*
		Function view_restaurant_info will display the menu which will let a user to see restuarnts' info. 
		This function will prompt the user to enter the name of the restaurnat whose information is to be seen. 
		Then if the restaurant is present in the database then resturant information will be displayed in the screen.
		
		The function below will take a single argument which is a HANDLE to the consle screen whose information will 
		be user by this function to display the restaurants review menu.
	*/
	void view_restaurant_info(const HANDLE& hout);
	
	/*
		The display_user_favourites below will dispaly users' favourite restaurant list to the screen.

		The function below will take a single argument which is a HANDLE to the consle screen whose information will be
		user by this function to display the list of user favourite restaurants.
	*/
	void display_user_favourites(const HANDLE& hout);
	
	/*
		The display_user_checkIns below will display list to restaurants that the user has visied.

		The function below will take a single argument which is a HANDLE to the consle screen whose information will be
		user by this function to display the list of restaurants visisted by the user.
	*/
	void display_user_checkIns(const HANDLE& hout);

	/*
		The store_review_rate_in_db function will store user rating and review for restaurant in the database.

		This function takes in five arguments.

		The first argument is the sqlite database where the users' review and rating for the resturant is to be stored.
		The second argument is a string which represents user review. This cannot be longer than 90 characters. 
		The third argument is a string that represents a time when the user reviewd and rated the restaurant.
		The fourth argument a double which is the user's rating for that reviewed restaurant. It ranges from 1-5
		The fifth argumenent is a refrence to restaurant object which is being reviewd. This refrence restaurants
		id will be used to store the review and rating in the database.

	*/
	bool store_review_rate_in_db(sqlite3* db, std::string review, std::string time_stamp, double rate, restaurants& reviewed);
	
	/*
		The store_fav_in_db function will store user's favourite resturants list in the database.
		This function takes in two arguments.
		The first argument is a sqilte database where the user's favourite restaurants list is stored.
		The second argument is a refrence to restaurant object which is being stored in the database.
		The name and id of the restaurant will be taken out from this refrence and will be stored in
		the database.
	*/
	bool store_fav_in_db(sqlite3* db, restaurants& fav_resturant);
	/*
	The store_fav_in_db function will store user's visted(check-in) resturants list in the database.
	This function takes in two arguments.
	The first argument is a sqilte database where the user's visited restaurants list is stored.
	The second argument is a refrence to restaurant object which is being stored in the database.
	The name and id of the restaurant will be taken out from this refrence and will be stored in
	the database.
*/
	bool store_checked_in_db(sqlite3* db, restaurants& checkedIn_resturant);
	void display_recommendations(const HANDLE& hout, std::vector<std::pair<std::string, std::string>> recommendation_list);

	void recommend_restaurants(const HANDLE& hout);
};
