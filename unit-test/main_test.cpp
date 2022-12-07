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
		ASSERT_TRUE(obtener_mes(aux),3);
	}
	TEST(testeo5, Example)
	{
		string aux = "7/3/2020";
		ASSERT_TRUE(obtener_anio(aux),2020);
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

}