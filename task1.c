
#include<stdio.h>

int main()
{
    int seats[5][6]={0};
    int r,c,i,j;
    int booked=0,empty=0;
    int count,max=0,row=1;

    while(1)
    {
        printf("Enter row and column (-1 to stop): ");
        scanf("%d",&r);

        if(r==-1)
            break;

        scanf("%d",&c);

        if(r<1 || r>5 || c<1 || c>6)
        {
            printf("Error: Invalid row or column!\n");
            continue;
        }

        if(seats[r-1][c-1]==1)
        {
            printf("Error: Seat already booked!\n");
        }
        else
        {
            seats[r-1][c-1]=1;
            printf("Seat booked successfully.\n");
        }
    }

    printf("\nSeating Chart:\n");
    printf("   ");

    for(j=1;j<=6;j++)
        printf("%d ",j);

    printf("\n");

    for(i=0;i<5;i++)
    {
        printf("Row %d ",i+1);

        for(j=0;j<6;j++)
        {
            if(seats[i][j]==1)
            {
                printf("X ");
                booked++;
            }
            else
            {
                printf("O ");
                empty++;
            }
        }

        printf("\n");
    }

    for(i=0;i<5;i++)
    {
        count=0;

        for(j=0;j<6;j++)
        {
            if(seats[i][j]==1)
                count++;
        }

        if(count>max)
        {
            max=count;
            row=i+1;
        }
    }

    printf("Total booked seats: %d\n",booked);
    printf("Total empty seats: %d\n",empty);
    printf("Row with most bookings: Row %d\n",row);

    return 0;
}
