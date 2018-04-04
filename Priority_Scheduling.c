#include<stdio.h>
#include<stdlib.h>
struct process
{
	int id;int pri;int at;
	int bt;int ubt;int start;int wait;int comp;int tat;
	
};
int main()
{
	int time,p,i,j,r,working=-1;
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
				if(pro[i].start==-1)
				pro[i].start=time;
				working=i;
			}
		}
		printf("At time %d Process%d is running\n",time,pro[working].id);
		pro[working].ubt-=1;
		time=time+1;
		if(pro[working].ubt==0)
		{
			working=p;
			r--;
		}
	}
}
