#include <stdio.h>

int calculate_sum(int arr[], int size) {
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    return sum;
}

double calculate_average(int sum, int size) {
    return sum / size;
}

int main(void) {
    int numbers[] = {10, 20, 30, 40, 50};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    int sum = calculate_sum(numbers, size);
    double average = calculate_average(sum, size);

    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);

    return 0;
}