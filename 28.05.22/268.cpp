#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, k;
    string s;

    cin >> n >> k >> s;

    int i, j, count1, count2, temp;
    int sum = 0;
    if (n > 1) {
        for (int a = 0; a < n; ++a) {
            i = a;
            j = a + 1;
            temp = 2;

            count1 = 0;
            count2 = 0;
            ++sum;

            while (i > -1 && j < n) {
                if (s[i] != s[j]) {
                    if (temp % 2 == 1) {
                        ++count1;
                        if (count1 <= k)
                            sum++;
                    } else {
                        ++count2;
                        if (count2 <= k)
                            ++sum;
                    }
                } else
                    sum++;
                if (temp % 2 == 0)
                    i--;
                else
                    j++;
                ++temp;
            }
        }
        cout << sum << endl;
    } else
        cout << 1 << endl;
}