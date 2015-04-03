/*
QUentin Pinçon
*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "mpi.h"
#include <string.h>

struct timeval startwtime, endwtime;
double seq_time;


int N;          // data array size
int *a;         // data array to be sorted

const int ASCENDING  = 1;
const int DESCENDING = 0;
int  numtasks, taskid;
MPI_Status stat;
void init(int task, int N);
int cmpfuncASC (const void * b, const void * c);
int cmpfuncDES (const void * b, const void * c);
void print(void);
void sort(void);
void test(void);
inline void exchange(int i, int j);
void compare(int i, int j, int dir);
void bitonicMerge(int lo, int cnt, int dir);
void recBitonicSort(int lo, int cnt, int dir);
void impBitonicSort(void);
void exchangeLow (int paired_process);
void exchangeHigh (int paired_process);
void testall ();


/** the main program **/ 
int main(int argc, char **argv) {

  if (argc != 2) {
    printf("Usage: %s q\n  where n=2^q is problem size (power of two)\n", 
	   argv[0]);
    exit(1);
  }

  N = 1<<atoi(argv[1]);
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
  MPI_Comm_rank(MPI_COMM_WORLD,&taskid);
  //printf ("MPI task %d has started...\n", taskid);
  a = (int *) malloc(N * sizeof(int));
  
  init(taskid, N); //initialization of all arrays

  gettimeofday (&startwtime, NULL);
  impBitonicSort();
  gettimeofday (&endwtime, NULL);
  MPI_Barrier(MPI_COMM_WORLD); 
  if (taskid==0){
    seq_time = (double)((endwtime.tv_usec - startwtime.tv_usec)/1.0e6 + endwtime.tv_sec - startwtime.tv_sec);

    printf("\nImperative wall clock time = %f\n", seq_time);
  } 
  MPI_Barrier(MPI_COMM_WORLD); 
  print();
  testall();

  MPI_Finalize();

}

/** -------------- SUB-PROCEDURES  ----------------- **/ 

int cmpfuncASC (const void * b, const void * c)
{
   return ( *(int*)b - *(int*)c );
}

int cmpfuncDES (const void * b, const void * c)
{
   return ( *(int*)c - *(int*)b );
}


