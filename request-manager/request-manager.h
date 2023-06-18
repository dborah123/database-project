#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>

#define BUFF_SIZE 4000
#define MAX_FDS 20
#define BACKLOG 20