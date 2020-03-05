#ifndef LINK
#define LINK

#include <cstdio>

template<typename T>
class Link
{
private:
    struct Node
    {
        T data;
        Node* pNext;
        Node* pFront;
        Node(){}
        Node(T data):data(data),pNext(NULL),pFront(NULL){}
    };
    Node* pHead;
    Node* pTail;
    int msize;
public:
    class iterator//��������װ��һ��ָ��
    {
    private:
        Node* pNode;
    public:
        iterator(){}
        iterator(Node* pNode):pNode(pNode){}
        bool operator!=(const iterator& other)
        {
            return pNode!=other.pNode;
        }
        
        iterator operator++(int a)
        {
            iterator tmp = *this;
            pNode = pNode->pNext;
            return tmp;
        }
        
        T& operator*()
        {
            return pNode->data;
        }
    };
    
public:
    Link():pHead(new Node),pTail(pHead),msize(0){}
    
    Link& add(T data)
    {
        Node* pNode = new Node(data);
        pTail->pNext = pNode;
        pNode->pFront = pTail;
        pTail = pNode;
        msize++;
        return *this;
    }
    
    T& operator[](int index)//�������õ�Ŀ����Ϊ���ܹ�ͨ������ֵ�����ݽ����޸�
    {
        Node* pNode = findNode(index);
        return pNode->data;
    }
    
    void erase(int index)
    {
        Node* pNode = findNode(index);
        if(pNode!=NULL)
        {
            eraseNode(pNode);
            msize--;
        }
    }
    
    void erase(int start, T data)
    {
        Node* pNode = findNode(start);
        while(pNode != NULL)
        {
            if(pNode->data == data)
            {
                pNode = eraseNode(pNode);
                msize--;
            }
            else
            {
                pNode = pNode->pNext;   
            }
        }
    }
    
    int size()
    {
        return msize;
    }
    
    iterator begin()
    {
        iterator iter(pHead->pNext);
        return iter;
    }
    
    iterator end()
    {
        iterator iter(NULL);
        return iter;
    }
private:
    Node* findNode(int index)
    {
        Node* pNode = pHead->pNext;
        for(int i = 0;i < index;i++)
        {
            pNode = pNode->pNext;
        }
        return pNode;
    }
    Node* eraseNode(Node* pNode)//����ֵ����һ���ڵ��ָ�룬��Ϊ��ǰ����ڵ㱻ɾ���ˣ�pNode�Ѿ���Ұָ����
    {
        Node* tmp = pNode->pNext;
        if(pNode == pTail)//ɾ����β
        {
            pNode->pFront->pNext = NULL;
            pTail = pTail->pFront;
            delete pNode;
        }
        else//ɾ������
        {
            pNode->pFront->pNext = pNode->pNext;
            pNode->pNext->pFront = pNode->pFront;
            delete pNode;
        }
        return tmp;
    }
};

#endif // LINK

