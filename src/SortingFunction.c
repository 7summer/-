#include "SportMeeting.h"
void NumberSort(SportMeeting *S)
{
    int i,j;
    int flag=1;
    School temp;
    for(i=1;flag&&i<S->n;i++)
    {
        for(flag=0,j=1;j<=S->n-i;j++)
        {
            if(S->school[j].number>S->school[j+1].number)
            {
                temp=S->school[j];
                S->school[j]=S->school[j+1];
                S->school[j+1]=temp;
                flag=1;
            }
        }
    }
}
void SumSort(SportMeeting *S)
{
    int *d;
    int t=0;
    int temp=S->n;
    int i,j,k;
    d=(int*)malloc(sizeof(int)*(S->n));
    while(temp) //��������d[]
    {
        d[t++]=temp/2;
        temp /= 2;
    }
    for(k=0;k<t;k++)
    {
        for(i=d[k]+1;i<=S->n;i++)
        {
            if(S->school[i].sum>S->school[i-d[k]].sum)
            {
                S->school[0]=S->school[i];
                for(j=i-d[k];j>0 && S->school[0].sum>S->school[j].sum;j-=d[k])
                    S->school[j+d[k]]=S->school[j];
                S->school[j+d[k]]=S->school[0];
            }
        }
    }
}
void ManCreditSort(SportMeeting *S,int low,int high)
{
    int i,j;
    if(low<high)
    {
        i=low;
        j=high;
        S->school[0]=S->school[i];
        while(i<j)
        {
            while(i<j && S->school[j].man_sum<=S->school[0].man_sum) j--;
            S->school[i]=S->school[j];
            while(i<j && S->school[i].man_sum>S->school[0].man_sum) i++;
            S->school[j]=S->school[i];
        }
        S->school[i]=S->school[0];
        ManCreditSort(S,low,i-1);
        ManCreditSort(S,i+1,high);
    }
}
void AdjustTree(SportMeeting *S,int n,int k)
{
    int i,j;
    i=k;
    j=2*i;
    S->school[0]=S->school[i];
    while (j<=n)
    {
        if(j<n&&S->school[j+1].women_sum<S->school[j].women_sum)
            j=j+1;
        if(S->school[0].women_sum<S->school[j].women_sum)
            break;
        S->school[i]=S->school[j];
        i=j;
        j=2*i;
    }
    S->school[i]=S->school[0];
}
void WomenCreditSort(SportMeeting *S)
{
    int i;
    School temp;
    for(i=S->n/2;i>=1;i--)
        AdjustTree(S,S->n,i);
    for(i=S->n;i>=2;i--)
    {
        temp=S->school[i];
        S->school[i]=S->school[1];
        S->school[1]=temp;
        AdjustTree(S,i-1,1);
    }
}