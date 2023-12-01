#include <iostream>

template<typename T, typename U>
void solve_two_var_lin_eqn(const T& a, const T& b, const T& m, const T& c, const T& d, const T& n, U& x, U& y);
//client program
int main(){
    double x;
    double y;

    solve_two_var_lin_eqn(3, 3, 6, 4, 9, 15, x, y);

    std::cout << "X = " << x << std::endl;
    std::cout << "Y = " << y << std::endl;    

}

/*
    A template function that will take six arguments for the coefficients and 
    y-intecepts for two linear equations as well as two more arguments to 
    hold thier solutions X and Y
    The equations will be in form of
    ax + by = m 
    cx + dy = n
    the last two arguments ,x and y, in this function will hold the value for their solutions
*/
template<typename T, typename U>
void solve_two_var_lin_eqn(const T& a, const T& b, const T& m, const T& c, const T& d, const T& n, U& x, U& y){
    auto denominator = (a * d - c * b);
    if(denominator == 0){
        std::cout << "No Solutons!" << std::endl;
        exit(0);
    }
    x =  static_cast<U>(m * d - b * n) / denominator;
    y =  static_cast<U>(n * a - m * c) / denominator;
}