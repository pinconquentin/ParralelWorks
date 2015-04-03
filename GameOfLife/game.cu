#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <cuda.h>

#define BLOCKSIZE 25





__host__ __device__ int countAlive (int i, int j, int N, int* in);
__host__ __device__ void check (int index, int *count, int * in);

  /* The Kernel procedure. Assumes that the grid and blocks are squared, so we have a square matrix*/
__global__ void game( int N, int* in, int* out ) {
  int i = blockIdx.y*blockDim.y + threadIdx.y;
  int j = blockIdx.x*blockDim.x + threadIdx.x;
  int neighbours=countAlive(i,j,N,in);

  if ((neighbours==3) || ((neighbours==2) && (in[i*N + j]==1))){
    out [i*N + j]=1;
  }
  else {
    out [i*N + j]=0;
  }
  __syncthreads();
}


__global__ void game2( int N, int* in, int* out, int thperblok ) {
  int i = blockIdx.y*blockDim.y + threadIdx.y;
  int j = blockIdx.x*blockDim.x + threadIdx.x;
  int k=0;
  for (k=0; k<thperblok;k++){
    int neighbours=countAlive(i,j* thperblok + k,N,in);

    if ((neighbours==3) || ((neighbours==2) && (in[i*N + j*thperblok + k ]==1))){
      out [i*N + j*thperblok + k]=1;
    }
    else {
      out [i*N + j*thperblok + k]=0;
    }
  }

  __syncthreads();
}


