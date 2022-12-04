#pragma once
#include<string>
#include <stdlib>
#include <fstream>
using namespace std;

#pragma once

#include<stdlib.h>
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
//------------------------------
struct Historia_clinica
{

	string dni_paciente;
	tm fecha_ultima_cita;
	bool cita_concurrida; // verdadero: asistio�, falso:no asistio
	bool reprogramacion_fecha; // verdadero: reprogramaron , falso: no reprogramaron
	string ultimo_medico; // matricula del ultimo medico que atendia al paciente
	tm fecha_de_reprogramacion; // el dia de reprogramacion la cita medica
	string estado; // 0 si está vivo, 1 si está internado, 2 si murió
}; typedef struct Historia_clinica historia_clinica_t;

