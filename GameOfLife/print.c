#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv) {

 if (argc != 3) {
 	printf("Usage : filename, number of elements");
 	exit(1);
 }
 char *filename = argv[1];
 int i,j;
 int N = atoi(argv[2]);

 int *X = (int *)malloc(N*N*sizeof(int));
 FILE *fp = fopen(filename, "r+");
 fread(X, sizeof(int), N*N, fp);

 printf("Printing %d x %d elements from file %s\n", N , N, filename);
 for(i=(N-1); i>=0; i--){
    for(j=0; j<N; j++){
    	if ((X[i*N + j])==1){
      		printf("@ "); 
    	}
    	else {
    		printf(". "); 
    	}
  	}
    printf("\n");
 }
}
