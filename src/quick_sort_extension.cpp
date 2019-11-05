#include <iostream>

#define N 15

// 为了满足附加题的要求, 对原快排代码进行改写
void quick_sort(int *array, int left, int right, bool(*compare)(int, int, bool))
{
    if (left >= right)  //结速条件
        return;

    int i = left;
    int j = right;
    int key = array[left];

    while (i < j)
    {
        // 确保右边的都大于key
        while (i < j && compare(key, array[j], true))
            j--;
        array[i] = array[j];

        // 确保左边的都小于key
        while (i < j && compare(key, array[i], false))
            i++;
        array[j] = array[i];
    }

    array[i] = key;
    quick_sort(array, left, i - 1, compare);
    quick_sort(array, i + 1, right, compare);
}

// 升序排序
bool cmp_ascend(int v1, int v2, bool key)
{
    if (key)
        return v1 <= v2;
    else
        return v1 >= v2;
}

// 降序排序
bool cmp_descend(int v1, int v2, bool key)
{
    if (key)
        return v1 >= v2;
    else
        return v1 <= v2;
}

// 附加题规则排序
bool cmp(int v1, int v2, bool key)
{
    if (key)
        if ((v1 + v2) % 2 == 0)
            if (v1 % 2 == 0)
                return v1 >= v2;
            else
                return v1 <= v2;
        else
            if (v1 % 2 == 0)
                return false;
            else
                return true;
    else
        if ((v1 + v2) % 2 == 0)
            if (v1 % 2 == 0)
                return v1 <= v2;
            else
                return v1 >= v2;
        else
            if (v1 % 2 == 0)
                return true;
            else
                return false;
}

// 思路1
void split_odd_even(int *array, int left, int right)
{
    int i = left;
    int j = right;
    while (i < j)
    {
        while (i < j && (array[j] % 2 == 0))
            j--;
        while (i < j && (array[i] % 2 != 0))
            i++;
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    quick_sort(array, 0, i, cmp_ascend);
    quick_sort(array, i+1, right, cmp_descend);
}

int main()
{
    int array[N];

    srand(0);
    for (int i = 0; i < N; i++)
        array[i] = rand();

    std::cout << "排序前: ";
    for (int i = 0; i < N; i++)
        std::cout << array[i] << ", ";
    std::cout << std::endl;

    // 思路1
    // split_odd_even(array, 0, N);

    // 思路2
    quick_sort(array, 0, N, cmp);

    std::cout << "排序后: ";
    for (int i = 0; i < N; i++)
        std::cout << array[i] << ", ";
    std::cout << std::endl;

    getchar();
    return 0;
}

