#ifndef LOGIC_H
#define LOGIC_H
#include "judge.h"
#include "player.h"
#include <vector>
using namespace std;


class Logic
{

 private:
    Judge judge;
    //������ҵ�����
    vector<Player> playVec;


public:
    Logic();

    void run();

    //ѭ��ѯ����� �Ƿ�Ҫ��
    void ask();

    //У��
    void check();

    //��ʾ������� ���е���
    void show();

    //��Ϸ����������
    bool isStop();

    //˭��Ӯ��
    void winner();



    ~Logic();
};

#endif // LOGIC_H
