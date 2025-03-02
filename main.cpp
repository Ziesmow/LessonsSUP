#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <vector>
using namespace std;
int plan[6][5];


void Wypisz(){
  for (int i = 0; i < 6;i++){
    for (int j = 0; j < 5; j++){
      cout << plan[i][j] << ' ';
    }
    cout << endl;
  }
}
struct Przedmiot {
  int index;
  int ilosc;
  bool pior;
  string PelnaNazwa;
}pol, ang, fiz, jez, rel, mat;
void PrzypisywanieDoPrzedmiotu(Przedmiot &przedmiot, int liczba, int pioryt, int index, string nazwa){
  przedmiot.ilosc = liczba;
  przedmiot.pior = pioryt;
  przedmiot.index = index;
  przedmiot.PelnaNazwa = nazwa;
}
void losowanieLekcji(vector<Przedmiot> lekcje, int lek){
  for(int i = 0; i < 6; i++){
    for(int j = 0; j < 5; j++){
      if(i == 0 || i == 5){
        while (true) {
          lek = rand() % 6;
          if (lekcje[lek].pior && lekcje[lek].ilosc > 0){
            plan[i][j] = lekcje[lek].index;
            lekcje[lek].ilosc--;
            break;
          }
          else if(lekcje[lek].pior){
            for (Przedmiot test : lekcje){
              if (test.index != lekcje[lek].index &&  test.ilosc > 0 && test.pior) {
                plan[i][j] = test.index;
                test.ilosc--;
                break;
              }
            }
            if (plan[i][j] != 0) {
              break;
            }
            while (true){
              lek = rand() % 6;
              if(lekcje[lek].ilosc > 0){
                plan[i][j] = lekcje[lek].index;
                lekcje[lek].ilosc--;
                break;
              }
            }
            break;
          }
          else{
            while (true) {
              lek = rand() % 6;
              if (lekcje[lek].ilosc > 0) {
                plan[i][j] = lekcje[lek].index;
                lekcje[lek].ilosc--;
                break;
              }
            }
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
}


int main () {
  srand(time(NULL));
  int lek = 0;
  PrzypisywanieDoPrzedmiotu(pol, 5, false, 6, "polski");
  PrzypisywanieDoPrzedmiotu(ang, 5, false, 1, "angielski");
  PrzypisywanieDoPrzedmiotu(mat, 5, false, 2, "matematyka");
  PrzypisywanieDoPrzedmiotu(fiz, 5, false, 3, "fizyka");
  PrzypisywanieDoPrzedmiotu(jez, 5, true, 4, "język obcy");
  PrzypisywanieDoPrzedmiotu(rel, 5, true, 5, "religia");
  vector<Przedmiot> lekcje = {pol, ang, mat, fiz, jez, rel };
  losowanieLekcji(lekcje, lek);
  Wypisz();

  return 0;
}

