#include <iostream>
#include "../include/header.h"

void Home::setName(std::string& name) { AlfName = name; }

std::string& Home::getName() { return AlfName; }



Normal::Normal() { home = new Home; }

Normal::~Normal() { delete home; }

Home* Normal::getHome() { return home; }



Big::Big(int const inNumberOfNormals) :
        numberOfNormals{ inNumberOfNormals }
{
    normals = new Normal * [numberOfNormals];
    for (int i{}; i < numberOfNormals; ++i)
        normals[i] = new Normal;

    home = new Home;
}

Big::~Big()
{
    for (int i{}; i < numberOfNormals; ++i)
        delete normals[i];

    delete normals;
}

int Big::getNumberOfNormals() const { return numberOfNormals; }

Normal* Big::getNormalByIndex(int idx) { return normals[idx]; }

Home* Big::getHome() { return home; }

int Big::numberOfNeighbors()
{
    int numberOfNeighbors{};

    for (int i{}; i < numberOfNormals; ++i)
        if (!normals[i]->getHome()->getName().empty()) ++numberOfNeighbors;

    if (!getHome()->getName().empty()) ++numberOfNeighbors;

    return --numberOfNeighbors;
}


Tree::Tree(const int inNumberOfBigs, const int normalMin, const int normalMax) :
        numberOfBigs{ inNumberOfBigs }
{
    bigs = new Big * [numberOfBigs];
    for (int i{}; i < numberOfBigs; ++i)
        bigs[i] = new Big(rand() % (normalMax - normalMin + 1) + normalMin);
}

Tree::~Tree()
{
    for (int i{}; i < numberOfBigs; ++i)
        delete bigs[i];

    delete bigs;
}

int Tree::getNumberOfBigs() const { return numberOfBigs; }

Big* Tree::getBigByIndex(int idx) { return bigs[idx]; }



Forest::Forest(const int InNumberOfTrees, const int bigsMin, const int bigsMax,
               const int normalMin, const int normalMax) : numberOfTrees{ InNumberOfTrees }
{
    trees = new Tree * [numberOfTrees];
    for (int i{}; i < numberOfTrees; ++i)
        trees[i] = new Tree(rand() % (bigsMax - bigsMin + 1) + bigsMin,
                            normalMin, normalMax);
}

Forest::~Forest()
{
    for (int i{}; i < numberOfTrees; ++i)
        delete trees[i];

    delete trees;
}

int Forest::getNumberOfTrees() const { return numberOfTrees; }

Tree* Forest::getTreeByIndex(int idx) { return trees[idx]; }

Big* Forest::search()
{
    std::cout << "\nName: ";
    std::string name;
    std::cin >> name;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    //Поиск во всех домиках

    for (int k{}; k < getNumberOfTrees(); ++k)
    {
        for (int j{}; j < getTreeByIndex(k)->getNumberOfBigs(); ++j)
        {
            if (name == getTreeByIndex(k)->getBigByIndex(j)->getHome()->getName())
                return getTreeByIndex(k)->getBigByIndex(j);

            for (int i{}; i < getTreeByIndex(k)->getBigByIndex(j)->getNumberOfNormals(); ++i)
            {
                if (name == getTreeByIndex(k)->getBigByIndex(j)->getNormalByIndex(i)->getHome()->getName())
                    return getTreeByIndex(k)->getBigByIndex(j);
            }
        }
    }

    return nullptr;
}



