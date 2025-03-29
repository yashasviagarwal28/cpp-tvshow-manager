#ifndef TVSHOW_H 
#define TVSHOW_H

#include <iostream>
using namespace std;
#include <string>

#include "FlexLL.h"
#include "Episode.h"
#include "Actor.h"

class TVShow {
   public:
  TVShow(string name_p, unsigned int pilot_year_p, string productioncompany_p, string network_p, unsigned int totalep_p);
      TVShow();
  TVShow(string name_p);

  void display() const;
  string getName() const;
  unsigned int getPilotYear() const;
  string getProductionCompany() const;
  string getNetwork() const;
  unsigned int getTotalEp() const;

  void addActor(const string& actor);
  void addEpisode(const string& title, int season);
  void sortActors();
  void sortEpisodes();
  void thinActors();
  void thinEpisodes();
  void flushShow();
  
   private:
      string name = "";
      unsigned int pilot_year = 0;
  string productioncompany = "";
  string network = "";
  unsigned int totalep = 0;

  FlexLL<Actor> cast;
    FlexLL<Episode> episodes;
  
};

#endif
