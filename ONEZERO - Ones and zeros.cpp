#include<bits/stdc++.h>
using namespace std;


string find_multiple(int n){
	if(n == 1) return "1";

	vector<string> dp(n);

	dp[1] = "1";

	queue<int> bfs;

	bfs.push(1);

	while(!bfs.empty()){
		int r = bfs.front();

		bfs.pop();

		if(r == 0) return dp[r];

		for(int digit : {0, 1}){
			int new_r = (10 * r + digit) % n;
			if(dp[new_r].empty()){
				bfs.push(new_r);
				dp[new_r] = dp[r] + to_string(digit);
			}
		}

	}

	return "IMPOSSIBLE";
}


int main(){
	int T; cin >> T;

	while(T--){
		int n; cin >> n;
		cout << find_multiple(n) << endl;
	}

	return 0;
}

