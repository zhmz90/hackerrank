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
    void print_list(){
        Node* tmp = head;
         while (tmp != NULL) {
            cout<<tmp->value<<" ";
            tmp = tmp->next;
        }        
        cout<<endl;
    }
    void mv_head(Node* nd){
        cout<<"before mv_head\n";
        print_list();
        if (nd->prev == NULL)
            // node is the head
            return;

        // delete node D -->
        nd->prev->next = nd->next;

        if (nd->next != NULL){
            // D <--
            nd->next->prev = nd->prev;
        }
        //else if(nd->next == NULL){
        //    nd->prev->next = NULL;
        //}

        Node* h = head;
        //head = nd;
        head->prev = nd;
        nd->next   = head;
        nd->prev   = NULL;
        head = nd;
        cout<<"after mv_head\n";
        print_list();
    }

    virtual int get(int key) {
        Node* n = head;
        
        if (mp.size()>0){
            map<int,Node*>::iterator itr = mp.begin();
            while (itr != mp.end()){
                if(itr->first == key){
                    mv_head(mp[key]);
                    return mp[key]->value;
                }
                itr++;
            }
        }
        return -1;
    }
    void update_end(Node* nd) {
        tail->prev->next = nd;
        nd->prev = tail->prev;
    }
    void add_end(Node* nd) {
        tail->next = nd;
        nd->prev = tail;
    }

    virtual void set(int key, int value) {
        //print_list();

        Node* nd = new Node(key,value);
       
        if (mp.size() == 0){
            mp[key] =  nd;
            head = nd;
            tail = nd;
            return;
        }

        map<int,Node*>::iterator itr = mp.begin();
        while (itr != mp.end()) {
            if (itr->first == key){
                mp[key] = nd;
                /*
                if (mp.size()<cp){
                    // add nd the most recently used key
                    mv_head(nd);
                }
                else {
                    // add the least recently and delete origin node
                    tail->prev->next = nd;
                    nd->prev = tail->prev;
                    tail = nd;
                }
                */
                return;
            }
            itr++;
        }

        mp[key] = nd;
        if (mp.size() <= cp){
            // add new node  to head
            cout<<"<=cp\n";
            nd->next = head;
            head->prev = nd;
            head = nd;
        }
        else {
            Node *tmp = tail;
            //delete tail;
            tail->prev->next = nd;
            nd->prev = tail->prev;
            tail = nd;
            mp.erase(tmp->key);
        }
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
        else if (command == "print")
            l.print_list();
    }

    return 0;
}
