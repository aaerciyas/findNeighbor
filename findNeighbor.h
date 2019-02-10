#include <iostream>
#include <fstream>

using namespace std;

#define COLOMN 16
#define ROW 10
void readFromTextFile(int map[COLOMN][ROW]);
void scanArray(int map[COLOMN][ROW]);
void compareOthers(int i,int j,int map[COLOMN][ROW],int counter);
void testVektor(int map[COLOMN][ROW]);
