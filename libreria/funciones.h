#pragma once
#include<string>
using namespace std;
struct Consulta
{
	string dni_pac;
	string fecha_solicitado;
	string fecha_turno;
	string presento;
	string matricula_med;

}; typedef Consulta consultas_t;

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
pacientes_t* cargar_datos_de_un_archivo_a_una_estruct_pacientes(string file, consultas_t* vector);
