#include<bits/stdc++.h>
#define int long long int
using namespace std;

int32_t main(){
	int t; cin >> t;
	int c = 1;
	while(t--){
		int n; cin >> n;

		vector<int> arr(n + 1);
		for(int i = 0; i < n; ++i) cin >> arr[i];

		if(n == 0){
			cout << "Case " << c << ": ";
			cout << 0 << endl;
			c++;
			continue;
		}

		if(n == 1){
			cout << "Case " << c << ": ";
			cout << arr[0] << endl;
			c++;
			continue;
		}

		vector<int> dp(n, 0);

		dp[0] = arr[0];

		dp[1] = max(arr[1], dp[0]);

		for(int i = 2; i < n; ++i){
			dp[i] = max(dp[i - 2] + arr[i], dp[i - 1]);
		}

		cout << "Case " << c << ": ";
		cout << dp[n - 1] << endl;

		c++;
	}
	return 0;
}

