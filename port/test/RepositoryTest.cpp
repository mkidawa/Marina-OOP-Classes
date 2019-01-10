#include <boost/test/unit_test.hpp>
#include <boost/uuid/uuid_io.hpp>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/random_generator.hpp>

#include <vector>
#include <algorithm>
#include <sstream>

#include "Repository.hpp"

using namespace std;
using boost::posix_time::time_from_string;

template<class T>
string str(T C){
    stringstream tmp;
    tmp << C;
    return tmp.str();
}

BOOST_AUTO_TEST_SUITE(RepositoryTest)

BOOST_AUTO_TEST_CASE(T_Konstruktor){
    BOOST_CHECK_NO_THROW(Repository<Book_ptr> books);
}

BOOST_AUTO_TEST_CASE(T_Same_Element_Add){
    Repository<Book_ptr> books;
    Book_ptr B(new Book("A", "B", "C"));
    books.create(B);
    BOOST_CHECK_THROW(books.create(B), invalid_argument);
}

BOOST_AUTO_TEST_CASE(T_Remove){
    Repository<Book_ptr> books;
    Book_ptr B(new Book("A", "B", "C"));
    books.create(B);
    BOOST_CHECK_NO_THROW(books.remove(B));
}

BOOST_AUTO_TEST_CASE(T_Find_By_UUID){
    Repository<Book_ptr> books;
    Book_ptr B(new Book("A", "B", "C"));
    boost::uuids::uuid uuid = B->get_uuid();
    books.create(B);
    BOOST_CHECK_EQUAL(books.find(uuid), B);
}

BOOST_AUTO_TEST_CASE(T_Find_Non_Existing){
    Repository<Book_ptr> books;
    for(int i = 0; i < 10; i++){
        books.create(Book_ptr(new Book("A", "B", "C")));
    }
    BOOST_CHECK(books.find(boost::uuids::random_generator()()) == nullptr);
}

BOOST_AUTO_TEST_CASE(T_Find_Book_By_Name){
    Repository<Book_ptr> books;
    Book_ptr myBook;
    for(int i = 0; i < 10; i++){
        string name = str(i);
        Book_ptr B(new Book(name, name, name));
        books.create(B);
        if(i == 5){
            myBook = B;
        }
    }
    BOOST_CHECK_EQUAL(books.find("5"), myBook);
}

BOOST_AUTO_TEST_CASE(T_Find_Renter_By_Name){
    Repository<Renter_ptr> renters;
    Renter_ptr myRenter;
    for(int i = 0; i < 10; i++){
        string name = str(i);
        Renter_ptr R(new Renter(name, PTime( time_from_string( "2017-12-30 00:00:00" )), name));
        renters.create(R);
        if(i == 5){
            myRenter = R;
        }
    }
    BOOST_CHECK_EQUAL(renters.find("5"), myRenter);
}

BOOST_AUTO_TEST_CASE(T_Find_Rent_By_Name){
    vector<Book_ptr> books;
    vector<Renter_ptr> renters;
    Repository<Rent_ptr> rents;
    Rent_ptr myRent;
    for(int i = 0; i < 10; i++){
        string name = str(i);
        Renter_ptr R(new Renter(name, PTime( time_from_string( "2017-12-30 00:00:00" )), name));
        renters.push_back(R);
    }
    for(int i = 0; i < 10; i++){
        string name = str(i);
        Book_ptr B(new Book(name, name, name));
        books.push_back(B);
    }
    for(int i = 0; i < 10; i++){
        Rent_ptr R(new Rent(books[i], renters[i]));
        rents.create(R);
        if(i == 5){
            myRent = R;
        }
    }
    BOOST_CHECK_EQUAL(rents.find("5"), myRent);
}

BOOST_AUTO_TEST_SUITE_END()
