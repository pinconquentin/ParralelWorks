#!/bin/bash
#PBS -q auth
#PBS -N bitonic
#PBS -j oe
#PBS -l nodes=1:ppn=2

#export I2G_MPI_TYPE=mpich2
#export I2G_MPI_APPLICATION=bitonic

#Change directory to job submission directory
cd $PBS_O_WORKDIR

#Number of MPI processes (p)
NP=$(cat $PBS_NODEFILE | wc -l)

#Start for q=16
q=16

#Which corresponds to 2^16=65536 integers for each process
length=65536

#For q=[16:20], 2^20=1048576
while [ $q -le 20 ]; do

#Set arguments for next run (array length)
#export I2G_MPI_APPLICATION_ARGS=$q

echo -e "Running $NP processes for q=$q, length=$length \n"
mpirun -np $NP ./bitonic $q
#Run bitonic executable with $length elements
#$I2G_MPI_START

#Increment q to print value on next iteration
q=$[q+1]

#Multiply array length by 2 for the next iteration
length=$[length*2]
done