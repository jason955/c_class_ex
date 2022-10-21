#include "udp-class-client.h"
#define MAXLINE 1024
int main() {
	UDPClient client("127.0.0.1", 8000);
	client.send_udp();
	client.recv_udp();
	client.close_socket();
}
