#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>

int connect_to_server(char* addr, int port)
{
    // create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0)
    {
        printf("Failed to create socket.\n");
        return -1;
    }

    struct sockaddr_in sa;

    sa.sin_family = AF_INET;
    sa.sin_port = htons(port);

    if (inet_pton(AF_INET, addr, &sa.sin_addr) <= 0)
    {
        printf("Invalid address.\n");
        return -1;
    }

    if (connect(sock, (struct sockaddr*)&sa, sizeof(sa)) < 0)
    {
        printf("Connection failed.\n");
        return -1;
    }

    return sock;
}

void send_message(int socket_fd, char* message)
{
    send(socket_fd, message, strlen(message), 0);
}
