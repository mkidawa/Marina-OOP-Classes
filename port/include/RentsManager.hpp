//
// Created by pobi on 15.01.19.
//

#ifndef POBIMARINA_RENTSMANAGER_HPP
#define POBIMARINA_RENTSMANAGER_HPP

#include <string>
#include <vector>
#include "Repo.hpp"
#include "Rent.hpp"

class RentsManager {
    Repo<Rent_ptr> currentRents;
    Repo<Rent_ptr> archiveRents;

public:
    void rent(PosixTime start, PosixTime stop, Place_ptr where, Renter_ptr who);
    void addRent(Rent_ptr rent);
    void endRent(Place_ptr place);
    int getSize(int param);
};


#endif //POBIMARINA_RENTSMANAGER_HPP
