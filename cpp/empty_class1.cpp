#include<iostream>
#include<cstdlib>

using namespace std;

class A
{
	public :
	int a;
	void display()
	{
		cout<<"In class A display function"<<endl;
	}


};

int main()
{
	A *a;	
	//to call a function an Object need not be a valid object
	//To acess the member variables of class then the OBJECT should be a valid one
//	cout<<a->a<<endl; This causes segmentation fault
	a->display();// This not an error as fun is defined in code and we r not acessing any class variables
	//If acessing then it is an error
	return 0;
}	
