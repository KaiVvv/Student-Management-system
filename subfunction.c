#include <stdio.h>
#include <stdlib.h>
#include "GlobeDefine.h"
#include "subfunction.h"
#include "functionProcessing.h"
Course couContainer[20];
int courseIndex=0;
int	courseCount=0;
int CourseInput()
{
	char answer[10];
	while(1)
	{
	printf("������γ̱��\n");
	scanf("%ld",&couContainer[courseIndex].Id);
	printf("������γ�����\n");
	scanf("%s",&couContainer[courseIndex].CourseName);
	printf("������������ʦ\n");
	scanf("%s",&couContainer[courseIndex].teacher);
	printf("������ѧ��\n");
	scanf("%d",&couContainer[courseIndex].score); 
	courseIndex++;
	courseCount++;
	printf("�Ƿ�������(yes/no)\n");
	scanf("%s",answer);
	if(0==strcmp(answer,"no"))
	{
		break;
	}
	}
	printf("�Ƿ񱣴�(yes/no)\n");
	scanf("%s",answer);
	if(0==strcmp(answer,"yes"))
	{
		FILE *fp=NULL;
		fp=fopen(".\\courseInfo","wt+");
		if(NULL==fp)
		{
			printf("��ʧ��\n");
			return -1; 
		}
		int i=0;
		int tmpRet=0;
		for(i=0;i<courseCount;i++)
		{
			tmpRet=fwrite(&couContainer[i],sizeof(couContainer),1,fp);
			if(1!=tmpRet)
			{
				printf("д�벻�ɹ�\n");
			}
		}
		fclose(fp);
		printf("����ɹ�\n");
	}
}
int CourseModify()//�޸� 
{
	int i;
	int answer;
	int id;
	int Index = -1; 
	char name[10]; 
	printf("*******************�����γ�*******************\n");
	printf("\t\t1 ��ż���\n");
	printf("\t\t2 ��������\n");
	
	printf("**********************************************\n");
	printf("������\n");
	scanf("%d",&answer);
	if(1 == answer){
		printf("������Id\n");
		scanf("%d",&id);
		printf("���\t����\t��ʦ\tѧ��\n");
			for(i=0;i<courseIndex;i++){
				if(id == couContainer[i].Id){
					
					printf("%ld\t",couContainer[i].Id);
					printf("%s\t",couContainer[i].CourseName);
					printf("%s\t",couContainer[i].teacher);
					printf("%d\n",couContainer[i].score);
					
				}
			}
			
		
	}else if(2 == answer){
		printf("����������\n");
		scanf("%s",&name);
		
		for(i=0;i<courseIndex;i++){
		if(name == couContainer[i].CourseName){
		printf("���\t����\t��ʦ\tѧ��\n");
		printf("%ld\t",couContainer[i].Id);
		printf("%s\t",couContainer[i].CourseName);
		printf("%s\t",couContainer[i].teacher);
		printf("%d\n",couContainer[i].score);
							
						}
					}
	} else{
		printf("��������\n");
	}

	int select = 0; 
		while(1){
			printf("************��ѡ��Ҫ�޸ĵ�����****************\n");
			printf("\t\t1 ����޸�\n");
			printf("\t\t2 �����޸�\n");
			printf("\t\t3 ��ʦ�޸�\n");
			printf("\t\t4 ѧ���޸�\n");
			printf("\t\t0 �˳�\n");
			printf("**********************************************\n");
			printf("��ѡ��(0~4)\n");
			scanf("%d",&select);
			if(0 > select || select > 4 ){
				printf("���������������������\n");
				continue; 
			}else if(0 == select){
				break;
			}else{ 
			              i=i-1;
						switch(select){
						case 1:
							printf("�������޸ĺ���\n");
							scanf("%ld",&couContainer[i].Id);
							printf("�޸����\n");
							break;
						case 2:
							printf("�������޸ĺ�����\n");
							scanf("%s",&couContainer[i].CourseName);
							printf("�޸����\n");
							break;
						case 3:
							printf("�������޸ĺ�ʦ\n");
							scanf("%s",&couContainer[i].teacher);
							printf("�޸����\n");
							break;
						case 4: 
							printf("�������޸ĺ�ѧ��\n");
							scanf("%d",&couContainer[i].score);
							printf("�޸����\n");
							break;
						 
					}
				FILE *fp=NULL;
						fp=fopen(".\\courseInfo","wt+");
							int tmpRet=0;
					for(i=0;i<courseCount;i++)
							{
								tmpRet=fwrite(&couContainer[i],sizeof(couContainer),1,fp);
								if(1!=tmpRet)
								{
									printf("д�벻�ɹ�\n");
								}
							}
							fclose(fp);
							printf("����ɹ�\n");
						}
			}
		}


		
		

int CourseRead()
{
	FILE *fp=NULL;
	fp=fopen(".\\courseInfo","r");
	if(NULL==fp)
	{
		printf("��ʧ��\n");
		return -1; 
	}
	int Index=0;
	int Count=0;
	int i=0;
	int tmpRet;
	while(!feof(fp))
	{
		tmpRet=fread(&couContainer[i++],sizeof(couContainer),1,fp);
		if(1!=tmpRet)
		{
			break;
		}
		Index++;
		Count++;
	}
	courseIndex=Index;
	courseCount=Count;
	fclose(fp);
}
void showCourseInfo(int Index)
{
	
	printf("%ld\t\t",couContainer[Index].Id);
	printf("%s\t\t",couContainer[Index].CourseName);
	printf("%s\t",couContainer[Index].teacher);
	printf("%d\n",couContainer[Index].score);
}
int CourseSelect()
{
	printf("**********�γ���Ϣ***********\n");
	int i=0;
	int courseId=0;
	printf("�γ̱��\t�γ�����\t��ʦ\tѧ��\n");
	for(i=0;i<courseCount;i++)
	{
		
		showCourseInfo(i);
	}
	printf("**********************\n");
	printf("��������ѡ�γ̵�Id\n");
	scanf("%ld",&courseId);
	for(i=0;i<studentCount;i++)
	{
		if(stuContainer[i].Id==CurrentUser.Id)
		{
			stuContainer[i].CourseId=courseId;
		}
	}
}
