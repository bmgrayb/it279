#ifndef _SORTS_H_
#define _SORTS_H_

class Sorts
{
 private:
  void quicksort(double *array, int left, int right);
  int median3(double *array, int left, int right);
  int partition(double *array, int left, int right, int pivot_index);
  void swap(double *array, int index1, int index2);
  void heapify(double *array, int min, int max);
  void percolate(double *array, int min, int max);
  void merge(double *array, int left, int mid, int right, int length);
 public:
  Sorts();
  static void insertion_sort(double *array,int length);
  void quicksort(double *array, int n);
  void heapsort(double *array, int n);
  void mergesort(double *array, int n);
};

 

#endif
