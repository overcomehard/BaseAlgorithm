#include <iostream>
#include <stdlib.h>

#define N 20

void quick_sort(int *array, int left, int right);
void quick_sort(int *array, int n);

/*
// 如果找到返回对应的索引
// 否则返回-1
param:
input:
src: 输入数组, 升序排序
n: 数组大小
x: 待查找元素
output:
index: 待查找元素在数组src中的位置
*/
int binary_search(int *src, int n, int x)
{
    if (n <= 0)
        return -1;
    int start = 0;
    int end = n - 1;
    int mid = (start + end) / 2;
    while (start <= end)
    {
        if (src[mid] == x)
            return mid;
        else if (src[mid] < x) {
            start = mid + 1;
            mid = (start + end) / 2;
        }
        else {
            end = mid - 1;
            mid = (start + end) / 2;
        }
    }
    return -1;
}

int main()
{
    int arr[N];
    for (int i = 0; i<N; i++)
        arr[i] = rand() % 100 + 1;  // 1~100的随机数

    // 对arr排序
    quick_sort(arr, N);

    int key = rand() % 100 + 1;  // 待查找元素
    // 二分查找
    int index = binary_search(arr, N, key);
    std::cout << "输入数组为: ";
    for (int i = 0; i < N; i++)
        std::cout << arr[i] << ",";
    std::cout << std::endl;
    std::cout << "待查找数为:" << key << ", 在数组中的索引为: " << index << std::endl;

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

