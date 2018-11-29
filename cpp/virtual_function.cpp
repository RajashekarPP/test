// virtual destructor in base class is used to call the derived class destructor when the base class destructor is called

#include<iostream>
#include<cstdio>

using namespace std;

class shape
{
public:
	virtual void area()=0;	
	shape()
	{
		puts("In default constructor of shape");
	}	
	virtual ~shape()
	{
		puts("In default destructor of shape");
	}
	
};

class rectangle:public shape
{
	float length , breadth;
public:
	rectangle()
	{
		puts("In default constructor of rectangle");
		cout<<"enter length and breadth of rectangle"<<endl;
		cin>>length>>breadth;
	}
	~rectangle()
	{
		cout<<"In default destructor of rectangle"<<endl;
	}
	void area()
	{
		float area;
		area = length*breadth;
		cout<<"Area of the rectangle is "<<area<<endl;
	}
};


class circle:public shape
{
	float radius;
public:
	circle()
	{
		puts("In default constructor of CIRCLE\nEnter the radius ");
		cin>>radius;
	}	
	~circle()
	{
		cout<<"In default destructor of circle"<<endl;
	}
	void area()
	{
		float area;
		area = 3.14*radius*radius;
		cout<<"area of the circle is "<<area<<endl;
	}

};

int main()
{
/*
	rectangle r;
	circle c;
	r.area();
	c.area();
*/
	rectangle *r1 = new rectangle();
	shape *s1 = r1;
	r1->area();
//	delete s1;
	delete r1;
	return 0;
}
