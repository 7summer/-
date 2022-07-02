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
            printf("    1.��ѧУ���Ʋ�ѯ\n\
    2.��ѧУ��Ų�ѯ\n\
    3.�˳�\n");
            printf("��ѡ��:");
            scanf("%d%*c",&choice2);
            switch (choice2)
            {
                case 1:
                    pos=ExamineNameSchool(S);
                    if(pos) FindSchool(S,pos);
                    else printf("�����ѧУ��������!\n");
                    break;
                case 2:
                    pos=ExamineNumberSchool(S);
                    if(pos) FindSchool(S,pos);
                    else printf("�����ѧУ�������!\n");
                    break;
                case 3:
                    printf("лл!\n");
                    break;
                default:
                    printf("��������!\n");
                    break;
            }
        } while (choice2!=3);
    }
    else
    {
        do
        {
            printf("    1.��ѯ�ѽ��е���Ŀ\n\
    2.��ѯδ���е���Ŀ\n\
    3.��ѯ������Ŀ�Ĳ�������\n\
    4.�˳�\n");
            printf("��ѡ��:");
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
                            printf("��δ¼���������!\n");
                        }
                    }
                }
                case 4:
                    printf("лл!\n");
                    break;
                default:
                    printf("��������!\n");
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
    printf("���ڿ�ʼ��ѯ(%d)%s������\n",temp->number,temp->school_name);
    do
    {
        printf("    1.�鿴ѧУ���ܷ֡�������Ŀ�ܷ֡�Ů����Ŀ�ܷ�\n\
    2.�鿴ѧУ������Ŀ�Ļ���\n\
    3.�鿴ѧУ�ѻ�û��ֵ���Ŀ\n\
    4.�鿴ĳ����Ŀ�Ļ���\n\
    5.�˳�\n");
        printf("������:");
        scanf("%d%*c",&choice);
        switch (choice)
        {
            case 1:
                printf("(%d)%s\t�ܷ�:%d\t������Ŀ�ܷ�:%d\tŮ����Ŀ�ܷ�:%d\n",temp->number,temp->school_name,temp->sum,temp->man_sum,temp->women_sum);
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
                    else printf("(%d)%s��δ��ʼ\n",i,temp2->project_name);   
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
                    printf("    1.����Ŀ���Ʋ�ѯ\n\
    2.����Ŀ��Ų�ѯ\n\
    3.�˳�\n");
                    printf("��ѡ��:");
                    scanf("%d%*c",&choice2);
                    switch (choice2)
                    {
                        case 1:
                            project_pos=ExamineNameProject(S);
                            if(!project_pos) printf("�������Ŀ��������!\n");
                            else if(ExamineParticipatingSchool(S,school_pos,project_pos))
                            {
                                temp2=&(S->project[project_pos]);
                                if(!temp2->carryout) printf("(%d)%s��û�н���\n",project_pos,temp2->project_name);
                                else printf("%s��(%d)%s�л��%d����\n",temp->school_name,project_pos,temp2->project_name,temp->high_standings[project_pos]);
                            }
                            break;
                        case 2:
                            project_pos=ExamineNumberProject(S);
                            if(!project_pos) printf("�������Ŀ�������!\n");
                            else if(ExamineParticipatingSchool(S,school_pos,project_pos))
                            {
                                temp2=&(S->project[project_pos]);
                                if(!temp2->carryout) printf("(%d)%s��û�н���\n",project_pos,temp2->project_name);
                                else printf("%s��(%d)%s�л��%d����\n",temp->school_name,project_pos,temp2->project_name,temp->high_standings[project_pos]);
                            }
                            break;
                        case 3:
                            printf("лл!\n");
                            break;
                        default:
                            printf("��������!\n");
                            break;
                    }
                } while (choice2!=3);
                break;
            case 5:
                printf("лл!\n");
                break; 
            default:
                printf("�������!\n");
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
    printf("(%d)%s��Ŀȡǰ%d��\n",project_pos,temp->project_name,temp->mark);
    if(temp->carryout)
    {
        for(i=1;i<=temp->mark;i++)
        {
            temp2=&(S->school[temp->AwardSchools[i].sequence]);
            printf("(%d)%s ��%d�� ���%d����\n",temp2->number,temp2->school_name,i,temp->AwardSchools[i].credits);
        }
    }
}
*/