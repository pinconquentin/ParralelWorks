#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <math.h>
#include <locale.h> //library used to print the float with a comma instead of a point.

#define DELTA 0.0001

int lines=0;
float* PR1;
float* PR2;
float damping = 0.85;
float *random_search;
int *index_row;
int *index_colomn;
int *numlinks;
struct timeval startwtime, endwtime;
double seq_time;
volatile int counter_threads = 0;
pthread_mutex_t counter_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t counter_cond = PTHREAD_COND_INITIALIZER ;
int semaphore = 1 ;

typedef struct {
	int id;
	int size;
	int nbthreads ;
	int N;
} arguments;

/* fuction max returns 0 if the former and the new page rankings are still too different
and 1 if they are all very closed. */
int max(int N){ 
	double temp=0.0; 
	int i ;
	
	for(i = 0 ; i<N; i++){
		temp = fabs((double)PR2[i]-(double)PR1[i]) ;
		// printf("temp = %f, PR1[%d]=%f ; PR2[%d]= %f\n",temp, i,PR1[i],i, PR2[i]);
		if (temp > DELTA){
			return 0 ;
		}
	}

	return 1 ;
}

/* get the sparce matrix from the adjacency file that we get from MATLAB */
int reading_from_matrix() {
	char ch;
	FILE* fid;
	fid = fopen ("data1000.txt", "r");

	do{		// calculate the number of lines of the file
    	ch = fgetc(fid);
   		if(ch == '\n')
    	lines++;
	} while (ch != EOF);

	index_row = (int*)malloc(sizeof(int)*lines);
	index_colomn = (int*)malloc(sizeof(int)*lines);
	char temp[15];
	int index=0;
	printf("Number of lines : %d\n",lines);
	rewind(fid);

	int i;
	for (i=0;i<lines;i++) {	// collects all the indexes of the row where there is a one.
		fscanf(fid, "%s", temp);
		index_row[i] = atoi(temp);
	}

	for (i=0;i<lines;i++) {	// collects all the indexes of the row where there is a one.
		fscanf(fid, "%s", temp);
		index_colomn[i] = atoi(temp);
	}
}


/* New function that finds all the number of outgoing links for each website, and save it in an array.*/
void get_number_links_tab (int N) { 
	int j,i;

/*	for (i=0;i<lines;i++){
		printf("index_colomn[%d]=%d\n",i,index_colomn[i]);
	}
	for (i=0;i<lines;i++){
		printf("index_row[%d]=%d\n",i,index_row[i]);
	}*/
	for (i=1;i<N+1;i++){
		for( j=0;j<lines; j++) {
			if (index_colomn[j] == i ){
				numlinks[i-1]++;
			}
		}
	}
/*		for (i=0;i<N;i++){
			printf("numlinks[%d]=%d\n",i,numlinks[i]);
		}
*/	
}

/* Calculate all the page rankings. */
void compute_pr (int N, float* new_page_ranking, float * former_page_ranking, int tid, int nbdata, int nbthreads){
	int i,j, deb, fin;

	if(tid == (nbthreads - 1)){
		deb = tid * nbdata ;
		fin = N ;
	}
	else{
		deb = tid * nbdata ;
		fin = (tid+1)*nbdata ;
	}

	for (i=deb; i<fin; i++){ //on parcours tous les nodes
		new_page_ranking[i] = 0.0;
		for(j=0;j<lines;j++){
			if (index_row[j]==i+1){ //regarde si i est dans la table des lignes i+1 car pas de node d'indice 0
				new_page_ranking[i]+= former_page_ranking[index_colomn[j]-1]/ numlinks[index_colomn[j]-1];/*get_number_links(index_colomn[j]);*/ // si oui, on mate dans la table des colonnes pour voir quel node, on retire son PR
			
			}
		}

	
	new_page_ranking[i] = (1-damping)*random_search[i] + damping*new_page_ranking[i] ;
			
		// printf("node %d : %f  	\n",i,new_page_ranking[i]);
	}
	// printf("\n\n");
}

