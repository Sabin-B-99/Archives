#include <iostream>
using namespace std;
class Fibonacci
{
private:
  //must be static
  static unsigned long get(unsigned long number, unsigned long memo[])
  {
    /*
      For a recursion funciton to work properply it must have a base condition to terminatie the recursion stack
      the previous if statement didn't satisfy the base condition so changing the if condition that fulfills the 
      fibbonacci's base condition.
    */
    if ((number == 1) || (number == 0))
    {
      memo[number] = number;
    }
    else
    {
      {
        memo[number] = get(number - 1, memo) + get(number - 2, memo);
      }
    }
    return memo[number];
  }

public:
  static unsigned long get(unsigned long number)
  {
    /*
    As variables can't be used in stack allocated arrays, declaring an array of unsinged int in the heap and 
    assasigining the head of the array to the pointer "memo"
    */
    unsigned long *memo = new unsigned long[number + 1];

    for (int i = 0; i < number; i++)
    {
      memo[i] = -1;
    }
    /*
    Can't use this keyword in static functions. And Sattic function can only call other static member functions
    so changing get to static
    */
    return get(number, memo);
  }
};

int main()
{
  cout << "f(10) = " << Fibonacci::get(10);
  return 0;
}