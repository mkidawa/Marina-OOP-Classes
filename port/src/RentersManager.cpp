//
// Created by pobi on 15.01.19.
//

#include "RentersManager.hpp"

using namespace std;

void RentersManager::add(Renter_ptr item){
    renters.add(item);
}

void RentersManager::remove(Renter_ptr item){
    renters.remove(item);
}

Renter_ptr RentersManager::operator()(boost::uuids::uuid UUID){
    return renters.find(UUID);
}
