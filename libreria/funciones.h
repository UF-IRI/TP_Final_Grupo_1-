
#pragma once
#include<cstdlib>
#include<iostream>
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
	int id_os=-1;
	string estado_obra_social=" ";
}; typedef Obra_Social obra_social_t;
struct Historia_clinica
{

	string dni_paciente=" ";// dni->consulta
	tm fecha_ultima_cita = { 0,0,0,0,0,0,0,0,0 };//fecha_turno ->consulta
	bool cita_concurrida=false; // verdadero: asistio�, falso:no asistio// presento ->consulta
	//--------- bool reprogramacion_fecha; // verdadero: reprogramaron , falso: no reprogramaron //
	string ultimo_medico=" "; // matricula del ultimo medico que atendia al paciente// matricula_medico -> consultas
	//--------- tm fecha_de_reprogramacion; // el dia de reprogramacion la cita medica
	ESTADO estado=ESTADO::niguno; // 0 si está vivo, 1 si está internado, 2 si murió// estado -> pacientes 
	//Historia_clinica();
}; typedef struct Historia_clinica historia_clinica_t;
struct Consultas
{
	string dni_pac=" ";
	tm fecha_solicitado= { 0,0,0,0,0,0,0,0,0 };
	tm fecha_turno= { 0,0,0,0,0,0,0,0,0 };
	bool presento = false;
	string matricula_med=" ";
	//Consultas(); //
}; typedef struct Consultas consultas_t;
struct Contactos
{
	string dni_paciente=" ";
	string telefono = " ";
	string celular = " ";
	string direccion = " ";
	string mail = " ";
	//Contactos();
}; typedef struct Contactos contactos_t;
struct Medicos
{
	string matricula=" ";
	string nombre=" ";
	string apellido=" ";
	string telefono=" ";
	string especialidad=" ";
	bool activo=false;
	//Medicos();
}; typedef struct Medicos medicos_t;
struct Pacientes
{
	string dni=" ";
	string nombre=" ";
	string apellido=" ";
	string sexo=" ";
	tm natalicio= { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	ESTADO estado = ESTADO::niguno;
	string obra_social=" ";
	//Pacientes();
}; typedef struct Pacientes pacientes_t;

int cantidad_de_registros(string file);
int obtener_dia(string cadena);
int obtener_mes(string cadena);
int obtener_anio(string cadena);
bool obtener_presento(string cadena);
int obtener_estado_como_numero(string estado_paciente);
void cargar_datos_de_un_archivo_a_una_estruct_consulta(string file, consultas_t* vector);
void cargar_datos_de_un_archivo_a_una_estruct_contactos(string file, contactos_t* vector);
void cargar_datos_de_un_archivo_a_una_estruct_medicos(string file, medicos_t* vector);
void cargar_datos_de_un_archivo_a_una_estruct_pacientes(string file, pacientes_t* vector);
void agregar_paciente_a_historia_clinica_irrecuperables(historia_clinica_t* lista,historia_clinica_t paciente,int& cantidad);
void cargar_estructura_irrecupeables_a_archivo_irrecuperable(historia_clinica_t* lista, int cantidad);
bool verificar_tiempo_10anios(tm fecha_turno);
void agregar_paciente_a_secretaria(contactos_t* lista_secretaria, string dni,contactos_t* lista_contactos,int& cantidad);
void mandar_archivo_a_secretaria(int cant_consultas, int cant_pacientes, contactos_t* lista_a_secretaria,  int _cant_de_contactos_secretaria, pacientes_t* lista_pacientes,consultas_t* lista_consultas);
void cargar_datos_de_un_archivo_a_una_estruct_obra_social(string file,obra_social_t* vector);
void crear_archivo_pacientes_medico_ultima_consulta(pacientes_t* list_pacientes,medicos_t* list_medicos,consultas_t* list_consultas,contactos_t* list_contactos,int cant_contactos,int cant_pacientes, int cant_medicos,int cant_consultas);

//------------------------------


