#include <iostream>
int rankTwo(int m, int n);
using namespace std;
 
int main()
{
    int m;
    cout << "Type positive first number" << endl;
    cin >> m;
    cout << rankTwo(m, 1) << endl;
}
 
int rankTwo(int m, int x)
{
    if (m > x)
        return rankTwo(m, x*2);
    if (m < x)
        cout << "NO" << endl;
    if (m == x)
        cout << "YES" << endl;
    return 0;
}
