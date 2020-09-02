#include <stdio.h>
#include <string.h>

int main()
{
    int valores[6];
    int test, i = 0;
    int n,bandera=1;
    char nombre[60];

    while(bandera==1){
        fflush(stdin);
        printf("ingrese un nombre o fin (FIN) para terminar");
        scanf("%s",nombre);
        //strcmp(res, "No") != 0;//Con este podemos comparar cadenas

        if(nombre!="fin" || nombre!="FIN"){

            bandera=1;
            srand(time(NULL));
            test = rand () % 9999;
            valores[i] = test;
            printf("%d",test);
            i = i+1;
        }
        else{
            bandera= 0;
            for(int j = 0;j<i;j++){
                printf("%d \t",valores[j]);
        }

        }


    }

    return 0;
}

