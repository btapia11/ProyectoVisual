#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define AA 2020//año actual
#define N 100 //TAMAÑO DEL VECTOR

//estructura INTERNA
struct fecha{
    int mes;
    int dia;
    int anio;
};

struct tiempo{
    int hh;
    int mint;
    int ss;
};

struct prueba{
    char apellido_1 [50];
    char apellido_2 [50];
    char nombre_1 [50];
    char nombre_2 [50];
    char ingreso[50];
    char genero[50];
    char categoria[50];
    int dorsal;
    struct tiempo tp2;
}prueba[N],orden[6];

//estructura EXTERNA
struct corredor{
    char *p_nombre;
    int dorsal;
    struct fecha ingreso;
    char genero[2];
    char categoria[15];
    char *p_categoria;
    struct tiempo tp;
}corredores[N];

int i,j,k;
//PROTOTIPOS--------------------------------------------------------------------
int validar_fercha();
int validar_tiempo();
void Inscribir_Participantes();
void mostrar_corredor_sin_ordenar();
void registrar_tiempo_corredores();
void sub_menu();
void registrar_tiempos();

//DEFINICIONES-------------------------------------------------------------------
int validar_fecha(){
    int bandera=0;
    if(corredores[i].ingreso.anio == AA){
        if (corredores[i].ingreso.mes == 8 || corredores[i].ingreso.mes == 9){
            switch(corredores[i].ingreso.mes){
                case 8:
                    if(corredores[i].ingreso.dia == 31)
                        bandera = 1;
                    else
                        bandera = 0;
                    break;
                case 9:
                    if(corredores[i].ingreso.dia >= 1 && corredores[i].ingreso.dia <= 7)
                        bandera = 1;
                    else
                        bandera = 0;
                    break;
            }
        }
    }
    else{
        bandera = 0;
    }
    return bandera;
}

void Inscribir_Participantes(){
    int test,opc;
    int bandera = 0;
    int bandera2;
    char nombre2[50];

    i = 0;

    FILE *fichero;
    while(bandera==0){
        int tiempo_inicial=0;
        bandera2 = 0;
        int size;
        fflush(stdin);
        srand(time(NULL)); //Para reiniciar el contador de los valores randomicos.


        system("cls");
        printf("\n**INGRESE LOS DATOS DEL COMPETIDOR***\n\n");
        printf("\nIngrese su nombre completo(apellidos, nombres): ");
        gets(nombre2);
        strupr(nombre2);
        //scanf("%s",nombre2);//gets(nombre2);

        if(strcmp(nombre2,"FIN")==0)
        {
            bandera = 1;
        }
        else{
            test = rand () % 9999;
            size = strlen(nombre2);
            printf("%d",size);
            corredores[i].p_nombre = malloc(size * sizeof(char));

            if(NULL == corredores[i].p_nombre){
                printf("¨no se asigno memoria");
            }
            else{
                    strcpy(corredores[i].p_nombre, nombre2);
                    size = 0;

            }

            do{
                printf("Ingrese la fecha  (dd/ mm/ aaaa): ");
                scanf("%d/%d/%d",&corredores[i].ingreso.dia,&corredores[i].ingreso.mes,&corredores[i].ingreso.anio);
                fflush(stdin);
                if(validar_fecha()==0){
                    printf("FUERA DE LA FECHA DE INSCRIPCION!\n");
                }
            }while(validar_fecha()==0);
            corredores[i].dorsal = test;
            fflush(stdin);
            printf("Ingrese el genero (M-masculino, F-femenino): ");
            scanf("%c",corredores[i].genero);
            strupr(corredores[i].genero);

            while(bandera2==0){
                if((strcmp(corredores[i].genero,"F")==0) || (strcmp(corredores[i].genero,"M")==0)){
                    bandera2 = 1;
                   ;
                }
                else{
                    bandera2 = 0;
                    printf("Ingrese el genero correctamente (M-masculino, F-femenino): ");
                    scanf("%s",corredores[i].genero);
                    strupr(corredores[i].genero);
                }
            }
            fflush(stdin);

            sub_menu();
            corredores[i].tp.hh = 0;
            corredores[i].tp.mint = 0;
            corredores[i].tp.ss = 0;
            fichero = fopen("majo.txt", "a");
            fprintf(fichero,"%s\n",corredores[i].p_nombre);
            fprintf(fichero,"%d/%d/%d\n",corredores[i].ingreso.mes,corredores[i].ingreso.dia,corredores[i].ingreso.anio);
            fprintf(fichero,"%s\n",corredores[i].genero);
            fprintf(fichero,"%s\n",corredores[i].categoria);
            fprintf(fichero,"%d\n",corredores[i].dorsal);
            fprintf(fichero,"%d %d %d \n",corredores[i].tp.hh,corredores[i].tp.mint,corredores[i].tp.ss);
            fprintf(fichero, "%c", '\n');

            fclose(fichero);

            bandera =0;
            i++;
        }
    }
    for(j=0;j<i;j++){
    printf("%s \n",corredores[j].p_nombre);
    }
}

