#include <iostream>
 
int main()
{
    int i;
    long int sum = 0;
    long long int pro = 1;
    for (i = 1; i < 11;i++) {
        sum += i;
        pro = pro * sum;
    }
    std::cout << pro;
}
