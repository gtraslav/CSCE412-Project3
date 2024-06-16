#include "webServer.h"

// Constructor
webServer::webServer() : available(true), timeLeft(0) {}

// Get the remaining processing time
int webServer::getTimeLeft(){
    return timeLeft;
}

// Check if the server is available
bool webServer::getAvailability() {
    return available;
}

// Get the current request being processed
request webServer::getRequest(){
    return currRequest;
}

// Set a new request for the server
void webServer::setRequest( request newRequest) {
    currRequest = newRequest;
    timeLeft = newRequest.ttl;
    available = false;
}

// Decrement the remaining time
void webServer::decrementTime() {
    if (timeLeft > 0) {
        --timeLeft;
    }
    if (timeLeft == 0) {
        available = true;
    }
}

// Mark the server as available
void webServer::markAsAvailable() {
    available = true;
}

