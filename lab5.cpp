// Name: lab5.cpp
// Author: Brianna Drew
// ID: #0622446
// Date Created: 2021-10-18
// Last Modified: 2021-10-22

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/operation.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <iostream>
#include <time.h>
#include <stdlib.h>

int main () {
  using namespace boost::numeric::ublas;
  using namespace std;

  double starttime = clock(); // start "timer"
  // create 3x3 matrices
  matrix<double> M(3, 3);
  matrix<double> N(3, 3);
  matrix<double> P(3, 3);
  srand(time(0)); // seed for random number generation

  // fill matrix M with random numbers between 1 and 100
  for (unsigned i = 0; i < M.size1(); i++)
    for (unsigned j = 0; j < M.size2(); j++)
      M(i, j) = rand() % 100 + 1;

  // fill matrix N with random numbers between 1 and 100
  for (unsigned i = 0; i < N.size1(); i++)
    for (unsigned j = 0; j < N.size2(); j++)
      N(i, j) = rand() % 100 + 1;

  // multiply M and N matrices and store resulting matrix in P
  axpy_prod(M, N, P, true);

  // output matrices
  cout << endl << "Matrix #1: " << M << endl;
  cout << "Matrix #2: " << N << endl;
  cout << "Product: " << P << endl << endl;

  // output sums of matrices
  cout << "Sum of Matrix #1: " << sum(prod(scalar_vector<double>(M.size1()), M)) << endl;
  cout << "Sum of Matrix #2: " << sum(prod(scalar_vector<double>(N.size1()), N)) << endl;
  cout << "Sum of Product Matrix: " << sum(prod(scalar_vector<double>(P.size1()), P)) << endl << endl;

  double endtime = clock(); // end "timer"
  // output time program took in seconds
  cout << "Time Elapsed: " << (((float)(endtime - starttime)) / CLOCKS_PER_SEC) << " seconds." << endl << endl;
  return 0;
}
