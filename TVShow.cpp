#include <iostream>
#include <stdlib.h>
#include "TVShow.h"
using namespace std;

TVShow::TVShow(string name_p, unsigned int pilot_year_p, string productioncompany_p, string network_p, unsigned int totalep_p){
  name = name_p;
  pilot_year = pilot_year_p;
  productioncompany = productioncompany_p;
  network = network_p;
  totalep = totalep_p;
};

TVShow::TVShow() : name(""), pilot_year(0), productioncompany(""), network(""), totalep(0) {};

TVShow::TVShow(string name_p) {
    name = name_p;
    pilot_year = 2023;
    productioncompany = "Self-Produced";
    network = "YouTube";
    totalep = 0;
}

string TVShow::getName() const{
  return name;
}

unsigned int TVShow::getPilotYear() const{
  return pilot_year;
}

string TVShow::getProductionCompany() const{
  return productioncompany;
}

string TVShow::getNetwork() const{
  return network;
}

unsigned int TVShow::getTotalEp() const{
  return totalep;
}

void TVShow:: display() const{
  cout << "TV Show: " << name << endl;
    cout << endl;

    cout << "Cast:" << endl;
    cast.rewind();
    while (!cast.finished()) {
        cout << "[" << cast.proceed().getName() << "] ";
    }
    cout << endl << endl;

    cout << "Episodes:" << endl;
    episodes.rewind();
    while (!episodes.finished()) {
        Episode ep = episodes.proceed();
        cout << "[S" << ep.getSeason() << ": " << ep.getTitle() << "] ";
    }
    cout << endl;
}

void TVShow::addActor(const string& actor) {
    cast.append(Actor(actor));
}

void TVShow::addEpisode(const string& title, int season) {
    episodes.append(Episode(title, season));
}

void TVShow::sortActors() {
    cast.sort();
}

void TVShow::sortEpisodes() {
    episodes.sort();
}

void TVShow::thinActors() {
    cast.thin();
}

void TVShow::thinEpisodes() {
    episodes.thin();
}

void TVShow::flushShow() {
    cast.flush();
    episodes.flush();
}
