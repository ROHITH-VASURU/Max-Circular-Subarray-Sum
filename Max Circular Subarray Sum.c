#include<stdio.h>
int maxSubarraySumCircular(int array[], int n);

int main(void)
{
  int arr[] = {8,-8,9,-9,10,-11,12};
  int a = maxSubarraySumCircular(arr, 7);
  printf("%d\n", a);
}

int maxSubarraySumCircular(int array[], int n){
  int max = 0;
  int a[n];
  for(size_t i=0; i < n; i++)
  {
    int x=i;
    int z = (n-i);
    int k;

    for(size_t j=0; j < n; j++)
    {
      k = j;
      if(z == j)
      {
        x = 0;
      }
      if(j == 0)
      {
        a[j] = array[x];
      }
      else
      {
        a[j] = array[x] + a[--k];
      }
      ++x;
    }
    if(i == 0)
    {
      max = a[i];
    }

    for(size_t b=0; b < n; b++)
    {
      if(max < a[b])
      {
        max = a[b];
      }
    }
  }
  return max;
}
