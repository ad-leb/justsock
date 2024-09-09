#include <socks.h>



int get_client_socket ()
{
	socks___sd = socket(socks___sockfam, socks___socktype, socks___sockprot);	if ( !~socks___sd ) return -1;
	if ( !~connect(socks___sd, &socks___addr, socks___addrlen) ) {
		close(socks___sd);
		return -1;
	}


	return socks___sd;
}
