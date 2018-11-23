// links.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdlib.h>
#include"list.h"

void destory(void *data)
{
	free(data);
}

int _tmain(int argc, _TCHAR* argv[])
{
	ListElmt *e1= new ListElmt();
	ListElmt *e2 = new ListElmt();
	ListElmt *e3= new ListElmt();
	List *list = new List();

	e1->data = (void*)2;
	list_init(list, destory);
	list_ins_next(list, NULL, e1);
	return 0;
}

