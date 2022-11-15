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