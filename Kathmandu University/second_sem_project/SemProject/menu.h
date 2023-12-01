/*
	Author: Angel Ghimire

	Description:
	Class which can be used to create objects
	that can be used to display menu in the console
	window. Client program can use this class' objects
	to add any number of menu options along with the
	menu title and outile designs. This can later be
	displayed in the console window, form which it will
	prompt user to enter his preffered option in the keyboard.
	This entered option number will be returned to the client
	program from which other process can be performed accordingly.

	This class objects can be used to display menu in the console
	such as displayed below:

	**************************menu-title****************************
	*                                                              *
	*                         option 1                             *
	*                         option 2                             *
	*                         .                                    *
	*                         .                                    *
	*                         .                                    *
	*                         option n                             *
	*Enter your choice?_                                           *
	****************************************************************

	Here, in above example '*' is the outline pattern of the menu while
	'option 1', 'option 2', ..., 'option n' are menu options and then
	at the bottom left of screenuser will be prompted to choose one of
	the option in the menu.
*/
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "basic_functions.h"

class menu {
private:
	/*
		string variable that will hold the name of menu or menu 
		title for the menu to be displayed
	*/
	std::string menu_title;
	/*
		Array that will take store all the availbale menu options 
		to be displayed.
	*/
	std::vector<std::string> menu_options;
public:
	/*
		constructor that will take in only the menu option to initalize the menu object.
		There is no default constructor as it would not be fruitful to display the menu 
		without displaying the menu-title (ex: main-menu etc)
	*/
	menu(const std::string&);
	~menu(); //destrcutor for the menu class
	
	/*
		Function that will let the client program to add
		the menu-options to the menu objects. These options will 
		be stored in the class member vector(array) menu_options.
		This function will return true if the given menu option
		is successfully stored in vector otherwise return false,
		and won't again store that option in the vector
		i.e, in case another menu option with the same name as given
		option is already present in the menu.
		For Example:
			If user decides to store option 'Exit' and if this option
			is already present in the vector then this 'add_option'function 
			will return false and will not store that option in the 
			vector again. Otherwise it will return true and store that option.
	*/
	bool add_option(const std::string&);
	/*
		The function display_menu will display the menu 
		to the console screen i.e, the menu-title and 
		menu_options and outline patterns stored in 
		the menu object. This function prints the menu as below:
		**************************menu-title****************************
		*                                                              *
		*                         option 1                             *
		*                         option 2                             *
		*                         .                                    *
		*                         .                                    *
		*                         .                                    *
		*                         option n                             *
		*Enter your choice?_                                           *
		****************************************************************
		FIG I: Sample of menu that can be displayed in the console screen

		The function takes in a console screen handle, a string pattern, a string flag, and two WORD types.
		
		HANDLE hout - In context of our program as described in microsoft win32 api is a 
					  HANDLE is a data type that stores a pointer to the memroy location that 
					  manages/store all the resources nedded to create a console window in the 
				      monitor as well as store its related informations like console 
				      windows dimension, cursor position and visibility etc. 

		string pattern - It is a word, mostly preferred a char like ' * ' for better output, 
						 that will be be used to create the outline for the menu to be displayed
						 In above FIG I: we can see use of '*' to create the outline pattern
		
		string position - It is the position where the menu options will be displayed. This position
						  or flag can be one of 'tm', 'm' and 'tl'. If this flag is choosen as 'tm'
						  then the the options will be displayed in middle of the screen towrads the 
						  top of the screen. If it is 'm' then it will be in middle of the screen.
						  If it is 'tl' then it will be in the option will be it will be at the top left 
						  corner of the screen

		WORD - Simply an 'int' type which is an unsigned(i.e, can't be negative)
				A 16-bit unsigned integer. The range is 0 through 65535 decimal.
				i.e, it can be reffered as typedef unsigned int WORD. So, in simple
				word it is an integer type.

		So,  WORD title_forgC_color, WORD title_bacgC_color are simply the color code that will be used
		as the foreground and background color for the tiitle.
		Micosoft win32 api color codes:
		Console Color
		Name         | Value
					 |
		Black        |   0
		Blue         |   1
		Green        |   2
		Cyan         |   3
		Red          |   4
		Magenta      |   5
		Brown        |   6
		Light Gray   |   7
		Dark Gray    |   8
		Light Blue   |   9
		Light Green  |   10
		Light Cyan   |   11
		Light Red    |   12
		Light Magenta|   13
		Yellow       |   14
		White        |   15
	*/
	void display_menu(const HANDLE& hout, const std::string& pattern, const std::string& position, WORD title_forgC_color, WORD title_bacgC_color);