__global__ void game5(int N, int* in, int* out, int thperblok){

   __shared__ extern int tab[] ;

  int j = blockIdx.x * blockDim.x + threadIdx.x;
  int i = blockIdx.y * blockDim.y + threadIdx.y;
  int x =threadIdx.x;
  int y=threadIdx.y;
  int sizeline = (blockDim.x)*thperblok+ 2;
  int k=0;

  for (k=0;k<thperblok;k++){
    if ((x==0) && (y==0)){ //bottom left
      if (k==0){
      tab[k] = in[((i-1+N)%N)*N+((j*thperblok +k-1+N)%N)]; //bottom left
      tab[(y+1)*sizeline+ x*thperblok + k]=in[i*N+((j*thperblok + k-1+N)%N)]; //left
    }
      tab[(y+1)*sizeline + (x+1)*thperblok -(thperblok-1) +k]=in[i*N + j*thperblok + k]; //self
      tab[y*sizeline + (x+1)*thperblok-(thperblok-1)+k]=in[(((i-1+N)%N)*N) + j*thperblok + k]; // down
    }
    else if ((x==0)&&(y!=0)&&(y!=blockDim.y-1)){ //all left
      if (k==0){
      tab[(y+1)*sizeline+ x*thperblok + k]=in[i*N+((j*thperblok + k-1+N)%N)]; //left
    }
      tab[(y+1)*sizeline + (x+1)*thperblok -(thperblok-1) +k]=in[i*N + j*thperblok + k]; //self
    }
    else if ((x==blockDim.x-1)&&(y==0)){ //bottom right
      if (k==(thperblok-1)){
      tab[(blockDim.x+1)*thperblok-(thperblok-1)]=in[((i-1+N)%N)*N+((j*thperblok + k+1)%N)];//bottom right
      tab[(y+1)*sizeline+ (x+2)*thperblok -(thperblok-1)]=in[(i*N) + ((j*thperblok + k+1)%N)];//right
    }
      tab[(y+1)*sizeline + (x+1)*thperblok -(thperblok-1) +k]=in[i*N + j*thperblok + k]; //self
      tab[y*sizeline + (x+1)*thperblok-(thperblok-1)+k]=in[(((i-1+N)%N)*N) + j*thperblok + k]; // down
    }
    else if((x==blockDim.x-1)&&(y!=0)&&(y!=blockDim.y-1)){// all right
      if (k==(thperblok-1)){
      tab[(y+1)*sizeline+ (x+2)*thperblok -(thperblok-1)]=in[(i*N) + ((j*thperblok + k+1)%N)];//right
    }
      tab[(y+1)*sizeline + (x+1)*thperblok -(thperblok-1)+k]=in[i*N + j*thperblok + k]; //self
    }
    else if ((x!=0)&&(x!=blockDim.x-1)&&(y==0)){ // all bottom
      tab[y*sizeline + (x+1)*thperblok-(thperblok-1)+k]=in[(((i-1+N)%N)*N) + j*thperblok + k]; // down 
      tab[(y+1)*sizeline + (x+1)*thperblok -(thperblok-1) +k]=in[i*N + j*thperblok + k]; //self
    }
    else if ((x==blockDim.x-1)&&(y==blockDim.y-1)){//right up
      if (k==(thperblok-1)){
      tab[sizeline*(blockDim.y+2) -1 ]=in[(((i+1)%N)*N) + ((j*thperblok + k+1)%N)];//right up
      tab[(y+1)*sizeline+ (x+2)*thperblok -(thperblok-1)]=in[(i*N) + ((j*thperblok + k+1)%N)];//right
    }
      tab[(y+1)*sizeline + (x+1)*thperblok -(thperblok-1) +k]=in[i*N + j*thperblok + k]; //self
      tab[(y+2)*sizeline + (x+1)*thperblok -(thperblok-1) + k]=in[(((i+1)%N)*N) + j*thperblok + k]; //up
    }
    else if ((x==0)&&(y==blockDim.y-1)){//left up
      if (k==0){
      tab[(y+2)*sizeline + k]=in[(((i+1)%N)*N) + ((j*thperblok + k-1+N)%N)];//up left
      tab[(y+1)*sizeline+ x*thperblok + k]=in[i*N+((j*thperblok + k-1+N)%N)]; //left
    }
      tab[(y+1)*sizeline + (x+1)*thperblok -(thperblok-1) +k]=in[i*N + j*thperblok + k]; //self
      tab[(y+2)*sizeline + (x+1)*thperblok -(thperblok-1) + k]=in[(((i+1)%N)*N) + j*thperblok + k]; //up
    }
    else if ((x!=0)&&(x!=blockDim.x)&&(y==blockDim.y-1)){//all up
      tab[(y+2)*sizeline + (x+1)*thperblok -(thperblok-1) + k]=in[(((i+1)%N)*N) + j*thperblok + k]; //up
      tab[(y+1)*sizeline + (x+1)*thperblok -(thperblok-1) +k]=in[i*N + j*thperblok + k]; //self
    }
    else {
        tab[(y+1)*sizeline + (x+1)*thperblok -(thperblok-1) +k]=in[i*N + j*thperblok + k]; //all other threads that are not on the side of the block
    }
}
  __syncthreads();

  for (k=0;k<thperblok;k++){
      int neighbours = countAlive(y+1,(x+1)*thperblok -(thperblok-1) + k,sizeline, tab);
      if ((neighbours==3) || ((neighbours==2) && (tab[(y+1)*sizeline + (x+1)*thperblok -(thperblok-1) +k]==1))){
        out [i*N + j*thperblok + k]=1;
      }
      else {
        out [i*N + j*thperblok + k]=0;
      }
  }

}


__host__ __device__ int countAlive (int i, int j, int N, int* array){
  int count=0;



  check ( (((i+1)%N)*N) + j, &count, array); //up cell
  check ( (((i-1+N)%N)*N) + j, &count, array); //down cell
  check ( (i*N) + ((j+1)%N), &count, array); //right cell
  check ( (i*N) + ((j-1+N)%N), &count, array); //left cell
  check ( (((i+1)%N)*N) + ((j+1)%N), &count, array); //right up cell
  check ( (((i+1)%N)*N) + ((j-1+N)%N), &count, array); //left up cell
  check ( (((i-1+N)%N)*N) + ((j-1+N)%N), &count, array); //left down cell
  check ( (((i-1+N)%N)*N) + ((j+1)%N), &count, array); //right down cell
  return count;
}

__host__ __device__ void check (int index, int *count, int * array) {
  if(array[index]==1){
    (*count)++;
  }
}


void read_from_file(int *X, char *filename, int N){
  FILE *fp = fopen(filename, "r+");
  int size = fread(X, sizeof(int), N*N, fp);
  printf("elements: %d\n", size);
  fclose(fp);
}

