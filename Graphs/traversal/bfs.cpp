#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

void bfs(std::unordered_map<int, std::vector<int>> graph, int n, int source) {
  std::queue<int> q;
  std::vector<bool> visited(n, false);

  q.push(source);
  visited[source] = true;

  while (!q.empty()) {
    int f = q.front();
    std::cout << f << " ";
    q.pop();

    for (const int &i : graph[f]) {
      if (!visited[i]) {
        q.push(i);
        visited[i] = true;
      }
    }
  }
}

int main(void) {
  int n = 5;
  std::vector<std::vector<int>> edgelist = {{0, 1}, {1, 4}, {1, 2}, {2, 3}};

  std::unordered_map<int, std::vector<int>> adj_list;

  for (const auto &e : edgelist) {
    int a = e[0], b = e[1];
    adj_list[a].push_back(b);
    adj_list[b].push_back(a);
  }

  bfs(adj_list, n, 0);

  return 0;
}
