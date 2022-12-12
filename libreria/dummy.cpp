#include"dummy.h"

using namespace std;

int cantidad_de_registros(string _file)
{
	ifstream fp;
	string linea;
	char delimitador = ',';
	int contador = 0;
	fp.open(_file, ios::in);
	if (!fp.is_open())
	{
		cout << "el archivo no se pudo abrir para contar registros" << endl;
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
consultas_t* cargar_datos_de_un_archivo_a_una_estruct_consulta(string file,consultas_t* vector)
{											//(archivo_consultas,lista_consultas)
	string linea;
	int i = 0;
	char delimitador = ',';
	int cant = cantidad_de_registros(file);
	
	vector = new consultas_t[cant];
	//consultas_t aux = {" ",{ 0,0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0,0 },false," "};
	ifstream fp;//IRI_Consultas.csv
	fp.open(file, ios::in);

	if (!fp.is_open())
	{
		cout << " error al abrir el archivo de cosultas " << endl;
	}
	else
	{
		cout << cant << endl;
		getline(fp, linea); // guarda la primera fila en linea
		int i = 0;
		while (/*!fp.eof()&&i<cant_registros_en_el_archivo*/ getline(fp, linea))
		{
			string _dni;
			string _fecha_solicitado;
			string _fecha_turno;
			string _presento;
			string _matricula;

			stringstream buffer(linea);// buffer="451078121 , 03/08/2008 , 09/10/2008 , 1 , 01-114-7331"

			getline(buffer, _dni, delimitador);

			getline(buffer, _fecha_solicitado, delimitador);

			getline(buffer, _fecha_turno, delimitador);

			getline(buffer, _presento, delimitador);

			getline(buffer, _matricula, delimitador);
			
			vector[i].dni_pac = _dni;
			vector[i].fecha_solicitado.tm_mday = obtener_dia(_fecha_solicitado);
			vector[i].fecha_solicitado.tm_mon = obtener_mes(_fecha_solicitado);
			vector[i].fecha_solicitado.tm_year = obtener_anio(_fecha_solicitado);
			vector[i].fecha_turno.tm_mday = obtener_dia(_fecha_turno);
			vector[i].fecha_turno.tm_mon = obtener_mes(_fecha_turno);
			vector[i].fecha_turno.tm_year = obtener_anio(_fecha_turno);
			vector[i].presento = obtener_presento(_presento);
			vector[i].matricula_med = _matricula;
			//cout << vector[i].dni_pac<<"-" <<vector[i].matricula_med<< "-"<< vector[i].fecha_solicitado.tm_mday<<"-"<< vector[i].fecha_solicitado.tm_mon <<"-"<< vector[i].fecha_solicitado.tm_year << endl;
			i++;
		}
	}
	fp.close();
	cout << "......." << endl;
	return vector;
}
//---------------------------------------------------------------
void agregar_consulta(consultas_t* vector, consultas_t  aux, int* tamanio) 
{
	/*int uno = 1;
	consultas_t* list_aux = new consultas_t[*tamanio +uno];
	for (int i  = 0;  i< *tamanio-1; i++)
	{
			list_aux[i] = vector[i];
	}
	list_aux[*tamanio] = aux;
	delete[] vector;
	vector = list_aux;
	tamanio++;*/
}

contactos_t* cargar_datos_de_un_archivo_a_una_estruct_contactos(string file, contactos_t* vector)
{
	int cant_registros_del_archivo = 0;
	string linea;
	int i = 0;
	char delimitador = ',';
	cant_registros_del_archivo = cantidad_de_registros(file);
	vector = new contactos_t[cant_registros_del_archivo];
	ifstream fp;
	fp.open(file, ios::in);
	if(!fp.is_open())
	{
		cout << "no se puede abrir el archivo contactos " << endl;
		exit(1);
	}
	getline(fp, linea);
	cout << "la cantidad de registro de contactos es: " << cant_registros_del_archivo << endl;
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
	return vector;
}
//------------------------------------------------------------

medicos_t* cargar_datos_de_un_archivo_a_una_estruct_medicos(string file, medicos_t* vector)
{
	int cant_registros_del_archivo = 0;
	string linea;
	int i = 0;
	char delimitador = ',';
	cant_registros_del_archivo = cantidad_de_registros(file);
	vector = new medicos_t[cant_registros_del_archivo];
	ifstream fp;
	fp.open(file, ios::in);
	if(!fp.is_open())
	{
		cout << "no se puede abrir el archivo medicos " << endl;
		exit(1);
	}
	cout << " cantidad de registros de archivo medicos: " << cant_registros_del_archivo << endl;
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
	return vector;
}
//-------------------------------------------

pacientes_t* cargar_datos_de_un_archivo_a_una_estruct_pacientes(string file, pacientes_t* vector)
{
	int aux_estado = 3;
	int cant_registros_del_archivo = 0;
	string linea;
	int i = 0;
	char delimitador = ',';
	cant_registros_del_archivo = cantidad_de_registros(file);
	vector = new pacientes_t[cant_registros_del_archivo];
	ifstream fp;
	fp.open(file, ios::in);
	if(!fp.is_open())
	{
		cout << "no se puede abrir el archivo pacientes " << endl;
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
			//cout << "el estado ingresado es falecido." << endl;
			break;
		case 1:
			vector[i].estado = ESTADO::internado;
			//cout << "el estado ingresado es internaod." << endl;
			break;
		case 2:
			vector[i].estado = ESTADO::n_c;
			//cout << "el estado ingresado es n_c." << endl;
			break;
		}
		vector[i].obra_social = _obra_social;
		i++;
	}
	fp.close();
	return vector;
}

int obtener_dia(string cadena)////, 03/08/2008
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
	if (cadena[1] == '0')
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
	if (estado_paciente == " fallecido ")
	{
		return 0;
	}
	else if (estado_paciente == " internado ")
	{
		return 1;
	}
	else //if (estado_paciente == " n_c ")
	{
		return 2;
	}
}

