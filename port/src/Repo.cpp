//
// Created by pobi on 15.01.19.
//

#include "Repo.hpp"
#include "Place.hpp"
#include "Rent.hpp"

template<>
Place_ptr Repo<Place_ptr>::find(std::string zone) {
    for(auto i : container) {
        if(i->getZone() == zone) return i;
    }
    return nullptr;
}