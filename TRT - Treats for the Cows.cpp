#include<bits/stdc++.h>
using namespace std;
int dp[2005][2005];
int arr[2005];


int cows(int x, int y, int year){
	if(x > y) return 0;
	if(dp[x][y] != -1) return dp[x][y];

	return dp[x][y] = max(cows(x + 1, y, year + 1) + year * arr[x], cows(x, y - 1, year + 1) + arr[y] * year);
}

int main(){
	int n; cin >> n;
	memset(dp, -1, sizeof dp);

	for(int i = 0; i < n; ++i) cin >> arr[i];

	cout << cows(0, n - 1, 1) << endl;
	return 0;
}

