#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Graph
{
    private:
        int V; // No. of vertices
        list<int> *adj;
        bool *visited;
    
    public:
        // Constructor
        Graph(int V);

        // Destructor
        ~Graph();

        // Function to add edges to the graph
        void addEdge(int v, int w);

        // DFS interative method function
        void DFS(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
    visited = new bool[V];
}

Graph::~Graph()
{
    delete adj;
    delete visited;
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::DFS(int s)
{
    // Mark all vertices as not visited
    for (int i = 0; i < V ; i++)
    {
        visited[i] = false;
    }

    // Create a stack for storing the DFS
    stack<int> stack;

    // Push the current node to the stack
    stack.push(s);

    // Go through all adjaent verties from the given vertex (only if not visited) and push that to the stack
    while (!stack.empty())
    {
        // Pop the stack and print it
        s = stack.top();
        stack.pop();
        
        if (!visited[s])
        {
            cout << s << " ";
            visited[s] = true;   
        }

        for(auto i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                stack.push(*i);
            }
        }
    }
}

// Driver program to test methods of graph class 
int main() 
{ 
    Graph g(5); // Total 5 vertices in graph 
    g.addEdge(1, 0); 
    g.addEdge(0, 2); 
    g.addEdge(2, 1); 
    g.addEdge(0, 3); 
    g.addEdge(1, 4); 
  
    cout << "Following is Depth First Traversal\n"; 
    g.DFS(0); 
  
    return 0; 
} 
