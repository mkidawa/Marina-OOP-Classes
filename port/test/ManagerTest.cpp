//
// Created by pobi on 16.01.19.
//

#include <boost/test/unit_test.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <vector>
#include <algorithm>
#include <sstream>
#include "Renter.hpp"
#include "Rent.hpp"
#include "Place.hpp"
#include "Repo.hpp"
#include "PlaceManager.hpp"
#include "RentsManager.hpp"
#include "RentersManager.hpp"
#include "RentException.hpp"
using namespace std;

BOOST_AUTO_TEST_SUITE(RepoTest)
    BOOST_AUTO_TEST_CASE(PMng_Test){
        PlaceManager places;
        Place_ptr place1(new Place("A", true));
        Place_ptr place2(new Place("A", true));
        places.addPlace(place1);
        places.addPlace(place2);
        BOOST_CHECK_EQUAL((places.findAll("A")).size(),2); //liczba obiektów dodanych do menedżera
        BOOST_CHECK_NO_THROW(places.removePlace(place1));
    }
    BOOST_AUTO_TEST_CASE(RenterMng_Test){
        Yacht_ptr yacht1(new Yacht( 5, 1.5, 1));
        Renter_ptr renter1(new Renter("Pogoria","Poland",yacht1));
        RentersManager renters;
        renters.add(renter1);
        BOOST_CHECK_NO_THROW(renters.add(renter1));
        BOOST_CHECK_NO_THROW(renters.remove(renter1));
    }
    BOOST_AUTO_TEST_CASE(RentsMng_Test){
        RentsManager rents;
        Yacht_ptr yacht1(new Yacht( 5, 1.2, 1));
        Yacht_ptr yacht2(new Yacht( 6, 1.1, 2));
        Renter_ptr renter1(new Renter("Pogoria","Poland",yacht1));
        Renter_ptr renter2(new Renter("Tofik","Albania",yacht2));
        Place_ptr place1(new Place("B", true));
        string start = "2019-01-20 00:00:00";
        string stop = "2019-01-23 00:00:00";
        string start2 = "2019-01-24 00:00:00";
        string stop2 = "2019-01-26 00:00:00";
        PosixTime t1(boost::posix_time::time_from_string(start));
        PosixTime t2(boost::posix_time::time_from_string(stop));
        PosixTime t3(boost::posix_time::time_from_string(start2));
        PosixTime t4(boost::posix_time::time_from_string(stop2));
        BOOST_CHECK_NO_THROW(Rent_ptr rent1(new Rent(t1,t2,place1,renter1)));
        Rent_ptr rent1(new Rent(t1,t2,place1,renter1));
        BOOST_CHECK_NO_THROW(Rent_ptr rent2(new Rent(t1,t2,place1,renter2)));
        Rent_ptr rent2(new Rent(t1,t2,place1,renter2));
        Rent_ptr rent3(new Rent(t3,t4,place1,renter2));
        rents.addRent(rent1);
        BOOST_CHECK_THROW(rents.addRent(rent2),RentException);
        BOOST_CHECK_NO_THROW(rents.addRent(rent3));
    }
    BOOST_AUTO_TEST_CASE(RentsMng_Archive_Test){
        RentsManager rents;
        Yacht_ptr yacht1(new Yacht( 5, 1.2, 1));
        Renter_ptr renter1(new Renter("Pogoria","Poland",yacht1));
        Place_ptr place1(new Place("B", true));
        string start = "2019-01-20 00:00:00";
        string stop = "2019-01-23 00:00:00";
        PosixTime t1(boost::posix_time::time_from_string(start));
        PosixTime t2(boost::posix_time::time_from_string(stop));
        Rent_ptr rent1(new Rent(t1,t2,place1,renter1));
        rents.addRent(rent1);
        rents.endRent(place1);
        BOOST_CHECK_EQUAL(rents.getSize(1), 0);
        BOOST_CHECK_EQUAL(rents.getSize(2), 1);
    }




BOOST_AUTO_TEST_SUITE_END()