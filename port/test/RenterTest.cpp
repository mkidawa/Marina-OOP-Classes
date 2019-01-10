#include <boost/test/unit_test.hpp>
#include <boost/uuid/uuid_io.hpp>

#include <vector>
#include <algorithm>
#include <sstream>

#include "Renter.hpp"

using namespace std;
using boost::posix_time::time_from_string;

template<class T>
string str(T C){
    stringstream tmp;
    tmp << C;
    return tmp.str();
}

BOOST_AUTO_TEST_SUITE(RenterTest)

BOOST_AUTO_TEST_CASE(T_Konstruktor){
    Renter_ptr renter(new Renter("D", PTime( time_from_string( "2017-12-30 00:00:00" )), "E"));
    string test = "D E 2017-Dec-30 00:00:00";
    BOOST_CHECK_EQUAL(test, renter->get_all());
}

BOOST_AUTO_TEST_CASE(T_Length){
    Renter_ptr renter(new Renter("D", PTime( time_from_string( "2017-12-30 00:00:00" )), "E"));
    BOOST_CHECK_EQUAL(5, renter->get_max_lenght());
}

BOOST_AUTO_TEST_CASE(T_Change_Prof){
    Renter_ptr renter(new Renter("D", PTime( time_from_string( "2017-12-30 00:00:00" )), "E"));
    renter->changeToProfessor();
    BOOST_CHECK_EQUAL(20, renter->get_max_lenght());
}

BOOST_AUTO_TEST_CASE(T_Change_Stud){
    Renter_ptr renter(new Renter("D", PTime( time_from_string( "2017-12-30 00:00:00" )), "E"));
    renter->changeToProfessor();
    renter->changeToStudent();
    BOOST_CHECK_EQUAL(5, renter->get_max_lenght());
}

BOOST_AUTO_TEST_CASE(T_Copy_Constructor){
    Renter T1("D", PTime( time_from_string( "2017-12-30 00:00:00" )), "E");
    Renter T2(T1);
    BOOST_CHECK_EQUAL(T1.get_all(), T2.get_all());
}

BOOST_AUTO_TEST_CASE(T_Assignment){
    Renter T1("D", PTime( time_from_string( "2017-12-30 00:00:00" )), "E");
    Renter T2;
    T2 = T1;
    BOOST_CHECK_EQUAL(T1.get_all(), T2.get_all());
}

BOOST_AUTO_TEST_SUITE_END()
