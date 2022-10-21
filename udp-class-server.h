#ifndef UDPSERVER_H
#define UDPSERVER_H

class UDPServer
{
private:
    char* m_addr;
    int m_port;
    int m_sock;
    int m_server_fd;


public:
    UDPServer(char* addr, int port);

    int send_udp();
    int recv_udp();
    void close_socket();
    void shutdown_socket();

};

#endif