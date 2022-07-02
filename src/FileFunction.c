#include "SportMeeting.h"
void InputToFile(SportMeeting *S)
{
    FILE *f;
    int i,j;
    int school_pos;
    int n;
    School *temp;
    Project *temp2;
    f=fopen("C:\\�˶���.txt","w");
    fprintf(f,"ѧУ%d��\t������Ŀ%d��\tŮ����Ŀ%d��\n",S->n,S->man_num,S->women_num);
    for(i=1;i<=S->n;i++)
    {
        temp=&(S->school[i]);
        fprintf(f,"(%d)%s\t��Ŀ�ܷ�:%d\t������Ŀ�ܷ�:%d\tŮ����Ŀ�ܷ�:%d\n",temp->number,temp->school_name,temp->sum,temp->man_sum,temp->women_sum);
    }
    for(i=1;i<=S->man_num+S->women_num;i++)
    {
        temp2=&(S->project[i]);
        fprintf(f,"(%d)%s �Ƿ���¼�����ѧУ(%d)\t",i,temp2->project_name,temp2->num);
        if(temp2->num)
        {
            fprintf(f,"����ѧУ:");
            for(j=1;j<=temp2->num;j++)
            {
                school_pos=ExamineSchool_pos(S,temp2->ParticipatingSchool[j]);
                temp=&(S->school[school_pos]);
                fprintf(f,"(%d)%s\t",temp->number,temp->school_name);
            }
            fprintf(f,"\n");
        }
        else
        {
            fprintf(f,"\n");
        }
    }
    for(i=1;i<=S->man_num+S->women_num;i++)
    {
        temp2=&(S->project[i]);
        fprintf(f,"(%d)%s ȡǰ%d�� ����Ŀ�Ƿ��Ѿ�����(%d)\t",i,temp2->project_name,temp2->mark,temp2->carryout);
        if(!temp2->carryout)
        {
            fprintf(f,"\n");
            continue;
        }
        for(j=1;j<=temp2->mark;j++)
        {
            n=ExamineSchool_pos(S,temp2->AwardSchools[j].sequence);
            temp=&(S->school[n]);
            fprintf(f,"(%d)%s %d\t",temp->number,temp->school_name,temp2->AwardSchools[j].credits);   
        }
        fprintf(f,"\n");
    }
    fclose(f);
    printf("�ɹ�¼�뵽�ļ�\n");
}
void OuputFromFile(SportMeeting *S)
{
    FILE *f;
    School *temp1;
    Project *temp2;
    ProjectCredits *temp3;
    int school_number;
    int i,j;
    int n;
    f=fopen("C:\\�˶���.txt","r");
    fscanf(f,"ѧУ%d��\t������Ŀ%d��\tŮ����Ŀ%d��\n",&S->n,&S->man_num,&S->women_num);
    for(i=1;i<=S->n;i++)
    {
        temp1=&(S->school[i]);
        fscanf(f,"(%d)%s\t��Ŀ�ܷ�:%d\t������Ŀ�ܷ�:%d\tŮ����Ŀ�ܷ�:%d\n",&temp1->number,temp1->school_name,&temp1->sum,&temp1->man_sum,&temp1->women_sum);
        for(j=1;j<=S->man_num+S->women_num;j++)
        {
            temp1->high_standings[j]=0;
        }
    }
    for(i=1;i<=S->man_num+S->women_num;i++)
    {
        temp2=&(S->project[i]);
        fscanf(f,"(%*d)%s �Ƿ���¼�����ѧУ(%d)\t",temp2->project_name,&temp2->num);
        if(temp2->num)
        {
            fscanf(f,"����ѧУ:");
            for(j=1;j<=temp2->num;j++)
            {
                fscanf(f,"(%d)%*s\t",&school_number);
                temp2->ParticipatingSchool[i]=school_number;
            }
        }
    }
    for(i=1;i<=S->man_num+S->women_num;i++)
    {
        temp2=&(S->project[i]);
        fscanf(f,"(%*d)%*s ȡǰ%d�� ����Ŀ�Ƿ��Ѿ�����(%d)\t",&temp2->mark,&temp2->carryout);
        if(temp2->carryout)
        {
            for(j=1;j<=temp2->mark;j++)
            {
                temp3=&(temp2->AwardSchools[j]);
                fscanf(f,"(%d)%*s %d\t",&temp3->sequence,&temp3->credits);
                n=ExamineSchool_pos(S,temp3->sequence);
                S->school[n].high_standings[i]=temp3->credits;
            }
        }
        fscanf(f,"\n");
    }
    fclose(f);
    printf("�Ѵ��ļ��гɹ���ȡ����!\n");
}
