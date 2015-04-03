#!/bin/bash
#PBS -q auth
#PBS -N bitonic
#PBS -j oe
#PBS -l nodes=1

#Change directory to job submission directory
cd $PBS_O_WORKDIR


#Start for q=16
q=21

#Which corresponds to 2^16=65536 integers for each process
length=65536

#For q=[16:20], 2^20=1048576
while [ $q -le 27 ]; do

echo -e "Running $NP processes for q=$q \n"

#Run bitonic executable with q elements
./bitonicserial $q

#Increment q to print value on next iteration
q=$[q+1]

done