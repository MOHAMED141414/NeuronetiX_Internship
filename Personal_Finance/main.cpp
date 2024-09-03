#include <bits/stdc++.h>
#include"file.h"
using namespace std;

int main()
{
  vector<Trans> trans;
    int choice;
    do
        {
    cout<<"Personal Finance Tracker"<<endl;
    cout<<"1. Input Transaction"<<endl;
    cout<<"2. View Transactions"<<endl;
    cout<<"3. View Summary"<<endl;
    cout<<"4. Get Insights"<<endl;
    cout<<"5. Exit"<<endl;
    cout<<"Choose an option: ";
    cin>>choice;
    switch(choice)
    {
    case 1:Input_Transaction(trans);
        break;
    case 2:viewTransactions(trans);
        break;
    case 3:viewSummary(trans);
        break;
    case 4:getInsights(trans);
        break;
    case 5:cout<<"Exiting the program. Goodbye!"<<endl;
        break;
    default:cout<<"Invalid choice. Please try again"<<endl;
    }
        }while(choice !=5);
    return 0;
}
