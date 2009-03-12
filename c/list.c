#include "list.h"


int main(){

  struct list l1, *l2, *l3, *l22;
  l22 = list_c();
  l22->value= 56;

  
  l1.value = 3; 
  l2 = add_list(&l1, 4);
  l3 = add_list(l2, 5);
  list_a_p(l22, l3);
    list_a_n(l22, &l1);
  
  search(&l1, 4);
  
  show_all(l22);

  return 0;
}
