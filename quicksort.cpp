using namespace std;
//time complexity O(n)

//find the kth biggest number
int findKmax(int A[], int p, int q, int K)
{
  if(K <= 0)
    return -1;
  if(K > q - p + 1)
    return -1;
  int pivot = p + rand()%(q-p+1);
  swap(a[p],a[pivot]);
  //mark the pivot 
  int m = p;
  int count = 1;
  
  //scan all element and shift larger number to the left side
  for(int i = p + 1, i < q, i++)
  {
    if(a[i] > a[p])
    {
      swap(a[i], a[++m]);
      count ++
    }
  }
  // put the pivot to the middle of the left and right parts
  swap(a[m], a[p]);

  //start recursion
  if(count > K)
  {return findKmax(a, p, m-1, K);}
  else if(count < K)
  {return findKmax(a, m+1, q, K);}
  else
  {return m;}

}

//find the kth smallest number
int findKmin(int A[], int p, int q, int K)








