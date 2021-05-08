#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <stack> //pilha
#include <queue> //fila
#include <functional>
#include <tr1/functional> //hash
#include <vector>
#include <cstring>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 25;
    int m[n][n];
    int i = 0, j = 0;
    while (true)
    {
        int v = 0;
        system("clear");
        for (int k = 0; k < n; k++)
        {
            for (int l = 0; l < n; l++)
            {
                if (k == i && l == j)
                {
                    cout << "O";
                }
                else
                {
                    cout << "-";
                }
            }
            cout << endl;
        }

        cin >> v;
        switch (v)
        {
        case 4:
            j--;
            break;
        case 6:
            j++;
            break;
        case 5:
            i++;
            break;
        case 8:
            i--;
            break;

        default:
            i = 0;
            j = 0;
            break;
        }
    }
}