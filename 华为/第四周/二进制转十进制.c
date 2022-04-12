#include "stdio.h"
#include <string.h>


int bintodec(const char *pbin){
  int ii=0;
  int result=0;
  while (pbin[ii]!=0)
  {
    result=result*2+(pbin[ii]-'0');
    ii++;
  }
  return result;
}

int main()
{
  char str[65];
  memset(str,0,sizeof(str));
  scanf("%s",str);
  printf("%d\n",bintodec(str));
}
