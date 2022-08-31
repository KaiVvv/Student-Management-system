#ifndef _GLOBEDEFINE_H_
#define _GLOBEDEFINE_H_

#define maxSize 500

enum studentM{
	Student_Add = 1,
	Student_Input,
	Student_Modify,
	Student_Query,
	Student_Output,
	Student_Count,
	Student_Save,
	Student_Read,
	Student_Delete
};

typedef struct Stu{
	unsigned long int Id;
	char Name[20]; 
	char Major[20];
	int cScore;			//c���Գɼ�
    int JavaScore;		//Java�ɼ�
    int avgScore;		//���Ƶ�ƽ����
    int count;			//�ܷ� 
	int rank;
    unsigned long int CourseId;
}Student;
typedef struct cour
{
	unsigned long int Id;
	char CourseName[10];
	char teacher[12];
	int score;

}Course;
extern Student CurrentUser;
typedef struct HealtReport
{
	unsigned long int Id;
	
	char address[10];
	float  temperature; 
	

}Healt;

#endif
