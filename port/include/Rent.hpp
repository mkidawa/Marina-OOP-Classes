//
// Created by pobi on 10.01.19.
//

#ifndef POBIMARINA_RENT_HPP
#define POBIMARINA_RENT_HPP

#include <boost/uuid/uuid.hpp>
#include <boost/date_time/local_time/local_time.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <iostream>
#include <memory>
#include <string>

typedef boost::posix_time::ptime PosixTime;

class Renter;
class Place;
class Rent;

typedef std::shared_ptr<Renter> Renter_ptr;
typedef std::shared_ptr<Place> Place_ptr;

class Rent {
    boost::uuids::uuid UUID;
    PosixTime start;
    PosixTime stop;
    Place_ptr where;
    Renter_ptr who;

public:
    Rent(const PosixTime &start, const PosixTime &stop, const Place_ptr &where, const Renter_ptr &who);
    Rent(const std::string &start, const std::string &stop, const Place_ptr &where, const Renter_ptr &who);
    virtual ~Rent();
    std::string get_info();
    const boost::uuids::uuid &getUUID() const;
};

#endif //POBIMARINA_RENT_HPP