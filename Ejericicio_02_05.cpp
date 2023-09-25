// Materia: Programación I, Paralelo 1

// Autor: Alan Franz Flores Campos

// Fecha creación: 24/09/2023

// Fecha modificación: 24/09/2023

// Número de ejericio: 2

/* Problema planteado: De acuerdo con la siguiente estructura, realice en C++ un programa que lea N atletas y
nos devuelva el país que mayor número de medallas ha ganado. */

#include <iostream>
#include <cstring>
using namespace std;

struct Datos
{
    char nombre[40];
    char pais[25];
};

struct Atleta
{
    char deporte[30];
    Datos datosAtleta;
    int medallas;
};

void ingresarAtletas(Atleta atletas[], int n);

int main()
{
    int n;
    cout<<"Ingrese el numero de atletas: ";cin>>n;
    Atleta atletas[n];

    ingresarAtletas(atletas, n);

    // Encontrar el país con el mayor número de medallas
    char paisMayorMedallas[25];
    int maxMedallas=0, IndiceMaxMedallas=0;

    for (int i=0; i<n; i++)
    {
        if (atletas[i].medallas>maxMedallas)
        {
            maxMedallas=atletas[i].medallas;
            strcpy(paisMayorMedallas, atletas[i].datosAtleta.pais);
            IndiceMaxMedallas=i;
        }
    }
    cout<<"\n           DATOS DEL ATLETA CON MAYOR NUMERO DE MEDALLAS: "<<endl;
    cout<<"NOMBRE: "<<atletas[IndiceMaxMedallas].datosAtleta.nombre<<endl;
    cout<<"PAIS: "<<atletas[IndiceMaxMedallas].datosAtleta.pais<<endl;
    cout<<"DEPORTE: "<<atletas[IndiceMaxMedallas].deporte<<endl;
    cout<<"NUMERO DE MEDALLAS: "<<maxMedallas<<" medallas"<<endl;

    return 0;
}

void ingresarAtletas(Atleta atletas[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<"\nIngrese el nombre del atleta "<<i+1<<": ";
        cin.ignore();
        cin.getline(atletas[i].datosAtleta.nombre, sizeof(atletas[i].datosAtleta.nombre));

        cout<<"Ingrese el pais del atleta "<<i+1<<": ";
        cin.getline(atletas[i].datosAtleta.pais, sizeof(atletas[i].datosAtleta.pais));

        cout<<"Ingrese el deporte del atleta "<<i+1<<": ";
        cin.getline(atletas[i].deporte, sizeof(atletas[i].deporte));

        cout<<"Ingrese el numero de medallas ganadas por el atleta "<<i+1<<": ";
        cin>>atletas[i].medallas;
    }
}
