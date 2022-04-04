/*    USING  DFS  */

bool isBipartite(int src,vector<int>graph[],vector<int>&color){

	if(color[src] == -1) color[src] = 1;

	for(int i : graph[src]){
		if(color[i] == -1){
			color[i] = 1 - color[src];
			return isBipartite(i,graph,color);
		}
		else if(color[i] == color[src])
				return false;
		
	}
	return true;

}




/*   USING BFS  */

bool isBipartite(int v,vector<int>graph[]){

	queue<int>q;
	vector<int>color(v,-1);
	q.push(0);
	color[0] = 0;

	while(!q.empty()){
		int  node = q.front();
		q.pop();

		for(int i : graph[node]){
			if(color[i] == -1){
				color[i] = 1-color[node];
				q.push(i);
			}
			else if(color[i] == color[node]) return false;
		}
	} 
	return true;

}