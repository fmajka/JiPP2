#include <iostream>
#include <list>
#include "Track.h"
#include "Playlist.h"

using namespace std;

//utwory globalnie dostepne
list<Track> tracks;

//zwraca wskanik do utworu o danym indeksie
Track* getTrackByIndex(int i){
    auto it = tracks.begin();
    advance(it, i);
    return (&(*it));
}

//zwraca wskanik do utworu o danej nazwie
Track* getTrackByName(string name){
    for (auto it = tracks.begin(); it != tracks.end(); it++) {
        if(it->getName() == name)
            return (&(*it));
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    //Zadanie 1
    string napis = "chowder mp3 player";
    cout << "Maly napis: " << napis << endl;

    //iteruje napis
    for (auto x = napis.begin(); x != napis.end(); x++) {
        if((*x) >= 'a' && (*x) <= 'z')
            (*x)-=32;   //konwertuje maly znak na duzy
    }

    cout << "Duzy napis: " << napis << endl << endl;

    //Zadanie 2
    //dodaj utwory do wspolnej listy
    tracks.emplace_back(Track("Warrior of Ice", "Rhapsody", 1997));
    tracks.emplace_back(Track("Emerald Sword", "Rhapsody", 1998));
    tracks.emplace_back(Track("Dawn of Victory", "Rhapsody", 2000));
    tracks.emplace_back(Track("Dragonland's Rivers", "Rhapsody", 2004));
    tracks.emplace_back(Track("Majesty", "Wind Rose", 2012));
    tracks.emplace_back(Track("Distant Battlefields", "Wind Rose", 2017));

    //stworz nowa pusta playliste
    Playlist p1("Emerald Sword Saga");

    //dodaj/usun kawalki (poprzez nazwe lub index na wspolnej liscie)
    p1.addTrack(getTrackByIndex(1));
    p1.addTrack(getTrackByIndex(2));
    p1.addTrack(getTrackByIndex(4));
    p1.addTrack(getTrackByName("Warrior of Ice"));
    p1.removeTrack(getTrackByName("Majesty"));

    p1.print();
    //odtwarzanie w petli
    p1.play().play();

    return 0;
}
