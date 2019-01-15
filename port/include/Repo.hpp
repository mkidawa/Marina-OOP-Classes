//
// Created by pobi on 15.01.19.
//

#ifndef POBIMARINA_REPO_HPP
#define POBIMARINA_REPO_HPP

#include <vector>
#include <memory>
#include <string>
#include <fstream>
#include <algorithm>
#include <boost/uuid/uuid.hpp>

template <class T>
class Repo {
    std::vector<T> container;

public:
    void add(T object) {
        container.push_back(object);
    };
    void remove(T object) {
        container.erase(std::find(container.begin(), container.end(), object));
    };
    T find(boost::uuids::uuid UUID) {
        for(auto i : container) {
            if(i->getUUID == UUID) return i;
        }
        return nullptr;
    };
    Repo<T>() {};
};


#endif //POBIMARINA_REPO_HPP
