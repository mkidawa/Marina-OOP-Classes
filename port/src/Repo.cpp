//
// Created by pobi on 15.01.19.
//

#include "Repo.hpp"
#include "Place.hpp"
#include "Rent.hpp"
#include "RentException.hpp"
#include <vector>
#include <iostream>

template<>
void Repo<Rent_ptr>::add(Rent_ptr obj) {
    if(container.size()==0)
    {
        container.push_back(obj);
    }
    else
    {
        for(auto i:container) {
            boost::posix_time::time_duration diff1 = obj->getStart() - i->getStop();
            std::stringstream sub1;
            sub1 << diff1;
            std::string conv1 = sub1.str();
            std::string same1 = conv1.substr(0, ':');
            int hours1 = std::stoi(same1);
            int days1 = hours1 / 24;
            boost::posix_time::time_duration diff2 = i->getStart() - obj->getStop();
            std::stringstream sub2;
            sub2 << diff2;
            std::string conv2 = sub2.str();
            std::string same2 = conv2.substr(0, ':');
            int hours2 = std::stoi(same2);
            int days2 = hours2 / 24;
            if(i->getStart()<obj->getStart())
            {
                if (i->getWhere() == obj->getWhere() && days1>=0)
                {
                    container.push_back(obj);
                }
                else
                {
                    throw RentException("Following dates are not correct!");
                }
            }
            else if(i->getStart()>obj->getStart())
            {
                if (i->getWhere() == obj->getWhere() && days2>=0)
                {
                    container.push_back(obj);
                }
                else
                {
                    throw RentException("Following dates are not correct!");
                }
            }
            else
            {
                throw RentException("Following dates are not correct!");
            }
        }
    }

};

template<>
void Repo<Place_ptr>::add(Place_ptr object)
{
    container.push_back(object);
}

template<>
void Repo<Renter_ptr>::add(Renter_ptr object)
{
    container.push_back(object);
}

template<>
Place_ptr Repo<Place_ptr>::find(std::string zone) {
    for(auto i : container) {
        if(i->getZone() == zone) return i;
    }
    return nullptr;
}
template<>
std::vector<Place_ptr> Repo<Place_ptr>::findAll(std::string zone) {
    std::vector<Place_ptr> found;
    for(auto i : container) {
        if(i->getZone() == zone) found.push_back(i);
    }
    return found;
}