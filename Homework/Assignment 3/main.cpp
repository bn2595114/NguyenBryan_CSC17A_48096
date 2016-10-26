/* 
 * File:   main.cpp
 * Author: Bryan
 *
 * Created on October 17, 2016, 11:25 AM
 */

#include <cstdlib>
#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
using namespace std;

#include "company.h"

//FILE NAME: hello.txt 
//FILE NAME: hello1.txt

int count(char*);
char* rev(char*);
int wCount(char*);
int vow(char*);
int cons(char*);
int lett(char*);
void menu();
bool arrayToFile(fstream&, int*, int);
bool fileToArray(fstream&, int*, int);
int main(int argc, char** argv) {

    int n;
    do{
        cout << endl << endl;
    cout << "Enter the number of the program you would like to run:" << endl;
    cout << "1) 10.1 String Length" << endl;
    cout << "2) 10.2 Backward String" << endl;
    cout << "3) 10.3 Word Counter" << endl;
    cout << "4) 10.4 Average Number of Letters" << endl;
    cout << "5) 10.6 Vowels and Consonants" << endl;
    cout << "6) 12.1 File Head Program" << endl;
    cout << "7) 12.2 File Display Program" << endl;
    cout << "8) 12.7 Sentence Filter" << endl;
    cout << "9) 12.8 Array/File Functions" << endl;
    cout << "10) 12.11 Corporate Sales Data Output" << endl;
    
    
    cin >> n;
    switch(n)
    {
        case 1:
        {
            char* word = new char[50];
            cout << "Enter a word: ";
            cin >> word;
            cout << "Word Length: " << count(word);
            delete[] word;
            break;
        }
        case 2:
        {
            char* word;
            cout << "Enter a word to write backwards" << endl;
            cin.ignore();
            cin.getline(word, 50);
            char* reverse = rev(word);
            for(int i = 0; i < strlen(word); i++)
                cout << reverse[i];
            
            delete[] reverse;
            break;
        }
        case 3:
        {
            char* sent = new char[50];
            cout << "Enter the sentence" << endl;
            cin.ignore();
            cin.getline(sent, 50);
            int count = wCount(sent);
            cout << count << " words in the sentence";
            delete[] sent;
            break;
        }
        case 4:
        {
            char* sent = new char[50];
            cout << "Enter the sentence" << endl;
            cin.ignore();
            cin.getline(sent, 50);
            int count = wCount(sent);
            cout << count << " words in the sentence";
            delete[] sent;
            break;
        }
        case 5:
        {
            char* sent;
            cout << "Enter a string" << endl;
            cin.ignore();
            cin.getline(sent, 50);
            menu();
            int sol;
            char resp;
            cin >> resp;
            
            do{
            if(toupper(resp) == 'A')
            {
                sol = vow(sent);
                cout << "Number of Vowels: " << sol;
            }
            if(toupper(resp) == 'B')
            {
                sol = cons(sent);
                cout << "Number of Consonants: " << sol;
            }
            if(toupper(resp) == 'C')
            {
                sol = lett(sent);
                cout << "Number of letters: " << sol;
            }
            if(toupper(resp) == 'D')
            {
                cout << "Enter another string: " << endl;
                cin.ignore();
                cin.getline(sent, 50);
            }
            if(toupper(resp) == 'E')
                cout << "This program will now exit" << endl;
            menu();
            cin >> resp;
            } while(toupper(resp) != 'E');
            break;
        }
        case 6:
        {
            cout << "Please enter the name of the file: ";
            string name;
            cin.ignore();
            getline(cin, name);
            fstream file(name.c_str(), ios::in);
            if(!file)
            {
                cout << "File could not be found" << endl;
                exit(1);
            }
            string line;
            int count;
            while(getline(file, line))
            {
                ++count;
            }
            cout << endl << count << endl;
            
            if(count < 10)
            {
                cout << "File has fewer than 10 lines, full file is displayed";
                cout << endl;
                while(getline(file, line))
                {
                    cout << line << endl;
                }
            }
            else
            {
                count = 1;
                cout << "First 10 lines will be displayed" << endl;
                while(getline(file, line))
                {
                    if(count <= 10)
                    {
                        cout << line << endl;
                    }
                    else if(count > 10)
                        break;
                }
                ++count;
            }
            file.close();
            break;
        }
        case 7:
        {
            string file;
            cout << "Enter file name" << endl;
            cin.ignore();
            getline(cin, file);
            int count = 0;
            ifstream infile(file.c_str(), ios::in);
            string line;
            while(getline(infile, file))
            {
                cout << line << endl;
                count++;
                if(count%2 == 0)
                    cout << endl;
            }
            break;
        }
        case 8:
        {
            char c;
            string name;
            cout << "Enter first file" << endl;
            cin.ignore();
            getline(cin, name);
            ifstream infile;
            infile.open(name.c_str(), ios::in);
            if(!infile)
            {
                cout << "File could not be opened" << endl;
                exit(1);
            }
            cout << "Enter second file" << endl;
            string name1;
            cin.ignore();
            getline(cin, name1);
            ofstream outfile;
            outfile.open(name1.c_str(), ios::out);
            infile.get(c);
            while(!infile.eof())
            {
                outfile.put(tolower(c));
                infile.get(c);
            }
            infile.close();
            outfile.close();
            break;
        }
        case 9:
        {
            const int SIZE = 5;
            int a[SIZE] = {1, 2, 3, 4, 5};
            int b[SIZE];
            fstream file;
            if(arrayToFile(file, a, SIZE))
            {
                if(fileToArray(file, b, SIZE ))
                {
                    for(int i = 0; i < SIZE; i++)
                    {
                        cout << b[i] << " ";
                    }
                    cout << endl;
                }
            }
            break;
        }
        case 10:
        {
            Divis comp;
            int sale;
            cout << "Enter Division name" << endl;
            cin.ignore();
            cin.getline(comp.dName, 50);
            comp.quar = new int[4];
            
            
            
            
            delete[] comp.quar;
            break;
        }
        default: if(n < 1 || n >12)cout << "You entered " << n << " to exit";
    }
    } while(n >= 1 && n < 11);
    
    return 0;
}

