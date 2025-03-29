#ifndef ACTOR_H
#define ACTOR_H

#include <string>
#include <iostream>
using namespace std;

class Actor{
 private:
  string name;
 public:
 Actor() : name(""){}
 Actor(const string& actorName) : name(actorName) {}
 string getName() const { return name; }
  void display() const{
    cout << name << endl;
  }

};

inline int compare(const Actor& a1, const Actor& a2) {
    if (a1.getName() < a2.getName()) return -1;
    else if (a1.getName() > a2.getName()) return 1;
    return 0;
}

#endif
  
