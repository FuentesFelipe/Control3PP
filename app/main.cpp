#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <fstream>
#include "menu.h"
#include "Matriz.h"
#include <mpi.h>

int main(int argc, char** argv) {

  MPI_Init(&argc, &argv);

  int world_size;
    // Get the number of processes
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Get the rank of the process
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    // Get the name of the processor
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);

    // Print off a hello world message
    printf("Hello world from processor %s, rank %d out of %d processors\n",
           processor_name, world_rank, world_size);

    // Finalize the MPI environment.
    MPI_Finalize();

    if (argc > 4) {
        std::string archivo_entrada(obtener_entrada(argv, argc));
        std::string archivo_salida(obtener_salida(argv, argc));

        if (!archivo_entrada.empty() && !archivo_salida.empty()) {

            std::ifstream entrada(archivo_entrada);
            std::ofstream salida(archivo_salida);
            std::string linea;
            while (std::getline(entrada, linea)) {
                Matriz matriz(linea);
                if (matriz.esMagico()) {
                    std::string str = matriz.toString();
                    salida.write(str.c_str(), str.size());
                }

                linea.clear();
            }

            entrada.close();
            salida.close();

            return EXIT_SUCCESS;
        } else {
            std::cerr << std::endl << "Error al determinar las rutas de los archivos de entrada " << archivo_entrada << " y salida " << archivo_salida << std::endl;
            return EXIT_FAILURE;
        }
    } else {
        std::cerr << std::endl << "Argumentos insuficientes" << std::endl;
        std::cerr << std::endl << argv[0] << " -f /ruta/archivo/entrada.txt -o /ruta/archivo/salida.txt" << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
