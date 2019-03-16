#include <iostream>
using namespace std;

class A {
 public:
  void set(int x) { entry = x; }
  void get() { cout << "A" << entry << endl; }

 private:
  int entry;
};

class B : public A {
 public:
  void setB(int x)

  {
    entryb = x;
  }
  void getB() { cout << "B" << entryb << endl; }

 private:
  int entryb{0};
};

int main() {
  B b;
  b.set(3);
  b.get();
  b.getB();
}