#include "DSet.h"

DSet::DSet(int s) {
  size = s;
  count.resize(s);
  parent.resize(s);
  for (int i = 0; i < size; i++) {
    count[i] = 1;
    parent[i] = i;
  }
}

DSet::~DSet() {
  size = 0;
  parent.~vector();
  count.~vector();
}

int DSet::Find(int a) {
  int i = a;
  while (parent[i] != i) {
    i = parent[i];
  }
  return i;
}

void DSet::Union(int a, int b) {
  int i = Find(a);
  int j = Find(b);

  if (count[i] < count[j]) {
    count[j]++;
    parent[i] = j;
  } else {
    count[i]++;
    parent[j] = i;
  }
}
