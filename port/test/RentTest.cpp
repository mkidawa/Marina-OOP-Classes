#include <boost/test/unit_test.hpp>
#include <boost/uuid/uuid_io.hpp>

#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>

#include "Rent.hpp"
#include "Renter.hpp"
#include "Book.hpp"

using namespace std;
using boost::posix_time::time_from_string;

template<class T>
string str(T C){
    stringstream tmp;
    tmp << C;
    return tmp.str();
}

BOOST_AUTO_TEST_SUITE(RentTest)

BOOST_AUTO_TEST_CASE(T_Different_UUID){
    vector<Rent> R;
    Renter_ptr renter(new Renter("nazwisko",
                               PTime( time_from_string( "2017-12-30 00:00:00" ) ),
                               "adress"));
    Book_ptr book(new Book("tytul", "tojestdramat", "decomoreno"));

    for(int i=10; i-->0;){
        Rent rent(book, renter);
        R.push_back(rent);
    }

    vector<string> UUID;

    for(int i=10; i-->0;){
        UUID.push_back( str( R.back().get_uuid() ) );
        R.pop_back();
    }
    sort(UUID.begin(), UUID.end());

    for(int i=1; i<10; i++){
        BOOST_CHECK(UUID[i-1]!=UUID[i]);
    }
}

BOOST_AUTO_TEST_CASE(T_Not_Ended){
    Book_ptr book(new Book("A", "B", "C"));
    Renter_ptr renter(new Renter("D", PTime( time_from_string( "2017-12-30 00:00:00" )), "E"));
    Rent_ptr rent(new Rent(book, renter));
    BOOST_CHECK_EQUAL(rent->duration(), 0);
}

BOOST_AUTO_TEST_CASE(T_Duration){
    Book_ptr book(new Book("A", "B", "C"));
    Renter_ptr renter(new Renter("D", PTime( time_from_string( "2017-12-30 00:00:00" )), "E"));
    Rent_ptr rent(new Rent(book, renter));
    rent->end_rent();
    BOOST_CHECK_EQUAL(rent->duration(), 1);
}

BOOST_AUTO_TEST_SUITE_END()
