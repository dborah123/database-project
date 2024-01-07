#include <stdio.h>
#include <stdlib.h>
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
#define INFINITE_TIMEOUT -1

int is_port_invalid(char *port);
int setup_port(char *port);
void setup_poll_struct(struct pollfd poll_fds[], int listen_fd);
int handle_action(struct pollfd *current_file, int listen_fd);
void listen_for_requests(char *port, int listen_fd);
int isnumber(char *s);