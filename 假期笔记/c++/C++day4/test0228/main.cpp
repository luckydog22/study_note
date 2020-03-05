#include <iostream>
#include <map>

using namespace std;

template<typename T>
T div(T a, T b)
{
    return a/b;
}

class Person
{
public:
    Person(const char* name):name(name)
    {
        
    }
    bool operator<(const Person& other) const
    {
        return name < other.name;
    }
    string getName() const
    {
        return name;
    }
private:
    string name;
};

int main()
{  
    map<Person, int> m;
    m.insert(pair<Person, int>("jack", 18));
    m.insert(pair<Person, int>("rose", 1));
    m.insert(pair<Person, int>("tom", 2));
    m.insert(pair<Person, int>("jerry", 3));
    
    for(map<Person, int>::iterator iter = m.begin();iter != m.end();iter++)
    {
        cout<<iter->first.getName()<<" "<<iter->second<<endl;
    }

    
    //Á·Ï°1
//    cout<<div<int>(10, 3)<<endl;
//    cout<<div<double>(10, 3)<<endl;
    //Á·Ï°2
//    Link<int> l;
//    l.add(1).add(2).add(3).add(4).add(5).add(6).add(5).add(5).add(5);
//    l[2] = 99;
//    //l.erase(3);
//    l.erase(5, 5);
//    for(int i = 0;i < l.size();i++)
//    {
//        cout<<l[i]<<endl;
//    }
    //Ê¾Àı  Ä£·Âµü´úÆ÷
//    Link<int> l;
//    for(int i = 0;i < 10;i++)
//    {
//        l.add(i);
//    }
    
//    for(Link<int>::iterator iter = l.begin();iter != l.end();iter++)
//    {
//        cout<<*iter<<endl;
//    }
    
    return 0;
}

