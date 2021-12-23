#include <string>
#include <iostream>
#include <stack>
#include"XML.h"
using namespace std;
template<class T>
bool find(stack<T> source, T value)
{
    while (!source.empty() && source.top() != value)
        source.pop();

    if (!source.empty())
        return true;

    return false;
}
string XML_Consistency(string input)
{
    string edited_corrected;
    string to_be_edited = input;
    string add_tag;
    string check;

    stack <string>xml_check;

   int begin_index;
   int end_index;
   int tag_len;
    int i_c;

    bool f;

    for (unsigned long long  i = 0; i < to_be_edited.length(); i++) {
        if (to_be_edited[i] == '<') {
            i++;
            if (to_be_edited[i] != '/') {
                begin_index = i;
                end_index=to_be_edited.find('>', begin_index) ;
                tag_len = end_index-begin_index;
                edited_corrected.push_back('<');
                add_tag = to_be_edited.substr(begin_index,tag_len);
                edited_corrected =edited_corrected+(add_tag);
                edited_corrected.push_back('>');
                xml_check.push(add_tag);
                i = end_index+1;
                while(to_be_edited[i] == char(10) || to_be_edited[i] ==' ' )i++;
                if (to_be_edited[i] != '<') {
                    i_c = to_be_edited.find('<', i );
                    if (to_be_edited[i_c + 2] != '/') {
                        int len = i_c  - i;
                        if(len==0){edited_corrected.append(to_be_edited.substr(i , 1));}
                        else { edited_corrected.append(to_be_edited.substr(i, len)); }
                        edited_corrected.push_back('<');
                        edited_corrected.push_back('/');
                        add_tag = xml_check.top();
                        edited_corrected = edited_corrected + (add_tag);
                        edited_corrected.push_back('>');
                        xml_check.pop();
                        i = i_c-1;
                    }
                }
                i--;
            }
            else if (to_be_edited[i] == '/') {
                i_c = to_be_edited.find('>', i);
                int len = i_c - i - 1;
                check = to_be_edited.substr(i + 1, len);
                f = find(xml_check,check);
                while (f) {
                    if (check != xml_check.top()) {
                        edited_corrected.push_back('<');
                        edited_corrected.push_back('/');
                        add_tag = xml_check.top();
                        edited_corrected = edited_corrected + (add_tag);
                        edited_corrected.push_back('>');
                        xml_check.pop();
                    }
                    else if (check == xml_check.top()) {
                        edited_corrected.push_back('<');
                        edited_corrected.push_back('/');
                        add_tag = xml_check.top();
                        edited_corrected = edited_corrected + (add_tag);
                        edited_corrected.push_back('>');
                        xml_check.pop();
                        f = false;
                    }
                    i = i_c;
                }
            }

        }

    }
    while (!xml_check.empty()) {
        edited_corrected.push_back('<');
        edited_corrected.push_back('/');
        add_tag = xml_check.top();
        edited_corrected = edited_corrected + (add_tag);
        edited_corrected.push_back('>');
        xml_check.pop();
    }
    return edited_corrected;
}
/*
int main()
{
 //   string s1 = "<users><user><id>1<name>Ahmed Ali</id><posts><post><body>Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.</body><topics><topic>economy</topic><topic>finance</topic></topics></post><post><body>Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.</body><topics><topic>solar_energy</topic></topics></post></posts><followers><follower><id>2</id></follower><follower><id>3</id></follower></followers></user><user><id>2</id><name>Yasser Ahmed</name><posts><post> ";
   // string z = XML_Consistency(s1);
   // cout << z;

    return 0;
}
*/

