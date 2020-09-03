#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main()
{

    string str1 = "Text";
    string str2 = "Text";
    char str3[] = "Text";
    char str4[] = "Text";
    if (str1 == str2)
    {
        cout << "Strign 1 and 2 Same" << endl;
    }
    else
    {
        cout << "String 1 and 2 are not  the Same" << endl;
    }
    // if (str3 == str4)(Wrong Code)
    // {
    //     cout << "Strign 3 and 4 Same" << endl;
    // }
    // else
    // {
    //     cout << "String 3 and 4 are not the Same" << endl;
    // }
    if (strcmp(str3, str4) == 0)
    {
        cout << "Strign 3 and 4 Same" << endl;
    }
    else
    {
        cout << "String 3 and 4 are not the Same" << endl;
    }

    cout << str1.length() << endl;           //Returns len of the string
    cout << str1[str1.length() - 1] << endl; //because of no negative indexing

    //  Use of strlen() can be avoided by:
    int temp = str1.length();
    for (int i = 0; i < temp; i++)
    {
        cout << str1[i];
    }
    for (int i = 0; str1[i]; i++)
    {
        cout << str1[i];
    }
    cout << endl;
    cout << __gcd(2, 8) << endl;
    int a = 10;
    if (a < 20 and a > 5)
        cout << "Yes" << endl;

    // math function
    cout << max(5, 10) << endl;
    cout << min(5, 10) << endl;
    cout << sqrt(64) << endl;
    cout << round(2.6) << endl; //closest number
    cout << cbrt(2.6) << endl;  //cube root
    cout << ceil(2.6) << endl;  //heighest number
    cout << floor(2) << endl;   //lower number
    cout << pow(2, 2) << endl;
    cout << log(2) << endl;
    cout << exp(2) << endl; // eraise to x
    // https://www.w3schools.com/cpp/cpp_math.asp

    // converting string to integers
    const string no = "42";
    int num1 = stoi(no);
    cout << num1 << endl;
    string newString = to_string(num1);
    cout << newString << endl;

    //Stack
    stack<int> s;
    s.push(10);
    cout << "top of the stack" << s.top() << endl;
    cout << "is the stack empty " << s.empty() << endl;
    s.pop();
    cout << "is the stack empty " << s.empty() << endl;

    cout << "top of the stack" << s.top() << endl;
    // https://www.geeksforgeeks.org/stack-in-cpp-stl/
}