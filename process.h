#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MYFILE "info"

void load_file_toList();  //加载数据文件到链表

void entry_data_toList();  //增加信息到链表

void delete_single();  //删除单条信息

void modify_single(); //修改单条信息

void search_all();

void search_single();  //查看单条信息

void save_list_toFile();  //保存链表到文件





