#include <iostream>
#include <sstream>
#include "ItemsManager.hpp"
#include "RentersManager.hpp"
#include "RentsManager.hpp"

#include "Renter.hpp"
#include "Rent.hpp"
#include "Book.hpp"

using namespace std;

int main() {

    ItemsManager rzeczy;
    RentersManager ludzie;
    RentsManager wypoz;

    rzeczy.add(Book_ptr(new Book("nazwa1","gatunek","autor")));
    rzeczy.add(Book_ptr(new Book("nazwa2","gatunek","autor")));

    ludzie.add(Renter_ptr(new Renter("imie1", "2017-12-30 00:00:00", "adres")));

    wypoz.rent(ludzie("imie1"), rzeczy("nazwa1"));

    wypoz.end(rzeczy("nazwa1"));

    return 0;
}
