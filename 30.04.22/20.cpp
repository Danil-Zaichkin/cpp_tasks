#include <iostream>


using namespace std;

int main() {
    int n;
    cin >> n;

    int ans = 1;
    int cur_num;
    int prev_num;
    scanf("%d", &prev_num);
    bool flag = true;
    int max_len = 0;
    int len = 0;
    for (int i = 0; i < n-1; i++) {
        scanf("%d", &cur_num);
        if ((flag and cur_num > prev_num) or (!flag and cur_num < prev_num)) {
            len++;
            flag = !flag;
        } else {
            max_len = max(max_len, len);
            len = 1;
            if (cur_num != prev_num) {
                flag = cur_num < prev_num;
                len++;
            }
        }
        prev_num = cur_num;
    }

    max_len = max(len, max_len);
    cout << max_len;
    return 0;
}
