#include "udp-class-server.h"
#include <stdio.h>
int main(int argc, char *argv[]) {
	printf("JB");

	UDPServer serverUDP("127.0.0.1", 8000);
	printf("JB");

	serverUDP.recv_udp2();
	serverUDP.send_udp();
	serverUDP.close_socket();
	serverUDP.shutdown_socket();

}
