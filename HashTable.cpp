#include "hash_table.h"

/* Name: Shlok Agarwal
Creating a HAsh MAp just for fun.
Hash Table class implemented below*/

// template<typename T, typename V>
// HashTable<T, V>::HashTable(){
//     // Nothing needed in the constructor

    
// }

template<typename T, typename V>
int HashTable<T, V>::hashingFunction(T key){
        hash<T> hasher;
        return hasher(key) %10;
}


template<typename T, typename V>
bool HashTable<T, V>::isEmpty(){
            int sum = 0;
        for (int i = 0; i < size; i++){ // check the size of every list to check if the Hash table is empty or not
            sum += hashMap[i].size();
        }
    
        return !sum;
}

template<typename T, typename V>
void HashTable<T, V>::insert(T key, V value){
            // inserting a key value pair in the Hash table;

    // first get the hash value of the key

    int hash = hashingFunction(key);

    // First check if the key already exists in the table or not
    // auto& temp = hashMap[hash];
    // auto iterator = begin(temp);
    list<pair<T, V> >& temp = hashMap[hash];
    auto it  = begin(temp);
    bool key_present = false;
    for ( ; it != end(temp); it++){
        if (it->first == key){
            cout << "[WARNING]: Already existing key updated." << endl;
            it->second = value;
            key_present = true;
            break;
        }
        cout << it->first << endl; 
    }
        // once the hash value is created and the key does not exist in the table already then and the key, value pair to the hash table 

    if (!key_present){
        cout << "A new key-value pair was inserted in the table." << endl;
        // make_pair(key, value);
        temp.push_back(make_pair(key, value));
        //hashMap[hash].emplace_back(key, value);
        //cout << hashMap[hash] << endl;
    }

}

template<typename T, typename V>
void HashTable<T, V>::print(){
    if (!isEmpty()){
        for (int i = 0; i < 10; i++){
            if (!hashMap[i].empty()){
                auto iterator = hashMap[i].begin();
                for (; iterator != hashMap[i].end(); iterator++){
                    cout << "Key: " << iterator->first << " ," << " Value: " << iterator->second << endl;
                }
            }
            
        }
    }
}

template<typename T, typename V>
bool HashTable<T, V>::remove(T key){
    if (isEmpty()){
        cout << "[ERROR]: The table is empty. Could not remove the key." << endl;
    }
    int hash = hashingFunction(key);
    auto& table = hashMap[hash];
    auto iterator = table.begin();
    bool key_found = false;
    for (; iterator != table.end(); iterator++){
        if (iterator->first == key){
            key_found = true;
            table.erase(iterator);
            cout << "Key-Value pair  deleted" << endl;
            return true;
        }
    }

    cout << "[WARNING]: Key was not found. Nothing removed from the table." << endl;
    return false;
}

template<typename T, typename V>
V HashTable<T, V>::search(T key){
    if (isEmpty()){
        cout << "[ERROR]: The table is empty, nothing to search." << endl;
        return NULL;
    }

    int hash = hashingFunction(key);
    auto table = hashMap[hash];
    auto it = table.begin();
    for (; it != table.end(); it++){
        if (it->first == key){
            cout << "Key was found and the value associated with the key is: " << it->second << endl ;
            return it->second;
        }
    }
    
    cout << "[WARNING]: Key not present" << endl;
    return NULL;


}



int main(){
    HashTable<string, int> h1;
    h1.insert("Shlok", 1);
    h1.insert("Aman", 5);
    h1.insert("Shail", 70);
    h1.insert("Yash", 80);
    h1.insert("Prerit", 56);
    h1.insert("Varun", 100);
    h1.insert("Abhi", 10000);
    h1.insert("Tushar", 10000);
    h1.insert("Swapnil", 10000);
    h1.insert("Emmet", 10000);
    h1.insert("Hello", 10000);
    h1.insert("Sheldon", 10000);

    h1.print();
    
    h1.search("Yash");
    h1.search("Prerit");
    return 0;

}
