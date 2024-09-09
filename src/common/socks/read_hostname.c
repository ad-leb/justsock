#include <socks.h>



void read_hostname (unsigned char* str)
{
	unsigned char*				tmp;
	int							is_service_exist = 0;



	tmp = str;
	while ( *tmp++ )
		if ( *tmp == ':' )		is_service_exist++;

	if ( is_service_exist ) 	tmp = socks___service;
	else 						tmp = socks___hostname;


	for (*str; 0x20 <= *str && *str <= 0x79; str++ ) {

		if ( *str == ':' && is_service_exist ) {
			*tmp = 0;
			tmp = socks___hostname;
			str += 2;
			continue;
		} else if ( *str == '/' || *str == '?' ) {
			break;
		}

		*tmp++ = *str;
	}
	*tmp = 0;
}
