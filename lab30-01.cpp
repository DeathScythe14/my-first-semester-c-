#include<iostream>
using namespace std;
int main()
{
	int A[8];
	int B[8];
	int Add[8];
	int mul[8];
	int sub[8];
	float divide[8];
	double modulus[8];
	cout<<"Enter value of 'A' = ";
	for(int i=0;i<8;i++)
	{
		cin>>A[i];
		cout<<endl;
	}
	cout<<"Enter value of 'b' = ";
	for(int i=0;i<8;i++)
	{
		cin>>B[i];
		cout<<endl;
	}
	

	cout<<"Result of the given array = ";
	for(int i=0;i<8;i++)
	{
		Add[i]=A[i]+B[i];
		cout<<Add[i]<<"\n";

	
	}
	
	cout<<"Result of the given array in multi = ";
	for(int i=0;i<8;i++)
	{
		mul[i]=A[i]*B[i];
		cout<<mul[i]<<"\n";
	}
	
	cout<<"Result of the given array in sub = ";
	for(int i=0;i<8;i++)
	{
		sub[i]=A[i]-B[i];
		cout<<sub[i]<<"\n";
	
	}
	
	
	
	
	cout<<"Result of the given array in divide = ";
	for(int i=0;i<8;i++)
	{
		divide[i]=A[i]/B[i];
		cout<<divide[i]<<"\n";
	
	
	}
	
	
	
	
	cout<<"Result of the given array in modulus = ";
	for(int i=0;i<8;i++)
	{
		modulus[i]=A[i]%B[i];
		cout<<modulus[i]<<"\n";
	}
	
	
	
	return 0;
}