void mostrar_corredor_sin_ordenar(){
    char linea[1024];
    FILE *fich;
    fich = fopen("majo.txt", "r");

    if(fich == NULL){
        printf("ERROR: el archivo no existe \n");
    }
    else{
        while(fgets(linea, 1024, (FILE*) fich)) {
            printf(" %s ", linea);
        }
        fclose(fich);
    }
    //Lee línea a línea y escribe en pantalla hasta el fin de fichero
}

void registrar_tiempo_corredores(){
    FILE * fp;
    int bandera;
    i=0;
    fp = fopen ("majo.txt" , "r");
    if(fp == NULL){

        printf("   ERROR: NO EXISTE PARTICIPANTES EN LA CARRERA \n");

    }
    else{
        while(!feof(fp)){
                fscanf(fp,"%s",prueba[i].apellido_1);
                fscanf(fp,"%s",prueba[i].apellido_2);
                fscanf(fp,"%s",prueba[i].nombre_1);
                fscanf(fp,"%s",prueba[i].nombre_2);
                fscanf(fp,"%s",prueba[i].ingreso);
                fscanf(fp,"%s",prueba[i].genero);
                fscanf(fp,"%s",prueba[i].categoria);
                fscanf(fp,"%i",&prueba[i].dorsal);
                fscanf(fp,"%i",&prueba[i].tp2.hh);
                fscanf(fp,"%i",&prueba[i].tp2.mint);
                fscanf(fp,"%i",&prueba[i].tp2.ss);
                i++;

        }
        fclose(fp);
    }

    fp = fopen ("majo.txt" , "w");

    for(int j = 0 ; j<i-1;j++){
            bandera = 0;
            fprintf(fp,"%s %s %s %s \n",prueba[j].apellido_1,prueba[j].apellido_2,prueba[j].nombre_1,prueba[j].nombre_2);
            fprintf(fp,"%s\n",prueba[j].ingreso);
            fprintf(fp,"%s \n",prueba[j].genero);
            fprintf(fp,"%s\n",prueba[j].categoria);
            fprintf(fp,"%d\n",prueba[j].dorsal);
            printf("Ingrese el tiempo del participante [hh:mm:ss] \n %s %s %s %s \n",prueba[j].apellido_1,prueba[j].apellido_2,prueba[j].nombre_1,prueba[j].nombre_2);
            scanf("%d:%d:%d",&prueba[j].tp2.hh,&prueba[j].tp2.mint,&prueba[j].tp2.ss);

            while(bandera==0){
                printf("entra");
                if((prueba[j].tp2.hh >= 0 && prueba[j].tp2.hh<=23) && (prueba[j].tp2.mint >= 0 && prueba[j].tp2.mint <=59)&& (prueba[j].tp2.ss >= 0 && prueba[j].tp2.ss <=59) ){
                    printf("entra");
                    bandera=1;
                }
                else{
                    printf("ERROR: Ingrese el tiempo del participante [hh:mm:ss] \n %s %s %s %s \n ",prueba[j].apellido_1,prueba[j].apellido_2,prueba[j].nombre_1,prueba[j].nombre_2);
                    scanf("%d:%d:%d",&prueba[j].tp2.hh,&prueba[j].tp2.mint,&prueba[j].tp2.ss);
                    bandera= 0;
                }

            }

            fprintf(fp,"%i %i %i \n",prueba[j].tp2.hh,prueba[j].tp2.mint,prueba[j].tp2.ss);
            fprintf(fp,"%c",'\n');

    }

    fclose(fp);


}
void limpiar_genero(){

    for(int i=0;i<6;i++){
        strcpy(orden[i].apellido_1," ");
        strcpy(orden[i].apellido_2," ");
        strcpy(orden[i].nombre_1," ");
        strcpy(orden[i].nombre_2," ");
        orden[i].tp2.hh =0;
        orden[i].tp2.mint =0;
        orden[i].tp2.ss =0;

    }
}
void asignacion(int i){
    int cont1 = 0;
    int cont2 = 0;
    printf("________________________________________________________________________________\n");
    printf("\t\t\t CUADRO FINAL DE PREMIOS 10K          \t\t\n\n");
    printf("________________________________________________________________________________\n");
    printf("\t\t\t      CATEGORIA:JUVENIL\n\n");

    for(int j=0;j<i-1;j++){
        if(strcmp(prueba[j].categoria,"JUVENIL")==0){
            if((strcmp(prueba[j].genero,"F")==0) && cont1 <3 ){
                orden[cont1] = prueba[j];
                cont1++;
            }

            else
                if((strcmp(prueba[j].genero,"M")==0) && cont2 < 3){
                    orden[cont2+3] = prueba[j];
                    cont2++;
                }
        }
    }
        imprimir();
        limpiar_genero();
        cont1=0;
        cont2=0;

        // ************************************************************//
        printf("________________________________________________________________________________\n");
        printf("\n\t\t\t      CATEGORIA:ELITE \n\n");
        for(int j=0;j<i-1;j++){
            if(strcmp(prueba[j].categoria,"ELITE")==0){
                if((strcmp(prueba[j].genero,"F")==0) && cont1 <3 ){
                    orden[cont1] = prueba[j];
                    cont1++;
                }

                else
                    if((strcmp(prueba[j].genero,"M")==0) && cont2 < 3){
                        orden[cont2+3] = prueba[j];
                        cont2++;
                    }
            }
        }
        imprimir();
        limpiar_genero();
        cont1=0;
        cont2=0;

        //***********************************************************//
        printf("________________________________________________________________________________\n");
        printf("\n\t\t\t      CATEGORIA:MASTER \n\n");
        for(int j=0;j<i-1;j++){
            if(strcmp(prueba[j].categoria,"MASTER")==0){
                if((strcmp(prueba[j].genero,"F")==0) && cont1 <3 ){
                    orden[cont1] = prueba[j];
                    cont1++;
                }

                else
                    if((strcmp(prueba[j].genero,"M")==0) && cont2 < 3){
                        orden[cont2+3] = prueba[j];
                        cont2++;
                    }
            }
        }
        imprimir();
        limpiar_genero();
        cont1=0;
        cont2=0;

        //*****************************************************//
        printf("________________________________________________________________________________\n");
        printf("\n\t\t\t      CATEGORIA:SUPERMASTER \n\n");
        for(int j=0;j<i-1;j++){
            if(strcmp(prueba[j].categoria,"SUPERMASTER")==0){
                if((strcmp(prueba[j].genero,"F")==0) && cont1 <3 ){
                    orden[cont1] = prueba[j];
                    cont1++;
                }

                else
                    if((strcmp(prueba[j].genero,"M")==0) && cont2 < 3){
                        orden[cont2+3] = prueba[j];
                        cont2++;
                    }
            }
        }
        imprimir();
        limpiar_genero();
        cont1=0;
        cont2=0;

        //******************************************************//
        printf("________________________________________________________________________________\n");
        printf("\n\t\t\t      CATEGORIA:DISCAPACITADOS \n\n");
        for(int j=0;j<i-1;j++){
            if(strcmp(prueba[j].categoria,"DISCAPACITADOS")==0){
                if((strcmp(prueba[j].genero,"F")==0) && cont1 <3 ){
                    orden[cont1] = prueba[j];
                    cont1++;
                }

                else
                    if((strcmp(prueba[j].genero,"M")==0) && cont2 < 3){
                        orden[cont2+3] = prueba[j];
                        cont2++;
                    }
            }
        }
        imprimir();
        printf("________________________________________________________________________________\n");
}
void ordenar_posiciones(int i){
    struct prueba aux;
    int h1,m1,s1,r1,h2,m2,s2,r2;
        for(int j=1;j<i-1;j++){
            for(int k=1;k<i-1;k++){
                    h1=prueba[k].tp2.hh*3600;
                    m1=prueba[k].tp2.mint*60;
                    s1=prueba[k].tp2.ss;
                    r1=h1+m1+s1;
                    h2=prueba[k-1].tp2.hh*3600;
                    m2=prueba[k-1].tp2.mint*60;
                    s2=prueba[k-1].tp2.ss;
                    r2=h2+m2+s2;
                    if(r1<r2){
                        aux = prueba[k-1];
                        prueba[k-1]=prueba[k];
                        prueba[k]=aux;
                    }
                    h1=0,m1=0,s1=0,r1=0,h2=0,m2=0,s2=0,r2=0;
            }
        }


}
void imprime_mejores_corredores(){

    FILE * fp;
    i=0;
    fp = fopen ("majo.txt" , "r");
    if(fp == NULL){

        printf("   ERROR: NO EXISTE PARTICIPANTES EN LA CARRERA \n");

    }
    else{
        while(!feof(fp)){
                fscanf(fp,"%s",prueba[i].apellido_1);
                fscanf(fp,"%s",prueba[i].apellido_2);
                fscanf(fp,"%s",prueba[i].nombre_1);
                fscanf(fp,"%s",prueba[i].nombre_2);
                fscanf(fp,"%s",prueba[i].ingreso);
                fscanf(fp,"%s",prueba[i].genero);
                fscanf(fp,"%s",prueba[i].categoria);
                fscanf(fp,"%i",&prueba[i].dorsal);
                fscanf(fp,"%i",&prueba[i].tp2.hh);
                fscanf(fp,"%i",&prueba[i].tp2.mint);
                fscanf(fp,"%i",&prueba[i].tp2.ss);
                i++;

        }
        ordenar_posiciones(i);
        asignacion(i);
    }
}

