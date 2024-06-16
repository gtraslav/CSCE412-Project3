#ifndef LOADBALANCER_H
#define LOADBALANCER_H


#include "request.h"
#include "webServer.h"
#include <vector> 
#include <queue> 


class loadBalancer{
    private:

        std::vector<webServer> servers;
        std::queue<request> requestQueue; 
        int time; 

    public: 

        loadBalancer();

        void addNewRequest(request newRequest);

        void handleRequests();

        void createWebservers(int numberServers);

        int getQueueSize();
};





#endif