//in main.cpp
#include <iostream>
#include "video.hpp"
void popular_video(video& v1,video& v2);
//compile with g++ main.cpp video.cpp
int main(){
    video* v1 = new video("Gagnam Style", 100, 50, 5);
    video* v2 = new video("Purba Paschim Rel", 20, 10,8);
    popular_video(*v1, *v2);
}

/*
    Function that takes two video obejcts and check 
    and displays wether the video passed in the first argument is 
    more popular than the video passed in the second
    argument by using the overloaded '>' operator present in video 
    class.  
*/
void popular_video(video& v1,video& v2){
    if(v1.operator>(v2)){
        std::cout <<"Video: " << v1.get_title() << " is popular than video: " << v2.get_title() << std::endl; 
    }else{
        std::cout <<"Video: " << v2.get_title() << " is popular than video: " << v1.get_title() << std::endl;
    }    
}