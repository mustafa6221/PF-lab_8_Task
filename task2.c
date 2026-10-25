
#include<stdio.h>

int main()
{
    int marks[4][3];
    int total[4],i,j,sum;
    int high,low,top=0,worst=0;
    float avg[4],savg[3];

    for(i=0;i<4;i++)
    {
        for(j=0;j<3;j++)
        {
            do
            {
                scanf("%d",&marks[i][j]);

                if(marks[i][j]<0 || marks[i][j]>100)
                    printf("Invalid mark! Enter a value between 0 and 100.\n");

            }while(marks[i][j]<0 || marks[i][j]>100);
        }
    }

    for(i=0;i<4;i++)
    {
        sum=0;

        for(j=0;j<3;j++)
            sum=sum+marks[i][j];

        total[i]=sum;
        avg[i]=sum/3.0;

        if(avg[i]>avg[top] || i==0)
            top=i;
    }

    printf("\n%-12s %6s %6s %6s %7s %8s %6s\n",
           "Student","Prog","Calc","Phys","Total","Average","Grade");

    for(i=0;i<4;i++)
    {
        printf("Student %-3d",i+1);

        for(j=0;j<3;j++)
            printf("%6d",marks[i][j]);

        printf("%7d %8.2f",total[i],avg[i]);

        if(avg[i]>=80)
            printf("%6s\n","A");
        else if(avg[i]>=65)
            printf("%6s\n","B");
        else if(avg[i]>=50)
            printf("%6s\n","C");
        else
            printf("%6s\n","F");
    }

    printf("\nSubject statistics:\n");
    printf("%-15s %8s %8s %8s\n",
           "Subject","Highest","Lowest","Average");

    for(j=0;j<3;j++)
    {
        high=marks[0][j];
        low=marks[0][j];
        sum=0;

        for(i=0;i<4;i++)
        {
            sum=sum+marks[i][j];

            if(marks[i][j]>high)
                high=marks[i][j];

            if(marks[i][j]<low)
                low=marks[i][j];
        }

        savg[j]=sum/4.0;

        if(savg[j]<savg[worst] || j==0)
            worst=j;

        if(j==0)
            printf("%-15s","Programming");
        else if(j==1)
            printf("%-15s","Calculus");
        else
            printf("%-15s","Physics");

        printf("%8d %8d %8.2f\n",high,low,savg[j]);
    }

    printf("\nTop student: Student %d (Average %.2f)\n",
           top+1,avg[top]);

    if(worst==0)
        printf("Worst subject: Programming");
    else if(worst==1)
        printf("Worst subject: Calculus");
    else
        printf("Worst subject: Physics");

    printf(" (Average %.2f)\n",savg[worst]);

    return 0;
}
