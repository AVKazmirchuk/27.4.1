#include <iostream>
#include <ctime>

#include "../include/header.h"



void input(Forest* forest)
{
    std::string name;

    //Дерево, большая ветвь, средняя ветвь

    std::cout << 'T' << " B" << " N" << '\n';

    for (int k{}; k < forest->getNumberOfTrees(); ++k)
        for (int j{}; j < forest->getTreeByIndex(k)->getNumberOfBranches(); ++j)
        {
            std::cout << k << ' ' << j << "  : ";
            std::cin >> name;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (name != "None") forest->getTreeByIndex(k)->getBranchesByIndex(j)->setName(name);

            for (int i{}; i < forest->getTreeByIndex(k)->getBranchesByIndex(j)->getNumberOfChild(); ++i)
            {
                std::cout << k << ' ' << j << ' ' << i << ": ";
                std::cin >> name;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                if (name != "None") forest->getTreeByIndex(k)->getBranchesByIndex(j)->getChildByIndex(i)->setName(name);
            }
        }
}



void output(Forest* forest)
{
    std::cout << "\n\n";

    //Дерево, большая ветвь, средняя ветвь

    std::cout << 'T' << " B" << " N" << '\n';

    for (int k{}; k < forest->getNumberOfTrees(); ++k)
        for (int j{}; j < forest->getTreeByIndex(k)->getNumberOfBranches(); ++j)
        {
            std::cout << k << ' ' << j << "   " << forest->getTreeByIndex(k)->getBranchesByIndex(j)->getName() << '\n';
            for (int i{}; i < forest->getTreeByIndex(k)->getBranchesByIndex(j)->getNumberOfChild(); ++i)
            {
                std::cout << k << ' ' << j << ' ' << i << ' ' << forest->getTreeByIndex(k)->getBranchesByIndex(j)->getChildByIndex(i)->getName() << '\n';
            }
        }
}



int main()
{
    std::srand(static_cast<int>(std::time(nullptr)));

    const int numberOfTrees = 2;
    const int branchesMin = 1, branchesMax = 2;
    const int childMin = 1, childMax = 2;

    /*const int numberOfTrees = 5;
    const int branchesMin = 3, branchesMax = 5;
    const int childMin = 2, childMax = 3;*/

    Forest* forest = new Forest(numberOfTrees, branchesMin, branchesMax,
                                childMin, childMax);

    input(forest);
    output(forest);

    while (true)
    {
        if (Branch* branch = forest->search(); branch != nullptr)
        {
            std::cout << "Elf found. Number of neighbors: " << branch->numberOfNeighbors();

        }
        else std::cout << "Elf not found!";

        std::cout << "Continue - \"yes\"";
        std::string goOn;
        std::cin >> goOn;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (goOn != "yes") break;
    }

    delete forest;
}