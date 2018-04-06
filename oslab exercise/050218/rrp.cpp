#include<iostream>
#include<iomanip>
#include<deque>
using namespace std;
int ea=1;
class Process
{
	public:
	int pid;
	int at;
	int bt;
	int tempt;
	bool ini;
	int pt;
	int wt,ct,tat;
	Process()
	{
		//cout<<"Enter process id: ";
		pid=ea++; 
		cout<<"Enter arrival time: ";
		cin>>at; 
		cout<<"Enter burst time: ";
		cin>>bt;
		cout<<"enter priority: ";
		cin>>pt; 
		tempt = bt;
		ini = false;
	}
};
int main()
{
	int n;
	int tq;
	cout<<"enter no of processs: ";
	cin>>n;
	deque<int> q;
	Process* p[n+1];
	int sumt = 0;
	for(int i=0;i<n;i++)
	{
		cout<<"Process "<<i+1<<": \n";
		p[i] = new Process();
		sumt += p[i]->bt; 
	}	
	cout<<"Enter time Quantum: ";
	cin>>tq;
	int ti=0;
	int tpq=tq;
	bool cp=true;
	for(ti=0;cp;ti++)
	{
		cp = false;
		for(int i=0;i<n;i++)
		{
			if(p[i]->at<=ti && p[i]->ini==false)
			{
				int k=q.front();
				if(k<0 || p[i]->pt<=p[k]->pt)
					q.push_back(i);
				else
				{
					q.pop_front();
					q.push_back(k);
					q.push_front(i);
					tpq=tq;
				}
				p[i]->ini=true;
			}
		}	
		if(q.empty())
		{
			cout<<"0 ";
		}
		else
		{
		
			int k = q.front();
			q.pop_front();
			//cout<<p[k]->pid<<" ";
			(p[k]->tempt)--;
			tpq--;
			if(p[k]->tempt>0)
			{
			if(tpq>0)
				q.push_front(k);
			else
			{
				tpq=tq;
				q.push_back(k);
			}
			}
			else
			{
				p[k]->tat=ti+1;
				p[k]->wt=p[k]->tat - p[k]->bt;
			}
		
		}	for(int i=0;i<n;i++)
			{
				if(p[i]->tempt>0)
					cp=true;
			}
		
	}
	cout<<"\n";
	float avgwt = 0,avgat = 0;
	cout<<"process id ------- arrival time  -----------  burst time  -----------------  completion time  ------------  waiting time  --------  tat\n";
	for(int i=0;i<n;i++)
	{
		cout<<p[i]->pid<<setw(5)<<" ------ "<<p[i]->at<<setw(5)<<" ----------- "<<p[i]->bt<<setw(5)<<" ------  "<<p[i]->ct<<setw(5)<<" ------  "<<p[i]->wt<<setw(5)<<" -------- "<<p[i]->tat<<"\n";
		avgat+=p[i]->tat;
		avgwt+=p[i]->wt;
	}
	avgat/=(float)n;
	avgwt/=(float)n;
	cout<<"Avgwt: "<<avgwt<<"\n";
	cout<<"Avgtat: "<<avgat<<"\n";
	return 0;
}
	
