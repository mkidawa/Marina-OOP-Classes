//
// Created by pobi on 16.01.19.
//
#include <iostream>
#include <sstream>
#include <string>
#include "PlaceManager.hpp"
#include "RentersManager.hpp"
#include "RentsManager.hpp"

#include "Renter.hpp"
#include "Rent.hpp"
#include "Place.hpp"

using namespace std;

int main() {
    Repo<Rent_ptr> rents;
    Yacht_ptr yacht1(new Yacht( 5, 1.5, 1));
    Yacht_ptr yacht2(new Yacht( 4, 1.1, 1));
    Renter_ptr renter1(new Renter("Pogoria","Poland",yacht1));
    Renter_ptr renter2(new Renter("Pia","Pd",yacht2));
    Place_ptr place1(new Place("A", true));
    string start = "2019-01-26 00:00:00";
    string stop = "2019-01-27 00:00:00";
    string start2 = "2019-01-24 00:00:00";
    string stop2 = "2019-01-25 00:00:00";
    PosixTime t1(boost::posix_time::time_from_string(start));
    PosixTime t2(boost::posix_time::time_from_string(stop));
    PosixTime t3(boost::posix_time::time_from_string(start2));
    PosixTime t4(boost::posix_time::time_from_string(stop2));
    Rent_ptr rent1(new Rent(t1,t2,place1,renter1));
    Rent_ptr rent2(new Rent(t3,t4,place1,renter2));
    rents.add(rent1);
    rents.add(rent2);

}
