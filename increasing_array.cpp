#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

int main(){
    ll n;
    cin >> n;

    vector<ll> nums(n);
    long long ans = 0;

    for(int i = 0; i < n; i++){
        cin >> nums[i];

        if(i > 0 && nums[i-1] > nums[i]){
            ans += (nums[i-1] - nums[i]);
            nums[i] = nums[i-1];
        }
    }

    cout << ans << '\n';
}