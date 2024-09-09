#include <strng.h>



int ncopy (void* to, void* from, int len)
{
	int							cur;
	unsigned char*				c_to = to;
	unsigned char*				c_from = from;


	for ( cur = 0; cur < len; cur++)	*c_to++ = *c_from++;


	return cur;
}
