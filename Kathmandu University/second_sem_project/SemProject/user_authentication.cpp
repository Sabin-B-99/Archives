#include "user_authentication.h"


user_authenication::user_authenication(const std::string& first_name, const std::string& last_name, const std::string& address, const std::string& city, 
    const std::string& country, int country_code, const std::string& online_book, const std::string& online_delivery, const std::string& switch_menu, 
    std::vector<std::string>& pref_cuisines,
    const std::string& username, const std::string& password, const std::string& salt)

    :user(first_name, last_name, address, city, country, country_code, online_book, online_delivery, switch_menu, pref_cuisines), 
    user_name(username), password(password), salt(salt)
{
}

bool user_authenication::display_resgister_form(const HANDLE& hout)
{
    std::string first_name;
    std::string last_name;
    std::string address;
    std::string city;
    std::string country;
    int country_code;
    std::string user_name;
    std::string password_hashed;
    std::string salt;
    std::string online_book;
    std::string online_delivery;
    std::string switch_menu;
    std::vector<std::string> pref_cuisines;
    
    display_first_page(hout,first_name,last_name,address,city,country,country_code);
    display_second_page(hout, user_name, password_hashed, salt);
    display_third_page(hout, online_book, online_delivery, switch_menu, pref_cuisines);

    sqlite3* db = open_db("restaurants_info.db");
    user_authenication* reg_user = new user_authenication(first_name, last_name, address, city, country, country_code, online_book, online_delivery, switch_menu, pref_cuisines, user_name, password_hashed, salt);
    
    if (store_user_info(db, *reg_user)) {
        goto_xy(hout, 0, 30);
        center_allign_text_print(hout, " Registration Successful :) ", 2);
        SetConsoleTextAttribute(hout, 15);
        sqlite3_close(db);
        freeze_display(hout);
        clear_screen(hout);
        return true;
    }
   
    goto_xy(hout, 0, 30);
    center_allign_text_print(hout," Registration Failed :( ", 4);
    SetConsoleTextAttribute(hout, 15);
    sqlite3_close(db);
    freeze_display(hout);
    clear_screen(hout);
    return false;
}

void user_authenication::user_login_auth(const HANDLE& hout, user& logged_in_user)
{
    cls_and_draw_outline(hout, 0, 8, "Sign-in", "*", 15);
    show_cursor(hout, TRUE);
    center_allign_text_print(hout, "******INSTRUCTIONS******\n", 15);
    center_allign_text_print(hout, "Please, enter correct username and password.\n", 15);
    center_allign_text_print(hout, "You haven't signed up? Please register from the main menu.\n", 15);
    center_allign_text_print(hout, "If your username or password doesn't match then You have\n", 15);
    center_allign_text_print(hout, "to enter them again. You wont be able to sign until it matches.\n", 15);
    std::cout << std::endl;
    
    std::string entered_username;
    std::string password_salt;
    std::string hashed_password;

    sqlite3* db = open_db("restaurants_info.db");

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hout, &csbi);

    int no_of_try = 0;
    
    while (true) {
        move_cursor_off_left_edge_and_print(hout, "User Name? ", (no_of_try >= 1) ? 4 : 15);
        clear_current_line(hout);
        std::cin >> entered_username;
        std::cin.ignore(123, '\n');
        
        password_salt = get_salt(db, entered_username);
        
        move_cursor_off_left_edge_and_print(hout, "Password? ", (no_of_try >= 1) ? 4 : 15);
        clear_current_line(hout);
        hashed_password = sha256(getpassword() + password_salt);

        if (does_uName_pass_match(db, entered_username, hashed_password)) {
            break;
        }
        std:: cout << std::endl;
        move_cursor_off_left_edge_and_print(hout, "Wrong username or password",  4 );
        no_of_try++;
        goto_xy(hout, csbi.dwCursorPosition.X, csbi.dwCursorPosition.Y);
    }
    load_user_info_from_db(db, entered_username, hashed_password, logged_in_user);
    sqlite3_close(db);
}

