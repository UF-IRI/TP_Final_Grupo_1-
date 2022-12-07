#include"dummy.h"

using namespace std;
//Consultas::Consultas()
//{
//	dni_pac = " ";
//	fecha_solicitado = { 0,0,0,0,0,0,0,0,0 };
//	fecha_turno = { 0,0,0,0,0,0,0,0,0 };
//	presento = false;
//	matricula_med = " ";
//};

//Historia_clinica::Historia_clinica()
//{
//	dni_paciente = "";
//	fecha_ultima_cita = { 0,0,0,0,0,0,0,0,0 };
//	cita_concurrida = false;
//	ultimo_medico = "";
//	estado = ESTADO::niguno;
//};
//Medicos::Medicos()
//{
//	matricula = " ";
//	nombre = " ";
//	apellido = " ";
//	telefono = " ";
//	especialidad = " ";
//	activo = false;
//};
//
//Contactos::Contactos()
//{
//	dni_paciente = " ";
//	telefono = " ";
//	celular = " ";
//	direccion = " ";
//	mail = " ";
//}
//
//Pacientes::Pacientes()
//{
//	string dni = " ";
//	string nombre = " ";
//	string apellido = " ";
//	sexo = '0';
//	natalicio = { 0,0,0,0,0,0,0,0,0 };
//	estado = ESTADO::niguno;
//	obra_social = " ";
//};

