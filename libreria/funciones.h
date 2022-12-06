
#pragma once
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
#include<ctime> 

using namespace std;

enum class ESTADO
{
	fallecido, internado, n_c, niguno
};
//enum class EstadoObraSocial
//{ 
//	Medicus, OSDE, IOSFA, Italiano, Aleman, Espanyol,ninguno
//};
struct Obra_Social 
{
	int id_os;
	string estado_obra_social;
}; typedef Obra_Social obra_social_t;
struct Historia_clinica
{

	string dni_paciente;// dni->consulta
	tm fecha_ultima_cita;//fecha_turno ->consulta
	bool cita_concurrida; // verdadero: asistio�, falso:no asistio// presento ->consulta
	//--------- bool reprogramacion_fecha; // verdadero: reprogramaron , falso: no reprogramaron //
	string ultimo_medico; // matricula del ultimo medico que atendia al paciente// matricula_medico -> consultas
	//--------- tm fecha_de_reprogramacion; // el dia de reprogramacion la cita medica
	ESTADO estado; // 0 si está vivo, 1 si está internado, 2 si murió// estado -> pacientes 
	Historia_clinica();
}; typedef struct Historia_clinica historia_clinica_t;
struct Consultas
{
	string dni_pac;
	tm fecha_solicitado;
	tm fecha_turno;
	bool presento = false;
	string matricula_med;
	Consultas(); //
}; typedef struct Consultas consultas_t;
struct Contactos
{
	string dni_paciente;
	string telefono;
	string celular;
	string direccion;
	string mail;
	Contactos();
}; typedef struct Contactos contactos_t;
struct Medicos
{
	string matricula;
	string nombre;
	string apellido;
	string telefono;
	string especialidad;
	bool activo;
	Medicos();
}; typedef struct Medicos medicos_t;
struct Pacientes
{
	string dni;
	string nombre;
	string apellido;
	string sexo;
	tm natalicio;
	ESTADO estado;
	string obra_social;
	Pacientes();
}; typedef struct Pacientes pacientes_t;

int cantidad_de_registros(string file);
int obtener_dia(string cadena);
int obtener_mes(string cadena);
int obtener_anio(string cadena);
bool obtener_presento(string cadena);
int obtener_estado_como_numero(string estado_paciente);
consultas_t* cargar_datos_de_un_archivo_a_una_estruct_consulta(string file, consultas_t* vector);
contactos_t* cargar_datos_de_un_archivo_a_una_estruct_contactos(string file, contactos_t* vector);
medicos_t* cargar_datos_de_un_archivo_a_una_estruct_medicos(string file, medicos_t* vector);
pacientes_t* cargar_datos_de_un_archivo_a_una_estruct_pacientes(string file, pacientes_t* vector);
void agregar_paciente_a_historia_clinica_irrecuperables(historia_clinica_t* lista,historia_clinica_t paciente,int& cantidad);
void cargar_estructura_irrecupeables_a_archivo_irrecuperable(historia_clinica_t* lista, int cantidad);
bool verificar_tiempo_10anios(string  _dni_paciente);
void agregar_paciente_a_secretaria(contactos_t* lista_secretaria, string dni,contactos_t* lista_contactos,int& cantidad);
void mandar_archivo_a_secretaria(contactos_t* lista_a_secretaria,  int _cant_de_contactos_secretaria, pacientes_t* lista_pacientes,consultas_t* lista_consultas);
obra_social_t* cargar_datos_de_un_archivo_a_una_estruct_obra_social(string file,obra_social_t* vector);

//------------------------------


