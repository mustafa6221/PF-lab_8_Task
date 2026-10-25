
#include<stdio.h>

int main()
{
    int image[4][4],result[4][4];
    int i,j,k,l;
    int amount,th;

    printf("Enter 16 pixel values:\n");

    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            scanf("%d",&image[i][j]);
        }
    }

    printf("Enter brightness amount: ");
    scanf("%d",&amount);

    printf("Enter threshold: ");
    scanf("%d",&th);

    printf("\nOriginal image:\n");

    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
            printf("%d ",image[i][j]);

        printf("\n");
    }

    printf("\nBrightness (%+d):\n",amount);

    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            result[i][j]=image[i][j]+amount;

            if(result[i][j]>255)
                result[i][j]=255;

            if(result[i][j]<0)
                result[i][j]=0;

            printf("%d ",result[i][j]);
        }

        printf("\n");
    }

    printf("\nBlack and white (threshold %d):\n",th);

    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(image[i][j]>=th)
                result[i][j]=255;
            else
                result[i][j]=0;

            printf("%d ",result[i][j]);
        }

        printf("\n");
    }

    printf("\nFlipped horizontally:\n");

    for(i=0;i<4;i++)
    {
        for(j=3;j>=0;j--)
            printf("%d ",image[i][j]);

        printf("\n");
    }

    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
            result[i][j]=image[i][j];
    }

    // A second array is used so changed pixels do not affect the next calculations.
    for(i=1;i<3;i++)
    {
        for(j=1;j<3;j++)
        {
            int sum=0;

            for(k=i-1;k<=i+1;k++)
            {
                for(l=j-1;l<=j+1;l++)
                {
                    sum=sum+image[k][l];
                }
            }

            result[i][j]=sum/9;
        }
    }

    printf("\nSmoothed image:\n");

    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
            printf("%d ",result[i][j]);

        printf("\n");
    }

    return 0;
}
