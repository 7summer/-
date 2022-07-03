#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int sequence; //��¼ѧУ���
    int credits; //��¼����
}ProjectCredits;
typedef struct
{
    char project_name[20]; //��¼��Ŀ����
    int mark; //������¼����Ŀ��ȡǰ�廹��ǰ��
    int num; //����ѧУ����
    int carryout; //�жϸ���Ŀ�Ƿ����
    ProjectCredits AwardSchools[6]; //������¼��ЩѧУ�񽱡���ö��ٻ���
    int ParticipatingSchool[20]; //��¼����ѧУ�ı��
}Project;
typedef struct
{
    char school_name[20]; //��¼ѧУ����
    int number; //ѧУ���
    int sum; //��¼ѧУ�ܷ�
    int man_sum,women_sum; //�ֱ��¼���ӡ�Ů����Ŀ�ܷ�
    int high_standings[41]; //��У������Ŀ�Ļ��ְ�
}School;
typedef struct
{
    int n; //��¼ѧУ����
    int man_num,women_num; //�ֱ��¼������Ŀ��Ů����Ŀ�ĸ���
    Project project[41]; //1~20Ϊ������Ŀ 21~40ΪŮ����Ŀ
    School school[21]; //���Լ�¼20��ѧУ�Ļ������
}SportMeeting;
void InputData(SportMeeting *S); //����ѡ��¼��ѧУ���ݡ���Ŀ����
void InputCredit(SportMeeting *S,int project_pos); //����Ŀ���Ϊpos��λ��¼���������
void InputParticipatingSchool(SportMeeting *S,int project_pos); //����Ŀ���Ϊpos��λ��¼�����ѧУ����
void InputToFile(SportMeeting *S);
void OuputFromFile(SportMeeting *S);
void Find(SportMeeting *S,int choice); //ѯ���û�����ͨ�����Ʋ�ѯ���Ǳ�Ų�ѯ
void FindSchool(SportMeeting *S,int school_pos); //ѯ���û���Ҫ���ʲô���ݣ�Ȼ���������
//void FindProject(SportMeeting *S,int project_pos);
int ExamineNameProject(SportMeeting *S); //�ں�����������Ŀ���ƣ�Ȼ����Ҹ���Ŀ�����Ƿ�����Ŀ�������ھͷ���0
int ExamineNumberProject(SportMeeting *S); //�ں�����������Ŀ��ţ�Ȼ����Ҹ���Ŀ����Ƿ�����Ŀ�������ھͷ���0
int ExamineNameSchool(SportMeeting *S);
int ExamineNumberSchool(SportMeeting *S);
int ExamineSchool_pos(SportMeeting *S,int n); //����ѧУ���Ϊn��λ��,���������λ��
int ExamineParticipatingSchool(SportMeeting *S,int school_pos,int project_pos);
void ModifySchoolName(SportMeeting *S,int school_pos); //�޸�school_posλ�õ�ѧУ����
void ModifyProject(SportMeeting *S,int project_pos,int choice); //�޸���Ŀ�����ơ���Ŀ������� choice(2�޸���Ŀ���� 3�޸���Ŀ���� 4�޸���Ŀ�������)
void NumberSort(SportMeeting *S); //ʹ��ð������
void SumSort(SportMeeting *S); //ʹ��ϣ������
void ManCreditSort(SportMeeting *S,int low,int high); //ʹ�ÿ������� low������С������ high������������
void WomenCreditSort(SportMeeting *S); //������
void AdjustTree(SportMeeting *S,int n,int k); //nΪ����±�ֵ kΪ�������±�
