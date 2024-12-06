#include<iostream>
#include<string>
#include<stack>
using namespace std;

int find(const string &s, int open)
{
    if(s[open]!='[') return -1;
    stack <int> stk;
    for(int i=open; i<s.length(); i++)
    {
        if(s[i]=='[') stk.push(i);
        else if(s[i]==']') 
        {
            int last=stk.top();
            stk.pop();
            if(last==open) return i;
        }
    }
    return -1;
}

int main()
{
    string s;
    getline(cin,s);
    int open;
    cin>>open;
    int res=find(s, open);
    cout<<res<<endl;
    return 0;
}