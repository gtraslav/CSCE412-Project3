#ifndef WEBSERVER_H
#define WEBSERVER_H
#include "request.h"


class webServer{

    private:
        bool available;
        int timeLeft;
        request currRequest; 

    public: 

        webServer();

        int getTimeLeft(); 

        bool getAvailability();

        request getRequest();

        void setRequest(request newRequest);

        void decrementTime();

        void markAsAvailable();

        
};



#endif