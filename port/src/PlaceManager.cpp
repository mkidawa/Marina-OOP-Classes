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

std::vector<Place_ptr> PlaceManager::showPlaces(std::string zone) {
    std::vector<Place_ptr> places;
    places.push_back(takenPlaces.find(zone));
    return places;
}

bool PlaceManager::isTaken(boost::uuids::uuid UUID) {
    if(takenPlaces.find(UUID) != nullptr) return 1;
    else return 0;
}