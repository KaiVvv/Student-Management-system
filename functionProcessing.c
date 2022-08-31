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
	printf("������ѧ����Ϣ\n");
	while(1){
		printf("������ѧ��ѧ��\n");
		scanf("%ld",&stuContainer[studentIndex].Id);
		printf("������ѧ������\n");
		scanf("%s",&stuContainer[studentIndex].Name);
		printf("������ѧ��רҵ\n");
		scanf("%s",&stuContainer[studentIndex].Major);
		printf("������ѧ��C�ɼ�\n");
		scanf("%d",&stuContainer[studentIndex].cScore); 
		printf("������ѧ��Java�ɼ�\n");
		scanf("%d",&stuContainer[studentIndex].JavaScore); 
		
		studentIndex++;
		studentCount++;
		
		printf("ѧ����Ϣ��ӳɹ�\n");
		
		printf("�Ƿ�������(yes/no)\n");
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
	printf("*******************����ѧ��*******************\n");
	printf("\t\t1 Id����\n");
	printf("\t\t2 ��������\n");
	printf("**********************************************\n");
	printf("������\n");
	scanf("%d",&answer);
	if(1 == answer){
		printf("������Id\n");
		scanf("%d",&id);
		printf("id:%d\n",id);
		Index = QueryById(id);
		printf("Index:%ld\n",Index);
	}else if(2 == answer){
		printf("����������\n");
		scanf("%s",&name);
		Index = QueryByName(name);
	} else{
		printf("��������\n");
	}
	return Index;
} 
 
void studentScoreInput(){
	int Index = QueryStudent();
	printf("������ѧ��C�ɼ�\n");
	scanf("%d",&stuContainer[Index].cScore); 
	printf("������ѧ��Java�ɼ�\n");
	scanf("%d",&stuContainer[Index].JavaScore); 
} 

void ModifyInfo(int Index,int select){
	switch(select){
		case 1:
			printf("������ѧ��ѧ��\n");
			scanf("%ld",&stuContainer[Index].Id);
			break;
		case 2:
			printf("������ѧ������\n");
			scanf("%s",&stuContainer[Index].Name);
			break;
		case 3:
			printf("������ѧ��רҵ\n");
			scanf("%s",&stuContainer[Index].Major);
			break;
		case 4:
			printf("������ѧ��C�ɼ�\n");
			scanf("%d",&stuContainer[Index].cScore); 
			break;
		case 5:
			printf("������ѧ��Java�ɼ�\n");
			scanf("%d",&stuContainer[Index].JavaScore); 
			break;		 
	}
} 

