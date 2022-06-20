#include "SportMeeting.h"
void InputData(SportMeeting *S)
{
    int i,j,k;
    int flag; //用于判断项目是否男女共有
    int mark;
    int choice;
    S->n=S->man_num=S->women_num=0;
    do
    {
        printf("    1.录入学校数据\n\
    2.录入项目数据\n\
    3.退出\n");
        printf("请选择:");
        scanf("%d%*c",&choice);
        switch (choice)
        {
            case 1:
                flag=1;
                printf("请输入学校个数:");
                again:scanf("%d%*c",&S->n);
                if(S->n>20)
                {
                    printf("n<=20\n");
                    printf("请重新输入:");
                    goto again;
                }
                {
                    for(i=1;i<=S->n;i++)
                    {
                        printf("请输入编号为%d的学校名称:",i);
                        scanf("%s%*c",S->school[i].school_name);
                        S->school[i].number=i;
                        S->school[i].sum=0;
                        S->school[i].man_sum=S->school[i].women_sum=0;
                    }   
                }
                break;
            case 2:
                printf("请输入男子项目个数:");
                again1:scanf("%d",&S->man_num);
                if(S->man_num>20)
                {
                    printf("n<=20\n");
                    printf("请重新输入:");
                    goto again1;
                }
                printf("请输入女子项目个数:");
                again2:scanf("%d%*c",&S->women_num);
                if(S->women_num>20)
                {
                    printf("n<=20\n");
                    printf("请重新输入:");
                    goto again2;
                }
                j=1;
                {
                    for(i=1;i<=S->man_num;i++)
                    {
                        printf("请输入编号为%d的项目名称:",i);
                        scanf("%s",S->project[i].project_name);
                        printf("%s项目是取前五名还是取前三名?(取前五名输入5 取前三名输入3):",S->project[i].project_name);
                        again3:scanf("%d%*c",&mark);
                        if(mark!=3 && mark!=5)
                        {
                            printf("输入有误!\n");
                            printf("请重新输入:");
                            goto again3;
                        }
                        else
                        {
                            S->project[i].mark=mark;
                        }
                        for(k=1;k<=mark;k++)
                        {
                            S->project[i].AwardSchools[k].credits=0;
                        }
                        S->project[i].carryout=0;
                        printf("这个项目男女都有吗:(1/0):");
                        again4:scanf("%d%*c",&flag);
                        if(flag!=0 && flag!=1)
                        {
                            printf("输入有误!");
                            printf("请重新输入:");
                            goto again4;
                        }
                        if(flag)
                        {
                            printf("(女子)%s项目编号为:%d\n",S->project[i].project_name,S->man_num+j);
                            strcpy(S->project[S->man_num+j].project_name,S->project[i].project_name);
                            S->project[S->man_num+j].mark=mark;
                            S->project[S->man_num+j].carryout=0;
                            for(k=1;k<=mark;k++)
                            {
                                S->project[S->man_num+j].AwardSchools[k].credits=0;
                            }
                            j++;
                        }
                    }
                    for(;j<=S->women_num;j++)
                    {
                        printf("请输入编号为%d的项目名称:",j+S->man_num);
                        scanf("%s",S->project[j+S->man_num].project_name);
                        printf("%s项目是取前五名还是取前三名?(取前五名输入5 取前三名输入3):",S->project[j+S->man_num].project_name);
                        again5:scanf("%d%*c",&mark);
                        if(mark!=3 && mark!=5)
                        {
                            printf("输入有误!\n");
                            printf("请重新输入:");
                            goto again5;
                        }
                        else
                        {
                            S->project[j+S->man_num].mark=mark;
                        }
                        S->project[j+S->man_num].carryout=0;
                        for(k=1;k<=mark;k++)
                        {
                            S->project[j+S->man_num].AwardSchools[k].credits=0;
                        }
                    }
                }
            case 3:
                break; 
            default:
                printf("输入错误!\n");
                break;
        }
    } while (choice!=3);
    for(i=1;i<=S->n;i++)
    {
        for(j=1;j<=S->man_num+S->women_num;j++)
        {
            S->school[i].high_standings[j]=0;
        }
    }
    printf("录入基本信息完成!\n");
}
void InputCredit(SportMeeting *S,int project_pos)
{
    Project *temp;
    School *temp2;
    int i;
    int record=999; //用来后面的积分录入时，防止后面大于前面
    int credit;
    int school_pos;
    int choice;
    char name[20];
    temp=&(S->project[project_pos]);
    temp->carryout=1; //该项目已进行
    if(temp->mark>S->n)
    {
        temp->mark=S->n;
    }
    printf("(%d)%s项目取前%d名\n",project_pos,temp->project_name,temp->mark);
    for(i=1;i<=temp->mark;i++)
    {
        printf("现在录入第%d名的积分数据\n",i);
        do
        {
            printf("    1.按学校名称录入\n\
    2.按学校编号录入\n");
            printf("请选择:");
            scanf("%d%*c",&choice);
            switch(choice)
            {
                case 1:
                    school_pos=ExamineNameSchool(S);
                    if(!school_pos)
                    {
                        choice=0;
                        printf("输入的学校名称有误!\n");
                    }
                    break;
                case 2:
                    school_pos=ExamineNumberSchool(S);
                    if(!school_pos)
                    {
                        choice=0;
                        printf("输入的学校编号有误!\n");
                    }
                    break;
                default:
                    printf("输入错误!\n");
                    break;
            }
        } while (choice!=1 && choice!=2);
        temp2=&(S->school[school_pos]);
        temp->AwardSchools[i].sequence=temp2->number;
        printf("请输入%s在%s项目获得的积分:",temp2->school_name,temp->project_name);
        again:scanf("%d%*c",&credit);
        if(record>credit)
        {
            record=credit;
            temp->AwardSchools[i].credits=credit;
            temp2->sum+=credit;
            if(project_pos>S->man_num) {temp2->women_sum+=credit;}
            else if(project_pos<=S->man_num) {temp2->man_sum+=credit;};
            temp2->high_standings[project_pos]=credit;
        }
        else
        {
            printf("输入的积分大于或等于前一名的积分\n");
            printf("请重新输入:");
            goto again;
        }
    }
    
}