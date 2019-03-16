#include <iostream>

struct Node {
  int endPoint;
  Node *next;

  Node() { next = NULL; }
  Node(int &x) {
    endPoint = x;
    next = NULL;
  }
};

template <class Record>
struct Vertex {
  Record data;
  Node *next;
  Vertex() { next = NULL; }
  Vertex(Record &data) { this->data = data; }

  Vertex &operator=(const Vertex &origin) {
    this->data = origin.data;
    this->next = origin.next;
    return *this;
  }
};
template <class Record>
class Digraph {
 public:
  // constructors;
  Digraph(int &);

  // accessor functions;

  // mutator functions;

  // Traversal;
  void dfs(void (*visit)(const Vertex<Record> *&nodes));
  void bfs(void (*visit)(const Vertex<Record> *&nodes));
  // Shortest_Path
  void Dijkstra(int source);
  void Bellman_Ford();
  void SPFA();

  // spanning Tree
  prim();
  Kruscal();

  // destructors;
  ~Digraph();

 private:
  Vertex<Record> *graph;
  int count;
  // auxiliary functions
  void traversal(int, bool[], void (*visit)(const Vertex<Record> *&nodes));
};

template <class Record>
void Digraph<Record>::dfs(void (*visit)(const Vertex<Record> *&nodes)) {
  bool visited[count] = {0};
  for (int i = 0; i < cout; i++) {
    if (!visited[i])
      traversal(i, visited, void (*visit)(const Vertex<Record> *&nodes));
  }
}

template <class Record>
void Digraph<Record>::traversal(int current, bool visited[],
                                void (*visit)(const Vertex<Record> *&nodes)) {
  visited[current] = true;
  visit[graph[i]];
}