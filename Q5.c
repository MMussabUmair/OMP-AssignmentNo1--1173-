// Parallel (Atomic, No Scheduling)

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<omp.h>

#define N 1000000 // define the array size

// function to count the even numbers in the array
int countEvenParallel(int arr[], int size) {
    int count = 0;

    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            #pragma omp atomic
            count++;
        }
    }

    return count;
}

int main() {

    int numbers[N];
    srand(time(0));   // random number generator

    // generate random numbers and print them
    printf("generated random numbers:\n");
    for (int i = 0; i < N; i++) {
        numbers[i] = rand() % 1000;
        // printf("%d ", numbers[i]);
    }

     //  printf("\n");

    // measure execution time 
    double start = omp_get_wtime();
    int evenCount = countEvenParallel(numbers, N);
    double end = omp_get_wtime();

    // print results 
    printf("Parallel Even Count: %d\n", evenCount);
    printf("Execution Time: %f seconds\n", end - start);

    return 0;
}

//Sum = 0.027293 + 0.026220 + 0.021238 + 0.021173 + 0.028235 + 0.027295 + 0.022313 + 0.023271 + 0.021586 + 0.022083
//Average = sum / 10 
//Average = 0.024071