void testall () {
  int max,min;
  test();
  max=a[N-1];
  if(taskid==0){
    MPI_Send(&max,1,MPI_INT,taskid+1,0,MPI_COMM_WORLD);
  }
  else if (taskid==(numtasks-1)){
    MPI_Recv(&min,1,MPI_INT,taskid-1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
    if(min>a[0]){
      printf("TEST FAILED for process %d\n",taskid);
    }
    else{
      printf("TEST PASSED for process %d\n",taskid);
    }
  }
  else{
    MPI_Send(&max,1,MPI_INT,taskid+1,0,MPI_COMM_WORLD);
    MPI_Recv(&min,1,MPI_INT,taskid-1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
   if(min>a[0]){
      printf("TEST FAILED for process %d\n",taskid);
   }
  else{
    printf("TEST PASSED for process %d\n",taskid);
  }
  }
}

/** procedure test() : verify sort results **/
void test() {
  int pass = 1;
  int i;
  for (i = 1; i < N; i++) {
    pass &= (a[i-1] <= a[i]);
  }

  printf(" TEST %s for order in array in process %d\n",(pass) ? "PASSED " : "FAILED",taskid);
}


/** procedure init() : initialize array "a" with data **/
void init(int task, int N) {
  int i;
  srand(task*N); // different seed for every process
  for (i = 0; i < N; i++) {
    a[i] = rand() % N; // (N - i);
  }
}

/** procedure  print() : print array elements **/
void print() {
  int i;
  for (i = 0; i < N; i++) {
    printf("%d  ", a[i]);
  }
  printf("\n");
}


/** INLINE procedure exchange() : pair swap **/
inline void exchange(int i, int j) {
  int t;
  t = a[i];
  a[i] = a[j];
  a[j] = t;
}



/** procedure compare() 
   The parameter dir indicates the sorting direction, ASCENDING 
   or DESCENDING; if (a[i] > a[j]) agrees with the direction, 
   then a[i] and a[j] are interchanged.
**/
inline void compare(int i, int j, int dir) {
  if (dir==(a[i]>a[j])) 
    exchange(i,j);
}




/** Procedure bitonicMerge() 
   It recursively sorts a bitonic sequence in ascending order, 
   if dir = ASCENDING, and in descending order otherwise. 
   The sequence to be sorted starts at index position lo,
   the parameter cbt is the number of elements to be sorted. 
 **/
void bitonicMerge(int lo, int cnt, int dir) {
  if (cnt>1) {
    int k=cnt/2;
    int i;
    for (i=lo; i<lo+k; i++)
      compare(i, i+k, dir);
    bitonicMerge(lo, k, dir);
    bitonicMerge(lo+k, k, dir);
  }
}



/** function recBitonicSort() 
    first produces a bitonic sequence by recursively sorting 
    its two halves in opposite sorting orders, and then
    calls bitonicMerge to make them in the same order 
 **/
void recBitonicSort(int lo, int cnt, int dir) {
  if (cnt>1) {
    int k=cnt/2;
    recBitonicSort(lo, k, ASCENDING);
    recBitonicSort(lo+k, k, DESCENDING);
    bitonicMerge(lo, cnt, dir);
  }
}


/** function sort() 
   Caller of recBitonicSort for sorting the entire array of length N 
   in ASCENDING order
 **/
void sort() {
  recBitonicSort(0, N, ASCENDING);
}



/*
  imperative version of bitonic sort
*/
void impBitonicSort() {

  int j,k;
  
  for (k=2; k<=numtasks; k=2*k) {
    for (j=k>>1; j>0; j=j>>1) {
	   int ij=taskid^j;
      if (ij>taskid){
	     if ((taskid&k)==0) 
	      exchangeLow(ij);
	     if ((taskid&k)!=0)
	      exchangeHigh(ij);
      }else{
        if ((taskid&k)!=0) 
        exchangeLow(ij);
        if ((taskid&k)==0)
        exchangeHigh(ij);
      }

    }
  }
   qsort(a,N,sizeof(int),cmpfuncASC);
}


/*The process caller of this function will first get his array sorted depending if the paired process is higher (ASC) or lower (DES) than him. 
Then it will send half of his array to the paired process and receive half of the array of the paired process, compare N/2 times and exchange if the received part is lower than him.
Then it will send bak the half sorted and received the other half sorted and paste it*/
void exchangeLow (int paired_process) {

  int i;
  int sort;
  int *buf_send = (int *)malloc((N/2)*sizeof(int));
  int *buf_rcv = (int *)malloc((N/2)*sizeof(int));

  if (taskid<paired_process) {
    qsort(a,N,sizeof(int),cmpfuncASC);
    sort=ASCENDING;
  }else{
    qsort(a,N,sizeof(int),cmpfuncDES);
    sort=DESCENDING;
  }


  //send the upper part of the array of the process
  MPI_Send (a+(N/2),      //upper part of the array
           (N/2),         // half of total elements
            MPI_INT,paired_process,0,MPI_COMM_WORLD); 

  MPI_Recv (buf_rcv,N/2,MPI_INT,paired_process,0,MPI_COMM_WORLD,&stat); //receive half of the data of the paired process (his lower part)

  if (sort==ASCENDING){
  for (i=((N/2)-1);i>0;i--) { //the compare loop. exchange values with buffer if lower values in buffer
    if (buf_rcv[i]<a[i]) {
      int temp;
      temp=a[i];
      a[i]=buf_rcv[i];
      buf_rcv[i]=temp;
    }
    else {
      break; //optimization : break if the condition is not true because there is no point continuing comparing since one array is going ascending and the other descending
    }
  }
  }
  else {
    for (i=0;i<(N/2);i++) { //the compare loop. exchange values with buffer if lower values in buffer
    if (buf_rcv[i]<a[i]) {
      int temp;
      temp=a[i];
      a[i]=buf_rcv[i];
      buf_rcv[i]=temp;
    }
    else {
      break; //optimization : break if the condition is not true because there is no point continuing comparing since one array is going ascending and the other descending
    }
  }
  }


  //send of the compared received array
  buf_send=buf_rcv;
  MPI_Send (buf_send,(N/2),MPI_INT,paired_process,0,MPI_COMM_WORLD);
  //Receiving of the corresponding compared array of the paired process
  MPI_Recv (buf_rcv,(N/2),MPI_INT,paired_process,0,MPI_COMM_WORLD,&stat);
  //to finish, copy the received array into the upper half of the array of current process
  memcpy(a+(N/2), buf_rcv, (N/2)*sizeof(int));



  //free(buf_rcv);
  //free(buf_send);
}



/*==================================================*/

void exchangeHigh (int paired_process) {

  int i;
  int sort;
  int *buf_send = (int *)malloc((N/2)*sizeof(int));
  int *buf_rcv = (int *)malloc((N/2)*sizeof(int));

  if (taskid<paired_process) {
    qsort(a,N,sizeof(int),cmpfuncASC);
    sort=ASCENDING;
  }else{
    qsort(a,N,sizeof(int),cmpfuncDES);
    sort=DESCENDING;
  }

  MPI_Recv (buf_rcv,N/2,MPI_INT,paired_process,0,MPI_COMM_WORLD,&stat); //receive half of the data of the paired process (his upper part)

    //send the lower part of the array of the process
  MPI_Send (a,      //lower part of the array
           (N/2),         // half of total elements
            MPI_INT,paired_process,0,MPI_COMM_WORLD); 


  if (sort==ASCENDING){
  for (i=0;i<(N/2);i++) {
    if (a[i+(N/2)]<buf_rcv[i]) {
      int temp=0;
      temp=a[i+(N/2)];
      a[i+(N/2)]=buf_rcv[i];
      buf_rcv[i]=temp;
    }
    else {
      break;
    }
  }
  }
  else{
    for (i=((N/2)-1);i<0;i--) {
    if (a[i+(N/2)]<buf_rcv[i]) {
      int temp=0;
      temp=a[i+(N/2)];
      a[i+(N/2)]=buf_rcv[i];
      buf_rcv[i]=temp;
    }
    else {
      break;
    }
  }
  }

  //send of the previously compared received array
  buf_send=buf_rcv;
  MPI_Send (buf_send,(N/2),MPI_INT,paired_process,0,MPI_COMM_WORLD);
  //Receiving of the corresponding compared array of the paired process
  MPI_Recv (buf_rcv,(N/2),MPI_INT,paired_process,0,MPI_COMM_WORLD,&stat);

  //to finish, copy the received array into the lower half of the array of current process
  memcpy(a, buf_rcv, (N/2)*sizeof(int));

 // free(buf_rcv);
 // free(buf_send);
}