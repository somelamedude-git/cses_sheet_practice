#include <iostream>
#include <vector>
#include <string>

using namespace std;

long long helper(string num1, string num2, int tight1, int tight2, int prevNum, int currPos, int leadingZeros, vector<vector<vector<vector<vector<long long>>>>>& dp) {

    if(currPos == num2.size()) {
        return 1;
    }

    if(dp[currPos][tight1][tight2][prevNum][leadingZeros] != -1)
        return dp[currPos][tight1][tight2][prevNum][leadingZeros];

    int lowerLimit = tight1 ? num1[currPos] - '0' : 0;
    int upperLimit = tight2 ? num2[currPos] - '0' : 9;

    long long ans = 0;

    for(int i = lowerLimit; i <= upperLimit; i++) {
        if(!leadingZeros && i == prevNum)
            continue;

        int nextLeadingZeros = leadingZeros && (i == 0);

        int nextPrevNum;
        if(nextLeadingZeros)
            nextPrevNum = 10;
        else
            nextPrevNum = i;

        int nextTight1 = tight1 && (i == num1[currPos] - '0');
        int nextTight2 = tight2 && (i == num2[currPos] - '0');

        ans += helper(num1, num2, nextTight1, nextTight2, nextPrevNum, currPos + 1, nextLeadingZeros, dp);
    }

    return dp[currPos][tight1][tight2][prevNum][leadingZeros] = ans;
}

int main(){
    long long n1;
    cin>>n1;
    long long n2;
    cin>>n2;
    
    string num1 = to_string(n1);
    string num2 = to_string(n2);
    
    while(num1.size()<num2.size()){
        num1 = '0' + num1;
    }
    
vector<vector<vector<vector<vector<long long>>>>> dp(
    num2.size(),
    vector<vector<vector<vector<long long>>>>(
        2,
        vector<vector<vector<long long>>>(
            2,
            vector<vector<long long>>(
                11,
                vector<long long>(2, -1)
            )
        )
    )
);

    long long ans = helper(num1, num2, 1, 1, 10, 0, 1, dp);
    
    cout<<ans<<'\n';
    
}