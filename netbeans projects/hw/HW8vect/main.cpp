#include "vector.h"
#include <iostream>
using namespace std;
int main()
{
	Vector a;    //test defalut constructor
	cout<<a<<endl;
	
	if(a.isEmpty())
	cout<<"is empty"<<endl;
	else 
	cout<<"not empty"<<endl;   //test empty()
	
	
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);
	a.push_back(6);
	a.push_back(7);
	cout<<a<<endl;             //test push_back()
	
	a.erase(0);           //test erase(0);
	cout<<a<<endl;
	
	a.erase(2,4);			//test erase(2,4);
	cout<<a<<endl;
	
	a.insert(1,22);           //test insert();
	cout<<a<<endl;
	
	a.pop_back();            //test pop_back();
	cout<<a<<endl;
	
	cout<<"before shrink_to_fit the capacity is "<<a.expandCapacity()<<endl;  //test expandCapacity()
	cout<<"before shrink_to_fit the size is "<<a.size()<<endl;       //test size()
	a.shrink_to_fit();        //test shrink_to_fit()
	cout<<"after shrink_to_fit the capacity is "<<a.expandCapacity()<<endl;  //test expandCapacity()
	cout<<"after shrink_to_fit the size is "<<a.size()<<endl;       //test size()

	a.resize(10);             //test resize()
	cout<<"after a.resize(10);  the capacity is "<<a.expandCapacity()<<endl;  //test expandCapacity()
	cout<<"after a.resize(10);  the size is "<<a.size()<<endl;       //test size()
	return 0;

}