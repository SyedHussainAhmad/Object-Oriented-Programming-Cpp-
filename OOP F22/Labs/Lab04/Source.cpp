#include<iostream>
#include"String.h"
using namespace std;

int main()
{
    String s = "Thi-s, a , sample, str-ing.";
    String s1 = "- This, a , sample, str-ing.";
    while (!s.isEmpty())
    {
        String token = s.tokenzie(" ,.-");
        token.display();
        cout << '\n';
    }

   /* String s = "Hello! How are you? Me? Me Fine?";
    s.reverseWords();
    s.display();*/

    //String newCharSet = "qwertuiopasdfghjklzxcvbnm";
    //String s = "ok, what";
    //s.changeToNewCharSet(newCharSet);
    //s.display();
    cout << endl;
    return 0;
}