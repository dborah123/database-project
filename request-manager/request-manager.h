#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <ctype.h>
#include <poll.h>

#define BUFF_SIZE 4000
#define MAX_FDS 20
#define BACKLOG 20

int is_port_invalid(char *port);
int setup_port(char *port);
int setup_poll_struct(struct pollfd *poll_fds, char *port)