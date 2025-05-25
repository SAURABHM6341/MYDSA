#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unordered_map<string,int>m;    
    //insertion 

    //method 1

    pair<string,int>p = make_pair("fish",4);

    m.insert(p);

    //method 2
    pair<string,int>p1("cat",0);
    //method 3
    m["dog"] = 1;

    //search
    cout<<m["dog"];
    cout<<"\n";
    cout<<m.at("dog");
    cout<<"\n";
    // cout<<m.at("babbbar");//it will throw error
    cout<<m["babbbar"];//it will not throw error because by acessing this if entry doesn't exist then it will amke a entry and map to 0 by default;
    cout<<"\n";
    cout<<m.size()<<"\n";

    cout<<m.count("saurabh");//it will return whether a entry is present or not (true(1) or false(0))
    m.erase("cat");
    cout<<"\n";
    //for (auto i :m)
    //{
    //  cout<<i.first<<"="<<i.second;
    //}

    //making an iterator
    unordered_map<string,int> :: iterator it = m.begin();
    while (it!=m.end())
    {
        cout<<it->first<<" = "<<it->second<<endl;
        it++;
    }
    //Note: 
    /*
    In unordered map thing print in random order but in orderred map or simple map it will print just like in order you inserted 
    */
    
    
    return 0;
};
