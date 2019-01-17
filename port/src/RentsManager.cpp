//
// Created by pobi on 15.01.19.
//
#include <sstream>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include "RentsManager.hpp"
#include "Place.hpp"

void RentsManager::rent(PosixTime start, PosixTime stop, Place_ptr where, Renter_ptr who) {
    currentRents.add(Rent_ptr(new Rent(start, stop, where, who)));
}

void RentsManager::addRent(Rent_ptr rent) {
    currentRents.add(rent);
}

void RentsManager::endRent(Place_ptr place) {
    Rent_ptr R = currentRents.find(place->getUUID());
    archiveRents.add(R);
    currentRents.remove(R);
}

int RentsManager::getSize(int param) {
    int temp;
    if(param == 1) temp = currentRents.getSize();
    else if (param == 2) temp = archiveRents.getSize();
    return temp;
}