#include <stdio.h>
#include <stdlib.h>
int sum(int a[], unsigned len)
{
  int i, sum = 0;
  for (i = 0; i <= len - 1; i++)
  {
    sum += a[i];
  }
  return sum;
}
int main()
{
  int a[10] = {1, 2, 3};
  unsigned k = 0;
  printf("%u", k - 1);
  system("pause");
  return 0;
}