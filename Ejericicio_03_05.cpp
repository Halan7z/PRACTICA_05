// Materia: Programación I, Paralelo 1

// Autor: Alan Franz Flores Campos

// Fecha creación: 24/09/2023

// Fecha modificación: 24/09/2023

// Número de ejericio: 3

/* Problema planteado: Realice un programa en C++ con funciones y estructuras para el estacionamiento del Multicine.
Este estacionamiento cuenta con 4 pisos, cada piso tiene distintas capacidades de autos
Piso 1 – 50 autos, Piso 2 – 40 autos, Piso 3 – 30 autos, Piso 4 – 45 autos
El estacionamiento debe recibir varios tipos de autos (vagoneta, camionetas,automóviles, minivans y motocicletas), marca del auto, modelo del auto y color del auto.
Escribir un programa en C++ utilizando funciones y estructuras para:
• Simular la entrada de vehículos, el programa debe pedir la cantidad de vehículos ingresados y el programa debe simular los tipos de vehículo, la
marca, el modelo, el color y en que piso se han estacionado.
• La simulación puede repetirse varias veces hasta que el usuario ingrese el valor de 0 (cero) en la cantidad de vehículos. La cantidad de vehículos debe se
incremental.
• Luego de cada ingreso de vehículos se desea saber cuantos hay estacionado en cada piso.
• Cuantos son vagoneta, camionetas, automóviles, minivans y motocicletas.
• Hacer un reporte por colores de autos, modelo y marca.
• La simulación debe determinar cuando el parqueo se ha llenado.
• La simulación debe determinar cuántos espacios libres queda. */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Vehiculo
{
    string tipo;
    string marca;
    string modelo;
    string color;
};

struct Piso
{
    int capacidad;
    int ocupados;
};

void ingresarVehiculos(Piso pisos[], int numPisos, int& totalEstacionados, vector<Vehiculo>& vehiculosEstacionados);

void imprimirReportePorTipo(const vector<Vehiculo>& vehiculosEstacionados);

void imprimirReportePorColorModeloMarca(const vector<Vehiculo>& vehiculosEstacionados);

int main()
{
    int totalEstacionados=0;
    vector<Vehiculo> vehiculosEstacionados;

    // definicion de las capacidades de los pisos dadas por el ejercicio
    Piso pisos[4]=
    {
        {50, 0},   // piso 1
        {40, 0},   // piso 2
        {30, 0},   // piso 3
        {45, 0}    // piso 4
    };

    // Inicio
    ingresarVehiculos(pisos, 4, totalEstacionados, vehiculosEstacionados);

    imprimirReportePorTipo(vehiculosEstacionados);

    imprimirReportePorColorModeloMarca(vehiculosEstacionados);

    // Verificar si el estacionamiento se llenó
    if (totalEstacionados==(pisos[0].capacidad+pisos[1].capacidad+pisos[2].capacidad+pisos[3].capacidad))
        cout<<"El estacionamiento se ha llenado."<<endl;
    else
    {
        int espaciosLibres=(pisos[0].capacidad+pisos[1].capacidad+pisos[2].capacidad+pisos[3].capacidad)-totalEstacionados;
        cout<<"\nEspacios libres en el estacionamiento: "<<espaciosLibres<<" autos"<<endl;
    }
    return 0;
}

void ingresarVehiculos(Piso pisos[], int numPisos, int& totalEstacionados, vector<Vehiculo>& vehiculosEstacionados)
{
    int cantidad;
    cout<<"Ingrese 1 para estacionar un vehiculo o 0 para salir: ";cin>>cantidad;

    while (cantidad>0)
    {
        Vehiculo vehiculo;
        cout<<"\nTipo de vehiculo (vagoneta, camioneta, deportivo, minivan, motocicleta): ";cin>>vehiculo.tipo;

        if (vehiculo.tipo=="0")
        {
            cout<<"Usted ingreso todos los vehiculos "<<endl;
            break;
        }

        cout<<"Marca del vehiculo: ";
        cin>>vehiculo.marca;
        cout<<"Modelo del vehiculo: ";
        cin>>vehiculo.modelo;
        cout<<"Color del vehiculo: ";
        cin>>vehiculo.color;

        // Encontrar un piso disponible
        bool estacionado=false;
        for (int i=0; i<numPisos; i++)
        {
            if (pisos[i].ocupados<pisos[i].capacidad)
            {
                pisos[i].ocupados++;
                totalEstacionados++;
                vehiculosEstacionados.push_back(vehiculo);
                estacionado=true;
                cout<<"El vehiculo ha sido estacionado en el Piso "<<i+1<<endl;
                break;
            }
        }
        if (!estacionado)
            cout << "El estacionamiento esta lleno."<<endl;

        cout<<"Cantidad de vehiculos en cada piso: "<<endl;
        for (int i=0; i<numPisos; i++)
            cout<<"Piso "<<i+1<< ": "<<pisos[i].ocupados<<" autos"<<endl;

        cout<<"\nIngrese 1 para estacionar un vehiculo o 0 para salir: ";cin>>cantidad;
    }
}

void imprimirReportePorTipo(const vector<Vehiculo>& vehiculosEstacionados)
{
    int vagonetas=0, camionetas=0, deportivos=0, minivans=0, motocicletas=0;

    for (const Vehiculo& vehiculo : vehiculosEstacionados)
    {
        if (vehiculo.tipo == "vagoneta")
            vagonetas++;
        else if (vehiculo.tipo=="camioneta")
            camionetas++;
        else if (vehiculo.tipo=="deportivo")
            deportivos++;
        else if (vehiculo.tipo=="minivan")
            minivans++;
        else if (vehiculo.tipo=="motocicleta")
            motocicletas++;
    }

    cout<<"Reporte por tipo de vehiculo:"<<endl;
    cout<<"Vagonetas: "<<vagonetas<<" autos"<<endl;
    cout<<"Camionetas: "<<camionetas<<" autos"<<endl;
    cout<<"Deportivos: "<<deportivos<<" autos"<<endl;
    cout<<"Minivans: "<<minivans<<" autos"<<endl;
    cout<<"Motocicletas: "<<motocicletas<<" autos"<<endl;
}

void imprimirReportePorColorModeloMarca(const vector<Vehiculo>& vehiculosEstacionados)
{
    cout << "\nReporte de los vehiculos:" << endl;
    for (const Vehiculo& vehiculo : vehiculosEstacionados)
        cout<<"Color: "<<vehiculo.color<<", Modelo: "<<vehiculo.modelo<<", Marca: "<<vehiculo.marca<<endl;
}
