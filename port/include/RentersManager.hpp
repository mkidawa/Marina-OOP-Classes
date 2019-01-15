//
// Created by pobi on 15.01.19.
//

#ifndef PORT_RENTERSMANAGER_HPP
#define PORT_RENTERSMANAGER_HPP

#include "Repo.hpp"
#include "Renter.hpp"

#include <string>

class RentersManager{
    Repo<Renter_ptr> renters;
public:
    void add(Renter_ptr item);
    void remove(Renter_ptr item);
    Renter_ptr operator()(boost::uuids::uuid UUID);
};


#endif //PORT_RENTERSMANAGER_HPP
