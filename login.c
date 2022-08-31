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
	printf("\t\t1 登陆\n");
	printf("\t\t2 注册\n");
	printf("\t\t3 修改密码\n");
	printf("\t\t0 退出\n");
	printf("请选择所要进行的操作，输入对应的序号(0~3)\n");
			scanf("%d",&select);
			if(0 > select || select > 3 ){
				printf("你的输入有误，请重新输入\n");
				continue;
			}else if(0 == select){
				return select;
			}else if(1==select)
			{
				 FILE *fp=NULL;
				 fp=fopen(".\\Account","wt+");
				 if(NULL==fp)
				 {
				 	printf("打开失败\n");
					 return -1;
					  
				 }
				 int tmpRet=fwrite(&user,sizeof(User),1,fp);
				 if(1!=tmpRet)
				 {
				 	printf("写入不成功\n"); 
				 }
				 fclose(fp);
				 printf("请输入账号\n");
	 			 scanf("%ld",&account);
	 			 printf("请输入密码\n");
	 			 scanf("%s",&password);
	 			 if(account==user.account && password==user.password)
	 			 {
	 			 	CurrentUser.Id=account;
	 			 	system("cls");
				  	return 1;
				  }else
				  {
				  	printf("用户名或密码错误!\n");
				  	return -1;
				  }
			}else if(2==select)
			{
			 printf("请输入账号\n");
			 scanf("%ld",&user.account);
			 printf("请输入密码\n");
			 scanf("%s",&user.password);
			 FILE *fp=NULL;
			 fp=fopen(".\\Account","wt+");
			 if(NULL==fp)
			 {
			 	printf("打开失败\n");
				 return -1;
				  
			 }
			 int tmpRet=fwrite(&user,sizeof(User),1,fp);
			 if(1!=tmpRet)
			 {
			 	printf("写入不成功\n"); 
			 }
			 fclose(fp);
	
			}
			else if(3==select)
			{
				int oldpassword,oldaccount;
				int newpassword;  
				printf("请输入账号\n");
				scanf("%ld",&oldaccount);
				printf("请输入原密码\n");
				scanf("%s",&oldpassword);
				if(oldaccount==user.account && oldpassword==user.password)
				{
					printf("请输入你要修改的密码\n");
					scanf("%s",&newpassword);
					user.password=newpassword;
					printf("修改成功,重新登陆\n");
					FILE *fp=NULL;
					 fp=fopen(".\\Account","wt+");
					 if(NULL==fp)
					 {
					 	printf("打开失败\n");
						 return -1; 
					 }
					 int tmpRet=fwrite(&user,sizeof(User),1,fp);
					 if(1!=tmpRet)
					 {
					 	printf("写入不成功\n"); 
					 }
					 fclose(fp);
				}
				else
				{
						printf("输入的密码或账号错误\n");
				} 
			}
	}
} 
