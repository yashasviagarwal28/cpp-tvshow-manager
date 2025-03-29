#ifndef EPISODE_H
#define EPISODE_H
#include <iostream>
#include <string>
using namespace std;

class Episode {

public:
  string title;
  int season;

    Episode();
    Episode(const string& title, int season);
    string getTitle() const;
    int getSeason() const;
    void display() const;
};

inline int compare(const Episode &a, const Episode &b) {
    if (a.getSeason() < b.getSeason()) return -1;
    if (a.getSeason() > b.getSeason()) return 1;
    if (a.getTitle() < b.getTitle()) return -1;
    if (a.getTitle() > b.getTitle()) return 1;
    return 0;
}

#endif
