#pragma once
#include <stdio.h>
#include <stdlib.h>


#define CLEAR system("clear");

#define PRINT_LOGIN_INTERFACE \
		printf("**************** 员  工  信  息  管  理  系  统 *******************\n");\
		printf("                                                                 \n");\
		printf("                 管 理 员 登 录:   1                                \n"); \
		printf("                 普 通 登 录:      2                                \n"); \
		printf("                 退 出:           3                                \n");\
		printf("                                                                 \n"); 

#define PRINT_ADMIN_INTERFACE \
		printf("*********** 员  工  信  息  管  理  系  统  ************\n");\
		printf("                                                      \n");\
		printf("               增加信息:  1                            \n");\
		printf("               删除信息:  2                             \n");\
		printf("               修改信息:  3                             \n");\
		printf("               查看信息:  4                             \n");	\
		printf("               退出:      5                             \n"); \
		printf("                                                      \n"); 

#define PRINT_USR_INTERFACE \
		printf("*********** 员  工  信  息  管  理  系  统  ************\n");\
		printf("                                                     \n");\
		printf("                  查看信息:  1                         \n");\
		printf("                  退出:      2                         \n");\
		printf("                                                     \n");

#define PRINT_USR_ATTB \
		printf("名字\t\t年龄\t性别\t电话\n");	
		
#define PRINT_MODIFY \
		printf("                                                       \n");\
		printf("                                                       \n");\
		printf("             年龄：1      性别：2      电话：3             \n");\
		printf("                                                        \n");\
		printf("                                                       \n");		
                     
int usr_operation();  //用户操作

void admin_mode(int mode_select);  //管理员模式

void usr_mode(int mode_select);    //用户模式

	
