# ThreadsC

## introduction:
The task is to count the number of prime numbers in the resulting stream of numbers.
Source code has been received and it needs to be improved so that it performs the task in less time and uses less than 2MB of RAM space.
## Explanation of the improved code:
The improved code uses 4 threads that allow simultaneous processing, creating a structure to store parameters for the thread function that contains the array of numbers, the range of the position in the array to be processed in the thread, a counter to count the first numbers. <br />
The isPrime function checks if the number is prime.
The countPrimes function counts the number of prime numbers in a range and updates the counter. <br />
The array built is dynamic and is defined according to the amount of numbers that is assigned, which receives from the program all the numbers defined in the program, the numbers are divided into threads and each amount of numbers is processed by a thread, each thread counts the number of the first numbers in the range assigned to it. and sum up all the first ones of the processing of each thread <br />
To make sure that the code does not exceed the memory of 2MB of RAM space, which is precisely that the dynamic memory that is allocated to the array of numbers and the array of the structure thread does not exceed that, therefore we will limit the memory allocation in favor of these cases and so that the code does not stop in the middle if it needs more memory, then we will call the numbers ranges And we will process each range and then we will make room before the next range.<br /><br />
• The files makefile, generator.c and PrimeCounter.c are in the submission folder.
## How to run the program:
It is necessary to make sure before running that the makefile file is found together with the file PrimeCounter.c and the file generator.c
To run the program, we will write at the beginning: <br />
```
make all 
  ```
 In the next line we will write: <br />
 ```
time ./randomgenerator 10 10000000| ./primeCounter
```
This way the program will run with 10 million numbers as required and print at the end of the run the time it took the program to find the initial ones from the given random numbers.

## The result of running the original code (given to us under the false name)
<img width="753" alt="‏result1" src="https://github.com/eynavbe/ThreadsC/assets/93534494/6a0de64b-df7c-4dd4-9d28-05dd299a972f">

## The result of the run after the changes:
<img width="598" alt="result2" src="https://github.com/eynavbe/ThreadsC/assets/93534494/802401b6-3567-43cc-92dc-096cfcadd3e4">


## Amount of memory space used by the program:
```
time ./randomgenerator 10 1000| valgrind --tool=massif ./primeCounter
```
Creates a file in the folder that shows the amount of memory used, the running line of the file:
```
ms_print massif.out...
```
<img width="548" alt="result3" src="https://github.com/eynavbe/ThreadsC/assets/93534494/450d4ece-dd19-412a-a0ad-38ba4ae44a86">


