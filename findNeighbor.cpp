#include "findNeighbor.h"

// i satir ======= j sutun

int main(){
	int map[16][10] = {0}; //arraylerin aktarilacagi harita tanimlandi ve hepsi sifira set edildi
	readFromTextFile(map);
	scanArray(map);
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


void scanArray(int map[16][10]){
	int groupCounter = 1;
	for(int i = 0; i<10 ; i++){
		for(int j=0;j<16;j++){
			if(map[j][i]==1){
				groupCounter = groupCounter+1;
				map[j][i]=groupCounter;		//bulunmasi durumunda kacinci grup ise ona gore grup numarasi ile 1 yerine yaziliyor
				compareOthers(i,j,map,groupCounter); //komsular bulunuyor
			}
			}
	}
	cout << "Bulunan grup sayisi: " << groupCounter  - 1	 << endl;
}


void compareOthers(int i,int j,int map[16][10],int counter){
	if(map[j+1][i] == 1 && ((i*16+j) % 16 != 1 || j < 16)){
		// bulunan satirin sagindaki
		map[j+1][i] = 0;
		compareOthers(i,j+1,map,counter);
	}	
	if(map[j-1][i] == 1 && (i*16+j) % 16 != 0){		//bulunan satirin solundaki
		map[j-1][i] = 0;
		compareOthers(i,j-1,map,counter);
	}
	if(map[j][i+1] == 1 && (i*16+j) < 144  ){	//bulunan sutunun altindaki
		map[j][i+1] = 0;
		compareOthers(i+1,j,map,counter);
	}
	if(map[j][i-1] == 1 && (i*16+j) > 15){		//bulunan sutunun ustundeki
		map[j][i-1] = 0;
		compareOthers(i-1,j,map,counter);	
	}	
}

void readFromTextFile(int map[16][10]){
	ifstream myFile ("text"); //arrayin okunacagi dosya
	char c; 	//karakter karakter okunarak 1 ise c charindan arrayimize aktarilacak
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