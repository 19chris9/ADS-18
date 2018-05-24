#include "MyAlgorithms.h"
#include <omp.h>


void Merge(vector<int> &a, int low, int m, int high)
{
	int n1 = m - low + 1;
	int n2 = high - m;
	vector<int> l, r;
	l.resize(n1);
	r.resize(n2);

	for (int i = 0; i < n1; i++)
		l[i] = a[low + i];
	for (int z = 0; z < n2; z++)
		r[z] = a[m + 1 + z];

	int c1 = 0; int c2 = 0; int c3 = low;

	while (c1 < n1 && c2 < n2)
	{
		if (l[c1] <= r[c2])
		{
			a[c3] = l[c1];
			c1++;
		}
		else
		{
			a[c3] = r[c2];
			c2++;
		}
		c3++;
	}

	while (c1 < n1)
	{
		a[c3] = l[c1];
		c1++;
		c3++;
	}
	while (c2 < n2)
	{
		a[c3] = r[c2];
		c2++;
		c3++;
	}
}

void swap(int *a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(vector<int> &arr, int left, int right)
{
	int p = arr[right];
	int small = (left - 1);

	for (int i = left; i <= right - 1; i++) {
		if (arr[i] <= p) {
			small++;
			swap(&arr[small], &arr[i]);
		}
	}
	swap(&arr[small + 1], &arr[right]);
	return (small + 1);
}

void heap(vector<int> &a, int n, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && a[left] > a[largest])
		largest = left;
	if (right < n && a[right] > a[largest])
		largest = right;

	if (largest != i) {
		swap(a[i], a[largest]);
		heap(a, n, largest);
	}
}

namespace MyAlgorithms {

  //************
  // QuickSort *
  //************      
  void QuickSort(vector<int> &arr, int left, int right) {
	  if (left < right) {
		  int pi = partition(arr, left, right);
		  QuickSort(arr, left, pi - 1);
		  QuickSort(arr, pi + 1, right);
	  }

  }

  //************
  // MergeSort *
  //************
  void MergeSort(vector<int> &a, int low, int high) {
	  if (low < high) {
		  int m = low + (high - low) / 2;
		  MergeSort(a, low, m);
		  MergeSort(a, m + 1, high);
		  Merge(a, low, m, high);
	  }

  }
  
  //************
  // Heapsort  *
  //************

  void HeapSort(vector<int> &a, int n) { 
	  for (int i = n / 2 - 1; i >= 0; i--)
		  heap(a, n, i);
	  for (int i = n - 1; i >= 0; i--) {
		  swap(a[0], a[i]);
		  heap(a, i, 0);
	  }
  }

  //************
  // Shellsort *
  //************
  void ShellSort(vector<int> &a, int n)
  {
	  for (int gap = (2 << (int)(log(n / 2) / log(2))) - 1; gap > 0; gap /= 2) {
		  for (int i = gap; i < n; i++) {
			  int tmp = a[i];
			  int j = i;
			  for (; j >= gap && tmp < a[j - gap]; j -= gap) {
				  a[j] = a[j - gap];
			  }
			  a[j] = tmp;
		  }
	  }

  }
 
  //************************************
  //Matrix Multiplication Column Major *
  //************************************

  void MatrixMul_ColMajor(vector<double> &A, 
			  vector<double> &B, 
			  vector<double> &C, 
			  int n, 
			  int numThreads)
  {
	  int num_procs = numThreads;
	  omp_set_num_threads(num_procs);

    //lda, ldb, ldc are leading dimensions of matrices A,B and C
    int lda = n;
    int ldb = n;
    int ldc = n;
    double s = 0.0;

	int i;
	#pragma omp parallel for
    for (i = 0; i<n ; i++) {
      for (int j=0; j<n ; j++) {
	s = 0.0;
	for (int k=0; k<n; k++) {
	  s = s + A[i+k*lda] * B[k+j*ldb];
	}
	C[i+j*ldc]=s;
      }
    }
  }

  //*********************************
  //Matrix Multiplication Row Major *
  //*********************************

  void MatrixMul_RowMajor(vector<double> &A, 
			  vector<double> &B, 
			  vector<double> &C, 
			  int n,
			  int numThreads)
  {
	  int num_procs = numThreads;
	  omp_set_num_threads(num_procs);

	  int lda = n;
	  int ldb = n;
	  int ldc = n;
	  double s = 0.0;

	#pragma omp parallel for
	  for (int i = 0; i<n; i++) {
		  for (int j = 0; j<n; j++) {
			  s = 0.0;
			  for (int k = 0; k<n; k++) {
				  s = s + A[i* lda + k] * B[k * ldb + j];
			  }
			  C[i * lda + j] = s;
		  }
	  }

  }

  //********************
  // helper functions  *
  //********************
  double fRand(double fMin, double fMax) {
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
  }

  void randomizeMatrix(vector<double> &matrix, int n) {
    matrix.resize(n*n);
    int i;
    for (i=0;i<matrix.size();i++)
      matrix[i]=fRand(-1000,1000);
  }

  void randomizeArray(vector<int> &array, int n) {
    array.resize(n);

    for(int i=0;i<array.size();i++)
      array[i]=rand() % 1000000;
  }
}