	/*
		This Function will prompt the user to choose one of the menu options and
		return the option number. Once the user enters the number it will check 
		wether the options exists or not. If the option exists then it will return
		the option number. Else the program will re-prompt the user to enter the 
		correct option choice until an existing choice is provided.
		This function also takes in the screen HANDLE that has infromation about the
		console window.
	*/
	unsigned int get_selection(const HANDLE& hout);
	/*
		This function will display a message when client program chooses to exit quit the program.
		The function takes in three arguments:
		Frist argument is as usual a HANDLE to the current console
		Second argument is the string that will be the title to quit message screen, Similar to menu title.
		Third argumtnt is also a string that is the quit message to be displayed to the screem.
		An Example on how this function works is below:
		**************************Thank You*****************************
		*                                                              *
		*								                               *
		*		    Thank You for using our program!                   *
		*                                                              *
		*                                                              *
		*                                                              *
		*								                               *
		*                                                              *
		****************************************************************
		FIG II: Quit Screen
		In above Screen word 'Thank You' will be the quit message title
		and message 'Thank you for .... program!' will be the quit message.
	*/
	void display_exit_message(const HANDLE& hout,const std::string& quit_msg_title,const std::string& quit_screen);

private:
	/*
		The function below i.e, doe_option_exist will check wether a specified menu 
		option passed as parameter in the function as a string exists in the 
		menu (vector menu_options above) or not. If that menu option exists 
		then the function will return true otherwise it will return false.
	*/
	bool does_option_exist(const std::string&);

	/*
		The function below will calculate the horizontal mid-point of the screen using  
		middle character of the text (option name). It is simlar to the option 'justify' 
		in Microsoft Word where the a word can be written right from the middle of document.
		The option is passed as the first argument to the function as its position number in
		the option list(vector above). 
		
		The second argument is the win32 api structure,  CONSOLE_SCREEN_BUFFER_INFO which 
		contains information about the cursor position, cursor visibility, console window 
		size(x, y) etc.

		In <windows.h> (win32 api) file it is defined as:

		typedef struct _CONSOLE_SCREEN_BUFFER_INFO {
		  COORD      dwSize; //console size in (x,y) in (character column, character rows) (for our purpose (98, 36))
		  COORD      dwCursorPosition; //current cursor position
		  WORD       wAttributes; //color of the console window
		  SMALL_RECT srWindow; //structure that contains cordinates for console window upper left point and lower right point
		  COORD      dwMaximumWindowSize; //maximum size of the window that can be represented
		} CONSOLE_SCREEN_BUFFER_INFO;

		This function returns the mid-point of a screen in the x-dirction
		i.e. the horizontal mid-point of the line where currently the cursor is 
		placed. This midpoint then will later be used by other public member functions
		of this class to display the option at the middle point of the screen.
	*/
	inline int calculate_mid_X(int option_no, const CONSOLE_SCREEN_BUFFER_INFO& csbi);
	/*
		The function below will calculate the vertical mid-point of the screen using
		middle character of the text (option name). It is simlar to the option 'justify'
		in Microsoft Word where the a word can be written right from the middle of document.
		The option is passed as the first argument to the function as its position number in
		the option list(vector above).

		The second argument is the win32 api structure,  CONSOLE_SCREEN_BUFFER_INFO which
		contains information about the cursor position, cursor visibility, console window
		size(x, y) etc.

		In <windows.h> (win32 api) file it is defined as:

		typedef struct _CONSOLE_SCREEN_BUFFER_INFO {
		  COORD      dwSize; //console size in (x,y) in (character column, character rows) (for our purpose (98, 36))
		  COORD      dwCursorPosition; //current cursor position
		  WORD       wAttributes; //color of the console window
		  SMALL_RECT srWindow; //structure that contains cordinates for console window upper left point and lower right point
		  COORD      dwMaximumWindowSize; //maximum size of the window that can be represented
		} CONSOLE_SCREEN_BUFFER_INFO;

		This function returns the mid-point of a screen in the y-direction
		i.e. the vertical line no where the the middle option among all 
		the options in the menu will be placed. This midpoint then will 
		later be used by other public member functions
		of this class to display the option at the middle point of the screen. 
	*/
	inline int calculate_mid_Y(int option_no, const CONSOLE_SCREEN_BUFFER_INFO& csbi);


