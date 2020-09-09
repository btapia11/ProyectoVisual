# ProyectoVisual
La Fundación Virgen de la Merced requiere un aplicación en C que almacene los datos de los participantes que se inscriben para la vuelta 10k en Quito a llevarse a efecto el 19 de Septiembre de 2020, el plazo para inscribirse será del 31 de Agosto de 2020 al 07 de Septiembre del 2020, registre el tiempo de la carrera e imprima: La nómina de los inscritos por categoría y el resultados de los tres primeros puestos por categoría correspondientes, para dicho efecto se solicita: 

1. Diseñe  y defina una estructura que contenga los datos de los participantes, usando de forma obligatoria la estructura struct tiempo y struct fecha. 
2. Realice una función inscribir_participante, la cual registra el nombre, número de dorsal (valor aleatoria), fecha de inscripción, genero (M- masculino, F- femenino) y categoría. 

Las categorías que debe mostrar al usuario son: 
1. Juvenil (12 a 19 años) 
2. Elite (20 a 39 años) 
3. Máster (40 a 59 años) 
4. Supermáster (60 años en adelante) 
5. Discapacitados 

El proceso continuará hasta que el nombre de un participante comience con los caracteres FIN (tanto en mayúsculas como en minúsculas). Cuando se encuentre FIN, se escribirá en el archivo de datos  inscripción.txt. 

3. Realice una función registrar_tiempo, la cual  permitirá actualizar el archivo que contiene a los inscritos para registrar el tiempo que ha realizado en la carrera de acuerdo a su categoría (horas, minutos y segundos). 

4. Realice el procedimiento imprime_inscritos_categoria, que muestre por pantalla el total de hombres y mujeres de inscritos por categoría

5. Realice el procedimiento imprime_mejores_corredores, la cual debe mostrar en pantalla los tres mejores corredores por categoría.

6. Realice el procedimiento imprime_inscritos, la cual debe mostrar en pantalla de acuerdo a la selección realizada la nómina de los hombres o mujeres inscritos ordenados alfabéticamente, utilizando el método por inserción. 

7. Realice el programa principal en C que llame a las funciones/procedimientos correspondientes utilizando un menú de opciones debidamente validado. 
