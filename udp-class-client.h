#ifndef UDPCLIENT_H
#define UDPCLIENT_H

class UDPClient
{
private:
    char* m_addr;
    int m_port;
    int m_sock;
    int m_client_fd;


public:
    UDPClient(char* addr, int port);

    int send_udp();
    int recv_udp();
    void close_socket();
};

#endif