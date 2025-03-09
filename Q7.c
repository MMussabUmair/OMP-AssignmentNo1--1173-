// Parallel(Reduction, Static Scheduling with 4 threads)

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<omp.h>

#define N 1000000 // define the array size

// function to count the even numbers in the array

int countEvenParallel (int arr[], int size){
    int count = 0;

    #pragma omp parallel for reduction(+:count) schedule(static, 100)
    for (int i=0; i<size; i++ ){
        if(arr[i] % 2 == 0){
            count++;
        }
    }

    return count;
}

int main(){

    int numbers[N];
    srand(time(0));   // random number generator

    // generate random numbers and print them 
    printf("generated random numbers:\n");
    for(int i=0; i<N; i++){
        numbers[i] = rand() % 1000;
      // printf("%d ", numbers[i]);

    }

    //  printf("\n");

    // Set number of threads to 4
    omp_set_num_threads(4);

    //measure execution time 
    double start = omp_get_wtime();
    int evenCount = countEvenParallel(numbers, N);
    double end = omp_get_wtime();

    //print results 
    printf("Parallel Even Count: %d\n", evenCount);
    printf("Execution Time: %f seconds\n", end - start);

    return 0;
}

//Sum = 0.004588 + 0.004655 + 0.004652 + 0.005248 + 0.004556 + 0.005125 + 0.005187 + 0.005095 + 0.005122 + 0.004539
//Average = sum / 10 
//Average = 0.004877
