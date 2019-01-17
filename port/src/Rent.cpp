//
// Created by pobi on 10.01.19.
//

#include "Rent.hpp"
#include "Place.hpp"
#include "Renter.hpp"
#include <sstream>
#include <string>
#include <boost/uuid/random_generator.hpp>
#include <boost/date_time/local_time/local_time.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/uuid/uuid_io.hpp>

std::string Rent::get_info() {
    std::stringstream tmp;
    tmp << "Rent ID: " << this->UUID << ", start time: " << this->start << ", end time: " << this->stop << ", place id: " <<
          ", renter: " << this->who->get_info() << "\n";
    return tmp.str();
}

Rent::~Rent() {}

Rent::Rent(const PosixTime &start, const PosixTime &stop, const Place_ptr &where, const Renter_ptr &who) : start(start),
                                                                                                           stop(stop),
                                                                                                           where(where),
                                                                                                           who(who) {
    UUID = boost::uuids::random_generator()();
}

Rent::Rent(const std::string &start, const std::string &stop, const Place_ptr &where, const Renter_ptr &who) :
    Rent(PosixTime(boost::posix_time::time_from_string(start)), PosixTime(boost::posix_time::time_from_string(stop)), where, who) {}

const boost::uuids::uuid &Rent::getUUID() const {
    return UUID;
}

double Rent::calculateRealPrice() {
    double price = who->get_realPrice();
    if(where->isBuoy()) price += 10;
    std::string zone = where->getZone();
    if(zone == "A") price *= 1.2;
    else if (zone == "B") price *= 1.15;
    else if (zone == "C") price *= 1.1;
    boost::posix_time::time_duration diff = stop-start;
    std::stringstream sub;
    sub << diff;
    std::string conv = sub.str();
    std::string same = conv.substr(0,2);
    int hours = stoi(same);
    int days = hours/24;
    return price*days;
}

const PosixTime &Rent::getStart() const {
    return start;
}

const PosixTime &Rent::getStop() const {
    return stop;
}

const Place_ptr &Rent::getWhere() const {
    return where;
}

const Renter_ptr &Rent::getWho() const {
    return who;
}
