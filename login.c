#include <stdio.h>
#include <stdlib.h>
#include "GlobeDefine.h"
typedef struct usr{
	int account;
	int password;
}User;
Student CurrentUser;
int login()
{
	User user;
	int select=-1;
	int account;
	int password; 
	while(1){
	printf("************************\n");
	printf("\t\t1 ��½\n");
	printf("\t\t2 ע��\n");
	printf("\t\t3 �޸�����\n");
	printf("\t\t0 �˳�\n");
	printf("��ѡ����Ҫ���еĲ����������Ӧ�����(0~3)\n");
			scanf("%d",&select);
			if(0 > select || select > 3 ){
				printf("���������������������\n");
				continue;
			}else if(0 == select){
				return select;
			}else if(1==select)
			{
				 FILE *fp=NULL;
				 fp=fopen(".\\Account","wt+");
				 if(NULL==fp)
				 {
				 	printf("��ʧ��\n");
					 return -1;
					  
				 }
				 int tmpRet=fwrite(&user,sizeof(User),1,fp);
				 if(1!=tmpRet)
				 {
				 	printf("д�벻�ɹ�\n"); 
				 }
				 fclose(fp);
				 printf("�������˺�\n");
	 			 scanf("%ld",&account);
	 			 printf("����������\n");
	 			 scanf("%s",&password);
	 			 if(account==user.account && password==user.password)
	 			 {
	 			 	CurrentUser.Id=account;
	 			 	system("cls");
				  	return 1;
				  }else
				  {
				  	printf("�û������������!\n");
				  	return -1;
				  }
			}else if(2==select)
			{
			 printf("�������˺�\n");
			 scanf("%ld",&user.account);
			 printf("����������\n");
			 scanf("%s",&user.password);
			 FILE *fp=NULL;
			 fp=fopen(".\\Account","wt+");
			 if(NULL==fp)
			 {
			 	printf("��ʧ��\n");
				 return -1;
				  
			 }
			 int tmpRet=fwrite(&user,sizeof(User),1,fp);
			 if(1!=tmpRet)
			 {
			 	printf("д�벻�ɹ�\n"); 
			 }
			 fclose(fp);
	
			}
			else if(3==select)
			{
				int oldpassword,oldaccount;
				int newpassword;  
				printf("�������˺�\n");
				scanf("%ld",&oldaccount);
				printf("������ԭ����\n");
				scanf("%s",&oldpassword);
				if(oldaccount==user.account && oldpassword==user.password)
				{
					printf("��������Ҫ�޸ĵ�����\n");
					scanf("%s",&newpassword);
					user.password=newpassword;
					printf("�޸ĳɹ�,���µ�½\n");
					FILE *fp=NULL;
					 fp=fopen(".\\Account","wt+");
					 if(NULL==fp)
					 {
					 	printf("��ʧ��\n");
						 return -1; 
					 }
					 int tmpRet=fwrite(&user,sizeof(User),1,fp);
					 if(1!=tmpRet)
					 {
					 	printf("д�벻�ɹ�\n"); 
					 }
					 fclose(fp);
				}
				else
				{
						printf("�����������˺Ŵ���\n");
				} 
			}
	}
} 
