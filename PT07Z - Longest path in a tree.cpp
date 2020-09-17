#include <bits/stdc++.h>
#define int long long int
#define endl "\n"
#define pb push_back
#define vi vector<int>
#define f(i, j, n) for(int i = j; i < n; ++i)
#define fe(i, j, n) for(int i = j; i <= n; ++i)
#define watch(x) cout << #x << " is " << x << endl


using namespace std;
const int N = 1e5 + 5;

vector<int> G[N];
int parent[N];
int dist[N];

void dfs(int src, int par){

	parent[src] = par;

	dist[src] = dist[par] + 1;

	for(auto child : G[src]){
		if(dist[child] == 0)
			dfs(child, src);
	}
}

void test(){
	int n; cin >> n;
	int u, v;
	f(i, 0, n - 1){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	memset(parent, 0, sizeof(parent));
	memset(dist, 0, sizeof(dist));

	dfs(1, 0);

	cout << endl;

	int mx = INT_MIN;
	int nextNode = 1;

	for(int i = 1; i <= n; ++i){
		if(mx < dist[i]){
			mx = dist[i];
			nextNode = i;
		}
	}

	memset(parent, 0, sizeof(parent));
	memset(dist, 0, sizeof(dist));

	dfs(nextNode, 0);


	cout << endl;

	for(auto it : dist) mx = max(mx, it);


	cout << mx - 1<< endl;
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//int t; cin >> t;
	//while(t--)
	test();
	return 0;
}

