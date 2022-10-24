#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include "client.h"
#include <iostream>
#include <thread>
#include <functional>
#include <mutex>
#include <condition_variable>
#define PORT 8000


Custom_Client::Custom_Client()
{


}

Custom_Client::~Custom_Client()
{
}

void Custom_Client::setDataLoaded(bool val){
	h_data_loaded = val;
}
bool Custom_Client::getDataLoaded(){
	return h_data_loaded;
}
// std::mutex Custom_Client::getClientMutex(){
// 	return h_mutex;
// }
// std::condition_variable Custom_Client::getClientCondVar(){
// 	return h_condVar;
//}
void Custom_Client::custom_send(char *val)
{	
	
	int sock = 0, valread, client_fd;
	struct sockaddr_in serv_addr;
	char* hello = "Hello from the client";
	char buffer[1024] = { 0 };
	
	if ((sock = socket(AF_INET, SOCK_STREAM,  0)) < 0) 
	{
		printf("\n Socket creation error");
		//return "fail";
	}
	
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);
	
	if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
	{
		printf("\nInvalid Address/ Address not supported");
		//return "fail";
	}
	
	if ((client_fd = connect(sock, (struct sockaddr*)&serv_addr,
										 sizeof(serv_addr))) < 0 )
	{
		printf("\nConnection Failed \n");
		//return "fail";
	}
	send(sock, hello, strlen(hello), 0);
	recvfrom(sock, val, 1024, 0, (struct sockaddr*) &serv_addr, 0);
	//printf("RCVD from server: %s", buffer);
	close(client_fd);
	//val = buffer;
}