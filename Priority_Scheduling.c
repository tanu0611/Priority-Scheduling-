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
