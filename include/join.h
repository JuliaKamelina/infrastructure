#ifndef INCLUDE_JOIN_H_
#define INCLUDE_JOIN_H_

#include <vector>
#include <utility>

using std::vector;
using std::pair;

int* join(vector<pair<int, int> > p, vector<int> q);
void unite(int a, int b, int *count, int *parent);
int find(int a, int *parent);
int disjoin(int a, int b, int *count, int *parent);

#endif  // INCLUDE_JOIN_H_