void user_authenication::display_first_page(const HANDLE& hout, std::string& first_name, std::string& last_name, std::string& address, std::string& city, std::string& country ,int& country_code)
{
    cls_and_draw_outline(hout, 0, 8, "Registration: Page - 1", "*", 15);

    center_allign_text_print(hout, "******INSTRUCTIONS******\n", 15);
    center_allign_text_print(hout, "Welcome to registrartion page.\n", 15);
    center_allign_text_print(hout, "here you will be prompted to enter your personal infomations.\n", 15);
    center_allign_text_print(hout, "Note: After entering your country name, you will have to.\n", 15);
    center_allign_text_print(hout, "correctly enter your country's country code too. If either\n", 15);
    center_allign_text_print(hout, "of the counrty name or country code is incorrect then you'll\n", 15);
    center_allign_text_print(hout, "have to re-enter both the country name and its code again.\n", 15);
    center_allign_text_print(hout, "and you cannot move forward in the registration process until.\n", 15);
    center_allign_text_print(hout, "and unless you enter both of them correctly.\n", 15);
    std::cout << std::endl;

    move_cursor_off_left_edge_and_print(hout, "First Name? ", 15);
    std::getline(std::cin, first_name);
    first_name = to_lower_case(first_name);
    
    move_cursor_off_left_edge_and_print(hout, "Last Name? ", 15);
    std::getline(std::cin, last_name);
    last_name = to_lower_case(last_name);
    
    move_cursor_off_left_edge_and_print(hout, "Address? ", 15);
    std::getline(std::cin, address);
    address = to_lower_case(address);

    move_cursor_off_left_edge_and_print(hout, "City? ", 15);
    std::getline(std::cin,city);
    city = to_lower_case(city);

    sqlite3* db = open_db("restaurants_info.db");

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hout, &csbi);

    int no_of_try = 0;
    while (true) {
       
        move_cursor_off_left_edge_and_print(hout, "Country? ", (no_of_try >= 1) ? 4 : 15);
        clear_current_line(hout);
        std::getline(std::cin, country);
        country = to_upper_case(country);

        move_cursor_off_left_edge_and_print(hout, "Country Code? ", (no_of_try >= 1) ? 4 : 15);
        clear_current_line(hout);
        
        //forcing user to enter an integer
        //if integer is not entered then the other 'type' entered and stored in input buffer will be ignored and cleared
        if (!(std::cin >> country_code)) {
            std::cin.clear(); //clear previous input
        }

        //if the country is not in database then user has to reenter the country name and its specific country code
        if (does_region_exist(db, country, country_code)) {
            break;
        }

        no_of_try++;
        goto_xy(hout, csbi.dwCursorPosition.X, csbi.dwCursorPosition.Y);
        std::cin.ignore(123, '\n'); //flush out the newline character in cin that otherwise not removed will be eaten by the geline() function and lead to unexpected behaviour
    }

    sqlite3_close(db);
}

void user_authenication::display_second_page(const HANDLE& hout, std::string& user_name, std::string& hashed_password, std::string& salt)
{
    cls_and_draw_outline(hout, 15, 11, "Registration: Page - 2", "*", 15);

    goto_xy(hout, 0, 3);
    show_cursor(hout, TRUE);

    center_allign_text_print(hout, "******INSTRUCTIONS******\n", 15);
    center_allign_text_print(hout, "In this page you will be prompeted to choose your username and\n", 15);
    center_allign_text_print(hout, "password. So, you must choose the username that hasn't already\n", 15);
    center_allign_text_print(hout, "been selected by other users. If your username has already been\n", 15);
    center_allign_text_print(hout, "registered by other users then you will be prompted to choose your\n", 15);
    center_allign_text_print(hout, "username once again. This can be known as the username text box will\n", 15);
    center_allign_text_print(hout, "be highlited in red and you won't see box to enter your password.\n", 15);
    center_allign_text_print(hout, "Similary, Your initial password and final conformation password\n", 15);
    center_allign_text_print(hout, "should also match. Else, you'll be prompted to enter your password\n", 15);
    center_allign_text_print(hout, "and its conformation again, similary to username\n", 15);
    std::cout << std::endl;

    register_username(hout, user_name);
    register_password(hout,hashed_password, salt);
}

