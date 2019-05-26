# Control 3 Paralela
Intento de Paralelización de algoritmo en C++ 
que a partir de un txt con matrices representadas linealmente
genera otro igual pero excluyendo toda matriz que en la suma de 
elementos por filas, columnas y diagonales no tengan los mismos
resultados entre ellas.

### Instalación:
* $ git clone https://github.com/FuentesFelipe/Control3P.git

### Compilación y ejecución:

* $ cd app
* $ make
* $ cd dist
* $ ./programa -f /home/usuario/ruta_archivo.txt -o /home/usuario/ruta_salida_archivo.txt 
 -np número procesadores --hostfile maquinas.txt
 
 Se puede modificar el archivo maquinas.txt con las direcciones IP correspondientes
 
 


