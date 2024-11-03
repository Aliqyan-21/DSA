#include <iostream>
#include <unordered_map>
#include <vector>

void print_graph(const std::unordered_map<int, std::vector<int>> &al) {
  for (const auto &a : al) {
    std::cout << a.first << " -> ";
    for (const auto &i : a.second)
      std::cout << i << " ";
    std::cout << std::endl;
  }
}

int main(void) {
  std::vector<std::vector<int>> edgelist = {
      {1, 2}, {2, 3}, {3, 4}, {4, 2}, {1, 3}};

  std::unordered_map<int, std::vector<int>> adj_list;

  for (const auto e : edgelist) {
    int a = e[0], b = e[1];

    // undirected
    adj_list[a].push_back(b);
    adj_list[b].push_back(a);
  }

  print_graph(adj_list);

  return 0;
}
