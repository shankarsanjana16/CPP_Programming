#include<iostream>
using namespace std;
int main()
{
	int age;
	cout<<"\nCHECK VOTING ELIGIBILITY HERE:\nEnter Your Age: ";
	cin>>age;
	if(age<18)
	{
		cout<<"Sorry, minors are not eligible to vote.";
	}
	else if(age==18)
	{
		cout<<"Congrats! You are finally a major! Now you are eligible to vote.";
	}
	else
	{
		cout<<"You are eligible to vote.";
	}
	cout<<"\n\n";
}