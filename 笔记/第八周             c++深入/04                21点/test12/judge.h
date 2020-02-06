#ifndef JUDGE_H
#define JUDGE_H
#include<vector>
#include "poker.h"
using namespace std;
class Judge
{
 private:
    vector<Poker> pokerVec;
public:

    //Ï´ÅÆº¯Êý
    void shuffle(vector<Poker>& pokerVec);

    //·¢ÅÆº¯Êý
    Poker deal();

    Judge();
    ~Judge();
};

#endif // JUDGE_H
