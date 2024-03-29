/*************************************************************************
	> File Name: 44.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月12日 星期四 21时46分50秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
using namespace std;

#define MAX_N 1000000
int arr[MAX_N + 5];
int dp[MAX_N + 5];

int main() {
    
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) cin >> arr[i], dp[i] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (arr[j] >= arr[i]) continue;
            dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    
    
    return 0;
}
