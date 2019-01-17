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
using namespace std;

BOOST_AUTO_TEST_SUITE(RenterTest)
    BOOST_AUTO_TEST_CASE(Constructor_Test_string){
        Yacht_ptr yacht1(new Yacht( 5, 1.5, 1));
        Renter_ptr renter1(new Renter("Pogoria","Poland",yacht1));
        Place_ptr place1(new Place("A", true));
        string start = "2019-01-20 00:00:00";
        string stop = "2019-01-23 00:00:00";
        PosixTime t1(boost::posix_time::time_from_string(start));
        PosixTime t2(boost::posix_time::time_from_string(stop));
        Rent_ptr rent1(new Rent(start,stop,place1,renter1)); // sprawdzanie czy następuje konwersja string -> posix w obrębie konstruktora
        BOOST_CHECK_EQUAL(rent1->getStart(),t1);
        BOOST_CHECK_EQUAL(rent1->getStop(),t2);
        BOOST_CHECK_EQUAL(rent1->getWhere(),place1);
        BOOST_CHECK_EQUAL(rent1->getWho(),renter1);
    }
    BOOST_AUTO_TEST_CASE(Constructor_Test_posix){
        Yacht_ptr yacht1(new Yacht( 5, 1.5, 1));
        Renter_ptr renter1(new Renter("Pogoria","Poland",yacht1));
        Place_ptr place1(new Place("A", true));
        string start = "2019-01-20 00:00:00";
        string stop = "2019-01-23 00:00:00";
        PosixTime t1(boost::posix_time::time_from_string(start));
        PosixTime t2(boost::posix_time::time_from_string(stop));
        Rent_ptr rent1(new Rent(t1,t2,place1,renter1));
        BOOST_CHECK_EQUAL(rent1->getStart(),t1);
        BOOST_CHECK_EQUAL(rent1->getStop(),t2);
        BOOST_CHECK_EQUAL(rent1->getWhere(),place1);
        BOOST_CHECK_EQUAL(rent1->getWho(),renter1);
    }
    BOOST_AUTO_TEST_CASE(Test_Add_Price){
        Yacht_ptr yacht1(new Yacht( 5, 1.5, 1));
        Renter_ptr renter1(new Renter("Pogoria","Poland",yacht1));
        Place_ptr place1(new Place("A", true));
        string start = "2019-01-20 00:00:00";
        string stop = "2019-01-23 00:00:00";
        Rent_ptr rent1(new Rent(start,stop,place1,renter1));
        BOOST_CHECK_CLOSE(rent1->calculateRealPrice(),454.5,0.001);

    }
BOOST_AUTO_TEST_SUITE_END()

