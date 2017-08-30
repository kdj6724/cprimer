// twotemps.cc -- using overloaded template functions
#include <iostream>
template <typename T>
void Swap(T &a, T &b);

template <typename T>
void Swap(T *a, T *b, int n);

void Show(int a[]);
const int Lim = 8;

int main() {
  using namespace std;
  int i = 10, j = 20;
  cout << "i, j = " << i << ", " << j << endl;
  cout << "Using compiler-generated int swapper:" << endl;
  Swap(i, j);
  
  int d1[Lim] = {0,1,2,3,4,5,6,7};
  int d2[Lim] = {7,6,5,4,3,2,1,0};
  cout << "ori" << endl;
  Show(d1);
  Show(d2);
  Swap(d1, d2, Lim);
  cout << "Swapped arrays:\n" << endl;
  Show(d1);
  Show(d2);

  return 0;
}

template <typename T>
void Swap(T &a, T &b) {
  T temp;
  temp = a;
  a = b;
  b = temp;
}

template <typename T>
void Swap(T *a, T *b, int n) {
  for (int i=0; i<n; i++) {
    Swap(a[i], b[i]);
  }
}

void Show(int a[]) {
  using namespace std;
  cout << "Array : " << endl;
  for(int i=0; i<Lim; i++)
    cout << a[i];
  cout << endl;
}

