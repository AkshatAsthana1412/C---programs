#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n = 1000; // number of vertices
vector<vector<int>> adj(n);  // adjacency list representation
vector<bool> used(n);
vector<int> d(n), p(n);

void print_path(int v, vector<int> p){
	if (p[v] == -1){
		cout << v << ' ';
		return;
	}
	print_path(p[v], p);
	cout << '\t' << v;
}

void build_adj(int e){
	//Input
	int u,v;
	for (int i = 0; i < e; i++){
		cin >> u >> v;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
}

void bfs(int s){
	//BFS
	queue<int> q;
	q.push(s);
	used[s] = true;
	p[s] = -1;
	while (!q.empty()) {
	    int v = q.front();
	    q.pop();
	    for (int u : adj[v]) {
	        if (!used[u]) {
	            used[u] = true;
	            q.push(u);
	            d[u] = d[v] + 1;
	            p[u] = v;
	        }
	    }
	}
}

int main() {
	// your code goes here
	int s1, s2; // source vertex
	cin >> n >> s1 >> s2;
	
	int e; //no. of edges
	cin >> e;
	
	//Build Graph
	build_adj(e);	
	
	//BFS from s1
	bfs(s1);
	
	//Print Path from s1
	cout << "BFS from s1\n";
	for(int t = 0; t < n; t++){
		print_path(t, p);
		cout << '\n';
	}
	used.assign(used.size(), 0); //set used to default

	//BFS from s2
	bfs(s2);
	cout << "\nBFS from s2\n";

	//Print Path from s2
	for(int t = 0; t < n; t++){
		print_path(t, p);
		cout << '\n';
	}
	
	return 0;
}

/**
 * n is the number of vertices, s1 is the starting vertex for first bfs
 * s2 is starting vertex for second bfs
 * e is the number of edges
 * Input format:
 * n s1 s2
 * e
 * u1 v1
 * u2 v2
 * u3 v3
 * .
 * .
 * ue ve
 **/

// Output format:
// path of each vertex from s1
// .
// .
// .
// path of eatch vertex from s2
// .
// .
// .
