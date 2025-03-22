// Parallel (Reduction, dynamic Scheduling) with chunk size 500 with by default 8 threads 

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<omp.h>

#define N 1000000 // define the array size

// function to count the even numbers in the array

int countEvenParallel (int arr[], int size){
    int count = 0;

    #pragma omp parallel for reduction(+:count) schedule(dynamic, 500)
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

    //measure execution time 
    double start = omp_get_wtime();
    int evenCount = countEvenParallel(numbers, N);
    double end = omp_get_wtime();

    //print results 
    printf("Parallel Even Count: %d\n", evenCount);
    printf("Execution Time: %f seconds\n", end - start);

    return 0;
}


//Sum=0.002147+0.001289+0.004829+0.006048+0.004698+0.001820+0.006483+0.006063+0.004596+0.001411
//Average = sum / 10
//Average = 0.003938
