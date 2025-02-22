#include<iostream>
using namespace std;
int main()
{
	int arr[4][4]={{45,52,56,45},{58,98,45,32},{15,81,150,35},{46,85,76,93}};
	int brr[4][4]={{45,45,56,45},{48,98,45,32},{15,01,150,35},{46,85,96,93}};
	int result[4][4]={{45,452,56,45},{48,98,45,32},{15,01,150,35},{46,85,96,93}};
	
	
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			cout<<arr[i][j]<<"\n";
			
		}
	}
	
	cout<<endl;
	
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			cout<<brr[i][j]<<"\n";
		}
	}
	
	cout<<endl;
	
	cout<<"Final result of cout ="<<endl;
	
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			result[i][j]=arr[i][j]*brr[i][j];
			cout<<result[i][j]<<"\n";
		}
	}
	
	cout<<endl;
	
	
	
	
	
	int ar[2][2];
	int br[2][2];
	int report[2][2];
	
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			cin>>ar[i][j];
		}
	}
	
	cout<<endl;
	
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			cin>>br[i][j];
		}
	}
	
	cout<<endl;
	
	cout<<"Final result in cin ="<<endl;
	
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			report[i][j]=ar[i][j]+br[i][j];
			cout<<report[i][j];
		}
	}
	
	cout<<endl;
	
	
	return 0;
}
