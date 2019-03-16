class Edge;
class Vertex {
  int data;
  Edge *first_edge;
  Vertex *next_vertex;
};

class Edge {
  Vertex *end_point;
  Edge *next_edge;
};

class Digraph {
  Vertex *first_vertex;
  int max_size;

 public:
  void depth_first(void (*visit)(Vertex &)) const;
};

void Digraph::depth_first(void (*visit)(Vertex &)) const {
  bool visited[max_size];
  for (int i = 0; i < max_size) {
    visited[i] = 0;
  }
  Vertex *v = first_vertex;
  while (!v) {
    if()
  }
}
