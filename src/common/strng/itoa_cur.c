#include <strng.h>



unsigned char* itoa_cur (unsigned char* from, int* num)
{
	*num = 0;
	while ( '0' <= *from && *from <= '9' )		*num = (*num * 10) + (*from++ & 0xf);


	return from;
}
