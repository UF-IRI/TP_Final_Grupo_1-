#pragma once
#include<string>
using namespace std;

bool verificar_tiempo_10años(Historia_clinica pac_hist); // verdadero>10 , falso<10
void agregar_un_paciente_al_archivo(Historia_clinica paciente);// Agrega el paciente al archivo
void reprogramacion_fecha(Historia_clinica* array, int N, Fecha nueva, string dni);// función que permite modificar la fecha de reprogramacion
int revisar_estado(Historia_clinica paciente);// permite revisar si el paciente ha muerto o está internado// consultar
void guardar_secretaria(Ultima_consulta datos, contacto contacto_paciente);// añade un elemento de la estructura última consulta al archivo
bool Comprobacion_dni(string dni);// verifica si el DNI ingresado es válido
int buscar_posición(string dni, Historia_clinica pac);// devuelve la posición de un paciente en el 
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
	string num_celular
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
	bool cita_concurrida; // verdadero: asistió, falso:no asistió
	bool reprogramacion_fecha; // verdadero: reprogramaron , falso: no reprogramaron
	string ultimo_medico; // matrícula del último médico que atendió al paciente
	fecha fecha_de_reprogramacion; // el dia de reprogramación la cita médica
	string estado; // 0 si está vivo, 1 si está internado, 2 si murió
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
/*
struct Contacto
{
	string dni_paciente;
	string telefono;
	string celular; 
	string direccion;
	string mail;

}; typedef Contacto contactos_t;
struct Medico
{
	string matricula;
	string nombre;
	string apellido;
	string telefono;
	string especialidad;
	string activo;
}; typedef struct Medico medicos_t;

struct ObraSocial
{
	string id_os;
	string obra_social;
}; typedef struct ObraSocial obrasocial_t;
struct Paciente
{
	string dni;
	string nombre;
	string apellido;
	string sexo; 
	string natalicio;
	string estado;
	string id_os;
}; typedef struct Paciente pacientes_t;

int cantidad_de_registros(string file);
consultas_t* cargar_datos_de_un_archivo_a_una_estruct_consulta(string file, consultas_t* vector);
contactos_t* cargar_datos_de_un_archivo_a_una_estruct_contactos(string file, contactos_t* vector);
medicos_t* cargar_datos_de_un_archivo_a_una_estruct_medicos(string file, consultas_t* vector);
obrasocial_t* cargar_datos_de_un_archivo_a_una_estruct_obra_social(string file, consultas_t* vector);
pacientes_t* cargar_datos_de_un_archivo_a_una_estruct_pacientes(string file, consultas_t* vector);*/

