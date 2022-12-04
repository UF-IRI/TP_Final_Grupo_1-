//#include "iri.cpp"
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "funciones.h"
//#include <ctime>

using namespace std;

int main()
{
    string archivo_Consultas = "Consultas.csv";
    string archivo_Contactos = "Contactos.csv";
    string archivo_Medicos = "Medicos.csv";
    string archivo_Pacientes = "Pacientes.csv";

    consultas_t* lista_de_consultas = nullptr;
    contactos_t* lista_de_contactos = nullptr;
    medicos_t* lista_de_medicos = nullptr;
    pacientes_t* lista_de_pacientes = nullptr;
    // cargo cada registro del archivo a su respectiva estructura
    lista_de_consultas = cargar_datos_de_un_archivo_a_una_estruct_consulta(archivo_Consultas, lista_de_consultas);
    lista_de_contactos = cargar_datos_de_un_archivo_a_una_estruct_contactos(archivo_Contactos, lista_de_contactos);
    lista_de_medicos = cargar_datos_de_un_archivo_a_una_estruct_medicos(archivo_Medicos, lista_de_medicos);
    lista_de_pacientes = cargar_datos_de_un_archivo_a_una_estruct_pacientes(archivo_Pacientes, lista_de_pacientes);
    //-----------------------------------------------------------------------

    //f(verificar_tiempo_10anios(aux_h) == verdadero)
    //{
    //    agregar_un_paciente_al_archivo(aux_p[j]);
    //}
    //    else
    //    {
    //    estado_paciente = revisar_estado(aux_h[j])
    //        if (estado_paciente == 0 || estado_paciente == 1)
    //        {
    //            guardar_secretaria(aux_u[j])
    //        }
    //        else if (estado_paciente == 2)
    //        {
    //            agregar_un_paciente_al_archivo(aux_p[j]);
    //        }
    //    }




    // libero la memoria pedida.
    delete[] lista_de_consultas;
    delete[] lista_de_contactos;
    delete[] lista_de_medicos;
    delete[] lista_de_pacientes;

    return 0;
}
