#include <iostream>
//*******************************************************************
class Point
{
private:
    int pos_x;
    int pos_y;
public:
    Point(){
        this->pos_x = 0;
        this->pos_y = 0;
    }

    Point(int pos_x, int pos_y){
        this->pos_x = pos_x;
        this->pos_y = pos_y;
    };

    void setPoint(int new_x, int new_y){
        this->pos_x = new_x;
        this->pos_y = new_y;
    }

    int getX(){
        return this->pos_x;
    }

    int getY(){
        return this->pos_y;
    }
    
};

//******************************************************************************8
class Polygon
{
protected:
int numberOfSides;
Point centroid;

public:
Polygon(int numberOfSides, Point centroid){
    this->numberOfSides = numberOfSides;
    this->centroid = centroid;
}

void virtual display(){
    std::cout << "The number of side in this polygon is " << this->numberOfSides << std::endl;
    std::cout << "The centroid of the polygon is:" << std::endl;
    std::cout << "("<<this->centroid.getX() << "," << this->centroid.getY() <<")" << std::endl;
}

void virtual move(int new_x, int new_y)
{
    this->centroid.setPoint(centroid.getX() + new_x, centroid.getY() + new_y);
}
};
//***********************************************************************
class Triangle : public Polygon
{
private:
Point vertex[3];

public:
Triangle(int numberOfSides, Point centroid, Point vertex[])
:Polygon(numberOfSides, centroid)
{
    int total_vertex = (sizeof(this->vertex) / sizeof(Point));
    for (int i = 0; i < total_vertex; i++)
    {
        this->vertex[i] = vertex[i];   
    }
}

void display(){
    std::cout << "The number of side of the given triangle is " << this->numberOfSides << std::endl;
    
    std::cout << "The vetrices are " << std::endl;
    for (int i = 0; i < (sizeof(this->vertex) / sizeof(Point)); i++)
    {
        std::cout << "("<<vertex[i].getX() << "," << vertex[i].getY() <<")" << std::endl;
    }

    std::cout << "The centroid of the triangle is:" << std::endl;
    std::cout << "("<<this->centroid.getX() << "," << this->centroid.getY() <<")" << std::endl;
}

void move(int new_x, int new_y)
{
    for (int i = 0; i < (sizeof(this->vertex) / sizeof(Point)); i++)
    {
        Point translated((vertex[i].getX() + new_x), (vertex[i].getY() + new_y));
        this->vertex[i] = translated;
    }

    this->centroid.setPoint(centroid.getX() + new_x, centroid.getY() + new_y);
}
};

//***************************************************************************
class Rectangle : public Polygon
{
private:
Point vertex[4];

public:
Rectangle(int numberOfSides, Point centroid, Point vertex[])
:Polygon(numberOfSides, centroid)
{
    int total_vertex = (sizeof(this->vertex) / sizeof(Point));
    for (int i = 0; i < total_vertex; i++)
    {
        this->vertex[i] = vertex[i];   
    }
}

void display(){
    std::cout << "The number of side of the given rectangle is " << this->numberOfSides << std::endl;
    
    std::cout << "The vetrices are " << std::endl;
    for (int i = 0; i < (sizeof(this->vertex) / sizeof(Point)); i++)
    {
        std::cout << "("<<vertex[i].getX() << "," << vertex[i].getY() <<")" << std::endl;
    }

    std::cout << "The centroid of the rectangle is:" << std::endl;
    std::cout << "("<<this->centroid.getX() << "," << this->centroid.getY() <<")" << std::endl;
}

void move(int new_x, int new_y)
{
    for (int i = 0; i < (sizeof(this->vertex) / sizeof(Point)); i++)
    {
        Point translated((vertex[i].getX() + new_x), (vertex[i].getY() + new_y));
        this->vertex[i] = translated;
    }

    this->centroid.setPoint(centroid.getX() + new_x, centroid.getY() + new_y);
}
};

//****************************************************************************

int main()
{
    Point tri_P1(0,0);
    Point tri_P2(1,0);
    Point tri_P3(0,1);
    Point tri_cent(1,2);

    
    Point triVertex[3];
    triVertex[0] = tri_P1;
    triVertex[1] = tri_P2;
    //triVertex[2] = tri_P3;

    Polygon* tri = new Triangle(3, tri_cent, triVertex);

    std::cout << "******Triangle before translation******" << std::endl;
    tri->display();
    std::cout << "******Triangle after translation******" << std::endl;
    tri->move(2,2);   
    tri->display();

    //********************************************************************
    Point rect_P1(0,0);
    Point rect_P2(2,0);
    Point rect_P3(0,2);
    Point rect_P4(2,2);
    Point rect_cent(1,1);

    
    Point rectVertex[4];
    rectVertex[0] = rect_P1;
    rectVertex[1] = rect_P2;
    rectVertex[2] = rect_P3;
    rectVertex[3] = rect_P4;

    Polygon* rect = new Rectangle(4, rect_cent, rectVertex);

    std::cout << "******Rectangle before translation******" << std::endl;
    rect->display();
    std::cout << "******Rectangle after translation******" << std::endl;
    rect->move(3,-1);   
    rect->display();

}