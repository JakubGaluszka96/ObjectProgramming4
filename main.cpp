#include <iostream>
#include <fstream>

using namespace std;
//klasa wirtualna
class obiekt_wojskowy {
public:
    bool czyNaSluzbie;
//metody wirtualne
    void ZwolnijZeSluzby(){
    czyNaSluzbie=0;
    cout << "Obiekt zwolniono ze sluzby"<<endl;
    }
    void Najmij(){
    czyNaSluzbie=1;
    cout << "Obiekt podjal sluzbe"<<endl;
    }
protected:
private:

};
//klasa wirtualna
class obiekt {
public:
    string nazwa;

    //metoda 1 //setter
    void Zmien_Nazwe(string nazwa){
    this->nazwa=nazwa;
    cout << "Zmieniono nazwe obiektu."<<endl;
    }


protected:
private:
};
//klasa standardowa 1
class lodz: public obiekt_wojskowy { //dziedzicznie z klasy obiekt wojskowy
public:
    int ladownosc;
//Destruktor
~lodz(){
cout << "Lodz o ladownosci " << this->ladownosc <<" kg, zniszczono"<< endl;
}

lodz(){ //konstruktor domyslny
this->czyNaSluzbie=1;
this->ladownosc=1000;
}
//polimorfizm
lodz(bool czyNaSluzbie, int ladownosc){ //konstruktor 2
this->czyNaSluzbie=czyNaSluzbie;
this->ladownosc=ladownosc;
}
//konstruktor kopiujacy
lodz(lodz &x) {
czyNaSluzbie=x.czyNaSluzbie;
ladownosc=x.ladownosc;
cout << "Stworzono druga taka sama lodz wojskowa."<<endl;
}
//setter
void Zmien_ladownosc(int ladownosc){
this->ladownosc=ladownosc;
}
};
//klasa standardowa 2
class autoo: public obiekt{ //dziedziczenie z klasy obiekt
public:
    int polozenie_X, polozenie_Y, predkosc_X, predkosc_Y; //pola z danymi publicznymi
//metoda
void zmien_polozenie(int polozenie_X, int polozenie_Y){ //setter
    cout<< "Zmieniono polozenie auta " << endl;
    this->polozenie_X=this->polozenie_X;
    this->polozenie_Y=this->polozenie_Y;
}
void zmien_predkosc(int predkosc_X, int predkosc_Y){ //setter
    cout<< "Zmieniono polozenie auta " << endl;
    this->predkosc_X=this->predkosc_X;
    this->predkosc_Y=this->predkosc_Y;
}
void przesun_X(int x){ //setter
    polozenie_X=polozenie_X+x;
    cout<<"Przesunieto auto w osi X"<<endl;
}
//metoda
void przesun_Y(int y){ // setter
    polozenie_Y=polozenie_Y+y;
    cout<<"Przesunieto auto w osi Y"<<endl;
}
get_polozenie_X(){ //getter
return polozenie_X;
}
get_polozenie_Y(){ // getter
return polozenie_Y;
}
get_predkosc_X(){ //getter
return predkosc_X;
}
get_predkosc_Y(){ // getter
return predkosc_Y;
}
krokCzasu(int s){
polozenie_X=polozenie_X+predkosc_X*s;
polozenie_Y=polozenie_Y+predkosc_Y*s;
cout<<"uplynelo " << s <<" sekund" <<endl;
}


};
//klasa standardowa 3
class amfibia: public autoo, public lodz{
public:
    bool LadCzyWoda;

void WjedzNaLad(){ //setter
    LadCzyWoda=1;
    cout<<"Wjechano na lad"<<endl;
}
void Wyplyn(){ //setter
    LadCzyWoda=0;
    cout<<"Wyplynieto na wode"<<endl;
}

// metoda druku
void druk(){
cout<<"Amfibia o nazwie "<<nazwa<< "i ladwonosci " << ladownosc<<" jest "; pomSluzba(); cout<<" i jest w polozeniu ("<<polozenie_X<< "," <<polozenie_Y<<") i porusza sie z predkoscia o skladowych ("<<predkosc_X<< "," <<predkosc_Y<<"), Jest "; pomLad(); cout<<""<<endl;
}
//metody pomocnicze do wydruku
void pomSluzba(){
if (czyNaSluzbie==1){
    cout<<"na sluzbie";
}
else {
    cout<<"zwolniona ze sluzby";
}
}
void pomLad(){
if (LadCzyWoda==1){
    cout<<"na ladzie";
}
else {
    cout<<"na wodzie";
}
}

    //zapis do pliku
void zapis(){
ofstream plik("plik.txt", ios_base::app);
plik << nazwa << " "<< czyNaSluzbie << " " << ladownosc << " " << polozenie_X << " " << polozenie_Y << " " << predkosc_X << " " << predkosc_Y << " " << LadCzyWoda<< endl;
plik.close();
}
//odczyt z pliku
void odczyt(){
ifstream plik;
plik.open ("plik.txt");
plik >> nazwa >> czyNaSluzbie >> ladownosc >> polozenie_X >> polozenie_Y >> predkosc_X >> predkosc_Y >> LadCzyWoda;
cout<<"POCZATEK ODCZYTU"<<endl;
cout << "Amfibia o nazwie "<<nazwa<< " i ladwonosci " << ladownosc<<" jest "; pomSluzba(); cout<<" i jest w polozeniu ("<<polozenie_X<< "," <<polozenie_Y<<") i porusza sie z predkoscia o skladowych ("<<predkosc_X<< "," <<predkosc_Y<<"), Jest "; pomLad();cout<< "."<<endl;
cout<<"KONIEC ODCZYTU"<<endl;
plik.close();
}
~amfibia(){
cout<<"Zniszczono amfibie."<<endl;
}
private:

};
int main()
{
    amfibia a1; //utworzenie instancji amfibia (a1)
    a1.druk(); //wywolanie metody druku
    a1.zapis(); //zapis do pliku "plik.txt"
    a1.odczyt(); //oczyt z pliku "plik.txt"
//    delete a1; //zwolnienie pamieci
//    delete a1; //zwolnienie pamieci
    cout << "KONIEC PROGRAMU." << endl;
    return 0;
}
