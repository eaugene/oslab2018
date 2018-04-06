#include<bits/stdc++.h>
using namespace std;
float rr(int v,int s)
{
	float y=0;
	y=(float)v/s;
	y=y+1.0000;
	return y;
}
int main()
{
	int n;
	cin>>n;
	int a[n],b[n],t[n],wt[n],tat[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
		t[i]=b[i];
	}
	float r=-999.999;
	int count=0;
	int smallest;
	for(int time=0;count !=n;)
	{
		r=-999.999;
            	smallest=n+1;
		for(int i=0;i<n;i++)
		{
			
			if(a[i]<=time && b[i] > 0)
			{
				float ri=rr(time-a[i],b[i]);
				if(ri > r)
				{
					smallest=i;
					r=ri;
				}
			}
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

