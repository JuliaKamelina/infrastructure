#include "Heap.h"
#include "DSet.h"
#include "Algs.h"

Mat drowGraph(vector<vector<Node> >g, vector<Node> core) {
  vector<Point> drown(g.size(), Point(-1, -1));
  vector<bool> visited(g.size(), false);

  int lineType = cv::LINE_AA;
  int width = g.size() * 100 + 100;
  Mat image = Mat::zeros(width, width, CV_8UC3);

  Point pt = Point(width / 2, width / 7);

  pt = Point(pt.x, pt.y);
  std::queue<pair<pair<Point, Point>, Node > > q;  //  first.first - точка родителя,
                                                   //  first.second - текущая точка

  q.push(make_pair(make_pair(pt, pt), Node(0, 0, 0)));

  while (!q.empty()) {
    auto v = q.front();
    q.pop();

    Point pt1;
    char const *pchar;
    string s;

    if (drown[v.second.second].x < 0) {
      pt = v.first.second;  //  place to drow
      circle(image, pt, 25, Scalar(1000, 1000, 1000), 1, lineType);

      s = std::to_string(v.second.second);
      pchar = s.c_str();

      pt1 = Point(pt.x - 8, pt.y + 7);
      putText(image, pchar, pt1, cv::FONT_HERSHEY_COMPLEX, 1, Scalar(0, 255, 0), 1, lineType);

      drown[v.second.second] = v.first.second;
    } else {
      pt = drown[v.second.second];
    }

    if ((v.first.first.x != pt.x) || (v.first.first.y != pt.y)) {
      line(image, v.first.first, pt, Scalar(1000, 1000, 1000), 1.5, lineType);

      for (int i = 0; i < static_cast<int>(core.size()); i++) {
        if (core[i] == v.second) {
          line(image, v.first.first, pt, Scalar(150, 0, 150), 1.5, lineType);
          break;
        }
      }

      pt1.x = pt.x + (v.first.first.x - pt.x) / 2;
      pt1.y = pt.y + (v.first.first.y - pt.y) / 2;

      s = std::to_string(v.second.dist);
      pchar = s.c_str();

      putText(image, pchar, pt1, cv::FONT_HERSHEY_COMPLEX_SMALL, 1,
               Scalar(1000, 1000, 1000), 1, lineType);
    }

    int n = static_cast<int>(g[v.second.second].size());  //  для всех потомков v
    for (int i = -n / 2; i < (n + 1) / 2; i++) {
      auto u = g[v.second.second][i + n / 2];

      if (visited[u.second] == false) {
        Point to = Point(pt.x + i * 100, pt.y + 100 - 7);
        q.push(make_pair(make_pair(pt, to), u));
      }
    }
    visited[v.second.second] = true;
  }

  return image;
}

vector<Node> Prim(vector<vector<int> >g) {
  vector<bool> visited(g.size(), false);
  DHeap<Node> h;
  vector<vector<Node> > graph;
  int n = static_cast<int>(g.size());

  for (int i = 0; i < n; i++) {
    vector<Node> gr;
    for (int j = 0; j < n; j++) {
      if (g[i][j] != 0) gr.push_back(Node(g[i][j], i, j));
    }
    graph.push_back(gr);
  }

  vector<Node> core;

  h.insert(Node(0, 0, 0));  //  стартовая вершина
  int vc = 0;

  while (h.getSize() != 0 && vc != n) {
    auto v = h.getMin();
    h.deleteNode(0);

    if (v.first != v.second && visited[v.second] == false) {
      core.push_back(v);
    }

    for (int i = 0; i < static_cast<int>(graph[v.second].size()); i++) {
      if (visited[i] == false) {
      h.insert(graph[v.second][i]);
      }
    }
    visited[v.second] = true;
    vc++;
  }

  Mat im = drowGraph(graph, core);
  imwrite("../PrimGraph.png", im);

  return core;
}


vector<Node>Kruskal(vector<vector<int> >g) {
  vector<Node> core;
  vector<Node> arr;
  vector<vector<Node> > graph(g.size());

  for (int i = 0; i < static_cast<int>(g.size()); i++) {
    int j = 0;
    while (j < static_cast<int>(g[i].size())) {
      if (g[i][j + 1] >= 0) {
        arr.push_back(Node(g[i][j], i, g[i][j + 1]));
        graph[i].push_back(Node(g[i][j], i, g[i][j + 1]));
      }
      j += 2;
    }
  }

  sort(arr.begin(), arr.end());
  DSet s(g.size());

  for (int i = 0; i < static_cast<int>(arr.size()); i++) {  //  кол-во ребер
    int from = arr[i].first;
    int to = arr[i].second;

    if (s.Find(from) != s.Find(to)) {
      core.push_back(arr[i]);
      s.Union(from, to);
    }
  }

  Mat im = drowGraph(graph, core);
  imwrite("../KruskalGraph.png", im);

  return core;
}
