#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GlobeDefine.h"
#include "functionProcessing.h"
Student stuContainer[maxSize];
Healt Health[maxSize];
int studentIndex = 0;
int k=0;
int studentCount = 0;

int addNewStudent(){
	printf("请输入学生信息\n");
	while(1){
		printf("请输入学生学号\n");
		scanf("%ld",&stuContainer[studentIndex].Id);
		printf("请输入学生姓名\n");
		scanf("%s",&stuContainer[studentIndex].Name);
		printf("请输入学生专业\n");
		scanf("%s",&stuContainer[studentIndex].Major);
		printf("请输入学生C成绩\n");
		scanf("%d",&stuContainer[studentIndex].cScore); 
		printf("请输入学生Java成绩\n");
		scanf("%d",&stuContainer[studentIndex].JavaScore); 
		
		studentIndex++;
		studentCount++;
		
		printf("学生信息添加成功\n");
		
		printf("是否继续添加(yes/no)\n");
		char answer[10];
		scanf("%s",answer);
		if(0 == strcmp(answer,"no")){
			break;
		}
	}
}

int QueryById(unsigned long int id){
	int i=0;
	for(i=0;i<studentCount;i++){
		if(id == stuContainer[i].Id){
			return i;
		}
	}
	return -1;
} 

int QueryByName(char name[]){
	int i=0;
	for(i=0;i<studentCount;i++){
		if(0 == strcmp(stuContainer[i].Name,name)){
			return i;
		}
	}
	return -1;
} 
int QueryStudent(){
	int answer;
	int id;
	int Index = -1; 
	char name[10]; 
	printf("*******************检索学生*******************\n");
	printf("\t\t1 Id检索\n");
	printf("\t\t2 姓名检索\n");
	printf("**********************************************\n");
	printf("请输入\n");
	scanf("%d",&answer);
	if(1 == answer){
		printf("请输入Id\n");
		scanf("%d",&id);
		printf("id:%d\n",id);
		Index = QueryById(id);
		printf("Index:%ld\n",Index);
	}else if(2 == answer){
		printf("请输入姓名\n");
		scanf("%s",&name);
		Index = QueryByName(name);
	} else{
		printf("输入有误\n");
	}
	return Index;
} 
 
void studentScoreInput(){
	int Index = QueryStudent();
	printf("请输入学生C成绩\n");
	scanf("%d",&stuContainer[Index].cScore); 
	printf("请输入学生Java成绩\n");
	scanf("%d",&stuContainer[Index].JavaScore); 
} 

void ModifyInfo(int Index,int select){
	switch(select){
		case 1:
			printf("请输入学生学号\n");
			scanf("%ld",&stuContainer[Index].Id);
			break;
		case 2:
			printf("请输入学生姓名\n");
			scanf("%s",&stuContainer[Index].Name);
			break;
		case 3:
			printf("请输入学生专业\n");
			scanf("%s",&stuContainer[Index].Major);
			break;
		case 4:
			printf("请输入学生C成绩\n");
			scanf("%d",&stuContainer[Index].cScore); 
			break;
		case 5:
			printf("请输入学生Java成绩\n");
			scanf("%d",&stuContainer[Index].JavaScore); 
			break;		 
	}
} 

void studentScoreModify(){
	int select = 0; 
	int Index = QueryStudent();
	while(1){
		printf("************请选择要修改的字段****************\n");
		printf("\t\t1 学号\n");
		printf("\t\t2 姓名\n");
		printf("\t\t3 专业\n");
		printf("\t\t4 C成绩\n");
		printf("\t\t5 Java成绩\n");
		printf("\t\t0 退出\n");
		printf("**********************************************\n");
		printf("请选择(0~5)\n");
		scanf("%d",&select);
		if(0 > select || select > 5 ){
			printf("你的输入有误，请重新输入\n");
			continue; 
		}else if(0 == select){
			break;
		}else{
			ModifyInfo(Index,select);
		}
	}
			
} 
int QueryByMajor(char major[],int Index[]){
	int i=0,j=0;
	for(i=0;i<studentCount;i++){
		if(0 == strcmp(stuContainer[i].Major,major)){
			Index[j++] = i;
		}
	}
	return j;
}

