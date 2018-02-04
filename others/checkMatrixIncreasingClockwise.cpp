#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//(x, y, hvh, v, hn, vn, numChecked, prevVal)

bool checkOne(vector<vector<int>> & matrix, int x, int y, bool hORv, int h, int v, int hNext, int vNext, int numToCheck, int prevVal) {
  if(numToCheck == 0) {
    return true;
  }
  // cout<< x << " " << y <<" " << hORv<<" : " << h << " " << v <<" : " << numToCheck<< "  " << prevVal<<endl;
  if(hORv) {
    int diff = h/(abs(h));
    y += diff;
    h -= diff;
    if(h == 0) {
      h = hNext;
      hNext = -(hNext-diff);
      hORv = !hORv;
    }
  } else {
    int diff = v/(abs(v));
    x += diff;
    v -= diff;
    if(v == 0) {
      v = vNext;
      vNext = -(vNext-diff);
      hORv = !hORv;
    }
  }
  if(x >= 0 && y >= 0 && x < matrix.size() && y < matrix[0].size()) {
    if( prevVal > matrix[x][y]) {
      return false;
    } else {
      prevVal = matrix[x][y];
    }
    numToCheck--;
  }
  return checkOne(matrix, x, y, hORv, h, v, hNext, vNext, numToCheck, prevVal);
}

bool checkMatrix(vector<vector<int>> & matrix, int x, int y) {
  int row = matrix.size();
  if(row == 0) {
    return true;
  }
  int col = matrix[0].size();
  if(col == 0) {
    return true;
  }
  return checkOne(matrix, x, y, true, 1, 1, -2, -2, row*col-1, INT_MIN);
  
}

bool checkMatrixIteratively(vector<vector<int>> & matrix, int x, int y) {
  int row = matrix.size();
  if(row == 0) {
    return true;
  }
  int col = matrix[0].size();
  if(col == 0) {
    return true;
  }
  int numToCheck = row * col - 1;
  bool hORv = true;
  int h = 1, v = 1, hNext = -2, vNext = -2, prevVal = INT_MIN;
  while(numToCheck > 0) {
    if(numToCheck == 0) {
      return true;
    }
    // cout<< x << " " << y <<" " << hORv<<" : " << h << " " << v <<" : " << numToCheck<< "  " << prevVal<<endl;
    if(hORv) {
      int diff = h/(abs(h));
      y += diff;
      h -= diff;
      if(h == 0) {
        h = hNext;
        hNext = -(hNext-diff);
        hORv = !hORv;
      }
    } else {
      int diff = v/(abs(v));
      x += diff;
      v -= diff;
      if(v == 0) {
        v = vNext;
        vNext = -(vNext-diff);
        hORv = !hORv;
      }
    }
    if(x >= 0 && y >= 0 && x < matrix.size() && y < matrix[0].size()) {
      if( prevVal > matrix[x][y]) {
        return false;
      } else {
        prevVal = matrix[x][y];
      }
      numToCheck--;
    }
  }
  return true;
}
/*
(x, y, hv, h,  v, hn, vn, numChecked, prevVal)
(0, 1, 0,  1,  1, -2, -2, 0, 3)
(0, 2, 1, -2,  1,  3, -2, 1, 4)
(1, 1, 1, -2,  1,  3, -2, 1, 4)
*/
// To execute C++, please define "int main()"
int main() {
   vector<vector<int>> matrix = {
    {8,  3,  4,  9,  15},
    {7,  6,  5,  10, 16},
    {14, 13, 12, 11, 17},
    {22, 21, 20, 19, 18},
  };
  cout<<checkMatrix(matrix, 0, 1)<<"  finish"<<endl;
  return 0;
}

