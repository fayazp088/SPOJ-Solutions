#include<bits/stdc++.h>
#define int long long int
using namespace std;

const int N = 1e4 + 5;

vector<int> G[N];
vector<int> primes;
int dist[N];


bool isPrime(int n){

	for(int i = 2; i * i <= n; ++i){
		if(n % i == 0) return false;
	}

	return true;
}

void bfs(int src){
	queue<int> q;
	q.push(src);
	dist[src] = 0;

	while(!q.empty()){
		int curr = q.front();
		q.pop();

		for(auto child : G[curr]){
			if(dist[child] == -1){
				dist[child] = dist[curr] + 1;
				q.push(child);
			}
		}
	}
}

bool canChange(int a, int b){
	int cnt = 0;
	while(a > 0){
		if(a % 10 != b % 10) cnt++;
		a /= 10;
		b /= 10;
	}
	return cnt == 1;
}

void buildGraph(){

	for(int i = 1000; i <= 9999; ++i){
		if(isPrime(i))
			primes.push_back(i);
	}

	int n = primes.size();

	for(int i = 0; i < n; ++i){
		for(int j = i + 1; j < n; ++j){
			if(canChange(primes[i], primes[j])){
				G[primes[i]].push_back(primes[j]);
				G[primes[j]].push_back(primes[i]);
			}
		}
	}
}

int32_t main(){

	int t; cin >> t;
	buildGraph();
	while(t--){
		int a, b; cin >> a >> b;

		memset(dist, -1, sizeof(dist));

		bfs(a);

		if(dist[b] == -1) cout << "Impossible" << endl;
		else cout << dist[b] << endl;
	}
	return 0;
}

