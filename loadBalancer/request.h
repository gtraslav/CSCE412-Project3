#ifndef REQUEST_H
#define REQUEST_H

#include <string>


class request{
    public: 
        std::string ipDest;
        std::string ipSrc;
        int ttl; 
        
        request();

        std::string createIP();

        int getRandomNumber(); 


};


#endif



