#include "FlexLL.h"
#include "TVShow.h"
#include <iostream>
#include <cassert>

using namespace std;

void testFlexLL() {
    cout << "================================================" << endl;
    cout << "Testing FlexLL..." << endl;

    //Test empty()
    cout << "Testing empty list... ";
    FlexLL<int> list;
    assert(list.empty());
    cout << "passed!" << endl;

    //Test append()
    cout << "Testing append... ";
    list.append(10);
    list.append(20);
    assert(!list.empty());
    cout << "passed!" << endl;

    //Test prepend()
    cout << "Testing prepend... ";
    list.prepend(1);
    
    //Verify order after prepend
    list.rewind();
    assert(list.proceed() == 1);
    assert(list.proceed() == 10);
    assert(list.proceed() == 20);
    cout << "passed!" << endl;

    //Test sort()
    cout << "Testing sort... ";
    list.append(2);
    list.sort();

    list.rewind();
    assert(list.proceed() == 1);
    assert(list.proceed() == 2);
    assert(list.proceed() == 10);
    assert(list.proceed() == 20);
    cout << "passed!" << endl;

    //Test thin() (removes duplicates)
    cout << "Testing thin... ";
    list.append(2);
    list.append(10);
    list.append(20);
    assert(list.thin());

    list.rewind();
    assert(list.proceed() == 1);
    assert(list.proceed() == 2);
    assert(list.proceed() == 10);
    assert(list.proceed() == 20);
    cout << "passed!" << endl;

    //Test iteration (rewind, finished, proceed)
    cout << "Testing iteration... ";
    list.rewind();
    int count = 0;
    while (!list.finished()) {
        list.proceed();
        count++;
    }
    assert(count == 4);
    cout << "passed!" << endl;

    //Test flush()
    cout << "Testing flush... ";
    list.flush();
    assert(list.empty());
    cout << "passed!" << endl;

    //Test self-prepending (copy=false should not modify the list)
    cout << "Testing self-prepending... ";
    FlexLL<int> self_list;
    self_list.append(100);
    self_list.append(200);
    self_list.prepend(self_list, false); //Should remain unchanged
    self_list.rewind();
    assert(self_list.proceed() == 100);
    assert(self_list.proceed() == 200);
    assert(self_list.finished());
    cout << "passed!" << endl;

    //Test compare() specialization for Actor and Episode
    cout << "Testing Actor compare... ";
    Actor actor1("John Doe");
    Actor actor2("Jane Doe");
    assert(compare(actor1, actor2) > 0);
    cout << "passed!" << endl;
    

    Episode ep1("Pilot", 1);
    Episode ep2("Finale", 1);
    cout << "Testing Episode compare... " << endl;
    int result = compare(ep1, ep2);
    cout << "Comparing Episodes: " << ep1.title << " (S" << ep1.season << ") vs "
         << ep2.title << " (S" << ep2.season << ")" << endl;
    cout << "Compare result: " << result << endl;
    assert(result == -1 || result == 0 || result == 1); //Ensures it returns valid compare values
    

    Episode ep3("Pilot", 2);
    assert(compare(ep1, ep3) < 0); //Different season
    cout << "passed!" << endl;

    cout << "All FlexLL tests passed!" << endl;
    cout << "================================================\n" << endl;
}


void testTVShow() {
    cout << "================================================" << endl;
    cout << "Testing TVShow: 'The Life of a Last-Minute Coder'..." << endl;
    TVShow show("The Life of a Last-Minute Coder");

    //Adding Actors
    show.addActor("Professor Debugging");
    show.addActor("Stack Overflow Addict");
    show.addActor("Sleep-Deprived Student");
    show.addActor("Group Project Ghost");
    show.addActor("Sleep-Deprived Student");  //Duplicate

    cout << "\nActors after adding:" << endl;
    show.display();
    cout << "================================================" << endl;

    //Adding Episodes
    show.addEpisode("Day 1: I Will Start Early This Time", 1);
    show.addEpisode("Day 7: Plenty of Time Left", 1);
    show.addEpisode("Day 14: The Debugging Spiral", 2);
    show.addEpisode("Day 15: Why Didn't It Work?", 4);
    show.addEpisode("Day 14: The Debugging Spiral", 2);  //Duplicate

    cout << "\nEpisodes after adding:" << endl;
    show.display();
    cout << "================================================" << endl;

    //Sorting Actors & Episodes
    show.sortActors();
    show.sortEpisodes();

    cout << "\nActors and Episodes after sorting:" << endl;
    show.display();
    cout << "================================================" << endl;
   

    //Removing Duplicates
    show.thinActors();
    show.thinEpisodes();

    cout << "\nActors Episodes after removing duplicates:" << endl;
    show.display();
    cout << "================================================" << endl;

    cout << "\nFlushing the show data (Just like forgetting everything after (sometimes before) the exam)..." << endl;
    show.flushShow();
    cout << "\nAfter flushing show:\n";
    show.display();
    cout << "================================================" << endl;

    cout << "\n'The Life of a Last-Minute Coder' tests passed! (But the show is not over yet...)" << endl;
    cout << "================================================" << endl;
}



int main() {
    testFlexLL();
    testTVShow();
    cout << "\nAll tests passed successfully!" << endl;
    return 0;
}


//instantiation of template class
template class FlexLL<int>;
