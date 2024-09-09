#include <strng.h>



int getlen (const unsigned char* str)
{
	int							len = 0;


	while ( *str++ )		len++;

	
	return len;
}
