//in m_string.hpp
#include "m_string.hpp"
/*
    Parameterized constructor that initialzies the m_string
    type with the literal string provided as its argument.
    In the constructor first a memory is allocated for the
    m_string type. The size of memory to be allocated depends 
    upon the length of the string literal passed as the arguments.
    Then, the string literal passed as arguments is copied in the newly
    allocated memory location of m_string type.
*/
m_string::m_string(char* word)
{   
    this->string = (char*) malloc(strlen(word) + 1); 
    strcpy(this->string, word);
}
//destrcutor that destroys m_string type and frees all memory used by it
m_string::~m_string(){
    delete this->string;
}
/*
    In this function, I have used the C strcat function to 
    concatenate two give m_string types.
*/
void m_string::operator+(const m_string& word){
    strcat(this->string, word.string);
}

/*
    In this function, I have used the C memset function
    to first override all the characters of the old m_string
    type with null characters('\0), while not deleteing the 
    memory location of the old string. And the I used the C
    strcpy function to copy the new m_string (char* internally)
    values into that old memory location which had null characters.
*/
void m_string::operator=(const char* word){
    memset(this->string, '\0', strlen(word) + 1);
    strcpy(this->string, word);
}

/*
    In this function, I have used the C strcmp function to 
    check wether two give m_string type, which is a char* 
    type internally, are equal or not.
*/
bool m_string::operator=(const m_string& word){
    if(strcmp(this->string, word.string) == 0){
        return true;
    }
    return false;
}

std::ostream& operator << (std::ostream& out_stream, const m_string& obj){
    out_stream <<  obj.string; 
    return out_stream;
}
