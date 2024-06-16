#include <iostream>
#include <random>


#include "loadBalancer.h"


int main(){
    

    std::cout << "Right now, a request has between 1 and 25 cycles" << std::endl; 
    //some stuff we'll need to randomly create new requests at random points
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 15);

    // Initialize the loadBalancer
    loadBalancer lB; 
    
    int numberServers, cycles; 
    
    // Take in user input for webservers and cycles to run for
    std::cout << "How many webservers do you wish to run? " << std::endl;
    
    std::cin >> numberServers; 

    std::cout << "How many cycles do you wish to run for? " << std::endl;

    std::cin >> cycles; 

    


    // Create numberServers * 100 requests initally and enqueue them
    for(int i = 0; i < numberServers * 100; i++){

        request newRequest;
        lB.addNewRequest(newRequest);
        // std::cout << newRequest.ttl << std::endl;
    }

    std::cout << "Starting Queue Size is: " << lB.getQueueSize() << std::endl;
    

    // Create a vector of numberServers webservers
    lB.createWebservers(numberServers); 

    for(int i = 1; i <= cycles; i++){
        

        lB.handleRequests();

        int num1 = dist(gen);
        int num2 = dist(gen);
        // std::cout << num1 << " " << num2 << std::endl; 

        if(num1 == num2 && lB.getQueueSize() < 100 * numberServers){
            request newRequest;
            lB.addNewRequest(newRequest);
        }

    }

    std::cout << "Ending Queue Size is: " << lB.getQueueSize() << std::endl;
    
    std::cout << "Terminating Program" << std::endl;


}