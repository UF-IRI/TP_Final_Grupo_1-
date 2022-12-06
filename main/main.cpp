#include "iri.cpp"
#include<iostream>
#include "funciones.h"

using namespace std;

int main()
{
    string archivo_Consultas = "Consultas.csv";
    string archivo_Contactos = "Contactos.csv";
    string archivo_Medicos = "Medicos.csv";
    string archivo_Pacientes = "Pacientes.csv";
    string archivo_Obra_Social = "ObraSocial.csv";

    consultas_t* lista_de_consultas = nullptr;
    contactos_t* lista_de_contactos = nullptr;
    medicos_t* lista_de_medicos = nullptr;
    pacientes_t* lista_de_pacientes = nullptr;
    obra_social_t* lista_obra_social = nullptr;

    // cargo cada registro del archivo a su respectiva estructura
    lista_de_consultas = cargar_datos_de_un_archivo_a_una_estruct_consulta(archivo_Consultas, lista_de_consultas);
    lista_de_contactos = cargar_datos_de_un_archivo_a_una_estruct_contactos(archivo_Contactos, lista_de_contactos);
    lista_de_medicos = cargar_datos_de_un_archivo_a_una_estruct_medicos(archivo_Medicos, lista_de_medicos);
    lista_de_pacientes = cargar_datos_de_un_archivo_a_una_estruct_pacientes(archivo_Pacientes, lista_de_pacientes);
    lista_obra_social = cargar_datos_de_un_archivo_a_una_estruct_obra_social(archivo_Obra_Social, lista_obra_social);
    //-----------------------------------------------------------------------
    //tm fechainicializar = { 0,0,0,0,0,0,0,0 };
    historia_clinica_t aux_h = { " ", { 0,0,0,0,0,0,0,0,0 }, false, " ", ESTADO::niguno };
    int cant_irrecuperables = 0;
    historia_clinica_t* lista_historia_clinica_irrecuperables= new historia_clinica_t[cant_irrecuperables];

    int cant_de_contactos_secretaria = 0;
    contactos_t* lista_a_secretaria = new contactos_t[0];

    
    for (int i = 0; i < cantidad_de_registros(archivo_Consultas); i++)
    {
        if (verificar_tiempo_10anios(lista_de_consultas[i].dni_pac) == true)
        {
            aux_h.dni_paciente = lista_de_consultas[i].dni_pac;
            
            aux_h.fecha_ultima_cita.tm_mday = lista_de_consultas[i].fecha_turno.tm_mday;
            aux_h.fecha_ultima_cita.tm_mon = lista_de_consultas[i].fecha_turno.tm_mon;
            aux_h.fecha_ultima_cita.tm_year = lista_de_consultas[i].fecha_turno.tm_year;
            aux_h.cita_concurrida = lista_de_consultas[i].presento;
            aux_h.ultimo_medico = lista_de_consultas[i].matricula_med;
            for (int j = 0; j < cantidad_de_registros(archivo_Pacientes); j++)
            {
                if (lista_de_consultas[i].dni_pac==lista_de_pacientes[j].dni)
                {
                    aux_h.estado = lista_de_pacientes[j].estado;
                }
                else
                {
                    aux_h.estado = ESTADO::niguno;
                }
            }
            agregar_paciente_a_historia_clinica_irrecuperables(lista_historia_clinica_irrecuperables, aux_h, cant_irrecuperables);

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
                        cout << "el paciente esta muerto no enviar a secretaria. " << endl;
                    }
                    else if(lista_de_pacientes[j].estado == ESTADO::n_c)
                    {
                        cout << "no se sabe nada." << endl;
                    }
                }
            }
            mandar_archivo_a_secretaria(cantidad_de_registros(archivo_Consultas),cantidad_de_registros(archivo_Pacientes),lista_a_secretaria, cant_de_contactos_secretaria,lista_de_pacientes,lista_de_consultas);
        }
    }


    delete[] lista_de_consultas;
    delete[] lista_de_contactos;
    delete[] lista_de_medicos;
    delete[] lista_de_pacientes;
    delete[] lista_historia_clinica_irrecuperables;

    return 0;
}
