#include <stdlib.h>
#include <iostream>


void merge(int *source_arr, int *temp_arr, int start, int middle, int end)
{
	int i = start, j = middle + 1, k = start;
	// 每次选择较小的元素放入辅助空间末尾
	while (i <= middle && j <= end)
	{
		if (source_arr[i] > source_arr[j])
			temp_arr[k++] = source_arr[j++];
		else
			temp_arr[k++] = source_arr[i++];
	}
	// 如果前半部分还有剩余
	while (i <= middle)
		temp_arr[k++] = source_arr[i++];
	// 如果后半部分还有剩余
	while (j <= end)
		temp_arr[k++] = source_arr[j++];
	for (i = start; i <= end; i++)
		source_arr[i] = temp_arr[i];
}

void merge_sort(int *source_arr, int *temp_arr, int start, int end)
{
	if (start >= end)
		return;

	int middle = start + (end - start) / 2;
	// 对数组前半部分进行排序
	merge_sort(source_arr, temp_arr, start, middle);
	// 对数组后半部分进行排序
	merge_sort(source_arr, temp_arr, middle + 1, end);
	merge(source_arr, temp_arr, start, middle, end);
}

void merge_sort(int *source_arr, int start, int end)
{
	int *temp_arr;
	// 创建辅助空间
	temp_arr = (int*)malloc((end - start + 1) * sizeof(int));
	merge_sort(source_arr, temp_arr, start, end);
	// 释放辅助空间
	free(temp_arr);
}

int main()
{
	int a[8] = { 50, 10, 20, 30, 70, 40, 80, 60 };

	std::cout << "排序前: ";
	for (int i = 0; i<8; i++)
		std::cout << a[i] << ",";
	std::cout << std::endl;

	merge_sort(a, 0, 7);
	std::cout << "排序后: ";
	for (int i = 0; i<8; i++)
		std::cout << a[i] << ",";
	std::cout << std::endl;

	getchar();
	return 0;
}