#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string.h>
using namespace std;
struct Seat
{
	char name[100];
}*buses[10][32];
int vacant_seats = 320, bus_no = -1, seat_no = -1;
class Reservation
{
	public:
	void showSeats(char name[100]);
	void addReservation(char name[100]);
	void removeReservation(char name[100]);
	void checkReservation(char name[100]);
	void askForPayment(char name[100], char d[100], char a[100]);
};
void Reservation::showSeats(char name[100])
{
	for(int i = 0;i<10;i++)
	{
		for(int j = 0;j<7;j++)
		{
			cout<<(i+1)<<"-"<<(j+1)<<"\t";
		}
		cout<<"\n";
		for(int j = 1;j<=5;j++)
		{
			for(int k = 0;k<7;k++)
			{
				cout<<(i+1)<<"-";
				if((k==3)||(k==4))
				{
					continue;
				}
				if((k==5)||(k==6))
				{
					cout<<((j*7)-(k-2));
				}
				else
				{
					cout<<((j*7)-k);
				}
				cout<<"\t";
			}
			cout<<"\n";
		}
		cout<<"\t\t\t\t\t\tDOOR";
		cout<<"DRIVER'S SEAT\n\n";
	}
}
void Reservation::addReservation(char name[100])
{
	if(vacant_seats==0)
	{
		cout<<"None of the seats are vacant. Sorry for the inconvenience.";
		return;
	}
	int n;
	cout<<"How many seats do you wish to occupy? ";
	cin>>n;
	if(vacant_seats<n)
	{
		if(vacant_seats==1)
		{
			cout<<"Sadly, there is only 1 seat available. ";
		}
		else
		{
			cout<<"Sadly, there are only "<<vacant_seats<<" seats available. ";
		}
		char ch;
		cout<<"Would you like to continue? If yes, then either type 'y' or 'Y'. If no, then click on any other key.";
		cin>>ch;
		if((ch!='y')||(ch!='Y'))
		{
			return;
		}
		addReservation(name);
	}
	cout<<"The following are the seats that are vacant:\n";
	showSeats(name);
	if(n==1)
	{
		bool b = true;
		while(b)
		{
			cout<<"Enter the seat number that you wish to choose:\n\tBus Number: ";
			cin>>bus_no;
			bus_no--;
			cout<<"\tSeat Number: ";
			cin>>seat_no;
			seat_no--;
			if(buses[bus_no][seat_no]->name == name)
			{
				cout<<"Sorry, that seat is already reserved under the name of "<<name<<". Please try again.";
			}
			else if(buses[bus_no][seat_no]->name != "")
			{
				cout<<"Sorry, that seat is already reserved. Please try again.";
			}
			else
			{
				buses[bus_no][seat_no]->name = name;
				b = false;
			}
		}
	}
	else
	{
		cout<<"Enter the seat numbers that you wish to choose:";
		for(int i = 1;i<=n;i++)
		{
			cout<<"\n\tSeat Number "<<i<<":\n\t\tBus Number: ";
			cin>>bus_no;
			bus_no--;
			cout<<"\t\tSeat Number: ";
			cin>>seat_no;
			seat_no--;
			if(buses[bus_no][seat_no]->name != "")
			{
				cout<<"Sorry, that seat is already reserved. Please try again.";
				i--;
			}
			else
			{
				buses[bus_no][seat_no]->name = name;
			}
		}
	}
	vacant_seats--;
}
void Reservation::removeReservation(char name[100])
{
	if(vacant_seats==0)
	{
		cout<<"Sorry, could not remove reservation as all seats are empty.";
		return;
	}
	int n = 0;
	for(int i = 0;i<10;i++)
	{
		for(int j = 0;j<32;j++)
		{
			if(buses[i][j]->name==name)
			{
				n++;
			}
		}
	}
	if(n==0)
	{
		cout<<"\nSorry, could not remove reservations as no reservations under the name of "<<name<<" was found.";
		return;
	}
	checkReservation(name);
	char ch;
	cout<<"Would you like to continue? If yes, then either type 'y' or 'Y'. If no, then click on any other key.";
	cin>>ch;
	if((ch!='y')||(ch!='Y'))
	{
		return;
	}
	cout<<"How many seats do you wish to omit? ";
	cin>>n;
	for(int i = 1;i<=n;i++)
	{
		cout<<"\n\tSeat Number "<<i<<":\n\t\tBus Number: ";
		cin>>bus_no;
		bus_no--;
		cout<<"\t\tSeat Number: ";
		cin>>seat_no;
		seat_no--;
		if(buses[bus_no][seat_no]->name == "")
		{
			cout<<"Sorry, that seat is already vacant. Please try again.";
			i--;
		}
		else if(buses[bus_no][seat_no]->name != name)
		{
			cout<<"Sorry, that seat is not reserved under the name of "<<name<<". Please try again.";
			i--;
		}
		else
		{
			buses[bus_no][seat_no]->name = name;
		}
	}
	vacant_seats++;
}
void Reservation::checkReservation(char name[100])
{
	int n = 0;
	for(int i = 0;i<10;i++)
	{
		for(int j = 0;j<32;j++)
		{
			if(buses[i][j]->name==name)
			{
				n++;
			}
		}
	}
	if(n==0)
	{
		cout<<"\nSorry, no reservations under the name of "<<name<<" was found.";
	}
	n = 0;
	cout<<"Seats that are reserved under the name of "<<name<<" are as follows:";
	for(int i = 0;i<10;i++)
	{
		for(int j = 0;j<32;j++)
		{
			if(buses[i][j]->name==name)
			{
				cout<<"\n\tSeat "<<++n<<":\n\t\tBus Number: "<<(i+1)<<"\n\t\tSeat Number: "<<(j+1);
			}
		}
	}
	showSeats(name);
}
void Reservation::askForPayment(char name[100], char d[100], char a[100])
{
	int n = 0;
	for(int i = 0;i<10;i++)
	{
		for(int j = 0;j<32;j++)
		{
			if(buses[i][j]->name==name)
			{
				n++;
			}
		}
	}
	if(n==0)
	{
		cout<<"\nSorry, could not calculate the payment as no reservations under the name of "<<name<<" was found.";
		return;
	}
	cout<<"\nCost of each seat per minute = Rs10.";
	int d_hr = ((((int)(d[0]))*10)+((int)(d[1])));
	int d_min = ((((int)(d[3]))*10)+((int)(d[4])));
	int a_hr = ((((int)(a[0]))*10)+((int)(a[1])));
	int a_min = ((((int)(a[3]))*10)+((int)(a[4])));
	int total_time = (((a_hr-d_hr)*60)+(a_min-d_min));
	cout<<"\nTotal time of Travel = "<<total_time;
	cout<<"\nTotal Cost = "<<(total_time*10);
	cout<<"\nSAFE TRAVELS!";
}
int main()
{
	char name[100], gender[100], departure[100], arrival[100], pickup[100], destination[100];
	int age, choice;
	Reservation reserve;
	cout<<"BUS RESERVATION SYSTEM";
	cout<<"Enter you Name please: ";
	fgets(name,100,stdin);
	cout<<"And age: ";
	cin>>age;
	cout<<"And gender: ";
	fgets(gender,100,stdin);
	cout<<"Okay....Now, when do you want to board the bus?(hrs:mins) ";
	fgets(departure,100,stdin);
	cout<<"And by when do you want to reach your destination?(hrs:mins) ";
	fgets(arrival,100,stdin);
	cout<<"Okay Great! Now, from where do you want the bus to pick you up? ";
	fgets(pickup,100,stdin);
	cout<<"And where exactly do you want the bus to drop you? ";
	fgets(destination,100,stdin);
	cout<<"Okay cool. Now, select an option from the following menu to continue:";
	do
	{
		cout<<"\n1. Type '1' to see which seats are vacant.";
		cout<<"\n2. Type '2' to add seats to your reservation.";
		cout<<"\n3. Type '3' to check your reservation.";
		cout<<"\n4. Type '4' to remove seats from your reservation.";
		cout<<"\n5. Type '5' to confirm your reservation and continue with payment.";
		cout<<"Enter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				reserve.showSeats(name);
				break;
			case 2:
				reserve.addReservation(name);
				break;
			case 3:
				reserve.checkReservation(name);
				break;
			case 4:
				reserve.removeReservation(name);
				break;
			case 5:
				reserve.askForPayment(name,departure,arrival);
				return 0;
			default:
				cout<<"Sorry, this option is wrong.";
				continue;
		}
	}
	while(true);
}