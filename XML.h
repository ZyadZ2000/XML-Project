#pragma once
#include <string>
#include <iostream>
#include <stack>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <cstdlib>
using namespace std;


string XML_Format(string str);
string XML_TO_JSON(string str);
string XML_Consistency(string input);
vector<int> encoding(string s);
string decoding(vector<int>code);

class Node
{
public:
    string key;
    string value;
    vector<Node*> children;
    friend class Tree;
    void setvalue(string v);
};

class Tree {
public:
    Node* m_root;
    void setroot(Node* t);
    void addNode(Node* node, Node* parent);
    string format(int depth , Node* parent );
    string XMLToJson(int level, Node* parent );

};
Tree Parsing(string g);
string read(string path);
Tree network(string g);
string visual(string r);
Tree parse(string g);
