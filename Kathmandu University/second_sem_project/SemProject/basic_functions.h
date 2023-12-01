#pragma once
#include <iostream>
#include <string>
#include <Windows.h>


#include <stdexcept>

#include <openssl/sha.h>
#include <iomanip>
#include <sstream>

#include <time.h>
#include <chrono>  // chrono::system_clock
#include <ctime>   // localtime
#include <sstream> // stringstream

std::string to_lower_case(const std::string&);
std::string to_upper_case(const std::string& line);
std::string current_time_and_date();

void create_screen(const HANDLE&);
void clear_screen(const HANDLE&);
void clear_screen(const HANDLE&, int, int);
void goto_xy(const HANDLE&,int, int);
void show_cursor(const HANDLE&, bool);
void clear_line(const HANDLE&, int);
void clear_current_line(const HANDLE&);
void cls_and_draw_outline(const HANDLE&, int, int, const std::string&, const std::string&, WORD);
void freeze_display(const HANDLE& hout);

void move_cursor_off_left_edge(const HANDLE&);
void set_cursor_at_middle(const HANDLE&);
void set_cursor_near_right(const HANDLE&);
void print_line_with_color(const HANDLE&,const std::string&, WORD);

void move_cursor_off_left_edge_and_print(const HANDLE& hout, const std::string& line, WORD color);
void set_cursor_at_middle_and_print(const HANDLE& hout, const std::string& line, WORD color);
void set_cursor_near_right_and_print(const HANDLE& hout, const std::string& line, WORD color);
void center_allign_text_print(const HANDLE& hout, const std::string& line, WORD color);

void create_screen_outline(const HANDLE&, const std::string&, const std::string&, WORD);

bool yes_no_to_bool(std::string&);
std::string yes_no_to_Yes_No(std::string);

std::string generate_salt(const unsigned int len);
std::string getpassword();
std::string sha256(const std::string str);

