#include <iostream>
#include <stdlib.h>
#include <time.h>

// 链表(单链表)实现方式

typedef struct node
{
    int data;
    struct node *next;
}listNode;

listNode* merge(listNode* first, listNode* second)
{
    //合并两个链表, 按从小到大的顺序
    //假定两个链表均不带头节点
    if(first == NULL)
        return second;
    if(second == NULL)
        return first;
    listNode* new_head = (listNode *)malloc(sizeof(listNode));
    if(new_head == NULL)  //分配失败返回空指针
        exit(0);
    listNode* ptr = new_head;
    listNode* p1 = first;
    listNode* p2 = second;
    while(p1 != NULL && p2 != NULL)
    {
        if(p1->data < p2->data)
        {
            ptr->next = p1;
            p1 = p1->next;
        }
        else
        {
            ptr->next = p2;
            p2 = p2->next;
        }
        ptr = ptr->next;
    }
    //合并剩余部分(对于数组进行归并排序, 这部分可通过设置哨兵来省略)
    if(p1 != NULL)
        ptr->next = p1;
    if(p2 != NULL)
        ptr->next = p2;
    return new_head->next;
}

listNode* merge_sort(listNode *array)
{
    // 经过实验, 是否带有头结点, 均可以正常使用
    //递归调用, 首先找到分裂点, 对于链表可以使用快慢指针方法
    if(array == NULL || array->next == NULL)
        return array;
    listNode* fast = array->next;
    listNode* slow = array;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    //此时slow即为中间点, 依次对slow之前的元素和之后的元素递归调用归并排序, 然后进行合并
    listNode* se = slow->next;
    slow->next = NULL;
    listNode* first = merge_sort(array);
    listNode* second = merge_sort(se);
    return merge(first, second);
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
	creat_list(array, 20);

	std::cout << "排序前: " << std::endl;
	print_list(array);

	array->next = merge_sort(array->next);  // 不考虑头结点进行排序
	// array = merge_sort(array);  // 将头结点一起传入进行排序

	std::cout << "排序后: " << std::endl;
	print_list(array);

	//getchar();
	return 0;
}
