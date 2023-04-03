/*
 * 问题：那你用一个简单的代码demo 来实现这些算法，同时将计算出来的数据进行存储
 * 以下是一个使用加权平均和滑动平均算法的代码示例，同时将计算出来的数据存储在数组中：
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DATA_SIZE 20

float data[DATA_SIZE];
/*
 * 随机数生成
 * */
int randvol(float *data) {

    // 设置随机数种子
    srand(time(NULL));
    // 生成随机电压数据
    for (int i = 0; i < DATA_SIZE; i++) {
        data[i] = 31 + (float)rand()/(float)(RAND_MAX/25); // 生成3.6~3.8之间的随机数
    }
    // 输出结果
    for (int i = 0; i < DATA_SIZE; i++) {
        printf("%f  \t", data[i]);
    }
    printf("\n");
    return 0;
}

float sort(float *arr){
    int i, j;
    float temp;
    float sum = 0, avg;
    for (i = 0; i < DATA_SIZE; i++) {
        for (j = i + 1; j < DATA_SIZE; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (i = 0; i < DATA_SIZE-2; i++) {
        sum += arr[i];
    }
    sum = sum - arr[0] - arr[DATA_SIZE - 1];
    avg = sum / (DATA_SIZE - 2);
#if 0
    printf("Sorted array after removing minimum and maximum elements:\n");
    for (i = 1; i < DATA_SIZE - 1; i++) {
        printf("%f ", arr[i]);
    }
    printf("\nAverage of the remaining elements:sum:%.2f %.2f \n", sum,avg);
    return 0;
#endif
    return avg;
}
/*
 * weighted average algorithm
 *
 */
float weighted_average(float *data){
    // 加权平均算法
    float weights[DATA_SIZE] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
    float sum = 0, weight_sum = 0;
    for (int i = 0; i < DATA_SIZE; i++) {
        sum += data[i] * weights[i];
        weight_sum += weights[i];
    }
    float weighted_avg = sum / weight_sum;
    printf("Weighted average: %f\n", weighted_avg);
    return weighted_avg;
}
/*
 * 滑动平均算法
 * */
float moving_average(float *data){
    int window_size = 3;
    float moving_avg[DATA_SIZE - window_size + 1];
    float window_sum = 0;
    for (int i = 0; i < window_size; i++) {
        window_sum += data[i];
    }
    moving_avg[0] = window_sum / window_size;
    for (int i = window_size; i < DATA_SIZE; i++) {
        window_sum -= data[i - window_size];
        window_sum += data[i];
        moving_avg[i - window_size + 1] = window_sum / window_size;
    }
    // 输出结果
    printf("Moving average: ");
    for (int i = 0; i < DATA_SIZE - window_size + 1; i++) {
        printf("%f ", moving_avg[i]);
    }
    printf("\n");
    return 0;
}
int main() {
    randvol(data);
    sort(data);
    weighted_average(data);
    moving_average(data);
    return 0;
}
