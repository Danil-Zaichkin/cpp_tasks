#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main()
{
    string a, b;
    cin >> a >> b;
    int minLen = (int)a.size() + (int)b.size();
    for(int bPos=-(int)b.size(); bPos <= (int)a.size(); ++bPos)
    {
        int first = min(bPos, 0);
        int last = max(bPos + (int)b.size() - 1, (int)a.size() - 1);
        bool flag = true;
        for(int i=first; i<=last; ++i)
        {
            int aVal;
            if (0 <= i && i < (int)a.size())
                aVal = a[i] - '0';
            else
                aVal = 1;
            int bVal;
            if (bPos <= i && i < bPos + (int)b.size())
                bVal = b[i - bPos] - '0';
            else
                bVal = 1;
            if(aVal + bVal > 3)
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            int len = last - first + 1;
            if (len < minLen)
                minLen = len;
        }
    }
    cout << minLen;
    return 0;
}