int QueryByCScore(int CScored,int CScorep,int Index[]){
	int i=0,j=0;
	for(i=0;i<studentCount;i++){
		if(stuContainer[i].cScore > CScored && stuContainer[i].cScore < CScorep){
			Index[j++] = i;
		}
	}
	return j;
}
void showStudentInfo(int Index) {
	printf("%ld\t",stuContainer[Index].Id);
	printf("%s\t",stuContainer[Index].Name);
	printf("%s\t",stuContainer[Index].Major);
	printf("%d\t",stuContainer[Index].cScore);
	printf("%d\t",stuContainer[Index].JavaScore);
	printf("%d\t",stuContainer[Index].avgScore);
	printf("%d\t",stuContainer[Index].count);
	printf("%d\n",stuContainer[Index].rank);
}

void studentScoreQuery(){
		int num = 0;
		int answer;
		int id;
		int Index = -1;
		int IndexContainer[maxSize];
		int CScoredown,CScoreup,JavaScore;
		char name[10]; 
		char major[10]; 
		printf("*******************查找学生*******************\n");
		printf("\t\t1 Id查找\n");
		printf("\t\t2 姓名查找\n");
		printf("\t\t3 专业查找\n");
		printf("\t\t4 C成绩查找\n");
		printf("\t\t5 Java成绩查找\n");
		printf("**********************************************\n");
		printf("请输入\n");
		scanf("%d",&answer);
		if(1 == answer){
			printf("请输入Id\n");
			scanf("%d",&id);
			printf("id:%d\n",id);
			Index = QueryById(id);
			printf("Index:%ld\n",Index);
		}else if(2 == answer){
			printf("请输入姓名\n");
			scanf("%s",&name);
			Index = QueryByName(name);
		}else if(3 == answer){
			printf("请输入专业\n");
			scanf("%s",&major);
			num = QueryByMajor(major,IndexContainer);
		}else if(4 == answer){
			printf("请输入C成绩下限\n");
			scanf("%d",&CScoredown);
			printf("请输入C成绩上限\n");
			scanf("%d",&CScoreup);
			num = QueryByCScore(CScoredown,CScoreup,IndexContainer);
		}else if(5 == answer){
			printf("请输入Java成绩\n");
			scanf("%d",&JavaScore);
//			Index = QueryByJavaScore(JavaScore);
		} else{
			printf("输入有误\n");
		}
	printf("----------------------------------------------------------\n");
	printf("学号\t姓名\t专业\tC成绩\tJava\t平均分\t总分\t排名\n");
	if(1 == answer||2==answer){
		showStudentInfo(Index);
	} else{
		for(int i=0;i<num;i++){
			showStudentInfo(IndexContainer[i]);
		}
	}
} 

void studentScoreOutput(){
	printf("\t\t\t学生信息\n");
	printf("----------------------------------------------------------\n");
	printf("学号\t姓名\t专业\tC成绩\tJava\t平均分\t总分\t排名\n");
	int i=0;
	for(i=0;i<studentCount;i++){
		showStudentInfo(i);
	} 
} 

void studentScoreCount(){
	 int answer=0;
	 int i=0,j=0;
	 int stuId[maxSize],count[maxSize];
	 int temp=0,tempId=0;
	 printf("***********统计***********\n");
	 printf("\t\t1 统计总分\n");
	 printf("\t\t2 统计平均分\n");
	 printf("\t\t3 统计排名\n");
	 printf("*************************\n");
	 printf("请输入\n");
	 scanf("%d",&answer);
	 if(1==answer)
	 {
	 	
	 
	 	for(i=0;i<studentCount;i++)
	 	{
		 	stuContainer[i].count=stuContainer[i].cScore+stuContainer[i].JavaScore;
		 }
	 } else if(2==answer)
	 {
	 
	 	for(i=0;i<studentCount;i++)
	 	{
		 	stuContainer[i].avgScore=(stuContainer[i].cScore+stuContainer[i].JavaScore)/2;
		 }
		
	 }else if(3==answer)
	 		 {
	 		 
			  	for( i=0;i<studentCount;i++)
			  	{
			  		stuId[i]=stuContainer[i].Id;
				  	count[i]=stuContainer[i].count;
				  }
				  for( i=studentCount-1;i>1;i--)
				  {
				  	for(j=0;j<i;j++)
				  	{
					  	if(count[j]<count[j+1])
					  	{
						temp=count[j];
					  	count[j]=count[j+1];
					  	count[j+1]=temp;
					  	
					  	tempId=stuId[j];
					  	stuId[j]=stuId[j+1];
					  	stuId[j+1]=tempId;
					  	}
					  }
					  
				  }
				  for( i=0;i<studentCount;i++)
				  {
				  	for(j=0;j<studentCount;j++)
				  	{
					  	if(stuContainer[i].Id==stuId[j])
					  	{
						  	stuContainer[i].rank=j+1;
						  	break;
						  }
					  }
				  } 
				  
			  }
	 
	  
} 

