#ifndef INCLUDE_ALGS_H_
#define INCLUDE_ALGS_H_

#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <queue>
#include <string>
#include <stdexcept>
#include <utility>
#include <vector>
#include <algorithm>

using cv::Mat;
using cv::Point;
using cv::Scalar;

using std::string;

struct Node {
  int dist;
  int first;
  int second;

  explicit Node(int _d, int _f, int _s) {
    dist = _d;
    first = _f;
    second = _s;
  }

  bool operator>(const Node &a) {
    return (this->dist > a.dist);
  }

  bool operator<(const Node &a) {
    return (this->dist < a.dist);
  }

  bool operator == (const Node &a) {
    if (((this->first == a.first && this->second == a.second) ||
      (this->second == a.first && this->first == a.second)) && this->dist == a.dist) {
      return true;
    } else {
      return false;
    }
  }
};

using std::sort;
using std::pair;
using std::vector;
using std::make_pair;
using std::logic_error;

cv::Mat drowGraph(vector<vector<Node> >g, vector<Node> core, char *ch);
vector<Node> Prim(vector<vector<int> >g);
vector<Node>Kruskal(vector<vector<int> >g);

#endif  // INCLUDE_ALGS_H_
