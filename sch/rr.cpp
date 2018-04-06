#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n],b[n],wt[n],tat[n],t[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
		t[i]=b[i];
	}
	int tq;
	cin>>tq;
	int count=0;
	int remain=n;
	int flag=0;
	for(int time=0;remain>0;)
	{
		if(b[count]<=tq && b[count] >0)
		{
			time=time+b[count];
			b[count]=0;
			remain--;
			tat[count]=time-a[count];
			wt[count]=tat[count]-t[count];
		}
		if(b[count]>0)
		{
			time+=tq;
			b[count]-=tq;
		}
		if(count==n-1)
			count=0;
		else if(a[count+1]<=time)
			count++;
		else
			count=0;
	}
	for(int i=0;i<n;i++)
		cout<<"\n"<<tat[i]<<" "<<wt[i]<<endl;
	return 0;
}
