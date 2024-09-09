#include <socks.h>



void parse_ipv4 (unsigned char* str)
{
	struct sockaddr_in* 		addr = (struct sockaddr_in*) &socks___addr;
	int							ipv4 = 0;
	int							port = 0;
	int							temp = 0;


	for (int i=3; i>=0; i--) {
		str = itoa_cur(str, &temp) + 1;
		ipv4 |= temp << i*8;
	}
	itoa_cur(str, &port);

	for (int i=0; i<sizeof(struct sockaddr_in); i++) 		*((char*)addr + i) = 0;
	addr->sin_family			= socks___sockfam;
	addr->sin_port				= htons(port);
	addr->sin_addr.s_addr		= htonl(ipv4);

	socks___addrlen = sizeof(struct sockaddr_in);
}
