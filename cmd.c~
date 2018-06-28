#include "cmd.h"
#include "msg_list.h"
#include "process.h"

void admin_mode(int mode_select)
{
	int flag = 1;
	int usr_select = 0;
	
	CLEAR;
	while (flag)
	{
		PRINT_ADMIN_INTERFACE;
		printf("请输入命令号： ");
		scanf("%d", &usr_select);
		switch (usr_select)
		{
			case 1: 
					entry_data_toList(); //增加信息到链表
					break; 
			case 2: 
					delete_single(); //从链表删除某个人的信息
					break;
			case 3: 
					modify_single(); //从链表修改某个人的信息
					break;
			case 4: 
					search_all(); //从链表查看所有信息
					break;                 
			case 5: 
					save_list_toFile();  //保存链表到文件，并退出
					//flag = 0;
					printf("---已退出---\n"); 
					exit(0);
					break;          
			default: 
					return;
		}			
	}	
}

void usr_mode(int mode_select)
{	
	int flag = 1;
	int usr_select = 0;
	
	CLEAR;	
	while (flag)
	{	
		PRINT_USR_INTERFACE;
		printf("请输入命令号： ");
		scanf("%d", &usr_select);
		switch (usr_select)
		{
			case 1: 
					search_single(); // 查看某个人信息
					break; 
			case 2: 
					save_list_toFile();  //保存链表到文件，并退出
					//flag = 0;
					printf("---已退出---\n"); 
					exit(0);
					break;//保存，退出
			default: break;
		}
	}	
}

int usr_operation()
{	
	int exit_flag = 1;
	int mode_select = 0;
	
	CLEAR;                    //清屏并打印用户界面
	PRINT_LOGIN_INTERFACE;
	while (exit_flag)
	{		
		printf("请输入命令号： ");
		scanf("%d", &mode_select);   //选择进入管理员或者普通用户模式
		if (mode_select == 1)        //管理员模式
		{
			admin_mode(mode_select);
			//exit_flag = 0;			
		}
		else if (mode_select == 2)     //普通用户模式
		{
			usr_mode(mode_select);
			exit_flag = 0;			
		}
		else if (mode_select == 3)
		{
			break;
		}
		else
		{
			printf("输入不正确，请重新输入！！！\n");
		}
	}
	return 0;
}



