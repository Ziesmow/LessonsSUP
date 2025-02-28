#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <vector>
using namespace std;
int plan[6][5];


void wypisz(){
  for (int i = 0; i < 6;i++){
    for (int j = 0; j < 5; j++){
      cout << plan[i][j];
    }
    cout << endl;
  }
}
struct lekcja {
  int index;
  int ilosc;
  bool pior;
}pol, ang, fiz, jez, rel, mat;
void przyp(lekcja & przedmiot, int liczba, int pioryt, int in ){
  przedmiot.ilosc = liczba;
  przedmiot.pior = pioryt;
  przedmiot.index = in;
}

int main () {
  srand(time(NULL));
  int lek;
  przyp(pol, 5, false, 0);
  przyp(ang, 5, false, 1);
  przyp(mat, 5, false, 2);
  przyp(fiz, 5, false, 3);
  przyp(jez, 5, true, 4);
  przyp(rel, 5, true, 5);
  vector<lekcja> lekcje = {pol, ang, mat, fiz, jez, rel };
  for(int i = 0; i < 6; i++){
    for(int j = 0; j < 5; j++){
      if(i == 0 || i == 5){
          while (true) {
            lek = rand() % 6;
              if(lekcje[lek].pior && lekcje[lek].ilosc > 0){
                plan[i][j] = lekcje[lek].index;
                lekcje[lek].ilosc--;
                break;
              }
              else if (lekcje[lek].ilosc > 0) {
                plan[i][j] = lekcje[lek].index;
                lekcje[lek].ilosc--;
                break;
              }
        }
      }
      else{
        while(true){
          lek = rand() % 6;
          if(lekcje[lek].ilosc > 0) {
            plan[i][j] = lekcje[lek].index;
            lekcje[lek].ilosc--;
            break;
          }
        }
      }
    }
  }
  wypisz();

  return 0;
}

