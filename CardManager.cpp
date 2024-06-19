#include "cardManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

extern map<string, Card *> allclasses;

CardManager::~CardManager()
{
    vector<Card *>::iterator iter;
    for (iter = myclasses.begin(); iter != myclasses.end(); ++iter)
    {
        delete (*iter);
    }
}

void CardManager::printAll()
{
    for (int i = 0; i < myclasses.size(); i++)
    {
        cout << i + 1 << " | " << myclasses[i]->toString() << endl;
    }

    string gds[9] = {"A+", "A0", "B+", "B0", "C+", "C0", "D+", "D0", "F"};
    int gCount[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0}; // 0: A+ ~ 6: F
    int credit = 0;

    for (int i = 0; i < myclasses.size(); i++)
    {
        credit += myclasses[i]->getCredit();
        for (int j = 0; j < 9; j++)
        {
            if (myclasses[i]->getGrade() == gds[j])
            {
                gCount[j]++;
            }
        }
    }

    cout << "Total " << myclasses.size() << " classes, " << credit << " credit";
    for (int i = 0; i < 9; i++)
    {
        if (gCount[i] > 0)
        {
            cout << ", " << gds[i] << "(" << gCount[i] << ")";
        }
    }
    cout << "\n";
}

void CardManager::addCard()
{
    string code, grade;
    cout << ">> Enter class code > ";
    cin >> code;
    if (allclasses.count(code) > 0)
    {
        cout << allclasses[code]->toStringShort() << endl;
        cout << ">> Enter grade > ";
        cin >> grade;
        Card *new_card = new Card(allclasses[code], grade);
        myclasses.push_back(new_card);
        count++;
        total_credit += new_card->getCredit();
        setGPA();
    }
    else
    {
        cout << "No such class." << endl;
    }
}

void CardManager::editCard()
{
    int no;
    string new_grade;
    cout << ">> Enter a Card number > ";
    cin >> no;
    cout << myclasses[no - 1]->toString() << endl;
    cout << ">> Enter new grade > ";
    cin >> new_grade;
    myclasses[no - 1]->setGrade(new_grade);
    setGPA();
    cout << "Grade changed." << endl;
}

void CardManager::loadCards(string filename)
{
    string line, code, grade;
    int count = 0;
    ifstream file(filename);
    while (!file.eof())
    {
        if (file.eof())
            break;
        file >> code >> grade;
        Card *new_card = new Card(allclasses[code], grade);
        myclasses.push_back(new_card);
        count++;
        total_credit += new_card->getCredit();
    }
    file.close();
    setGPA();
    cout << count << " classes are loaded.\n";
}

void CardManager::saveCards(string filename)
{
    ofstream file(filename);
    for (const auto &card : myclasses)
    {
        file << card->getCode() << " " << card->getGrade() << endl;
    }
    file.close();
    cout << "Data saved to " << filename << ".\n";
}

void CardManager::findCards(string name)
{
    int found = 0;
    cout << "Searching keyword: " << name << endl;
    for (int i = 0; i < myclasses.size(); i++)
    {
        if (myclasses[i]->getName().find(name) != string::npos)
        {
            found++;
            cout << i + 1 << " | " << myclasses[i]->toString() << endl;
        }
    }
    cout << count << " classes found.\n";
}

void CardManager::setGPA()
{
    double totalS = 0.0;
    int totalC = 0;

    for (const auto &card : myclasses)
    {
        totalS += card->getScore() * card->getCredit();
        totalC += card->getCredit();
    }

    if (totalC > 0)
    {
        gpa = totalS / totalC;
    }
    else
    {
        gpa = 0.0;
    }
}

void CardManager::sortMenu()
{
    string cName[2] = {"code", "name"};
    int x;
    cout << ">> select sorting criteria (1 code, 2 name) > ";
    cin >> x;
    if (x < 1 || x > 2)
    {
        cout << "Wrong number." << endl;
        return;
    }
    (x == 1) ? sortByCode() : sortByName();

    cout << "Sorted by the " << cName[x - 1] << endl;
}

void CardManager::printRanking()
{
    string in;
    int n;
    int x = 0; // num of ranked class
    string gds[9] = {"A+", "A0", "B+", "B0", "C+", "C0", "D+", "D0", "F"};
    cout << "Enter a grade? > ";
    cin >> in;
    n = gToNum(in);
    for (int i = 0; i < myclasses.size(); i++)
    {
        if (gToNum(myclasses[i]->getGrade()) <= n)
        {
            cout << x++ << " | " << myclasses[i]->toString() << endl;
        }
    }
}

int CardManager::gToNum(string grade)
{
    string gds[9] = {"A+", "A0", "B+", "B0", "C+", "C0", "D+", "D0", "F"};
    for (int i = 0; i < 9; i++)
    {
        if (gds[i] == grade)
        {
            return i;
        }
    }
    return 0;
}