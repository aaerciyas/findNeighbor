#include "findNeighbor.h"

// i satir ======= j sutun

int main(){
	int map[COLOMN][ROW] = {0}; //arraylerin aktarilacagi harita tanimlandi ve hepsi sifira set edildi
	string makeUrChoice;
	cout << "Text filedan okumak icin 1'e test vektorunu kullanmak icin 2'ye basin ve ardindan Enter'a basin" << endl;
	cin >> makeUrChoice;
	if(makeUrChoice == "1")
		readFromTextFile(map);
	else if(makeUrChoice == "2")
		testVektor(map);
	else{
		cout << "uuups yanlis bir tusa basildi programdan cikiliyor...." << endl;
		exit(0);
	}

	scanArray(map);

	return 0;
}


void scanArray(int map[COLOMN][ROW]){
	int groupCounter = 1;
	for(int i = 0; i<ROW ; i++){
		for(int j=0;j<COLOMN;j++){
			if(map[j][i]==1){
				groupCounter = groupCounter+1;
				map[j][i]=groupCounter;		//bulunmasi durumunda kacinci grup ise ona gore grup numarasi ile 1 yerine yaziliyor
				compareOthers(i,j,map,groupCounter); //komsular bulunuyor
			}
			}
	}
	#ifdef DEBUG
		for (int i = 0; i < ROW; ++i)
		{
			for (int j = 0; j < COLOMN; ++j)
			{
				if(map[j][i] == 0)
					cout<<map[j][i];
				else
					cout<<map[j][i] - 1 ;
			}
			cout << endl;
		}
		cout << endl<<endl;
	#endif
	cout << "Bulunan grup sayisi: " << groupCounter  - 1	 << endl;
}


void compareOthers(int i,int j,int map[COLOMN][ROW],int counter){
	#ifdef DEBUG
		cout << "satir: " << i << "    " << "sutun: " << j << "    "  <<"grup: " << counter - 1 << endl; 
	#endif
	if(map[j+1][i] == 1 && ((i*COLOMN+j) % COLOMN != 1 || j < COLOMN)){
		// bulunan satirin sagindaki
		map[j+1][i] = counter;
		compareOthers(i,j+1,map,counter);
	}	
	if(map[j-1][i] == 1 && (i*COLOMN+j) % COLOMN != 0){		//bulunan satirin solundaki
		map[j-1][i] = counter;
		compareOthers(i,j-1,map,counter);
	}
	if(map[j][i+1] == 1 && (i*COLOMN+j) < ((ROW-1) * COLOMN)  ){	//bulunan sutunun altindaki
		map[j][i+1] = counter;
		compareOthers(i+1,j,map,counter);
	}
	if(map[j][i-1] == 1 && (i*COLOMN+j) > (COLOMN - 1)){		//bulunan sutunun ustundeki
		map[j][i-1] = counter;
		compareOthers(i-1,j,map,counter);	
	}	
}

void readFromTextFile(int map[COLOMN][ROW]){
	ifstream myFile ("text"); //arrayin okunacagi dosya
	char c; 	//karakter karakter okunarak 1 ise c charindan arrayimize aktarilacak
	for(int satC = 0; satC < ROW; satC++)
	{	
		for(int sutC = 0;sutC < COLOMN; sutC++){
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
	cout << endl << endl << "Girilen data asagidaki gibidir" << endl << endl;

	for (int i = 0; i < ROW; ++i){
		for (int j = 0; j < COLOMN; ++j){
			cout<<map[j][i];
		}
		cout << endl;
	}

	cout << endl <<endl;
    myFile.close();
}

void testVektor(int map[COLOMN][ROW]){
	cout << "Olusturulan test vektoru: " << endl;
	srand(time(NULL));
	for(int i = 0; i<ROW ; i++){
		for(int j=0;j<COLOMN;j++){
			map[j][i]=rand() %2;
			cout << map[j][i];
		}
		cout<< endl;
	}
	cout<<endl;


}