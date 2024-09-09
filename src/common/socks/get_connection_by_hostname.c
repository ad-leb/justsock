#include <socks.h>



int get_connection_by_hostname (unsigned char* str)
{
	int							count = 0;
	struct addrinfo				hint;
	struct addrinfo*			variant;



	for (int i=0; i<NAMELEN; i++) {
		socks___hostname[i] = 0;
		socks___service[i] = 0;
	}
	read_hostname(str);
	if ( socks___service[0] == 0 )		ncopy(&socks___service, DEFAULT_SERVICE, getlen(DEFAULT_SERVICE));

	for (int i=0; i<sizeof(hint); i++)		*((char*)&hint + i) = 0;
	hint.ai_family		= socks___sockfam;
	hint.ai_socktype	= socks___socktype;

	switch ( getaddrinfo(socks___hostname, socks___service, &hint, &variant) ) {	/* thx, Michael Kerrisk	*/
		case EAI_AGAIN:			/* try again										*/			return -1;
		case EAI_BADFLAGS:		/* bad flags										*/			return -1;
		case EAI_FAIL:			/* not!												*/			return -1;
		case EAI_FAMILY:		/* wrong addrinfo family							*/			return -1;
		case EAI_MEMORY:		/* my fault											*/			return -1;
		case EAI_NONAME:		/* maybe, server not know about host				*/			return -1;
		case EAI_SERVICE:		/* wrong socket type or protocol					*/			return -1;
		case EAI_SOCKTYPE:		/* wrong socket type								*/			return -1;
		case EAI_SYSTEM:		/* error in *errno*									*/			return -1;
		default:				/* ok!												*/			break;
	}

	while ( (variant) && (count++ < MAGIC_COUNT) ) {
		socks___addrlen = ncopy(&socks___addr, variant->ai_addr, variant->ai_addrlen);
		socks___sd = get_client_socket();

		if ( !~socks___sd ) 	variant = variant->ai_next;
		else					break;
	}



	return socks___sd;
}
