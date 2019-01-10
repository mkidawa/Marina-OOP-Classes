//
// Created by pobi on 10.01.19.
//

#include "Place.hpp"
#include <sstream>
#include <boost/lexical_cast.hpp>
#include <boost/uuid/uuid_io.hpp>

Place::Place(const std::string &zone, bool buoy, const boost::uuids::uuid &place_id) : zone(zone), buoy(buoy),
                                                                                       place_id(place_id) {}

Place::~Place() {}

std::string Place::get_info() {
    std::stringstream tmp;
    const std::string tmp2 = boost::lexical_cast<std::string>(place_id);
    const char * value = tmp2.c_str();
    tmp << "Place id: " << value << ", zone: " << this->zone;
    if(this->buoy) tmp << ", buoy present";
        else tmp << ", buoy absent";
    return tmp.str();
}
