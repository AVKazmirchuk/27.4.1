#pragma once



class Branch
{
private:
    static int nesting;
    const int numberOfChild;
    Branch* parent;
    Branch** child;

    std::string AlfName{};
public:
    Branch(const int inNumberOfChild);

    ~Branch();

    int getNumberOfChild() const;

    Branch* getChildByIndex(int idx);

    int numberOfNeighbors();

    void setName(std::string& name);

    std::string& getName();
};

int Branch::nesting = 2;

class Tree
{
private:
    const int numberOfBranches;
    Branch** branches;
public:
    Tree(const int inNumberOfBranches, const int childMin, const int childMax);

    ~Tree();

    int getNumberOfBranches() const;

    Branch* getBranchesByIndex(int idx);
};



class Forest
{
private:
    const int numberOfTrees;
    Tree** trees;
public:
    Forest(const int InNumberOfTrees, const int branchesMin, const int branchesMax,
           const int childMin, const int childMax);

    ~Forest();

    int getNumberOfTrees() const;

    Tree* getTreeByIndex(int idx);

    Branch* search();
};