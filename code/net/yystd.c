#include "yystd.h"
#include <stdio.h>


//static  the function defined in .cpp file only can be used in this file even if it is declared in .h file
 void yyprintf()
{
	printf("static object probe\n");

}
