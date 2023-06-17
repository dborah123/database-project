#include "request-manager.h"

int
main(int argc, char *argv[]) {
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

    listen_port = argv[1];

    /* create a socket */
    if ((listen_fd = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
    }
}