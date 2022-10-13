// C++ implementation of SPFA

#include <bits/stdc++.h>
using namespace std;

// Graph is stored as vector of vector of pairs
// first element of pair store vertex
// second element of pair store weight
vector<vector<pair<int, int> >> graph;

// Function to add edges in the graph
// connecting a pair of vertex(frm) and weight
// to another vertex(to) in graph
void addEdge(int frm, int to, int weight)
{

	graph[frm].push_back({ to, weight });
}

// Function to print shortest distance from source
void print_distance(int d[], int V)
{
	cout << "Vertex \t\t Distance"
		<< " from source" << endl;

	for (int i = 1; i <= V; i++) {
		cout << i << "			 " << d[i] << '\n';
	}
}

// Function to compute the SPF algorithm
void shortestPathFaster(int S, int V)
{
	// Create array d to store shortest distance
	int d[V + 1];

	// Boolean array to check if vertex
	// is present in queue or not
	bool inQueue[V + 1] = { false };

	// Initialize the distance from source to
	// other vertex as INT_MAX(infinite)
	for (int i = 0; i <= V; i++) {
		d[i] = INT_MAX;
	}
	d[S] = 0;

	queue<int> q;
	q.push(S);
	inQueue[S] = true;

	while (!q.empty()) {

		// Take the front vertex from Queue
		int u = q.front();
		q.pop();
		inQueue[u] = false;

		// Relaxing all the adjacent edges of
		// vertex taken from the Queue
		for (int i = 0; i < graph[u].size(); i++) {

			int v = graph[u][i].first;
			int weight = graph[u][i].second;

			if (d[v] > d[u] + weight) {
				d[v] = d[u] + weight;

				// Check if vertex v is in Queue or not
				// if not then push it into the Queue
				if (!inQueue[v]) {
					q.push(v);
					inQueue[v] = true;
				}
			}
		}
	}

	// Print the result
	print_distance(d, V);
}

// Driver code
int main()
{
	int V = 5;
	int S = 1;

	graph = vector<vector<pair<int,int>>> (V+1);
	// Connect vertex a to b with weight w
	// addEdge(a, b, w)

	addEdge(1, 2, 1);
	addEdge(2, 3, 7);
	addEdge(2, 4, -2);
	addEdge(1, 3, 8);
	addEdge(1, 4, 9);
	addEdge(3, 4, 3);
	addEdge(2, 5, 3);
	addEdge(4, 5, -3);

	// Calling shortestPathFaster function
	shortestPathFaster(S, V);

	return 0;
}
