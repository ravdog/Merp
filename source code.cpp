#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

bool t = false;
int attempt = 1;


int mySequentialSearch(int [], int, int);

int main()
{
    int Arr[300], size = 300, code;

    // loading the access code file into the array
    ifstream fin("C:\\Files\\SystemAccessCodes.txt");
    if(fin.is_open())
    {

        for (int i = 0; i <= size; i++)
        {
            fin >> Arr[i];
        }
    }
//prompt to enter code
    cout << "===== ENTER YOUR CODE TO ACCESS INTO THE SYSTEM====" << endl;
    cout << " " << endl;

    // while loop to establish the 'exit after 3 attempts' clause
    while (attempt <= 3)
    {
        //stating how many attempts
        cout << "Attempt " << attempt << "/3: ENTER 4 DIGIT CODE ";
            cin >> code;
        //using the search function
        mySequentialSearch(Arr,size,code);
        //TRYING to be the verification of search
        attempt++;
    }
return 0;
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
            cout <<"===================================" << endl;
            cout <<" ACCESS GRANTED" << endl;
            cout <<"      WELCOME" << endl;
            cout << " " << endl;
            cout <<"===================================" << endl;
            return 0;
        }
        else if (!found)
        {
            if (attempt < 3)
            {
                cout << "           NOT MATCHING! TRY AGAIN." << endl;
            }
            else if (attempt == 3)
            {
                cout <<"===================================" << endl;
                cout <<" ACCESS DENIED" << endl;
                cout <<" BYE" << endl;
                cout << " " << endl;
                cout <<"===================================" << endl;
            }



        }
return 0;
}
