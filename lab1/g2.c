#include <stdio.h>
#include <stdlib.h>

int main()
{
  double f[120];
  f[1] = 1;
  f[2] = 1;
  for (int i = 3; i < 102; i++)
  {
    f[i] = f[i - 1] + f[i - 2];
  }
  printf("%.8lf\n", f[100] / f[101]);
  system("pause");
  return 0;
}