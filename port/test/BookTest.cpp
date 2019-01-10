#include <boost/test/unit_test.hpp>
#include <boost/uuid/uuid_io.hpp>

#include <vector>
#include <algorithm>
#include <sstream>

#include "Rent.hpp"
#include "Renter.hpp"
#include "Book.hpp"

using namespace std;
using boost::posix_time::time_from_string;

using namespace std;

template<class T>
string str(T C){
    stringstream tmp;
    tmp << C;
    return tmp.str();
}

BOOST_AUTO_TEST_SUITE(BookTest)

BOOST_AUTO_TEST_CASE(T_Konstruktor){
    Book_ptr book(new Book("A", "B", "C"));
    string test = "Title: A\nGenre: B\nAuthor: C";
    BOOST_CHECK_EQUAL(test, book->get_all());
}

BOOST_AUTO_TEST_CASE(T_Tytul){
    Book_ptr book(new Book("A", "B", "C"));
    BOOST_CHECK_EQUAL("A", book->get_title());
}

BOOST_AUTO_TEST_SUITE_END()
