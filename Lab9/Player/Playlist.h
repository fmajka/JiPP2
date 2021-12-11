//
// Created by Franek on 06.11.2021.
//

#ifndef PLAYER_PLAYLIST_H
#define PLAYER_PLAYLIST_H

#include <iostream>
#include <list>
#include "Playlist.h"
#include "Track.h"

using namespace std;

class Playlist {
private:
    string name;
    list<Track> tracks;

public:
    Playlist(const string &name);

    void addTrack(Track * track);
    void removeTrack(Track * track);

    void print();
    Playlist play();
};



#endif //PLAYER_PLAYLIST_H
