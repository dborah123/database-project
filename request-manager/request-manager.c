#include "request-manager.h"

int
main(int argc, char *argv[]) {

    char *port = argv[1];

    if (is_port_invalid(port)) {
        perror("port is invalid");
    }

    int listen_fd = setup_port(port);

    listen_for_requests(port, listen_fd);
    

}

int
setup_port(char *port) {
    /**
     * DESCRIPTION: Prepares for listening to a port. Creates socket and binds to a port
     * PARAMS:
     *  port: String of digits that represents port to bind to
     * RETURNS: The file descriptor to listen on for poll
    */

    int listen_fd, rc;
    struct addrinfo hints, *res;

    /* create a socket */
    if ((listen_fd = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    /* bind it to a port */
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    if ((rc = getaddrinfo(NULL, port, &hints, &res)) != 0) {
        perror("getaddrinfo failed: %s\n", gai_strerror(rc));
        freeaddrinfo(res);
        exit(1);
    }

    if (bind(listen_fd, res->ai_addr, res->ai_addrlen) < 0) {
        perror("bind");
        freeaddrinfo(res);
        exit(1);
    }

    freeaddrinfo(res);

    return listen_fd;
}

void
listen_for_requests(char *port, int listen_fd) {
    socklen_t addrlen;
    struct sockaddr_in remote_sa;

    /* start listening */
    if (listen(listen_fd, BACKLOG) < 0) {
        perror("listen");
        exit(1);
    }

    printf("Threaded HTTP Server waiting on port %s\n", port); 

    addrlen = sizeof(remote_sa);

    /* Set up poll structure */

    nfds_t nfds = 0;
    struct pollfd *poll_fds;

    if (setup_poll_struct(poll_fds, port)) {
        perror("malloc");
        free(poll_fds);
        exit(1);
    }

    int num_fds = 1;
    free(poll_fds);
}

int
setup_poll_struct(struct pollfd *poll_fds, char *port) {
    /**
     * DESCRIPTION: Sets up pollfd struct for polling. Allocates memory for the struct
     * PARAMS:
     *  poll_fds: pollfd struct being initialized
     *  port: String of digits that represents port to bind to
     * RETURNS: 1 if error, 0 otherwise
    */

    if ((poll_fds = malloc(MAX_FDS * sizeof(struct pollfd))) == NULL) {
        return 1;
    }

    poll_fds->fd = port;
    poll_fds->events = POLLIN;
    poll_fds->revents = 0;

    return 0;
}

int
is_port_invalid(char *port) {
    if (isnumber(port)) {
        return 1;
    }
    return 0;
}

int
isnumber(char *s) {
    int length = strlen(s);

    for (int i = 0; i < length; i++) {
        if (!isdigit(s[i])) {
            return 0;
        }
    }

    return 1;
}
