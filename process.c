#include "process.h"
#include "msg_list.h"
#include "cmd.h"

extern employee_info_t *head;

void load_file_toList()
{
	int ret = 0;
	employee_info_t *data_read = NULL;
	
	FILE *fp_data_read = fopen(MYFILE, "rb");
	if (!fp_data_read)
	{	
		//char cmd[50];
		//printf("file %s is not exist, now creat it\n", FILE);
		//sprintf(cmd, "touch %s", FILE);
		//system(cmd);
		printf("文件打开失败！！！\n");
		exit(1);
	}
		
	while (!feof(fp_data_read))
	{
		data_read = malloc(sizeof(employee_info_t));
		ret = fread(data_read, sizeof(employee_info_t), 1, fp_data_read);
		//printf("%s\t%d\t%s\t%s\t\n", data_read->name, data_read->age, data_read->sex, data_read->phone);
		if (data_read->age != 0)
		{
			insert_node(data_read);
		}
	}	
	//traverse();	
	fclose(fp_data_read);
}

//增加信息
void entry_data_toList()  
{
	int i = 0;
	int num_info = 0;
	employee_info_t *p = NULL;
	char name[20] = "0";
	int age = 0;
	char sex[10] = "0"; 
	char phone[11] = "0";
	
	printf("你要录入几条信息：");
	scanf("%d", &num_info);
	
	for (i; i < num_info; i++)
	{
		printf("请输入名字：");
		scanf("%s", name);
		printf("请输入年龄：");
		scanf("%d", &age);
		
		p = creat_node(name, age, sex, phone);
		insert_node(p);				
	}	
	//traverse();
}

void delete_single()
{	
	char ch;
	char name[20] = "0";
	int ret = 0;
	
	printf("请输入要删除的名字： ");
	scanf("%s", name);
	ret = delete_node(name);
	if (ret == 0)
	{
		printf("此员工信息已被删除！\n");			
	}
}

void modify_single()
{	
	int ret = 0;
	char name[20] = "0";
	int age = 0;
	char sex[10] = "0";
	char phone[11] = "0";
	employee_info_t *p = NULL;
	
	printf("请输入你要修改的员工名字： ");
	scanf("%s", name);
	
	p = find_node(name);
	if (p != NULL)
	{	
		//printf("此员工信息为：");
		//printf("%s\t%d\t%s\t%s\n", p->name, p->age, p->sex, p->phone);
		PRINT_MODIFY;
		printf("你要修改哪一项？1/2/3\n");
		scanf("%d", &ret);
		switch (ret)
		{
			case 1:
					printf("请输入新的年龄： ");
					scanf("%d", &age);
					p->age = age;
					break;
			case 2: 
					printf("请输入新的性别： ");
					scanf("%s", sex);
					strcpy(p->sex, sex);
					break;
			case 3:
					printf("请输入新的电话： ");
					scanf("%s", phone);
					strcpy(p->phone, phone);
					break;
			default:
					return;
		}
		
	}
	else
	{
		printf("------------------------\n");
		printf("此员工不存在！！！\n");
		printf("退出修改！！！");
		printf("------------------------\n");
	}			
}

void search_all()
{
	traverse();
}

void search_single()
{	
	char name[20] = "0";
	employee_info_t *p = NULL;
	
	printf("请输入要查找的名字： ");
	scanf("%s", name);
	
	p = find_node(name);
	if (p != NULL)
	{	
		printf("此员工信息为：");
		PRINT_USR_ATTB;
		printf("%s\t%d\t%s\t%s\n", p->name, p->age, p->sex, p->phone);

	}
	else
	{
		printf("------------------------\n");
		printf("此员工不存在！！！\n");
		printf("退出查找！！！");
		printf("------------------------\n");
	}		
}

void save_list_toFile()
{	
	int ret = 0;
	employee_info_t *p = head;
	
	FILE *fp_data_write = fopen(MYFILE, "wb");
	if (!fp_data_write)
	{
		printf("文件打开失败！！！\n");
		exit(1);
	}
	
	while (p != NULL)
	{
		ret = fwrite(p , sizeof(employee_info_t), 1, fp_data_write);
		p = p->next;
	}

	fclose(fp_data_write);	
}
