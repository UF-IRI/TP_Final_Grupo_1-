
#include <funciones.h>
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