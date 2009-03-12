#include <stdio.h>
#include <malloc.h>

struct list {

  int value;

  struct list *next;
  struct list *prev;


};

/*
  append a previus node to current node

 */

int list_a_p(struct list *now, struct list *prev){

  now->prev = prev;
  prev->next = now;
  return 0;
    


}

/*
  append a next node to current node

 */

int list_a_n(struct list *now, struct list *next){

  now->next = next;
  next->prev = now;
  return 0;
  
}

/*

  create a node 

 */

struct list* list_c(){
  
  
  struct list *tmp = (struct list* )malloc(sizeof(struct list));
  tmp->value = NULL;
  return tmp;

}

/*

  create a node and add it to list
 */

struct list* list_add(struct list *l, int value){

  struct list *tmp;
  tmp = (struct list *) malloc(sizeof(struct list));
  
  tmp->value = value;
  l->next = tmp;
  tmp->prev = l;
  tmp->next = NULL;
  return tmp;
}


/*
  
  remove a node form list and merge the other

 */

int list_rem(struct list *l){
  
  /*

    rimuove il pezzo della lista e unisce i due pezzi staccati
    
   */
  if(l->prev != NULL)
    l->prev->next = l->next;
  if(l->next != NULL)
    l->next->prev = l->prev;
  
  free(l);
  return 0;
  
  
  
  
}

/*
  
  search a value into all nodes

 */

int search(struct list *l, int value){
  struct list *i = l;
  do{

    
    if(i->value == value){
      
     
      return 1;
    }
    i = i->next;
  }
  while(i != NULL);
    return 0;
  
}

/*

  return the last nodes

 */

int list_last(struct list *l){
  struct list *i;
  for(i = l; i->next != 0; i = i->next);
  
  return i->value;
}

/*
  
  return the first nodes

 */

int list_first(struct list *l){

  return l->value;

}

/*
  
  print all nodes

 */

int show_all(struct list *first){
  struct list *i = first;
  do{

    printf("%d\n", i->value);
    i = i->next;
  }

  while(i != 0 );
  return 0;
}
