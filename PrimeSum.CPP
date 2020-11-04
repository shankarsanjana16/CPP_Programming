#include<iostream>
using namespace std;
bool isPrime(int x, int t)
{
	if(t==x)
	{
		return true;
	}
	if((x%t)==0)
	{
		return false;
	}
	return isPrime(x,(t+1));
}
int main()
{
	int n;
	cout<<"\nEnter a +ve Integer: ";
	cin>>n;
	if(n<0)
	{
		cout<<n<<" is -ve\n\n";
		return 0;
	}
	int l = 0;
	for(int i = 2;i<=(n/2);i++)
	{
		if((isPrime(i,2))&&(isPrime((n-i),2)))
		{
			cout<<n<<" = "<<i<<" + "<<(n-i)<<"\n";
			l++;
		}
	}
	if(l==0)
	{
		cout<<"Sorry. "<<n<<" cannot be expressed as a Sum of 2 Prime Numbers.";
	}
	cout<<"\n";
}