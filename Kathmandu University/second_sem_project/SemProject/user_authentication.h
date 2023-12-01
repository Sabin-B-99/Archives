/*
	Author: Sabin Badal

	Description:
		Objects of this class will let user register their username and password
		(account) as well as their personal info and restaurants preferences.
		Moreover, this calss will also authenticate users' password and username
		while loggin in.
	File: user_authentication.h
*/
#pragma once
#include <iostream>
#include <string>
#include "user.h"
#include "basic_functions.h"

class user_authenication : public user{
private:
	std::string user_name;
	std::string password;
	std::string salt;
public:
	user_authenication(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, int, const std::string&, 
		const std::string&, const std::string&, std::vector<std::string>&,
		const std::string&, const std::string&, const std::string&);


	static bool display_resgister_form(const HANDLE& hout);
	static void user_login_auth(const HANDLE& hout, user& logged_in_user);

private:
	static void display_first_page(const HANDLE& hout, std::string& first_name, std::string& last_name, std::string& address, std::string& city, std::string& country, int& country_code);
	static void display_second_page(const HANDLE& hout, std::string& user_name, std::string& hashed_password, std::string& salt);
	static void display_third_page(const HANDLE& hout, std::string& online_book, std::string& online_delivery,std::string& switch_to_order, std::vector<std::string>& cuisines );
	static void register_username(const HANDLE& hout,std::string& user_name);
	static void register_password(const HANDLE& hout, std::string& password, std::string& salt);
	static bool store_user_info(sqlite3* db,const user_authenication& user_info);

	static  bool does_uName_pass_match(sqlite3* db, const std::string& user_name, const std::string& password);

	static std::string get_salt(sqlite3* db, std::string user_name);
	static int get_salt_callback(void* memory_to_store_salt, int argc, char** argv, char** azColName);

	static void load_user_info_from_db(sqlite3* db, std::string username, std::string hashed_password, user& logged_in_user);
	static int user_private_info_callback(void* memory_to_store_user_obj, int argc, char** argv, char** azColName);
	static int user_pref_info_callback(void* memory_to_store_user_obj, int argc, char** argv, char** azColName);
	static int user_cuisine_info_callback(void* memory_to_store_user_obj, int argc, char** argv, char** azColName);
	static int user_fav_OR_checkin_callback(void* fav_OR_check_list, int argc, char** argv, char** azColName);

	static bool does_region_exist(sqlite3* db, const std::string& country_name, int country_code);
};