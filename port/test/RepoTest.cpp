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
    BOOST_AUTO_TEST_CASE(Constructor_Test){
    BOOST_CHECK_NO_THROW(Repo<Renter_ptr> renters); //nullptr exception i inne :v
    }
    BOOST_AUTO_TEST_CASE(Element_Test){
        Repo<Renter_ptr> renters;
        Yacht_ptr yacht1(new Yacht( 5, 1.5, 1));
        Renter_ptr renter1(new Renter("Pogoria","Poland"));
        BOOST_CHECK_NO_THROW(renters.add(renter1));
        renters.add(renter1);
    }
    BOOST_AUTO_TEST_CASE(Remove_Test){
        Repo<Renter_ptr> renters;
        Yacht_ptr yacht1(new Yacht( 5, 1.5, 1));
        Renter_ptr renter1(new Renter("Pogoria","Poland"));
        renters.add(renter1);
        BOOST_CHECK_NO_THROW(renters.remove(renter1));
    }
    BOOST_AUTO_TEST_CASE(Find_Test){
        Repo<Place_ptr> places;
        Place_ptr place1(new Place("A", true));
        Place_ptr place2(new Place("A", false));
        Place_ptr place3(new Place("C", true));
        places.add(place1);
        places.add(place2);
        places.add(place3);
        BOOST_CHECK_EQUAL(places.find("A"),place1);
        BOOST_CHECK_EQUAL(places.findAll("A").size(),2);
    }
    BOOST_AUTO_TEST_CASE(Exception_Test){
        Repo<Rent_ptr> rents;
        Yacht_ptr yacht1(new Yacht( 5, 1.5, 1));
        Yacht_ptr yacht2(new Yacht( 4, 1.1, 1));
        Renter_ptr renter1(new Renter("Pogoria","Poland",yacht1));
        Renter_ptr renter2(new Renter("Pia","Pd",yacht2));
        Place_ptr place1(new Place("A", true));
        string start = "2019-01-20 00:00:00";
        string stop = "2019-01-23 00:00:00";
        PosixTime t1(boost::posix_time::time_from_string(start));
        PosixTime t2(boost::posix_time::time_from_string(stop));
        Rent_ptr rent1(new Rent(t1,t2,place1,renter1));
        Rent_ptr rent2(new Rent(t1,t2,place1,renter2));
        rents.add(rent1);
        BOOST_CHECK_THROW(rents.add(rent2),RentException);
    }


BOOST_AUTO_TEST_SUITE_END()

