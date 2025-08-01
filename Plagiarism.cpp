#include <iostream>
#include <cstring>
using namespace std;

//AYESHA NOOR
//23I-0736
//ASSIGNMENT 01

bool checkSim(char* ptr1, char* ptr2)
{
    // Count the words in the first string
    int s1 = 0;
    for (int i = 0; ptr1[i] != '\0'; i++) 
    {
        if (ptr1[i] == ' ')
        {
            s1++;
        }
    }
    s1++;                                         // because words is equal to spaces + 1


    // Store words of the first string
    char** array1 = new char* [s1];
    int index1 = 0;
    int start = 0;
    for (int i = 0; i < s1; i++) 
    {
        int len = 0;
        while (ptr1[start] == ' ') 
        {
            start++; 
        }

        while (ptr1[start + len] != ' ' && ptr1[start + len] != '\0')
        {
            len++;
        }
        array1[index1] = new char[len + 1];
        for (int j = 0; j < len; j++)
        {
            array1[index1][j] = ptr1[start + j];
        }
        array1[index1][len] = '\0';
        index1++;
        start += len;
    }

    // Count the words in the second string
    int s2 = 0;
    for (int i = 0; ptr2[i] != '\0'; i++) 
    {
        if (ptr2[i] == ' ')
        {
            s2++;
        }
    }
    s2++;

    // Store words of the second string
    char** array2 = new char* [s2];
    int index2 = 0;
    int start2 = 0;
    for (int i = 0; i < s2; i++)
    {
        int len2 = 0;
        while (ptr2[start2] == ' ')
        {
            start2++;
        }
        while (ptr2[start2 + len2] != ' ' && ptr2[start2 + len2] != '\0')
        {
            len2++;
        }
        array2[index2] = new char[len2 + 1];
        for (int j = 0; j < len2; j++) 
        {
            array2[index2][j] = ptr2[start2 + j];
        }
        array2[index2][len2] = '\0';
        index2++;
        start2 += len2;
    }

    // determine the shorter and the longer array
    char** shorter;
    char** longer;
    int shortSize, longSize;
    if (s1 < s2)
    {
        shorter = array1;
        longer = array2;
        shortSize = s1;
        longSize = s2;
    }
    else
    {
        shorter = array2;
        longer = array1;
        shortSize = s2;
        longSize = s1;
    }

    // Check if the shorter array is a prefix or suffix of the longer array
    bool isPrefix = true, isSuffix = true;
    for (int i = 0; i < shortSize; i++)
    {
        // Compare characters 
        int k = 0;
        while (shorter[i][k] != '\0' && longer[i][k] != '\0' && shorter[i][k] == longer[i][k])
        {
            k++;
        }
        if (shorter[i][k] != '\0' || longer[i][k] != '\0')
        {
            isPrefix = false;
        }

        int j = 0;
        while (shorter[shortSize - 1 - i][j] != '\0' && longer[longSize - 1 - i][j] != '\0' && shorter[shortSize - 1 - i][j] == longer[longSize - 1 - i][j])
        {
            j++;
        }
        if (shorter[shortSize - 1 - i][j] != '\0' || longer[longSize - 1 - i][j] != '\0')
        {
            isSuffix = false;
        }
    }

    if (isPrefix || isSuffix)
    {
        return true;
    }

    // Check if shorter array can be made equal to longer array by inserting a single segment
    for (int i = 0; i <= longSize - shortSize; i++)
    {
        bool matchPrefix = true, matchSuffix = true;
        // Check prefix
        for (int j = 0; j < i; j++)
        {
            int k = 0;
            while (shorter[j][k] != '\0' && longer[j][k] != '\0' && shorter[j][k] == longer[j][k])
            {
                k++;
            }
            if (shorter[j][k] != '\0' || longer[j][k] != '\0')
            {
                matchPrefix = false;
                break;
            }
        }
        // Check suffix
        for (int j = i; j < shortSize; j++)
        {
            int k = 0;
            while (shorter[j][k] != '\0' && longer[j + (longSize - shortSize)][k] != '\0' && shorter[j][k] == longer[j + (longSize - shortSize)][k])
            {
                k++;
            }
            if (shorter[j][k] != '\0' || longer[j + (longSize - shortSize)][k] != '\0')
            {
                matchSuffix = false;
                break;
            }
        }
        if (matchPrefix && matchSuffix)
        {
            return true;
        }
    }

    return false;
}


