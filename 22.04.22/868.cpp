#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fileIn("INPUT.TXT");
    ofstream fileOut("OUTPUT.TXT");
    int n, m;
    fileIn >> n >> m;

    int** matrix = new int* [n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[m];
        for (int j = 0; j < m; ++j)
            fileIn >> matrix[i][j];
    }

    for (int i = 0; i < m - 1; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[j][i] < matrix[j][i + 1]) {
                for (int j = 0; j < n; j++) {
                    swap(matrix[j][i], matrix[j][i + 1]);
                }
            }
        }   
    }
        

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] < matrix[i + 1][j]) {
                for (int j = 0; j < m; j++) {
                    swap(matrix[i][j], matrix[i + 1][j]);
                }
            }
        }
    }
    fileOut << matrix[n - 1][m - 1];
}