//--------------------------------------------
bool verificar_tiempo_10anios(tm fecha_turno)
{
	time_t t = time(0);      // get time now
	tm* actual= localtime(&t);
	int diferencia = 0;
	/*cout << (now->tm_year + 1900) << '-'
		<< (now->tm_mon + 1) << '-'
		<< now->tm_mday
		<< "\n";*/
	//--------------------------
	if (((actual->tm_year + 1900) - fecha_turno.tm_year) > 10)
	{
		return true;

	}
	else if (((actual->tm_year + 1900) - fecha_turno.tm_year) == 10)
	{
		if ((actual->tm_mon + 1)>fecha_turno.tm_mon)
		{
			return true;
		}
		else if((actual->tm_mon + 1) == fecha_turno.tm_mon)
		{
			if (actual->tm_mday>fecha_turno.tm_mday)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}else//((actual->tm_year + 1900) - fecha_turno.tm_year) < 10)
	{
		return false;
	}
	
}

void agregar_paciente_a_historia_clinica_irrecuperables(historia_clinica_t*& lista, historia_clinica_t historia_clinica_para_agregar, int* tamanio_actual)
{
	*tamanio_actual = *tamanio_actual + 1;
	int i = 0;
	historia_clinica_t* aux = new historia_clinica_t[*tamanio_actual];
	while (i < *tamanio_actual - 1 && *tamanio_actual - 1 != 0) {
		aux[i] = lista[i];
		i++;
	}

	aux[i] = historia_clinica_para_agregar;
	delete[] lista;
	lista = aux;
	return;
}


void cargar_estructura_irrecupeables_a_archivo_irrecuperable(historia_clinica_t*& lista, int* cantidad) //agrega un paciente al archivo de irrecuperables
{
	fstream fp;
	fp.open("irrecuperables.txt", ios::out);//  ios::out||ios::app
	if (!fp.is_open())
	{ 
		cout << "el archivo no se puede abrir." << endl;
		exit(1);
	}
	for (int i = 0; i < *cantidad; i++)
	{
		fp << lista[i].dni_paciente << " - " << lista[i].fecha_ultima_cita.tm_mday << "/" << lista[i].fecha_ultima_cita.tm_mon << "/" << lista[i].fecha_ultima_cita.tm_year << " - " << lista[i].cita_concurrida << " - " << lista[i].ultimo_medico << endl;
	}
	fp.close();
}
void imprimir_archivo(string archivo)
{
	ifstream fp;
	string linea;
	fp.open(archivo, ios::in);
	if (!fp.is_open())
	{
		cout << "el archivo de irrecuperables no se pudo abrir. " << endl;
	}
	else
	{
		while (getline(fp, linea))
		{
			cout << linea << endl;
		}
	}
	fp.close();
}
/*
void cargar_datos_de_un_archivo_a_una_estruct_obra_social(string file, obra_social_t* vector)
{
	int cant_registros_del_archivo = 0;
	string linea;
	int i = 0;
	char delimitador = ',';
	cant_registros_del_archivo = cantidad_de_registros(file);
	vector = new obra_social_t[cant_registros_del_archivo];
	ifstream fp;
	fp.open(file, ios::in);
	if (!fp.is_open())
	{
		cout << "no se puede abrir el archivo obra social " << endl;
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
*/
void agregar_contacto_a_la_lista_de_secretaria(contactos_t*& lista_secretaria, contactos_t aux_contacto, int* cantidad)
{
	int i = 0;
	*cantidad = *cantidad + 1;
	contactos_t* aux = new contactos_t[*cantidad];
	while (i < *cantidad - 1 && *cantidad - 1 != 0) {
		aux[i] = lista_secretaria[i];
		i++;
	}

	aux[i] = aux_contacto;
	delete[] lista_secretaria;
	lista_secretaria = aux;
	return;

}
void mandar_archivo_a_secretaria(int cant_consultas, int cant_pacientes, contactos_t*& lista_a_secretaria, int _cant_de_contactos_secretaria, pacientes_t*& lista_pacientes, consultas_t*& lista_consultas)
{
	int dia=0;
	int mes=0;
	int anio = 0;
	string aux_obrasocial;
	string mensaje;
	ofstream fp1;
	srand(time(NULL));
	
	 int valor_para_saber_si_retorna = 0;
	int valor_para_obras_social =0;
	string retorna;

	fp1.open("contactos_de_secretaria.txt", ios::out);
	//fp2.open("archivo_paciente_medico_y_ultima_consulta",ios::app);
	if (!fp1.is_open())
	{
		cout << "no se pudo abrir archivo contactos_de_secretaria.txt." << endl;
		exit(1);
	}

	for (int i = 0; i < _cant_de_contactos_secretaria; i++)
	{
		valor_para_saber_si_retorna = rand()% 2;// si y no 
		if (valor_para_saber_si_retorna == 0)
		{
			retorna = "retorna";
			valor_para_obras_social = 1 + rand() % 7;
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

			for (int j = 0; j < cant_consultas; j++)//para estableces la nueva fecha_turno del que retorna
			{
				if (lista_a_secretaria[i].dni_paciente == lista_consultas[j].dni_pac)
				{
					lista_consultas[j].fecha_turno.tm_mday = 1 + rand()% 32;
					lista_consultas[j].fecha_turno.tm_mon = 1 + rand() % 13;
					lista_consultas[j].fecha_turno.tm_year = 2022 + rand() % 2024;
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

		fp1 << lista_a_secretaria[i].dni_paciente << "," << lista_a_secretaria[i].telefono << "," << lista_a_secretaria[i].celular << "," << lista_a_secretaria[i].direccion << "," << lista_a_secretaria[i].mail << "," << retorna << "," << valor_para_obras_social << "," << dia<< "/" << mes << "/" << anio << "," << mensaje << endl;

	}

	fp1.close();

}

void crear_archivo_pacientes_medico_ultima_consulta(pacientes_t*& list_pacientes, int* cant_pac, consultas_t*& list_consultas,int* cant_consul, contactos_t*& list_contactos_secretaria, int* cant_contactos_secretaria,medicos_t*& list_medicos,int* cant_medicos )
{
	ofstream fp;
	char coma = ';';
	string _dni_paciente;
	string _nombre_paciente;//--
	string _apellido_paciente;//--
	string _telefono_paciente;//----

	string _nombre_medico;
	string _apellido_medico;
	string _telefono_medico;
	string _matricula_medico;
	
	string aux_matricula;
	fp.open("archivo_paciente_medico_y_ultima_consulta.txt", ios::out);

	if (!fp.is_open())
	{
		cout << "no se pudo abrir el archivo." << endl;
	}
	else
	{
		for (int i = 0; i < *cant_contactos_secretaria; i++)
		{
			for (int j = 0; j < *cant_consul; j++)
			{
				if (list_contactos_secretaria[i].dni_paciente == list_consultas[j].dni_pac)
				{
					aux_matricula = list_consultas[j].matricula_med;
				}
			}
		}


		for (int i = 0; i < *cant_contactos_secretaria; i++)
		{
			_dni_paciente = list_contactos_secretaria[i].dni_paciente;
			_telefono_paciente = list_contactos_secretaria[i].telefono;
			for (int j = 0; j <*cant_pac ; j++)
			{
				if (list_contactos_secretaria[i].dni_paciente == list_pacientes[j].dni)
				{
					_nombre_paciente = list_pacientes[j].nombre;
					_apellido_paciente = list_pacientes[j].apellido;
				}
				for (int k = 0; k <*cant_medicos ; k++)
				{
					if (list_medicos[k].matricula==aux_matricula)
					{
						_nombre_medico = list_medicos[k].nombre;
						_apellido_medico = list_medicos[k].apellido;
						_telefono_medico = list_medicos[k].telefono;
					}
				}

			}

			fp << _dni_paciente << ";" << _nombre_paciente << ";" << _apellido_paciente << ";" << _telefono_paciente <<";"<<aux_matricula<< endl;//----
		}
	}
	fp.close();
}




