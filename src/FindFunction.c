#include "SportMeeting.h"
void Find(SportMeeting *S,int choice)
{
    int choice2;
    int pos;
    int i,j;
    Project *temp;
    School *temp2;
    int n;
    if(choice==3)
    {
        do
        {
            printf("    1.按学校名称查询\n\
    2.按学校编号查询\n\
    3.退出\n");
            printf("请选择:");
            scanf("%d%*c",&choice2);
            switch (choice2)
            {
                case 1:
                    pos=ExamineNameSchool(S);
                    if(pos) FindSchool(S,pos);
                    else printf("输入的学校名称有误!\n");
                    break;
                case 2:
                    pos=ExamineNumberSchool(S);
                    if(pos) FindSchool(S,pos);
                    else printf("输入的学校编号有误!\n");
                    break;
                case 3:
                    printf("谢谢!\n");
                    break;
                default:
                    printf("输入有误!\n");
                    break;
            }
        } while (choice2!=3);
    }
    else
    {
        do
        {
            printf("    1.查询已进行的项目\n\
    2.查询未进行的项目\n\
    3.查询各个项目的参赛队伍\n\
    4.退出\n");
            printf("请选择:");
            scanf("%d%*c",&choice2);
            switch (choice2)
            {
                case 1:
                {
                    for (i=1;i<=S->man_num+S->women_num;i++)
                    {
                        temp=&(S->project[i]);
                        if(temp->carryout)
                        {   
                            printf("(%d)%s\t",i,temp->project_name);
                            for(j=1;j<=temp->mark;j++)
                            {
                                n=ExamineSchool_pos(S,temp->AwardSchools[j].sequence);
                                temp2=&(S->school[n]);
                                printf("(%d)%s %d\t",temp2->number,temp2->school_name,temp->AwardSchools[j].credits);
                            }
                            printf("\n");
                        }
                    }
                }
                    break;
                case 2:
                {
                    for (i=1;i<=S->man_num+S->women_num;i++)
                    {
                        temp=&(S->project[i]);
                        if(!temp->carryout) printf("(%d)%s\n",i,temp->project_name);
                    }
                }
                    break;
                case 3:
                {
                    for(i=1;i<=S->man_num+S->women_num;i++)
                    {
                        temp=&(S->project[i]);
                        printf("(%d)%s\t",i,temp->project_name);
                        if(temp->num)
                        {
                            for(j=1;j<=temp->num;j++)
                            {
                                pos=ExamineSchool_pos(S,temp->ParticipatingSchool[j]);
                                temp2=&(S->school[pos]);
                                printf("(%d)%s\t",temp2->number,temp2->school_name);
                            }
                            printf("\n");
                        }
                        else
                        {
                            printf("还未录入参赛队伍!\n");
                        }
                    }
                }
                case 4:
                    printf("谢谢!\n");
                    break;
                default:
                    printf("输入有误!\n");
                    break;
            }
        } while (choice2!=4);   
    }
}
void FindSchool(SportMeeting *S,int school_pos)
{
    int choice,choice2;
    int project_pos;
    School *temp;
    Project *temp2;
    int i;
    temp=&(S->school[school_pos]);
    printf("现在开始查询(%d)%s的数据\n",temp->number,temp->school_name);
    do
    {
        printf("    1.查看学校的总分、男子项目总分、女子项目总分\n\
    2.查看学校参赛项目的积分\n\
    3.查看学校已获得积分的项目\n\
    4.查看某个项目的积分\n\
    5.退出\n");
        printf("请输入:");
        scanf("%d%*c",&choice);
        switch (choice)
        {
            case 1:
                printf("(%d)%s\t总分:%d\t男子项目总分:%d\t女子项目总分:%d\n",temp->number,temp->school_name,temp->sum,temp->man_sum,temp->women_sum);
                break;
            case 2:
            {
                for(i=1;i<=S->man_num+S->women_num;i++)
                {
                    temp2=&(S->project[i]);
                    if(!ExamineParticipatingSchool(S,school_pos,i))
                    {
                        continue;
                    }
                    if(temp2->carryout) printf("(%d)%s %d\n",i,temp2->project_name,temp->high_standings[i]);
                    else printf("(%d)%s还未开始\n",i,temp2->project_name);   
                }
            }
                break;
            case 3:
            {
                for(i=1;i<=S->man_num+S->women_num;i++)
                {
                    temp2=&(S->project[i]);
                    if(temp->high_standings[i])
                    {
                        printf("(%d)%s %d\n",i,temp2->project_name,temp->high_standings[i]);
                    }
                }
            }
                break;
            case 4:
                do
                {
                    printf("    1.按项目名称查询\n\
    2.按项目编号查询\n\
    3.退出\n");
                    printf("请选择:");
                    scanf("%d%*c",&choice2);
                    switch (choice2)
                    {
                        case 1:
                            project_pos=ExamineNameProject(S);
                            if(!project_pos) printf("输入的项目名称有误!\n");
                            else if(ExamineParticipatingSchool(S,school_pos,project_pos))
                            {
                                temp2=&(S->project[project_pos]);
                                if(!temp2->carryout) printf("(%d)%s还没有进行\n",project_pos,temp2->project_name);
                                else printf("%s在(%d)%s中获得%d积分\n",temp->school_name,project_pos,temp2->project_name,temp->high_standings[project_pos]);
                            }
                            break;
                        case 2:
                            project_pos=ExamineNumberProject(S);
                            if(!project_pos) printf("输入的项目编号有误!\n");
                            else if(ExamineParticipatingSchool(S,school_pos,project_pos))
                            {
                                temp2=&(S->project[project_pos]);
                                if(!temp2->carryout) printf("(%d)%s还没有进行\n",project_pos,temp2->project_name);
                                else printf("%s在(%d)%s中获得%d积分\n",temp->school_name,project_pos,temp2->project_name,temp->high_standings[project_pos]);
                            }
                            break;
                        case 3:
                            printf("谢谢!\n");
                            break;
                        default:
                            printf("输入有误!\n");
                            break;
                    }
                } while (choice2!=3);
                break;
            case 5:
                printf("谢谢!\n");
                break; 
            default:
                printf("输入错误!\n");
                break;
        }
    } while (choice!=5);
}
/*
void FindProject(SportMeeting *S,int project_pos)
{
    int choice;
    Project *temp;
    temp=&(S->project[project_pos]);
    School *temp2;
    int i;
    printf("(%d)%s项目取前%d名\n",project_pos,temp->project_name,temp->mark);
    if(temp->carryout)
    {
        for(i=1;i<=temp->mark;i++)
        {
            temp2=&(S->school[temp->AwardSchools[i].sequence]);
            printf("(%d)%s 第%d名 获得%d积分\n",temp2->number,temp2->school_name,i,temp->AwardSchools[i].credits);
        }
    }
}
*/