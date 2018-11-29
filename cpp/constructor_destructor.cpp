
#include<iostream>
#include<cstdio>

using namespace std;

class A
{
	int a;
public:
	void display();
	A(int );
	A(const A& );
	A();//constructor
	~A();//Destructor
};

void A::display()
{
	cout<<"a = "<<a<<endl;
	return;
}

A::A(const A &c)
{
	cout<<"In copy constructor"<<endl;
	a=c.a;
}

A::A(int p)
{
	cout<<"In parametarized constructor"<<endl;
	a=p;
}
A::A()
{
	cout<<"In default constructor"<<endl;
	cout<<"enter a value"<<endl;
	cin>>a;
}

A::~A()
{
	cout<<"in default destructor"<<endl;
}

int main()
{
	A a(11);// parametarized constructor will b called

	A b; //default constructor will be called
	A c(a); //copy constructor will b called
	A d=b; //declaration  come initialization means copy constructor is called not the assign operator overloading
	puts("object a ");
	a.display();
	puts("object b");
	b.display();
	puts("object c");
	c.display();
	puts("object d");
	d.display();
	//a.~A();
	//b.~A();
	return 0;
}
