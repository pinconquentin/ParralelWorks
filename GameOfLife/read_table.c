#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BLOCKSIZE 25

int countAlive (int i, int j, int N, int* in);
void check (int index, int *count, int * in);

  /* The Kernel procedure. Assumes that the grid and blocks are squared, so we have a square matrix*/
__global__ void game( int N, int* in, int* out ) {
  int i = blockIdx.x*blockDim.x + threadIdx.x;
  int j = blockIdx.y*blockDim.y + threadIdx.y;
  if ((countAlive(i,j,N,x)==3) || ((countAlive(i,j,N,x)==2) && (in[i*N + j]==1){
    out [i*N + j]=1;
  }
  else {
    out [i*N + j]=0;
  }
}


int countAlive (int i, int j, int N, int* in){
  int count=0;

  // check((i*N+((j+1)%N),&count,in)  // Right side cellule to left side
  // if ((i==0) && (j==0)) { // only one case, don't affect performance
  //   check(N-1,&count,in)
  // }
  // else {
  // check(((i*N+j-1)%N)+i*N,&count,in) //left side to right side (except for j = i = 0)
  // }
  // check((i*N+j+N)%(N*N),&count,in) //for connect the upper side to lower side

  //   check(i*N+j+N-1,&count,in);
  // }
  // if (((i*N+j-1)%N)==N-1){
  //   check(i*N+j+N-1,&count,in);
  // }
  // else if  (((i*N+j+1)%N)==0) {
  //   check(i*N+j-N+1,&count,in);
  // }
  // else if (((i*N+j+N)>=N*N)

  // }

  check ( (((i+1)%N)*N) + j, &count, in); //up cell
  check ( (((i-1+N)%N)*N) + j + j, &count, in); //down cell
  check ( (i*N) + ((j+1)%N), &count, in); //right cell
  check ( (i*N) + ((j-1+N)%N), &count, in); //left cell
  check ( (((i+1)%N)*N) + ((j+1)%N), &count, in); //right up cell
  check ( (((i+1)%N)*N) + ((j-1+N)%N), &count, in); //left up cell
  check ( (((i-1+N)%N)*N) + ((j-1+N)%N), &count, in); //left down cell
  check ( (((i-1+N)%N)*N) + ((j+1)%N), &count, in); //right down cell
  return count;
}

void check (int index, int *count, int * in) {
  if(in[index]==1)
    *count++;
}


void read_from_file(int *X, char *filename, int N){
  FILE *fp = fopen(filename, "r+");
  int size = fread(X, sizeof(int), N*N, fp);
  printf("elements: %d\n", size);
  fclose(fp);
}

void save_new_table(int *X, int N){
  FILE *fp;
  char filename[20];
  sprintf(filename, "table%dx%dnew.bin", N, N);
  printf("Saving table in file %s\n", filename);
  fp = fopen(filename, "w+");
  fwrite(X, sizeof(int), N*N, fp);
  fclose(fp);
}



int main(int argc, char **argv){
  //int *host_x, *host_y;
  int *dev_in, *dev_out;

  char *filename = argv[1];

  int N = atoi(argv[2]);

  printf("Reading %dx%d table from file %s\n", N, N, filename);

  int *table = (int *)malloc(N*N*sizeof(int));
  
  
  
  read_from_file(table, filename, N);

  // printf("Grid une dimension :\n");
  //    for(int i=0; i<N; i++){
  //     for(int j=0; j<N; j++){
  //       printf("%d ",table[i*N + j]);
  //     }
  //     printf("\n");
  //   }

  // int newTable[N][N];
  // printf("Grid deux dimensions :\n");
  //  for(int i=0; i<N; i++){
  //   for(int j=0; j<N; j++){
  //     newTable[i][j]=table[i*N+j];
  //     printf("%d ",newTable[i][j]);
  //   }
  //   printf("\n");
  // }

  /*CUDA PART : Sending of the table to the GPU and computation depending of the memory managment chosen*/

  //host_in = (int*)malloc( (N*N)*sizeof(int) );
  //host_result = (int*)malloc( (N*N)*sizeof(int) );

  /* Memory allocation part */
  cudaMalloc( &dev_in, (N*N)*sizeof(int) );
  cudaMalloc( &dev_out, (N*N)*sizeof(int) );
  /* TODO: fill host_x[i] with data here */
  cudaMemcpy( dev_in, table, (N*N)*sizeof(int), cudaMemcpyHostToDevice );
   // Launch of the computation 
  dim3 dimBlock( BLOCKSIZE, BLOCKSIZE );
  dim3 dimGrid( N/dimBlock.x, N/dimBlock.y );
  game<<<dimGrid,dimBlock>>>(N, dev_in, dev_out );
  cudaMemcpy( table, dev_out, N*sizeof(int), cudaMemcpyDeviceToHost );
  /* host_y now contains cos(x) data */
  save_new_table(table,N);
  free(table);

}