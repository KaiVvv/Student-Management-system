#include <stdio.h>
#include <stdlib.h>
#include "subfunction.h"
void subwelcome()
{
	printf("*****************");
	printf("\n\t��ӭ����ѧ���γ̹�����ϵͳ\n\n"); 
}
int CourseSystem()
{
	int select=0;
	system("cls");
	subwelcome();
	while(1){
	printf("****************\n");
	printf("\t\t1 ¼��γ�\n");
	printf("\t\t2 �γ��޸�\n");
	printf("\t\t3 ѧ��ѡ��\n");
	printf("\t\t0 �˳�ϵͳ\n");
	printf("****************\n");
	printf("��ѡ��Ҫ���еĲ����������Ӧ�����(0-3)\n");
	scanf("%d",&select);
	if(0>select || select>3)
	{
		printf("���������������������\n");
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
