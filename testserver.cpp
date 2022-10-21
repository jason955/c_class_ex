#include "udp-class-server.h"
#define MAXLINE 1024
int main() {
	UDPServer server("127.0.0.1", 8000);
	server.send_udp();
	server.recv_udp();
	server.close_socket();
	server.shutdown_socket();

}
