#include "SportMeeting.h"
int ExamineNameProject(SportMeeting *S)
{
    int i,n;
    int flag;
    char name[20];
    Project *temp;
    printf("请问是男子项目还是女子项目(1/0):");
    again:scanf("%d%*c",&flag);
    if(flag!=1 && flag!=0)
    {
        printf("输入有误!\n");
        printf("请重新输入:");
        goto again;
    }
    if(flag) {i=1;n=S->man_num;}
    else {i=S->man_num+1;n=S->women_num+S->man_num;}
    printf("请输入项目名称:");
    scanf("%s%*c",name);
    for(;i<=n;i++)
    {
        temp=&(S->project[i]);
        if(!strcmp(name,temp->project_name))
        {
            return i;
        }
    }
    return 0;
}
int ExamineNumberProject(SportMeeting *S)
{
    int pos;
    printf("请输入项目编号:");
    scanf("%d%*c",&pos);
    if(pos<1 || pos>S->man_num+S->women_num) return 0;
    return pos;
}
int ExamineNameSchool(SportMeeting *S)
{
    char name[20];
    int i;
    School *temp;
    printf("请输入学校名称:");
    scanf("%s%*c",name);
    for(i=1;i<=S->n;i++)
    {
        temp=&(S->school[i]);
        if(!strcmp(name,temp->school_name))
        {
            return i;
        }
    }
    return 0;
}
int ExamineNumberSchool(SportMeeting *S)
{
    int n;
    printf("请输入学校编号:");
    scanf("%d%*c",&n);
    n=ExamineSchool_pos(S,n);
    return n;  
}
/*
int ExamineNumberSchool(SportMeeting *S)
{
    int n;
    printf("请输入学校编号:");
    scanf("%d%*c",&n);
    if(n<1 || n>S->n) return 0;
    return n;
}
*/
int ExamineSchool_pos(SportMeeting *S,int n)
{
    if(n<1 || n>S->n) return 0;
    int i;
    for(i=1;i<=S->n;i++)
    {
        if(S->school[i].number==n) return i;
    }
    return 0;  
}