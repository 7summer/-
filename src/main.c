#include "SportMeeting.h"
int main()
{
    SportMeeting S;
    School *temp1;
    Project *temp2;
    int pos;
    int i,j;
    int n;
    int choice1,choice2,choice3;
    S.n=S.man_num=S.women_num=0;
    do
    {
        printf("    1.录入学校、项目数据\n\
    2.录入积分数据\n\
    3.从电脑中读数据\n\
    4.将数据存储到电脑\n\
    5.查询数据\n\
    6.修改数据\n\
    7.查看排名\n\
    8.退出\n");
        printf("请输入:");
        scanf("%d%*c",&choice1);
        switch (choice1)
        {
            case 1:
                InputData(&S);
                break;
            case 2:
                do
                {
                    printf("还未进行的项目\n");
                    for(i=1;i<=S.man_num+S.women_num;i++)
                    {
                        temp2=&(S.project[i]);
                        if(!temp2->carryout) printf("(%d)%s\n",i,temp2->project_name);
                    }
                    printf("    1.按项目名称输入积分\n\
    2.按项目编号输入积分\n\
    3.退出\n");
                    printf("请输入:");
                    scanf("%d%*c",&choice2);
                    switch(choice2)
                    {
                        case 1:
                            pos=ExamineNameProject(&S);
                            if(pos) InputCredit(&S,pos);
                            else printf("输入的项目名称有误!\n");
                            break;
                        case 2:
                            pos=ExamineNumberProject(&S);
                            if(pos) InputCredit(&S,pos);
                            else printf("输入的项目编号有误!\n");
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
            case 3:
                OuputFromFile(&S);
                break;
            case 4:
                InputToFile(&S);
                break;
            case 5:
                do
                {
                    printf("    1.查看全部学校的分数数据\n\
    2.查看全部项目的获奖数据\n\
    3.查看学校的详细数据\n\
    4.查看项目的详细数据\n\
    5.退出\n");
                    printf("请输入:");
                    scanf("%d%*c",&choice2);
                    switch (choice2)
                    {
                        case 1:
                            {
                                for(i=1;i<=S.n;i++)
                                {
                                    temp1=&(S.school[i]);
                                    printf("(%d)%s\t总分:%d\t男子项目总分:%d\t女子项目总分:%d\n",temp1->number,temp1->school_name,temp1->sum,temp1->man_sum,temp1->women_sum);
                                }
                            }
                            break;
                        case 2:
                            {
                                for(i=1;i<=S.man_num+S.women_num;i++)
                                {
                                    temp2=&(S.project[i]);
                                    printf("(%d)%s\t",i,temp2->project_name);
                                    if(temp2->carryout)
                                    {
                                        for(j=1;j<=temp2->mark;j++)
                                        {
                                            n=ExamineSchool_pos(&S,temp2->AwardSchools[j].sequence);
                                            temp1=&(S.school[n]);
                                            printf("(%d)%s %d\t",temp1->number,temp1->school_name,temp2->AwardSchools[j].credits);
                                        }
                                    }
                                    printf("\n");
                                }
                            }
                            break;
                        case 3:
                            Find(&S,choice2);
                            break;
                        case 4:
                            Find(&S,choice2);
                            break;
                        case 5:
                            printf("谢谢!\n");
                            break;
                        default:
                            printf("输入有误!\n");
                            break;
                    }
                } while (choice2!=5);
                break;
            case 6:
                do
                {
                    printf("    1.修改学校名称\n\
    2.修改项目名称\n\
    3.修改项目名次\n\
    4.修改项目进行情况\n\
    5.修改项目积分\n\
    6.修改项目参赛学校\n\
    7.退出\n");
                    printf("请输入:");
                    scanf("%d%*c",&choice2);
                    switch (choice2)
                    {
                        case 1:
                            printf("请输入学校编号:");
                            again1:scanf("%d%*c",&pos);
                            pos=ExamineSchool_pos(&S,pos);
                            if(!pos) 
                            {
                                printf("输入错误!\n");
                                printf("请重新输入:");
                                goto again1;
                            }
                            ModifySchoolName(&S,pos);
                            break;
                        case 2: //修改项目名称
                            printf("请输入项目编号:");
                            again2:scanf("%d%*c",&pos);
                            if(pos>S.man_num+S.women_num)
                            {
                                printf("输入错误!\n");
                                printf("请重新输入:");
                                goto again2;
                            }
                            ModifyProject(&S,pos,choice2);
                            break;
                        case 3: //修改项目名次
                            printf("请输入项目编号:");
                            again3:scanf("%d%*c",&pos);
                            if(pos>S.man_num+S.women_num)
                            {
                                printf("输入错误!\n");
                                printf("请重新输入:");
                                goto again3;
                            }
                            ModifyProject(&S,pos,choice2);
                            break;                    
                        case 4: //修改项目进行情况
                            printf("请输入项目编号:");
                            again4:scanf("%d%*c",&pos);
                            if(pos>S.man_num+S.women_num)
                            {
                                printf("输入错误!\n");
                                printf("请重新输入:");
                                goto again4;
                            }
                                ModifyProject(&S,pos,choice2);
                            break;
                        case 5: //修改项目积分
                            printf("请输入项目编号:");
                            again5:scanf("%d%*c",&pos);
                            if(pos>S.man_num+S.women_num)
                            {
                                printf("输入错误!\n");
                                printf("请重新输入:");
                                goto again5;
                            }
                            temp2=&(S.project[pos]);
                            if(temp2->carryout)
                            {
                                for(i=1;i<=temp2->mark;i++)
                                {
                                    n=ExamineSchool_pos(&S,temp2->AwardSchools[i].sequence);
                                    temp1=&(S.school[n]);
                                    temp1->sum-=temp2->AwardSchools[i].credits;
                                    if(pos>S.man_num) temp1->women_sum-=temp2->AwardSchools[i].credits;
                                    else temp1->man_sum-=temp2->AwardSchools[i].credits;
                                    temp1->high_standings[pos]=0;
                                    temp2->AwardSchools[i].credits=0;
                                }
                                InputCredit(&S,pos);
                            }
                            else printf("(%d)%s还没开始!\n",pos,temp2->project_name);
                            break;
                        case 6:
                            printf("请输入项目编号:");
                            again6:scanf("%d%*c",&pos);
                            if(pos>S.man_num+S.women_num)
                            {
                                printf("输入错误!\n");
                                printf("请重新输入:");
                                goto again6;
                            }
                            temp2=&(S.project[pos]);
                            if(temp2->carryout)
                            {
                                printf("(%d)%s已录入积分,请修改项目进行情况后,再修改项目参赛学校,再对项目重新录入积分\n",pos,temp2->project_name);
                            }
                            else
                            {
                                InputParticipatingSchool(&S,pos);
                            }
                            break;
                        case 7:
                            printf("谢谢!\n");
                            break;
                        default:
                            printf("输入有误!\n");
                            break;
                    }
                } while (choice2!=7);
                break;
            case 7:
                do
                {
                    printf("    1.按学校编号排序输出\n\
    2.按学校总分排序输出\n\
    3.按学校男子项目总分排序输出\n\
    4.按学校女子项目总分排序输出\n\
    5.退出\n");
                    printf("请选择:");
                    scanf("%d%*c",&choice2);
                    switch (choice2)
                    {
                        case 1:
                            NumberSort(&S);
                            {
                                for(i=1;i<=S.n;i++)
                                {
                                    temp1=&(S.school[i]);
                                    printf("(%d)%s\t总分:%d\n",temp1->number,temp1->school_name,temp1->sum);
                                }
                            }                           
                            break;
                        case 2:
                            SumSort(&S);
                            {
                                for(i=1;i<=S.n;i++)
                                {
                                    temp1=&(S.school[i]);
                                    printf("(%d)%s\t总分:%d\n",temp1->number,temp1->school_name,temp1->sum);
                                }
                            }
                            break;
                        case 3:
                            ManCreditSort(&S,1,S.n);
                            {
                                for(i=1;i<=S.n;i++)
                                {
                                    temp1=&(S.school[i]);
                                    printf("(%d)%s\t男子项目总分:%d\n",temp1->number,temp1->school_name,temp1->man_sum);
                                }
                            }
                            break;
                        case 4:
                            WomenCreditSort(&S);
                            {
                                for(i=1;i<=S.n;i++)
                                {
                                    temp1=&(S.school[i]);
                                    printf("(%d)%s\t女子项目总分:%d\n",temp1->number,temp1->school_name,temp1->women_sum);
                                }
                            }
                            break;
                        case 5:
                            printf("谢谢!\n");
                            break;
                        default:
                            printf("输入错误!\n");
                            break;
                    }
                } while (choice2!=5);
                break;
            case 8:
                printf("谢谢!\n");
                break;
            default:
                printf("输入有误!\n");
                break;
        }
    } while (choice1!=8);
    return 0;
}