#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *fp;
  unsigned char s[1000];
  int i = 0;
  fp = fopen("hello.c", "r");
  while (!feof(fp))
  {
    fscanf(fp, "%c", &s[i]);
    i++;
  }
  fclose(fp);
  int n = 0;
  for (int j = 0; j < i; j++)
  {
    if (s[j] == '\n')
    {
      printf("\\n\n");
      for (int k = n; k <= j; k++)
      {
        if (s[k] == '\n')
          printf("%x\n", s[k]);
        else
          printf("%x  ", s[k]);
      }
      n = j + 1;
    }
    else
      printf("%c  ", s[j]);
  }
  printf("\n");
  system("pause");
  return 0;
}