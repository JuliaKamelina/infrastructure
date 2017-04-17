#ifndef INCLUDE_PRCL_H_
#define INCLUDE_PRCL_H_

const int N = 10;

bool percolation(int** g);

void unite(int a, int b);
int find(int a);

double minThrows(int** g);

#endif  // INCLUDE_PRCL_H_
