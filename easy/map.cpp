#include <map>
#include <iostream>

using namespace std;

int main() {
    map<char,int> m;
    m['a'] = 1;
    
    for (map<char,int>::iterator it=m.begin(); it!=m.end();it++) {
        cout<<it->first<<"=>"<<it->second<<endl;
    }

    return 0;
}
