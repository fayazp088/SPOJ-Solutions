#include<bits/stdc++.h>
#define hashmap unordered_map<char, Node*>
using namespace std;
bool found = 0;
 
class Node{
	public:
		char data;
		hashmap h;
		bool isTerminal;
	Node(char d){
		data = d;
		isTerminal = false;
	}
};
 
 
class Trie{
	Node* root;
 
	public:
		Trie(){
			root = new Node('/0');
		}
 
	void addWord(string word){
		Node *temp = root;
		for(auto c : word){
			if(temp->h.count(c) == 0){
				Node *child = new Node(c);
				temp->h[c] = child;
				temp = child;
			}else{
				temp = temp->h[c];
				if(temp->isTerminal) found = 1;
			}
		}
	temp->isTerminal = true;
	}
};
 
 
bool comp(string &a, string &b){
	return a.size() < b.size();
}
 
int main(){
	int T; cin >> T;
 
	while(T--){
 
		int n; cin >> n;
		vector<string> numbers(n);
		Trie tie;
		found = 0;
		for(int i = 0; i < n; ++i){
			cin >> numbers[i];
		}
 
		sort(numbers.begin(), numbers.end(), comp);
 
		//for(auto it : numbers) cout << it << ' ';
 
		for(auto num : numbers){
			if(found) break;
			tie.addWord(num);
		}
 
		if(found) cout << "NO";
		else cout << "YES";
		cout << endl;
	}
	return 0;
}
 
