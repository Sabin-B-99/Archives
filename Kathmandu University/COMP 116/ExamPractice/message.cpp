#include <iostream>
#include <typeinfo>

class Pizza
{
protected:
  int size;
  int numToppings;
  std::string *toppings;

private:
  virtual void makeBase();
  virtual void addToppings();
  virtual void bake();

public:
  Pizza(unsigned int size = 10) : size(size)
  {
  }

  /*
  No expect means the function doesn't throw any error so removing the noexpect specifier
  */
  void make()
  {
    try
    {
      makeBase();
      addToppings();
      bake();
      std::cout << typeid(*this).name() << " is ready!\n";
    }
    catch (const std::exception &e)
    {
      std::cout << e.what() << std::endl;
      throw;
    }
  }

  virtual double getPrice() = 0;
};

void Pizza::makeBase()
{
  // If the size of the pizza is too small, throw an exception
  if (size < 10)
  {
    throw std::runtime_error("Pizza size too small!");
  }
  std::cout << "Making pizza base of size " << size << " cm...\n";
  std::cout << "Adding sauce\n";
  std::cout << "Pizza base is ready!\n";
}

void Pizza::bake()
{
  std::cout << "Baking...\n";
  std::cout << "Baked!\n";
}

void Pizza::addToppings()
{
  // If there are no toppings, throw an exception
  if (numToppings == 0)
  {
    throw std::runtime_error("Toppings not found");
  }

  std::cout << "Adding ";
  for (int i = 0; i < numToppings; i++)
  {
    if (toppings[i] != "")
    {
      std::cout << toppings[i] << " ";
    }
  }
  std::cout << std::endl;
}

/*
  In order for other base classes that are inherited from VegPizza to access Pizza. i.e class Pizza in thier constructor,
  we muse allow access by changing the access specifier from protected to public. We also require the base classes to access the class Pizza
  because we will be using Polymorphism to make an array of class Pizza
*/
class VegPizza : public Pizza
{
public:
  VegPizza(unsigned int size) : Pizza(size) {}
};

class PepperoniPizza : public Pizza
{
public:
  PepperoniPizza(unsigned int size) : Pizza(size)
  {
    /*
    Number of toppings was no specified so it had garbage value and caused the program to be in a for loop for many iterations
    */
    numToppings = 3;

    toppings = new std::string[numToppings];
    toppings[0] = "Cheese";
    toppings[1] = "Pepperoni";
    toppings[2] = "Olive";
  }
  /*
    removing virtual keyword. Because vitual keyword is not required in base class's implementation
  */
  double getPrice() { return size * 20; }
};

class MushroomPizza : public VegPizza
{
protected:
  bool extraOil;

public:
  ~MushroomPizza()
  {
    delete toppings;
  }

  MushroomPizza(unsigned int size) : extraOil(false), VegPizza(size)
  {
    numToppings = 3;
    toppings = new std::string[numToppings];
    toppings[0] = "Cheese";
    toppings[1] = "Mushroom";
    toppings[2] = "Olive";
  }
  double getPrice() { return size * 10 + (extraOil ? 20 : 0); }

  void extraOliveOil()
  {
    extraOil = true;
    std::cout << "Drizzling extra olive oil\n";
  }
};

int main()
{
  Pizza *pizzas[3];

  pizzas[0] = new PepperoniPizza(5);
  pizzas[1] = new MushroomPizza(15);
  pizzas[2] = new PepperoniPizza(20);

  for (Pizza *p : pizzas)
  {
    try
    {
      p->make();
      MushroomPizza *mp = dynamic_cast<MushroomPizza *>(p);
      if (mp)
      {
        mp->extraOliveOil();
      }
      std::cout << "Price of " << typeid(*p).name() << " = "
                << p->getPrice() << std::endl;
    }
    catch (const std::exception &e)
    {
      std::cout << "Could not make pizza!\n";
    }
  }
}