#include"digraph.hpp"
#include<fstream>
#include<iostream>
#include<queue>
#include<algorithm>

// Constructor
DiGraph::DiGraph(int n) : n(n), m(0) {
    A.resize(n + 1, vector<bool>(n + 1, false));

    out_neighbors.resize(n + 1);
    in_neighbors.resize(n + 1);
}

// Destructor
DiGraph::~DiGraph() {}

// Add edge
void DiGraph::add_edge(int v, int w) {
    A[v][w] = true;
    out_neighbors[v].push_back(w);
    in_neighbors[w].push_back(v);
    m++;
}

// Read graph from file
void DiGraph::read(const string file) {
    ifstream input(file);

    if (input.is_open()) {
        n = 0;
        m = 0;
        A.clear();
        in_neighbors.clear();
        out_neighbors.clear();

        // Read the number of vertices
        input >> n;

        // Resize data members accordingly
        A.resize(n + 1, vector<bool>(n + 1, false));
        in_neighbors.resize(n + 1);
        out_neighbors.resize(n + 1);

        int v, w;
        while (input >> v >> w) {
            add_edge(v, w);
        }
        
        input.close();
    } else {
        cerr << "Unable to open file: " << file << endl;
    }
}

// Get number of vertices
int DiGraph::vertices() const {
    return n;
}

// Get number of edges
int DiGraph::edges() const {
    return m;
}

// Print all edges to the screan
void DiGraph::print() const {
    for (int v = 1; v <= n; ++v) {
        for (int w : out_neighbors[v]) {
            cout << v << "->" << w << endl;
        }
    }
}

vector<int> DiGraph::path(int v, int w) const {
    
    
    vector<int> predecessor(n + 1, -1);

    queue<int> bfs_queue;
    bfs_queue.push(v);

    vector<bool> visited(n + 1, false);
    visited[v] = true;

    while (!bfs_queue.empty()) {
        int current_vertex = bfs_queue.front();
        bfs_queue.pop();

        for (int neighbor : out_neighbors[current_vertex]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                predecessor[neighbor] = current_vertex;
                bfs_queue.push(neighbor);
            }

            if (neighbor == w) {
                vector<int> shortest_path;
                int backtrack_vertex = w;
                while (backtrack_vertex != -1) {
                    shortest_path.push_back(backtrack_vertex);
                    backtrack_vertex = predecessor[backtrack_vertex];
                }
                reverse(shortest_path.begin(), shortest_path.end());

                return shortest_path;

            }

        }
    } 

    return {};
}