void studentScoreSave(){
	printf("信息保存\n");
	FILE *fp=NULL;
	fp=fopen(".\\studentInfo","wt+");
	if(NULL==fp)
	{
		printf("打开失败\n");
			return -1;
	} 

	for(int i=0;i<studentCount;i++)
	{
		int tmpRet=0;
		tmpRet=fwrite(&stuContainer[i],sizeof(stuContainer),1,fp);
		if(1 != tmpRet)
		{
			printf("写入不成功"); 
		}
	}
	fclose(fp);
} 

void studentScoreRead(){
		int i=0;
		int tmpRet=0;
		int Index=0;
		int Count=0;
	printf("信息读取\n");
	FILE *fp=NULL;
	fp=fopen(".\\studentInfo","r");
	if(NULL==fp)
	{
		printf("打开失败\n");
		return -1;
	}

	while(!feof(fp)){
		tmpRet=fread(&stuContainer[i++],sizeof(stuContainer),1,fp);
		if(1!=tmpRet)
		{
			break;
		}
		Index++;
		Count++;
	}
	studentIndex=Index;
	studentCount=Count;
	fclose(fp);
} 

void studentDelete(){
printf("*******************删除学生*******************\n");
	printf("\t\t请指定要删除的学生\n");
	int Index=QueryStudent();
	int i; 
	for(i=Index;i<studentCount-1;i++)
	{
		stuContainer[i].Id=stuContainer[i+1].Id;
		strcpy(stuContainer[i].Name,stuContainer[i+1].Name);
		strcpy(stuContainer[i].Major,stuContainer[i+1].Major);
		stuContainer[i].cScore=stuContainer[i+1].cScore;
		stuContainer[i].JavaScore=stuContainer[i+1].JavaScore;
		stuContainer[i].avgScore=stuContainer[i+1].avgScore;
		stuContainer[i].count=stuContainer[i+1].count;
		stuContainer[i].rank=stuContainer[i+1].rank;			
	}
	studentIndex--;
	studentCount--;
	printf("删除完成\n");
}
void HealthReport()
	{
	printf("*******************健康上报*******************\n");
	printf("\t\t请输入你的信息\n");
	int m=0;
	int answer;
do{
	printf("请输入你的学号\n"); 
	scanf("%d",&Health[k].Id); 
	printf("请输入你的地址\n");
	scanf("%s",&Health[k].address);  
	printf("请输入你的体温\n");
	scanf("%f",&Health[k].temperature);
	m++;
	printf("\t\t第%d次上报 已完成\n",m);


	printf("是否继续上报 输入1或2(1.yes/2.no)\n");
	scanf("%d",&answer);
	if(answer==1)
	{
		k++;
	}
}while(answer==1);
	FILE *fp=NULL;
	fp=fopen(".\\health","wt+");
	if(NULL==fp)
	{
		printf("打开失败\n");
			return -1;
	} 

	for(int i=0;i<k;i++)
	{
		int tmpRet=0;
		tmpRet=fwrite(&Health[i],sizeof(Health),1,fp);
		if(1 != tmpRet)
		{
			printf("写入不成功"); 
		}
	}
	fclose(fp);
	printf("信息保存成功\n");
}
void QueryHealth()
{
			int i=0;
			int tmpRet=0;
		
		printf("信息读取\n");
		FILE *fp=NULL;
		fp=fopen(".\\Health","r");
		if(NULL==fp)
		{
			printf("打开失败\n");
			return -1;
		}
	
		while(!feof(fp)){
			tmpRet=fread(&Health[i++],sizeof(Health),1,fp);
			if(1!=tmpRet)
			{
				break;
			}
		
		}
	
		fclose(fp);
		printf("学号\t地址\t体温\n");
		for(int j=0;j<k+1;j++) 
		{
			printf("%ld\t",Health[j].Id);
			printf("%s\t",Health[j].address);
			printf("%.1f\t\n",Health[j].temperature);
		}
			
}

