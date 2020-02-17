#ifndef POKERMANAGER_H
#define POKERMANAGER_H
#include <vector>
#include<map>
#include<string>
using namespace std;

class PokerManager
{
 public:
    static PokerManager* getInstance();
    vector<string>& getColors();
    vector<string>& getPoints();
    map<string, int>& getScores();
private:
    vector<string> colors;
    vector<string> points;
    map<string,int> scores;
    PokerManager();




    PokerManager(const PokerManager& o);
    static PokerManager* instance;
    ~PokerManager();
};

#endif // POKERMANAGER_H
