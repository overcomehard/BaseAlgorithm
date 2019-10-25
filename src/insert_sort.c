#include <iostream>
#include <stdlib.h>

// 顺序表方式实现
void insert_sort(int *array, int n)
{
	// 为什么从1开始呢?
	for (int i = 1; i < n; ++i)
	{
		// 注意这里的实现, 不是每次都交换两数, 一个小技巧
		// 为了便于理解, 不妨对比一下每次都交换两数的代码, 比较一下计算量, 看看每次都交换时其中的规律
		/*
		for(int j = i; j > 0 && array[j-1] > array[j]; --j)
		{
		int tmp = array[j];
		array[j] = array[j-1];
		array[j-1] = tmp;
		}
		*/
		// 内存循环是倒序的, 可否使用顺序呢?
		// 不可以, 因为这样处理后就变成冒泡排序了
		int tmp = array[i];
		int j;
		for (j = i; j > 0 && array[j - 1] > array[j]; --j)
			array[j] = array[j - 1];
		array[j] = tmp;
	}
}

int main()
{
	int array[10];

	srand(0);
	for (int i = 0; i<10; i++)
		array[i] = rand();

	std::cout << "排序前: ";
	for (int i = 0; i<10; i++)
		std::cout << array[i] << ", ";
	std::cout << std::endl;

	insert_sort(array, 10);

	std::cout << "排序后: ";
	for (int i = 0; i<10; i++)
		std::cout << array[i] << ", ";
	std::cout << std::endl;

	getchar();
	return 0;
}
