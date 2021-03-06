#include <iostream>
#include <list>
#include <bits/stdc++.h>

using namespace std;

// Graph class represents a directed graph 
// using adjacency list representation 
class Graph
{
    private:
        int V; // No. of vertices of the graph.
        
        // Pointer to an array containing 
        // adjacency lists
        list<int> *adj;

        // Recursive utility function used by DFS
        void DFSUtil(int v, bool visited[]);

        // Recursive utility function used by topoSort
        void topoUtil(int v, bool visited[]);

        stack<int> stack;

    public:
        // Constructor
        Graph(int V);

        // Function to add edge to the graph
        void addEdge(int v, int w);

        // Topological sort of the complete graph
        void topoSort();

        // DFS --> Print complete graph
        void DFS();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::topoUtil(int s, bool visited[])
{
    // Mark the current node as visited and push it into the stack
    visited[s] = true;

    // Recur all the adjacent vertices of the graph from the given source vertex 's'.
    list<int>::iterator i;
    for (i = adj[s].begin(); i != adj[s].end();  ++i)
    {
        if (!visited[*i])
        {
            topoUtil(*i , visited);
        }
    } 
    
    stack.push(s); 
}

void Graph::topoSort()
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    // Call the recursive helper function 
    // to print DFS traversal on each vertex one by one
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            topoUtil(i , visited);
        } 
    }

    while (!stack.empty())
    {
        int vertex = stack.top();
        stack.pop();
        cout << vertex << " ";
        
    }
}

void Graph::DFSUtil(int s, bool visited[])
{
    // Mark the current node as visited and print it
    visited[s] = true;
    cout << s << " ";

    // Recur all the adjacent vertices of the graph from the given source vertex 's'.
    list<int>::iterator i;
    for (i = adj[s].begin(); i != adj[s].end();  ++i)
    {
        if (!visited[*i])
        {
            DFSUtil(*i , visited);
        }
    }  
}

void Graph::DFS()
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    // Call the recursive helper function 
    // to print DFS traversal on each vertex one by one
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            DFSUtil(i , visited);
        }
    }
}

// Driver program to test methods of graph class 
int main() 
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    cout << "Following is the Topological Sort (disconnected graph) "
         << "(complete graph) \n"; 
    g.topoSort();
    cout << endl; 

    cout << "Following is Depth First Traversal (disconnected graph) "
         << "(complete graph) \n"; 
    g.DFS();
  
    return 0; 
}