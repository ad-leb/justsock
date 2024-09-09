#include <socks.h>
#include <defs.h>




int								socks___sockfam = AF_INET;
int								socks___socktype = SOCK_STREAM;
int								socks___sockprot = 0;

struct sockaddr					socks___addr;
int								socks___addrlen = -1;



int								socks___sd;
unsigned char					socks___service[NAMELEN];
unsigned char					socks___hostname[NAMELEN];
unsigned char					socks___request[NAMELEN] = "domain\0";
