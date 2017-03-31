#include "way.h"
#include <math.h>

char* Way(int x, int y) {
  char* way = new char[1000];
  int cx = 0, cy = 0;
  int i = 1;

  while ((cx != x) && (cy != y) && (abs(x - cx) > i) && (abs(y - cy) > i)) {
    if (y > 0) {
      way[i - 1] = 'N';
      cy += i;
      i++;
    } else {
      if (y < 0) {
        way[i - 1] = 'S';
        cy -= i;
        i++;
      }
    }

    if (x > 0) {
      way[i - 1] = 'E';
      cx += i;
      i++;
    } else {
      if (x < 0) {
        way[i - 1] = 'W';
        cx -= i;
        i++;
      }
    }
  }

  if (abs(x - cx) >= i) {
    if (x > 0) {
      cx += i;
      way[i - 1] = 'E';
      i++;
    } else {
      if (x < 0) {
        cx -= i;
        way[i - 1] = 'W';
        i++;
      }
    }
  }

  if (abs(y - cy) >= i) {
    if (y > 0) {
      cy += i;
      way[i - 1] = 'N';
      i++;
    } else {
      if (y < 0) {
        cy -= i;
        way[i - 1] = 'S';
        i++;
      }
    }
  }

  while (cx != x) {
    if (x > 0) {
      cx -= i;
      way[i - 1] = 'W';
      i++;

      cx += i;
      way[i - 1] = 'E';
      i++;
    } else {
      if (x < 0) {
        cx += i;
        way[i - 1] = 'E';
        i++;

        cx -= i;
        way[i - 1] = 'W';
        i++;
     }
    }
  }

  while (cy != y) {
    if (y > 0) {
      cy -= i;
      way[i - 1] = 'S';
      i++;

      cy += i;
      way[i - 1] = 'N';
      i++;
    } else {
      if (y < 0) {
        cy += i;
        way[i - 1] = 'N';
        i++;

        cy -= i;
        way[i - 1] = 'S';
        i++;
      }
    }
  }

  way[i - 1] = 0;
  return way;
}
