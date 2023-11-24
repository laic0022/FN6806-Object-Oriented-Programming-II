#include<fstream>
#include<iostream>
#include<list>
#include<vector>

using namespace std;

class DiGraph {
    int n;
    int m;
    vector<vector<bool>> A;
    vector<vector<int>> out_neighbors;
    vector<vector<int>> in_neighbors;

public:
    DiGraph() : n(0), m(0) {};
    DiGraph(int n);

    ~DiGraph();

    void add_edge(int n, int m);

    void read(const string file);

    int vertices() const;
    int edges() const;

    void print() const;

    vector<int> path(int v, int w) const;
};