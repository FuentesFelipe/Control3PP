#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include "menu.h"
#include "Matriz.h"
#include <mpi.h>
#include <time.h>

int main(int argc, char** argv) {

    if (argc > 4) {
        std::string archivo_entrada(obtener_entrada(argv, argc));
        std::string archivo_salida(obtener_salida(argv, argc));

        if (!archivo_entrada.empty() && !archivo_salida.empty()) {

              int TAG = 0;                        // TAG
              int procesador = 0;
              int tamano = 0;

              MPI_Init(NULL, NULL);

              MPI_Comm_rank(MPI_COMM_WORLD, &procesador);
              MPI_Comm_size(MPI_COMM_WORLD, &tamano);

              std::ifstream entrada(archivo_entrada);
              std::ofstream salida(archivo_salida);
              std::string linea;

              while (std::getline(entrada, linea)) {
                // Procesador maestro
                if(procesador == 0){
                    MPI_Status status;

                  for(int fuente = 1; fuente < tamano; fuente++){
                      std::string linea;
                      MPI_Recv(&linea,linea.size(), MPI_CHAR,fuente, TAG, MPI_COMM_WORLD, &status);
                      salida.write(linea.c_str(), linea.size());
                      std::cerr << std::endl << "Recibiendo desde "<<fuente<<std::endl;
                      }
                }
                else{
                    for(int i = 0; i < tamano; i++){
                        Matriz matriz(linea);
                        if (matriz.esMagico()) {
                            std::string str = matriz.toString();
                            MPI_Send(&str,str.size(), MPI_CHAR, 0, 7, MPI_COMM_WORLD);
                            }
                        linea.clear();
                        }
                    }
              } // while
                  MPI_Finalize();
                  entrada.close();
                  salida.close();


            return EXIT_SUCCESS;
        } else {
            std::cerr << std::endl << "Error al determinar las rutas de los archivos de entrada " << archivo_entrada << " y salida " << archivo_salida << std::endl;
            return EXIT_FAILURE;

          }
    }
      else {
        std::cerr << std::endl << "Argumentos insuficientes" << std::endl;
        std::cerr << std::endl << argv[0] << " -f /ruta/archivo/entrada.txt -o /ruta/archivo/salida.txt" << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
  }
