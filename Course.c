#include <stdio.h>
#include <stdlib.h>
#include "subfunction.h"
void subwelcome()
{
	printf("*****************");
	printf("\n\t欢迎进入学生课程管理子系统\n\n"); 
}
int CourseSystem()
{
	int select=0;
	system("cls");
	subwelcome();
	while(1){
	printf("****************\n");
	printf("\t\t1 录入课程\n");
	printf("\t\t2 课程修改\n");
	printf("\t\t3 学生选课\n");
	printf("\t\t0 退出系统\n");
	printf("****************\n");
	printf("请选择要进行的操作，输入对应的序号(0-3)\n");
	scanf("%d",&select);
	if(0>select || select>3)
	{
		printf("你的输入有误，请重新输入\n");
		continue;
	}
	else if(0==select)
	{
		system("cls");
		return select;
	}
	else {
		int ret =subprocessUserSelected(select);
	}
	}
}
int subprocessUserSelected(int selected)
{
	switch(selected)
	{
		case 1:
			CourseInput();
			break;
		case 2:
			CourseModify();
			break;
		case 3:
			CourseSelect();
			break;
		default:
			break;		
	}
}
