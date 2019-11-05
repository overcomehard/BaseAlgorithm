#include <iostream>
#include <cmath>

void print_circle(int radius)
{
    for (int i = 0; i <= 2 * radius; i++)
    {
        for (int j = 0; j <= 2 * radius; j++)
            if (abs(sqrt((i - radius)*(i - radius) + (j - radius)*(j - radius)) - radius) < 0.5)
                std::cout << "*";
            else
                std::cout << " ";
        std::cout << std::endl;
    }
}

int main()
{
    int radius = 10;
    print_circle(10);

    getchar();
    return 0;
}
