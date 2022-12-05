
#include <funciones.h>
namespace foobar
{
    struct Example
    {
        int getValue() const;
    };
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