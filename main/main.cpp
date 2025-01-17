// windows + r -> cmd.exe
//taskkill /F /IM ApplicationName.exe
//taskkill /F /IM main.exe
#include "iri.cpp"
#include <iostream>
#include"dummy.h"

using namespace std;

int main() {
       //------------------------------------ guarda la ruta a a de los archivos csv
    string archivo_consultas = "C:\\Users\\sando\\source\\repos\\TP_Final_Grupo_1-\\data_files\\input\\IRI_Consultas.csv";
    string archivo_contactos = "C:\\Users\\sando\\source\\repos\\TP_Final_Grupo_1-\\data_files\\input\\IRI_Contactos.csv";
    string archivo_medicos = "C:\\Users\\sando\\source\\repos\\TP_Final_Grupo_1-\\data_files\\input\\IRI_Medicos.csv";
    string archivo_pacientes = "C:\\Users\\sando\\source\\repos\\TP_Final_Grupo_1-\\data_files\\input\\IRI_Pacientes.csv";

    //---------------------------------------- creamos punteros simples apntando a nullptr, puesto que esto van a representar nuestras listas despues de pedir memoria dinamica
    consultas_t* list_consultas = nullptr;
    contactos_t* list_contactos = nullptr;
    medicos_t* list_medicos = nullptr;
    pacientes_t* list_pacientes = nullptr;
    //--------------------------------------- guardamos la cantidad de registros que contiene cada archivo csv ------------------
    int cant_consultas = cantidad_de_registros(archivo_consultas);
    int cant_pacientes = cantidad_de_registros(archivo_pacientes);
    int cant_contactos = cantidad_de_registros(archivo_contactos);
    int cant_medicos = cantidad_de_registros(archivo_medicos);
    //-------------- cada una de esta funcion pide memoria dinamica y las carga con lo registros que contiene cada archivo  -----------------------------------------------------------
    list_consultas = cargar_datos_de_un_archivo_a_una_estruct_consulta(archivo_consultas, list_consultas);
    list_contactos = cargar_datos_de_un_archivo_a_una_estruct_contactos(archivo_contactos, list_contactos);
    list_medicos = cargar_datos_de_un_archivo_a_una_estruct_medicos(archivo_medicos, list_medicos);
    list_pacientes = cargar_datos_de_un_archivo_a_una_estruct_pacientes(archivo_pacientes, list_pacientes);

    //------------------------------------------ imprimo la losta consultas una ves cargada la estructura list_consultas ----------------------------------------------------------- 
     cout << "---------------------------lista de consultas---------------------------------------------------" << endl;
     for (int i = 0; i < cant_consultas; i++)
     {
         cout << list_consultas[i].dni_pac << " - " << list_consultas[i].fecha_solicitado.tm_mday << "/" << list_consultas[i].fecha_solicitado.tm_mon << "/" << list_consultas[i].fecha_solicitado.tm_year <<" - " << list_consultas[i].fecha_turno.tm_mday << "/" << list_consultas[i].fecha_turno.tm_mon << "/" << list_consultas[i].fecha_turno.tm_year << " - " << list_consultas[i].presento << " - " << list_consultas[i].matricula_med << endl;
     }
     //------------------------------------------imprimo la losta consultas una ves cargada la estructura list_contactos ------------------------------------------------------------
      cout << "--------------------------listas contactos--------------------------------------------------" << endl;
    for (int i = 0; i < cant_contactos; i++)
    {
        cout << list_contactos[i].dni_paciente << " - " << list_contactos[i].telefono << " - " << list_contactos[i].celular << " - " << list_contactos[i].direccion << " - " << list_contactos[i].mail << endl;
        //cout << list_consultas[i].dni_pac << " - " << list_consultas[i].fecha_solicitado.tm_mday << "/" << list_consultas[i].fecha_solicitado.tm_mon << "/" << list_consultas[i].fecha_solicitado.tm_year <<" - " << list_consultas[i].fecha_turno.tm_mday << "/" << list_consultas[i].fecha_turno.tm_mon << "/" << list_consultas[i].fecha_turno.tm_year << " - " << list_consultas[i].presento << " - " << list_consultas[i].matricula_med << endl;
    }
    //--------------------------imprimo la losta consultas una ves cargada la estructura list_medicos-------------------------
     cout << "-------------------------- lista de medicos --------------------------------------------------" << endl;
    for (int i = 0; i < cant_medicos; i++)
     {
         cout << list_medicos[i].matricula<< " - "<< list_medicos[i].nombre<<" - "<< list_medicos[i].apellido<<" - "<< list_medicos[i].telefono<<" - "<< list_medicos[i].especialidad<<" - "<< list_medicos[i].activo << endl;
     }
    //------------------------------------------imprimo la losta consultas una ves cargada la estructura list_pacientes--------------------------
     cout << "-------------------------- lista de pacientes --------------------------------------------------" << endl;
     for (int i = 0; i < cant_pacientes; i++)
     {
         cout << list_pacientes[i].dni<<" - " << list_pacientes[i].nombre<<" - "<<list_pacientes[i].apellido<<" - "<< list_pacientes[i].natalicio.tm_mday<<"/"<< list_pacientes[i].natalicio.tm_mon<<"/"<< list_pacientes[i].natalicio.tm_year<<" - "<<" - "<< list_pacientes[i].obra_social << endl;
    }
    cout << "----------------------------------------- consignas---------------------------------------" << endl;
    //--------------------------------------------- resolviendo las consignas ---------------------------

    historia_clinica_t aux_h; //guardo una historia clinica auxiliar de irrecuperables para luegro agregarla a la estructura de irrecuperables.
    aux_h.dni_paciente = "";
    aux_h.fecha_ultima_cita = { 0,0,0,0,0,0,0,0,0 };
    aux_h.cita_concurrida = false;
    aux_h.estado = ESTADO::n_c;
    aux_h.ultimo_medico = "";
    // creando la lista de los pacientes de histria  clinicas de irrecuperables
    int cant_irrecuperables = 0;
    historia_clinica_t* lista_historia_clinica_irrecuperables = new historia_clinica_t[cant_irrecuperables];
    // creando la lista de los pacientes  que se le pasa a secretaria para que esta se comunique con ellos
    contactos_t aux_contacto;
    aux_contacto.dni_paciente = "";
    aux_contacto.telefono = "";
    aux_contacto.celular = "";
    aux_contacto.direccion = "";
    aux_contacto.mail = "";

    int cant_de_contactos_secretaria = 0;
    contactos_t* lista_a_secretaria = new contactos_t[cant_de_contactos_secretaria];    //<10anio para preguntar
    //------------------------------------------------------------------------------------------------------------
    string aux_dni;
    for (int i = 0; i < cant_consultas; i++)
    {
        if (verificar_tiempo_10anios(list_consultas[i].fecha_turno) == true)// si paso mas de 10 a�os
        {
            aux_h.dni_paciente = list_consultas[i].dni_pac;

            aux_h.fecha_ultima_cita.tm_mday = list_consultas[i].fecha_turno.tm_mday;
            aux_h.fecha_ultima_cita.tm_mon = list_consultas[i].fecha_turno.tm_mon;
            aux_h.fecha_ultima_cita.tm_year = list_consultas[i].fecha_turno.tm_year;
            aux_h.cita_concurrida = list_consultas[i].presento;
            aux_h.ultimo_medico = list_consultas[i].matricula_med;
            for (int j = 0; j < cant_pacientes; j++) //comp. dni y guarda el estado
            {
                if (list_consultas[i].dni_pac == list_pacientes[j].dni)
                {
                    aux_h.estado = list_pacientes[j].estado;
                }
            }
            //------------------------ agregamos una historia clinica a una a la estructura de irrecuperables----------------
             agregar_paciente_a_historia_clinica_irrecuperables(lista_historia_clinica_irrecuperables, aux_h, &cant_irrecuperables);

        }
        else if (verificar_tiempo_10anios(list_consultas[i].fecha_turno) == false && list_consultas[i].presento == false)///  pasaron menos de 10 a�os y  aquellos que cumplieron 10 a�os pero que aun no se vennce el turno
        {
            for (int j = 0; j < cant_pacientes; j++)
            {
                if (list_consultas[i].dni_pac == list_pacientes[j].dni)
                {
                    for (int k = 0; k < cant_contactos; k++)
                    {
                        if (list_pacientes[j].dni == list_contactos[k].dni_paciente)
                        {
                            aux_contacto.dni_paciente = list_contactos[k].dni_paciente;
                            aux_contacto.telefono = list_contactos[k].telefono;
                            aux_contacto.celular = list_contactos[k].celular;
                            aux_contacto.direccion = list_contactos[k].direccion;
                            aux_contacto.mail = list_contactos[k].mail;
                        }
                    }
                    if (list_pacientes[j].estado == ESTADO::fallecido)
                    {
                        aux_h.dni_paciente = list_consultas[i].dni_pac;
                        aux_h.fecha_ultima_cita.tm_mday = list_consultas[i].fecha_turno.tm_mday;
                        aux_h.fecha_ultima_cita.tm_mon = list_consultas[i].fecha_turno.tm_mon;
                        aux_h.fecha_ultima_cita.tm_year = list_consultas[i].fecha_turno.tm_year;
                        aux_h.cita_concurrida = list_consultas[i].presento;
                        aux_h.ultimo_medico = list_consultas[i].matricula_med;
                        aux_h.estado = ESTADO::fallecido;
                        //------------------------ agregamos una historia clinica a una a la estructura de irrecuperables------------------------
                         agregar_paciente_a_historia_clinica_irrecuperables(lista_historia_clinica_irrecuperables, aux_h, &cant_irrecuperables);
                    }
                    else
                    {//------------------------ agregamos un contacto a la listas lista_secretaria para enviar a secretaria y esta se comunique con el paciente para saber si retorna ---------------
                      agregar_contacto_a_la_lista_de_secretaria(lista_a_secretaria, aux_contacto, &cant_de_contactos_secretaria);//
                    }
                }
            }
        }
    }
    //----------------------------------  imprimir la lista de irrecuperables desde la estructrua --------------------------------------------------------------------------------------------
    cout << "--------------------lista de los irrecuperables--------------------------------------------------------------" << endl;

   for (int k = 0; k < cant_irrecuperables; k++)
   {
       cout << lista_historia_clinica_irrecuperables[k].dni_paciente << " - " << lista_historia_clinica_irrecuperables[k].fecha_ultima_cita.tm_mday << "/" << lista_historia_clinica_irrecuperables[k].fecha_ultima_cita.tm_mon << "/" << lista_historia_clinica_irrecuperables[k].fecha_ultima_cita.tm_year << " - " << lista_historia_clinica_irrecuperables[k].cita_concurrida << " - " << lista_historia_clinica_irrecuperables[k].ultimo_medico << endl;
   }
    //---------------imprimi la lista de estruturas del tipo contactos que se le pasa a secretaria para que se coomunique la secretaria para saber si retorna --------------------------------------------------------------------------
   cout << "--------------------lista de aquellos que no pasaron de 10 a�os y no fueron a la consulta que estan vivos----------------------------- " << endl;

     for (int k = 0; k < cant_de_contactos_secretaria; k++)
     {
         cout << lista_a_secretaria[k].dni_paciente << " - " << lista_a_secretaria[k].telefono << " - " << lista_a_secretaria[k].celular << " - " << lista_a_secretaria[k].direccion << " - " << lista_a_secretaria[k].mail << endl;
     }
    //-------------- ---------------------------------------------------------------------------------------------------
   cout << "------------------------ cargo la lista de irrecuperables a un archivo y lo mando a secretaria --------------------------------------" << endl;
     cargar_estructura_irrecupeables_a_archivo_irrecuperable(lista_historia_clinica_irrecuperables, &cant_irrecuperables);
     cout << "---------------------------------- imprimo la lista de irrecuperabes.txt desde el archivo --------------------------------" << endl;
     imprimir_archivo("irrecuperables.txt");
    //-------------------------------------------------------------------------------------------------------------------

   for (int i = 0; i < cant_de_contactos_secretaria; i++)
   {
       cout << lista_a_secretaria[i].dni_paciente << endl;
   }
   cout << "---------------------------------- cargo la lista de contactos en un archivoy se envia a secretaria para que esta se comunique con cada paciente --------------------------------" << endl;
     crear_archivo_pacientes_medico_ultima_consulta(list_pacientes, &cant_pacientes,list_consultas,&cant_consultas, lista_a_secretaria,&cant_de_contactos_secretaria,list_medicos,&cant_medicos);
     cout << "-------------------------------------- imprima  archivo_paciente_medico_y_ultima_consulta.txt que se envia a secretaria -----------------------------" << endl;
     imprimir_archivo("archivo_paciente_medico_y_ultima_consulta.txt");
   cout << "------------------------------------------ -----------------------------------------" << endl;
    mandar_archivo_a_secretaria(cant_consultas, cant_pacientes, lista_a_secretaria, cant_de_contactos_secretaria, list_pacientes, list_consultas);
    imprimir_archivo("contactos_de_secretaria.txt");
    cout << "fin" << endl;

    delete[] list_consultas;
    delete[] list_contactos;
    delete[]  list_medicos;
    delete[]  list_pacientes;

     return EXIT_SUCCESS;
}




