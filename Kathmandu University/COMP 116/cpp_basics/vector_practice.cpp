#include <iostream>
#include <vector>

class Menu{
    private:
        std::string title;
        std::vector<std::string> menu_options;

    public:
        Menu(std::string title){
            this->title = title;
        }

        void set_menu_options(std::string menu_item){
            menu_options.push_back(menu_item);
        }

        void display_menu(Menu& menu){
            std::cout << "*********************** " << menu.title << " **************************" << std::endl;
            for (size_t i = 0; i < menu.menu_options.size(); i++)
            {
                std::cout << menu_options[i] << std::endl;
            }
        }
        
            
};

int main(){
    Menu* menu = new Menu("Main-Menu");
    menu->set_menu_options("Login");
    menu->set_menu_options("Register");
    menu->set_menu_options("Exit");
    
    menu->display_menu(*menu);
    
    
    return 0;
    
}