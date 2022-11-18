#pragma once
#include<string>
#include <stdlib>
#include <fstream>
using namespace std;

bool verificar_tiempo_10a�os(Historia_clinica pac_hist); // verdadero>10 , falso<10
void agregar_un_paciente_al_archivo(Historia_clinica paciente);// Agrega el paciente al archivo
void reprogramacion_fecha(Historia_clinica* array, int N, Fecha nueva, string dni);// funci�n que permite modificar la fecha de reprogramacion
int revisar_estado(Historia_clinica paciente);// permite revisar si el paciente ha muerto o est� internado// consultar
void guardar_secretaria(Ultima_consulta datos, contacto contacto_paciente);// a�ade un elemento de la estructura �ltima consulta al archivo
bool Comprobacion_dni(string dni);// verifica si el DNI ingresado es v�lido
int buscar_posici�n(string dni, Historia_clinica pac);// devuelve la posici�n de un paciente en el
//-------------------------------------------------------------------------------
int cantidad_de_registros(string file);
bool agregar_consulta(consultas_t* lista, int cant, int tamanio, consultas_t cons);
bool agregar_contactos(contacto* lista, int cant, int tamanio, contacto cons);
bool agregar_medico(medico* lista, int cant, int tamanio, medico cons);
bool agregar_obra_social(obra_social* lista, int cant, int tamanio, obra_social cons);
bool agregar_paciente(paciente lista, int cant, int tamanio, paciente cons);
bool resize_consulta(consultas_t* lista, int tamanio);
bool resize_contactos(contacto* lista, int tamanio);
bool resize_medico(medico* lista, int tamanio);
bool resize_obra_social(obra_social* lista, int tamanio);
bool resiz_paciente(paciente* lista, int tamanio);
bool eliminar_paciente(paciente* lista, int pos, int cant);
bool eliminar_obra_social(obra_social* lista, int pos, int cant);
bool eliminar_medico(medico* lista, int pos, int cant);
bool eliminar_contacto(contacto* lista, int pos, int cant);
bool eliminar_consulta(consulta* lista, int pos, int cant);
struct Consulta
{
	string dni_pac;
	string fecha_solicitado;
	string fecha_turno;
	bool presento;
	string matricula_med;

}; typedef Consulta consultas_t;
typedef struct Paciente
{
	string nombre;
	string apellido;
	string dni;
	char sexo;
	fecha nacimiento;
	string obra_social;
	string ultimo_medico;

}paciente;
typedef struct Fecha
{
	int dia;
	int mes;
	int anio;
}fecha;
typedef struct Contacto
{
	string dni;
	string num_telefono;
	string num_celular;
	string mail;
	string direccion;
}contacto;
typedef struct Medico
{
	string nombre;
	string apellido;
	string matricula;
	string especialidad;
	string contacto;
	bool activo;
}medico;
typedef struct Historia_clinica
{

	string dni_paciente;
	fecha fecha_ultima_cita;
	bool cita_concurrida; // verdadero: asisti�, falso:no asisti�
	bool reprogramacion_fecha; // verdadero: reprogramaron , falso: no reprogramaron
	string ultimo_medico; // matr�cula del �ltimo m�dico que atendi� al paciente
	fecha fecha_de_reprogramacion; // el dia de reprogramaci�n la cita m�dica
	string estado; // 0 si est� vivo, 1 si est� internado, 2 si muri�
};
typedef struct Ultima_consulta
{
	string dni_paciente;
	string dni_medico;
	fecha ultima_consulta;// igual al valor de fecha_ultima_cita en Historia_Clinica
}ultima_consulta;
typedef struct Obra_Social
{
	int codigo;
	string nombre_os;

}obra_social;

//struct Contacto
//{
//	string dni_paciente;
//	string telefono;
//	string celular; 
//	string direccion;
//	string mail;
//
//}; typedef Contacto contactos_t;
//struct Medico
//{
//	string matricula;
//	string nombre;
//	string apellido;
//	string telefono;
//	string especialidad;
//	string activo;
//}; typedef struct Medico medicos_t;
//
//struct ObraSocial
//{
//	string id_os;
//	string obra_social;
//}; typedef struct ObraSocial obrasocial_t;
//struct Paciente
//{
//	string dni;
//	string nombre;
//	string apellido;
//	string sexo; 
//	string natalicio;
//	string estado;
//	string id_os;
//}; typedef struct Paciente pacientes_t;



