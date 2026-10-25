
#include<stdio.h>

int main()
{
    int a[3][3][3];
    int i,j,k,sum=0,high,low;
    float avg;

    printf("Enter 27 elements:\n");

    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            for(k=0;k<3;k++)
                scanf("%d",&a[i][j][k]);

    high=a[0][0][0];
    low=a[0][0][0];

    for(i=0;i<3;i++){
        int total=0;

        printf("\nLayer %d:\n",i+1);

        for(j=0;j<3;j++){
            for(k=0;k<3;k++){
                printf("%d ",a[i][j][k]);

                total=total+a[i][j][k];
                sum=sum+a[i][j][k];

                if(a[i][j][k]>high)
                    high=a[i][j][k];

                if(a[i][j][k]<low)
                    low=a[i][j][k];
            }
            printf("\n");
        }

        avg=total/9.0;

        printf("Layer Total = %d\n",total);
        printf("Layer Average = %.2f\n",avg);
    }

    printf("\nOverall Total = %d\n",sum);
    printf("Overall Average = %.2f\n",sum/27.0);
    printf("Highest Value = %d\n",high);
    printf("Lowest Value = %d\n",low);

    return 0;
}
