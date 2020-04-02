#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

struct node
{
	struct node *next;
	struct node *front;
	int data;
};

class queue
{
public:
	queue() {};
	~queue() {
		while (tail != NULL) {
			tail = tail->next;
			free(tail->front);
		}
		length = 0;
	};
	void push(struct node t) {
		struct node* temp = (struct node*)malloc(sizeof(struct node));
		temp->data = t.data;
		temp->front = NULL;
		temp->next = NULL;
		if (tail == NULL) {
			head = temp;
			tail = temp;
		}
		else {
			temp->next = tail;
			tail->front = temp;
			tail = temp;
		}
		length++;
	};
	struct node pop() {
		struct node temp;
		temp.data = head->data;
		temp.front = NULL;
		temp.next = NULL;
        if(size() > 1) {
		    head = head->front;
		    free(head->next);
            head->next = NULL;
        }
        else {
            free(head);
            head = NULL;
            tail = NULL;
        }
		length--;
		return temp;
	};
	bool isEmpty() {
		if (tail != NULL)
			return false;
		else
			return true;
	};
	size_t size() {
		return length;
	};
private:
	struct node* head = NULL;  // 指向链表头
	struct node* tail = NULL;  // 指向链表尾
	size_t length = 0;
};

#endif  // QUEUE_H
