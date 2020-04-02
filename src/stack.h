#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

struct node
{
	struct node *next;
	int data;
};

class stack
{
public:
	stack() {};
	~stack() {
		while (head != NULL) {
			struct node* temp = head;
			head = head->next;
			free(temp);
		}
		length = 0;
	};
	void push(struct node t) {
		struct node* temp = (struct node*)malloc(sizeof(struct node));
		temp->data = t.data;
		temp->next = NULL;
		if (head == NULL) {
			head = temp;
		}
		else {
			temp->next = head;
			head = temp;
		}
		length++;
	};
	struct node pop() {
		struct node temp;
		temp.data = head->data;
		temp.next = NULL;
		struct node *temp_;
		temp_ = head;
		head = head->next;
		free(temp_);
		length--;
		return temp;
	};
	bool isEmpty() {
		if (head != NULL)
			return false;
		else
			return true;
	};
	size_t size() {
		return length;
	};
private:
	struct node* head = NULL;  // 指向链表头
	size_t length = 0;
};

#endif  // STACK_H
