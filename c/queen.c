#include <stdio.h>
int i, k;
int matrix[8][8];
void aggiorna(int r, int c);
void posiziona_regina(int r,int c);
void cerca_posizione();
int nega(int x);

int nega(int x){

  return x>0?x:0;
}

void posiziona_regina( int r, int c ){
     
     matrix[r][c] = 9;
     aggiorna(r, c);
}                  

void aggiorna(int c, int r){
     
     for(i = 0; i < 8; i++){ 
       if(matrix[c][i] != 9) // verticale
	 matrix[c][i] += 1;
       if(matrix[i][r] != 9) // laterale
	 matrix[i][r] += 1;
     }
     /*
     for(i = r ; i != 0; i--)
       if(matrix[c-i][r+i] != 9)
	 matrix[c-i][r+i] += 1;
     */
	 

     for(i = r; i > 0; i--)
       if(matrix[c+i][r-i] != 9)
	 matrix[c+i][r-i] += 1;

   

     for( i = c,k = r ;i != 8;k++, i++) //down dx diago
       if(matrix[i][k] != 9)
	 matrix[i][k] += 1;
     
   
     
     /*  for( i = 0; i != c ; i++){ //diagonale superiore sinistra
       if(matrix[nega(r-c)+i][nega(c-r)+i] != 9) // ho bisogno di numeri naturali quindi usando nega vedo se negativo (e mi ritorna 0 senno' mi ritorna il numero normale
	 matrix[nega(c-r)+i][nega(r-c)+i] += 1;
	 }*/
    
     for(i = c; i != 0; i--){
       if(matrix[c+i][r-i] != 9)
	 matrix[c+i][r-i] += 1;
       
     }
     for(i = r; i>0;i--)
       if(matrix[c-i][r+i] != 9)
	 matrix[c-1][r+i] += 1;
     
 
}

void cerca_posizione(int b, int n){
     
  for(i = b; i < n;i++)
           for(k = 0; k < 8; k++)
	     if(matrix[i][k] == 0){
	       posiziona_regina(i,k);
	       cerca_posizione(i, n);
	     }
  
}


int main(){
    posiziona_regina(0 , 0);
    cerca_posizione()
    
    
    //cerca_posizione();
    
         puts("\n\n");
     for(i = 0;i < 8;i++){
       for(k = 0; k < 8;k++)
	 printf("%d ", matrix[i][k]);
       
       puts("");
     }

    return 0;   
}
