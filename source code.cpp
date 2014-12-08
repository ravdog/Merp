
// Complier Info: Windows 7 Enterprise 64-bit, Lenovo T430, Code::Blocks 13.12
// Purpose: This program is created to verify a login to a secure database.
//----------------------------------------------------------------------------
// Definition of the Variables:
// code: the access codes, and a boolean variable to ensure it was found in the file;
// Arr: the array into which the access code file was printed;
// size: the size of the access codes;
// key: the key to search inside the array
// fin: the access code file
// i: the count for the array to keep print into Arr until the end of the file;
// found: whether or not the code was found
// attempt: number of attempts

#include <iostream>
#include <fstream>
using namespace std;

bool t =false;
int mySequentialSearch(int [], int, int);

int main()
{
    int Arr[300], size = 300, code;
    int attempt = 1;
    // loading the access code file into the array
    ifstream fin("C:\\Files\\SystemAccessCodes.txt");
    if(fin.is_open())
    {

        for (int i = 0; i <= size; i++)
        {
            fin >> Arr[i];
        }
    }

    cout << "===== ENTER YOUR CODE TO ACCESS INTO THE SYSTEM====" << endl;
    cout << " " << endl;
    while (attempt <= 3)
    {
        cout << "Attempt " << attempt << "/3: ENTER 4 DIGIT CODE ";
            cin >> code;
        mySequentialSearch(Arr,size,code);
        if (!t)
        {
            cout << "           NOT MATCHING! TRY AGAIN." << endl;
            attempt++;
        }
        else
        {
            cout <<"===================================" << endl;
            cout <<" ACCESS GRANTED" << endl;
            cout <<"      WELCOME" << endl;
            cout << " " << endl;
            cout <<"===================================" << endl;
        }

    }
    cout <<"===================================" << endl;
    cout <<" ACCESS DENIED" << endl;
    cout <<" BYE" << endl;
    cout << " " << endl;
    cout <<"===================================" << endl;
}
int mySequentialSearch(int array[], int size, int code)
{
    int key = 0;
    bool found = false;
// actually searching
        while (key < size && !found)
        {
            if (array[key]==code)
                {
                    found = true;
                }
                key++;
        }
        if (found)
        {
            cout  << "It's all good, welcome" << endl;
            t = true;
            return t;
        }
        else
        {
            cout << "Try Again." << endl;
            t = false;
            return t;
        }
    return 0;

}
