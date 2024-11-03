#include <iostream>
#include <vector>

void print_graph(const std::vector<std::vector<int>> &am) {
  for (int i = 1; i < am.size(); i++) {
    std::cout << i << " -> ";
    for (int j = 1; j < am.size(); j++) {
      if (am[i][j] == 1)
        std::cout << j << " ";
    }
    std::cout << std::endl;
  }
}

int main(void) {
  std::vector<std::vector<int>> edgelist = {
      {1, 2}, {2, 3}, {3, 4}, {4, 2}, {1, 3}};

  int n = 5; // ignoring 0

  std::vector<std::vector<int>> adj_matrix(n, std::vector<int>(n, 0));

  for (const auto &e : edgelist) {
    // undirected
    int a = e[0], b = e[1];
    adj_matrix[a][b] = 1;
    adj_matrix[b][a] = 1;
  }

  print_graph(adj_matrix);

  return 0;
}
