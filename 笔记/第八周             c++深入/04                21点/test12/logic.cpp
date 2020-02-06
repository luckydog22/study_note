#include "logic.h"
#include <iostream>

using namespace std;
Logic::Logic()
{
    //�������
    playVec.push_back(Player("л����"));
    playVec.push_back(Player("����"));
    playVec.push_back(Player("����"));

}
//��Ϸ��ʼ
void Logic::run()
{
    while(!isStop())
    {
        ask();
        check();
        show();

    }
    winner();

}

 //ѭ��ѯ����� �Ƿ�Ҫ��
void Logic::ask()
{
    /*
     * 1.forѭ��ѯ���������
     * �ж� ���wantΪtrue
     * 2.л�����²�Ҫ�ƣ�y or n��
     * 3.��ȡ������ַ������Ϊy ���з��ƣ���ұ��浽������
     * 4.���Ϊn  ����ҵ�want ��Ϊfalse
     */
    for(int i = 0 ; i < playVec.size(); i++)
    {
        if(!playVec[i].getWant())
        {
            continue;
        }
        cout<<playVec[i].getName()<<"Ҫ��Ҫ�ƣ�Y OR N?"<<endl;
        char input;
        cin>>input;
        if(input == 'y')
        {
            Poker p =judge.deal();
            playVec[i].addPoker(p);
        }else
        {
            playVec[i].setWant(false);
        }

    }

}
//У���ֵ ��12���бȽ�
void Logic::check()
{
    /*
     * �����������21 ��ʾ���֣���want��Ϊfalse
     * */
    for(int i = 0 ; i < playVec.size();i++)
    {
        if(playVec[i].getScores() >21)
        {
            playVec[i].setWant(false);
            cout<<playVec[i].getName()<<" ���ˡ�����"<<endl;
        }
    }


}

//��ʾ����������ж�����Щ��
void Logic::show()
{
    for(int i = 0 ; i < playVec.size();i++)
    {
        playVec[i].show();
    }
    cout<<endl;

}

//��Ϸ�Ƿ�Ҫ���� ѭ��ֹͣ������
bool Logic::isStop()
{

    for(int i = 0 ; i < playVec.size();i++)
    {
        //��ȡ��ҵ�wantֵ�����ж�Ϊfalseʱ������true
        //��һ��Ϊtrue���򷵻�false
        if(playVec[i].getWant())
        {
            return false;
        }
    }
    return true;
}

//�ж�û�г���21����� ˭��ӽ�21  ˭��ʤ
void Logic::winner()
{
    int score = 21;
    int index = -1;
     //�Ƚ���С��21������ߣ�����ӽ�21 �ģ�Ӯ
    for(int i = 0 ; i < playVec.size();i++)
    {
        int s = 21 - playVec[i].getScores();
        if(s >= 0 && s < score)
        {
            score = s;
            index = i;
        }
    }
    if(index == -1)
    {
        cout<<"ȫ������"<<endl;
    }

}




Logic::~Logic()
{

}

