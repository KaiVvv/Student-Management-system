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
		printf("\t\t1 ѧ������\n");
		printf("\t\t2 ѧ���ɼ�¼��\n");
		printf("\t\t3 ѧ���ɼ��޸�\n");
		printf("\t\t4 ѧ���ɼ���ѯ\n");
		printf("\t\t5 ѧ���ɼ����\n");
		printf("\t\t6 ѧ���ɼ�ͳ��\n");
		printf("\t\t7 ѧ���ɼ�����\n");
		printf("\t\t8 ѧ���ɼ�����\n");
		printf("\t\t9 ѧ��ɾ��\n");
		printf("\t\t10 �γ̹�����ϵͳ\n");
		printf("\t\t11 �����ϱ�\n");
		printf("\t\t12 ��ѯ�����ϱ����\n");
		printf("\t\t0 ϵͳ�˳�\n");
		printf("**********************************************\n");
		printf("��ѡ����Ҫ���еĲ����������Ӧ�����(0~12)\n");
		scanf("%d",&selectIndex);
		if(0 > selectIndex || selectIndex > 12 ){
			printf("���������������������\n");
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
