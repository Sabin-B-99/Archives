#include <iostream>

class Time{
    private: 
        int hour;
        int min;
        int sec;
    public:
        Time()
        :hour(0), min(0), sec(0)
        {
            convert_time();
        }

        Time(int hour, int min, int sec)
        :hour(hour), min(min), sec(sec)
        {
            convert_time();
        }

    Time operator+ (const Time& second_obj) const{
        Time res;
        res.hour = this->hour + second_obj.hour;
        res.min = this->min + second_obj.min;
        res.sec = this->sec + second_obj.sec;
        res.convert_time();
        return res;
    }

    friend std::ostream& operator << (std::ostream& stream, const Time& time_obj){
        stream << time_obj.hour << ":" << time_obj.min << ":" << time_obj.sec;
        return stream;
    }

    private:
        void convert_time(){
            if(this->sec > 59){
                this->min++;
                this->sec == 0;
            }
            if(this->min > 59 ){
                this->hour++;
                this->min == 0;
                this->sec == 0;
            }
            if(hour > 12){
                this->hour == 1;
                this->min == 0;
                this->sec == 0;
            }
        }
};



int main(){
    Time time_One(2,29,35);
    Time time_two(2,31,29);
    Time res = time_One.operator+(time_two);
    std::cout << res << std::endl; 
}