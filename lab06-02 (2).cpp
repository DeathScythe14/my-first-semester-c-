#include<iostream>
#include<string>
using namespace std;
int main()
{
	string arr[1][4]={{"Syed Ali Hasnian Shah"}};
	string brr[1][4]={{"Syed Amir Husain Shah"}};
	string result[1][4];
	
	
	for(int i=0;i<1;i++)
	{
		for(int j=0;j<4;j++)
		{
			cout<<arr[i][j]<<"\n";
			
		}
	}
	
	cout<<endl;
	
	for(int i=0;i<1;i++)
	{
		for(int j=0;j<4;j++)
		{
			cout<<brr[i][j]<<"\n";
		}
	}
	
	cout<<endl;
	
	cout<<"Final result of cout ="<<endl;
	
	for(int i=0;i<1;i++)
	{
		for(int j=0;j<4;j++)
		{
			result[i][j]=arr[i][j]+brr[i][j];
			cout<<result[i][j]<<"\n";
		}
	}
	
	cout<<endl;
	return 0;
}
