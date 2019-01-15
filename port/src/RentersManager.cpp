//
// Created by pobi on 15.01.19.
//

#include "RentersManager.hpp"

using namespace std;

void RentersManager::add(Renter_ptr item){
    renters.create(item);
}

void RentersManager::remove(Renter_ptr item){
    renters.remove(item);
}

Renter_ptr RentersManager::operator()(string title){
    return renters.find(title);
}