void user_authenication::display_third_page(const HANDLE& hout, std::string& online_book, std::string& online_delivery, std::string& switch_to_order, std::vector<std::string>& cuisines)
{
    cls_and_draw_outline(hout, 15, 11, "Registration: Page - 3", "*", 15);

    goto_xy(hout, 0, 3);
    show_cursor(hout, TRUE);

    center_allign_text_print(hout, "******INSTRUCTIONS******\n", 15);
    center_allign_text_print(hout, "In this page you will be prompted to to choose your preferences of\n", 15);
    center_allign_text_print(hout, "restaurant services. So, you will be asked with 3 questions and you can\n", 15);
    center_allign_text_print(hout, "answer them in only 'Yes' and 'No' (case doesn't matter) form. If not\n", 15);
    center_allign_text_print(hout, "answered in 'Yes' or 'No' form you will be prompted with same question\n", 15);
    center_allign_text_print(hout, "until you choose either 'Yes' or 'No'.\n", 15);
    center_allign_text_print(hout, "Moreover, this registration page will also ask you to choose some of your\n", 15);
    center_allign_text_print(hout, "favortie food cuisines. For example: Indian, Chinese, Thakali, Fast food\n", 15);
    center_allign_text_print(hout, "etc. Once you are done choosing your favorite food cusines then you need\n", 15);
    center_allign_text_print(hout, "to enter the keyword 'Exit' in same box where you type your favourite food\n", 15);
    center_allign_text_print(hout, "cuisines. Once the registration completes, you'll be prompted with 'Registration\n", 15);
    center_allign_text_print(hout, " Successful' Message. Now, you can sign in and enjoy our services.\n", 15);
    std::cout << std::endl;

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hout, &csbi);
    int no_of_try = 0;

    while (true) {
        move_cursor_off_left_edge_and_print(hout, "Do you prefer online booking? ", (no_of_try >= 1) ? 4 : 15);
        clear_current_line(hout);
        std::getline(std::cin, online_book);
        online_book = to_lower_case(online_book);

        move_cursor_off_left_edge_and_print(hout, "Do you prefer online delivery? ", (no_of_try >= 1) ? 4 : 15);
        clear_current_line(hout);
        std::getline(std::cin, online_delivery);
        online_delivery = to_lower_case(online_delivery);

        move_cursor_off_left_edge_and_print(hout, "Do you prefer switch to order menu? ", (no_of_try >= 1) ? 4 : 15);
        clear_current_line(hout);
        std::getline(std::cin, switch_to_order);
        switch_to_order = to_lower_case(switch_to_order);

        bool compare_ans_to_yes_no = (online_book.compare("yes") == 0 || online_book.compare("no") == 0) && 
                                     (online_delivery.compare("yes") == 0 || online_delivery.compare("no") == 0) && 
                                     (switch_to_order.compare("yes") == 0 || switch_to_order.compare("no") == 0);

        if (compare_ans_to_yes_no) {
            break;
        }
        no_of_try++;
        goto_xy(hout, csbi.dwCursorPosition.X, csbi.dwCursorPosition.Y);
    }

    
    std::string cuisine;
    GetConsoleScreenBufferInfo(hout, &csbi);

    no_of_try = 0;
    while(true){
        move_cursor_off_left_edge_and_print(hout, "Enter some cuisines you prefer?", (no_of_try >= 1) ? 2 : 15);
        std::cout << std::endl;
        move_cursor_off_left_edge(hout);
        clear_current_line(hout);
        std::getline(std::cin, cuisine);
        cuisine = to_lower_case(cuisine);

        if (cuisine.compare("exit") == 0) {
            break;
        }
        else {
            cuisines.emplace_back(cuisine);
        }
        no_of_try++;
        goto_xy(hout, csbi.dwCursorPosition.X, csbi.dwCursorPosition.Y);
    }
}

