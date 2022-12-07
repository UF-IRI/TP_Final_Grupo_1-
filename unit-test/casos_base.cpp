#include "gmock/gmock.h"
//#include"funciones.h"
#include"dummy.h"
using namespace std;
namespace Casos_Base::tests {

	TEST(testeo1, Example)
	{
		string aux = "0";
		ASSERT_FALSE(obtener_presento(aux));
	}
	TEST(testeo2, Example)
	{
		string aux = "0";
		ASSERT_TRUE(obtener_presento(aux));
	}
	TEST(testeo3, Example)
	{
		string aux = "7/3/2020";
		ASSERT_EQ(7, obtener_dia(aux));
	}
	TEST(testeo4, Example)
	{
		string aux = "7/3/2020";
		ASSERT_TRUE(obtener_mes(aux));
	}
	TEST(testeo5, Example)
	{
		string aux = "7/3/2020";
		ASSERT_TRUE(obtener_anio(aux));
	}
	/*TEST(Casos_Base, Test_Caso1) {
		ASSERT_THAT(1, 1);
	}
	TEST(Casos_Base, Test_Caso2) {
		ASSERT_THAT(1, 1);
	}

	TEST(Casos_Base, Test_Caso3) {
		ASSERT_THAT(1, 1);
	}*/
	//-------------------------------------
	//TEST(Casos_Base, Test_Caso1) {
	//	paciente_t* list_pacientes = new paciente_t[12];

	//	//dni, nombre, apellido, sexo, natalicio, estado, id_os
	//	list_pacientes[0] = { 456501088 , Winfield , Fetter , M , 5 / 11 / 2016 , internado , IOSFA };
	//	list_pacientes[1] = { 454792376, Britteny, Veel, F, 1 / 4 / 1970, fallecido, Italiano };
	//	list_pacientes[2] = { 783659576, Ernie, Iacovelli, M, 6 / 18 / 1968, fallecido, OSDE };
	//	list_pacientes[3] = { 070686285, Grantley, Larwell, M, 2 / 21 / 1976, n / c, Aleman };
	//	list_pacientes[4] = { 887095128, Edita, Gillfillan, F, 6 / 20 / 2013, n / c, Espanyol };
	//	list_pacientes[5] = { 501982285, Harmonia, Williscroft, F, 3 / 23 / 1964, n / c, IOSFA };
	//	list_pacientes[6] = { 450394726, Roi, Stanier, M, 6 / 5 / 1977, n / c, Medicus };
	//	list_pacientes[7] = { 336407375, Salim, McKintosh, M, 3 / 2 / 1958, internado, OSDE };
	//	list_pacientes[8] = { 583220578, Mirna, Izhaky, F, 11 / 9 / 2005, fallecido, Italiano };
	//	list_pacientes[9] = { 112855825, Derrek, Dadley, M, 8 / 29 / 1995, internado, Medicus };
	//	list_pacientes[10] = { 427921914, Abby, Rowberry, M, 3 / 7 / 1974, internado, Espanyol };
	//	list_pacientes[11] = { 104039798, Elnar, Adderson, M, 4 / 4 / 1955, internado, Aleman };
	//	ASSERT_FALSE(eliminar_paciente(list_pacientes, 5, 12);


}


