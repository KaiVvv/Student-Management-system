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
	printf("请输入课程编号\n");
	scanf("%ld",&couContainer[courseIndex].Id);
	printf("请输入课程名称\n");
	scanf("%s",&couContainer[courseIndex].CourseName);
	printf("请输入主讲讲师\n");
	scanf("%s",&couContainer[courseIndex].teacher);
	printf("请输入学分\n");
	scanf("%d",&couContainer[courseIndex].score); 
	courseIndex++;
	courseCount++;
	printf("是否继续添加(yes/no)\n");
	scanf("%s",answer);
	if(0==strcmp(answer,"no"))
	{
		break;
	}
	}
	printf("是否保存(yes/no)\n");
	scanf("%s",answer);
	if(0==strcmp(answer,"yes"))
	{
		FILE *fp=NULL;
		fp=fopen(".\\courseInfo","wt+");
		if(NULL==fp)
		{
			printf("打开失败\n");
			return -1; 
		}
		int i=0;
		int tmpRet=0;
		for(i=0;i<courseCount;i++)
		{
			tmpRet=fwrite(&couContainer[i],sizeof(couContainer),1,fp);
			if(1!=tmpRet)
			{
				printf("写入不成功\n");
			}
		}
		fclose(fp);
		printf("保存成功\n");
	}
}
int CourseModify()//修改 
{
	int i;
	int answer;
	int id;
	int Index = -1; 
	char name[10]; 
	printf("*******************检索课程*******************\n");
	printf("\t\t1 编号检索\n");
	printf("\t\t2 姓名检索\n");
	
	printf("**********************************************\n");
	printf("请输入\n");
	scanf("%d",&answer);
	if(1 == answer){
		printf("请输入Id\n");
		scanf("%d",&id);
		printf("编号\t名称\t讲师\t学分\n");
			for(i=0;i<courseIndex;i++){
				if(id == couContainer[i].Id){
					
					printf("%ld\t",couContainer[i].Id);
					printf("%s\t",couContainer[i].CourseName);
					printf("%s\t",couContainer[i].teacher);
					printf("%d\n",couContainer[i].score);
					
				}
			}
			
		
	}else if(2 == answer){
		printf("请输入名称\n");
		scanf("%s",&name);
		
		for(i=0;i<courseIndex;i++){
		if(name == couContainer[i].CourseName){
		printf("编号\t名称\t讲师\t学分\n");
		printf("%ld\t",couContainer[i].Id);
		printf("%s\t",couContainer[i].CourseName);
		printf("%s\t",couContainer[i].teacher);
		printf("%d\n",couContainer[i].score);
							
						}
					}
	} else{
		printf("输入有误\n");
	}

	int select = 0; 
		while(1){
			printf("************请选择要修改的内容****************\n");
			printf("\t\t1 编号修改\n");
			printf("\t\t2 名称修改\n");
			printf("\t\t3 讲师修改\n");
			printf("\t\t4 学分修改\n");
			printf("\t\t0 退出\n");
			printf("**********************************************\n");
			printf("请选择(0~4)\n");
			scanf("%d",&select);
			if(0 > select || select > 4 ){
				printf("你的输入有误，请重新输入\n");
				continue; 
			}else if(0 == select){
				break;
			}else{ 
			              i=i-1;
						switch(select){
						case 1:
							printf("请输入修改后编号\n");
							scanf("%ld",&couContainer[i].Id);
							printf("修改完成\n");
							break;
						case 2:
							printf("请输入修改后名称\n");
							scanf("%s",&couContainer[i].CourseName);
							printf("修改完成\n");
							break;
						case 3:
							printf("请输入修改后讲师\n");
							scanf("%s",&couContainer[i].teacher);
							printf("修改完成\n");
							break;
						case 4: 
							printf("请输入修改后学分\n");
							scanf("%d",&couContainer[i].score);
							printf("修改完成\n");
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
									printf("写入不成功\n");
								}
							}
							fclose(fp);
							printf("保存成功\n");
						}
			}
		}


		
		

int CourseRead()
{
	FILE *fp=NULL;
	fp=fopen(".\\courseInfo","r");
	if(NULL==fp)
	{
		printf("打开失败\n");
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
	printf("**********课程信息***********\n");
	int i=0;
	int courseId=0;
	printf("课程编号\t课程名称\t讲师\t学分\n");
	for(i=0;i<courseCount;i++)
	{
		
		showCourseInfo(i);
	}
	printf("**********************\n");
	printf("请输入所选课程的Id\n");
	scanf("%ld",&courseId);
	for(i=0;i<studentCount;i++)
	{
		if(stuContainer[i].Id==CurrentUser.Id)
		{
			stuContainer[i].CourseId=courseId;
		}
	}
}