void imprimir(){
    printf("________________________________________________________________________________\n");
    printf("Ubicacion   \tHOMBRE\t   TIEMPO(hh:min:ss) \tMUJER\t    TIEMPO(hh:min:ss)\n");
    printf("________________________________________________________________________________\n");
    printf("PRIMERO      %5s %5s     %d:%d:%d        %5s %5s     %d:%d:%d \n",orden[3].apellido_1,orden[3].apellido_2,orden[3].tp2.hh,orden[3].tp2.mint,orden[3].tp2.ss,orden[0].apellido_1,orden[0].apellido_2,orden[0].tp2.hh,orden[0].tp2.mint,orden[0].tp2.ss);
    printf("             %5s %5s                     %5s %5s%            \n",orden[3].nombre_1,orden[3].nombre_2,orden[0].nombre_1,orden[0].nombre_2);
    printf("________________________________________________________________________________\n");
    printf("SEGUNDO      %5s %5s     %d:%d:%d       %5s %5s    %d:%d:%d \n",orden[4].apellido_1,orden[4].apellido_2,orden[4].tp2.hh,orden[4].tp2.mint,orden[4].tp2.ss,orden[1].apellido_1,orden[1].apellido_2,orden[1].tp2.hh,orden[1].tp2.mint,orden[1].tp2.ss);
    printf("             %5s %5s                     %5s %5s%            \n",orden[4].nombre_1,orden[4].nombre_2,orden[1].nombre_1,orden[1].nombre_2);
    printf("________________________________________________________________________________\n");
    printf("TERCERO      %5s %5s     %d:%d:%d       %5s %5s    %d:%d:%d \n",orden[5].apellido_1,orden[5].apellido_2,orden[5].tp2.hh,orden[5].tp2.mint,orden[5].tp2.ss,orden[2].apellido_1,orden[2].apellido_2,orden[2].tp2.hh,orden[2].tp2.mint,orden[2].tp2.ss);
    printf("             %5s %5s                     %5s %5s%            \n",orden[5].nombre_1,orden[5].nombre_2,orden[2].nombre_1,orden[2].nombre_2);
}

