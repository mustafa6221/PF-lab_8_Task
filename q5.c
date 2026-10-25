
#include<stdio.h>

int main()
{
    int a[3][3][3];
    int i,j,k,same;

    printf("Enter 27 elements:\n");

    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            for(k=0;k<3;k++)
                scanf("%d",&a[i][j][k]);

    for(i=0;i<3;i++){
        printf("\nLayer %d:\n",i+1);

        for(j=0;j<3;j++){
            for(k=0;k<3;k++)
                printf("%d ",a[i][j][k]);
            printf("\n");
        }
    }

    for(i=0;i<3;i++){
        for(j=i+1;j<3;j++){
            same=1;

            for(int x=0;x<3;x++){
                for(int y=0;y<3;y++){
                    if(a[i][x][y]!=a[j][x][y])
                        same=0;
                }
            }

            printf("\nLayer %d and Layer %d: ",
                   i+1,j+1);

            if(same)
                printf("Identical\n");
            else
                printf("Distinct\n");
        }
    }

    return 0;
}
