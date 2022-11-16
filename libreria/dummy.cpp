//bool verificar_tiempo_10años(Historia_clinica pac_hist); // verdadero>10 , falso<10
//void agregar_un_paciente_al_archivo(Historia_clinica paciente);// Agrega el paciente al archivo
//void reprogramacion_fecha(Historia_clinica* array, int N, Fecha nueva, string dni);// función que permite modificar la fecha de reprogramacion
//int revisar_estado(Historia_clinica paciente);// permite revisar si el paciente ha muerto o está internado// consultar
//void guardar_secretaria(Ultima_consulta datos, contacto contacto_paciente);// añade un elemento de la estructura última consulta al archivo
//bool Comprobacion_dni(string dni);// verifica si el DNI ingresado es válido
//int buscar_posición(string dni, Historia_clinica pac);// devuelve la posición de un paciente en el arreglo
typedef struct Paciente
{
    string nombre;
    string apellido;
    string dni;
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
    string mail;

}contacto;
typedef struct Medico
{
    string nombre;
    string apellido;
    string matricula;
    string dni_medico;
}medico;
typedef struct Historia_clinica
{

    string dni_paciente;
    fecha fecha_ultima_cita;
    bool cita_concurrida; // verdadero: asistió, falso:no asistió
    bool reprogramacion_fecha; // verdadero: reprogramaron , falso: no reprogramaron
    string ultimo_medico; // matrícula del último médico que atendió al paciente
    fecha fecha_de_reprogramacion; // el dia de reprogramación la cita médica
    int estado; // 0 si está vivo, 1 si está internado, 2 si murió
};
typedef struct Ultima_consulta
{
    string dni_paciente;
    string dni_medico;
    fecha ultima_consulta;// igual al valor de fecha_ultima_cita en Historia_Clinica
}ultima_consulta;

namespace foobar
{
    struct Example
    {
        int getValue() const;
    };
}

bool verificar_tiempo_10años(Historia_clinica pac_hist)
{
			time_t actual;
			time(*actual);
			time_t fecha_ultimo;
			fecha_ultimo = pac_hist.fecha_ultima_cita.Anio * 31540000 + pac_hist.fecha_ultima_cita.mes * 262800 + pac_hist.fecha_ultima_cita.dia * 86400;
			float decada;
			decada = difftime(actual, fecha_ultimo) / 31540000;
			if (decada >= 10)
			{
				return true;
			}
			else
				return false;

}
void agregar_un_paciente_al_archivo(Historia_clinica paciente) //agrega un paciente al archivo de irrecuperables
{
	fstream fp;
	fp.open("irrecuperables.txt", ios::app);
	if (!fp.is_open())
	{
		exit(1);
	}
	getline(cin, paciente.dni_paciente);
	fp << paciente.dni_paciente << endl;
	fp.close();
}