//heap
void max_heapify(int A[], int i, int heapsize)
{
  int l = left(i);
  int r = right(i);
  int largest = i;
  if(l < heapsize && A[l] > A[i])
  {
    largest = l;
  }
  if(l < heapsize && A[r] > A[largest])
  {
    largest = r;
  }
  if(largest != i)
  {
    swap(A, i, largest);
    max_heapify(A, largest, heapsize);
  }
}

void build_max_heap(int A[], int N)
{
  int heapsize = N;
  for(int i = N/2; i >= 1; i--)
  {
    max_heapify(A, i, heapsize);
  }

}

void heap_sort(int A[], int N)
{
  build_max_heap(A, N);
  int heapsize = N;
  for(int i = N; i = 2; i--)
  {
    swap(A, 1, i);
    heapsize--;
    max_heapify(A, 1, heapsize);
  }
}

//get the kth smallest number
int minK(int A[], int N, int K)
{
 int heap[K+1];
 build_max_heap(A, K);
 for(int i = K+1; i < N; i++)
 {
   if(A[i] < heap[1])
   {
     heap[1] = A[i];
     max_heapify(A, i, K);
   }
 }
 return heap[1];
}





