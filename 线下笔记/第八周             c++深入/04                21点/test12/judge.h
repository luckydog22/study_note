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

    //ϴ�ƺ���
    void shuffle(vector<Poker>& pokerVec);

    //���ƺ���
    Poker deal();

    Judge();
    ~Judge();
};

#endif // JUDGE_H
