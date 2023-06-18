#include "request-manager.h"

int
main(int argc, char *argv[]) {

    setup_port(argv[1]);

    listen_for_requests();
    

    // if (bind(listen_fd, res->ai_addr, res->ai_addrlen) < 0) {
        // perror("bind");
    // }
// 
    // /* start listening */
    // if (listen(listen_fd, BACKLOG) < 0) {
        // perror("listen");
    // }
// 
    // printf("Threaded HTTP Server waiting on port %s\n", listen_port); 
// 
    // addrlen = sizeof(remote_sa);
// 
    // /* Set up poll structure */
// 
    // nfds_t nfds = 0;
    // struct pollfd *poll_fds;
    // int  num_fds = 0;
// 
    // if ((poll_fds = malloc(MAX_FDS * sizeof(struct pollfd))) == NULL) {
        // perror("malloc");
    // }
// 
    // poll_fds->fd = listen_fd;
    // poll_fds->events = POLLIN;
    // poll_fds->revents = 0;
    // num_fds += 1;
}


void
setup_port(char *port) {

    char *listen_port;
    int listen_fd, new_fd;
    struct addrinfo hints, *res;
    int rc;
    struct sockaddr_in remote_sa;
    uint16_t remote_port;
    socklen_t addrlen;
    char *remote_ip;

    int bytes_received;
    char input_buf[BUFF_SIZE];

    listen_port = port;

    /* create a socket */
    if ((listen_fd = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
    }

    /* bind it to a port */
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    if((rc = getaddrinfo(NULL, listen_port, &hints, &res)) != 0) {
        printf("getaddrinfo failed: %s\n", gai_strerror(rc));
        exit(1);
    }
}

void
listen_for_requests() {

}