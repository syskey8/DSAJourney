#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char str[] = {'a', 'b', 'c'}; // normal array
    cout << str << endl;          // abcP?@

    /*The strange characters "P␦@" are being printed because the first character array, str, is not a properly terminated C-style string.
    The cout << str statement expects a null-terminated character array.
    When a character array is not null-terminated, cout will keep reading and printing characters from adjacent memory locations until it finds a null character (\0) by chance.
    The characters "P␦@" are just whatever happens to be in memory immediately after your str array.
    */

    char str1[] = {'a', 'b', 'c', '\0'}; // btw each char takes 1B of storage even \0
    cout << str1 << endl;                // abc
    cout << strlen(str1) << endl;

    char str2[] = "hello";   // string literals
    cout << str2[2] << endl; // constant pointers, output : l
    cout << str2[5] << endl; // output:  , there will be a blank output cuz of the null character
    cout << str2[7] << endl; // output:  , there will be a blank output cuz of the null character

    char str3[3]; // while creating a blank character array we have to define some space with it, unlike for normal arrays we can create blank arrays wihtout mentioning size for them
    cout << "Enter char arrary: " << endl;
    cin >> str3;
    cout << "output: " << str3 << endl; // if input hello then output hello, if input hello world then output hello

    // for this we use cin.geline(str, len, delim?)
    char str4[100];
    cout << "Enter char arrary: " << endl;
    cin.getline(str4, 100);
    cout << "output : " << str4 << endl; // will give entire hello world output as long the input is in the limit of the string size

    char str5[100];
    cout << "Enter char arrary: " << endl;
    cin.getline(str5, 100, '$');         // added a delimiter, -> means if that character is entered the input before that willl only be considered
    cout << "output : " << str5 << endl; // example input: hello worl$d from here, output: hello worl

    char str6[12];
    cout << "enter char array: ";
    cin.getline(str6, 12);
    for (char ch : str6)
    {
        cout << ch << " ";
    }
    cout << endl;

    char str7[] = "apna college";
    int len = 0;

    for (int i = 0; i != strlen(str7); i++)
    {
        len++;
    }

    cout << "length : " << len << endl;

    string str8 = "Hello WOrld";
    cout << str8 << endl;
    str8 = "test";
    cout << str8 << endl;

    string str9 = "apna";
    string str10 = "college";
    string str11 = str10 + str9;  // concatenation
    cout << str9 + str10 << endl; // apancollege

    str9 = "test";
    str10 = "test";
    cout << (str10 == str9) << endl; // 1

    cout << (str8 < str7) << endl; // lexicographically returns 0 or 1 (alphabetically)

    cout << str10.length() << endl;

    /*
    string str;

    cin >> str; // if we input apna college
    cout << str << endl; // we will only get apna in output not college

    // for that we need to use getline



    */

    // we can use a normal for loop to print all the characters or a for each loop

    return 0;
}