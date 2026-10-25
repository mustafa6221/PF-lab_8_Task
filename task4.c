
#include<stdio.h>

int main()
{
    int beds[2][3][2]={0};
    int ch,f,w,b,id;
    int i,j,k,found;
    int occ,vac,total;
    int max=0,mf=0,mw=0;
    float per;

    while(1)
    {
        printf("\n1. Admit\n");
        printf("2. Discharge\n");
        printf("3. Report\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d",&ch);

        if(ch==1)
        {
            printf("Enter floor and patient ID: ");
            scanf("%d%d",&f,&id);

            if(f<1 || f>2 || id<=0)
            {
                printf("Invalid floor or patient ID.\n");
                continue;
            }

            found=0;

            for(w=0;w<3;w++)
            {
                for(b=0;b<2;b++)
                {
                    if(beds[f-1][w][b]==0 && found==0)
                    {
                        beds[f-1][w][b]=id;

                        printf("Patient %d admitted: Floor %d, Ward %d, Bed %d.\n",
                               id,f,w+1,b+1);

                        found=1;
                    }
                }
            }

            if(found==0)
                printf("Floor %d is full.\n",f);
        }
        else if(ch==2)
        {
            printf("Enter patient ID: ");
            scanf("%d",&id);

            found=0;

            for(i=0;i<2;i++)
            {
                for(j=0;j<3;j++)
                {
                    for(k=0;k<2;k++)
                    {
                        if(beds[i][j][k]==id && found==0)
                        {
                            beds[i][j][k]=0;

                            printf("Patient %d discharged from Floor %d, Ward %d, Bed %d.\n",
                                   id,i+1,j+1,k+1);

                            found=1;
                        }
                    }
                }
            }

            if(found==0)
                printf("Patient ID %d not found.\n",id);
        }
        else if(ch==3)
        {
            printf("\n--- Occupancy Report ---\n");

            max=0;

            for(i=0;i<2;i++)
            {
                printf("Floor %d\n",i+1);
                total=0;

                for(j=0;j<3;j++)
                {
                    occ=0;

                    for(k=0;k<2;k++)
                    {
                        if(beds[i][j][k]!=0)
                            occ++;
                    }

                    vac=2-occ;
                    total=total+occ;

                    printf("Ward %d: Occupied %d, Vacant %d\n",
                           j+1,occ,vac);

                    if(occ>max)
                    {
                        max=occ;
                        mf=i+1;
                        mw=j+1;
                    }
                }

                per=(total/6.0)*100;

                printf("Floor occupancy: %.1f%%\n",per);

                if(per>80)
                    printf("WARNING: Floor %d is more than 80%% full.\n",i+1);
            }

            printf("Highest occupancy: Floor %d, Ward %d (%d occupied)\n",
                   mf,mw,max);
        }
        else if(ch==4)
        {
            break;
        }
        else
        {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
