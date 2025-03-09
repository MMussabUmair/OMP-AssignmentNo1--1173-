//Sequntial code to find the count of even numbers in the array 

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 1000000 // define the array size

// function to count the even numbers in the array

int countEvenNumbers(int arr[], int size){
    int count = 0;
    for (int i=0; i<size; i++ ){
        if(arr[i]%2==0){
            count++;
        }
    }

    return count;
}

int main(){

    int numbers[N];
    srand(time(0));   // random number genetor

    // generate random numbers and print them 
    printf("generated random numbers:\n");
    for(int i=0; i<N; i++){
        numbers[i] = rand() % 1000;
     //  printf("%d ", numbers[i]);

    }

     // printf("\n");

    //measure execution time of even number counting 
    clock_t start = clock();
    int evenCount = countEvenNumbers(numbers, N);
    clock_t end = clock();

    //print results 
    printf("Even Numbers Count: %d\n", evenCount);
    printf("Execution Time: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

//Sum = 0.006941 + 0.008186 + 0.006770 + 0.006682 + 0.006603 + 0.006640 + 0.007330 + 0.007980 + 0.007172 + 0.008075
//Sum = 0.072379
//Average = sum / 10
//Average = 0.007238
