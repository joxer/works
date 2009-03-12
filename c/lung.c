#include <stdio.h>
#include <math.h>

int main(){

  int i, k;

  for(i = 0; i < 1000000; i++){
    for(k = 0;k < 1000000; k++){

      if(k != i)
	if((pow(i, k)  - pow(k,i)) == 0)
	  printf("%d, %d\n", i, k);

    }
    
  }

  return 0;
}