/* Translate the page ranking calculated into probabilities.*/
void pr_to_probabilities(int N){
	
	float sum=0.0;
	int i;
	for (i=0;i<N;i++){
		sum += PR1[i];
		// printf("Node %d : %f \n", i+1,PR1[i]);
	}
	printf("\n\n");

	double factor = 1/sum;	// The sum is different than 1, so it is not probabilities.
	
	sum=0.0;

	for (i=0;i<N;i++){

		PR1[i]=factor * PR1[i];	// Multiply each Page Ranking with the found factor, in order to have probabilites.

		sum += PR1[i];	// Computation of the sum again, in order to check that the sum of all the probabilities is equal to 1.
		
		setlocale(LC_NUMERIC,"it_IT.UTF-8");
		printf("%f\n", PR1[i]);  // print the values of the page rankings
	}

	printf("\n Average = %f",sum);
}

void * function(void * arg){

	arguments t_arg = *(arguments*)arg ;
	int x ;
	int nbdata=t_arg.N/t_arg.nbthreads;
	float * temp;
	int it=0;

	while(semaphore==1){
		compute_pr(t_arg.N,PR2, PR1, t_arg.id, nbdata, t_arg.nbthreads);
		it++; // We used this varaible to check the number of iterations.
		//printf("après computePR N° %d \n", t_arg.id);
		pthread_mutex_lock(&counter_mutex);
    	counter_threads++;
    	
    	if(counter_threads!=t_arg.nbthreads){
    		pthread_cond_wait(&counter_cond, &counter_mutex );
    	}
    	else{
    		counter_threads = 0 ;
    		if(max(t_arg.N) == 1){
    			// printf("Semaphore = %d, threadID = %d\n", semaphore, t_arg.id);
				semaphore = 0 ;
			}
			// Put the value of PR2 (the new page rankings calculated) into PR1. For that we use a temporary pointer.
    		temp = PR2 ;
			PR2=PR1;
			PR1=temp;
    		pthread_cond_broadcast(&counter_cond) ;
    	}
    	pthread_mutex_unlock(&counter_mutex);

		
	}
	if(t_arg.id==0){
		printf("Number of it : %d \n",it);
	}

	pthread_exit(NULL);
}


int main( int argc, char* argv[]){
	

	int N;
	int init;
	int nbthreads;
		if(argc != 4){
		printf("You should use the function like this : first N init nbthreads\nWhere N is the size of the graph (be careful that it is the same size then the file, \n init the value of the initial vector\nand nbthreads the number of threads.\n");
			exit(1);
	}

	N = atoi(argv[1]) ;
	init = atoi(argv[2]) ;
	nbthreads = atoi(argv[3]) ;

	random_search = (float *)malloc(sizeof(int)*N); // rando vector, used in the formula
	PR1 = (float *) malloc (sizeof(float)*N);
	PR2 = (float *) malloc (sizeof(float)*N);
	numlinks = (int *)malloc(sizeof(int)*N); // array containing the number of outgoing links of every node

	int i,j;

	for (i=0;i<N;i++){ // initialize the random vector.
		random_search[i]=/*(float)rand()/RAND_MAX*/1;
	}

	for (i=0;i<N;i++){ // initialize the vector of page ranking with the value given by the user.
		PR1[i]=init;
	}

	reading_from_matrix() ;

	get_number_links_tab(N);

/*===============COMPUTATION OF THE NEW PAGE RANK creation of the threads =================*/
	pthread_t * threads = (pthread_t *) malloc(sizeof(pthread_t)*nbthreads);
	int rc;
	arguments * args = (arguments *) malloc( sizeof(arguments)*nbthreads);
	int * tid = (int *) malloc(sizeof(int)*nbthreads) ;
	int t;

	gettimeofday (&startwtime, NULL);	//Starts the timer

	for(t=0; t<nbthreads; t++){
		args[t].id = t;
		args[t].size = N;
		args[t].N = N ;
		args[t].nbthreads = nbthreads ;
		//printf("Creation du th n° %d\n", t);

    	rc = pthread_create(&threads[t], NULL, function, &args[t]);
    	if (rc){
     		printf("ERROR; return code from pthread_create() is %d\n", rc);
        	exit(-1);
    	}
	}

	for(t=0; t<nbthreads;t++){	//wait for all the threads to have finish his computation
		pthread_join(threads[t],NULL) ;
	}
	
	pr_to_probabilities(N);

	gettimeofday (&endwtime, NULL);		//stops the timer
	seq_time = (double)((endwtime.tv_usec - startwtime.tv_usec)/1.0e6 + endwtime.tv_sec - startwtime.tv_sec);
    printf("\nWall clock time for parrallel computation : %f\n", seq_time);


    free(PR1);
    free(PR2);
    free(numlinks);
    free(index_colomn);
    free(index_row);
    free(random_search);
    return 0;

}
