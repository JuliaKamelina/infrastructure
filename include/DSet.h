#ifndef INCLUDE_DSET_H_
#define INCLUDE_DSET_H_

#include <vector>

using std::vector;

class DSet {
  int size;
  vector<int> parent;
  vector<int> count;

 public:
  explicit DSet(int s);
  ~DSet();
  void Union(int a, int b);
  int Find(int a);
};

#endif  //  INCLUDE_DSET_H_
