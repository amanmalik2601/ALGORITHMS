#include<bits/stdc++.h>
using namespace std;

bool isCycle(int src,vector<bool>&vis,vector<int>graph[]){
	queue<pair<int,int>>q;
	q.push({src,-1});

	while(!q.empty()){
		int nde = q.front().first;
		int p = q.front().second;
		q.pop();

		for(int it : graph[nde]){

			if(!vis[it]){
				vis[it] = true;
				q.push({it,nde});
			}
			else if(vis[it] and it != p){
				cout << p << "----->" << it ;
				return true;
			}
			

		}
	}
	return false;
}


void Solver(){

	int n,m;
	cin >> n >> m;
	vector<int>graph[n];

	for(int i = 0; i < m; ++i){
		int a,b;
		cin >> a>> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	bool flag = false;
	vector<bool>vis(n,false);
	for(int i = 0; i < m; ++i){
		if(!vis[i]){
			vis[i] = true;
			if(isCycle(i,vis,graph)){
				flag = true;
				break;
			}
		}
	}

	if(flag)
		cout << "YES";
	else
		cout << "NO";
	cout <<"\n";

}

int main(){

	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solver();

	return 0;
}