void sub_menu(){
    int opc;
    do{
    printf("Seleccione el numero segun su categoria:\n");
    printf("\t[1]. Juvenil (12 - 19 anios)\n");
    printf("\t[2]. Elite (20 - 39 anios)\n");
    printf("\t[3]. Master (40 - 59 anios)\n");
    printf("\t[4]. Supermaster (60 anios en adelante)\n");
    printf("\t[5]. Discapacitados (60 anios en adelante)\n");
    scanf("%i",&opc);
        printf("ERROR. Seleccione el numero segun su categoria:\n");
        switch(opc){
            case 1:
                strcpy(corredores[i].categoria,"JUVENIL");
                break;
            case 2:
                strcpy(corredores[i].categoria,"ELITE");
                break;
            case 3:
                strcpy(corredores[i].categoria,"MASTER");
                break;
            case 4:
                strcpy(corredores[i].categoria,"SUPERMASTER");
                break;
            case 5:
                strcpy(corredores[i].categoria,"DISCAPACITADOS");
                break;
        }
    }while(opc!=5 && opc!=4 && opc!=3 && opc!=2 && opc!=1);

}

void contador_caregoria(){
    FILE * fp;
    int jub_f=0,jub_m=0,e_f=0,e_m=0,m_f=0,m_m=0,s_f=0,s_m=0,d_f=0,d_m=0;
    i=0;
    fp = fopen("majo.txt" , "r");
    if(fp != NULL){

            while(!feof(fp)){
                fscanf(fp,"%s",prueba[i].apellido_1);
                fscanf(fp,"%s",prueba[i].apellido_2);
                fscanf(fp,"%s",prueba[i].nombre_1);
                fscanf(fp,"%s",prueba[i].nombre_2);
                fscanf(fp,"%s",prueba[i].ingreso);
                fscanf(fp,"%s",prueba[i].genero);
                fscanf(fp,"%s",prueba[i].categoria);
                fscanf(fp,"%i",&prueba[i].dorsal);
                fscanf(fp,"%i",&prueba[i].tp2.hh);
                fscanf(fp,"%i",&prueba[i].tp2.mint);
                fscanf(fp,"%i",&prueba[i].tp2.ss);
                i++;

        }
        fclose(fp);
        for(int j = 0;j<i;j++){

            if(strcmp(prueba[j].categoria,"JUVENIL")==0){
                if(strcmp(prueba[j].genero,"F")==0)
                    jub_f++;
                else
                    if(strcmp(prueba[j].genero,"M")==0)
                    jub_m++;
            }

            if(strcmp(prueba[j].categoria,"ELITE")==0){
                if(strcmp(prueba[j].genero,"F")==0)
                    e_f++;
                else
                    if(strcmp(prueba[j].genero,"M")==0)
                    e_m++;
            }
            if(strcmp(prueba[j].categoria,"MASTER")==0){
                if(strcmp(prueba[j].genero,"F")==0)
                    m_f++;
                else
                    if(strcmp(prueba[j].genero,"M")==0)
                    m_m++;

            }
            if(strcmp(prueba[j].categoria,"SUPERMASTER")==0){
                if(strcmp(prueba[j].genero,"F")==0)
                    s_f++;
                else
                    if(strcmp(prueba[j].genero,"M")==0)
                    s_m++;

            }

            if(strcmp(prueba[j].categoria,"DISCAPACITADOS")==0){
                if(strcmp(prueba[j].genero,"F")==0)
                    d_f++;
                else
                    if(strcmp(prueba[j].genero,"M")==0)
                    d_m++;

            }
        }
        printf("_______________________________________________________________________________\n");
        printf("\n  \t                  CARRERA 10K               ");
        printf("\n\t             INSCRITOS POR CATEORIA               \n");
        printf("_______________________________________________________________________________\n");
        printf("\nCATEGORIA  \t\t   TOTAL HOMBRES  \t\t   TOTAL MUJERES \n");
        printf("_______________________________________________________________________________\n");
        printf("JUVENILES       \t       %d    \t\t\t\t%d\n", jub_m,jub_f);
        printf("_______________________________________________________________________________\n");
        printf("ELITE           \t       %d    \t\t\t\t%d\n",  e_m,e_f);
        printf("_______________________________________________________________________________\n");
        printf("MASTER          \t       %d    \t\t\t\t%d\n",  m_m,m_f);
        printf("_______________________________________________________________________________\n");
        printf("SUPERMASTER     \t       %d    \t\t\t\t%d\n", s_m,s_f);
        printf("_______________________________________________________________________________\n");
        printf("DISCAPACITADOS  \t       %d    \t\t\t\t%d\n", d_m,d_f);
        printf("_______________________________________________________________________________\n");
        printf("\n\t \t Total de inscritos                : %i \n",i-1);
        printf("_______________________________________________________________________________\n");



    }
    else{
            printf("   ERROR: NO EXISTE PARTICIPANTES EN LA CARRERA \n");

    }
}


