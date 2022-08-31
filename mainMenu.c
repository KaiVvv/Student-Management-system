#include <stdio.h>
#include <stdlib.h>
#include "GlobeDefine.h"
#include "functionProcessing.h"
#include "Course.h"
int processUserSelected(int selected);

int mainMenu(int isShow){
	
	int selectIndex = 0; 
	
	while(1==isShow){
		printf("**********************************************\n");
		printf("\t\t1 学生新增\n");
		printf("\t\t2 学生成绩录入\n");
		printf("\t\t3 学生成绩修改\n");
		printf("\t\t4 学生成绩查询\n");
		printf("\t\t5 学生成绩输出\n");
		printf("\t\t6 学生成绩统计\n");
		printf("\t\t7 学生成绩保存\n");
		printf("\t\t8 学生成绩读入\n");
		printf("\t\t9 学生删除\n");
		printf("\t\t10 课程管理子系统\n");
		printf("\t\t11 健康上报\n");
		printf("\t\t12 查询健康上报情况\n");
		printf("\t\t0 系统退出\n");
		printf("**********************************************\n");
		printf("请选择所要进行的操作，输入对应的序号(0~12)\n");
		scanf("%d",&selectIndex);
		if(0 > selectIndex || selectIndex > 12 ){
			printf("你的输入有误，请重新输入\n");
			continue; 
		}else if(0 == selectIndex){
			return selectIndex; 
		}else{
			int result = processUserSelected(selectIndex);
		}
		
	}
	return selectIndex;
}

int processUserSelected(int selected){
	switch(selected){
		case Student_Add:
			addNewStudent();
			break;
		case Student_Input:
			studentScoreInput();
			break;
		case Student_Modify:
			studentScoreModify();
			break;
		case Student_Query:
			studentScoreQuery();
			break;
		case Student_Output:
			studentScoreOutput();
			break;
		case Student_Count:
			studentScoreCount();
			break;
		case Student_Save:
			studentScoreSave();
			break;
		case Student_Read:
			studentScoreRead();
			break;
		case Student_Delete:
			studentDelete();
			break;
		case 10:
			CourseSystem();
			break;
		case 11:
			HealthReport();
			break;
		case 12:
			 QueryHealth();
			 break;
		default:
			break; 
	}
	return selected;
}