void save_new_table(int *X, int N, int cycles){
  FILE *fp;
  char filename[20];
  sprintf(filename, "table%dx%d-%dit.bin", N, N,cycles);
  printf("Saving table in file %s\n", filename);
  fp = fopen(filename, "w+");
  fwrite(X, sizeof(int), N*N, fp);
  fclose(fp);
}










int main(int argc, char **argv){

  int *dev_in, *dev_out;
  char *filename = argv[1];
  int N = atoi(argv[2]);
  int cycles = atoi (argv[3]);
  int *table = (int *)malloc(N*N*sizeof(int));
  int l=1;
  int m=1;
  int o=1;
  int choice;
  float ttime;
  int thperblok = 4 ;
  cudaError_t err;
  cudaEvent_t start, stop;

  if (argc != 4) {
    printf("Usage : filename, number of elements, number of cycles\n");
    exit(1);
  }

  if ((cycles%2)!=0) {
    printf("Error : need a pair number of cycles ! Exiting...\n");
    exit(1);
  }

  printf("Enter your choice : 1 for one cell per thread, 2 for multiple cells per thread without shared memory, 3 for multiple cells per thread with shared memory, 4 for serial computation\n");
  scanf ("%d", &choice);

  if ((choice==2) || (choice==3)){
    printf("Choose a number of cells per thread so that %d/(25xnumber) is an integer\n",N);
    scanf("%d", &thperblok);
  }

  printf("Reading %dx%d table from file %s\n", N, N, filename);
  
  read_from_file(table, filename, N);



  /* Memory allocation part */
  cudaMalloc( &dev_in, (N*N)*sizeof(int) );
  cudaMalloc( &dev_out, (N*N)*sizeof(int) );
  
  cudaMemcpy( dev_in, table, (N*N)*sizeof(int), cudaMemcpyHostToDevice );

  cudaEventCreate(&start);
  cudaEventCreate(&stop);
  cudaEventRecord(start, 0);

  /*Launch of the computation*/ 
  dim3 dimBlock( BLOCKSIZE, BLOCKSIZE );

  dim3 dimGrid1= dim3(N/dimBlock.x, N/dimBlock.y);
  dim3 dimGrid2= dim3(N/(dimBlock.x*thperblok), N/dimBlock.y); //same for 2 and 3
  printf(" Size of the one per threads grid: Grid : %dx%d, blocks : %dx%d\n", dimGrid1.x, dimGrid1.y, dimBlock.x, dimBlock.y);
  printf(" Size of the multiple cells per threads grid: Grid : %dx%d, blocks : %dx%d\n", dimGrid2.x, dimGrid2.y, dimBlock.x, dimBlock.y);

  switch (choice) {
    case 1 :
    printf("Lauch of the computation with one cell per thread...\n");


    for (l=1; l<=cycles;l++){ /* Needs a pair number of cycles !*/
      if ((l%2)==1){
        game<<<dimGrid1,dimBlock>>>(N, dev_in, dev_out );
        cudaThreadSynchronize();
        cudaDeviceSynchronize();
      }
      else {
            game<<<dimGrid1,dimBlock>>>(N, dev_out, dev_in ); /* Executed last, so we have the result in dev_in*/
        cudaThreadSynchronize();
        cudaDeviceSynchronize();
      }
    }
    err = cudaGetLastError();
    if( err != cudaSuccess ) {
      printf("Error: %s\n", cudaGetErrorString(err));
    }
    cudaEventRecord(stop, 0);
    cudaEventSynchronize(stop);
    cudaEventElapsedTime(&ttime, start, stop);

    cudaMemcpy( table, dev_in, (N*N)*sizeof(int), cudaMemcpyDeviceToHost );

    save_new_table(table,N,cycles);
    printf("\nTime for 1 cell per thread= %3.1f ms\n", ttime);
    break;




    case 2:
    printf("Lauch of the computation with multiple cells per thread without shared memory...\n");
    printf("Grid : %dx%d, blocks : %dx%d", dimGrid2.x, dimGrid2.y, dimBlock.x, dimBlock.y);
    for (m=1; m<=cycles;m++){ /* Needs a pair number of cycles !*/
      if ((m%2)==1){
        game2<<<dimGrid2,dimBlock>>>(N, dev_in, dev_out,thperblok );
        cudaDeviceSynchronize();
        cudaThreadSynchronize();
      }
      else {
              game2<<<dimGrid2,dimBlock>>>(N, dev_out, dev_in,thperblok ); /* Executed last, so we have the result in dev_in*/
        cudaDeviceSynchronize();
        cudaThreadSynchronize();
      }
  }
err = cudaGetLastError();
if( err != cudaSuccess ) {
  printf("Error: %s\n", cudaGetErrorString(err));
}
cudaEventRecord(stop, 0);
cudaEventSynchronize(stop);
cudaEventElapsedTime(&ttime, start, stop);

cudaMemcpy( table, dev_in, (N*N)*sizeof(int), cudaMemcpyDeviceToHost );
save_new_table(table,N,cycles);
printf("\nTime for %d cells per thread= %3.1f ms\n", thperblok, ttime);

break;





case 3:

printf("Lauch of the computation with multiple cells per thread with shared memory...\n");

      //game3<<<dimGrid2,dimBlock, (dimBlock.x+1)*(dimBlock.y+1)*thperblok*sizeof(int)>>>(N, dev_in, dev_out, thperblok );
     for (l=1; l<=cycles;l++){ /* Needs a pair number of cycles !*/
      if ((l%2)==1){
        game5<<<dimGrid2,dimBlock,(dimBlock.x*thperblok+2)*(dimBlock.y+2)*sizeof(int)>>>(N, dev_in, dev_out,thperblok); /*because we need all surrounding cells in the shared memory*/
        cudaThreadSynchronize();
        cudaDeviceSynchronize();
      }
      else {
        game5<<<dimGrid2,dimBlock,(dimBlock.x*thperblok+2)*(dimBlock.y+2)*sizeof(int)>>>(N, dev_out, dev_in,thperblok); /* Executed last, so we have the result in dev_in*/
        cudaThreadSynchronize();
        cudaDeviceSynchronize();
      }
}

err = cudaGetLastError();
if( err != cudaSuccess ) {
  printf("Error: %s\n", cudaGetErrorString(err));
}
cudaEventRecord(stop, 0);
cudaEventSynchronize(stop);
cudaEventElapsedTime(&ttime, start, stop);

cudaMemcpy( table, dev_in, (N*N)*sizeof(int), cudaMemcpyDeviceToHost );
save_new_table(table,N,cycles);
printf("\nTime for %d cells per thread with shared memory= %3.1f ms\n", thperblok, ttime);
break;




case 4:
{
  clock_t begin, end;
  double time_spent;
  printf("Lauch of the serial computation...\n");
  int *newtable = (int *)malloc(N*N*sizeof(int));
  begin = clock();
  for (o=1;o<=cycles;o++){ /*Iteration loop*/
    if ((o%2)==1){
      for (l=0;l<N;l++){ /*Line indicator*/
        for(m=0;m<N;m++){ /*Row indicator*/
          int neighbours=countAlive(l,m,N,table);
              //printf("Voisins pour index %d : %d \n",l*N + m, neighbours);
          if ((neighbours==3) || ((neighbours==2) && (table[l*N + m]==1))){
            newtable [l*N + m]=1;
          }
          else {
            newtable [l*N + m]=0;
          }

        }
      }
    }
    else {
      for (l=0;l<N;l++){ /*Line indicator*/
        for(m=0;m<N;m++){/*Row indicator*/
          int neighbours=countAlive(l,m,N,newtable);
              //printf("Voisins pour index %d : %d \n",l*N + m, neighbours);
          if ((neighbours==3) || ((neighbours==2) && (newtable[l*N + m]==1))){
            table [l*N + m]=1;
          }
          else {
            table [l*N + m]=0;
          }

        }
      }
    }
  }
  end = clock();
  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  save_new_table(table,N,cycles);
  printf("\nTime for serial code = %3.1f ms\n",time_spent*1000);
}
break;


default :
printf("Error in the choice : must be beetwen 1 and 3. Exiting...\n");
exit(1);
}

cudaFree(dev_in);
cudaFree(dev_out);
free(table);
return 0;

}