#include <iostream>

/*template <int max_size>
struct Set {
  bool is_element[max_set];
};

template <int max_size>
class Digraph {
  int count;
  Set<max_size> neighbors[max_size];
};
*/

template <int max_size>
class Digraph {
  int count;
  bool adjacency[max_size][max_size];
};