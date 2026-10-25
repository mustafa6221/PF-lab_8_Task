
#include<stdio.h>

int main()
{
    int a[3][3],b[3][3],c[3][3];
    int r1,s1,r2,s2,i,j,k;

    printf("Enter rows and columns of first matrix: ");
    scanf("%d%d",&r1,&s1);

    printf("Enter rows and columns of second matrix: ");
    scanf("%d%d",&r2,&s2);

    if(r1<1 || r1>3 || s1<1 || s1>3 ||
       r2<1 || r2>3 || s2<1 || s2>3){
        printf("Invalid size");
        return 0;
    }

    if(s1!=r2){
        printf("Multiplication not possible");
        return 0;
    }

    printf("Enter first matrix:\n");

    for(i=0;i<r1;i++)
        for(j=0;j<s1;j++)
            scanf("%d",&a[i][j]);

    printf("Enter second matrix:\n");

    for(i=0;i<r2;i++)
        for(j=0;j<s2;j++)
            scanf("%d",&b[i][j]);

    printf("\nFirst Matrix:\n");

    for(i=0;i<r1;i++){
        for(j=0;j<s1;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }

    printf("\nSecond Matrix:\n");

    for(i=0;i<r2;i++){
        for(j=0;j<s2;j++)
            printf("%d ",b[i][j]);
        printf("\n");
    }

    for(i=0;i<r1;i++){
        for(j=0;j<s2;j++){
            c[i][j]=0;

            for(k=0;k<s1;k++)
                c[i][j]=c[i][j]+a[i][k]*b[k][j];
        }
    }

    printf("\nResult Matrix:\n");

    for(i=0;i<r1;i++){
        for(j=0;j<s2;j++)
            printf("%d ",c[i][j]);
        printf("\n");
    }

    return 0;
}