void user_authenication::register_username(const HANDLE& hout, std::string& user_name)
{
    sqlite3* db = open_db("restaurants_info.db");

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hout, &csbi);

    int no_of_try_user_name = 0;
    while (true) {
        move_cursor_off_left_edge_and_print(hout, "User Name? ", (no_of_try_user_name >= 1) ? 4 : 15);
        clear_current_line(hout);
        std::cin >> user_name;

        if (!does_user_name_exists(db, user_name)) {
            break;
        }
        no_of_try_user_name++;
        goto_xy(hout, csbi.dwCursorPosition.X, csbi.dwCursorPosition.Y);
    }

    std::cin.ignore(123, '\n');
    sqlite3_close(db);
}

void user_authenication::register_password(const HANDLE& hout, std::string& password, std::string& salt)
{
    std::string temp_password;
    std::string temp_password_again;
    salt = generate_salt(15);

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hout, &csbi);
   

    int no_of_try_password = 0;
    while (true) {
        move_cursor_off_left_edge_and_print(hout, "Password? ", (no_of_try_password >= 1) ? 4 : 15);
        clear_current_line(hout);
        temp_password = sha256(getpassword() + salt);

        move_cursor_off_left_edge_and_print(hout, "Confirm Password? ", (no_of_try_password >= 1) ? 4 : 15);
        clear_current_line(hout);
        temp_password_again = sha256(getpassword() + salt);

        if (strcmp(temp_password.c_str(), temp_password_again.c_str()) == 0) {
            break;
        }
        no_of_try_password++;
        goto_xy(hout, csbi.dwCursorPosition.X, csbi.dwCursorPosition.Y);
    }

    password = temp_password;
}

bool user_authenication::store_user_info(sqlite3* db,const user_authenication& user_info)
{
    sqlite3_stmt* st;

    std::string insert_personal_info = "INSERT INTO user_info(first_name, last_name, address, city, country, country_code, country_id) VALUES(?,?,?,?,?,?,(SELECT id FROM country WHERE name = ?));";
    int res_code = sqlite3_prepare(db, insert_personal_info.c_str(), -1, &st, NULL);
    
    sqlite3_int64 last_insert_id;
    
    if (res_code == SQLITE_OK) {
        sqlite3_bind_text(st, 1, user_info.first_name.c_str(), user_info.first_name.length(), SQLITE_TRANSIENT);
        sqlite3_bind_text(st, 2, user_info.last_name.c_str(), user_info.last_name.length(), SQLITE_TRANSIENT);
        sqlite3_bind_text(st, 3, user_info.address.c_str(), user_info.address.length(), SQLITE_TRANSIENT);
        sqlite3_bind_text(st, 4, user_info.city.c_str(), user_info.city.length(), SQLITE_TRANSIENT);
        sqlite3_bind_text(st, 5, user_info.country.c_str(), user_info.country.length(), SQLITE_TRANSIENT);
        sqlite3_bind_int(st, 6, user_info.country_code);
        sqlite3_bind_text(st, 7, to_upper_case(user_info.country).c_str(), user_info.country.length(), SQLITE_TRANSIENT);
        sqlite3_step(st);
        sqlite3_finalize(st);
        last_insert_id = sqlite3_last_insert_rowid(db);
    }
    else {
        return false;
    }

    
    std::string insert_security_info = "INSERT INTO user_auth(id,user_name,password,salt) VALUES(?,?,?,?);";

    res_code = sqlite3_prepare(db, insert_security_info.c_str(), -1, &st, NULL);
    if (res_code == SQLITE_OK) {
        sqlite3_bind_int64(st, 1, last_insert_id);
        sqlite3_bind_text(st, 2, user_info.user_name.c_str(), user_info.user_name.length(), SQLITE_TRANSIENT);
        sqlite3_bind_text(st, 3, user_info.password.c_str(), user_info.password.length(), SQLITE_TRANSIENT);
        sqlite3_bind_text(st, 4, user_info.salt.c_str(), user_info.salt.length(), SQLITE_TRANSIENT);
        sqlite3_step(st);
        sqlite3_finalize(st);
    }
    else {
        return false;
    }

    

    std::string insert_preference = "INSERT INTO user_preference(id, online_book, online_deliver, switch_to_order) VALUES(?,?,?,?);";

    res_code = sqlite3_prepare(db, insert_preference.c_str(), -1, &st, NULL);
    if (res_code == SQLITE_OK) {
        sqlite3_bind_int64(st, 1,last_insert_id);
        sqlite3_bind_text(st, 2, user_info.online_book.c_str(), user_info.online_book.length(), SQLITE_TRANSIENT);
        sqlite3_bind_text(st, 3, user_info.online_delivery.c_str(), user_info.online_delivery.length(), SQLITE_TRANSIENT);
        sqlite3_bind_text(st, 4, user_info.switch_menu.c_str(), user_info.switch_menu.length(), SQLITE_TRANSIENT);
        sqlite3_step(st);
        sqlite3_finalize(st);
    }
    else {
        return false;
    }

    std::string insert_cuisine;

    std::vector<std::string> user_cuisine = user_info.user_pref_cuisine->get_cuisines();

    for (size_t i = 0; i < user_cuisine.size(); i++) {
        insert_cuisine = "INSERT INTO user_cuisines(id, cuisine) VALUES(?,?);";
        res_code = sqlite3_prepare(db, insert_cuisine.c_str(), -1, &st, NULL);
        if (res_code == SQLITE_OK) {
            sqlite3_bind_int64(st, 1, last_insert_id);
            sqlite3_bind_text(st, 2, user_cuisine[i].c_str(), user_cuisine[i].length(), SQLITE_TRANSIENT);
            sqlite3_step(st);
            sqlite3_finalize(st);
        }
        else {
            return false;
        }
    }

    return true;

}

