//
// Created by pobi on 16.01.19.
//

#include <boost/test/unit_test.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <vector>
#include <algorithm>
#include <sstream>
#include "Renter.hpp"
#include "RenterException.hpp"
using namespace std;



BOOST_AUTO_TEST_SUITE(RenterTest)

    BOOST_AUTO_TEST_CASE(Constructor_Test){
        Yacht_ptr yacht1(new Yacht( 5, 1.5, 1));
        Renter_ptr renter1(new Renter("Pogoria","Poland",yacht1));
        BOOST_CHECK_EQUAL(renter1->getName(),"Pogoria");
        BOOST_CHECK_EQUAL(renter1->getCountry(),"Poland");
        BOOST_CHECK_EQUAL(renter1->getInnerRenter(),yacht1);
        BOOST_CHECK_EQUAL(renter1->get_info(),"Pogoria Poland");
    }
    BOOST_AUTO_TEST_CASE(Price_Test){
        Yacht_ptr yacht1(new Yacht( 5, 1.5, 1));
        Renter_ptr renter1(new Renter("Pogoria","Poland",yacht1));
        BOOST_CHECK_CLOSE(renter1->get_realPrice(),116.25,0.0001);
        Motorboat_ptr mb1(new Motorboat(5,0.99,4));
        Renter_ptr renter2(new Renter("Orzel","Poland",mb1));
        BOOST_CHECK_CLOSE(renter2->get_realPrice(),119.1,0.0001);
    }
    BOOST_AUTO_TEST_CASE(Copy_Test){
        Yacht_ptr yacht1(new Yacht( 5, 1.5, 1));
        Renter renter1("Pogoria","Poland");
        Renter renter2(renter1);
        BOOST_CHECK_EQUAL(renter1.get_info(),renter2.get_info());
    }
    BOOST_AUTO_TEST_CASE(Overloaded_Equal_Test){
        Yacht_ptr yacht1(new Yacht( 5, 1.5, 1));
        Renter renter1("Pogoria","Poland");
        Renter renter2;
        renter2 = renter1;
        BOOST_CHECK_EQUAL(renter1.get_info(),renter2.get_info());
    }
    BOOST_AUTO_TEST_CASE(Exception_Test){
        Yacht_ptr yacht1(new Yacht( 5, 1.5, 1));
        BOOST_CHECK_THROW(Renter_ptr renter1(new Renter("Pogoria","Poland69",yacht1)),RenterException);

    }
BOOST_AUTO_TEST_SUITE_END()
