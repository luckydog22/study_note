#include "judge.h"
#include "pokermanager.h"
#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

Judge::Judge()
{
    //��ʼ���������
    srand(time(0));

    //����һ���� ��ɫ������ ����������
    vector<string> colors = PokerManager::getInstance()->getColors();
    vector<string> points = PokerManager::getInstance()->getPoints();

    for(int i = 0 ; i < colors.size(); i++)
    {
        for(int j = 0 ; j < points.size(); j++)
        {
            pokerVec.push_back(Poker(colors[i],points[j]));
        }
    }
    pokerVec.push_back(Poker("����"));
    pokerVec.push_back(Poker("С��"));

    for(int i = 0 ; i < pokerVec.size(); i++)
        cout<<pokerVec[i].toString()<<" ";
    cout<<endl;

    //ϴ��
    shuffle(pokerVec);
}

Judge::~Judge()
{

}
//ϴ�ƺ��� �����ȡ����λ�� ������ ѭ����ʮ��
 void Judge::shuffle(vector<Poker>& pokerVec)
 {
     for(int i = 0 ; i < 50; i++)
     {
        int a = rand()%pokerVec.size();
        int b = rand()%pokerVec.size();
        Poker  temp = pokerVec[a];
        pokerVec[a] = pokerVec[b];
        pokerVec[b] = temp;
     }
     for(int i = 0 ; i < pokerVec.size(); i++)
         cout<<pokerVec[i].toString()<<" ";
     cout<<endl;



 }
 //���ƺ��� ���������е����һ����
 Poker Judge::deal()
 {
       //��ȡ�����һ�ţ�����
    Poker p =pokerVec.back();
     //�������ƴ��������Ƴ�
    pokerVec.pop_back();
        return p;
 }

