//#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <ctime>
using namespace std;

int mass1[4][4];
int mass2[4][4];
int main(int argc, char* argv[])
{
    // заполняем массив
    for(int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {

            mass1[i][j] = rand() % 8;
        }


    // записываем массив
    
    /*ofstream fWrite("MyFile.txt", ios_base::binary);
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            fWrite << mass1[i][j];
        }
    fWrite.close();*/
    FILE* pFile;
    fopen_s(&pFile,"Text.txt","w");
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            fprintf(pFile, "%i", mass1[i][j]);
        }
    fclose(pFile);



    //читаем массив
    ifstream fRead("Text.txt", ios_base::binary);
    int n = 10;
    char* buffer = new char[11][11];
    if (fRead) {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++) {
                fRead.read(buffer, n);
            }
    }
    else
        cout << "File cannot be open";
    fRead.close();

    
    // выводим на экран mass2
    /*for(int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cout << mass2[i][j];*/
    for (int i = 0; i < 10; i++)
        cout << buffer[i];
    




    return 0;
}