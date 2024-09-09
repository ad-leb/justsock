#include <socks.h>



int get_connection_by_str_ipv4 (unsigned char* str)
{
	parse_ipv4(str);
	
	return get_client_socket();
}
