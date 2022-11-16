#include "iri.cpp"
#include <cstdlib>
#include <iostream>
#include <string>
#include "Funciones.h"
//#include <ctime>

using namespace std;

int main(int argc, char** argv)
{
    string* vector = new string[18];
    char coma;
    int estado_paciente;
    fstream fp;
    fp.open("pacientes.csv", ios::in);
    int j = 0;
    if (!fp.is_open())
    {
        return;
    }
    do {
        for (int i = 0; i < 18; i++)
        {
            paciente >> vector[i] >> coma;
        }
        Paciente aux_p[j];
        Contacto aux_cp[j];
        Contacto aux_cm[j];
        Medico aux_m[j];
        Historia_clinica aux_h[j];
        Ultima_consulta aux_u[j];
        while (paciente)
        {
            pacientes >> aux_p[j].nombre >> coma >> aux_p[j].
                apellido >> coma >> aux_p[j].dni >> coma >> aux_p[j].obra_social >> coma >> aux_cp.[j]num_telefo
                no >> coma >> aux_cp[j].mail >> coma >> aux_m[j].nombre >> coma >> aux_m[j].apellido >> coma >
            > aux_m[j].matricula >> coma >> aux_cm[j].num_telefono >> coma >> aux_cm[j].mail >> coma >> a
                ux_h[j].fecha_ultima_cita >> coma >> aux_h[j].cita_concurrida >> coma >> aux_h[j].reprogramaci
                ón >> coma >> aux_h[j].fecha_de_reprogramacion >> coma >> aux_h[j].estado;
            aux_cp[j].dni = aux_h[j].dni = aux_u[j].dni_paciente = aux_p[j].dni;
            aux_p[j].ultimo_medico = aux_m[j].matricula;
            aux_u[j].dni_medico = aux_m[j].dni;
            aux_u[j].fecha_ultima_consulta = aux_h[j].fecha_ultima_cita;
        } // Llenamos las estructuras con los datos del archivo
        if (verificar_tiempo_10años(aux_h) == verdadero)
        {
            agregar_un_paciente_al_archivo(aux_p[j]);
        }
        else
        {
            estado_paciente = revisar_estado(aux_h[j])
                if (estado_paciente == 0 || estado_paciente == 1)
                {
                    guardar_secretaria(aux_u[j])
                }
                else if (estado_paciente == 2)
                {
                    agregar_un_paciente_al_archivo(aux_p[j]);
                }
        }
        while (aux_h[j].cita_concurrida == false || aux_h[j].reprogramacion = false)
        {
            if (aux_h[j].cita_concurrida == true)
            {
                cout << "El paciente asistio a la cita" << endl;
            }
            else if (aux_h[j].reprogramacion == true)
            {
                cout << "El paciente reprogramo su cita" << endl;
            }

        }
        j++;
    } while (pacientes);
    foobar::Example example{};
    std::cout << "Example.getValue() => " << example.getValue() << std::endl;
    verificar_tiempo_10años()
        return EXIT_SUCCESS;
}

