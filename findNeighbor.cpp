#include "findNeighbor.h"

int main(){
	int map[16][10] = {0}; //arraylerin aktarilacagi harita tanimlandi ve hepsi sifira set edildi
	readFromTextFile(map);
	//print just for test
	//remove it later
	for (int i = 0; i < 10; ++i){
		for (int j = 0; j < 16; ++j){
			cout<<map[j][i];
		}
		cout << endl;
		}
		cout << endl<<endl;
	return 0;
}

void readFromTextFile(int map[16][10]){
	ifstream myFile ("text"); //arrayin okunacagi dosya
	char c; 	//karakter karakter okunarak 1 ise c charindan arrayimize aktarilacak
	//myFile.ignore('\n');
	for(int satC = 0; satC < 10; satC++)
	{	
		for(int sutC = 0;sutC < 16; sutC++){
			myFile.get(c);
			
			if(c == '\n'){ 			// new line ignore ediliyor
				sutC -= 1;
				continue;
			}
			if(c == '1'){
				map[sutC][satC] = int(c) - 48;
			}
		}
	}
    myFile.close();
}