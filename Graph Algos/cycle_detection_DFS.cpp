#include<bits/stdc++.h>
using namespace std;

bool isCycle(int src,int p,vector<bool>&vis,vector<int>graph[]){
	vis[src] = true;

	for(int it : graph[src]){
		if(!vis[it]){
			if(isCycle(it,src,vis,graph))
				return true;
		}
		else if(p != it) return true;
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
			if(isCycle(i,-1,vis,graph)){
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