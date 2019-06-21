#!/bin/bash

cd /afs/cern.ch/work/n/noormanm/private/Intel-QS/tests/reza/Q-NN

mpiicpc -g -O3 -DUSE_MM_MALLOC -DSTANDALONE -DINTELQS_HAS_MPI -DMKL_ILP64 -Wall -std=c++11 -qopenmp -I./  -I../ -I../../ -I../../../ -L/cvmfs/projects.cern.ch/intelsw/psxe/linux/x86_64/2018/compilers_and_libraries_2018.3.222/linux/mkl/lib/intel64 -lmkl_cdft_core -lmkl_intel_ilp64 -lmkl_core -lmkl_intel_thread -lmkl_blacs_intelmpi_ilp64 -lpthread -c test.cpp -o test.o

mpiicpc -o test.exe -g -O3 -DUSE_MM_MALLOC -DSTANDALONE -DINTELQS_HAS_MPI -DMKL_ILP64 -Wall -std=c++11 -qopenmp   test.o ../../../qureg/qHiPSTER.a -L/cvmfs/projects.cern.ch/intelsw/psxe/linux/x86_64/2018/compilers_and_libraries_2018.3.222/linux/mkl/lib/intel64 -lmkl_cdft_core -lmkl_intel_ilp64 -lmkl_core -lmkl_intel_thread -lmkl_blacs_intelmpi_ilp64 -lpthread

#./test.exe 12 