int count(char* str)
{
    int count = 0;
    while(*str != '\0')
    {
        count++;
        str++;
    }
    return count;
}

char* rev(char* str)
{
    int leng;
    leng = strlen(str);
    char* reverse = new char[leng];
    for(int i = 0; i < leng; i++)
        reverse[i] = str[leng-1-i];
    return reverse;
}

int wCount(char* str)
{
    int count = 0;
    float avg = 0;
    if(str[0] != ' ')
        count++;
    for(int i = 0; i < strlen(str); i++)
        if(str[i] == ' ')
            count++;
    for(int i = 0; i < strlen(str); i++)
        if(str[i] != ' ')
            avg++;
    cout << "Average letters per word: " << avg / count << endl;
    
    return count;
}

void menu()
{
    cout << endl;
    cout << "A) Count number of vowels in string" << endl;
    cout << "B) Count number of consonants in the string" << endl;
    cout << "C) Count both vowels and consonants in the string" << endl;
    cout << "D) Enter Another String" << endl;
    cout << "E) Exit the program" << endl;
}

int vow(char* str)
{
    int count = 0;
    
    for(int i = 0; i < strlen(str); i++)
    {
        if(str[i] == 'A' || str[i] == 'E' || str[i] == 'I' ||
                str[i] == 'O' || str[i] == 'U')
            count++;
    }
    for(int i = 0; i < strlen(str); i++)
    {
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' ||
                str[i] == 'o' || str[i] == 'u')
            count++;
    }
    return count;
}

int cons(char* str)
{
    int count = 0;
    for(int i = 0; i < strlen(str); i++)
    {
        if(str[i] != 'A' && str[i] != 'E' && str[i] != 'I' &&
                str[i] != 'O' && str[i] != 'U' && str[i] != 'a' 
                && str[i] != 'e' && str[i] != 'i' &&
                str[i] != 'o' && str[i] != 'u')
            count++;
    }
    
    return count;
}

int lett(char* str)
{
    int count = 0;
    for(int i = 0; i < strlen(str); i++)
        if(str[i] != ' ')
            count++;
    return count;
}

bool fileToArray(fstream &file, int* a, int size)
{
    string name;
    cout << "Enter file name " << endl;
    cin.ignore();
    getline(cin, name);
    file.open(name.c_str(), ios::in | ios::binary);
    if(!file)
    {
        cout << "Cannot open file" << endl;
        return false;
    }
    file.read((char*) a, size*sizeof(int));
    file.close();
    return true;
    
}

bool arrayToFile(fstream& file, int* a, int size)
{
    string name;
    cout << "Enter file name" << endl;
    cin.ignore();
    getline(cin, name);
    file.open(name.c_str(), ios::out | ios::binary);
    if(!file)
    {
        cout << "Cannot open file" << endl;
        return false;
    }
        file.write((char*) a, size*sizeof(int));
        file.close();
        return true;
}