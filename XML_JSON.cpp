#include"XML.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <stack>

using namespace std;

string Tree::XMLToJson(int level = 0, Node* parent = nullptr)
  {
      string ks;
      string sb = "{";
      string eb = "}";
      string r = "{";
      string u = "}";
      string output = "";
      if (parent == nullptr)
      {
          parent = m_root;
          level = 0;
      }

      for (unsigned long long i = 0; i < parent->children.size(); ++i)
      {
          Node* node = parent->children[i]; //creating poienters to children of the parent node
          string Spacing = "\t";
          for (int i = 0; i < level; ++i) // lvl1 4 spacing , lvl2 8 spacing ,...
          {
              Spacing += "\t";
          }

          output += Spacing + "\"" + node->key + "\": "; //"class":

          if (node->children.size() > 0)
          {
              if (node->children.size() > 1) {
                  Node* n = node->children[0];
                  Node* m = node->children[1];
                  if (n->key == m->key) {
                      sb = "[";
                      eb = "]";
                  }
              }
              output += XMLToJson(level + 1, node);
              //to know if this node is the last node in its level
              // from 119 to 127 each child
              if (i == parent->children.size() - 1)
              {
                  output += "\t"; // no action
              }
              else
              {
                  output += ",\n";
              }
          }
          else
          { // if it is leaf node
              if (i == parent->children.size() - 1)
              { // if last node in its level
                  output += "\"" + node->value +"\"";
              }
              else
              {
                  output += "\"" + node->value + "\""; //"1"
                  output += ",\n";
              }
          }
          ks = Spacing;
      }
          return "{\n" + output + "\n" + ks + "}";
  }



string XML_TO_JSON(string str){
    Tree tr = Parsing(str);
    return tr.XMLToJson();
}
