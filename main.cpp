#include <iostream>
#include <ctime>

#include "../include/header.h"

void input(Forest* forest)
{
    std::string name;

    //Дерево, большая ветвь, средняя ветвь

    std::cout << 'T' << " B" << " N" << '\n';

    for (int k{}; k < forest->getNumberOfTrees(); ++k)
        for (int j{}; j < forest->getTreeByIndex(k)->getNumberOfBigs(); ++j)
        {
            std::cout << k << ' ' << j << "  : ";
            std::cin >> name;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (name != "None") forest->getTreeByIndex(k)->getBigByIndex(j)->getHome()->setName(name);

            for (int i{}; i < forest->getTreeByIndex(k)->getBigByIndex(j)->getNumberOfNormals(); ++i)
            {
                std::cout << k << ' ' << j << ' ' << i << ": ";
                std::cin >> name;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                if (name != "None") forest->getTreeByIndex(k)->getBigByIndex(j)->getNormalByIndex(i)->getHome()->setName(name);
            }
        }
}

void output(Forest* forest)
{
    std::cout << "\n\n";

    //Дерево, большая ветвь, средняя ветвь

    std::cout << 'T' << " B" << " N" << '\n';

    for (int k{}; k < forest->getNumberOfTrees(); ++k)
        for (int j{}; j < forest->getTreeByIndex(k)->getNumberOfBigs(); ++j)
        {
            std::cout << k << ' ' << j << "   " << forest->getTreeByIndex(k)->getBigByIndex(j)->getHome()->getName() << '\n';
            for (int i{}; i < forest->getTreeByIndex(k)->getBigByIndex(j)->getNumberOfNormals(); ++i)
            {
                std::cout << k << ' ' << j << ' ' << i << ' ' << forest->getTreeByIndex(k)->getBigByIndex(j)->getNormalByIndex(i)->getHome()->getName() << '\n';
            }
        }
}

int main()
{
    std::srand(std::time(nullptr));

    const int numberOfTrees = 5;
    const int bigsMin = 3, bigsMax = 5;
    const int normalMin = 2, normalMax = 3;

    Forest* forest = new Forest(numberOfTrees, bigsMin, bigsMax,
                                normalMin, normalMax);

    input(forest);
    output(forest);

    while (true)
    {
        if (Big* big = forest->search(); big != nullptr)
        {
            std::cout << "Elf found. Number of neighbors: " << big->numberOfNeighbors();

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