bool user_authenication::does_uName_pass_match(sqlite3* db, const std::string& user_name, const std::string& password)
{
    std::string sql_cmd = "SELECT id FROM user_auth WHERE user_name = \"" + user_name + "\" AND password = \"" + password + "\";";
    return does_entity_exist(db, sql_cmd);
}

std::string user_authenication::get_salt(sqlite3* db ,std::string user_name)
{
    std::string salt;
    std::string sql_cmd = "SELECT salt FROM user_auth WHERE user_name = \"" + user_name + "\";";
    char* err_msg;
    int err_code = sqlite3_exec(db, sql_cmd.c_str(), get_salt_callback, &salt, &err_msg);
    
    if (err_code != SQLITE_OK) {
        std::cerr << err_msg << std::endl;
        return NULL;
    }

    return salt;
}

int user_authenication::get_salt_callback(void* memory_to_store_salt, int argc, char** argv, char** azColName)
{
    std::string* salt = static_cast<std::string*>(memory_to_store_salt);
    *salt = argv[0];
    return 0;
}

void user_authenication::load_user_info_from_db(sqlite3* db, std::string username, std::string hashed_password, user& logged_in_user)
{
    char* err_msg;
    int err_code;


    std::string get_pesonal_info = "SELECT user_info.id, first_name, last_name, address, city, country, country_code FROM user_info " 
                                   "INNER JOIN user_auth ON user_info.id = user_auth.id "  
                                   "WHERE user_name = \"" + username + "\" AND password = \"" + hashed_password + "\";";

    err_code = sqlite3_exec(db, get_pesonal_info.c_str(), user_private_info_callback, &logged_in_user, &err_msg);
    if (err_code != SQLITE_OK) {
        std::cerr << err_msg << std::endl;
    }

    std::string get_pref_info = "SELECT online_book, online_deliver, switch_to_order FROM user_preference " 
                                "INNER JOIN user_auth ON user_preference.id= user_auth.id "  
                                "WHERE user_name = \"" + username + "\" AND password = \"" + hashed_password + "\";";

    err_code = sqlite3_exec(db, get_pref_info.c_str(), user_pref_info_callback, &logged_in_user, &err_msg);
    if (err_code != SQLITE_OK) {
        std::cerr << err_msg << std::endl;
    }

    std::vector<std::string> user_cuisine_list;
    std::string get_user_cuisine = "SELECT cuisine FROM user_cuisines " 
                                   "INNER JOIN user_auth ON user_cuisines.id= user_auth.id "  
                                   "WHERE user_name = \"" + username + "\" AND password = \"" + hashed_password + "\";";
    err_code = sqlite3_exec(db, get_user_cuisine.c_str(), user_cuisine_info_callback, &user_cuisine_list, &err_msg);
    if (err_code != SQLITE_OK) {
        std::cerr << err_msg << std::endl;
    }
    logged_in_user.build_user_perf_cuisines(user_cuisine_list);

    std::vector<std::pair<std::string, std::string>> fav_list;
    
    std::string get_fav = "SELECT restName, address FROM restAddressInfo INNER JOIN user_fav ON restAddressInfo.rest_id = user_fav.restId "
                          "WHERE  user_fav.userId = " + std::to_string(logged_in_user.get_id()) + " ORDER BY restId DESC LIMIT 25;";
    err_code = sqlite3_exec(db, get_fav.c_str(), user_fav_OR_checkin_callback, &fav_list, &err_msg);
    
    logged_in_user.build_user_fav_list(fav_list);

    std::vector<std::pair<std::string, std::string>> checkIn_list;

    std::string get_check_in = "SELECT restName, address FROM restAddressInfo INNER JOIN user_checkIn ON restAddressInfo.rest_id = user_checkIn.restId "
                               "WHERE  user_checkIn.userId = " + std::to_string(logged_in_user.get_id()) + " ORDER BY restId DESC LIMIT 25;";
    
    err_code = sqlite3_exec(db, get_check_in.c_str(), user_fav_OR_checkin_callback, &checkIn_list, &err_msg);
    logged_in_user.build_user_checkIn_list(checkIn_list);
    
}

