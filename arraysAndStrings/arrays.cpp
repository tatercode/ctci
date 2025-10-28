#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unordered_set>


void print2dArray(const std::vector<std::vector<int>>& array)  {
  for (int i = 0; i < array.size(); ++i) {
    for (int j = 0; j < array[i].size(); ++j) {
      std::cout << array.at(i).at(j) << " ";      
    }
    std::cout << std::endl;
  }
}

void rotateMatrix(std::vector<std::vector<int>>& array) {
  if (array.size() == 0 || array.size() != array.at(0).size()) 
    return;

  int n = array.size();
  for (int layer = 0; layer < n / 2; layer++) {
    int first = layer;
    int last = n - 1 - layer;
    for (int i = first; i < last; ++i) {
      int offset = i - first;
      int top = array[first][i]; // save top

      // 
      array[first][i] = array[last-offset][first];

      array[last-offset][first] = array[last][last-offset];

      array[last][last-offset] = array[i][last];

      array[i][last] = top;
    }
  }
  return;
}


void nullifyRows(std::vector<std::vector<int>>& array, int index) {
  for (int i = 0; i < array.at(0).size(); ++i) {
    array.at(index).at(i) = 0;
  }
}

void nullifyCols(std::vector<std::vector<int>>& array, int index) {
  for (int i = 0; i < array.size(); ++i) {
    array.at(i).at(index) = 0;
  }

}

void zeroMatrix(std::vector<std::vector<int>>& array) {
  if (array.empty() || array[0].empty()) return;

  bool rowHasZero = false;
  bool colHasZero = false;

  // Check if the first row has a zero
  for (int j = 0; j < array[0].size(); ++j) {
    if (array[0][j] == 0) {
      rowHasZero = true;
      break;
    }
  }

  // Check if the first column has a zero
  for (int i = 0; i < array.size(); ++i) {
    if (array[i][0] == 0) {
      colHasZero = true;
      break;
    }
  }

  // Use the first row and column to mark zeros in the rest of the matrix
  for (int i = 1; i < array.size(); ++i) {
    for (int j = 1; j < array[i].size(); ++j) {
      if (array[i][j] == 0) {
        array[i][0] = 0;
        array[0][j] = 0;
      }
    }
  }

  // Nullify rows based on the markers in the first column
  for (int i = 1; i < array.size(); ++i) {
    if (array[i][0] == 0) {
      nullifyRows(array, i);
    }
  }

  // Nullify columns based on the markers in the first row
  for (int j = 1; j < array[0].size(); ++j) {
    if (array[0][j] == 0) {
      nullifyCols(array, j);
    }
  }

  // Nullify the first row if necessary
  if (rowHasZero) {
    nullifyRows(array, 0);
  }

  // Nullify the first column if necessary
  if (colHasZero) {
    nullifyCols(array, 0);
  }
}

int main(int argc, char* argv[]) {

  srand(time(0));

  std::vector<std::vector<int>> array(5, std::vector<int>(5));

  for (int i = 0; i < array.size(); ++i) {
    for (int j = 0; j < array[i].size(); j++) {
      array[i][j] = rand() % 5;
    }
  }

  print2dArray(array);

  // zeroMatrix(array);
  rotateMatrix(array);
  std::cout << std::endl;

  print2dArray(array);

  return 0;
}
