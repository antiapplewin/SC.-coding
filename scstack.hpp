//#include <iostream>
//#include <string>
//using namespace std;
//int q[101][10001], qcnt = 0, qsize[101];
//string qname[101];
//stack
//made by peterkim922
//used vector, string mainly
#include <vector>
#include <iostream>
#include <string>
using namespace std;
vector<int>s[100];
string sname[100];
int scnt = 0, ssize[100] = { 0 };
void make_s(string str)
{
    if (scnt >= 100)
    {
        cout << "Too many stacks";
        return;
    }
    if (str == "")
    {
        cout << "Invalid stack name: empty string";
    }
    sname[scnt] = str;
    scnt++;
}
int size_s(string str)
{
    int ind = -1;
    for (int i = 0; i <= scnt - 1; i++)
    {
        if (sname[i] == str)
        {
            ind = i;
        }
    }
    if (ind == -1)
    {
        cout << "Stack isn't declared";
        return -1;
    }
    return ssize[ind];
}
void push_s(string str, int v)
{
    int ind = -1;
    for (int i = 0; i <= scnt - 1; i++)
    {
        if (sname[i] == str)
        {
            ind = i;
        }
    }
    if (ind == -1)
    {
        cout << "Stack isn't declared";
        return;
    }
    s[ind].push_back(v);
    ssize[ind]++;
}
void pop_s(string str)
{
    int ind = -1;
    for (int i = 0; i <= scnt - 1; i++)
    {
        if (sname[i] == str)
        {
            ind = i;
        }
    }
    if (ind == -1)
    {
        cout << "Stack isn't declared";
        return;
    }
    else
    {
        if (!(ssize[ind] == 0))
            s[ind].pop_back(), ssize[ind]--;
        else
        {
            cout << "No Element is in stack";
        }
    }
}
void eprint_s(string str)
{
    int ind = -1;
    for (int i = 0; i <= scnt - 1; i++)
    {
        if (sname[i] == str)
        {
            ind = i;
        }
    }
    if (ind == -1)
    {
        cout << "Stack isn't declared";
        return;
    }
    while (!s[ind].empty())
    {
        cout << s[ind].back() << " ";
        s[ind].pop_back();
    }
    ssize[ind] = 0;
    cout << endl;
}
void sprint_s(string str)
{
    int ind = -1;
    vector<int>t;
    for (int i = 0; i <= scnt - 1; i++)
    {
        if (sname[i] == str)
        {
            ind = i;
        }
    }
    if (ind == -1)
    {
        cout << "Stack isn't declared";
        return;
    }
    while (!s[ind].empty())
    {
        cout << s[ind].back() << " ";
        t.push_back(s[ind].back());
        s[ind].pop_back();
    }
    for (int i = 1; i <= ssize[ind]; i++)
    {
        s[ind].push_back(t.back());
        t.pop_back();
    }
    cout << endl;
}
void clear_s(string str)
{
    int ind = -1;
    for (int i = 0; i <= scnt - 1; i++)
    {
        if (sname[i] == str)
        {
            ind = i;
        }
    }
    if (ind == -1)
    {
        cout << "Stack isn't declared";
        return;
    }
    while (!s[ind].empty())
    {
        s[ind].pop_back();
    }
    ssize[ind] = 0;
    return;
}
int top_s(string str)
{
    int ind = -1;
    for (int i = 0; i <= scnt - 1; i++)
    {
        if (sname[i] == str)
        {
            ind = i;
        }
    }
    if (ind == -1)
    {
        cout << "Stack isn't declared:returned true";
        return 1;
    }
    if (ssize[ind] == 0)
    {
        cout << "Fatal Error:Stack is Empty!; returned -1";
        return -1;
    }
    else
        return s[ind].back();
}
bool empty_s(string str)
{
    int ind = -1;
    for (int i = 0; i <= scnt - 1; i++)
    {
        if (sname[i] == str)
        {
            ind = i;
        }
    }
    if (ind == -1)
    {
        cout << "Stack isn't declared:returned true";
        return 1;
    }
    if (ssize[ind] == 0)
    {
        return true;
    }
    return false;
}
// int main()
// {
//   make_s("s");
//   push_s("s", 3);
//   push_s("s", 4);
//   push_s("s", 5);
//   cout << top_s("s");
//   make_s("p");
//   push_s("p", 8);
//   push_s("p", 9);
//   push_s("s", 6);
//   push_s("s", 7);
//   pop_s("s");
//   pop_s("s");
//   sprint_s("s");
//   if (!empty_s("s") && !empty_s("p"))
//   {
//     cout << "YEAH";
//   }
//   clear_s("p");
//   if (empty_s("p"))
//   {
//     cout << "YEAH";
//   }
// }//test code