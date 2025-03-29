#include "Episode.h"
#include <iostream>

Episode::Episode() : title(""), season(0){}

Episode::Episode(const string& title, int season) : title(title), season(season) {}

string Episode::getTitle() const {
    return title;
}

int Episode::getSeason() const {
    return season;
}

void Episode::display() const {
    cout << "S" << season << " | " << title << endl;
}
