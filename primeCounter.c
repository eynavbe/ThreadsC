// Improved Code



#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define NUM_THREADS 4

struct ThreadArgs {
    int *numbers;
    int start;
    int end;
    int counter;
};

bool isPrime(int n) {
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

void *countPrimes(void *args) {
    struct ThreadArgs *threadArgs = (struct ThreadArgs *)args;
    int counter = 0;

    for (int i = threadArgs->start; i < threadArgs->end; i++) {
        if (isPrime(threadArgs->numbers[i])) {
            counter++;
        }
    }

    threadArgs->counter = counter;

    return NULL;
}

int main() {
    int total_counter = 0;
    int capacity = 500000; 
    int *numbers = (int *)malloc(capacity * sizeof(int));

    if (numbers == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    int num;
    int count = 0;

    while (scanf("%d", &num) != EOF) {
        if (count >= capacity) {
            // Process current chunk
            pthread_t threads[NUM_THREADS];
            struct ThreadArgs threadArgs[NUM_THREADS];
            int chunkSize = count / NUM_THREADS;
            int remainder = count % NUM_THREADS;
            int start = 0;

            for (int i = 0; i < NUM_THREADS; i++) {
                threadArgs[i].numbers = numbers;
                threadArgs[i].start = start;
                threadArgs[i].end = start + chunkSize + (i < remainder ? 1 : 0);
                pthread_create(&threads[i], NULL, countPrimes, (void *)&threadArgs[i]);
                start = threadArgs[i].end;
            }


            for (int i = 0; i < NUM_THREADS; i++) {
                pthread_join(threads[i], NULL);
                total_counter += threadArgs[i].counter;
            }

            count = 0;
        }

        numbers[count++] = num;
    }

    if (count > 0) {
        pthread_t threads[NUM_THREADS];
        struct ThreadArgs threadArgs[NUM_THREADS];
        int chunkSize = count / NUM_THREADS;
        int remainder = count % NUM_THREADS;
        int start = 0;

        for (int i = 0; i < NUM_THREADS; i++) {
            threadArgs[i].numbers = numbers;
            threadArgs[i].start = start;
            threadArgs[i].end = start + chunkSize + (i < remainder ? 1 : 0);
            pthread_create(&threads[i], NULL, countPrimes, (void *)&threadArgs[i]);
            start = threadArgs[i].end;
        }

        for (int i = 0; i < NUM_THREADS; i++) {
            pthread_join(threads[i], NULL);
            total_counter += threadArgs[i].counter;
        }
    }

    printf("%d total primes.\n", total_counter);

    free(numbers);

    return 0;
}


// 491146 total primes.

// real    0m4.616s
// user    0m14.359s
// sys     0m0.219s


















/* Source Code


#include <stdio.h>
#include <stdbool.h>
#include <time.h> 


// Function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int num;
    int total_counter = 0;

    // Read numbers from stdin until end of file
    while (scanf("%d", &num) != EOF) {   
        if (isPrime(num)) {
            total_counter++;
        }
    }
    
    printf("%d total primes.\n", total_counter);

    return 0;
}


// 491146 total primes.

 // real    0m40.743s
 // user    0m41.281s
 // sys     0m1.000s

*/
