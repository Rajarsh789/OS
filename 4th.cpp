#include<stdio.h>
#include<stdlib.h>
int main()
{
	int number=4;
	printf("Enter the number of process  ");//taking number of process
	scanf("%d",&number);
	if(number<=0)
	{
		exit(0);
	}
	float arrival[number];//for arrival time of each process
	float burst[number];//for burst time of each processs
	float pri[number];//variable array for priority calvulation
	float gantt;    //variable to store the gantt value 
	float done[number];//the process done at which time
	float wait[number];//variable array for waiting time for each traversal
	float WT[number];   //array to store the final waiting time
    float TA[number];   //array to store the turn arount time
	int i,l=0;
	//for taking burst and arrival time of each process
	for(i=0;i<number;i++)
	{
		printf("enter the arrival time for process P%d ",i+1);
		scanf("%f",&arrival[i]);
		
	}
	for(i=0;i<number;i++)
	{
		printf("enter the burst time for process P%d ",i+1);
		scanf("%f",&burst[i]);
		
	}
	///////////////////////////////////////////////
	float sum=0;//variable to get the sum of all burst time for running the loop
	for(i=0;i<number;i++)
	{
		sum=sum+burst[i];
		
	}
	float min;
	for(i=0;i<number;i++)
	{
		if(arrival[i]==0)
		{
			min=burst[i];//to know which process arrives at 0
		     l=i;
		     
			break;
		}
		
	
	}

	gantt=min;//first of all that process will run
	for(i=0;i<number;i++)
	{
		if(arrival[i]==0)
		{
			wait[i]=0;
			
		}
		else
		{
		    wait[i]=gantt-arrival[i];
	    }
	}
	for(i=0;i<number;i++)
	{
		if(arrival[i]==0)
		{
			pri[i]=0;
		}
		else
		{
		pri[i]=1+(wait[i]/burst[i]);
	    }
		
}
//till here we are calculating priority for first time 
    int min_pri;
	int j=0,k=0;
	while(gantt<=(sum+min))
	{
		for(i=0;i<number;i++)
		{
			if(pri[i]==0)
			{
				continue;
			}
			else
			{
				if(min_pri<pri[i])
				{
					min_pri=pri[i];
					j=i;
				}
			}
		}
		
		gantt=gantt+burst[j];
		done[j]=gantt;
		for(i=0;i<number;i++)
	{
		if(done[i]>0)
		{
			wait[i]=0;
			continue;
		}
		else
		{
		    wait[i]=gantt-arrival[i];
	    }
	}
	for(i=0;i<number;i++)
	{
		if(done[i]>0)
		{
			pri[i]=0;
		}
		else
		{
			if(wait[i]!=0)
	      {
			pri[i]=1+(wait[i]/burst[i]);
	      }
	}
	}
	k++;
	j=0;	
	}
	for(i=0;i<number;i++)
	{
		if(arrival[i]==0)
		{
			done[i]=burst[i];
			break;
		}
	}
	for(i=0;i<number;i++)
	{
		if(done[i]<1)
		{
			done[i]=sum;
		}
	}
	
   
    for(i=0;i<number;i++)
    {
    	WT[i]=done[i]-burst[i]-arrival[i];
	}
	 for(i=0;i<number;i++)
    {
    	TA[i]=WT[i]+burst[i];
	}
	printf("\n\tAT\t          \tBT\t          \tWT\t          \tTA\t");
	for(i=0;i<number;i++)
	{
		printf("\n\t%f\t|\t%f\t|\t%f\t|\t%f\t",arrival[i],burst[i],WT[i],TA[i]);
	}
	float avrgW=0;//average waiting time
	float avrgT=0;//average turn around time
	for(i=0;i<number;i++)
	{
		 avrgW=avrgW+WT[i];
		 avrgT=avrgT+TA[i];
	}
	avrgW=avrgW/number;
	avrgT=avrgT/number;

	printf("\n\n The average waiting time= %f",avrgW);
	printf("\n\n The average turn around time time= %f",avrgT);
	
	return 0;
}
