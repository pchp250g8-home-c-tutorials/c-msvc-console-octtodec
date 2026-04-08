// OctToDec.c : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdint.h>


int main(int argc, char* argv[])
{
    const unsigned int nMaxOctDigits = (unsigned int)(floor(log2(UINT32_MAX)/3));
    unsigned int nOctPower = 1;
    unsigned int nDecNum = 0;
    char szLine1[256], szLine2[256];
    size_t nStrLen1, nStrLen2;
    bool bIsRightString = false;
    system("cls");
    printf("Input an octal number\r\n");
    scanf("%[^\n]", &szLine1);
    sscanf(szLine1, "%[0-7]", szLine2);
    nStrLen1 = strlen(szLine1);
    nStrLen2 = strlen(szLine2);
    bIsRightString = (nStrLen1 <= nMaxOctDigits) && (nStrLen1 == nStrLen2);
    if (!bIsRightString)
    {
        printf("Wrong octal number format!!!\r\n");
        getchar();
        getc(stdin);
        return 0;
    }
    for (unsigned int i = 0; i < nStrLen1; i++)
    {
        unsigned int nOctDigit = szLine1[nStrLen1 - 1 - i] - '0';
        nDecNum += (nOctDigit * nOctPower);
        nOctPower *= 8;
    }
    printf("The decimal equivalent of the octal number %s is %d\r\n", szLine1, nDecNum);
    getchar();
    getc(stdin);
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
