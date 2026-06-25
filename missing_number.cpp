#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    long long n;
    cin >> n;

    vector<long long> nums;
    unordered_map<long long, long long> mp;

    for (long long i = 0; i < n - 1; i++) {
        long long a;
        cin >> a;
        nums.push_back(a);

        if (a >= 1 && a <= n)
            mp[a]++;
    }

    for (long long i = 1; i <= n; i++) {
        if (mp[i] == 0) {
            cout << i << '\n';
            break;
        }
    }
}