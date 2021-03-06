// Radix Sort Algorithm
// Silas XU
// March 11  2019

#include <iostream>
#include <list>
#include <queue>

using namespace std;

template <class Record>
class Sortable_list : public list<Record> {
 public:
  void radix_sort();

 private:
  void rethread(queue<Record> q[]);
};
class Key {
  Key(Record &);
};

class Record {
 public:
  char key_letter(int position) const;
  Record();
  operator Key() const;  //??
};

const int max_chars = 28;
template <class Record>
void Sortable_list<Record>::radix_sort() {
  Record data;
  queue<Record> q[max_chars];
  for (int positiion = key_size - 1; positiion >= 0; position--) {
    while (!this->empty()) {
      data = this->front();
      this->pop_front();
      int queue_number = alphabetic_order(data.key_letter(positiion));
      q[queue_number].append(data);
    }
    rethread(q);
  }
}

