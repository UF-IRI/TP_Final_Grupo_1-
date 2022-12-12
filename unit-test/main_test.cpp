#include "gmock/gmock.h"
//#include"funciones.h"
#include"dummy.h"
using namespace testing;
namespace foobar::tests 
{
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
		ASSERT_EQ(7,obtener_dia(aux));
	}
	TEST(testeo4, Example)
	{
		string aux = "7/3/2020";
		ASSERT_EQ(7,obtener_mes(aux));
	}
	TEST(testeo5, Example)
	{
		string aux = "7/3/2020";
		ASSERT_EQ(2022,obtener_anio(aux));
	}
	TEST(testeo6, Example)
	{
		string _aux = "fallecido"; //fallecido=0, internado=1, n_c=2
		ASSERT_EQ(obtener_estado_como_numero(_aux), 0);
	}
	TEST(testeo7, Example)
	{
		string _aux = "n_c"; //fallecido=0, internado=1, n_c=2
		ASSERT_EQ(obtener_estado_como_numero(_aux), 1);
	}
	TEST(testeo8, Example)
	{
		string _aux = "6756432";
		ASSERT_FALSE(Comprobacion_dni(_aux));
	}
	TEST(testeo9, Example)
	{
		string _aux = "67564g32";
		ASSERT_TRUE(Comprobacion_dni(_aux));
	}
	TEST(testeo10, Example)
	{
		string _aux = "uhyg56432";
		ASSERT_FALSE(Comprobacion_dni(_aux));
	}
	TEST(testeo11, Example)
	{
		string _aux = "uhyg5643";
		ASSERT_FALSE(Comprobacion_dni(_aux));
	}

	TEST(testeo12, Example)
	{
		historia_clinica_t* lista = nullptr;
		ASSERT_FALSE(verificar_lista_diferente_a_nulptr_historia_clinicas(lista)); //tick
	}
	TEST(testeo13, Example)
	{
		historia_clinica_t historia_1 = { "xxx",{ 0,0,0,0,0,0,0,0,0 },false,"pepito",ESTADO::internado };
		historia_clinica_t* lista = new historia_clinica_t[2];
		lista[0] = historia_1;
		ASSERT_FALSE(verificar_lista_diferente_a_nulptr_historia_clinicas(lista)); //error
	}
	TEST(testeo14, Example)
	{
		historia_clinica_t historia_1 = { "yyy",{ 0,0,0,0,0,0,0,0,0 },false,"sandunga",ESTADO::internado };
		historia_clinica_t* lista = new historia_clinica_t[5];
		lista[0] = historia_1;
		ASSERT_TRUE(verificar_lista_diferente_a_nulptr_historia_clinicas(lista)); //error
	}






}