#pragma once
#include "../import.h"
#include <vector>


std::string classString = "";

std::string getFullName(std::string lastName, std::string firstName)
{
    return firstName + " - " + lastName;
}

class MyClassA
{
public:
    MyClassA() {}
    MyClassA(MyClassA&& otherClassA) : ids_(otherClassA.ids_)
    {
        classString += "Move Constructor \n";
    }
    MyClassA(const MyClassA& otherClassA) : ids_(otherClassA.ids_)
    {
        classString += "Copy Constructor \n";
    }
    void addIds(const int& ids) {
        ids_.push_back(ids); 
    }

    void toString() { 
        for (auto i : ids_)
            classString += i + "\n"; 
    }

    MyClassA operator+(const MyClassA& other)
    {
        classString += "Add oprator \n";
        MyClassA newClassA;
        for (auto i : ids_)
            newClassA.addIds(i);
        for (auto i : other.ids_)
            newClassA.addIds(i);
        return newClassA;
    }
    MyClassA operator=(const MyClassA& other)
    {
        classString += "Assignment operator \n";
        ids_ = other.ids_;
        return *this;
    }
    std::vector<int> ids_;
};
std::string function_3_move_semantic() {
    // 3. Move Semantic
    // https://blog.invivoo.com/decouverte-du-cplusplus-et-stdmove/
    std::string toReturn = "";
    toReturn += "######### 3 Move Semantic ############\n\n";

    // && 
    std::string&& name = getFullName("Doe", "John"); // 
    toReturn +=  name + "\n";

    MyClassA myClassA;
    myClassA.addIds(1);
    myClassA.addIds(2);
    myClassA.addIds(3);
    myClassA.toString();
    MyClassA myNewClassACopy(myClassA);            // Constructeur par copie
    MyClassA myNewClassAMove(std::move(myClassA)); // Constructeur par déplacement
    MyClassA addA = myClassA + myNewClassACopy;
    // std::move permet de passer une référence de rvalue au lieu de la rvalue
    // et donc d'utiliser le constructeur par déplacement.;

    toReturn += classString;

    return toReturn;
}