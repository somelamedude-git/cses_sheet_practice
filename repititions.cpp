#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

int main(){
    string s;
    cin>>s;

    ll len = s.size();
    ll left = 0;
    ll ans = 0;

    for(ll right = 0; right<len; right++){
        if(s[left] != s[right]){
            ans = max(ans, right-left);
            left = right;
        }
    }

    ans = max(ans, len-left);

    cout<<ans<<'\n';
}