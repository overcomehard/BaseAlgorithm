#include <iostream>


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

	quick_sort(array, 0, 9);

	std::cout << "排序后: ";
	for (int i = 0; i<10; i++)
		std::cout << array[i] << ", ";
	std::cout << std::endl;

	getchar();
	return 0;
}

