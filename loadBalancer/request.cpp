#include "request.h"
#include <random>
#include <sstream>

std::random_device rd;
std::mt19937 gen(rd());



request::request() : ipDest(createIP()), ipSrc(createIP()), ttl(getRandomNumber()) {}

std::string request::createIP() {
    
    std::uniform_int_distribution<> dist(1, 255);

    std::stringstream ss;
    ss << dist(gen) << "." << dist(gen) << "." << dist(gen) << "." << dist(gen);
    return ss.str();
}


int request::getRandomNumber() {
    
    std::uniform_int_distribution<> dist(1, 25); // Example range, can be adjusted as needed
    return dist(gen);
}


