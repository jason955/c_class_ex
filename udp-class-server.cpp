#include "udp-class-server.h"
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>

#define PORT 8080// Date constructor

UDPServer::UDPServer(char* addr, int port)
{
    m_addr = addr;
    m_port = port;
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = { 0 };
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET,
                SO_REUSEADDR | SO_REUSEPORT, &opt,
                sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr*)&address,
            sizeof(address))
        < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket
        = accept(server_fd, (struct sockaddr*)&address,
                (socklen_t*)&addrlen))
        < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    m_sock = new_socket;

    m_server_fd = server_fd;
}

int UDPServer::send_udp()
{
    char* hello = "Hello from client";
    int n = send(m_sock, hello, strlen(hello), 0);
    printf("Hello message sent\n");

    return n;

}

int UDPServer::recv_udp()
{
    char buffer[1024] = { 0 };

    int n = read(m_sock, buffer, 1024);
    printf("%s\n", buffer);
    return n;
}

void UDPServer::shutdown_socket()
{
    shutdown(m_server_fd, SHUT_RDWR);
}
void UDPServer::close_socket()
{
    close(m_sock);
}