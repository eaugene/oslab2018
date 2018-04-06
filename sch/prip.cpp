#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n],b[n+1],p[n+1],wt[n],tat[n],t[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>p[i]>>b[i];
		t[i]=b[i];
	}
	b[n+1]=99999;
	p[n+1]=-9999;
	int smallest=0;
	int count=0;
	for(int time=0;count != n;time++)
	{
		smallest=n+1;
		for(int i=0;i<n;i++)
		{
			if(a[i]<=time && p[i]>p[smallest] && b[i] >0)
			{
				smallest=i;
			}
		}
		b[smallest]--;
		if(b[smallest]==0)
		{
			count++;
			int ct=time+1;
			tat[smallest]=ct-a[smallest];
			wt[smallest]=tat[smallest]-t[smallest];
		}
	}
	for(int i=0;i<n;i++)
		cout<<"\n"<<tat[i]<<" "<<wt[i]<<endl;
	return 0;
}
