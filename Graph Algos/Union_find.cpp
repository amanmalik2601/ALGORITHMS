#include<bits/stdc++.h>
using namespace std;

int findParent(int a,vector<int>&parent){
	if(parent[a] == a)
		return a;

	return parent[a] = findParent(parent[a],parent);
}

void unite(int a,int b,vector<int>&parent,vector<int>&rank){

	int u = findParent(a,parent);
	int v = findParent(b,parent);

	if(rank[u] == rank[v]){
		parent[u] = v;
		rank[v]++;
	}
	if(rank[u] > rank[v])
		parent[v] = u;
	
	else
		parent[u] = v;
}


void Solver(){

	int n;
	cin >> n;

	vector<vector<int>>edges;

	for(int i = 0; i < n; ++i){
		int a,b;
		cin >> a>> b;

		edges.push_back({a,b});
	}

	vector<int>parent(n);

	for(int i = 0; i < n; ++i)
		parent[i] = i;

	vector<int>rank(n,0);

	for(int i = 0; i < n; ++i){
		if(findParent(edges[i][0],parent) != findParent(edges[i][1],parent))
			unite(edges[i][0],edges[i][1],parent,rank);
		else
			cout << edges[i][0] << "  " << edges[i][1] << "\n";
	}


}

int main(){

	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solver();

	return 0;
}