int cantidad_de_registros(string file)
{
	ifstream fp;
	string linea;
	char delimitador = ',';
	int contador = 0;
	fp.open(file, ios::in);
	if (fp.fail())
	{
		cout << "el archivo no se pudo abrir" << endl;
		exit(1);
	}
	getline(fp, linea);
	while (getline(fp, linea))
	{
		contador++;
	}
	return contador;
}
//------------------------------------------
void cargar_datos_de_un_archivo_a_una_estruct_consulta(string file, consultas_t* vector)
{
	int cant_registros_del_archivo = 0;
	string linea;
	int i = 0;
	char delimitador = ',';
	cant_registros_del_archivo = cantidad_de_registros(file);
	vector = new consultas_t[cant_registros_del_archivo];
	ifstream fp;
	fp.open("Consultas.csv", ios::in);
	{
		cout << " error al abrir el archivo de cosultas " << endl;
		exit(1);
	}
	getline(fp, linea);
	while (/*!fp.eof()&&i<cant_registros_en_el_archivo*/getline(fp, linea))
	{
		stringstream buffer(linea);
		string _dni;
		string _fecha_solicitado;
		string _fecha_turno;
		string presento;
		string matricula;
		getline(buffer, _dni, delimitador);

		getline(buffer, _fecha_solicitado, delimitador);

		getline(buffer, _fecha_turno, delimitador);

		getline(buffer, presento, delimitador);

		getline(buffer, matricula, delimitador);

		vector[i].dni_pac = _dni;
		vector[i].fecha_solicitado.tm_mday = obtener_dia(_fecha_solicitado);
		vector[i].fecha_solicitado.tm_mon = obtener_mes(_fecha_solicitado);
		vector[i].fecha_solicitado.tm_year = obtener_anio(_fecha_solicitado);
		vector[i].fecha_turno.tm_mday = obtener_dia(_fecha_solicitado);
		vector[i].fecha_turno.tm_mon = obtener_mes(_fecha_solicitado);
		vector[i].fecha_turno.tm_year = obtener_anio(_fecha_solicitado);
		vector[i].presento = obtener_presento(presento);
		vector[i].matricula_med = matricula;
		i++;
	}
	for (int i = 0; i < cant_registros_del_archivo; i++)
	{
		cout << vector[i].dni_pac << delimitador << vector[i].fecha_solicitado.tm_mday << vector[i].fecha_solicitado.tm_mon << vector[i].fecha_solicitado.tm_year << delimitador << vector[i].presento << vector[i].matricula_med << endl;
	}
	fp.close();
}
void cargar_datos_de_un_archivo_a_una_estruct_contactos(string file, contactos_t* vector)
{
	int cant_registros_del_archivo = 0;
	string linea;
	int i = 0;
	char delimitador = ',';
	cant_registros_del_archivo = cantidad_de_registros(file);
	vector = new contactos_t[cant_registros_del_archivo];
	ifstream fp;
	fp.open("Contactos.csv", ios::in);
	{
		cout << "sante se la come " << endl;
		exit(1);
	}
	getline(fp, linea);

	while (getline(fp, linea))
	{
		stringstream buffer(linea);
		string _dni_paciente;
		string _telefono;
		string _celular;
		string _direccion;
		string _mail;

		getline(buffer, _dni_paciente, delimitador);

		getline(buffer, _telefono, delimitador);

		getline(buffer, _celular, delimitador);

		getline(buffer, _direccion, delimitador);

		getline(buffer, _mail, delimitador);

		vector[i].dni_paciente = _dni_paciente;
		vector[i].telefono = _telefono;
		vector[i].celular = _celular;
		vector[i].direccion = _direccion;
		vector[i].mail = _mail;
		i++;
	}
	fp.close();
}
//------------------------------------------------------------
void cargar_datos_de_un_archivo_a_una_estruct_medicos(string file, medicos_t* vector)
{
	int cant_registros_del_archivo = 0;
	string linea;
	int i = 0;
	char delimitador = ',';
	cant_registros_del_archivo = cantidad_de_registros(file);
	vector = new medicos_t[cant_registros_del_archivo];
	ifstream fp;
	fp.open("Medicos.csv", ios::in);
	{
		cout << "sante se la come " << endl;
		exit(1);
	}
	getline(fp, linea);

	while (getline(fp, linea))
	{
		stringstream buffer(linea);

		string _matricula;
		string _nombre;
		string _apellido;
		string _telefono;
		string _especialidad;
		string _activo;

		getline(buffer, _matricula, delimitador);

		getline(buffer, _nombre, delimitador);

		getline(buffer, _apellido, delimitador);

		getline(buffer, _telefono, delimitador);

		getline(buffer, _especialidad, delimitador);

		getline(buffer, _activo, delimitador);

		vector[i].matricula = _matricula;
		vector[i].nombre = _nombre;
		vector[i].apellido = _apellido;
		vector[i].telefono = _telefono;
		vector[i].especialidad = _especialidad;
		vector[i].activo = obtener_presento(_activo);
		i++;
	}
	fp.close();

}
//-------------------------------------------
void cargar_datos_de_un_archivo_a_una_estruct_pacientes(string file, pacientes_t* vector)
{
	int aux_estado = 3;
	int cant_registros_del_archivo = 0;
	string linea;
	int i = 0;
	char delimitador = ',';
	cant_registros_del_archivo = cantidad_de_registros(file);
	vector = new pacientes_t[cant_registros_del_archivo];
	ifstream fp;
	fp.open("Pacientes.csv", ios::in);
	{
		cout << "sante se la come " << endl;
		exit(1);
	}
	getline(fp, linea);

	while (getline(fp, linea))
	{
		stringstream buffer(linea);

		string _dni;
		string _nombre;
		string _apellido;
		string _sexo;
		string _natalicio;
		string _estado;
		string _obra_social;

		getline(buffer, _dni, delimitador);

		getline(buffer, _nombre, delimitador);

		getline(buffer, _apellido, delimitador);

		getline(buffer, _sexo, delimitador);

		getline(buffer, _natalicio, delimitador);

		getline(buffer, _estado, delimitador);

		getline(buffer, _obra_social, delimitador);



		vector[i].dni = _dni;
		vector[i].nombre = _nombre;
		vector[i].apellido = _apellido;
		vector[i].sexo = _sexo;
		vector[i].natalicio.tm_mday = obtener_dia(_natalicio);
		vector[i].natalicio.tm_mon = obtener_mes(_natalicio);
		vector[i].natalicio.tm_year = obtener_anio(_natalicio);
		aux_estado = obtener_estado_como_numero(_estado);
		switch (aux_estado)
		{
		case 0:
			vector[i].estado = ESTADO::fallecido;
			break;
		case 1:
			vector[i].estado = ESTADO::internado;
			break;
		case 2:
			vector[i].estado = ESTADO::n_c;
			break;
		case 3:
			vector[i].estado = ESTADO::niguno;
			cout << "el estado ingresado es incorrecto." << endl;
			break;
		}
		vector[i].obra_social = _obra_social;
		i++;
	}
	fp.close();
}
int obtener_dia(string cadena)
{
	int dia = 0;
	int i = 0;
	string aux = "";
	do
	{
		if (cadena[i] != ' ') //    47/45//5
		{
			aux = aux + cadena[i];
		}
		i++;
	} while (cadena[i] != '/');
	//cout << aux << endl;
	dia = stoi(aux);
	return dia;
}
//--------------------------------------------------
int obtener_mes(string cadena)
{
	int mes = 0;
	int centinela = 0;
	int i = 0;
	string aux = "";
	do
	{
		if (cadena[i] == '/') ///   7/5/78
		{
			centinela++;
			i++;
		}

		if (centinela == 1)
		{
			aux = aux + cadena[i];
		}
		i++;
	} while (centinela < 2);
	mes = stoi(aux);
	return mes;
}
//-------------------------------------------
int obtener_anio(string cadena)
{
	int anio = 0;
	int centinela = 0;
	int i = 0;
	string aux = "";
	do
	{
		if (cadena[i] == '/') ///   7/5/78
		{
			centinela++;
			i++;
		}

		if (centinela == 2)
		{
			aux = aux + cadena[i];
		}
		i++;
	} while (cadena[i] != '\0');
	anio = stoi(aux);
	return anio;
}

