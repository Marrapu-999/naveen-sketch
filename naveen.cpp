  
	#include<stdio.h>
	int main()
	{
		int p[30];        
		int bt[40];
		 int su[40];
		  int wt[20],tat[30];
		  int j, k, n, temp;
		float wtavg, tatavg;
		printf("Enter the number of PROCESS  in the queue --- ");
		scanf("%d",&n);
		for(j=0;j<n;j++)
		{
			p[j] = j;
			printf("Enter the Burst Time for process  %d --- ", j);
			scanf("%d",&bt[j]);
			printf("teacher/student process (0/1) ? --- ");
			scanf("%d", &su[j]);
		}
		
		for(j=0;j<n;j++)
		{
			for(k=j+1;k<n;k++)
			{
				if(su[j] > su[k])
				{
					temp=p[j];
					p[j]=p[k];
					p[k]=temp;
					
					temp=bt[j];
					bt[j]=bt[k];
					bt[k]=temp;
					
					temp=su[j];
					su[j]=su[k];
					su[k]=temp;
				}
			}
		}
		wtavg = wt[0] = 0;
		tatavg = tat[0] = bt[0];
		for(j=1;j<n;j++)
		{
			wt[j] = wt[j-1] + bt[j-1];
			tat[j] = tat[j-1] + bt[j];
			wtavg = wtavg + wt[j];
			tatavg = tatavg + tat[j];
		}
		printf("\nPROCESS\t\t TEACHER/STUDENT PROCESS  \tBURST TIME\tWAITING TIME\tTURNAROUND TIME");
		
		for(j=0;j<n;j++)
		{
			printf("\n%d \t\t %d \t\t\t\t %d \t\t %d \t\t %d ",p[j],su[j],bt[j],wt[j],tat[j]);
		}
	

		printf("\nAverage Waiting Time is --- %f",wtavg/n);
		printf("\nAverage Turnaround Time is --- %f",tatavg/n);
	

		return 0;
	}


