#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int p[n],a[n+1],b[n+1],t[n+1],wt[n],tat[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
		t[i]=b[i];
		p[i]=i;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				int temp=a[i];
				a[i]=a[j];
				a[j]=temp;
				temp=b[i];
				b[i]=b[j];
				b[j]=temp;
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
				temp=t[i];
				t[i]=t[j];
				t[j]=temp;
			}
			else if(a[i] == a[j] && b[i] > b[j])
			{	
				int temp=a[i];
				a[i]=a[j];
				a[j]=temp;
				temp=b[i];
				b[i]=b[j];
				b[j]=temp;
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
				temp=t[i];
				t[i]=t[j];
				t[j]=temp;
			}
			else
			{
			}
		}
	}
	for(int i=0;i<n;i++)
		cout<<"\n"<<p[i]<<" "<<a[i]<<" "<<b[i]<<" "<<t[i]<<endl;
int count=0;
b[n+1]=99999;
int smallest=0;
	for(int time=0;count!=n;)
	{
		smallest=n+1;
		for(int j=0;j<n;j++)
		{
			if(a[j]<=time && b[j] > 0 && b[j]<b[smallest])
				smallest=j;
		}
		cout<<"\n####"<<smallest;
		count++;
b[smallest]=0;
		time=time+t[smallest];
		int pt=p[smallest];
		tat[pt]=time-a[smallest];
		wt[pt]=tat[pt]-t[smallest];
	}

	cout<<"\n******************************\n";
	for(int i=0;i<n;i++)
		cout<<"\n"<<tat[i]<<" "<<wt[i]<<endl;
	return 0;
}
