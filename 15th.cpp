#include<stdio.h>
#include<conio.h>

struct process
{
	
int	cpu_burst,arrival_time,pid;
	
};
struct result
{
	int waiting_time;
	int turnaround,pid;
};
int main()
{

struct process p[50],cpy[50];
struct result r[50];
struct process temp;

int n,i,j,time,prior,pos,k,timet,sumturn=0,sumwait=0;

float avgturn,avgwait;

printf("enter the number of processes\n ");
scanf("%d",&n);

for(i=0;i<n;i++)
{
	
printf("for process %d\n",i);
p[i].pid=i;

A : 

{

printf("enter the arrival time(no two processes should have same arrival time)\n");
scanf("%d",&p[i].arrival_time);

for(j=i;j<0;j--)
{

if(p[j].arrival_time == p[j-1].arrival_time)
{

printf("no two processes should have same arrival time\n");
printf("enter arrival time of each process again\n");
goto A;
	
}

}
	
}


printf("enter the burst time\n");
scanf("%d",&p[i].cpu_burst);
	
}

printf("the details you entered is:\n");

for(int i=0;i<n;i++)
{
	
printf("for process %d : \n ",p[i].pid);
printf("CPU burst= %d \n ",p[i].cpu_burst);
printf("arrival time= %d \n",p[i].arrival_time);
	
}
for(j=0;j<n;j++)
{
for(i=0;i<n-1;i++)
{	
	
if(p[i].arrival_time > p[i+1].arrival_time )
{
	
temp=p[i];
p[i] = p[i+1]; 	
p[i+1]=temp;
	
}

}

}
for(i=0;i<n;i++)
{
	cpy[i]=p[i];
}
time= p[0].arrival_time;
pos=0;
k=n;

p[0].cpu_burst=p[0].cpu_burst-p[1].arrival_time+p[0].arrival_time;
timet=p[1].arrival_time-p[0].arrival_time;

printf("process- %d       %d\n",p[0].pid,p[0].cpu_burst);
r[0].waiting_time=0;
for(i=1;i<n-1;i++)
{
		prior = p[i].cpu_burst;
		for(j=i+1;j>=0;j--)
		{
			if(prior>=p[j].cpu_burst)
			{
				prior=p[j].cpu_burst;
				pos=j;
			}
		}
		if(cpy[pos].cpu_burst==p[pos].cpu_burst)
		{
		r[p[pos].pid].waiting_time=timet-p[pos].arrival_time;
		}
		p[pos].cpu_burst=p[pos].cpu_burst-(p[i+1].arrival_time-p[i].arrival_time);
		timet=timet+p[i+1].arrival_time-p[i].arrival_time;
		printf("process- %d        %d\n",p[pos].pid,p[pos].cpu_burst);
		if(p[pos].cpu_burst<0)
		{
			
			time = -p[pos].cpu_burst;	
			while(time>0)
			{
					if(cpy[pos].cpu_burst==p[pos].cpu_burst)
					{
		   				r[p[pos].pid].waiting_time=timet-p[pos].arrival_time;
					} 
					r[p[pos].pid].turnaround=timet-p[pos].arrival_time;
				printf("process- %d  COMPLETED     %d\n",p[pos].pid,p[pos].cpu_burst);
				for(j=pos;j<n;j++)
          	 	{
             	   p[j]=p[j+1];
             	   cpy[j]=cpy[j+1];
          		}
          		n--;
          		i--;
				prior=p[pos].cpu_burst;
				for(j=0;j<=i+1;j++)
				{
					if(prior>=p[j].cpu_burst)
					{
						prior=p[j].cpu_burst;
						pos=j;
					}
				}
				p[pos].cpu_burst=p[pos].cpu_burst-time;
				timet=timet+time;
				
				time = -p[pos].cpu_burst;
				
			}
		}
		if(p[pos].cpu_burst==0)
		{
					if(cpy[pos].cpu_burst==p[pos].cpu_burst)
					{
						r[p[pos].pid].waiting_time=timet-p[pos].arrival_time;
						}
						r[p[pos].pid].turnaround=timet-p[pos].arrival_time;
				printf("process- %d  COMPLETED     %d\n",p[pos].pid,p[pos].cpu_burst);
				for(j=pos;j<n;j++)
          	 	{
             	   p[j]=p[j+1];
             	   cpy[j]=cpy[j+1];
          		}
          		n--;
          		i--;
			
		}
}
for(i=0;i<n;i++)
{
		prior = p[i].cpu_burst;
		for(j=0;j<n;j++)
		{
			if(prior>=p[j].cpu_burst)
			{
				prior=p[j].cpu_burst;
				pos=j;
			}
		}
		if(cpy[pos].cpu_burst==p[pos].cpu_burst)
		{
			r[p[pos].pid].waiting_time=timet-p[pos].arrival_time;
		}
		timet=timet+p[pos].cpu_burst;
		r[p[pos].pid].turnaround=timet-p[pos].arrival_time;
		printf("process- %d  COMPLETED     %d\n",p[pos].pid,p[pos].cpu_burst);
				for(j=pos;j<n;j++)
          	 	{
             	   p[j]=p[j+1];
             	   cpy[j]=cpy[j+1];
          		}
          		n--;
          		i--;
		
	}
     	printf("\n\n\n\nProcess No.    Waiting time      TurnAround time\n\n");
	for(i=0;i<k;i++)
	{
		printf("Process -%d        %d                  %d\n",i,r[i].waiting_time,r[i].turnaround);
		sumturn=sumturn+r[i].turnaround;
		sumwait=sumwait+r[i].waiting_time;
		
	}
	avgturn=(float)(sumturn/k);
	avgwait=(float)(sumwait/k);
	printf("\n\nAVERAGE WAITING TIME =  %f\nAVERAGE TURN AROUND TIME  =  %f",avgwait,avgturn);
}


