//
// Created by pobi on 10.01.19.
//

#ifndef POBIMARINA_PLACE_HPP
#define POBIMARINA_PLACE_HPP

#include <boost/uuid/uuid.hpp>
#include <iostream>
#include <string>
#include <memory>


class Place {
    std::string zone;
    bool buoy;
    boost::uuids::uuid UUID;
public:
    Place(const std::string &zone, bool buoy);
    virtual ~Place();
    std::string get_info();
    const boost::uuids::uuid &getUUID() const;
    const std::string &getZone() const;
    bool isBuoy() const;
};

typedef std::shared_ptr<Place> Place_ptr;


#endif //POBIMARINA_PLACE_HPP
