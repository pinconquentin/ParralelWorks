#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h> //library used to print the float with a comma instead of a point.

#define DELTA 0.0001

// const double delta=0.0001;


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

	int i ;
	for (i=0;i<lines;i++) {	// collects all the indexes of the row where there is a one.
		fscanf(fid, "%s", temp);
		index_row[i] = atoi(temp);
	}

	for (i=0;i<lines;i++) {	// collects all the indexes of the column where there is a one.
		fscanf(fid, "%s", temp);
		index_colomn[i] = atoi(temp);
	}
}

/* This function is not used anymore in this file. It was created in the first place to calculate the number of out going links of each website, 
but finally it was not optimal, because it was called each time we needed to know the total number of outgoing links. So instead, we decided to do 
the computation once, and then put them in one array. */
int get_number_links (int index) { 
	int j;
	int result=0;
	
		for( j=0;j<lines; j++) {
			if ( index_colomn[j]==index){
				result++;
			}
		}
		// printf("Result = %d for index %d\n", result, index);
	return result;
}

/* New function that finds all the number of outgoing links for each website, and save it in an array.*/
void get_number_links_tab (int N) { 
	int j;
	int i;

	for (i=1;i<N+1;i++){
		for( j=0;j<lines; j++) {
			if (index_colomn[j] == i ){
				numlinks[i-1]++;
			}
		}
	}

}

/* Calculate all the page rankings. */
void compute_pr (int N, float* new_page_ranking, float * former_page_ranking) {
	int i,j;

	for (i=0; i<N; i++){ //on parcours tous les nodes
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
		printf("%f\n", PR1[i]); // print the values of the page rankings
	}

	printf("\n Average = %f",sum);
}

int main( int argc, char* argv[]){
	

	int N;
	int init;
		if(argc != 3){
		printf("You should use the function like this : first N init \n Where N is the size of the graph (be careful that it is the same size then the file, \nand init the value of the initial vector.\n");
			exit(1);
	}

	N = atoi(argv[1]) ;
	init = atoi(argv[2]) ;
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

/*		for (i=0;i<lines;i++) {
			printf(" j=%d ; row : %d ; colomn : %d\n", i,index_row[i], index_colomn[i]) ;
		}*/

/*============================COMPUTATION OF THE NEW PAGE RANK (serial)======================*/
	get_number_links_tab(N);
	gettimeofday (&startwtime, NULL);
	int result ;
	float * temp;
	int it=0;
	while(1){

		compute_pr(N,PR2,PR1);
		it++; 	// We use this varaible to check the number of iterations.
		result = max(N) ;
		if(result == 1){
			break;
		}
		// Put the value of PR2 (the new page rankings calculated) into PR1. For that we use a temporary pointer.
		temp = PR2 ;
		PR2=PR1;
		PR1=temp;
		result = 0 ;
	}
	printf("Number of it : %d\n",it);
	/*We make the values probabilistic, to have a representation like the one in the given matlab code*/
	pr_to_probabilities(N) ;
	
	gettimeofday (&endwtime, NULL);

	seq_time = (double)((endwtime.tv_usec - startwtime.tv_usec)/1.0e6 + endwtime.tv_sec - startwtime.tv_sec);

    printf("\nImperative wall clock time = %f\n", seq_time);
/*=========================================================================================*/
    free(PR1);
    free(PR2);
    free(numlinks);
    free(index_colomn);
    free(index_row);
    free(random_search);
return 0;
}