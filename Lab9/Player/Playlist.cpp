//
// Created by Franek on 06.11.2021.
//

#include "Playlist.h"
#include "Track.h"

Playlist::Playlist(const string &name) : name(name) {};

void Playlist::addTrack(Track * track) {
    tracks.push_back(*track);
}

void Playlist::removeTrack(Track * track){
    for (auto it = tracks.begin(); it != tracks.end(); it++) {
        if (*it == *track) {
            tracks.erase(it);
            break;
        }
    }
}

//odtworz utwory w playliscie
Playlist Playlist::play() {
    int i = 0;
    cout << "Title: " << name << endl;
    cout << "Tracks: " << endl;

    for (auto x = tracks.begin(); x != tracks.end(); x++) {
        cout << ++i << ". " << (x->getName()) << endl;
    }

    //zwraca wskaznik do samego siebie dla kolejnego odtworzenia
    return *this;
}

//pokaz dokladne informacje na temat utworow
void Playlist::print() {
    int i = 0;
    cout << "Info about tracks contained by the playlist " << name << ":" << endl;
    for (auto x = tracks.begin(); x != tracks.end(); x++) {
        cout << ++i << ". ";
        x->print();
    }
}

