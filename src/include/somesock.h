#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define NAMELEN					256
#define MAGIC_COUNT				16
#define DEFAULT_SERVICE			"http"





extern int								socks___sockfam;
extern int								socks___socktype;
extern int								socks___sockprot;
extern struct sockaddr					socks___addr;
extern int								socks___addrlen;
extern int								socks___sd;
extern unsigned char					socks___service[NAMELEN];
extern unsigned char					socks___hostname[NAMELEN];
extern unsigned char					socks___request[NAMELEN];




int get_connection_by_hostname (unsigned char*);
int get_connection_by_str_ipv4 (unsigned char*);
int get_client_socket ();

void read_hostname (unsigned char*);
void parse_ipv4 (unsigned char*);

unsigned char* itoa_cur (unsigned char*, int*);
int ncopy (void*, void*, int);
int getlen (const unsigned char*);
