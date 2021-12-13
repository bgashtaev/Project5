#include <iostream>
#include <iomanip>
using namespace std;


const int ROWS = 3;
const int COLUMNS = 3;
const int MIN = 1;
const int MAX = 9;

bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max);
bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRowSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);
bool checkColSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);
bool checkDiagSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);
//get input from the user and fill it into array
void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
//show user input in the mamtrix form
void showArray(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);

int main()
{

    //define magic array
    int magicArrayRow1[COLUMNS], magicArrayRow2[COLUMNS], magicArrayRow3[COLUMNS];
    char again = 'y';

    do {

        fillArray(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLUMNS);

        showArray(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLUMNS);

        if (isMagicSquare(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLUMNS))
        {
            cout << "This is a Lo Shu magic square." << endl;
            cout << "Thank you for testing my program!" << endl;
            cout << "Programmer: Basang Gashtaev" << endl;
            cout << "CMSC 140 Project 5" << endl;
            cout << "Due Date: 12/6/2021" << endl;
        }
        else
            cout << "This is not a Lo Shu magic square." << endl;
        //Ask the user if he or she would like to do it again.
        cout << "\n\nDo you want to try again? (type for Yes(y) and No(n) " << endl;
        cin >> again;
    } while (again == 'y' || again == 'Y');

    if (again == 'n' || again == 'N');
    {
        cout << "Thank you for testing my program!" << endl;
        cout << "Programmer: Basang Gashtaev" << endl;
        cout << "CMSC 140 Project 5" << endl;
        cout << "Due Date: 12/6/2021" << endl;
        exit(0);
    }

    return 0;
}


// function to fill user input in to the array
void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
    int ROW_NUMBER = 0;
    // for loop to get user number for row 1
    for (int columnNumber = 0; columnNumber < size; columnNumber++)
    {
        cout << "Enter the number for row " << ROW_NUMBER
            << " and for column " << columnNumber << " : ";
        cin >> arrayRow1[columnNumber];
    }
    ROW_NUMBER++;
    // for loop to get user number for row 2
    for (int colNum = 0; colNum < size; colNum++)
    {
        cout << "Enter the number for row " << ROW_NUMBER
            << " and for column " << colNum << " : " << endl;
        cin >> arrayRow2[colNum];
    }
    ROW_NUMBER++;
    // for loop to get user number for row 3
    for (int colNum = 0; colNum < size; colNum++)
    {
        cout << "Enter the number for row " << ROW_NUMBER
            << " and for column " << colNum << " : " << endl;
        cin >> arrayRow3[colNum];
    }

}

// Display matrix input by the user in rows and columns

void showArray(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size)
{
    int ROW_NUMBER = 0;
    for (int colNum = 0; colNum < size; colNum++)
    {
        cout << arrayrow1[colNum] << " ";
    }
    cout << endl;
    ROW_NUMBER++;

    for (int colNum = 0; colNum < size; colNum++)
    {
        cout << arrayrow2[colNum] << " ";
    }
    cout << endl;
    ROW_NUMBER++;

    for (int colNum = 0; colNum < size; colNum++)
    {
        cout << arrayrow3[colNum] << " ";
    }
    cout << endl;
}

// check if user input is in range 1 to 9

bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max)
{
    bool status = true;
    for (int colNum = 0; colNum < COLUMNS; colNum++)
    {
        if (arrayRow1[colNum] < min || arrayRow1[colNum] > max)
        {
            status = false;
        }

        else if (arrayRow2[colNum] < min || arrayRow2[colNum] > max)
        {
            status = false;
        }

        else if (arrayRow3[colNum] < min || arrayRow3[colNum] > max)
        {
            status = false;
        }
    }
    return status;
}

// Check user input is unique or not

bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
    int i = 0, j = 0, k = 0;
    bool status = true;

    while (i < (sizeof(arrayRow1) / sizeof(arrayRow1[0]))
        && j < (sizeof(arrayRow2) / sizeof(arrayRow2[0]))
        && k < (sizeof(arrayRow3) / sizeof(arrayRow3[0])))
    {
        if ((arrayRow1[i] == arrayRow2[j]) && (arrayRow2[j] == arrayRow3[k]))
        {
            if (i > 1)
            {
                status = false;
            }

            i++;
            j++;
            k++;
        }

        else if (arrayRow1[i] < arrayRow2[j])
            i++;
        else if (arrayRow2[j] < arrayRow3[k])
            j++;
        else
            k++;
    }
    return status;
}

// function to check row sum
bool checkRowSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size)
{
    bool status = true;
    int sum1 = arrayrow1[0] + arrayrow1[1] + arrayrow1[2];

    int sum2 = arrayrow2[0] + arrayrow2[1] + arrayrow2[2];

    int sum3 = arrayrow3[0] + arrayrow3[1] + arrayrow3[2];

    if ((sum1 != sum2) || (sum1 != sum3) || (sum2 != sum3))
    {
        status = false;
    }
    return status;
}

//function to check column sum
bool checkColSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size)
{
    bool status = true;
    int sum1 = arrayrow1[0] + arrayrow2[0] + arrayrow3[0];

    int sum2 = arrayrow1[1] + arrayrow2[1] + arrayrow3[1];

    int sum3 = arrayrow1[2] + arrayrow2[2] + arrayrow3[2];

    if ((sum1 != sum2) || (sum1 != sum3) || (sum2 != sum3))
    {
        status = false;
    }
    return status;

}

//function to check diagonal sum

bool checkDiagSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size)
{
    bool status = true;
    int sum1 = arrayrow1[0] + arrayrow2[1] + arrayrow3[2];

    int sum2 = arrayrow1[2] + arrayrow2[1] + arrayrow3[0];

    if (sum1 != sum2)
    {
        status = false;
    }
    return status;
}

// function to check if matrix is magic square or not
bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
    bool status = false;


    bool isInRange = checkRange(arrayRow1, arrayRow2, arrayRow3, size, MIN, MAX);

    bool isUnique = checkUnique(arrayRow1, arrayRow2, arrayRow3, size);

    bool isRowEqual = checkRowSum(arrayRow1, arrayRow2, arrayRow3, size);

    bool isColEqual = checkColSum(arrayRow1, arrayRow2, arrayRow3, size);

    bool isDiagEqual = checkDiagSum(arrayRow1, arrayRow2, arrayRow3, size);


    if (isInRange && isUnique && isRowEqual
        && isColEqual && isDiagEqual)
    {
        status = true;
    }
    return status;

}