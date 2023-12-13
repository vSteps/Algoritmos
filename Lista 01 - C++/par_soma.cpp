#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    int n, s;
    cin >> n >> s;

    unordered_set<int> nums;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (nums.find(s - num) != nums.end()) {
            cout << "YES" << endl;
            return 0;
        }

        nums.insert(num);
    }

    cout << "NO" << endl;
    return 0;
}
