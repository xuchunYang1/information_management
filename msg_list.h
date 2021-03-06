#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct employee_info
{
	char name[20];
	int age;
	char sex[10];
	char phone[11];
	struct employee_info *next;
}employee_info_t;	

employee_info_t *creat_node(char *name, int age, char *sex, char *phone);  //创建员工结点

void free_node(employee_info_t *p);

void insert_node(employee_info_t *p);  //头插法插入链表
 
void traverse();  //遍历链表

employee_info_t *find_node(char *name);  //查找某个结点

int delete_node(char *name);  //删除某个结点

