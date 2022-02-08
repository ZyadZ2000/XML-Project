#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <stack>
using namespace std;

/*class Node
{
public:
    string key;
    string value;
    vector<Node*> children;
    friend class Tree;
    void setvalue(string v) {
        value = v;
    }
};*/

/*class Tree {
public:
    Node* m_root;
    void setroot(Node* t) {
        m_root = t;
    }
    void addNode(Node* node, Node* parent) {
        if (parent == nullptr)
        {
            parent = m_root;
        }
        parent->children.push_back(node);
    }

    string format(int depth = 0, Node* parent = nullptr)
    {
        if (parent == nullptr)
        {
            parent = m_root;
            depth = 0;
        }
        string output = "";
        for (int i = 0; i < parent->children.size(); ++i)
        {
            Node* node = parent->children[i];

            string indentation = "";

            // indentation value
            for (int i = 0; i < depth; ++i)
            {
                indentation += "    ";
            }

            // insert key open
            output += indentation + "<" + node->key + ">\n"; // <name>

            if (node->children.size() > 0)
            {
                output += format(depth + 1, node);
            }
            else
            {
                // insert value
                output += indentation + node->value + "\n"; // Nada
            }
            //close the key
            output += indentation + "</" + node->key + ">\n";// </name>
        }
        return output;
    }

    string XMLToJson(int level = 0, Node* parent = nullptr)
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

        for (int i = 0; i < parent->children.size(); ++i)
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
};*/

Tree network(string g) {
    Tree y;
    Node* root = new Node;
    y.setroot(root);
    Node* parent = root;
    int st = 0, ps = 0;
    int x = 0;
    string tag;
    while (g.find("<", ps) != string::npos) {
        if (st != string::npos) {
            st = g.find("<", ps);
            ps = g.find(">", st);
            tag = g.substr(st + 1, ps - st - 1);
        }
        if (tag == "id") {
             Node* c = new Node;
                st = g.find("<", ps);
                c->key = tag;
                c->value = g.substr(ps + 1, st - ps - 1);
                y.addNode(c, parent);
                if (x == 0) {
                    parent = c;
                    x++;
                }
            }
             if (tag == "/followers") {
                x = 0;
                parent = root;
    }
    }
    return y;

}

Tree parse(string g) {
    stack <Node*> stk;
    unsigned int h = g.find("<", 0), j;
    if (g.substr(h + 1, 1) == "?") {
        j = g.find(">", h);
        g.erase(h, j - h + 1);
    }
    string firsttag;
    unsigned int st = 0, ps;
    unsigned int o, v;
    st = g.find("<", st);
    ps = g.find(">", st);
    firsttag = g.substr(st + 1, ps - st - 1);
    Node* root = new Node;
    Node* node = new Node;
    node->key = firsttag;
    Tree  y;
    y.setroot(root);
    y.addNode(node, root);
    st = g.find("<", ps);
    ps = g.find(">", st);
    Node* parent = node;
    while (g.find("<", ps) != string::npos) {
        if (g.substr(st + 1, 1) != "/") {
            Node* newnode = new Node;
            newnode->key = g.substr(st + 1, ps - st - 1);
            st = g.find("<", ps);
            y.addNode(newnode, parent);
            if (st != string::npos) {
                newnode->value = g.substr(ps + 1, st - ps - 1);
                if (g.substr(st + 1, 1) != "/") {
                    stk.push(parent);
                    parent = newnode;

                }
            }
            ps = g.find(">", st);
        }
        if (g.substr(st + 1, 1) == "/") {
            st = g.find("<", ps);
            ps = g.find(">", st);
            if (st != string::npos) {
                if (g.substr(st + 1, 1) == "/") {
                    if (!stk.empty())
                    {
                        parent = stk.top();
                        stk.pop();
                    }

                }
            }
        }

    }
    return y;
}


string read() {
    string xml;
    string tmp;
    string filepath;
    cout << "enter file path" << endl;
    cin >> filepath;
    fstream file;
    file.open(filepath, ios::in);
    while (file >> xml)
    {
        for (int i = 0; i < xml.length(); i++)
        {
            tmp += xml[i];
        }
    }
    return  tmp;
}


string visual(string r)
{
   // string z = read();
    Tree  tr = network(r);
    string out = "digraph test {\n";
    for (int i = 0; i < tr.m_root->children.size(); i++) {
        for (int j = 0; j < tr.m_root->children[i]->children.size(); j++) {
            out += tr.m_root->children[i]->value + "->" + tr.m_root->children[i]->children[j]->value + '\n' ;
        }
    }
    out += "}";
    return out;
}
