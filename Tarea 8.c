#include <stdio.h>
#include <time.h>
#define TAM 10000

int GeneraRandom(int arr[TAM]);
int ordenamientoBurbuja( int arr[TAM]);
int ordenamientoInsertion( int arr[TAM]);
int ordenamientoSelection(int arr[TAM]);
int Menor(int arr[TAM],int i);
void ordenamientoQuicksort(int arr[TAM],int limite_izq,int limite_der);

int main()
{
    time_t inicio,fin;
    int tiempo;
    int arr[TAM];
     srand(100);
    GeneraRandom(arr);
      for (int i=0; i<TAM; i++){
       printf("%d,",arr[i]);
   }
    inicio=clock();
   
    //ordenamientoBurbuja(arr);
    //ordenamientoInsertion(arr);
    ordenamientoSelection(arr);
    //ordenamientoQuicksort(arr,0,TAM);
  
    fin=clock();
    tiempo= fin-inicio;
   printf("\n");
   for (int i=0; i<TAM; i++){
       printf("%d,",arr[i]);
   }

   
  
    
    
  
   printf("\n Tiempo de Ejecucion: %d milisegundos",tiempo);
}


int ordenamientoBurbuja( int arr[TAM]){
for (int i=1; i<TAM; i++){
    
    for(int j=0 ; j<TAM - 1; j++){
        if (arr[j] > arr[j+1]){ 
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
            
        }
        
        
    }
}
}
int GeneraRandom(int arr[TAM])
{
    int i;

    for(i=0; i<TAM; i++)
    {
        arr[i]=rand();
    }
}


int ordenamientoInsertion( int arr[TAM]){
for (int i=1; i<TAM; i++){
    int temp = arr[i]; 
    int j = i - 1; 
 
    while ( (arr[j] > temp) && (j >= 0) ){
        arr[j+1] = arr[j];
        j--;
        arr[j+1] = temp;
    }
}
}
int ordenamientoSelection(int arr[TAM]){
    
    
    
    for (int i=0; i<TAM - 1; i++){ 

        
    int pos_men = Menor(arr,  i); //Menor es una funcion que regresa el elemnto menor
    int temp = arr[i]; 
    arr[i] = arr [pos_men];
    arr[pos_men] = temp;

    }  
}
int Menor(int arr[TAM],int i){
    int aux = 100;
    int posaux;
      for (; i<TAM  ; i++){ 
          
          if(aux > arr[i]){
              
           aux = arr[i];
           posaux = i;
           
              
          }
          
    
        
     } 
    return posaux; 
}
void ordenamientoQuicksort(int arr[TAM],int limite_izq,int limite_der)
{
    int izq,der,temporal,pivote;

    izq=limite_izq; 
    der = limite_der; 
    pivote = arr[(izq+der)/2];

    do{
        while(arr[izq]<pivote && izq<limite_der)izq++; //1
        while(pivote<arr[der] && der > limite_izq)der--;//2
        if(izq <=der)
        {
            temporal= arr[izq];
            arr[izq]=arr[der]; 
            arr[der]=temporal;
            izq++;
            der--;

        }

    }while(izq<=der);

    if(limite_izq<der){ordenamientoQuicksort(arr,limite_izq,der);}
    if(limite_der>izq){ordenamientoQuicksort(arr,izq,limite_der);}

}


