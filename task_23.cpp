#include <iostream>
 
int main()
{
    int i;
    int sum = 0;
    for (i = 0; i < 10;i++) {
        sum += pow(2, i);
    }
    std::cout << sum;
}
