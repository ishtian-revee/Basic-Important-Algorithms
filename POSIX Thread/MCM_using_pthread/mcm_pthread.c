#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#define INT_MAX 99999

/*

matrices: A(1*3), B(3*4), C(4*8), D(8*9)

result should be:

0	12	44	116	
-1	0	96	312	
-1	-1	0	288	
-1	-1	-1	0

*/

// global scope
int size = 5;			// holds the size of the array
int arr[5] = {1, 3, 4, 8, 9};	// 4 matrices
int result[9][9];		// result matrix

// function ptototypes
void *mcm(void *param);

int main(int argc, char *argv){

	pthread_t thread;           		// thread id
        pthread_attr_t attr;        		// set of thread attributes
        pthread_attr_init(&attr);   		// get the default attribute
	int *arg = malloc(sizeof(*arg));	// declaring the argument in int type
	*arg = size;				// setting the pointer
	pthread_create(&thread, &attr, mcm, arg);	// creating the thread

	pthread_join(thread, NULL);		// main thread will wait till all threads are done
}

void *mcm(void *var){
	
	int length = *((int *) var);		// casting to its actual pointer type
	int i, j, k, l, res, num = 0;
	int len = length-1;

	// setting some default values in the result array
	for(i=1; i<length; i++){
	
		for(j=1; j<=i; j++){
			
			if(i==j){

				result[i][j] = 0;
			}else{

				result[i][j] = -1;
			}
		}
	}

	// main functionality of matrix chain multiplication
	for(i=2; i<=len; i++){

		for(j=1; j<=len-i+1; j++){

			k = j+i-1;
			result[j][k] = INT_MAX;		// maximum value for an object type int

			for(l=j; l<k; l++){

				num = result[j][l] + result[l+1][k] + (arr[j-1]*arr[l]*arr[k]);
				
				// checking if the value is less than INT_MAX value
				if(num < result[j][k]){

					result[j][k] = num;
				}
			}
		}
	}

	// printing the result matrix after matrix chain multiplication
	printf("\n\nResult: \n\n");
	for(i=1; i<length; i++){

		for(j=1; j<length; j++){

			printf("%d\t", result[i][j]);
		}
		
		printf("\n");
	}
	
	// printing the minimum multiplication value
	res = result[1][size-1];
	printf("\n\nMinimum multiplication: %d\n\n", res);
}