	/*
		The function display_menu will display the menu options
		at the top left corner of the console screen i.e, the menu-title and 
		menu_options and outline patterns stored in 
		the menu object. This function a prints the menu as below:
		**************************menu-title****************************
		* option 1                                                     *
		* option 2									                   *
		* option n							                           *
		*                                                              *
		*                                                              *
		*                                                              *
		*													           *
		*Enter your choice?_                                           *
		****************************************************************
		The function takes in a console screen HANDLE, a string pattern:
		The first argument will be the console screen HANDLE and second argument is a string as outline pattern 

		HANDLE hout - In context of our program as described in microsoft win32 api is a
					  HANDLE is a data type that stores a pointer to the memroy location that
					  manages/store all the resources nedded to create a console window in the
					  monitor as well as store its related informations like console
					  windows dimension, cursor position and visibility etc.

		string pattern - It is a word, mostly preferred a char like ' * ' for better output,
						 that will be be used to create the outline for the menu to be displayed
						 In above FIG I: we can see use of '*' to create the outline pattern
		
		This function will be used by the display_menu function to display the menu at the top-left of the screen
	*/
	void display_menu_at_top_left(const HANDLE& hout, const std::string&);

	/*
		The function display_menu will display the menu options
		at the middle of the console screen i.e, the menu-title and
		menu_options and outline patterns stored in
		the menu object. This function a prints the menu as below:
		**************************menu-title****************************
		*											                   *
		* 											                   *
		* 						    Option 1                           *
		*                           Option 2	                       *
		*                                                              *
		*                                                              *
		*													           *
		*Enter your choice?_                                           *
		****************************************************************
		The function takes in a console screen HANDLE, a string pattern:
		The first argument will be the console screen HANDLE and second argument is a string as outline pattern

		HANDLE hout - In context of our program as described in microsoft win32 api is a
					  HANDLE is a data type that stores a pointer to the memroy location that
					  manages/store all the resources nedded to create a console window in the
					  monitor as well as store its related informations like console
					  windows dimension, cursor position and visibility etc.

		string pattern - It is a word, mostly preferred a char like ' * ' for better output,
						 that will be be used to create the outline for the menu to be displayed
						 In above FIG I: we can see use of '*' to create the outline pattern

		This function will be used by the display_menu function to display the menu at the middle of the screen
	*/
	void display_menu_at_mid(const HANDLE& hout, const std::string&);

	/*
		The function display_menu will display the menu options
		at the top-middle of the console screen i.e, the menu-title and
		menu_options and outline patterns stored in
		the menu object. This function prints the menu as below:
		**************************menu-title****************************
		*							option 1		                   *
		* 						    option 2		                   *
		* 									                           *
		*                                                              *
		*                                                              *
		*                                                              *
		*													           *
		*Enter your choice?_                                           *
		****************************************************************
		The function takes in a console screen HANDLE, a string pattern:
		The first argument will be the console screen HANDLE and second argument is a string as outline pattern

		HANDLE hout - In context of our program as described in microsoft win32 api is a
					  HANDLE is a data type that stores a pointer to the memroy location that
					  manages/store all the resources nedded to create a console window in the
					  monitor as well as store its related informations like console
					  windows dimension, cursor position and visibility etc.

		string pattern - It is a word, mostly preferred a char like ' * ' for better output,
						 that will be be used to create the outline for the menu to be displayed
						 In above FIG I: we can see use of '*' to create the outline pattern

		This function will be used by the display_menu function to display the menu at the top and middle of the screen
	*/
	void display_menu_at_top_mid(const HANDLE& hout, const std::string&);

	/*
		This function will take a string which should be a menu option as an argument.
		And it will return the idex no where the menu option is located in the option list.
		(vector). If the passed in argument is not an option of the menu then this function
		will return -1
	*/
	int choice_no(std::string);
};
