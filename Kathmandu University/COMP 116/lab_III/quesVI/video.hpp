//in video.hpp
/*
    Author: Sabin Badal
    Date: 10/8/2020

    Description:
    Class that simulates a video in a streaming service. And through 
    this class we can check wether a given type of video is propular 
    that other type of video.

    We have overloaded > operartor in this class and used this operator
    to check whether the a video is more popular than other. A video is 
    more poular than other IFF the number of likes and views is greater
    than other video and the number of dislike is less than other video.
    These likes, views and dislikes as well as video title is represented 
    by data fields of this video class.   
*/
#pragma once
#include <iostream>
class video{
    private:
    std::string title;
    int views;
    int likes;
    int dislikes;

    public:
    video();
    video(const std::string& title, int views, int likes, int dislkies);
    bool operator > (const video& another_vid); 
    std::string get_title();
};