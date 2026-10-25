
#include<stdio.h>

int main()
{
    int stock[3][4];
    int i,j,sum,max=0,aisle=0;
    int empty=0,total=0;

    printf("Enter stock of 12 shelves:\n");

    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            scanf("%d",&stock[i][j]);
        }
    }

    printf("\nOriginal stock:\n");

    for(i=0;i<3;i++)
    {
        printf("Aisle %d: ",i+1);

        for(j=0;j<4;j++)
        {
            printf("%d ",stock[i][j]);
        }

        printf("\n");
    }

    for(i=0;i<3;i++)
    {
        sum=0;

        for(j=0;j<4;j++)
        {
            sum=sum+stock[i][j];
        }

        if(sum>max)
        {
            max=sum;
            aisle=i+1;
        }
    }

    printf("\nAisle with most stock: Aisle %d (%d units)\n",
           aisle,max);

    printf("\nLow stock alerts:\n");

    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            if(stock[i][j]<5)
            {
                printf("Aisle %d, Position %d -> %d units\n",
                       i+1,j+1,stock[i][j]);
            }

            if(stock[i][j]==0)
            {
                empty++;
            }
        }
    }

    printf("Empty shelves: %d\n",empty);

    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            if(stock[i][j]<5)
            {
                stock[i][j]=stock[i][j]+10;
            }
        }
    }

    printf("\nStock after restocking:\n");

    for(i=0;i<3;i++)
    {
        printf("Aisle %d: ",i+1);

        for(j=0;j<4;j++)
        {
            printf("%d ",stock[i][j]);
            total=total+stock[i][j];
        }

        printf("\n");
    }

    printf("\nNew grand total: %d units\n",total);

    return 0;
}
