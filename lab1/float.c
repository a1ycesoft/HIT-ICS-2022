#include <stdio.h>
#include <stdlib.h>
int main()
{
  float f;
  for (;;)
  {
    printf("input:");
    scanf("%f", &f);
    printf("it's:%f\n", f);
    if (f == 0)
    {
      break;
    }
  }

  system("pause");
  return 0;
}