//#include "iri.cpp"
#include <cstdlib>
#include <iostream>
#include <string>
#include "funciones.h"
//#include <ctime>

using namespace std;

int main(int argc, char** argv)
{
    
    int estado_paciente;
    fstream Consultas,Contactos,Medicos, ObraSocial, Pacientes;
    Consultas.open("IRI_Consultas.csv", ios::in);
    Contactos.open("IRI_Contactos.csv", ios::in);
    Medicos.open("IRI_Medicos.csv", ios::in);
    ObraSocial.open("IRI_ObraSocial.csv", ios::in);
    Pacientes.open("IRI_Pacientes.csv", ios::in);
    int j = 0;
    string* h_cons = new string[5];
    string* h_cont = new string[5];
    string* h_med = new string[6];
    string* h_os = new string[2];
    string* h_pac = new string[7];
    char coma;
    if (!(Consultas.is_open()||Contactos.is_open() || Medicos.is_open() || ObraSocial.is_open() || Pacientes.is_open())
    {
        return;
    }
    do {
        for (int i = 0; i < 5; i++)
        {
            Consultas >> h_cons[i] >> coma;
        }
        for (int i = 0; i < 5; i++)
        {
            Contactos >> h_cont[i] >> coma;
        }
        for (int i = 0; i < 6; i++)
        {
            Medicos >> h_med[i] >> coma;
        }
        for (int i = 0; i < 2; i++)
        {
            ObraSocial >> h_os[i] >> coma;
        }
        for (int i = 0; i < 7; i++)
        {
            Pacientes >> h_pac[i] >> coma;
        }
        
        Paciente aux_p[j];
        Contacto aux_cp[j];
        Contacto aux_cm[j];
        Medico aux_m[j];
        Historia_clinica aux_h[j];
        Ultima_consulta aux_u[j];
        Obra_Social aux_os[j];
        while (Pacientes)
        {
            Pacientes >> aux_p[j].dni >> coma >> aux_p[j].nombre
            >> coma >> aux_p[j].apellido >> coma >> aux_p[j].sexo >> coma >> aux_p[j].nacimiento >> aux_h[j].estado 
            >> coma >> aux_p[j].obra_social;// Leo y guardo en las estructuras el archivo IRI_Pacientes.csv
        } 
        while (ObraSocial) 
        {
            ObraSocial >> aux_os[j].codigo >> coma >> aux_os[j].nombre_os;
        }// Leo el archivo de obras sociales
        while (Medicos)
        {
            Medicos >> aux_m[j].matricula >> coma >> aux_m[j].nombre >> coma >> aux_m[j].apellido >> coma >> aux_cm[j].num_telefono >> coma >>
                aux_m[j].especialidad >> coma >> aux_m[j].activo;
        }// Leo el archivo de Medicos
            
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
    } 
    while (pacientes);
    string aux_dni;
    int e;//guarda la posicion del paciente
    cout << "Ingrese el dni del paciente a contactar: ";
    cin >> aux_dni;
    if (Comprobacion_dni(aux_dni) == TRUE)
    {
        e = Buscar_posicion(aux_dni, aux_h);
        char aux_cons;//Reprogramar si no
        cout << "Ingresar s, si el paciente desea repreogramar la consulta, de lo contrario ingrese n: " << endl;
        cin >> aux_cons;
        if (aux_cons == 's' || aux_cons == 'S')
        {
            fecha aux_f;
            cout << "Ingrese la fecha de la nueva consulta: " << endl;
            cout << "DD/MM/AAAA " << endl;
            cin >> aux_f.dia >> aux_f.mes >> aux_f.anio;
            aux_h[e].fecha_de_reprogramacion = aux_f;//Le paso la fecha de reprogramacion a la funcion
            aux_h[e].reprogramacion_fecha = TRUE;//Le paso la fecha en bool
            char aux_os;
            cout << "Ingresar s, si el paciente cambio su obra social, de lo contrario ingrese n: " << endl;
            cin >> aux_os;
            if (aux_os == 's' || aux_os == 'S')
            {
                int codigo;
                cout << "Ingrese el codigo de la obra social: ";//cambiodeobrasocial   void cambio_os(int codigo, paciente caso)
                cin >> codigo;
                cambio_os(codigo, aux_p[e]);
            }
            else
                agregar_un_paciente_al_archivo(aux_h[e]);
        }
        else
            cout << "Formato no aceptado" << endl;
        
    }

    foobar::Example example{};
    std::cout << "Example.getValue() => " << example.getValue() << std::endl;
    verificar_tiempo_10años()
        return EXIT_SUCCESS;
}