void studentScoreModify(){
	int select = 0; 
	int Index = QueryStudent();
	while(1){
		printf("************��ѡ��Ҫ�޸ĵ��ֶ�****************\n");
		printf("\t\t1 ѧ��\n");
		printf("\t\t2 ����\n");
		printf("\t\t3 רҵ\n");
		printf("\t\t4 C�ɼ�\n");
		printf("\t\t5 Java�ɼ�\n");
		printf("\t\t0 �˳�\n");
		printf("**********************************************\n");
		printf("��ѡ��(0~5)\n");
		scanf("%d",&select);
		if(0 > select || select > 5 ){
			printf("���������������������\n");
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
		printf("*******************����ѧ��*******************\n");
		printf("\t\t1 Id����\n");
		printf("\t\t2 ��������\n");
		printf("\t\t3 רҵ����\n");
		printf("\t\t4 C�ɼ�����\n");
		printf("\t\t5 Java�ɼ�����\n");
		printf("**********************************************\n");
		printf("������\n");
		scanf("%d",&answer);
		if(1 == answer){
			printf("������Id\n");
			scanf("%d",&id);
			printf("id:%d\n",id);
			Index = QueryById(id);
			printf("Index:%ld\n",Index);
		}else if(2 == answer){
			printf("����������\n");
			scanf("%s",&name);
			Index = QueryByName(name);
		}else if(3 == answer){
			printf("������רҵ\n");
			scanf("%s",&major);
			num = QueryByMajor(major,IndexContainer);
		}else if(4 == answer){
			printf("������C�ɼ�����\n");
			scanf("%d",&CScoredown);
			printf("������C�ɼ�����\n");
			scanf("%d",&CScoreup);
			num = QueryByCScore(CScoredown,CScoreup,IndexContainer);
		}else if(5 == answer){
			printf("������Java�ɼ�\n");
			scanf("%d",&JavaScore);
//			Index = QueryByJavaScore(JavaScore);
		} else{
			printf("��������\n");
		}
	printf("----------------------------------------------------------\n");
	printf("ѧ��\t����\tרҵ\tC�ɼ�\tJava\tƽ����\t�ܷ�\t����\n");
	if(1 == answer||2==answer){
		showStudentInfo(Index);
	} else{
		for(int i=0;i<num;i++){
			showStudentInfo(IndexContainer[i]);
		}
	}
} 

void studentScoreOutput(){
	printf("\t\t\tѧ����Ϣ\n");
	printf("----------------------------------------------------------\n");
	printf("ѧ��\t����\tרҵ\tC�ɼ�\tJava\tƽ����\t�ܷ�\t����\n");
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
	 printf("***********ͳ��***********\n");
	 printf("\t\t1 ͳ���ܷ�\n");
	 printf("\t\t2 ͳ��ƽ����\n");
	 printf("\t\t3 ͳ������\n");
	 printf("*************************\n");
	 printf("������\n");
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
	printf("��Ϣ����\n");
	FILE *fp=NULL;
	fp=fopen(".\\studentInfo","wt+");
	if(NULL==fp)
	{
		printf("��ʧ��\n");
			return -1;
	} 

	for(int i=0;i<studentCount;i++)
	{
		int tmpRet=0;
		tmpRet=fwrite(&stuContainer[i],sizeof(stuContainer),1,fp);
		if(1 != tmpRet)
		{
			printf("д�벻�ɹ�"); 
		}
	}
	fclose(fp);
} 

void studentScoreRead(){
		int i=0;
		int tmpRet=0;
		int Index=0;
		int Count=0;
	printf("��Ϣ��ȡ\n");
	FILE *fp=NULL;
	fp=fopen(".\\studentInfo","r");
	if(NULL==fp)
	{
		printf("��ʧ��\n");
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
printf("*******************ɾ��ѧ��*******************\n");
	printf("\t\t��ָ��Ҫɾ����ѧ��\n");
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
	printf("ɾ�����\n");
}
void HealthReport()
	{
	printf("*******************�����ϱ�*******************\n");
	printf("\t\t�����������Ϣ\n");
	int m=0;
	int answer;
do{
	printf("���������ѧ��\n"); 
	scanf("%d",&Health[k].Id); 
	printf("��������ĵ�ַ\n");
	scanf("%s",&Health[k].address);  
	printf("�������������\n");
	scanf("%f",&Health[k].temperature);
	m++;
	printf("\t\t��%d���ϱ� �����\n",m);


	printf("�Ƿ�����ϱ� ����1��2(1.yes/2.no)\n");
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
		printf("��ʧ��\n");
			return -1;
	} 

	for(int i=0;i<k;i++)
	{
		int tmpRet=0;
		tmpRet=fwrite(&Health[i],sizeof(Health),1,fp);
		if(1 != tmpRet)
		{
			printf("д�벻�ɹ�"); 
		}
	}
	fclose(fp);
	printf("��Ϣ����ɹ�\n");
}
void QueryHealth()
{
			int i=0;
			int tmpRet=0;
		
		printf("��Ϣ��ȡ\n");
		FILE *fp=NULL;
		fp=fopen(".\\Health","r");
		if(NULL==fp)
		{
			printf("��ʧ��\n");
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
		printf("ѧ��\t��ַ\t����\n");
		for(int j=0;j<k+1;j++) 
		{
			printf("%ld\t",Health[j].Id);
			printf("%s\t",Health[j].address);
			printf("%.1f\t\n",Health[j].temperature);
		}
			
}

