#include "SportMeeting.h"
void InputData(SportMeeting *S)
{
    int i,j,k;
    int flag; //�����ж���Ŀ�Ƿ���Ů����
    int mark;
    int choice;
    S->n=S->man_num=S->women_num=0;
    do
    {
        printf("    1.¼��ѧУ����\n\
    2.¼����Ŀ����\n\
    3.�˳�\n");
        printf("��ѡ��:");
        scanf("%d%*c",&choice);
        switch (choice)
        {
            case 1:
                flag=1;
                printf("������ѧУ����:");
                again:scanf("%d%*c",&S->n);
                if(S->n>20)
                {
                    printf("n<=20\n");
                    printf("����������:");
                    goto again;
                }
                {
                    for(i=1;i<=S->n;i++)
                    {
                        printf("��������Ϊ%d��ѧУ����:",i);
                        scanf("%s%*c",S->school[i].school_name);
                        S->school[i].number=i;
                        S->school[i].sum=0;
                        S->school[i].man_sum=S->school[i].women_sum=0;
                    }   
                }
                break;
            case 2:
                printf("������������Ŀ����:");
                again1:scanf("%d",&S->man_num);
                if(S->man_num>20)
                {
                    printf("n<=20\n");
                    printf("����������:");
                    goto again1;
                }
                printf("������Ů����Ŀ����:");
                again2:scanf("%d%*c",&S->women_num);
                if(S->women_num>20)
                {
                    printf("n<=20\n");
                    printf("����������:");
                    goto again2;
                }
                j=1;
                {
                    for(i=1;i<=S->man_num;i++)
                    {
                        printf("��������Ϊ%d����Ŀ����:",i);
                        scanf("%s",S->project[i].project_name);
                        printf("%s��Ŀ��ȡǰ��������ȡǰ����?(ȡǰ��������5 ȡǰ��������3):",S->project[i].project_name);
                        again3:scanf("%d%*c",&mark);
                        if(mark!=3 && mark!=5)
                        {
                            printf("��������!\n");
                            printf("����������:");
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
                        printf("�����Ŀ��Ů������:(1/0):");
                        again4:scanf("%d%*c",&flag);
                        if(flag!=0 && flag!=1)
                        {
                            printf("��������!");
                            printf("����������:");
                            goto again4;
                        }
                        if(flag)
                        {
                            printf("(Ů��)%s��Ŀ���Ϊ:%d\n",S->project[i].project_name,S->man_num+j);
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
                        printf("��������Ϊ%d����Ŀ����:",j+S->man_num);
                        scanf("%s",S->project[j+S->man_num].project_name);
                        printf("%s��Ŀ��ȡǰ��������ȡǰ����?(ȡǰ��������5 ȡǰ��������3):",S->project[j+S->man_num].project_name);
                        again5:scanf("%d%*c",&mark);
                        if(mark!=3 && mark!=5)
                        {
                            printf("��������!\n");
                            printf("����������:");
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
                printf("�������!\n");
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
    printf("¼�������Ϣ���!\n");
}
void InputCredit(SportMeeting *S,int project_pos)
{
    Project *temp;
    School *temp2;
    int i;
    int record=999; //��������Ļ���¼��ʱ����ֹ�������ǰ��
    int credit;
    int school_pos;
    int choice;
    char name[20];
    temp=&(S->project[project_pos]);
    temp->carryout=1; //����Ŀ�ѽ���
    if(temp->mark>S->n)
    {
        temp->mark=S->n;
    }
    printf("(%d)%s��Ŀȡǰ%d��\n",project_pos,temp->project_name,temp->mark);
    for(i=1;i<=temp->mark;i++)
    {
        printf("����¼���%d���Ļ�������\n",i);
        do
        {
            printf("    1.��ѧУ����¼��\n\
    2.��ѧУ���¼��\n");
            printf("��ѡ��:");
            scanf("%d%*c",&choice);
            switch(choice)
            {
                case 1:
                    school_pos=ExamineNameSchool(S);
                    if(!school_pos)
                    {
                        choice=0;
                        printf("�����ѧУ��������!\n");
                    }
                    break;
                case 2:
                    school_pos=ExamineNumberSchool(S);
                    if(!school_pos)
                    {
                        choice=0;
                        printf("�����ѧУ�������!\n");
                    }
                    break;
                default:
                    printf("�������!\n");
                    break;
            }
        } while (choice!=1 && choice!=2);
        temp2=&(S->school[school_pos]);
        temp->AwardSchools[i].sequence=temp2->number;
        printf("������%s��%s��Ŀ��õĻ���:",temp2->school_name,temp->project_name);
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
            printf("����Ļ��ִ��ڻ����ǰһ���Ļ���\n");
            printf("����������:");
            goto again;
        }
    }
    
}