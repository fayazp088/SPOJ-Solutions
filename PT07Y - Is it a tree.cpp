#include <bits/stdc++.h>
#define int long long int
#define endl "\n"
#define pb push_back
#define vi vector<int>
#define f(i, j, n) for(int i = j; i < n; ++i)
#define fe(i, j, n) for(int i = j; i <= n; ++i)
#define watch(x) cout << #x << " is " << x << endl

using namespace std;
bool check = 0; //just a flag to keep track if a graph contain cycle or not and even used for checking connectivity

vector<int> G[1005]; //For implementing graph
bool visited[1005]; // Visited array
int par[1005]; //Parent Array

//Checking for cycles using BFS

void isCyclic(int src){
	queue<int> q;
	q.push(src);

	memset(visited, 0, sizeof(visited));
	memset(par, 0, sizeof(par));


	visited[src] = true;
	par[src] = src;

	while(!q.empty()){

		int node = q.front();
		q.pop();

		for(auto child : G[node]){
			if(!visited[child]){  //If the node is not visited
				visited[child] = true; //we mark the node as visited
				par[child] = node;  //assigning the node its parent
				
				q.push(child); //pushing the node into a queue, a simple data structure use for implementing BFS algorithm
			}else if(visited[child] and child != par[node]){
				check = 1;  // if the node is already visited and the node is not the parent of the visiting node then a cycle is formed
				return;
			}
		}
	}
}



void test(){
	int n, m; cin >> n >> m;

	int u, v;
	f(i, 0, m){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	check = 0;

	isCyclic(1);

	for(int i = 1; i <= n; ++i)
		if(!visited[i]){
			check = 1;
			break;
		}

	if(check) cout << "NO\n";
	else cout << "YES\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//int t; cin >> t;
	//while(t--)
	test();
	return 0;
}

