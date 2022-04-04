class unionFind{

	vector<int>parent;
	vector<int>rank;

	public:
	unionFind(){}

	unionFind(int n){
		rank.resize(n,0);
		parent.resize(n);
		for(int i = 0; i < n; ++i)
			parent[i] = i;
	}

	int find(int x){
		if(parent[x] == x) return x;

		return parent[x] = find(parent[x]);
	}

	void unite(int a,int b){
		int u = find(a);
		int v = find(b);

		if(rank[u] > rank[v])
			parent[v] = u;
		else if(rank[u] < rank[v])
			parent[u] = v;

		else{
			parent[u] = v;
			rank[v]++;
		}
	}
};