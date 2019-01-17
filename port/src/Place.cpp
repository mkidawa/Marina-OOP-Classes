//
// Created by pobi on 10.01.19.
//

#include "Place.hpp"
#include <sstream>
#include <boost/lexical_cast.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/random_generator.hpp>

Place::Place(const std::string &zone, bool buoy) : zone(zone), buoy(buoy) {
    UUID = boost::uuids::random_generator()();
}

Place::~Place() {}

std::string Place::get_info() {
    std::stringstream tmp;
    const std::string tmp2 = boost::lexical_cast<std::string>(UUID);
    const char * value = tmp2.c_str();
    tmp << "Place id: " << value << ", zone: " << this->zone;
    if(this->buoy) tmp << ", buoy present";
        else tmp << ", buoy absent";
    return tmp.str();
}

const boost::uuids::uuid &Place::getUUID() const {
    return UUID;
}

const std::string &Place::getZone() const {
    return zone;
}

bool Place::isBuoy() const {
    return buoy;
}