bool obtener_presento(string cadena)
{
	if (cadena[0] == '0')
	{
		return false;
	}
	else
	{
		return true;
	}
}

int obtener_estado_como_numero(string estado_paciente)
{
	if (estado_paciente == "fallecido")
	{
		return 0;
	}
	else if (estado_paciente == "internado")
	{
		return 1;
	}
	else if (estado_paciente == "n_c")
	{
		return 2;
	}
	else
	{
		return 3;
	}
	return 4;
}
//--------------------------------------------
bool verificar_tiempo_10anios(tm fecha_turno)
{

	time_t tSac = time(NULL); // instante actual
	tm actual = *localtime(&tSac);
	//---------------------------
	float decada;
	if (actual.tm_year - fecha_turno.tm_year > 10)
	{
		return true;
	}
	else if (actual.tm_year - fecha_turno.tm_year == 10 && fecha_turno.tm_mon - actual.tm_mon <= 0)
	{
		return true;
	}
	else if (actual.tm_year - fecha_turno.tm_year == 10 && actual.tm_mon - fecha_turno.tm_mon == 0 && actual.tm_mday - fecha_turno.tm_mday <= 0)
	{
		return true;
	}
	else {
		return false;
	}
}
void agregar_paciente_a_historia_clinica_irrecuperables(historia_clinica_t* lista, historia_clinica_t paciente, int& cantidad)
{
	historia_clinica_t* aux = new historia_clinica_t[cantidad + 1];
	for (int i = 0; i < cantidad; i++)
	{
		aux[i] = lista[i];
	}
	aux[cantidad] = paciente;
	lista = aux;
	delete[] aux;
	cantidad++;
}

void cargar_estructura_irrecupeables_a_archivo_irrecuperable(historia_clinica_t* lista, int cantidad) //agrega un paciente al archivo de irrecuperables
{
	ofstream fp;
	fp.open("irrecuperables.txt", ios::app);
	if (!fp.is_open())
	{
		exit(1);
	}
	for (int i = 0; i < cantidad; i++)
	{
		//fp << lista[i].dni_paciente << "," << lista[i].cita_concurrida << "," << lista[i].estado << "," << lista[i].fecha_ultima_cita.tm_mday << "/" << lista[i].fecha_ultima_cita.tm_mon << "/" << lista[i].fecha_ultima_cita.tm_year << lista[i].ultimo_medico << "--->archivado" << endl;
	}
	fp.close();
}
void cargar_datos_de_un_archivo_a_una_estruct_obra_social(string file, obra_social_t* vector)
{
	int cant_registros_del_archivo = 0;
	string linea;
	int i = 0;
	char delimitador = ',';
	cant_registros_del_archivo = cantidad_de_registros(file);
	vector = new obra_social_t[cant_registros_del_archivo];
	ifstream fp;
	fp.open("ObraSocial.csv", ios::in);
	if (!fp.is_open())
	{
		cout << "no se puede abrir el archivo" << endl;
		exit(1);
	}
	getline(fp, linea);
	while (getline(fp, linea))
	{
		stringstream buffer(linea);
		string _id;
		string _obra_social;
		getline(buffer, _id, delimitador);
		getline(buffer, _obra_social, delimitador);
		
		vector[i].id_os = stoi(_id);
		vector[i].estado_obra_social = _obra_social;
		i++;
	}
	fp.close();
}

