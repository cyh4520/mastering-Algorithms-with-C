// pointer.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<Windows.h>
int(*match)(int key1, int key2);

int mymax(int a, int b)
{
	return a > b ? a : b;
}



//calculate the n!
int func(int n)
{
	if (n == 1) return 1;
	else
	{
		return n*func(n - 1);
	}
}

//tail recursion
int functail(int n, int result=1)
{
	if (n == 1) return result;   //only need to return the last step
	else
	{
		functail(n - 1, n*result);
	}
}

void swap(int *a, int *b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}
void insert(int *a, int lenth)
{
	int j = 0;
	for (int i = 1; i < lenth; i++)
	{
		j = i;
		
		while (j>0 && a[j]<a[j-1])
		{
			swap(&a[j], &a[j - 1]);
			j--;
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	/* 
	match = mymax;   //pointer can also used in the function
	int a = 3, b = 4;
	int c = 0;
	c = match(a, b);
	printf("%d", c);
	system("pause");
	*/

	/*int result = 0;
	result = functail(4);
	printf("%d", result);
	system("pause");*/

	int result = 0;
	int a[] = { 9,3, 1, 4, 2, 7, 8, 6, 5 };
	insert(a, 9);
	for (int i = 0; i < 9; i++)
		printf("%d", a[i]);
	system("pause");
}

