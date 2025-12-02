
//Develop a program to identify and efficiently store a sparse matrix using compact
representation and perform basic operations like display and simple transpose.

#include <iostream>
using namespace std;

void createSparse(int rows, int cols, int matrix[10][10], int sparse[100][3]) {
    int k = 1, nonZero = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
                nonZero++;
            }
        }
    }
    sparse[0][0] = rows;
    sparse[0][1] = cols;
    sparse[0][2] = nonZero;
}

void displaySparse(int sparse[100][3]) {
    int total = sparse[0][2] + 1;
    cout << "\nRow\tCol\tValue\n";
    for (int i = 0; i < total; i++) {
        cout << sparse[i][0] << "\t" << sparse[i][1] << "\t" << sparse[i][2] << endl;
    }
}

void transposeSparse(int sparse[100][3], int transpose[100][3]) {
    int rows = sparse[0][0];
    int cols = sparse[0][1];
    int nonZero = sparse[0][2];
    transpose[0][0] = cols;
    transpose[0][1] = rows;
    transpose[0][2] = nonZero;

    int k = 1;
    for (int col = 0; col < cols; col++) {
        for (int i = 1; i <= nonZero; i++) {
            if (sparse[i][1] == col) {
                transpose[k][0] = sparse[i][1];
                transpose[k][1] = sparse[i][0];
                transpose[k][2] = sparse[i][2];
                k++;
            }
        }
    }
}

int main() {
    int rows, cols;
    int matrix[10][10];
    int sparse[100][3], transpose[100][3];

    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    createSparse(rows, cols, matrix, sparse);
    cout << "\nSparse Matrix:\n";
    displaySparse(sparse);

    transposeSparse(sparse, transpose);
    cout << "\nTranspose of Sparse Matrix:\n";
    displaySparse(transpose);

    return 0;
}
