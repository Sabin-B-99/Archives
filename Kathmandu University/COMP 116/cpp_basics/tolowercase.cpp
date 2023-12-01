#include <iostream>
#include <string>
std::string to_lower_case(std::string&);
int main(){
    std::string init = "MY namE iS SaBiN BadAL";
    std::string result = to_lower_case(init);
    std::cout << result <<std::endl;
    std::cout << "init length: "<< init.length() << std::endl;
    std::cout << "result length: "<< result.length() << std::endl;
}

std::string to_lower_case(std::string& line) {
	std::string converted_line;
	int count = 0;
	int i;
	while(line[i] != '\0'){
		converted_line += static_cast<char>(tolower(line[i]));
		if(tolower(line[i]) == '\0'){
			count++;
		}
		i++;
	}
	converted_line += '\0';
	std::cout << count << std::endl;
	return converted_line;
}