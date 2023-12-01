//video.cpp
#include "video.hpp"

video::video()
:title(""), views(0), likes(0), dislikes(0)
{
} 

video::video(const std::string& title, int views, int likes, int dislkies)
:title(title), views(views), likes(likes), dislikes(dislikes) 
{
}

/*
    Getter that returns the title of current video object
*/
std::string video::get_title(){
    return this->title;
}

/*
    Function to check wether a given type of video is propular 
    that other type of video.
    A video is more poular than other IFF the number of likes 
    and views is greater than other video and the number of 
    dislike is less than other video. 
    This function returns true if a given video is popular than 
    the other video which is passed as argument to this function.
*/
bool video::operator >(const video& another_vid){
    if(this->likes > another_vid.likes && this->views > another_vid.views  && this->dislikes < another_vid.dislikes ){
        return true;
    }
    return false;
}