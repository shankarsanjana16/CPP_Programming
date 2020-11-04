#include<iostream>
using namespace std;
int main()
{
	int length;
	cout<<"\nEnter Maximum Length of the Array: ";
	cin>>length;
	int array[length], *ptr, l = 0;
	ptr = array;
	cout<<"Enter elements:\n";
	while(l<length)
	{
		cin>>*ptr++;
		l++;
	}
	l = 0;
	ptr = array;
	cout<<"You enterted:\n";
	while(l<length)
	{
		cout<<*ptr++<<" ";
		l++;
	}
	cout<<"\n\n";
}