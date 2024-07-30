#include <iostream>
#include <string>
using namespace std;
int q[101][10001], qcnt = 0, qsize[101];
string qname[101];
void make_q(string str)
{
    if (qcnt >= 100)
    {
        cout << "Too many queues";
        return;
    }
    if (str == "")
    {
        cout << "Invalid stack name: empty string";
    }
    qname[qcnt] = str;
    qcnt++;
}
int size_q(string str)
{
    int ind = -1;
    for (int i = 0; i <= qcnt - 1; i++)
    {
        if (qname[i] == str)
        {
            ind = i;
        }
    }
    if (ind == -1)
    {
        cout << "Queue isn't declared";
        return -1;
    }
    return qsize[ind];
}
void push_q(string str, int v)
{
    int ind = -1;
    for (int i = 0; i <= qcnt - 1; i++)
    {
        if (qname[i] == str)
        {
            ind = i;
        }
    }
    if (ind == -1)
    {
        cout << "Queue isn't declared";
        return;
    }
    q[ind][qsize[ind]] = v;
    qsize[ind]++;
}
void pop_q(string str)
{
    int ind = -1;
    for (int i = 0; i <= qcnt - 1; i++)
    {
        if (qname[i] == str)
        {
            ind = i;
        }
    }
    if (ind == -1)
    {
        cout << "Queue isn't declared";
        return;
    }
    else
    {
        if (!(qsize[ind] == 0))
        {
            q[ind][0] = 0;
            qsize[ind]--;
            for (int i = 1; i <= qsize[ind]; i++)
            {
                q[ind][i - 1] = q[ind][i];
            }
        }
        else
        {
            cout << "Fatal Error:Queue is Empty!";
        }
    }
}
void print_q(string str)
{
    int ind = -1;
    for (int i = 0; i <= qcnt - 1; i++)
    {
        if (qname[i] == str)
        {
            ind = i;
        }
    }
    if (ind == -1)
    {
        cout << "Queue isn't declared";
        return;
    }
    for (int i = 0; i <= qsize[ind] - 1; i++)
    {
        cout << q[ind][i] << " ";
    }
    cout << endl;
}
int front_q(string str)
{
    int ind = -1;
    for (int i = 0; i <= qcnt - 1; i++)
    {
        if (qname[i] == str)
        {
            ind = i;
        }
    }
    if (ind == -1)
    {
        cout << "Queue isn't declared, returned -1";
        return 0;
    }
    return q[ind][0];
}
bool empty_q(string str)
{
    int ind = -1;
    for (int i = 0; i <= qcnt - 1; i++)
    {
        if (qname[i] == str)
        {
            ind = i;
        }
    }
    if (ind == -1)
    {
        cout << "Queue isn't declared, returned true";
        return 1;
    }
    if (qsize[ind] == 0)
    {
        return 1;
    }
    return 0;
}
void clear_q(string str)
{
    int ind = -1;
    for (int i = 0; i <= qcnt - 1; i++)
    {
        if (qname[i] == str)
        {
            ind = i;
        }
    }
    if (ind == -1)
    {
        cout << "Queue isn't declared";
        return;
    }
    for (int i = 0; i <= qsize[ind] - 1; i++)
    {
        q[ind][i] = 0;
    }
    qsize[ind] = 0;
}
// int main()
// {
//   make_q("q");
//   push_q("q", 3);
//   push_q("q", 4);
//   push_q("q", 5);
//   cout << front_q("q") <<endl;
//   make_q("p");
//   push_q("p", 8);
//   push_q("p", 9);
//   push_q("q", 6);
//   push_q("q", 7);
//   pop_q("q");
//   print_q("q");
//   print_q("p");
//   if(!empty_q("q") && !empty_q("p"))
//   {
//     cout << "YEAH";
//   }
//   clear_q("q");
//   if(empty_q("q"))
//   {
//     cout << "YEAH";
//   }
//   return 0;
// }//test code