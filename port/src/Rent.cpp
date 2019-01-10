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
    //tmp << "Rent ID: " << this->rent_id << ", start time: " << this->start << ", end time: " << this->stop << ", place id: " <<
    //      << ", renter: " << getInfo_od_rentera;
    return tmp.str();
}

Rent::~Rent() {

}