void nomina_incritos(){
    FILE * fp;
    i=0;
    struct tiempo tp[N];
    fp = fopen ("majo.txt" , "r");
    if(fp == NULL){
        printf("   ERROR: NO EXISTE PARTICIPANTES EN LA CARRERA \n");
    }
    else{
        while(!feof(fp)){
                fscanf(fp,"%s",prueba[i].apellido_1);
                fscanf(fp,"%s",prueba[i].apellido_2);
                fscanf(fp,"%s",prueba[i].nombre_1);
                fscanf(fp,"%s",prueba[i].nombre_2);
                fscanf(fp,"%s",prueba[i].ingreso);
                fscanf(fp,"%s",prueba[i].genero);
                fscanf(fp,"%s",prueba[i].categoria);
                fscanf(fp,"%i",&prueba[i].dorsal);
                fscanf(fp,"%i",&prueba[i].tp2.hh);
                fscanf(fp,"%i",&prueba[i].tp2.mint);
                fscanf(fp,"%i",&prueba[i].tp2.ss);
                i++;

        }
        fclose(fp);
        struct prueba aux;
        for(int j = 0;j<i-1;j++){
            for(int k = 0;k<i-1;k++){
                if(strcmp(prueba[k-1].apellido_1,prueba[k].apellido_1)>0){
                    aux = prueba[k-1];
                    prueba[k-1]=prueba[k];
                    prueba[k]=aux;
                }

            }

        }
        char barra[]={"|"};
        printf("_______________________________________________________________________________\n");
        printf("\n\t\tCARRERA 10K-FUNDACION VIRGEN DE LA MERCED \n");
        printf("_______________________________________________________________________________\n");
        printf("\n\t\tNOMINA INSCRITOS <<MUJERES/HOMBRE>>\n");
        printf("_______________________________________________________________________________\n");
        printf("\nORD.\t\t\tAPELLIDOS Y NOMBRES\t\tNUMERO DE DORSAL \n");
        for(int t = 0 ;t < i-1; t++){
            printf("_______________________________________________________________________________\n");
            printf(" %d",t+1);
            printf(" %*s",5,barra);
            printf("\t%s %s %s %s ",prueba[t].apellido_1,prueba[t].apellido_2,prueba[t].nombre_1,prueba[t].nombre_2);
            printf("\t\t%d \n",prueba[t].dorsal);
        }
        printf("_______________________________________________________________________________\n");
    }


}

