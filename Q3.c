// Parallel (Reduction, Static Scheduling)

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

    //measure execution time 
    double start = omp_get_wtime();
    int evenCount = countEvenParallel(numbers, N);
    double end = omp_get_wtime();

    //print results 
    printf("Parallel Even Count: %d\n", evenCount);
    printf("Execution Time: %f seconds\n", end - start);

    return 0;
}

//Sum = 0.001232 + 0.001259 + 0.005331 + 0.001311 + 0.005924 + 0.001229 + 0.001572 + 0.005244 + 0.001326 + 0.005485
//Average = sum / 10
//Average =0.002991

