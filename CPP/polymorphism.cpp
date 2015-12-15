#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>

using namespace std;

struct Node{
    Node* next;
    Node* prev;
    int value;
    int key;
    Node(Node* p, Node* n, int k, int v):prev(p),next(n),key(k),value(v){};
    Node(int k, int v):prev(NULL),next(NULL),key(k),value(v){};
};


class Cache{
    
    protected:
    map<int,Node*>mp;
    int cp;
    Node* tail;
    Node* head;
    virtual void set(int, int)=0;
    virtual int get(int)=0;
};

class LRUCache: public Cache {
    public:
        LRUCache(int cap){
            cp = cap;
            head = NULL;
            tail = NULL;
        }
    void print_list(Node* head){
         while (head != NULL) {
            cout<<(head++)->value<<" ";
        }        
        cout<<endl;
    }
    virtual int get(int key) {
        Node* n = head;
        
        if (mp.size()>0){
            map<int,Node*>::iterator itr = mp.begin();
            while ((itr++) != mp.end()){
                if(itr->first == key){
                    return mp[key]->value;
                }
            }
        }
            
        return -1;
    }

    virtual void set(int key, int value) {
        Node* nd = new Node(key,value);
        mp[key] = nd;

        head = nd;
        tail = nd;
    }

};


int main() {
    int n,capacity,i;
    cin>>n>>capacity;
    LRUCache l(capacity);
    for (i=0;i<n;i++) {
        string command;   
        cin >> command;
        if (command == "get"){
            int key;
            cin>>key;
            cout<<l.get(key)<<endl;
        } 
        else if(command == "set"){
            int key,value;
            cin>>key>>value;
            l.set(key,value);
        }
    }
    
    return 0;
}

