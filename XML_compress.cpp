#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <fstream>
using namespace std;

vector<int> encoding(string s)
{
    unordered_map<string, int> table;   //make a table of a string key and a int value
    for (int i = 0; i <= 255; i++)
    {
        string cha = "";
        cha += char(i);     //every iteration char function will return a char that the ascii has
        table[cha] = i;   //for ex (A,65)
    }

    string current = "", next = "";
    current += s[0];   //the current to be the first character
    int code = 256;
    vector<int>output;    //make a vector to store the codes in it
    for (unsigned int i = 0; i < s.length(); i++)
    {
        if (i != s.length() - 1)
            next += s[i + 1];   //update next doesn't depend on the state so it is updated every iteration
        if (table.find(current + next) != table.end())    //if current+next is found in the table
        {
            current = current + next;    //in case of finding we doesn't make anything to the output or the table, but current=current+next
        }
        else   //if current+next isn't found
        {
            output.push_back(table[current]);  //output the current
            table[current + next] = code;   //put the current+next in the table
            code++;
            current = next;   //in case of not founding current = next
        }
        next = "";
    }
    output.push_back(table[current]);
    return output;
}
//The function that will decode and has an output string that will be printed in the cosnsole
string decoding(vector<int>code)
{
    string output = "";
    unordered_map<int, string> table;   //make a table of int key and a string value
    for (int i = 0; i <= 255; i++)
    {
        string cha = "";
        cha += char(i);  //every iteration char function will return a char that the ascii has
        table[i] = cha;   //for ex the key 65 will have A
    }
    int pre = code[0];   //pre will be the first element in the vector for ex 66
    int	neww;
    string s = table[pre];  //first element will be in the out without reffering to the table
    string a = "";
    a += s[0];   //s may be of two characters so a is the first one
    cout << s;
    int counter = 256;
    for (unsigned int i = 0; i < code.size() - 1; i++)
    {
        neww = code[i + 1];   //update new every iteration to be one element of the encoded vector
        if (table.find(neww) == table.end())   //if not founding the element in the table
        {
            s = table[pre];   //Not founding then s is to be twice the previous
            s = s + a;
        }
        else {
            s = table[neww];  //if founding the element in the table store is s the string thar refer to that element
        }
        output += s;  //output is the total string to be return
        a = "";
        a += s[0];
        table[counter] = table[pre] + a;  //every iteration we put the previous and the first one of current in the table
        counter++;
        pre = neww;  //every iteration we need to update the previous
    }
    return output;
}