float similarityIndex(char* ptr1, char* ptr2)
{
    // Count the words in the first string
    float s1 = 0;
    for (int i = 0; ptr1[i] != '\0'; i++) {
        if (ptr1[i] == ' ') {
            s1++;
        }
    }
    s1++;

    // Store words of the first string
    char** array1 = new char* [s1];
    int index1 = 0;
    int start = 0;
    for (int i = 0; i < s1; i++) {
        int len = 0;
        while (ptr1[start] == ' ') start++;
        while (ptr1[start + len] != ' ' && ptr1[start + len] != '\0') len++;
        array1[index1] = new char[len + 1];
        for (int j = 0; j < len; j++) {
            array1[index1][j] = ptr1[start + j];
        }
        array1[index1][len] = '\0';
        index1++;
        start += len;
    }

    // Count the words in the second string
    float s2 = 0;
    for (int i = 0; ptr2[i] != '\0'; i++) {
        if (ptr2[i] == ' ') {
            s2++;
        }
    }
    s2++;

    // Store words of the second string
    char** array2 = new char* [s2];
    int index2 = 0;
    int start2 = 0;
    for (int i = 0; i < s2; i++) {
        int len2 = 0;
        while (ptr2[start2] == ' ') start2++;
        while (ptr2[start2 + len2] != ' ' && ptr2[start2 + len2] != '\0') len2++;
        array2[index2] = new char[len2 + 1];
        for (int j = 0; j < len2; j++) {
            array2[index2][j] = ptr2[start2 + j];
        }
        array2[index2][len2] = '\0';
        index2++;
        start2 += len2;
    }

    // Calculate the number of common words
    int commonWords = 0;
    for (int i = 0; i < s1; i++) {
        for (int j = 0; j < s2; j++) {
            int k = 0;
            while (array1[i][k] != '\0' && array2[j][k] != '\0' && array1[i][k] == array2[j][k]) {
                k++;
            }
            if (array1[i][k] == '\0' && array2[j][k] == '\0') {
                commonWords++;
                break;
            }
        }
    }

    // Calculate the similarity index
   
    
    float larger = s1;
    s1 > s2 ? larger = s1 : larger = s2;
    cout << commonWords << " " << larger << endl;
    
    // Clean up allocated memory
    for (int i = 0; i < s1; i++) {
        delete[] array1[i];
    }
    delete[] array1;
    for (int i = 0; i < s2; i++) {
        delete[] array2[i];
    }
    delete[] array2;

    return ((commonWords/larger) * 100);
}


int main()
{

    //checking plag : 
    char sentence1[] = "my name is haley";
    char sentence2[] = "my haley";

    char* sen1 = &sentence1[0];
    char* sen2 = &sentence2[0];

    if (checkSim(sen1, sen2)) {
        cout << "The sentences are similar.\n";
    }
    else {
        cout << "The sentences are not similar.\n";
    }

    char sentence3[] = "of";
    char sentence4[] = "a lot of words";

    sen1 = &sentence3[0];
    sen2 = &sentence4[0];

    if (checkSim(sen1, sen2)) {
        cout << "The sentences are similar.\n";
    }
    else {
        cout << "The sentences are not similar.\n";
    }

    char sentence5[] = "eating";
    char sentence6[] = "right now eating";

    sen1 = &sentence5[0];
    sen2 = &sentence6[0];

    if (checkSim(sen1, sen2)) {
        cout << "The sentences are similar.\n";
    }
    else {
        cout << "The sentences are not similar.\n";
    }


    //similarity index :

    sen1 = &sentence1[0];
    sen2 = &sentence2[0];

    cout << "Similarity index is : " << similarityIndex(sen1, sen2) << "% ." << endl;

    sen1 = &sentence3[0];
    sen2 = &sentence4[0];

    cout << "Similarity index is : " << similarityIndex(sen1, sen2) << "% ." << endl;

    sen1 = &sentence5[0];
    sen2 = &sentence6[0];

    cout << "Similarity index is : " << similarityIndex(sen1, sen2) << "% ." << endl;

    return 0;
}
