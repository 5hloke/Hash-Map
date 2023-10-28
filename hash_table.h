#include <iostream>
#include <iomanip>
#include <list>



using namespace std;

template <typename T, typename V>

class HashTable{
    
    private:
    static const int size = 10;
    list<pair<T, V> > hashMap[size];
    
    public:

    void insert(T key, V value);
    bool isEmpty();
    int hashingFunction(T key);
    V search(T key);
    bool remove(T key);
    void print();

};