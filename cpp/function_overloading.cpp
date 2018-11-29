#include<iostream>
//fn ovrd follows compile time polymorphism
//compiler gives diff names to the same name funtions called as name mangling
using namespace std;
int add(int a,int b,int c=0,int d=0,int e=0)//fn with default arguments
{
	return(a+b+c+d+e);
}
/*
// This function call is ambiguious if called with two parameters
int add(int a, int b)
{
	return (a+b);
}

*/

float add(float a,float b)
{
	return(a+b);
}
float add(int a, float b)
{
	return(a+b);
}
float add(float a,int b)
{
	return(a+b);
}

main()
{
	cout<<add(1,2,3)<<endl;
	cout<<add(2,2.3f)<<endl;
	cout<<add(2.3f,3.2f)<<endl;

}



