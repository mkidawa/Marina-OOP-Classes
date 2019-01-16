//
// Created by pobi on 16.01.19.
//

#include <boost/test/unit_test.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <vector>
#include <algorithm>
#include <sstream>
#include "Place.hpp"
using namespace std;

BOOST_AUTO_TEST_SUITE(PlaceTest)
    BOOST_AUTO_TEST_CASE(Constructor_Test){
    Place_ptr place1(new Place("A", true));
    BOOST_CHECK_EQUAL(place1->getZone(),"A");
    BOOST_CHECK_EQUAL(place1->isBuoy(),true);
    BOOST_CHECK_EQUAL(place1->isBuoy(),1);
}
BOOST_AUTO_TEST_SUITE_END()
