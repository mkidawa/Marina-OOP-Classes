//
// Created by pobi on 15.01.19.
//

#include "PlaceManager.hpp"

void PlaceManager::addPlace(Place_ptr place) {
    takenPlaces.add(place);
}

void PlaceManager::removePlace(Place_ptr place) {
    takenPlaces.remove(place);
}

std::vector<Place_ptr> PlaceManager::findAll(std::string zone) {
    std::vector<Place_ptr> ret = takenPlaces.findAll(zone);
    return ret;
}