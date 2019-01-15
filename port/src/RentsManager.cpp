//
// Created by pobi on 15.01.19.
//
#include <sstream>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include "RentsManager.hpp"
#include "Place.hpp"

Rent_ptr RentsManager::rent(PosixTime start, PosixTime stop, Place_ptr where, Renter_ptr who) {
    currentRents.add(Rent_ptr(new Rent(start, stop, where, who)));
}

void RentsManager::endRent(Place_ptr place) {
    Rent_ptr R = currentRents.find(place->getUUID());
    currentRents.remove(R);
    archiveRents.add(R);
}
