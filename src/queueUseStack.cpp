#include <iostream>
#include "stack.h"

class queue
{
public:
	queue() {};
	~queue() {};
	void push(struct node t) {
		input.push(t);
	};
	struct node pop() {
		if(output.isEmpty()) {
			while (!input.isEmpty())
				output.push(input.pop());
		}
		return output.pop();
	};
	bool isEmpty() {
		if (input.isEmpty() && output.isEmpty())
			return true;
		else
			return false;
	};
	size_t size() {
		return input.size() + output.size();
	};

private:
	stack input;
	stack output;
};

int main()
{
	queue a;
	std::cout << "a.size = " << a.size() << std::endl;
	for (int i = 0; i < 5; i++) {
		struct node temp;
		temp.data = i;
		a.push(temp);
		std::cout << "a.size = " << a.size() << std::endl;
		std::cout << "push.data = " << temp.data << std::endl;
	}
	for (int i = 0; i < 5; i++) {
		struct node temp;
		temp = a.pop();
		std::cout << "a.size = " << a.size() << std::endl;
		std::cout << "pop.data = " << temp.data << std::endl;
	}

	system("pause");
	return 0;
}