//FUNCIÓN PRINCIPAL
int main(){
    char repite = 1;
    int opcion = -1;
    do {
        system("cls");
        printf("\n\t\t\t\t*MARATON 10K QUITO*\n");
        printf("\t \t \t  >> Fundacion Virgen de la Merced <<\n");
        printf("\n\t\t[1]. Registrar corredor \n");
        printf("\t\t[2]. Mostrar listado de Corredores (sin ordenar) \n");
        printf("\t\t[3]. Registrar tiempo de los corredores\n");
        printf("\t\t[4]. Inscritos por Categoria\n");
        printf("\t\t[5]. Mejores Corredores\n");
        printf("\t\t[6]. Nomina inscritos <<MUJERES Y HOMBRES>>\n");
        printf("\t\t[7]. Salir\n");

        printf("\n\t\tIngrese su opcion: [ ]\b\b");
        // Lectura segura de un entero
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                Inscribir_Participantes();
                break;
            case 2:
                mostrar_corredor_sin_ordenar();
                break;
            case 3:
                registrar_tiempo_corredores();
                break;
            case 4:
                contador_caregoria();
                break;
            case 5:
                imprime_mejores_corredores();
                break;
            case 6:
                nomina_incritos();
                break;
            case 7:
                repite = 0;
                break;

            }
        system("pause");
    } while (repite);
}

