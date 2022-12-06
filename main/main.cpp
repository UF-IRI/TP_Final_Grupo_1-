#include "iri.cpp"
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
    string archivo_Obra_Social= "Pacientes.csv";

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
    historia_clinica_t aux;
    int cant_irrecuperables = 0;
    historia_clinica_t* lista_historia_clinica_irrecuperables= new historia_clinica_t[cant_irrecuperables];
    
    contactos_t aux;
    int cant_de_contactos_secretaria = 0;
    contactos_t* lista_a_secretaria = new contactos_t[0];

    
    for (int i = 0; i < cantidad_de_registros(archivo_Consultas); i++)
    {
        if (verificar_tiempo_10anios(lista_de_consultas[i].dni_pac) == true)
        {
            aux.dni_paciente = lista_de_consultas[i].dni_pac;
            
            aux.fecha_ultima_cita.tm_mday = lista_de_consultas[i].fecha_turno.tm_mday;
            aux.fecha_ultima_cita.tm_mon = lista_de_consultas[i].fecha_turno.tm_mon;
            aux.fecha_ultima_cita.tm_year = lista_de_consultas[i].fecha_turno.tm_year;
            aux.cita_concurrida = lista_de_consultas[i].presento;
            aux.ultimo_medico = lista_de_consultas[i].matricula_med;
            for (int j = 0; j < cantidad_de_registros(archivo_Pacientes); j++)
            {
                if (lista_de_consultas[i].dni_pac==lista_de_pacientes[j].dni)
                {
                    aux.estado = lista_de_pacientes[j].estado;
                }
                else
                {
                    aux.estado = ESTADO::niguno;
                }
            }
            agregar_paciente_a_historia_clinica_irrecuperables(lista_historia_clinica_irrecuperables, aux, cant_irrecuperables);

        } else//  pasaron menos de 10 años
        {
            for (int j = 0; j < cantidad_de_registros(archivo_Pacientes); j++)
            {
                if (lista_de_consultas[i].dni_pac == lista_de_pacientes[j].dni)
                {
                    if (lista_de_pacientes[j].estado==ESTADO::internado)
                    {
                        agregar_paciente_a_secretaria(lista_a_secretaria,lista_de_pacientes[j].dni,lista_de_contactos,cant_de_contactos_secretaria);
                    }
                    else if(lista_de_pacientes[j].estado == ESTADO::fallecido)
                    {

                    }
                    else if(lista_de_pacientes[j].estado == ESTADO::n_c)
                    {

                    }
                }
            }
            mandar_archivo_a_secretaria(lista_a_secretaria, cant_de_contactos_secretaria);
        }


    }


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
    delete[] lista_historia_clinica_irrecuperables;

    return 0;
}
