#include"funciones.h"

int cantidad_de_registros(string file)
{
ifstream fp;
string linea;
char delimitador = ',';
int contador = 0;
fp.open(file, ios::in);
if (fp.fail())
{
	exit(1);
}
getline(fp, linea);
while (getline(fp, linea))
{
	contador++;
}
return contador;
}
//-----------------------------------------------

bool verificar_tiempo_10años(Historia_clinica pac_hist)
{
	fstream fp;
	Paciente aux2;
	Historia_clinica aux;
	Contacto aux3;
	char coma;
	fp.open("Historia_clinica.csv", ios::in);
	if (!fp.is_open())
	{
		cout << " No se pudo abrir";
		exit(1);
	}
	while (fp)
	{
		fp >> aux2.nombre >> coma >> aux2.apellido >> coma >> aux.aux.dni_paciente >> coma >> aux2.obra_social >> coma >> aux.fecha_ultima_cita.dia >> coma >> aux.fecha_ultima_cita.mes >> coma >> aux.fecha_ultima_cita.anio >> coma >> aux.cita_concurrida >> coma;
		if (aux.dni_paciente == pac_hist.dni_paciente)
		{
			time_t actual;
			time(*actual);
			time_t fecha_ultimo;
			fecha_ultimo = pac_hist.fecha_ultima_cita.Anio * 31540000 + pac_hist.fecha_ultima_cita.mes * 262800 + pac_hist.fecha_ultima_cita.dia * 86400;
			float década;
			decada = difftime(actual, fecha_ultimo) / 31540000;
			if (decada >= 10)
			{
				return true;
			}
			else
				return false;
		}
	}
	fp.close();

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
void reprogramacion_fecha(Historia_clinica* array, int N, Fecha nueva, string dni)
{
	for (int i = 0; i < N; i++)
	{
		if (array[i].dni_paciente == dni)
		{
			array[i].fecha_de_reprogramacion.dia = nueva.dia;
			array[i].fecha_de_reprogramacion.mes = nueva.mes;
			array[i].fecha_de_reprogramacion.anio = nueva.anio;
		}

	}
}
int revisar_estado(Historia_clinica paciente)// Devuelve el estado del paciente
{
	return paciente.estado;//0, 1 y 2 estados del paciente ya cargados en el archivo
}
void guardar_secretaria(Ultima_consulta datos, contacto contacto_paciente)
{
	fstream fp;
	fp.open("secretaria.txt", ios::app);
	if (!fp.is_open())
	{
		exit(1);
	}
	getline(cin, datos.dni_paciente);
	fp << datos.dni_paciente << " , " << datos.dni_medico << " , " << datos.ultima_consulta << " , " << contacto_paciente.mail << " , " << contacto_paciente.num_telefono << endl;
	fp.close();
}
bool Comprobacion_dni(string& dni)
{
	char* p;
	strtol(str.c_str(), &p, 10);
	return * p  == 0;// Devuelve 1 si son numeros y 0 si hay una letra

}
int buscar_posición(string dni, Historia_clinica* array)
{
	int longitud = sizeof(array) / sizeof(array[0]);
	for (int i = 0; i <= longitud; i++)
	{
		if (dni == array[i].dni_paciente)
		{
			return i;
		}
		else
			return -1;
	}
}
bool agregar_consulta(consultas_t* lista, int cant, int tamanio, consultas_t cons)
{
	consultas_t* aux = nullptr;
	if (cant < tamanio)
	{
		cout << "Hay espacio para cargar";
		lista[cant] = cons;
		return true;
	}
	else if (cant == tamanio)
	{
		lista[tamanio] = cons;
		return true;
	}
	else
	{
		return false;//Regresa false por que no se puede agregar a la lista
	}

}

bool agregar_contactos(contacto* lista, int cant, int tamanio, contacto cons)
{
	contacto* aux = nullptr;
	if (cant < tamanio)
	{
		cout << "Hay espacio para cargar";
		lista[cant] = cons;
		return true;
	}
	else if (cant == tamanio)
	{
		lista[tamanio] = cons;
		return true;
	}
	else
	{
		return false;//Regresa false por que no se puede agregar a la lista
	}

}

bool agregar_medico(medico* lista, int cant, int tamanio, medico cons)
{
	medico* aux = nullptr;
	if (cant < tamanio)
	{
		cout << "Hay espacio para cargar";
		lista[cant] = cons;
		return true;
	}
	else if (cant == tamanio)
	{
		lista[tamanio] = cons;
		return true;
	}
	else
	{
		return false;//Regresa false por que no se puede agregar a la lista
	}
}

bool agregar_obra_social(obra_social* lista, int cant, int tamanio, obra_social cons)
{
	consultas_t* aux = nullptr;
	if (cant < tamanio)
	{
		cout << "Hay espacio para cargar";
		lista[cant] = cons;
		return true;
	}
	else if (cant == tamanio)
	{
		lista[tamanio] = cons;
		return true;
	}
	else
	{
		return false;//Regresa false por que no se puede agregar a la lista
	}
}

bool agregar_paciente(paciente lista, int cant, int tamanio, paciente cons)
{
	paciente* aux = nullptr;
	if (cant < tamanio)
	{
		cout << "Hay espacio para cargar";
		lista[cant] = cons;
		return true;
	}
	else if (cant == tamanio)
	{
		lista[tamanio] = cons;
		return true;
	}
	else
	{
		return false;//Regresa false por que no se puede agregar a la lista
	}

}
bool resize_consulta(consultas_t* lista, int tamanio)
{
	consultas_t* aux = NULL;
	aux = new consultas_t[tamanio + 20];
	for (int i = 0; i < tamanio + 20; i++)
	{
		aux[i].dni_pac = " ";
		aux[i].fecha_solicitado = " ";
		aux[i].fecha_turno = " ";
		aux[i].presento = false;
		aux[i].matricula_med = " ";

	}
	for (int i = 0; i < tamanio; i++)
	{
		aux[i] = lista[i];
	}
	lista = aux;
	delete[] aux;
}
bool resize_contactos(contacto* lista, int tamanio)
{
	contacto* aux = NULL;
	aux = new contacto[tamanio + 20];
	for (int i = 0; i < tamanio + 20; i++)
	{
		aux[i].direccion = " ";
		aux[i].dni = " ";
		aux[i].num_telefono = " ";
		aux[i].mail = " ";
		aux[i].num_celular = " ";

	}
	for (int i = 0; i < tamanio; i++)
	{
		aux[i] = lista[i];
	}
	lista = aux;
	delete[] aux;
}
bool resize_medico(medico* lista, int tamanio)
{
	medico* aux = NULL;
	aux = new medico[tamanio + 20];
	for (int i = 0; i < tamanio + 20; i++)
	{
		aux[i].nombre = " ";
		aux[i].apellido = " ";
		aux[i].matricula = " ";
		aux[i].especialidad =" ";
		aux[i].contacto = " ";
		aux[i].activo= false;

	}
	for (int i = 0; i < tamanio; i++)
	{
		aux[i] = lista[i];
	}
	lista = aux;
	delete[] aux;
}
bool resize_obra_social(obra_social* lista, int tamanio)
{
	obra_social* aux = NULL;
	aux = new obra_social[tamanio + 20];
	for (int i = 0; i < tamanio + 20; i++)
	{
		aux[i].codigo = " ";
		aux[i].nombre_os = " ";
	}
	for (int i = 0; i < tamanio; i++)
	{
		aux[i] = lista[i];
	}
	lista = aux;
	delete[] aux;
}
bool resiz_paciente(paciente* lista, int tamanio)
{
	paciente* aux = NULL;
	aux = new paciente[tamanio + 20];
	for (int i = 0; i < tamanio + 20; i++)
	{
		aux[i].apellido = " ";
		aux[i].dni = " ";
		aux[i].nacimiento = " ";
		aux[i].nombre = " ";
		aux[i].obra_social = " ";
		aux[i].sexo = " ";
		aux[i].ultimo_medico = " ";
	

	}
	for (int i = 0; i < tamanio; i++)
	{
		aux[i] = lista[i];
	}
	lista = aux;
	delete[] aux;
}
bool eliminar_paciente(paciente* lista, int pos, int cant)
{
	paciente* aux;
	aux = new paciente[cant - 1];
	if (lista == nullptr)
	{
		return false;
    }
	else 
	{
		for (i = 0; i < cant; i++)
		{
			aux[i] = lista[i];
			if (i == pos)
			{
				for (int j = i + 1; j < cant; j++)
				{
					aux[j] = lista[j];
				}
			}
		}
	}
	lista = aux;
	delete[]aux;
	return true;
}

bool eliminar_obra_social(obra_social* lista, int pos, int cant)
{
	obra_social* aux;
	aux = new obra_social[cant - 1];
	if (lista == nullptr)
	{
		return false;
	}
	else
	{
		for (i = 0; i < cant; i++)
		{
			aux[i] = lista[i];
			if (i == pos)
			{
				for (int j = i + 1; j < cant; j++)
				{
					aux[j] = lista[j];
				}
			}
		}
	}
	lista = aux;
	delete[]aux;
	return true;
}

bool eliminar_medico(medico* lista, int pos, int cant)
{
	medico* aux;
	aux = new medico[cant - 1];
	if (lista == nullptr)
	{
		return false;
	}
	else
	{
		for (i = 0; i < cant; i++)
		{
			aux[i] = lista[i];
			if (i == pos)
			{
				for (int j = i + 1; j < cant; j++)
				{
					aux[j] = lista[j];
				}
			}
		}
	}
	lista = aux;
	delete[]aux;
	return true;
}

bool eliminar_contacto(contacto* lista, int pos, int cant)
{
	contacto* aux;
	aux = new contacto[cant - 1];
	if (lista == nullptr)
	{
		return false;
	}
	else
	{
		for (i = 0; i < cant; i++)
		{
			aux[i] = lista[i];
			if (i == pos)
			{
				for (int j = i + 1; j < cant; j++)
				{
					aux[j] = lista[j];
				}
			}
		}
	}
	lista = aux;
	delete[]aux;
	return true;
}

bool eliminar_consulta(consulta* lista, int pos, int cant)
{
	consulta* aux;
	aux = new consulta[cant - 1];
	if (lista == nullptr)
	{
		return false;
	}
	else
	{
		for (i = 0; i < cant; i++)
		{
			aux[i] = lista[i];
			if (i == pos)
			{
				for (int j = i + 1; j < cant; j++)
				{
					aux[j] = lista[j];
				}
			}
		}
	}
	lista = aux;
	delete[]aux;
	return true;
}

//------------------------------------------------------------------------------------------------------------


