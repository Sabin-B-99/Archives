#include <iostream>
#include <vector>

class Student{
private:
   std::string name;
   int roll_num;

public:
   Student()
   :name(""), roll_num(0)
   {
   }

   Student(std::string name, int roll_num)
   :name(name), roll_num(roll_num)
   {
   }

   bool operator == (Student stdObj)
   {
      if((this->name.compare(stdObj.name) == 0) && this->roll_num == stdObj.roll_num)
      {
        return true;
      }
      return false;
   }

};

template <typename T>
bool isPresent(std::vector<T>& arr, T compareObj)
{
  int matchObj = 0;
  for(size_t i = 0; i < arr.size(); i++)
  {
    if(arr[i].operator==(compareObj))
    {
      return true;
    }
  }
    return false;
}

int main()
{
	Student* std1 =  new Student("Sabin", 3);
	Student* std2 = new Student("Babin", 4);
  Student* std3 = new Student("Nabin", 5);
        
  Student* std4 = new Student("Sabin", 3);
  Student* std5 = new Student("Abin", 5);

	if(std1->operator==(*std4))
  {
    std::cout << "Given Type Match" << std::endl;
  }
  

	std::vector<Student> arr;
	arr.emplace_back(*std1);
	arr.emplace_back(*std2);
	arr.emplace_back(*std3);
	
	if(isPresent<Student>(arr, *std5))
	{
	 std::cout << "The student is present" << std::endl;
	}
	else
	{
	std::cout << "Student is not present" << std::endl;
	}
}
	