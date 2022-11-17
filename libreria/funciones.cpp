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

consultas_t* cargar_datos_de_un_archivo_a_una_estruct_consulta(string file, consultas_t* vector)
{
	int cant_registros_en_el_archivo;
	string linea;
	int i = 0;
	char delimitador = ',';
	cant_registros_en_el_archivo = cantidad_de_registros(file);
	vector = new consultas_t[cant_registros_en_el_archivo];
	ifstream fp;
	fp.open(file, ios::in);
	if (fp.fail())
	{
		cout << "no se pudo abrir el archivo" << endl;
		exit(1);
	}
	getline(fp, linea);
	while (/*!fp.eof()&&i<cant_registros_en_el_archivo*/getline(fp, linea))
	{
		stringstream buffer(linea);
		string _dni_pac;
		string _fecha_solicitado;
		string _fecha_turno;
		string _presento;
		string _matricula_med;
		getline(buffer,_dni_pac , delimitador);
		getline(buffer, _fecha_solicitado, delimitador);
		getline(buffer, _fecha_turno, delimitador);
		getline(buffer, _presento, delimitador);
		getline(buffer, _matricula_med, delimitador);


		vector[i].dni_pac =_dni_pac;
		vector[i].fecha_solicitado = _fecha_solicitado;
		vector[i].fecha_turno =_fecha_turno;
		vector[i].presento = _presento;
		vector[i].matricula_med = _matricula_med;
	
		/*fp >> lista[i]._dni >> delimitador >> lista[i]._nombre >> delimitador >> lista[i]._apellido >> delimitador >> lista[i]._sexo >> delimitador >> lista[i]._fecha_de_nacimiento >> delimitador >> lista[i]._id_os;
		*/
		i++;
	}
	/*for (int i = 0; i < cant_registros_en_el_archivo; i++)
	{
		cout << vector[i].dni_pac << delimitador << vector[i].fecha_solicitado << delimitador << vector[i].fecha_turno << delimitador << vector[i].presento << delimitador << vector[i].matricula_med << endl;
	}*/
	fp.close();
	return vector;
}
contactos_t* cargar_datos_de_un_archivo_a_una_estruct_contactos(string file, contactos_t* vector)
{
		int cant_registros_en_el_archivo;
		string linea;
		int i = 0;
		char delimitador = ',';
		cant_registros_en_el_archivo = cantidad_de_registros(file);
		vector = new consultas_t[cant_registros_en_el_archivo];
		ifstream fp;
		fp.open(file, ios::in);
		if (fp.fail())
		{
			cout << "no se pudo abrir el archivo" << endl;
			exit(1);
		}
		getline(fp, linea);
		while (/*!fp.eof()&&i<cant_registros_en_el_archivo*/getline(fp, linea))
		{
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


			vector[i].dni_paciente=_dni_paciente;
			vector[i].telefono=_telefono;
			vector[i].celular=_celular;
			vector[i].direccion=_direccion;
			vector[i].mail=_mail;

			/*fp >> lista[i]._dni >> delimitador >> lista[i]._nombre >> delimitador >> lista[i]._apellido >> delimitador >> lista[i]._sexo >> delimitador >> lista[i]._fecha_de_nacimiento >> delimitador >> lista[i]._id_os;
			*/
			i++;
		}
		/*for (int i = 0; i < cant_registros_en_el_archivo; i++)
		{
		cout<<vector[i].dni_paciente<<" , "<<vector[i].telefono<<" , "<<vector[i].celular<<" , "<<vector[i].direccion<<" , "<<vector[i].mail<<endl;

		}*/
		fp.close();
		return vector;
}
pacientes_t* cargar_datos_de_un_archivo_a_una_estruct_pacientes(string file, pacientes_t* vector)
{
	int cant_registros_en_el_archivo;
	string linea;
	int i = 0;
	char delimitador = ',';
	cant_registros_en_el_archivo = cantidad_de_registros(file);
	vector = new consultas_t[cant_registros_en_el_archivo];
	ifstream fp;
	fp.open(file, ios::in);
	if (fp.fail())
	{
		cout << "no se pudo abrir el archivo" << endl;
		exit(1);
	}
	getline(fp, linea);
	while (/*!fp.eof()&&i<cant_registros_en_el_archivo*/getline(fp, linea))
	{
		string _dni;
		string _nombre;
		string _apellido;
		string _sexo;
		string _natalicio;
		string _estado;
		string _id_os;

		getline(buffer, _dni, delimitador);
		getline(buffer, _nombre, delimitador);
		getline(buffer, _apellido, delimitador);
		getline(buffer, _sexo, delimitador); getline(buffer, _id_os, delimitador);
		getline(buffer, _natalicio, delimitador);
		getline(buffer, _estado, delimitador);
		getline(buffer, _id_os, delimitador);

		
		vector[i].dni=_dni;
		vector[i].nombre = _nombre;
		vector[i].apellido = _apellido;
		vector[i].sexo = _sexo;
		vector[i].natalicio=_natalicio;
		vector[i].estado=_estado;
		vector[i].id_os=_id_os;


		/*fp >> lista[i]._dni >> delimitador >> lista[i]._nombre >> delimitador >> lista[i]._apellido >> delimitador >> lista[i]._sexo >> delimitador >> lista[i]._fecha_de_nacimiento >> delimitador >> lista[i]._id_os;
		*/
		i++;
	}
	fp.close();
	return vector;
}
obrasocial_t* cargar_datos_de_un_archivo_a_una_estruct_obra_social(string file,obrasocial_t* vector)
{
	int cant_registros_en_el_archivo;
	string linea;
	int i = 0;
	char delimitador = ',';
	cant_registros_en_el_archivo = cantidad_de_registros(file);
	vector = new consultas_t[cant_registros_en_el_archivo];
	ifstream fp;
	fp.open(file, ios::in);
	if (fp.fail())
	{
		cout << "no se pudo abrir el archivo" << endl;
		exit(1);
	}
	getline(fp, linea);
	while (/*!fp.eof()&&i<cant_registros_en_el_archivo*/getline(fp, linea))
	{
		string _id_os;
		string _obra_social;
		getline(buffer, _id_os, delimitador);
		getline(buffer, _obra_social, delimitador);


		vector[i].id_os = _id_os;
		vector[i].obra_social = _obra_social;

		/*fp >> lista[i]._dni >> delimitador >> lista[i]._nombre >> delimitador >> lista[i]._apellido >> delimitador >> lista[i]._sexo >> delimitador >> lista[i]._fecha_de_nacimiento >> delimitador >> lista[i]._id_os;
		*/
		i++;
	}
	
	fp.close();
	return vector;
}
medicos_t* cargar_datos_de_un_archivo_a_una_estruct_medicos(string file, medicos_t* vector)
{
	int cant_registros_en_el_archivo;
	string linea;
	int i = 0;
	char delimitador = ',';
	cant_registros_en_el_archivo = cantidad_de_registros(file);
	vector = new consultas_t[cant_registros_en_el_archivo];
	ifstream fp;
	fp.open(file, ios::in);
	if (fp.fail())
	{
		cout << "no se pudo abrir el archivo" << endl;
		exit(1);
	}
	getline(fp, linea);
	while (/*!fp.eof()&&i<cant_registros_en_el_archivo*/getline(fp, linea))
	{
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
		vector[i].activo = _activo;
		/*fp >> lista[i]._dni >> delimitador >> lista[i]._nombre >> delimitador >> lista[i]._apellido >> delimitador >> lista[i]._sexo >> delimitador >> lista[i]._fecha_de_nacimiento >> delimitador >> lista[i]._id_os;
		*/
		i++;
	}
	fp.close();
	return vector;
}
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
//------------------------------------------------------------------------------------------------------------


