// Materia: Programación I, Paralelo 1

// Autor: Alan Franz Flores Campos

// Fecha creación: 24/09/2023

// Fecha modificación: 24/09/2023

// Número de ejericio: 1

/* Problema planteado: La información de todos los empleados de la UCB se almacena en una variable tipo struct llamada “empleado”.
La información con que se cuenta es: nombre, ci, departamento y salario.
Realizar un programa en C++ que lea un array de estructura de los datos de N empleados e imprima los siguiente:
• Empleado con mayor salario
• Empleado con menor salario
• Promedio salarial
• Promedio por departamento
• Departamento con mayor salario en promedio
• Departamento con menor salario en promedio */
#include <iostream>
#include <string>
using namespace std;
struct empleado
{
    string nombre;
    string ci;
    string departamento;
    int salario;
};
int main()
{
    int n;
    cout<<"Ingrese el numero de empleados a almacenar: ";cin>>n;
    empleado empleados[n];
    for (int i=0; i<n; i++)
    {
        cout<<"\nIngrese el nombre del empleado "<<i+1<<" : ";cin>>empleados[i].nombre;
        cout<<"Ingrese el CI del empleado "<<i+1<<" : ";cin>>empleados[i].ci;
        cout<<"Ingrese el departamento del empleado "<<i+1<<" : ";cin.ignore(); // Para evitar problemas con la lectura de la cadena
        getline(cin, empleados[i].departamento);
        cout<<"Ingrese el salario del empleado "<<i+1<<" : ";cin>>empleados[i].salario;
    }
    // Empleado con el mayor salario:
    int salarioMayor = empleados[0].salario;
    int indiceEmpleadoMayorSalario = 0;
    for (int i = 1; i < n; i++)
    {
        if (empleados[i].salario > salarioMayor)
        {
            salarioMayor = empleados[i].salario;
            indiceEmpleadoMayorSalario = i;
        }
    }

    // Empleado con el menor salario:
    int salarioMenor = empleados[0].salario;
    int indiceEmpleadoMenorSalario = 0;
    for (int i = 1; i < n; i++)
    {
        if (empleados[i].salario < salarioMenor)
        {
            salarioMenor = empleados[i].salario;
            indiceEmpleadoMenorSalario = i;
        }
    }
    //Promedio salarial:
    int promedio=0;
    for (int i=0; i<n; i++)
    {
        promedio+=empleados[i].salario;
    }
    // Promedio por departamento:
    double promedioDepartamento[9] = {0.0};
    int contadorDepartamento[9] = {0};
    for (int i = 0; i < n; i++) {
        if (empleados[i].departamento == "La Paz") {
            promedioDepartamento[0] += empleados[i].salario;
            contadorDepartamento[0]++;
        } else if (empleados[i].departamento == "Oruro") {
            promedioDepartamento[1] += empleados[i].salario;
            contadorDepartamento[1]++;
        } else if (empleados[i].departamento == "Potosí") {
            promedioDepartamento[2] += empleados[i].salario;
            contadorDepartamento[2]++;
        } else if (empleados[i].departamento == "Cochabamba") {
            promedioDepartamento[3] += empleados[i].salario;
            contadorDepartamento[3]++;
        } else if (empleados[i].departamento == "Chuquisaca") {
            promedioDepartamento[4] += empleados[i].salario;
            contadorDepartamento[4]++;
        } else if (empleados[i].departamento == "Tarija") {
            promedioDepartamento[5] += empleados[i].salario;
            contadorDepartamento[5]++;
        } else if (empleados[i].departamento == "Santa Cruz") {
            promedioDepartamento[6] += empleados[i].salario;
            contadorDepartamento[6]++;
        } else if (empleados[i].departamento == "Beni") {
            promedioDepartamento[7] += empleados[i].salario;
            contadorDepartamento[7]++;
        } else if (empleados[i].departamento == "Pando") {
            promedioDepartamento[8] += empleados[i].salario;
            contadorDepartamento[8]++;
        }
    }

    for (int i = 0; i < 9; i++) {
        if (contadorDepartamento[i] > 0) {
            promedioDepartamento[i] /= contadorDepartamento[i];
        }
    }

    // Encontrar el departamento con mayor salario en promedio:
    double mayorSalarioPromedio = promedioDepartamento[0];
    string departamentoMayorSalario = "La Paz";
    for (int i = 1; i < 9; i++) {
        if (promedioDepartamento[i] > mayorSalarioPromedio) {
            mayorSalarioPromedio = promedioDepartamento[i];
            if (i == 0) departamentoMayorSalario = "La Paz";
            else if (i == 1) departamentoMayorSalario = "Oruro";
            else if (i == 2) departamentoMayorSalario = "Potosí";
            else if (i == 3) departamentoMayorSalario = "Cochabamba";
            else if (i == 4) departamentoMayorSalario = "Chuquisaca";
            else if (i == 5) departamentoMayorSalario = "Tarija";
            else if (i == 6) departamentoMayorSalario = "Santa Cruz";
            else if (i == 7) departamentoMayorSalario = "Beni";
            else if (i == 8) departamentoMayorSalario = "Pando";
        }
    }

    // Encontrar el departamento con menor salario en promedio:
    double menorSalarioPromedio = promedioDepartamento[0];
    string departamentoMenorSalario = "La Paz";
    for (int i = 1; i < 9; i++) {
        if (promedioDepartamento[i] < menorSalarioPromedio) {
            menorSalarioPromedio = promedioDepartamento[i];
            if (i == 0) departamentoMenorSalario = "La Paz";
            else if (i == 1) departamentoMenorSalario = "Oruro";
            else if (i == 2) departamentoMenorSalario = "Potosí";
            else if (i == 3) departamentoMenorSalario = "Cochabamba";
            else if (i == 4) departamentoMenorSalario = "Chuquisaca";
            else if (i == 5) departamentoMenorSalario = "Tarija";
            else if (i == 6) departamentoMenorSalario = "Santa Cruz";
            else if (i == 7) departamentoMenorSalario = "Beni";
            else if (i == 8) departamentoMenorSalario = "Pando";
        }
    }

    // Resultados:
    cout << "\nEmpleado con mayor salario:" << endl;
    cout << "Nombre: " << empleados[indiceEmpleadoMayorSalario].nombre << endl;
    cout << "CI: " << empleados[indiceEmpleadoMayorSalario].ci << endl;
    cout << "Departamento: " << empleados[indiceEmpleadoMayorSalario].departamento << endl;
    cout << "Salario: " << empleados[indiceEmpleadoMayorSalario].salario << endl;

    cout << "\nEmpleado con menor salario:" << endl;
    cout << "Nombre: " << empleados[indiceEmpleadoMenorSalario].nombre << endl;
    cout << "CI: " << empleados[indiceEmpleadoMenorSalario].ci << endl;
    cout << "Departamento: " << empleados[indiceEmpleadoMenorSalario].departamento << endl;
    cout << "Salario: " << empleados[indiceEmpleadoMenorSalario].salario << endl;

    cout << "\nPromedio salarial: " <<promedio/n<< endl;

    cout << "\nPromedio por departamento:" << endl;
    for (int i = 0; i < 9; i++) {
        if (contadorDepartamento[i] > 0) {
            cout << "Departamento ";
            if (i == 0) cout << "La Paz: ";
            else if (i == 1) cout << "Oruro: ";
            else if (i == 2) cout << "Potosí: ";
            else if (i == 3) cout << "Cochabamba: ";
            else if (i == 4) cout << "Chuquisaca: ";
            else if (i == 5) cout << "Tarija: ";
            else if (i == 6) cout << "Santa Cruz: ";
            else if (i == 7) cout << "Beni: ";
            else if (i == 8) cout << "Pando: ";
            cout << promedioDepartamento[i] << endl;
        }
    }

    cout << "\nDepartamento con mayor salario en promedio: " << departamentoMayorSalario << endl;
    cout << "Departamento con menor salario en promedio: " << departamentoMenorSalario << endl;

    return 0;
}
