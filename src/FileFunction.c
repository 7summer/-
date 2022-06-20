#include "SportMeeting.h"
void InputToFile(SportMeeting *S)
{
    FILE *f;
    int i,j;
    int n;
    School *temp;
    Project *temp2;
    f=fopen("F:\\excise\\运动会.txt","w");  //储存位置根据自身情况而定
    fprintf(f,"学校%d所\t男子项目%d项\t女子项目%d项\n",S->n,S->man_num,S->women_num);
    for(i=1;i<=S->n;i++)
    {
        temp=&(S->school[i]);
        fprintf(f,"(%d)%s\t项目总分:%d\t男子项目总分:%d\t女子项目总分:%d\n",temp->number,temp->school_name,temp->sum,temp->man_sum,temp->women_sum);
    }
    for(i=1;i<=S->man_num+S->women_num;i++)
    {
        temp2=&(S->project[i]);
        fprintf(f,"(%d)%s 取前%d名 该项目是否已经进行(%d)\t",i,temp2->project_name,temp2->mark,temp2->carryout);
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
    printf("成功录入到文件\n");
}
void OuputFromFile(SportMeeting *S)
{
    FILE *f;
    School *temp1;
    Project *temp2;
    ProjectCredits *temp3;
    int i,j;
    int n;
    f=fopen("F:\\excise\\运动会.txt","r");
    fscanf(f,"学校%d所\t男子项目%d项\t女子项目%d项\n",&S->n,&S->man_num,&S->women_num);
    for(i=1;i<=S->n;i++)
    {
        temp1=&(S->school[i]);
        fscanf(f,"(%d)%s\t项目总分:%d\t男子项目总分:%d\t女子项目总分:%d\n",&temp1->number,temp1->school_name,&temp1->sum,&temp1->man_sum,&temp1->women_sum);
        for(j=1;j<=S->man_num+S->women_num;j++)
        {
            temp1->high_standings[j]=0;
        }
    }
    for(i=1;i<=S->man_num+S->women_num;i++)
    {
        temp2=&(S->project[i]);
        fscanf(f,"(%*d)%s 取前%d名 该项目是否已经进行(%d)\t",temp2->project_name,&temp2->mark,&temp2->carryout);
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
    printf("已从文件中成功读取数据!\n");
}
