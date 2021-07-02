#include <iostream>
#include "../include/header.h"

//-------Class Branch--------

Branch::Branch(const int inNumberOfChild) :
    numberOfChild{ inNumberOfChild }
{
    child = new Branch * [numberOfChild];
    for (int i{}; i < numberOfChild; ++i)
    {
        child[i] = new Branch(0);
        child[i]->parent = this;
    }
}

Branch::~Branch()
{
    for (int i{}; i < numberOfChild; ++i)
        delete child[i];

    delete child;
}

int Branch::getNumberOfChild() const { return numberOfChild; }

Branch* Branch::getChildByIndex(int idx) { return child[idx]; }

int Branch::numberOfNeighbors()
{
    int numberOfNeighbors{};

    for (int i{}; i < numberOfChild; ++i)
        if (!child[i]->getName().empty()) ++numberOfNeighbors;

    if (!getName().empty()) ++numberOfNeighbors;

    return --numberOfNeighbors;
}

void Branch::setName(std::string& name) { AlfName = name; }

std::string& Branch::getName() { return AlfName; }

//-------Class Tree----------

Tree::Tree(const int inNumberOfBranches, const int childMin, const int childMax) :
        numberOfBranches{ inNumberOfBranches }
{
    branches = new Branch * [numberOfBranches];
    for (int i{}; i < numberOfBranches; ++i)
        branches[i] = new Branch(rand() % (childMax - childMin + 1) + childMin);
}

Tree::~Tree()
{
    for (int i{}; i < numberOfBranches; ++i)
        delete branches[i];

    delete branches;
}

int Tree::getNumberOfBranches() const { return numberOfBranches; }

Branch* Tree::getBranchesByIndex(int idx) { return branches[idx]; }

//-------Class Forest--------

Forest::Forest(const int InNumberOfTrees, const int branchesMin, const int branchesMax,
               const int childMin, const int childMax) : numberOfTrees{ InNumberOfTrees }
{
    trees = new Tree * [numberOfTrees];
    for (int i{}; i < numberOfTrees; ++i)
        trees[i] = new Tree(rand() % (branchesMax - branchesMin + 1) + branchesMin,
                            childMin, childMax);
}

Forest::~Forest()
{
    for (int i{}; i < numberOfTrees; ++i)
        delete trees[i];

    delete trees;
}

int Forest::getNumberOfTrees() const { return numberOfTrees; }

Tree* Forest::getTreeByIndex(int idx) { return trees[idx]; }

Branch* Forest::search()
{
    std::cout << "\nName: ";
    std::string name;
    std::cin >> name;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    //Поиск во всех домиках

    for (int k{}; k < getNumberOfTrees(); ++k)
    {
        for (int j{}; j < getTreeByIndex(k)->getNumberOfBranches(); ++j)
        {
            if (name == getTreeByIndex(k)->getBranchesByIndex(j)->getName())
                return getTreeByIndex(k)->getBranchesByIndex(j);

            for (int i{}; i < getTreeByIndex(k)->getBranchesByIndex(j)->getNumberOfChild(); ++i)
            {
                if (name == getTreeByIndex(k)->getBranchesByIndex(j)->getChildByIndex(i)->getName())
                    return getTreeByIndex(k)->getBranchesByIndex(j);
            }
        }
    }

    return nullptr;
}



