#include<stdio.h>
#include<stdlib.h>
struct process
{
	int id;int pri;int at;
	int bt;int ubt;int start;int wait;int comp;int tat;
	
};
void increasepri(struct process p[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(p[i].wait!=0&&p[i].wait%2==0)
		{
			if(p[i].pri>1)
			p[i].pri-=1;
		}
	}
}
int main()
{
	int time,p,i,j,r,working=-1,current;
	float avgtat=0,avgwt=0;
	printf("Enter number of processes\n");
	scanf("%d",&p);
	struct process pro[p+1];
	printf("For the Processes Enter the Arrival Time Burst Time Priority\n");
	for(i=0;i<p;i++)
	{
		printf("For process P%d ",i+1);
		pro[i].id=i+1;
		scanf("%d",&pro[i].at);
		scanf("%d",&pro[i].bt);
		scanf("%d",&pro[i].pri);
		pro[i].wait=0;
		pro[i].start=-1;
		pro[i].ubt=pro[i].bt;
	}
	pro[p].pri=INT_MAX;
	printf("\nP AT BT Priority\n");
	for(i=0;i<p;i++)
	{
		printf("%d  %d  %d  %d\n",pro[i].id,pro[i].at,pro[i].bt,pro[i].pri);
	}
	time=0;
	working=p;
	r=p;
	while(r!=0)
	{
		for(i=0;i<p;i++)
		{	
			if(pro[i].at<=time && pro[i].ubt!=0 && pro[i].pri<pro[working].pri)
			{
				
				working=i;
				if(i!=working)
				pro[i].wait+=1;
			}
		}
		if(pro[working].start==-1)
		{
			if(r!=p)
			{
			pro[working].start=time+2;
			}
			else
			pro[working].start=time;
		}
	//	printf("At time %d Process%d is running\n",time,pro[working].id);
		pro[working].ubt-=1;
		current=working;
		time=time+1;
		increasepri(pro,p);
		 if(pro[working].ubt==0)
		{
			pro[working].comp=time;
			time+=2;
			current=working;
			increasepri(pro,p);
			working=p;
			r--;
		}
		if(r!=10&&current!=working)
		{
			time+=2;
			current=working;
		}
	}
	printf("\n\nProcess   AT   BT   CT   TAT   WT\n");
	for(i=0;i<p;i++)
	{
		pro[i].tat=pro[i].comp-pro[i].at;
		avgtat=avgtat+pro[i].tat;
		pro[i].wait=pro[i].tat-pro[i].bt;
		avgwt=avgwt+pro[i].wait;
		printf("%7d   %2d   %2d   %2d   %2d   %2d\n",pro[i].id,pro[i].at,pro[i].bt,pro[i].comp,pro[i].tat,pro[i].wait);
	}
	avgwt=(avgwt*1.0)/(p*1.0);
	avgtat=(avgtat*1.0)/(p*1.0);
	printf("Average waiting time is %0.2f\nAverage TAT is %0.2f\n",avgwt,avgtat);
}
