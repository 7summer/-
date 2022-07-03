#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int sequence; //记录学校编号
    int credits; //记录积分
}ProjectCredits;
typedef struct
{
    char project_name[20]; //记录项目名称
    int mark; //用来记录该项目是取前五还是前三
    int num; //参赛学校数量
    int carryout; //判断该项目是否进行
    ProjectCredits AwardSchools[6]; //用来记录哪些学校获奖、获得多少积分
    int ParticipatingSchool[20]; //记录参赛学校的编号
}Project;
typedef struct
{
    char school_name[20]; //记录学校名称
    int number; //学校编号
    int sum; //记录学校总分
    int man_sum,women_sum; //分别记录男子、女子项目总分
    int high_standings[41]; //该校各个项目的积分榜
}School;
typedef struct
{
    int n; //记录学校个数
    int man_num,women_num; //分别记录男子项目和女子项目的个数
    Project project[41]; //1~20为男子项目 21~40为女子项目
    School school[21]; //可以记录20所学校的积分情况
}SportMeeting;
void InputData(SportMeeting *S); //可以选择录入学校数据、项目数据
void InputCredit(SportMeeting *S,int project_pos); //在项目编号为pos的位置录入积分数据
void InputParticipatingSchool(SportMeeting *S,int project_pos); //在项目编号为pos的位置录入参赛学校数据
void InputToFile(SportMeeting *S);
void OuputFromFile(SportMeeting *S);
void Find(SportMeeting *S,int choice); //询问用户是想通过名称查询还是编号查询
void FindSchool(SportMeeting *S,int school_pos); //询问用户需要输出什么数据，然后输出出来
//void FindProject(SportMeeting *S,int project_pos);
int ExamineNameProject(SportMeeting *S); //在函数里输入项目名称，然后查找该项目名称是否在项目里，如果不在就返回0
int ExamineNumberProject(SportMeeting *S); //在函数里输入项目编号，然后查找该项目编号是否在项目里，如果不在就返回0
int ExamineNameSchool(SportMeeting *S);
int ExamineNumberSchool(SportMeeting *S);
int ExamineSchool_pos(SportMeeting *S,int n); //查找学校编号为n的位置,并返回这个位置
int ExamineParticipatingSchool(SportMeeting *S,int school_pos,int project_pos);
void ModifySchoolName(SportMeeting *S,int school_pos); //修改school_pos位置的学校名称
void ModifyProject(SportMeeting *S,int project_pos,int choice); //修改项目的名称、项目进行情况 choice(2修改项目名称 3修改项目名次 4修改项目进行情况)
void NumberSort(SportMeeting *S); //使用冒泡排序
void SumSort(SportMeeting *S); //使用希尔排序
void ManCreditSort(SportMeeting *S,int low,int high); //使用快速排序 low代表最小的坐标 high代表最大的坐标
void WomenCreditSort(SportMeeting *S); //堆排序
void AdjustTree(SportMeeting *S,int n,int k); //n为最大下标值 k为调整点下标