int user_authenication::user_private_info_callback(void* memory_to_store_user_obj, int argc, char** argv, char** azColName)
{
    user* member_passed = static_cast<user*>(memory_to_store_user_obj);
    member_passed->set_personal_info( std::stoi(argv[0]), argv[1], argv[2], argv[3], argv[4], argv[5], std::stoi(argv[6]));
    return 0;
}

int user_authenication::user_pref_info_callback(void* memory_to_store_user_obj, int argc, char** argv, char** azColName)
{
    user* member_passed = static_cast<user*>(memory_to_store_user_obj);
    member_passed->set_preference(argv[0], argv[1], argv[2]);
    return 0;
}

int user_authenication::user_cuisine_info_callback(void* memory_to_store_cuisine, int argc, char** argv, char** azColName)
{
   std::vector<std::string>* cuisine_list = static_cast<std::vector<std::string>*>(memory_to_store_cuisine); 
   cuisine_list->emplace_back(argv[0]);
    return 0;
}


int user_authenication::user_fav_OR_checkin_callback(void* fav_OR_check_list, int argc, char** argv, char** azColName) {
    std::vector<std::pair<std::string, std::string>>* required_list = static_cast<std::vector<std::pair<std::string, std::string>>*>(fav_OR_check_list);
    
    std::pair<std::string, std::string> rest_name_address;
    rest_name_address.first = argv[0];
    rest_name_address.second =argv[1];

    required_list->emplace_back(rest_name_address);
    return 0;
}

bool user_authenication::does_region_exist(sqlite3* db, const std::string& country_name, int country_code)
{
    std::string sql_cmd = "SELECT name FROM country WHERE name = \"" + to_upper_case(country_name) + "\" AND countryCode = " + std::to_string(country_code) + ";";
    return does_entity_exist(db, sql_cmd);
}



