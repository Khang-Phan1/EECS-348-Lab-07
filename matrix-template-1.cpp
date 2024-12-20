
#include <iostream>

using namespace std;

const int SIZE = 4; // Global variable for matrix size

class Matrix {
private:
  int data[SIZE][SIZE];  // 2D array for matrix data (using int for simplicity)

public:
  // 1. Read values from stdin into a matrix, user enters each element one by one
  void readFromStdin() {
    for (int i=0; i<SIZE; i++) {
      for (int j=0; j<SIZE; j++) {
        cin >> data[i][j];
      }
    }
  }

  // 2. Display a matrix with a tab in between each column for readability
  void display() const {
    for (int i=0; i<SIZE; i++) {
      for (int j=0; j<SIZE; j++) {
        cout << data[i][j] << "\t";
      }
      cout << endl;
    }
  }

  // 3. Add two matrices (operator overloading for +)
  Matrix operator+(const Matrix& other) const {
    Matrix sum;
    for (int i=0; i<SIZE; i++) {
      for (int j=0; j<SIZE; j++) {
        sum.data[i][j] = data[i][j] + other.data[i][j];
      }
    }
    return sum;
  }

  // 4. Multiply two matrices (operator overloading for *)
  Matrix operator*(const Matrix& other) const {
    Matrix product;
    for (int i=0; i<SIZE; i++) {
      for (int j=0; j<SIZE; j++) {
        product.data[i][j] = 0; //initializes each element of the product equal to 0 to avoid using random junk from memory

        for (int k=0; k<SIZE; k++) {
          //The element of the product is the ith row multiplied by the jth column. k iterates through each element of a row/col
          product.data[i][j] += data[i][k] * other.data[k][j];
        }
      }
    }
    return product;
  }

  // 5. Compute the sum of matrix diagonal elements
  int sumOfDiagonals() const {
    int sum;
    for (int i=0; i<SIZE; i++) {
      sum += data[i][i];
    }
    return sum;
  }

  // 6. Swap matrix rows
  void swapRows(int row1, int row2) {
    int temp[SIZE];
    for (int i=0; i<SIZE; i++) {
      temp[i] = data[row1][i];
      data[row1][i] = data[row2][i];
      data[row2][i] = temp[i];
    }
  }
};

int main() {
  // Example usage:
  Matrix mat1;
  cout << "Enter values for Matrix 1:" << endl;
  mat1.readFromStdin();
  cout << "Matrix 1:" << endl;
  mat1.display();

  Matrix mat2;
  cout << "Enter values for Matrix 2:" << endl;
  mat2.readFromStdin();
  cout << "Matrix 2:" << endl;
  mat2.display();

  Matrix sum = mat1 + mat2;
  cout << "Sum of matrices:" << endl;
  sum.display();

  Matrix product = mat1 * mat2;
  cout << "Product of matrices:" << endl;
  product.display();

  cout << "Sum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;

  mat1.swapRows(0, 2);
  cout << "Matrix 1 after swapping rows:" << endl;
  mat1.display();

  return 0;
}
