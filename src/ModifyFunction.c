#include "SportMeeting.h"
void ModifySchoolName(SportMeeting *S,int school_pos)
{
    School *temp;
    temp=&(S->school[school_pos]);
    printf("ԭ����ѧУ����:(%d)%s\n",school_pos,temp->school_name);
    printf("������ѧУ����:");
    scanf("%s%*c",temp->school_name);
    printf("�޸ĺ��ѧУ����:(%d)%s\n",school_pos,temp->school_name);
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
        printf("ԭ������Ŀ����:(%d)%s\n",project_pos,temp->project_name);
        printf("��������Ŀ����:");
        scanf("%s%*c",temp->project_name);
        printf("�޸ĺ����Ŀ����:(%d)%s\n",project_pos,temp->project_name);
    }
    else if(choice==3)
    {
        printf("ԭ����Ŀ����:(%d)%s ȡǰ%d��\n",project_pos,temp->project_name,temp->mark);
        printf("��������Ŀ����:(3/5):");
        again1:scanf("%d%*c",&mark);
        if(mark!=3 && mark!=5)
        {
            printf("��������!\n");
            printf("����������:");
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
            printf("���ڿ�ʼ����¼��(%d)%s�Ļ���\n",project_pos,temp->project_name);
            InputCredit(S,project_pos);
        }
        temp->mark=mark;
        printf("�޸ĳɹ�!\n");
    }
    else if(choice==4)
    {
        printf("(%d)%s ����Ŀ�Ƿ��Ѿ�����(%d)\n",project_pos,temp->project_name,temp->carryout);
        printf("��������Ŀ�Ľ������:(1����/0δ����):");
        again2:scanf("%d%*c",&flag);
        if(flag!=0 && flag!=1)
        {
            printf("��������!\n");
            printf("����������:");
            goto again2;
        }
        if(!temp->carryout && flag)
        {
            printf("���ڿ�ʼ¼��(%d)%s�Ļ���\n",project_pos,temp->project_name);
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
        printf("�޸ĳɹ�!\n");
    }
}