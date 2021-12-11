//
// Created by Franek on 06.12.2021.
//

#include "Track.h"

Track::Track(const string &name, const string &band, int year) : year(year), name(name), band(band) {}

//wypisuje dokladne informacje na temat utworu
void Track::print() {
    cout<< name << " by " << band << " released in " << year << endl;
}

//zwraca nazwe utworu
string Track::getName(){
    return this->name;
}

bool Track::operator==(const Track &rhs) const {
    if(name == rhs.name && band == rhs.band && year == rhs.year)
        return true;
    return false;
}
