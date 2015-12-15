#include <iostream>
#include <map>

using namespace std;

struct Node {
    int first;
    int last;
    Node(int k, int v):first(k),last(v){};
};


int main2(){

    map<int,Node*>mp;

    Node n = Node(1,2);
    mp[1] = &n;

    cout<<mp[1]->first<<endl;
    cout<<mp[1]->last<<endl;
    return 0;
}

int main(){

    map<int,char> mp;
    mp[1] =  'a';
    mp[1] = 'b';

    map<int,char>::iterator itr = mp.begin();

    while (itr != mp.end()){
        cout<<itr->second<<endl;
        itr++;
    }

    return 0;
}

