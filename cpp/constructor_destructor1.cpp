
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
	A *a = new A(11);
	puts("object a ");
	a->display();
/*	puts("object b");
	b.display();
	puts("object c");
	c.display();
	puts("object d");
	d.display();
*/
	delete a;
	return 0;
}
