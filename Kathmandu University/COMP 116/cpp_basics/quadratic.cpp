#include <iostream>
#include <cmath>

class quadraticSolver{
    private: 
        double a;
        double b;
        double c;

    public: quadraticSolver(double a, double b, double c){
        this->a = a;
        this->b = b;
        this->c = c;
    }

    public: 
        double getDiscriminant(){
            return (pow(this->b, 2) - (4 * this->a * this->c));
        }

        void checkIfReal(double discriminant){
            if(discriminant >= 0){
                std::cout << "Real" << std:: endl;;
            }else{
                std::cout << "Imaginary" << std:: endl;
            }
        }
};


int main(void){
    quadraticSolver eqnOne(2,4,6);
    quadraticSolver eqnTwo(1,5,6);


    eqnOne.checkIfReal(eqnOne.getDiscriminant());
    eqnTwo.checkIfReal(eqnTwo.getDiscriminant());
    
}
