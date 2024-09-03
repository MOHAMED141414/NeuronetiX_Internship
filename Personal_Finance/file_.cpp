#include <bits/stdc++.h>
#include "file.h"
using namespace std;

// Function to input a new financial transaction
void Input_Transaction(vector<Trans>& trans)
{
    Trans t;
    cout << "Enter transaction description: ";
    cin.ignore(); // Ignore any newline characters left in the input buffer
    getline(cin, t.descrbtion); // Input the description of the transaction
    cout << "Enter transaction amount (positive for income, negative for expense): ";
    cin >> t.amount; // Input the amount (positive for income, negative for expenses)
    cout << "Enter category (e.g., Food, Entertainment, Bills): ";
    cin.ignore(); // Ignore any newline characters left in the input buffer
    getline(cin, t.category); // Input the category of the transaction (e.g., Food, Entertainment)
    trans.push_back(t); // Add the transaction to the list
    cout << "Transaction added successfully" << endl << endl; // Confirm the transaction was added
}

// Function to view all financial transactions
void viewTransactions(vector<Trans>& trans)
{
    if(trans.empty()) // Check if there are no transactions recorded
    {
        cout << "No transaction recorded." << endl;
        return; // Exit the function if there are no transactions
    }

    // Sort the transactions by amount
    vector<Trans>& sorttrans = trans;
    sort(sorttrans.begin(), sorttrans.end(), compareByAmount);

    // Display transactions in a tabular format
    cout << left << setw(15) << "Description" << setw(15) << "Amount" << setw(15) << "Category" << endl;
    cout << "-------------------------------------------------" << endl;
    for(const auto& t : sorttrans) // Loop through each transaction and display it
    {
        cout << left << setw(15) << t.descrbtion << setw(15) << t.amount << setw(15) << t.category << endl << endl;
    }
}

// Function to view a summary of financial transactions
void viewSummary(vector<Trans>& trans)
{
    double Income = 0;
    double Expense = 0;

    // Calculate total income and total expenses
    for (const auto& t : trans)
    {
        if (t.amount > 0)
        {
            Income += t.amount; // Add to income if amount is positive
        }
        else
        {
            Expense += t.amount; // Add to expenses if amount is negative
        }
    }

    double balance = Income + Expense; // Calculate the balance
    cout << endl;
    cout << "Total Income: " << Income << endl;
    cout << "Total Expenses: " << Expense << endl;
    cout << "Balance: " << balance << endl << endl; // Display the summary
}

// Function to get insights into spending by category
void getInsights(vector<Trans>& trans)
{
    if(trans.empty()) // Check if there are no transactions recorded
    {
        cout << "No transaction recorded." << endl;
        return; // Exit the function if there are no transactions
    }

    map<string, double> Category_Expenses; // Map to store expenses by category
    double TotalExpenses = 0;

    // Aggregate expenses by category
    for (const auto& t : trans)
    {
        if (t.amount < 0)
        {
            Category_Expenses[t.category] += t.amount; // Add to the appropriate category
            TotalExpenses += t.amount; // Update the total expenses
        }
    }

    cout << endl;
    cout << "Category Analysis" << endl;

    // Display the analysis of expenses by category
    for (const auto& t : Category_Expenses)
    {
        double percentage = (t.second / TotalExpenses) * 100; // Calculate the percentage of total expenses
        cout << t.first << ": " << t.second << " " << percentage << "%" << endl; // Display the category and its percentage of total expenses
    }
    cout << endl;
}

// Function to compare two transactions by amount (used for sorting)
bool compareByAmount(const Trans& a, const Trans& b)
{
    return a.amount < b.amount; // Return true if the amount of 'a' is less than 'b'
}
