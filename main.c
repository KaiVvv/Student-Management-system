#include <stdio.h>
#include <stdlib.h>
#include "mainMenu.h"
#include "login.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void welcome(){
	printf("**********************************************\n");
	printf("\n\t欢迎进入学生信息管理系统\n\n");
}

int main() {
	welcome(); 
	int ret;
	ret=login();
	while(ret)
	{welcome();
	mainMenu(ret);
	break;
	}
	
	return 0;
}
