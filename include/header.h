#pragma once

class Home
{
private:
    std::string AlfName{};
public:
    void setName(std::string& name);

    std::string& getName();
};

//Средняя ветвь

class Normal
{
private:
    Home* home;
public:
    Normal();

    ~Normal();

    Home* getHome();
};

//Большая ветвь

class Big
{
private:
    const int numberOfNormals;
    Normal** normals;
    Home* home;
public:
    Big(int const inNumberOfNormals);

    ~Big();

    int getNumberOfNormals() const;

    Normal* getNormalByIndex(int idx);

    Home* getHome();

    int numberOfNeighbors();
};

class Tree
{
private:
    const int numberOfBigs;
    Big** bigs;
public:
    Tree(const int inNumberOfBigs, const int normalMin, const int normalMax);

    ~Tree();

    int getNumberOfBigs() const;

    Big* getBigByIndex(int idx);
};

class Forest
{
private:
    const int numberOfTrees;
    Tree** trees;
public:
    Forest(const int InNumberOfTrees, const int bigsMin, const int bigsMax,
           const int normalMin, const int normalMax);

    ~Forest();

    int getNumberOfTrees() const;

    Tree* getTreeByIndex(int idx);

    Big* search();
};