#include <iostream>
#include <omp.h>

void parallelBubbleSort(int arr[], int n) {
    #pragma omp parallel
    {
        #pragma omp for
        for (int i = 0; i < n - 1; i++) {
            // Code for Bubble Sort iterations

            // Each thread performs sorting on its assigned sublist
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    // Swap elements
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }

            // Synchronize the threads after each iteration
            #pragma omp barrier
        }
    }
}

int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    int arr[n];
    std::cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    parallelBubbleSort(arr, n);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
