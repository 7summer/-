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
        printf("    1.¼��ѧУ����Ŀ����\n\
    2.¼���������\n\
    3.�ӵ����ж�����\n\
    4.�����ݴ洢������\n\
    5.��ѯ����\n\
    6.�޸�����\n\
    7.�鿴����\n\
    8.�˳�\n");
        printf("������:");
        scanf("%d%*c",&choice1);
        switch (choice1)
        {
            case 1:
                InputData(&S);
                break;
            case 2:
                do
                {
                    printf("��δ���е���Ŀ\n");
                    for(i=1;i<=S.man_num+S.women_num;i++)
                    {
                        temp2=&(S.project[i]);
                        if(!temp2->carryout) printf("(%d)%s\n",i,temp2->project_name);
                    }
                    printf("    1.����Ŀ�����������\n\
    2.����Ŀ����������\n\
    3.�˳�\n");
                    printf("������:");
                    scanf("%d%*c",&choice2);
                    switch(choice2)
                    {
                        case 1:
                            pos=ExamineNameProject(&S);
                            if(pos) InputCredit(&S,pos);
                            else printf("�������Ŀ��������!\n");
                            break;
                        case 2:
                            pos=ExamineNumberProject(&S);
                            if(pos) InputCredit(&S,pos);
                            else printf("�������Ŀ�������!\n");
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
            case 3:
                OuputFromFile(&S);
                break;
            case 4:
                InputToFile(&S);
                break;
            case 5:
                do
                {
                    printf("    1.�鿴ȫ��ѧУ�ķ�������\n\
    2.�鿴ȫ����Ŀ�Ļ�����\n\
    3.�鿴ѧУ����ϸ����\n\
    4.�鿴��Ŀ����ϸ����\n\
    5.�˳�\n");
                    printf("������:");
                    scanf("%d%*c",&choice2);
                    switch (choice2)
                    {
                        case 1:
                            {
                                for(i=1;i<=S.n;i++)
                                {
                                    temp1=&(S.school[i]);
                                    printf("(%d)%s\t�ܷ�:%d\t������Ŀ�ܷ�:%d\tŮ����Ŀ�ܷ�:%d\n",temp1->number,temp1->school_name,temp1->sum,temp1->man_sum,temp1->women_sum);
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
                            printf("лл!\n");
                            break;
                        default:
                            printf("��������!\n");
                            break;
                    }
                } while (choice2!=5);
                break;
            case 6:
                do
                {
                    printf("    1.�޸�ѧУ����\n\
    2.�޸���Ŀ����\n\
    3.�޸���Ŀ����\n\
    4.�޸���Ŀ�������\n\
    5.�޸���Ŀ����\n\
    6.�޸���Ŀ����ѧУ\n\
    7.�˳�\n");
                    printf("������:");
                    scanf("%d%*c",&choice2);
                    switch (choice2)
                    {
                        case 1:
                            printf("������ѧУ���:");
                            again1:scanf("%d%*c",&pos);
                            pos=ExamineSchool_pos(&S,pos);
                            if(!pos) 
                            {
                                printf("�������!\n");
                                printf("����������:");
                                goto again1;
                            }
                            ModifySchoolName(&S,pos);
                            break;
                        case 2: //�޸���Ŀ����
                            printf("��������Ŀ���:");
                            again2:scanf("%d%*c",&pos);
                            if(pos>S.man_num+S.women_num)
                            {
                                printf("�������!\n");
                                printf("����������:");
                                goto again2;
                            }
                            ModifyProject(&S,pos,choice2);
                            break;
                        case 3: //�޸���Ŀ����
                            printf("��������Ŀ���:");
                            again3:scanf("%d%*c",&pos);
                            if(pos>S.man_num+S.women_num)
                            {
                                printf("�������!\n");
                                printf("����������:");
                                goto again3;
                            }
                            ModifyProject(&S,pos,choice2);
                            break;                    
                        case 4: //�޸���Ŀ�������
                            printf("��������Ŀ���:");
                            again4:scanf("%d%*c",&pos);
                            if(pos>S.man_num+S.women_num)
                            {
                                printf("�������!\n");
                                printf("����������:");
                                goto again4;
                            }
                                ModifyProject(&S,pos,choice2);
                            break;
                        case 5: //�޸���Ŀ����
                            printf("��������Ŀ���:");
                            again5:scanf("%d%*c",&pos);
                            if(pos>S.man_num+S.women_num)
                            {
                                printf("�������!\n");
                                printf("����������:");
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
                            else printf("(%d)%s��û��ʼ!\n",pos,temp2->project_name);
                            break;
                        case 6:
                            printf("��������Ŀ���:");
                            again6:scanf("%d%*c",&pos);
                            if(pos>S.man_num+S.women_num)
                            {
                                printf("�������!\n");
                                printf("����������:");
                                goto again6;
                            }
                            temp2=&(S.project[pos]);
                            if(temp2->carryout)
                            {
                                printf("(%d)%s��¼�����,���޸���Ŀ���������,���޸���Ŀ����ѧУ,�ٶ���Ŀ����¼�����\n",pos,temp2->project_name);
                            }
                            else
                            {
                                InputParticipatingSchool(&S,pos);
                            }
                            break;
                        case 7:
                            printf("лл!\n");
                            break;
                        default:
                            printf("��������!\n");
                            break;
                    }
                } while (choice2!=7);
                break;
            case 7:
                do
                {
                    printf("    1.��ѧУ����������\n\
    2.��ѧУ�ܷ��������\n\
    3.��ѧУ������Ŀ�ܷ��������\n\
    4.��ѧУŮ����Ŀ�ܷ��������\n\
    5.�˳�\n");
                    printf("��ѡ��:");
                    scanf("%d%*c",&choice2);
                    switch (choice2)
                    {
                        case 1:
                            NumberSort(&S);
                            {
                                for(i=1;i<=S.n;i++)
                                {
                                    temp1=&(S.school[i]);
                                    printf("(%d)%s\t�ܷ�:%d\n",temp1->number,temp1->school_name,temp1->sum);
                                }
                            }                           
                            break;
                        case 2:
                            SumSort(&S);
                            {
                                for(i=1;i<=S.n;i++)
                                {
                                    temp1=&(S.school[i]);
                                    printf("(%d)%s\t�ܷ�:%d\n",temp1->number,temp1->school_name,temp1->sum);
                                }
                            }
                            break;
                        case 3:
                            ManCreditSort(&S,1,S.n);
                            {
                                for(i=1;i<=S.n;i++)
                                {
                                    temp1=&(S.school[i]);
                                    printf("(%d)%s\t������Ŀ�ܷ�:%d\n",temp1->number,temp1->school_name,temp1->man_sum);
                                }
                            }
                            break;
                        case 4:
                            WomenCreditSort(&S);
                            {
                                for(i=1;i<=S.n;i++)
                                {
                                    temp1=&(S.school[i]);
                                    printf("(%d)%s\tŮ����Ŀ�ܷ�:%d\n",temp1->number,temp1->school_name,temp1->women_sum);
                                }
                            }
                            break;
                        case 5:
                            printf("лл!\n");
                            break;
                        default:
                            printf("�������!\n");
                            break;
                    }
                } while (choice2!=5);
                break;
            case 8:
                printf("лл!\n");
                break;
            default:
                printf("��������!\n");
                break;
        }
    } while (choice1!=8);
    return 0;
}