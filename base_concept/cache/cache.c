#include <stdio.h>
const int row = 1024;
const int col = 1024;
int matrix[row][col];

//按行遍历
int sum_row = 0;
for (int r = 0; r < row; r++) {
    for (int c = 0; c < col; c++) {
        sum_row += matrix[r][c];
    }
}

//按列遍历
int sum_col = 0;
for (int c = 0; c < col; c++) {
    for (int r = 0; r < row; r++) {
        sum_col += matrix[r][c];
    }
}
