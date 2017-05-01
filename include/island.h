#ifndef INCLUDE_ISLAND_H_
#define INCLUDE_ISLAND_H_

void sinkSet(int **a, const int n, const int m);
void sink(int **a, int n, int m);

void unite(int a, int b, int *count, int *parent);
int find(int a, int *parent);

#endif  // INCLUDE_ISLAND_H_
