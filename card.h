#ifndef CARD_H
#define CARD_H

#include <iostream>
using namespace std;

class Card
{
private:
    string code;
    string name;
    int credit;
    string grade;
    double score;

public:
    Card(string code, string name, int credit);
    Card(string code, string name, int credit, string grade);
    Card(Card *card, string grade);
    ~Card(){};
    void setGrade(string newgrade) { grade = newgrade; }
    string getCode() { return code; };
    string getName() { return name; };
    double getScore() { return score; };
    int getCredit() { return credit; };
    string getGrade() { return grade; };
    string toString();
    string toStringShort();

    static bool cmpCode(Card *c1, Card *c2)
    {
        return (c1->getCode() < c2->getCode());
    }

    static bool cmpName(Card *c1, Card *c2)
    {
        return (c1->getName() < c2->getName());
    }

    static bool cmpCredit(Card *c1, Card *c2)
    {
        return (c1->getCredit() < c2->getCredit());
    }

    static bool cmpScore(Card *c1, Card *c2)
    {
        return (c1->getScore() > c2->getScore());
    }

    static bool cmpGrade(Card *c1, Card *c2)
    {
        return (c1->getGrade() < c2->getGrade());
    }
};
#endif