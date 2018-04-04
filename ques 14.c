#include<stdio.h>
#include<stdlib.h>
struct process
{
	int status;
	int pid;
	int priority;
	int arr_time;
	int burst_time;
	int updated_burst_time;
	int start;
	int wait;
	int complete;
	int tat;
	
};
void sort(struct process p[],int n)
{
	int i,j;
	struct process temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(p[j].arr_time>p[j+1].arr_time)
			{
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;	
			}
		}
	}
}
int main()
{
	int time,p,i,j,running=-1;
	printf("Enter number of processes(less than equal to 10)\n");
	scanf("%d",&p);
	struct process pro[p];
	for(i=0;i<p;i++)
	{
		printf("For process P %d \nEnter",i+1);
		printf("Arrival Time Burst Time Priority\n");
		pro[i].pid=i+1;
		scanf("%d",&pro[i].arr_time);
		scanf("%d",&pro[i].burst_time);
		scanf("%d",&pro[i].priority);
		pro[i].updated_burst_time=pro[i].burst_time;
		pro[i].status=0;
		pro[i].complete=0;
	}
	sort(pro,p);
	printf("Process P \tArrivalTime \tBurstTime \tPriority\n");
	for(i=0;i<p;i++)
	{
		printf("%d \t%d \t%d \t%d\n",pro[i].pid,pro[i].arr_time,pro[i].burst_time,pro[i].priority);
	}
	time=pro[0].arr_time;
	running=0;
	while(time<20)
	{
		for(i=0;i<p;i++)
		{	
			if(pro[i].status==0&&pro[running].updated_burst_time!=0)
			{
			if(pro[i].arr_time<=time)
			{
				if(pro[i].priority<pro[running].priority)
				{
					running=i;
				}
				else if(pro[i].priority==pro[running].priority)
				{
					if(pro[i].arr_time==pro[running].arr_time)
					{
						if(pro[i].updated_burst_time<pro[running].updated_burst_time)
						{
							running=i;
						}
					}
				}
			}
			}
		}
		printf("At time %d Process %d is running\n",time,pro[running].pid);
		pro[running].updated_burst_time-=1;
		time=time+1;
		if(pro[running].updated_burst_time==0)
		{
			pro[running].complete=time;
			pro[running].status=1;
		}
	}
	/*printf("Process P \tArrivalTime \tBurstTime \tPriority \tUpdated BurstTime\n");
	for(i=0;i<p;i++)
	{
		printf("%d \t%d \t%d \t%d \t%d\n",pro[i].pid,pro[i].arr_time,pro[i].burst_time,pro[i].priority,pro[i].complete);
	}*/
}

