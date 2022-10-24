#include <iostream>
#include <thread>
#include <string.h>

class DisplayThread
{
public:
    void operator()()     
    {
        //printf("Thread STR: %s \n", str);
        for(int i = 0; i < 15; i++)
            std::cout<<"Display Thread Executing"<<std::endl;
        //str = "Barrett";
    }
    void jb(int i){
        printf("JBTHREAD %i \n\n", i);
    }
};
 
int main()  
{   
    //string str = "Jason";
    //char *string = &str;
    //printf("Main STR: %s \n", str);

    std::thread threadObj( (DisplayThread()));
    threadObj.jb();
    for(int i = 0; i < 15; i++)
        std::cout<<"Display From Main Thread "<<std::endl;
    std::cout<<"Waiting For Thread to complete"<<std::endl;
    threadObj.join();
    //printf("Main STR2: %s \n", str);
    std::cout<<"Exiting from Main Thread"<<std::endl;
    return 0;
}