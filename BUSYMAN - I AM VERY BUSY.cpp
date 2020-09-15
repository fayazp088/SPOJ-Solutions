#include<bits/stdc++.h>
#define int long long int
using namespace std;


struct activ{
	int start;
	int end;

	bool operator < (activ& act){
		if(end == act.end) return start < act.start;
		else return end < act.end;
	}

};

int32_t main(){

	int test; cin >> test;

	while(test--){
		int n; cin >> n;
		vector<activ> vec(n);

		for(int i = 0; i < n; ++i){
			cin >> vec[i].start;
			cin >> vec[i].end;
		}

		sort(vec.begin(), vec.end());

		int prev = vec[0].end;
		int cnt = 1;

		for(int i = 1; i < n; ++i){
			if(prev <= vec[i].start){
				cnt++;
				prev = vec[i].end;
			}
		}

		cout << cnt << endl;
	}

	return 0;
}

