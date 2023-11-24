#include "digraph.hpp"
#include <fstream>
#include <iostream>
#include <list>
#include <vector>

int main() {
  DiGraph G1(5);
  G1.add_edge(1, 2);
  G1.add_edge(2, 3);
  G1.add_edge(3, 4);
  cout << "Edges of digraph G1: " << endl;
  G1.print();

  DiGraph G;
  G.read("digraph2.txt");

  cout << endl;
  // G.print();
  vector<int> path;
  cout << "Shortest directed paths from 1 to 91,...,100 in G2:" << endl;
  for (int w = 91; w <= 100; w++) {
    path = G.path(1, w);
    if (path.size() == 0)
      cout << "No directed path from 1 to " << w << " exists.";
    for (int i = 0; i < static_cast<int>(path.size()); i++)
      cout << path[i] << " ";
    cout << endl;
  }

  return 0;
}
