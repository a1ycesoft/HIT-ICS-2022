#include <stdio.h>
#include <stdlib.h>
double a[200];
double f(int n)
{
  if (n == 1 || n == 2)
  {
    a[n] = 1;
    return a[n];
  }
  if (a[n] == 0)
  {
    a[n] = f(n - 1) + f(n - 2);
    return a[n];
  }
  else
    return a[n];
}
int main()
{
  printf("%.8lf", f(100) / f(101));
  system("pause");
  return 0;
}