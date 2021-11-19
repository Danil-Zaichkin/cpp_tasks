#include <iostream>
int functionAckerman(int m, int n);
using namespace std;
 
int main()
{
 
    int m, n;
    cout << "Type positive first number" << endl;
    cin >> m;
    cout << "Type postive second number" << endl;
    cin >> n;
    cout << functionAckerman(m, n) << endl;
}
 
int functionAckerman(int m, int n)
{
    if (m > 0 && n > 0)
       functionAckerman(m - 1, functionAckerman(m, n - 1));
    if (m > 0 && n == 0)
       functionAckerman(m - 1, 1);
    if (m == 0)
        return n + 1;
}
 
