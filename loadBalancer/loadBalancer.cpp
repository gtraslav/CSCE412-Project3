#include "loadBalancer.h"
#include <iostream>

loadBalancer::loadBalancer() : time(1) {}


void loadBalancer::addNewRequest(request newRequest) {
    requestQueue.push(newRequest);
}


void loadBalancer::handleRequests() {
    for (auto& server : servers) {
        if (server.getAvailability()) { // Corrected spelling of getAvailability
            if (!requestQueue.empty()) {
                // Server is available and there is a request in the queue
                request finishedRequest = server.getRequest();
                std::cout << "At time " << time << " we finished the request from " 
                          << finishedRequest.ipSrc << " sending it to " << finishedRequest.ipDest << std::endl;

                server.setRequest(requestQueue.front());
                requestQueue.pop();
            }
        } else {
            
                // Decrement the remaining processing time
                server.decrementTime();
            
        }
    }
    // Increment the simulation time
    time++;
}



void loadBalancer::createWebservers(int numberServers) {
    for (int i = 0; i < numberServers; ++i) {
        servers.emplace_back(); 
    }
}


int loadBalancer::getQueueSize(){
    return requestQueue.size();
}