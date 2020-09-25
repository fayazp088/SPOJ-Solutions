#include<bits/stdc++.h>
using namespace std;

int dist(int i, int j, int ii, int jj){
	return abs(i - ii) + abs(j - jj);
}

int main(){

	int t; cin >> t;
	while(t--){
		int n, m; cin >> n >> m;
		char arr[n + 1][m + 1];

		vector<pair<int, int>> vec;

		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				cin >> arr[i][j];
				if(arr[i][j] == '1') vec.push_back({i, j});
			}
		}

		int ans[n + 1][m + 1];

		memset(ans, 0, sizeof(ans));

		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j){
				if(arr[i][j] == '0'){
					int mn = INT_MAX;
					for(auto it : vec){
						int ii = it.first;
						int jj = it.second;
						mn = min(dist(i, j, ii, jj), mn);
					}
					ans[i][j] = mn;
				}
			}

		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				cout << ans[i][j] << ' ';
			}
			cout << endl;
		}
	}
	return 0;
}

