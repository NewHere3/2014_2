#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

struct komanda
{
    string sustojo= "Sekos pabaiga       ";
    int x = 0;
    int y = 0;
    int komandos[30];
    int sk = 0;
};

void read(int& N, int arr[], ifstream& duom);
void write(komanda seka, ofstream& rez);

int main()
{
    int x = 0, y = 0, X = 0, Y = 0, n = 0, N = 0;
    ifstream duom("Duomenys.txt");
    ofstream rez("Rezultatai.txt");
    duom >> x >> y >> X >> Y >> n;
    komanda sekos[10];

    for (int i = 0; i < n; i++)
    {
        int temp[30] = { 0 };
        read(N, temp, duom);
        sekos[i].x = x;
        sekos[i].y = y;
        for (int j = 0; j < N; j++)
        {
            sekos[i].sk++;
            sekos[i].komandos[j] = temp[j];
            if (temp[j] == 1) sekos[i].y++;
            else if (temp[j] == 2) sekos[i].x++;
            else if (temp[j] == 3) sekos[i].y--;
            else sekos[i].x--;
            if (sekos[i].x == X && sekos[i].y == Y)
            {
                sekos[i].sustojo = "Pasiektas tikslas   ";
                break;
            }
        }
        write(sekos[i], rez);
    }
    rez.close();
    duom.close();
    return 0;
}

void read(int& N, int arr[], ifstream& duom)
{
    duom >> N;
    for (int i = 0; i < N; i++)
    {
        duom >> arr[i];
    }
}

void write(komanda seka, ofstream& rez)
{
    rez << seka.sustojo;
    for (int i = 0; i < seka.sk; i++)
    {
        rez << seka.komandos[i] << ' ';
    }
    rez << seka.sk << '\n';
}