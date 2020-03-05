#include "mylink.h"

MyLink::MyLink():
    pHead(new Node),
    pTail(pHead),
    size(0)
{
    
}

MyLink::~MyLink()
{
    Node* pNode = pHead;//É¾³ýÁ´±í
    while(pNode != NULL)
    {      
        Node* pTmp = pNode;
        pNode = pNode->pNext;
        delete pTmp;
    }
}

void MyLink::add(int data)
{
    Node* pNode = new Node(data);
    pTail->pNext = pNode;
    pTail = pNode;
    size++;
}

int MyLink::get(int index)
{
    if(index >= size)//Ô½½ç
    {
        return -1;
    }
    Node* pNode = pHead->pNext;
    for(int i = 0;i < index;i++)
    {
        pNode = pNode->pNext;
    }
    return pNode->num;
}

int MyLink::getSize()
{
    return size;
}
