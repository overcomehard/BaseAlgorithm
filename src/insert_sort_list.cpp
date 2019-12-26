#include <iostream>
#include <stdlib.h>
#include <time.h>

// 链表(单链表)实现方式
// 该实现中注意要保证原有顺序的稳定性
typedef struct node
{
    int data;
    struct node *next;
}listNode;

void insert_sort(listNode *array)
{
    // 假设带头结点
    listNode *p = array;
    while(p->next != NULL)
    {
        listNode *q = array;
        while(q != p && q->next->data <= p->next->data)  // "<=" 才能保证顺序的稳定性
            q = q->next;
        if (q != p)
        {
            listNode *temp = p->next->next;
            p->next->next = q->next;
            q->next = p->next;
            p->next = temp;
            continue;
        }
        p = p->next;
    }
}

void creat_list(listNode *array, int n)
{
    listNode *p = array;
    for(int i = 0; i < n; i++)
    {
        listNode *temp = (listNode *)malloc(sizeof(listNode));
        temp->data = rand() % 100;
        temp->next = NULL;
        p->next = temp;
        p = p->next;
    }
}

void print_list(listNode *array)
{
    listNode *p = array->next;
    std::cout << "array: ";
    while(p != NULL)
    {
        std::cout << p->data << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

int main()
{
	listNode *array = (listNode *)malloc(sizeof(listNode));

	srand((int)time(NULL));
	creat_list(array, 10);

	std::cout << "排序前: " << std::endl;
	print_list(array);

	insert_sort(array);

	std::cout << "排序后: " << std::endl;
	print_list(array);

	//getchar();
	return 0;
}
