#include "gmock/gmock.h"
#include"funciones.h"
using namespace std;
namespace foobar::tests {
	TEST(ExampleTests, Example) {
        ASSERT_THAT(1, 1);
	}
	TEST(testeo1, Example) {//
		string _dni = "234321";
		ASSERT_TRUE(Comprobacion_dni(_dni));
	}
	TEST(testeo2, Example) {//
		string _dni = "wefrgtb";
		ASSERT_TRUE(Comprobacion_dni(_dni));
	}
	TEST(testeo2, Example) {//
		
	}



}