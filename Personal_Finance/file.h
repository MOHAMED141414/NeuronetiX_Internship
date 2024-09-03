#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

#include<string>
#include<vector>
#include<map>
using namespace std;
struct Trans
{
    string descrbtion;
    string category;
    double amount;
};


void Input_Transaction(vector<Trans>&trans);
void viewTransactions(vector<Trans>& trans);
void viewSummary(vector<Trans>& trans);
void getInsights(vector<Trans>& trans);
bool compareByAmount(const Trans& a, const Trans& b);



#endif // FILE_H_INCLUDED
