#include<bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		string a, b; cin >> a >> b;


		int n = a.size();
		int m = b.size();

		vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));

		for(int i = 0; i < m; ++i) dp[0][i] = i;
		for(int i = 0; i < n; ++i) dp[i][0] = i;

		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= m; ++j){
				if(a[i - 1] == b[j - 1]){
					dp[i][j] = dp[i - 1][j - 1];
				}else dp[i][j] = 1 + min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
			}
		}

		cout << dp[n][m] << endl;
	}
	return 0;
}

