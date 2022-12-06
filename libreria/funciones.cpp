#include"funciones.h"

using namespace std;
Consultas::Consultas()
{
	dni_pac = " ";
	fecha_solicitado = { 0,0,0,0,0,0,0,0,0 };
	fecha_turno = { 0,0,0,0,0,0,0,0,0 };
	presento = false;
	matricula_med = " ";
};

Historia_clinica::Historia_clinica()
{
	dni_paciente = "";
	fecha_ultima_cita = { 0,0,0,0,0,0,0,0,0 };
	cita_concurrida = false;
	ultimo_medico = "";
	estado = ESTADO::niguno;
};
Medicos::Medicos()
{
	matricula = " ";
	nombre = " ";
	apellido = " ";
	telefono = " ";
	especialidad = " ";
	activo = false;
};

Contactos::Contactos()
{
	dni_paciente = " ";
	telefono = " ";
	celular = " ";
	direccion = " ";
	mail = " ";
}

Pacientes::Pacientes()
{
	string dni = " ";
	string nombre = " ";
	string apellido = " ";
	sexo = '0';
	natalicio = { 0,0,0,0,0,0,0,0,0 };
	estado = ESTADO::niguno;
	obra_social = " ";
}
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
consultas_t* cargar_datos_de_un_archivo_a_una_estruct_consulta(string file, consultas_t* vector)
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
	return vector;
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
	return vector;
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
bool verificar_tiempo_10anios(string  _dni_paciente)
{
	fstream fp;
	//Paciente aux2;
	historia_clinica_t aux;
	//Contacto aux3;
	char coma = ',';
	fp.open("Historia_clinica.csv", ios::in);
	if (!fp.is_open())
	{
		cout << " No se pudo abrir";
		exit(1);
	}
	while (fp)
	{
		fp >> aux.dni_paciente >> coma >> aux.fecha_ultima_cita.tm_mday >> coma
			>> aux.fecha_ultima_cita.tm_mon >> aux.fecha_ultima_cita.tm_year >> coma >>
			aux.cita_concurrida >> coma >> aux.reprogramacion_fecha >> coma >>
			aux.ultimo_medico >> coma >> aux.fecha_de_reprogramacion.tm_mday >> coma >>
			aux.fecha_de_reprogramacion.tm_mon >> aux.fecha_de_reprogramacion.tm_year >> aux.estado;

		if (aux.dni_paciente == _dni_paciente)
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
	}
	fp.close();

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
		fp << lista[i].dni_paciente << "," << lista[i].cita_concurrida << "," << lista[i].estado << "," << lista[i].fecha_ultima_cita.tm_mday << "/" << lista[i].fecha_ultima_cita.tm_mon << "/" <<lista[i].fecha_ultima_cita.tm_year << lista[i].ultimo_medico<<"--->archivado" << endl;
	}
	fp.close();
}
obra_social_t* cargar_datos_de_un_archivo_a_una_estruct_obra_social(string file, obra_social_t* vector)
{
	int cant_registros_del_archivo = 0;
	string linea;
	int i = 0;
	char delimitador = ',';
	cant_registros_del_archivo = cantidad_de_registros(file);
	vector = new obra_social_t[cant_registros_del_archivo];
	ifstream fp;
	fp.open("ObraSocial.csv", ios::in);
	{
		cout << "no se puede abrir el archivo" << endl;
		exit(1);
	}
	getline(fp, linea);
	while (getline(fp, linea))
	{
		string _id;
		string _obra_social;
		getline(buffer, _id, delimitador);
		getline(buffer, _obra_social, delimitador);

		vector[i] = stoi(_di);
		vector[i] = _obra_social;
		i++;
	}
	fclose(fp);
	return vector;
}

void agregar_paciente_a_secretaria(contactos_t* lista_secretaria, string dni, contactos_t* lista_contactos, int& cantidad)
{
	contactos_t* aux = new contactos_t[cantidad + 1];
	for (int i = 0; i < cantidad_de_registros(lista_contactos); i++)
	{
		if (lista_contactos[i].dni_paciente == dni)
		{
			for (int j = 0; j <cantidad ; j++)
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
void mandar_archivo_a_secretaria(int cant_consultas,int cant_pacientes,contactos_t* lista_a_secretaria, int _cant_de_contactos_secretaria,pacientes_t* lista_pacientes, consultas_t* lista_consultas)
{
	string aux_obrasocial;
	string mensaje;
	ofstream fp;
	srand(time(NULL));
	int valor_para_saber_si_retorna = 0;
	int valor_para_obras_social = 0;
	string retorna;
	fp.open("contactos_de_secretaria.txt", ios::app);
	if (!fp.is_open())
	{
		exit(1);
	}
	for (int i = 0; i < _cant_de_contactos_secretaria; i++)
	{
		valor_para_saber_si_retorna = rand() + 2;
			if (valor_para_saber_si_retorna ==0)
			{
				retorna = "retorna";
				valor_para_obras_social = 1+rand() + 7;
				switch (valor_para_obras_social)
				{
				case 1: aux_obrasocial = "Medicus";
					break;
				case 2:aux_obrasocial ="OSDE"
					break;
				case 3:aux_obrasocial ="IOSFA"
					break;
				case 4:aux_obrasocial ="Italiano"
					break;
				case 5:aux_obrasocial ="Aleman"
					break;
				case 6:aux_obrasocial ="Espanyol"
					break;
				default:aux_obrasocial = "sigue con la misma bra social";
					break;
				}

				for (int j = 0; j <cant_consultas; j++)
				{
					if (lista_a_secretaria[i].dni_paciente==lista_consultas[j].dni_pac)
					{
						lista_consultas[j].fecha_turno.tm_mday = 1 + rand() + 32;
						lista_consultas[j].fecha_turno.tm_mon == 1 + rand()+13;
						lista_consultas[j].fecha_turno.tm_year == 2022 + rand()+2023 ;
					}
				}
				for (int j = 0; j < cant_pacientes; j++)
				{
					if (lista_a_secretaria[i].dni_paciente==lista_pacientes[j])
					{
						if (lista_pacientes[j].obra_social!=aux_obrasocial)
						{ 
							mensaje = "su obra socail cambio y la nueva es: " + aux_obrasocial;
							cout << "su obra socail cambio y la nueva es: " << aux_obrasocial << endl;
						}
						else
						{
							mensaje="no caambio su obra social. "
							cout << "no caambio su obra social. " << endl;
						}
					}
				}
			}
			else
			{
				retorna = "no retorna";
			}

		fp << lista_a_secretaria[i].dni_paciente << "," << lista_a_secretaria[i].telefono << "," << lista_a_secretaria[i].celular<<"," << lista_a_secretaria[i].direccion<<"," << lista_a_secretaria[i].mail <<","<< retorna<<"," << valor_para_obras_social<< "," << lista_consultas[j].fecha_turno.tm_mday <<"," << lista_a_secretaria[i].celular << "," << lista_a_secretaria[i].direccion << "," << lista_a_secretaria[i].mail << "," << retorna << "," << valor_para_obras_social << ","<< lista_consultas[j].fecha_turno.tm_mday<<"/" << lista_consultas[j].fecha_turno.tm_mon << "/" << lista_consultas[j].fecha_turno.tm_year<<","<<mensaje<< endl;
	}

	fp.close();

}



