// 题目：输入一个二维数组，其每一行和每一列都是从小到大排序的，再给定一个数，判断这个数在二维数组中是否存在，若存在返回其坐标，若不存在则返回 [-1, -1]
// 测试用例：1. 存在的值，正常输入
//           2. 存在的值，边界输入
//           3. 不存在的值
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

pair<int, int> func(vector<vector<int>> matrix, int target) {
  if (matrix.empty() || matrix[0].empty())
    return make_pair(-1, -1);
  int xLen = matrix.size();
  int yLen = matrix[0].size();
  int x = 0, y = yLen - 1;
  do {
    if (matrix[x][y] == target)
      return make_pair(x, y);
    if (matrix[x][y] > target) {
      y--;
      continue;
    }
    if (matrix[x][y] < target) {
      x++;
      continue;
    }
  } while (x != xLen && y != -1);
  return make_pair(-1, -1);
}


int main(int argc, char **argv) {
  if (argc != 2) {
    cout << "Usage: ./a num" << endl;
    return -1;
  }
  int num = atoi(argv[1]);
  vector<vector<int>> matrix = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
  pair<int, int> ret = func(matrix, num);
  cout << "[" << ret.first << ", " << ret.second << "]" << endl;
  return 0;
}
