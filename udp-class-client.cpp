#include "udp-class-client.h"
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 8080// Date constructor
UDPClient::UDPClient(char* addr, int port)
{
    m_addr = address;
    m_port = port;
    int sock = 0, valread, client_fd;
    struct sockaddr_in serv_addr;
    char buffer[1024] = { 0 };
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary
    // form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)
        <= 0) {
        printf(
            "\nInvalid address/ Address not supported \n");
    }

    if ((client_fd
        = connect(sock, (struct sockaddr*)&serv_addr,
                sizeof(serv_addr)))
        < 0) {
        printf("\nConnection Failed \n");
    }
    m_sock = sock;
    m_client_fd = client_fd;
}

int UDPClient::send_udp()
{
    char* hello = "Hello from client";
    int n = send(m_sock, hello, strlen(hello), 0);
    printf("Hello message sent\n");

    return n;

}

int UDPClient::recv_udp()
{
    char buffer[1024] = { 0 };

    int n = read(m_sock, buffer, 1024);
    printf("%s\n", buffer);
    return n;
}

void UDPClient::close_socket()
{
    close(m_client_fd);
}