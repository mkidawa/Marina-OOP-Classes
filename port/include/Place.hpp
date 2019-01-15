//
// Created by pobi on 10.01.19.
//

#ifndef POBIMARINA_PLACE_HPP
#define POBIMARINA_PLACE_HPP

#include <boost/uuid/uuid.hpp>
#include <iostream>
#include <string>


class Place {
    std::string zone;
    bool buoy;
    boost::uuids::uuid place_id;
public:
    Place(const std::string &zone, bool buoy, const boost::uuids::uuid &place_id);
    virtual ~Place();
    std::string get_info();
};

#endif //POBIMARINA_PLACE_HPP
