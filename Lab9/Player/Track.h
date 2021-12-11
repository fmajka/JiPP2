//
// Created by Franek on 06.12.2021.
//

#ifndef PLAYER_TRACK_H
#define PLAYER_TRACK_H

#include <iostream>

using namespace std;

class Track {
private:
    string name;
    string band;
    int year;

public:
    Track(const string &name, const string &band, int year);

    Track() {};

    void print();
    string getName();

    bool operator==(const Track &rhs) const;
};


#endif //PLAYER_TRACK_H
