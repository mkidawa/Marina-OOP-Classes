//
// Created by pobi on 10.01.19.
//

#include "Rent.hpp"
#include "Place.hpp"
//#include "Renter.hpp"
#include <boost/uuid/random_generator.hpp>
#include <boost/date_time/local_time/local_time.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/uuid/uuid_io.hpp>

std::string Rent::get_info() {
    std::stringstream tmp;
    tmp << "Rent ID: " << this->rent_id << ", start time: " << this->start << ", end time: " << this->stop << ", place id: " <<
          ", renter: ";
    return tmp.str();
}

Rent::~Rent() {}

Rent::Rent(const PosixTime &start, const PosixTime &stop, const Place_ptr &where, const Renter_ptr &who) : start(start),
                                                                                                           stop(stop),
                                                                                                           where(where),
                                                                                                           who(who) {
    rent_id = boost::uuids::random_generator()();
}

Rent::Rent(const std::string &start, const std::string &stop, const Place_ptr &where, const Renter_ptr &who) :
    Rent(PosixTime(boost::posix_time::time_from_string(start)), PosixTime(boost::posix_time::time_from_string(stop)), where, who) {}
