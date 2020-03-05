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
    class iterator//迭代器封装了一个指针
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
    
    T& operator[](int index)//返回引用的目的是为了能够通过返回值对数据进行修改
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
    Node* eraseNode(Node* pNode)//返回值是下一个节点的指针，因为当前这个节点被删除了，pNode已经是野指针了
    {
        Node* tmp = pNode->pNext;
        if(pNode == pTail)//删除结尾
        {
            pNode->pFront->pNext = NULL;
            pTail = pTail->pFront;
            delete pNode;
        }
        else//删除其他
        {
            pNode->pFront->pNext = pNode->pNext;
            pNode->pNext->pFront = pNode->pFront;
            delete pNode;
        }
        return tmp;
    }
};

#endif // LINK

