#include "SportMeeting.h"
void ModifySchoolName(SportMeeting *S,int school_pos)
{
    School *temp;
    temp=&(S->school[school_pos]);
    printf("原来的学校数据:(%d)%s\n",school_pos,temp->school_name);
    printf("请输入学校名称:");
    scanf("%s%*c",temp->school_name);
    printf("修改后的学校数据:(%d)%s\n",school_pos,temp->school_name);
}
void ModifyProject(SportMeeting *S,int project_pos,int choice)
{
    Project *temp;
    School *temp2;
    int flag;
    int mark;
    int i;
    int n;
    temp=&(S->project[project_pos]);
    if(choice==2)
    {
        printf("原来的项目数据:(%d)%s\n",project_pos,temp->project_name);
        printf("请输入项目名称:");
        scanf("%s%*c",temp->project_name);
        printf("修改后的项目数据:(%d)%s\n",project_pos,temp->project_name);
    }
    else if(choice==3)
    {
        printf("原来项目数据:(%d)%s 取前%d名\n",project_pos,temp->project_name,temp->mark);
        printf("请输入项目名次:(3/5):");
        again1:scanf("%d%*c",&mark);
        if(mark!=3 && mark!=5)
        {
            printf("输入有误!\n");
            printf("请重新输入:");
            goto again1;
        }
        if(temp->mark!=mark && temp->carryout)
        {
            for(i=1;i<=temp->mark;i++)
            {
                n=ExamineSchool_pos(S,temp->AwardSchools[i].sequence);
                temp2=&(S->school[n]);
                temp2->sum-=temp2->high_standings[project_pos];
                if(project_pos>S->man_num) temp2->women_sum-=temp2->high_standings[project_pos];
                else temp2->man_sum-=temp2->high_standings[project_pos];
                temp->AwardSchools[i].credits=0;
                temp2->high_standings[project_pos]=0;
            }
            temp->mark=mark;
            printf("现在开始重新录入(%d)%s的积分\n",project_pos,temp->project_name);
            InputCredit(S,project_pos);
        }
        temp->mark=mark;
        printf("修改成功!\n");
    }
    else if(choice==4)
    {
        printf("(%d)%s 该项目是否已经进行(%d)\n",project_pos,temp->project_name,temp->carryout);
        printf("请输入项目的进行情况:(1进行/0未进行):");
        again2:scanf("%d%*c",&flag);
        if(flag!=0 && flag!=1)
        {
            printf("输入有误!\n");
            printf("请重新输入:");
            goto again2;
        }
        if(!temp->carryout && flag)
        {
            printf("现在开始录入(%d)%s的积分\n",project_pos,temp->project_name);
            InputCredit(S,project_pos);
        }
        else if(temp->carryout && !flag)
        {
            for(i=1;i<=temp->mark;i++)
            {
                n=ExamineSchool_pos(S,temp->AwardSchools[i].sequence);
                temp2=&(S->school[n]);
                temp2->sum-=temp->AwardSchools[i].credits;
                if(project_pos>S->man_num) temp2->women_sum-=temp->AwardSchools[i].credits;
                else temp2->man_sum-=temp->AwardSchools[i].credits;
                temp->AwardSchools[i].credits=0;
                temp2->high_standings[project_pos]=0;
            }
        }
        temp->carryout=flag;
        printf("修改成功!\n");
    }
}