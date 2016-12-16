// Program to print Vertex Cover of a given undirected graph
#include<iostream>
#include <list>

#include <string.h>
using namespace std;
const int MAX_ROW = 20;
const int MAX_COL = 20;
const int adjacencyMatrix[MAX_ROW][MAX_COL] =  {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                                {0,0,1,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0},
                                                {0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0},
                                                {0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0},
                                                {0,0,0,0,0,0,1,0,0,1,0,0,0,1,0,0,0,0,1,0},
                                                {0,1,1,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,1},
                                                {0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
                                                {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
                                                {0,0,0,0,0,0,0,1,0,0,1,0,0,0,1,0,0,0,0,1},
                                                {0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                                {0,0,0,0,0,1,0,0,1,0,0,0,1,0,1,0,0,0,0,0},
                                                {0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
                                                {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,0},
                                                {0,0,0,1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0},
                                                {0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1},
                                                {0,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                                {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
                                                {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
                                                {0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
                                                {0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0}};
 
// This class represents a undirected graph using adjacency list 
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;  // Pointer to an array containing adjacency lists
public:
    Graph(int V);  // Constructor
    void addEdge(int v, int w); // function to add an edge to graph
    void printVertexCover();  // prints vertex cover
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to vs list.
    adj[w].push_back(v); // Since the graph is undirected
}
 
// The function to print vertex cover
void Graph::printVertexCover()
{
    // Initialize all vertices as not visited.
    bool visited[V];
    for (int i=0; i<V; i++)
        visited[i] = false;
 
    list<int>::iterator i;
 
    // Consider all edges one by one
    for (int u=0; u<V; u++)
    {
        // An edge is only picked when both visited[u] and visited[v]
        // are false
        if (visited[u] == false)
        {
            // Go through all adjacents of u and pick the first not
            // yet visited vertex (We are basically picking an edge
            // (u, v) from remaining edges.
            for (i= adj[u].begin(); i != adj[u].end(); ++i)
            {
                int v = *i;
                if (visited[v] == false)
                {
                     // Add the vertices (u, v) to the result set.
                     // We make the vertex u and v visited so that
                     // all edges from/to them would be ignored
                     visited[v] = true;
                     visited[u]  = true;
                     break;
                }
            }
        }
    }
 
    // Print the vertex cover
    for (int i=0; i<V; i++)
        if (visited[i])
          cout << i << " ";
    cout << endl;
}
 
// Driver program to test methods of graph class
int main()
{

    bool hasBeenAdded[MAX_ROW];
    memset(hasBeenAdded, false, MAX_ROW);
	//Create a graph based off of a given adjacancy matrix (i.e. friend list)	    
    Graph g(20);
    for ( int r = 0; r < MAX_ROW; r++){
	for ( int c = 0; c < MAX_COL; c++){
		if(adjacencyMatrix[r][c] == 1 && hasBeenAdded[r] == false){
			g.addEdge(r, c);
			hasBeenAdded[r] = true;
		}
	}
    } 
    g.printVertexCover();
 
    return 0;
}
