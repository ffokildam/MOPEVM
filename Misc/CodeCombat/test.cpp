#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
  char str[1000];
  int max_size = -1000, min_size = 1000;
  int n, i,rast=0;
  scanf("%d\n", &n);
  for (i = 0; i < n; i++)
  {
    scanf("%c", &str[i]);
  }
  for (i = 0;i < n;i++)
  {
    if (str[i] != '#' )
    {
      rast += 1;
    }
    else if(str[i]=='#' || str[i] == '\n')
    {
      if (rast < min_size)
      {
        min_size = rast;
      }
      if (rast > max_size)
      {
        max_size = rast;
      }
      rast = 0;
    }
  }
  printf("%d %d", min_size, max_size);
  return 0;

}