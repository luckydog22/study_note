#include "logic.h"
#include <iostream>

using namespace std;
Logic::Logic()
{
    //创建玩家
    playVec.push_back(Player("谢广坤"));
    playVec.push_back(Player("刘能"));
    playVec.push_back(Player("赵四"));

}
//游戏开始
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

 //循环询问玩家 是否要牌
void Logic::ask()
{
    /*
     * 1.for循环询问所有玩家
     * 判断 如果want为true
     * 2.谢广坤奥不要牌？y or n？
     * 3.获取输入的字符，如果为y 裁判发牌，玩家保存到容器中
     * 4.如果为n  将玩家的want 置为false
     */
    for(int i = 0 ; i < playVec.size(); i++)
    {
        if(!playVec[i].getWant())
        {
            continue;
        }
        cout<<playVec[i].getName()<<"要不要牌？Y OR N?"<<endl;
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
//校验分值 和12进行比较
void Logic::check()
{
    /*
     * 如果分数大于21 提示出局，将want变为false
     * */
    for(int i = 0 ; i < playVec.size();i++)
    {
        if(playVec[i].getScores() >21)
        {
            playVec[i].setWant(false);
            cout<<playVec[i].getName()<<" 爆了。。。"<<endl;
        }
    }


}

//显示所有玩家手中都有哪些牌
void Logic::show()
{
    for(int i = 0 ; i < playVec.size();i++)
    {
        playVec[i].show();
    }
    cout<<endl;

}

//游戏是否还要继续 循环停止的条件
bool Logic::isStop()
{

    for(int i = 0 ; i < playVec.size();i++)
    {
        //获取玩家的want值，所有都为false时，返回true
        //有一个为true，则返回false
        if(playVec[i].getWant())
        {
            return false;
        }
    }
    return true;
}

//判断没有超过21的玩家 谁最接近21  谁获胜
void Logic::winner()
{
    int score = 21;
    int index = -1;
     //比较在小于21的人里边，找最接近21 的，赢
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
        cout<<"全都爆了"<<endl;
    }

}




Logic::~Logic()
{

}

