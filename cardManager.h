#ifndef CARDMANAGER_H
#define CARDMANAGER_H

#include "card.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class CardManager
{
private:
    vector<Card *> myclasses;
    string name;
    int count;
    int total_credit;
    double gpa;

public:
    CardManager()
    {
        count = 0;
        total_credit = 0;
    }
    ~CardManager();
    int getCount() { return count; }
    int getAllCredit() { return total_credit; }
    double getGpa() { return gpa; };

    void printAll();             // Print all cards
    void findCards(string name); // Search a card by name from all cards
    void loadCards(string filename);
    void saveCards(string filename);

    void sortMenu();

    void printRanking();

    int gToNum(string grade);

    void sortByCode()
    {
        sort(myclasses.begin(), myclasses.end(), Card::cmpCode);
    }
    void sortByName()
    {
        sort(myclasses.begin(), myclasses.end(), Card::cmpName);
    }

    void addCard();  // Add a card
    void editCard(); // Change grade of a card
    void setGPA();
};

#endif