
#include<stdio.h>

int main()
{
    int a[3][3],c[3][3],b[3][3];
    int i,j,x,y,k,l,n,m;
    int d=0;
    float inv[3][3];

    printf("Enter 9 elements:\n");

    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            scanf("%d",&a[i][j]);

    printf("\nOriginal Matrix:\n");

    for(i=0;i<3;i++){
        for(j=0;j<3;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }

    printf("\nTranspose:\n");

    for(i=0;i<3;i++){
        for(j=0;j<3;j++)
            printf("%d ",a[j][i]);
        printf("\n");
    }

    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            int v[4],p=0;

            for(x=0;x<3;x++){
                for(y=0;y<3;y++){
                    if(x!=i && y!=j){
                        v[p]=a[x][y];
                        p++;
                    }
                }
            }

            c[i][j]=v[0]*v[3]-v[1]*v[2];

            if((i+j)%2!=0)
                c[i][j]=-c[i][j];
        }
    }

    for(j=0;j<3;j++)
        d=d+a[0][j]*c[0][j];

    printf("\nDeterminant = %d\n",d);

    printf("\nCofactor Matrix:\n");

    for(i=0;i<3;i++){
        for(j=0;j<3;j++)
            printf("%d ",c[i][j]);
        printf("\n");
    }

    printf("\nAdjoint Matrix:\n");

    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            b[i][j]=c[j][i];
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }

    if(d==0){
        printf("\nInverse does not exist.\n");
    }
    else{
        printf("\nInverse Matrix:\n");

        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                inv[i][j]=(float)b[i][j]/d;
                printf("%.2f ",inv[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
