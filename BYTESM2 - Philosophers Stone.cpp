#include<iostream>
using namespace std;
int row, col;

int main(){
	int t; cin >> t;
	while(t--){
		cin >> row >> col;
		int arr[row + 5][col + 5];

		for(int i =0; i < row; i++)
			for(int j = 0; j < col; j++)
				cin >> arr[i][j];

		int mx = -1;

		for(int i = 1; i < row; ++i){
			mx = -1;
			for(int j = 0; j < col; ++j){

				int ele = arr[i][j];

				if(j == 0){
					arr[i][j] = max(ele + arr[i - 1][j], ele + arr[i - 1][j + 1]);
				}else if(j == col - 1){
					arr[i][j] = max(ele + arr[i - 1][j], ele + arr[i - 1][j - 1]);
				}else{
					arr[i][j] = max(ele + arr[i - 1][j], max(ele + arr[i - 1][j - 1], ele + arr[i - 1][j + 1]));
				}

				mx = max(arr[i][j], mx);
			}
		}
		cout << mx << endl;
	}
	return 0;
}

