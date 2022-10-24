#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <iostream>

#include <mutex>
#include <condition_variable>
#define PORT 8000
class Custom_Client
{

	private:
		char* h_address;
		int h_port;
		bool h_data_loaded;
		std::mutex h_mutex;
		std::condition_variable h_condVar;
		
	public:
		Custom_Client();
		~Custom_Client();
		void custom_send(char *val);
		void setDataLoaded(bool val);
		bool getDataLoaded();
		std::mutex getClientMutex();
		std::condition_variable getClientCondVar();

};