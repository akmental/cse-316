#include<stdio.h>
#include<conio.h>
int main()
{
    int Burst_Time[10],Process_no[10],Waiting_Time[10],Turn_Around_Time[10];
    int Arrival_Time[10],Prior[10],i,j,Number_of_Process,tot=0,flag,temp,Avg_Waiting_Time,Avg_Turn_Around_Time;
    printf("Enter Number of Process:");
    scanf("%d",&Number_of_Process);
    printf("\nEnter Burst Time and Prior\n");
    for(i=0;i<Number_of_Process;i++)
    {
        printf("\nP[%d]\n",(i+1));
        printf("Enter Burst Time:");
        scanf("%d",&Burst_Time[i]);
        printf("Enter Arrival Time:");
        scanf("%d",&Arrival_Time[i]);
        printf("Enter Prior:");
        scanf("%d",&Prior[i]);
        Process_no[i]=i+1;
    }
    for(i=0;i<Number_of_Process;i++)
    {
        flag=i;
        for(j=i+1;j<Number_of_Process;j++)
        {
            if(Prior[j]<Prior[flag])
            flag=j;
        }
        temp=Prior[i];
        Prior[i]=Prior[flag];
        Prior[flag]=temp;
        temp=Burst_Time[i];
        Burst_Time[i]=Burst_Time[flag];
        Burst_Time[flag]=temp;
        temp=Process_no[i];
        Process_no[i]=Process_no[flag];
        Process_no[flag]=temp;
    }
    Waiting_Time[0]=0;  
    for(i=1;i<Number_of_Process;i++)
    {
        Waiting_Time[i]=0;
        for(j=0;j<i;j++)
            Waiting_Time[i]+=Burst_Time[j];
        tot+=Waiting_Time[i];
    }
    Avg_Waiting_Time=tot/Number_of_Process;  
    tot=0;
    printf("_______________________________________________________________");
    printf("\nProcess\t       B T              W T                T A T");
    for(i=0;i<Number_of_Process;i++)
    {
        Turn_Around_Time[i]=Burst_Time[i]+Waiting_Time[i];  
        tot+=Turn_Around_Time[i];
        printf("\nProcess %d \t %d\t \t   %d\t\t%d",Process_no[i],Burst_Time[i],Waiting_Time[i],Turn_Around_Time[i]);
    }
        printf("\n_______________________________________________________________");
    Avg_Turn_Around_Time=tot/Number_of_Process;
    printf("\n\nAvg W T= %d",Avg_Waiting_Time);
    printf("\nAvg T A T= %d",Avg_Turn_Around_Time);
    return 0;
} 


// Code End





