#include "card.h"
#include <sstream>
#include <map>

map<string, double> gradescore = {
    {"A+", 4.5}, {"A0", 4.0}, {"B+", 3.5}, {"B0", 3.0}, {"C+", 2.5}, {"C0", 2.0}, {"D+", 1.5}, {"D0", 1.0}, {"F", 0}};

Card::Card(string code, string name, int credit)
{
    this->code = code;
    this->name = name;
    this->credit = credit;
}

Card::Card(string code, string name, int credit, string grade)
{
    this->code = code;
    this->name = name;
    this->credit = credit;
    this->grade = grade;
}

Card::Card(Card *card, string grade)
{
    this->code = card->getCode();
    this->name = card->getName();
    this->credit = card->getCredit();
    this->grade = grade;
    this->score = gradescore[grade];
}

string Card::toString()
{
    stringstream sstm;
    sstm << code << " [" << credit << "]" << name << " " << grade << " " << score;
    return sstm.str();
}
string Card::toStringShort()
{
    stringstream sstm;
    sstm << code << " [" << credit << "]" << name;
    return sstm.str();
}
