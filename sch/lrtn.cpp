#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n],b[n+1],t[n],wt[n],tat[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
		t[i]=b[i];
	}
	b[n+1]=-9999;
	int smallest=0;
	int count=0;
	for(int time=0;count !=n;)
	{
		smallest=n+1;
		for(int i=0;i<n;i++)
		{
			if( a[i]<=time && b[i] > 0 &&b[i]>b[smallest])
				smallest=i;
		}
		b[smallest]=0;
		count++;
		time=time+t[smallest];
			tat[smallest]=time-a[smallest];
			wt[smallest]=tat[smallest]-t[smallest];
	}
	for(int i=0;i<n;i++)
		cout<<"\n"<<tat[i]<<" "<<wt[i]<<endl;
	return 0;
}
