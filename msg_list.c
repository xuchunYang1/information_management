#include "msg_list.h"
#include "cmd.h"

employee_info_t *head = NULL;

employee_info_t *creat_node(char *name, int age, char *sex, char *phone)
{
	employee_info_t *p = malloc(sizeof(employee_info_t));
	if (p == NULL)
	{
		printf("malloc failed\n");
		exit(1);
	}
	strcpy(p->name, name);
	p->age = age;
	strcpy(p->sex, sex);
	strcpy(p->phone, phone);
	p->next = NULL;
	
	return p;
}

void free_node(employee_info_t *p)
{
	free(p);
	p = NULL;
}

void insert_node(employee_info_t *p)
{
	p->next = head;
	head = p;
}

void traverse()
{
	employee_info_t *p = head;
	PRINT_USR_ATTB;
	while (p != NULL)
	{
		printf("%-12s\t%d\t%s\t%s\n", p->name, p->age, p->sex, p->phone);
		p = p->next;
	}
	printf("\n");
}

employee_info_t *find_node(char *name)
{
	employee_info_t *p = head;
	while (p != NULL)
	{
		if (strcmp(p->name, name) == 0)
		{
			//printf("%s\t%d\t%s\t%s\n", p->name, p->age, p->sex, p->phone);
			return p;
		}
		else
		{
			p = p->next;
		}
	}
	return NULL;
}

int delete_node(char *name)
{
	employee_info_t *p = head;
	employee_info_t *q = NULL;
	
	if (p == NULL)        //判断链表是否为空
	{
		printf("The List is NULL\n");
		return 1;
	}
	
	if (strcmp(p->name, name) == 0)  //第一个结点就是要被删除的
	{
		head = p->next;
		return 0;
	}	
	else
	{
		p = p->next;  //从第二个结点开始遍历
		while (p != NULL)
		{			
			if (p->next == NULL && strcmp(p->name, name) == 0)
			{
				q->next = NULL;
				return 0;
			}
			
			if (p->next != NULL && strcmp(p->name, name) == 0)
			{
				q->next = p->next;
				return 0;					
			}
			
			q = p;			
			p = p->next;						
		}
		
		printf("此员工不存在！！！\n");
	}
}



