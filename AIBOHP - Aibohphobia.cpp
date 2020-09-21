#include<bits/stdc++.h>
#define int long long int
using namespace std;


int32_t main(){
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		string p = s;
		int n = s.size();

		int dp[n + 1][n + 1];

		memset(dp, 0, sizeof(dp));

		reverse(p.begin(), p.end());

		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; ++j){
				if(s[i - 1] == p[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
				else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}



		int cnt = dp[n][n];

		cout << n - cnt << endl;
	}
	return 0;
}

