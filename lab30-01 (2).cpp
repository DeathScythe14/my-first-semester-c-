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
		mul[i]=A[i]*B[i];
		divide[i]=A[i]/B[i];
		sub[i]=A[i]-B[i];
		modulus[i]=A[i]%B[i];
	    
	}
	cout<<"index\t add\t sub\t mul\t divide\t modulus\n";
	for(int i=0;i<8;i++)
	{
		cout<<i<<"\t"<<Add[i]<<"\t"<<sub[i]<<"\t"<<mul[i]<<"\t"<<divide[i]<<"\t"<<modulus[i]<<endl;
	}
	return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
