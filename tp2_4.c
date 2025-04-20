#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int N = 5;

struct {
    int velocidad; // Velocidad de procesamiento en GHz (valor entre 1 y 3)
    int anio; // Año de fabricación (valor entre 2015 y 2024)
    int cantidad_nucleos; // Cantidad de núcleos (valor entre 1 y 8)
    char *tipo_cpu; // Tipo de procesador (apuntador a cadena de caracteres)
}typedef compu;
   
void listarPCs(compu misCompus[],int cantidad);
void mostrarMasVieja(compu misCompus[], int cantidad);

int main()
{
    srand(time(NULL));
    compu misCompus[N];
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core","Pentium"};

    //Genera aleatoriamente las caracteristas de las N computadoras
    for (int i=0;i<N;i++)
    {
        misCompus[i].velocidad = rand()%3 + 1;
        misCompus[i].anio = rand()%10 + 2015;
        misCompus[i].cantidad_nucleos = rand()%8 + 1;
        misCompus[i].tipo_cpu = tipos[rand()%6];
    }
    return 0;
}

void listarPCs(compu misCompus[],int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        printf("--------- Computadora %d\n ---------",i+1);
        printf("velocidad: %d\n",misCompus[i].velocidad);
        printf("Anio: %d\n",misCompus[i].anio);
        printf("Cantidad de nucleos %d\n",misCompus[i].cantidad_nucleos);
        printf("Tipo de CPU: %s\n",misCompus[i].tipo_cpu);
    }
}

void mostrarMasVieja(compu misCompus[], int cantidad)
{
    compu masVieja;
    masVieja.anio = 2025;
    for (int i = 0; i < cantidad; i++)
    {
        if (misCompus[i].anio < masVieja.anio)
        {
            masVieja = misCompus[i];
        }
    }
    printf("Velocidad: %d \n", masVieja.velocidad);
    printf("Anio: %d \n",masVieja.anio);
    printf("Cantidad de Nucleos: %d\n",masVieja.cantidad_nucleos);
    printf("Tipo de cpu: %s\n",masVieja.tipo_cpu);
}