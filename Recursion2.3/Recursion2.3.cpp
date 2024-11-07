#include <iostream>
using namespace std;

void shiftLeft(int** arr, int rows, int cols, int shifts) {
    if (shifts == 0) return;

    int* firstCol = new int[rows];
    for (int i = 0; i < rows; i++) {
        firstCol[i] = arr[i][0];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols - 1; j++) {
            arr[i][j] = arr[i][j + 1];
        }
        arr[i][cols - 1] = firstCol[i];
    }

    delete[] firstCol;
    shiftLeft(arr, rows, cols, shifts - 1);
}

int main() {
    int rows = 3, cols = 4;
    int arr[3][4] = {
        {4, 5, 6, 7},
        {1, 2, 4, 1},
        {4, 5, 6, 9}
    };

    int* matrix[3];
    for (int i = 0; i < rows; i++) matrix[i] = arr[i];

    int shifts;
    cout << "количество сдвигов влево: ";
    cin >> shifts;

    shiftLeft(matrix, rows, cols, shifts);

    cout << "матрица после сдвига влево:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) cout << matrix[i][j] << " ";
        cout << endl;
    }

    return 0;
}

