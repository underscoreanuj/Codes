#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

class Person{
public:    
    string name;
    string parent;
    int birth;
    string death;
    string religion;
    string gender;
    
    vector<Person*> children;
    
    Person(string name, string parent, int birth, string death, string religion, string gender) {
        this->name = name;
        this->parent = parent;
        this->birth = birth;
        this->death = death;
        this->religion = religion;
        this->gender = gender;
        this->children = {};
    }
};

class SortByGenderAndAge{
public:
    bool operator()(const Person *p1, const Person * p2) {
        return ((p1->gender == "M" && p2->gender == "F") ||
                (p1->gender == p2->gender && p1->birth < p2->birth));
    }
};

Person* addChild(Person* root, Person* child) {
    if(root == NULL) {
        root = child;
        return root;
    }
    
    if(child->parent == root->name) {
        root->children.push_back(child);
        return root;
    }
    
    for(Person* c : root->children) {
        c = addChild(c, child);
    }
    
    return root;
}
    
void printFamily(Person* root) {
    if(root->death == "-" && root->religion != "Catholic") cout<<root->name<<"\n";
    
    // sort children
    sort(root->children.begin(), root->children.end(), SortByGenderAndAge());
    
    for(Person *c : root->children) {
        printFamily(c);
    }
}

int main()
{
    int n;
    cin >> n; cin.ignore();
    string name;
    string parent;
    int birth;
    string death;
    string religion;
    string gender;
    
    Person* root = NULL;
    
    for (int i = 0; i < n; i++) {
        cin >> name >> parent >> birth >> death >> religion >> gender; cin.ignore();

        Person *child = new Person(name, parent, birth, death, religion, gender);
        root = addChild(root, child);
    }
    
    printFamily(root);
    
}