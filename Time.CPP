#include<iostream>
using namespace std;
class Time
{
	int hours, minutes, seconds;
	public:
	void takeTime(int secs, int mins, int hrs);
	void displayTime();
	int timeInSeconds();
};
void Time::takeTime(int secs, int mins, int hrs)
{
	seconds = secs;
	minutes = mins;
	hours = hrs;
}
void Time::displayTime()
{
	cout<<"The time is = ";
	if(hours<10)
	{
		cout<<"0";
	}
	cout<<hours<<":";
	if(minutes<10)
	{
		cout<<"0";
	}
	cout<<minutes<<":";
	if(seconds<10)
	{
		cout<<"0";
	}
	cout<<seconds;
}
int Time::timeInSeconds()
{
	return(seconds+(minutes*60)+(hours*3600));
}
int main()
{
	Time t;
	int seconds, minutes, hours;
	cout<<"\nHours? ";
	cin>>hours;
	cout<<"Minutes? ";
	cin>>minutes;
	cout<<"Seconds? ";
	cin>>seconds;
	t.takeTime(seconds,minutes,hours);
	t.displayTime();
	cout<<"\nTime in total Seconds: "<<t.timeInSeconds()<<"\n\n";
}