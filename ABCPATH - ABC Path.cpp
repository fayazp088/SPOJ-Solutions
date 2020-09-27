#include<bits/stdc++.h>
using namespace std;
int n, m;

int dist[55][55];
char arr[55][55];
int mx = -1;

//L, R, U, D, LUD, LDD, RUD, RDD
int dist_x[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dist_y[] = {-1, 1, 0, 0, -1, -1, 1, 1};

bool is_valid(int i, int j){
	return i >= 0 and i < n and j >= 0 and j < m;
}

void find_path(int i, int j){
	if(!is_valid(i, j)) return;
	for(int k = 0; k < 8; k++){
		int x = dist_x[k] + i;
		int y = dist_y[k] + j;
		if(is_valid(x, y) and dist[x][y] == -1){
		if(arr[x][y] == (arr[i][j] + 1)){
			dist[x][y] = dist[i][j] + 1;
			mx = max(dist[x][y], mx);
			find_path(x, y);
			}
		}
	}
}


int main(){

	int Test_case = 1;

	while(cin >> n >> m and n and m){
		mx = -1;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				cin >> arr[i][j];

		memset(dist, -1, sizeof(dist));

		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				if(arr[i][j] == 'A'){
					dist[i][j] = 1;
					mx = max(mx, 1);
					find_path(i, j);
				}
			}
		}



		if(mx == -1) mx = 0;

		cout << "Case " << Test_case << ": " << mx << endl;
		Test_case++;
	}
	return 0;
}

