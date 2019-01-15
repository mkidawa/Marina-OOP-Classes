//
// Created by pobi on 15.01.19.
//

#ifndef POBIMARINA_PLACEMANAGER_HPP
#define POBIMARINA_PLACEMANAGER_HPP

#include "Repo.hpp"
#include "Place.hpp"
#include "Rent.hpp"
#include <vector>
#include <string>

class PlaceManager {
    Repo<Place_ptr> takenPlaces;

public:
    void addPlace(Place_ptr place);
    void removePlace(Place_ptr place);
    std::vector<Place_ptr> showPlaces(std::string zone);
    bool isTaken(boost::uuids::uuid UUID);
};


#endif //POBIMARINA_PLACEMANAGER_HPP
