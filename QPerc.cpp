//------------------------------------------------------------------------------
// Copyright (C) 2017 Intel Corporation 
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//------------------------------------------------------------------------------

/* Test for qHiPSTER:
 * proper implementaiton of the methods to compute the expectation value of Pauli strings
 * on single, two or multiple qubitsi.
 */

#include "../qureg/qureg.hpp"

using namespace std;

#include <iostream>	// to use: std::cout, std::cin and std::endl
#include <iomanip>	// to use: setw() in making tables
#include <complex>


/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char **argv)
{
  unsigned myrank=0, nprocs=1;
#ifdef INTELQS_HAS_MPI
  openqu::mpi::Environment env(argc, argv);
  myrank = openqu::mpi::Environment::rank();
  nprocs = openqu::mpi::Environment::size();
//  MPI_rank(MPI_COMM_WORLD, &myrank);
#endif

  double sum = 0.;

  std::cout << "------------------\n"
            << "   Single qubit   \n"
            << "------------------\n";

  QubitRegister<ComplexDP> psi(3,"base",0);
  psi.EnableStatistics();  
  psi.Print(" initial state |psi>=|-> : ");

  psi.ApplyHadamard(0);
  psi.ApplyHadamard(1);

  psi.Print(" initial state |psi>=|-> : ");

  psi.ApplyPauliZ(1);

  psi.Print(" initial state |psi>=|-> : ");

  psi.ApplyCPauliZ(0,1);

  psi.Print(" initial state |psi>=|-> : ");

  psi.ApplyPauliZ(0);
  psi.ApplyPauliZ(1);

  psi.Print(" initial state |psi>=|-> : ");

  psi.ApplyCPauliZ(0,1);

  psi.Print(" initial state |psi>=|-> : ");

  psi.ApplyHadamard(0);
  psi.ApplyHadamard(1);
  
  psi.Print(" initial state |psi>=|-> : ");

  psi.ApplyPauliX(0);
  psi.ApplyPauliX(1);

  psi.Print(" initial state |psi>=|-> : ");

  psi.ApplyToffoli(2,0,1);
  
  psi.Print(" initial state |psi>=|-> : ");

  double prob = 0.;

  prob =  psi.GetProbability(2);

  std::cout<< " Ancilla Measurement: " << prob << std::endl;
  return 0;
}
