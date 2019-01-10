//
// Created by pobi on 10.01.19.
//

#ifndef POBIMARINA_RENT_HPP
#define POBIMARINA_RENT_HPP

#include <boost/uuid/uuid.hpp>
#include <boost/date_time/local_time/local_time.hpp>
#include <iostream>
#include <memory>
#include <string>

typedef boost::local_time::local_date_time LocalTime;
typedef boost::local_time::time_zone_ptr TimeZone;
typedef boost::posix_time::ptime PosixTime;

class Renter;
class Place;
class Rent;

typedef std::shared_ptr<Renter> Renter_ptr;
typedef std::shared_ptr<Place> Place_ptr;

class Rent {
    boost::uuids::uuid rent_id;
    //start: time_ptr
    //stop: time_ptr
    Place_ptr where;
    Renter_ptr who;

public:
    //konstruktor
    virtual ~Rent();
    std::string get_info();
};

#endif //POBIMARINA_RENT_HPP
