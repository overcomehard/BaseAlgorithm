#include <iostream>
#include "queue.h"

class stack
{
public:
    stack() {};
    ~stack() {};
    void push(struct node t) {
        if (output.isEmpty())
            input.push(t);
        else
            output.push(t);
    };
    struct node pop() {
        if(output.isEmpty()) {
            while (input.size() > 1)
                output.push(input.pop());
            return input.pop();
        }
        else {
            while (output.size() > 1)
                input.push(output.pop());
            return output.pop();
        }
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
    queue input;
    queue output;
};

int main()
{
    stack a;
    std::cout << "input stack:" << std::endl;
    for (int i = 0; i < 5; i++) {
        struct node temp;
        temp.data = i;
        a.push(temp);
        std::cout << "\tpush.data = " << temp.data << std::endl;
    }
    std::cout << "output stack:" << std::endl;
    for (int i = 0; i < 5; i++) {
        struct node temp;
        temp = a.pop();
        std::cout << "\tpop.data = " << temp.data << std::endl;
    }

    system("pause");
    return 0;
}
