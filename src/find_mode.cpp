#include <iostream>
#include <stdlib.h>

#define N 20

void quick_sort(int *array, int left, int right);
void quick_sort(int *array, int n);


int find_mode(int *array, int n)
{
	// 排序
	quick_sort(array, n);

	int key, count = 0;
	for (int start = 0, end = 1; end<n; end++) {
		if (array[end] != array[end - 1]) {
			if (end - start > count) {
				key = array[start];
				count = end - start;
			}
			start = end;
		}
		// 处理末尾数据
		if (end == n - 1 && (end - start + 1 > count))
		{
			key = array[start];
			count = end - start + 1;
		}
	}
	return key;
}

int main()
{
	int arr[N];
	for (int i = 0; i<N; i++)
		arr[i] = rand() % 7 + 1;  // 1~7的随机数

    std::cout << "输入数组为: ";
	for (int i = 0; i < N; i++)
		std::cout << arr[i] << ",";
	std::cout << std::endl;

	// 查找众数
	int key = find_mode(arr, N);
	std::cout << "众数为:" << key << std::endl;

	getchar();
	return 0;
}


void quick_sort(int *array, int left, int right)
{
	if (left >= right)  //结速条件
	{
		return;
	}
	int i = left;
	int j = right;
	int key = array[left];

	while (i < j)
	{
		// 确保右边的都大于key
		while (i < j && key <= array[j])
			j--;
		array[i] = array[j];

		// 确保左边的都小于key
		while (i < j && key >= array[i])
			i++;
		array[j] = array[i];
	}

	array[i] = key;
	quick_sort(array, left, i - 1);
	quick_sort(array, i + 1, right);
}

void quick_sort(int *array, int n)
{
	quick_sort(array, 0, n - 1);
}

