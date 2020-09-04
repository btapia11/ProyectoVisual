#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 20 //TAMAÑO DEL VECTOR

//estructura INTERNA
struct fecha{
    int mes;
    int dia;
    int anio;
};


//estructura EXTERNA
struct corredor{
  char nombre [50];
  int dorsal;
  struct fecha ingreso;
  char genero;
  int categoria;
}corredores[N];

//PROTOTIPo DE LA FUNCIÓN
void lectura_corredores(int nc); //se le pone un valor dentro de los parentesis porque voy a repetir un valor el teclado
void impresion_corredores(int nc); //Tambien se le podia mandar solo int
int aleatorio();

int aleatorio(){
  int test;
  srand(time(NULL));
  test = rand () % 9999;
  return test;
}
//DEFINICION de funciones




int main(){

  int bandera = 0;
  char nombre2[50];
  FILE* fichero;
  fichero = fopen("majo.txt", "w");
  int i = 0;

  while(bandera==0){
    printf("Ingrese su nombre:  ");
    scanf("%[^\n]",nombre2);//gets(nombre2);`
    fflush(stdin);

    if((strcmp(nombre2, "fin") == 0)||(strcmp(nombre2, "FIN") == 0))
      {
        bandera = 1;
      }
    else{
      strcpy(corredores[i].nombre, nombre2 );
      printf("\nIngrese la fecha del ultimo pago (mm/ dd/ aa):  \n");
      scanf("%d/%d/%d",&corredores[i].ingreso.mes,&corredores[i].ingreso.dia,&corredores[i].ingreso.anio);

      fichero = fopen("majo.txt", "a");
      fprintf(fichero,"%s   ",corredores[i].nombre);
      fprintf(fichero, "%c", '\n');
      fclose(fichero);
      

      bandera =0;
      i++;

    }

  
  }
      for(int j=0;j<i;j++){
          printf("%s \n",corredores[j].nombre);
        }
}
