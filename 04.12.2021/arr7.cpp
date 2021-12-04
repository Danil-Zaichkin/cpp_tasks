#include<iostream>
using namespace std;
 
int main()
{
    // p - значение, которое нельзя превышать
    __int64 x, radius, p;
    __int64 y = 0, counter = 0;
    cin >> radius;
    x = radius;
    while (y < radius)
    {
        p = radius * radius - y * y;
        while (x * x >= p && x >= 0)
            --x;
        counter += (x + 1);
        y++;
    }
    counter *= 4;
    cout << counter;
}
