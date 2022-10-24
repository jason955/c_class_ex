#include "client.h"
#include <stdio.h>
#include <thread>

int main(int argc, char *argv[]) {
	char buffer[1024] = { 0 };
	Custom_Client *cli = new Custom_Client();
	//char* value = cli.custom_send();
	std::thread t1(&Custom_Client::custom_send,cli,buffer);
	printf("JB %s \n", buffer);
	t1.join();
	printf("buffer %s", buffer);

}
