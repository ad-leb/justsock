#include <_main.h>


int main (int argc, char* argv[], char* env[])
{
	return get_connection_by_hostname(argv[1]);
}