void agregar_paciente_a_secretaria(contactos_t* lista_secretaria, string dni, contactos_t* lista_contactos, int& cantidad)
{
	contactos_t* aux = new contactos_t[cantidad + 1];
	for (int i = 0; i <cantidad ; i++)
	{
		if (lista_contactos[i].dni_paciente == dni)
		{
			for (int j = 0; j < cantidad; j++)
			{
				aux[j] = lista_secretaria[j];
			}
			aux[cantidad] = lista_contactos[i];
			lista_secretaria = aux;
			cantidad++;
			delete[] aux;
		}
		else {
			cout << "no se encontro el dni en el archivo consultas." << endl;
		}
	}
}
void mandar_archivo_a_secretaria(int cant_consultas, int cant_pacientes, contactos_t* lista_a_secretaria, int _cant_de_contactos_secretaria, pacientes_t* lista_pacientes, consultas_t* lista_consultas)
{
	int dia=0;
	int mes=0;
	int anio = 0;
	string aux_obrasocial;
	string mensaje;
	ofstream fp1;
	srand(time(NULL));
	int valor_para_saber_si_retorna = 0;
	int valor_para_obras_social = 0;
	string retorna;

	fp1.open("contactos_de_secretaria.txt", ios::app);
	//fp2.open("archivo_paciente_medico_y_ultima_consulta",ios::app);
	if (!fp1.is_open())
	{
		cout << "no se pudo abrir archivo contactos_de_secretaria.txt." << endl;
		exit(1);
	}

	for (int i = 0; i < _cant_de_contactos_secretaria; i++)
	{
		valor_para_saber_si_retorna = rand() + 2;
		if (valor_para_saber_si_retorna == 0)
		{
			retorna = "retorna";
			valor_para_obras_social = 1 + rand() + 7;
			switch (valor_para_obras_social)
			{
			case 1: aux_obrasocial = "Medicus";
				break;
			case 2:aux_obrasocial = "OSDE";
				break;
			case 3:aux_obrasocial = "IOSFA";
				break;
			case 4:aux_obrasocial = "Italiano";
				break;
			case 5:aux_obrasocial = "Aleman";
				break;
			case 6:aux_obrasocial = "Espanyol";
				break;
			default:aux_obrasocial = "sigue con la misma bra social";
				break;
			}

			for (int j = 0; j < cant_consultas; j++)
			{
				if (lista_a_secretaria[i].dni_paciente == lista_consultas[j].dni_pac)
				{
					lista_consultas[j].fecha_turno.tm_mday = 1 + rand()% 32;
					lista_consultas[j].fecha_turno.tm_mon = 1 + rand() % 13;
					lista_consultas[j].fecha_turno.tm_year = 2022 + rand() % 2023;
					dia = lista_consultas[j].fecha_turno.tm_mday;
					mes = lista_consultas[j].fecha_turno.tm_mon;
					anio = lista_consultas[j].fecha_turno.tm_year;
				}
			}
			for (int j = 0; j < cant_pacientes; j++)
			{
				if (lista_a_secretaria[i].dni_paciente == lista_pacientes[j].dni)
				{
					if (lista_pacientes[j].obra_social != aux_obrasocial)
					{
						mensaje = "su obra socail cambio y la nueva es: " + aux_obrasocial;
						cout << "su obra socail cambio y la nueva es: " << aux_obrasocial << endl;
					}
					else
					{
						mensaje = "no caambio su obra social. ";
							cout << "no caambio su obra social. " << endl;
					}
				}
			}
		}
		else
		{
			retorna = "no retorna";
		}

		fp1 << lista_a_secretaria[i].dni_paciente << "," << lista_a_secretaria[i].telefono << "," << lista_a_secretaria[i].celular << "," << lista_a_secretaria[i].direccion << "," << lista_a_secretaria[i].mail << "," << retorna << "," << valor_para_obras_social << "," << "," << lista_a_secretaria[i].celular << "," << lista_a_secretaria[i].direccion << "," << lista_a_secretaria[i].mail << "," << retorna << "," << valor_para_obras_social << "," << dia<< "/" << mes << "/" << anio << "," << mensaje << endl;

	}

	fp1.close();

}

void crear_archivo_pacientes_medico_ultima_consulta(pacientes_t* list_pacientes, medicos_t* list_medicos, consultas_t* list_consultas, contactos_t* list_contactos, int cant_contactos, int cant_pac, int cant_med, int cant_consul)
{
	ofstream fp;
	char coma = ',';
	string _nombre;
	string _apellido;
	string _telefono;
	string _matricula_medico;
	string _obra_social;
	fp.open("archivo_paciente_medico_y_ultima_consulta", ios::app);

	if (!fp.is_open())
	{
		cout << "no se pudo abrir el archivo." << endl;
		exit(1);
	}
	else
	{  // -matricula_medico(cons)
		for (int i = 0; i < cant_pac; i++)
		{
			if (verificar_tiempo_10anios(list_consultas[i].fecha_turno) != true)// es < 10 años
			{
				_nombre = list_pacientes[i].nombre;
				_apellido = list_pacientes[i].apellido;
				_obra_social = list_pacientes[i].obra_social;
				for (int j = 0; j < cant_contactos; j++)
				{
					if (list_pacientes[i].dni == list_contactos[j].dni_paciente)
					{
						_telefono = list_contactos[j].telefono;
					}
					break;
				}
				for (int k = 0; k < cant_consul; k++)
				{
					if (list_pacientes[i].dni == list_consultas[k].dni_pac)
					{
						_matricula_medico = list_consultas[k].matricula_med;
					}
					break;
				}
			}
		}
	}

	fp << _nombre << "," << _apellido << "," << _telefono << "," << _matricula_medico << "," << _obra_social << endl;
	fp.close();
}

