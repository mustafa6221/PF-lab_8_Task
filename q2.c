
#include<stdio.h>

int main()
{
    int a[5][5],b[5][5],c[5][5],d[5][5];
    int r,s,i,j,k;
    int zero=1,identity=1,diagonal=1,scalar=1;
    int upper=1,lower=1,sym=1,skew=1,equal=1;
    int idem=1,nil=0,det=0,found=0;
    int t;

    printf("Enter rows and columns (max 5): ");
    scanf("%d%d",&r,&s);

    if(r<1 || r>5 || s<1 || s>5){
        printf("Invalid size");
        return 0;
    }

    printf("Enter matrix:\n");

    for(i=0;i<r;i++)
        for(j=0;j<s;j++)
            scanf("%d",&a[i][j]);

    for(i=0;i<r;i++){
        for(j=0;j<s;j++){
            if(a[i][j]!=0)
                zero=0;

            if(i!=j && a[i][j]!=0)
                diagonal=0;

            if(i<j && a[i][j]!=0)
                lower=0;

            if(i>j && a[i][j]!=0)
                upper=0;
        }
    }

    if(r==1)
        printf("Row Matrix\n");

    if(s==1)
        printf("Column Matrix\n");

    if(r!=s)
        printf("Rectangular Matrix\n");
    else
        printf("Square Matrix\n");

    if(zero){
        printf("Zero Matrix\n");
        printf("Null Matrix\n");
    }

    if(r==s){
        for(i=0;i<r;i++){
            for(j=0;j<s;j++){
                if(i==j && a[i][j]!=1)
                    identity=0;

                if(i!=j && a[i][j]!=0)
                    identity=0;

                if(i==j && i>0 && a[i][i]!=a[0][0])
                    scalar=0;

                if(a[i][j]!=a[j][i])
                    sym=0;

                if(a[i][j]!=-a[j][i])
                    skew=0;
            }
        }

        if(identity)
            printf("Identity Matrix\n");

        if(diagonal)
            printf("Diagonal Matrix\n");

        if(diagonal && scalar)
            printf("Scalar Matrix\n");

        if(upper)
            printf("Upper Triangular Matrix\n");

        if(lower)
            printf("Lower Triangular Matrix\n");

        if(sym)
            printf("Symmetric Matrix\n");

        if(skew)
            printf("Skew-Symmetric Matrix\n");

        printf("Enter second matrix to check equality:\n");

        for(i=0;i<r;i++)
            for(j=0;j<s;j++)
                scanf("%d",&b[i][j]);

        for(i=0;i<r;i++)
            for(j=0;j<s;j++)
                if(a[i][j]!=b[i][j])
                    equal=0;

        if(equal)
            printf("Equal Matrices\n");
        else
            printf("Matrices are not equal\n");

        for(i=0;i<r;i++)
            for(j=0;j<r;j++){
                c[i][j]=0;
                for(k=0;k<r;k++)
                    c[i][j]=c[i][j]+a[i][k]*a[k][j];
            }

        for(i=0;i<r;i++)
            for(j=0;j<r;j++)
                if(c[i][j]!=a[i][j])
                    idem=0;

        if(idem)
            printf("Idempotent Matrix\n");

        for(i=0;i<r;i++)
            for(j=0;j<r;j++)
                d[i][j]=a[i][j];

        for(t=1;t<=r;t++){
            for(i=0;i<r;i++){
                for(j=0;j<r;j++){
                    c[i][j]=0;
                    for(k=0;k<r;k++)
                        c[i][j]=c[i][j]+d[i][k]*a[k][j];
                }
            }

            nil=1;

            for(i=0;i<r;i++)
                for(j=0;j<r;j++)
                    if(c[i][j]!=0)
                        nil=0;

            if(nil)
                break;

            for(i=0;i<r;i++)
                for(j=0;j<r;j++)
                    d[i][j]=c[i][j];
        }

        if(nil || zero)
            printf("Nilpotent Matrix\n");
        else
            printf("Not Nilpotent Matrix\n");

        for(i=0;i<r;i++)
            for(j=0;j<r;j++)
                d[i][j]=a[i][j];

        det=1;

        for(i=0;i<r;i++){
            if(d[i][i]==0){
                for(k=i+1;k<r;k++){
                    if(d[k][i]!=0){
                        for(j=0;j<r;j++){
                            int temp=d[i][j];
                            d[i][j]=d[k][j];
                            d[k][j]=temp;
                        }
                        det=-det;
                        break;
                    }
                }
            }

            if(d[i][i]==0){
                det=0;
                break;
            }

            det=det*d[i][i];

            for(k=i+1;k<r;k++){
                for(j=r-1;j>=i;j--)
                    d[k][j]=d[k][j]*d[i][i]-d[k][i]*d[i][j];
            }
        }

        if(det==0)
            printf("Singular Matrix\n");
        else
            printf("Non-Singular Matrix\n");
    }

    return 0;
}
