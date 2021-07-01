#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <thread>
#include <chrono>
using namespace std;
float f_rez;
float c_location;
float vrijeme_susreta;


    //udaljenost izmedju centra i tacke
void formula1(float y1, float x1, float y2, float x2) {
    float rez;
    float rez1 = pow(y1 - y2,2);
    float rez2 = pow(x1 - x2, 2);
    
    rez = rez1 + rez2;
    f_rez = sqrt(rez);
    cout <<"Udaljenost objekta " <<f_rez<< endl;


}

    //odredjivanje centra
    void center(float x, float y) {
        float n = (x * x) + (y * y);

        c_location = sqrt(n) / 2;

        cout << "Centar: " << c_location << endl;
                                                                                                                                                                  
    }
   //vrijeme kad ce se brod susresti sa objektom
    void vrijeme(float brzina_broda) {
        vrijeme_susreta = brzina_broda / f_rez;
        cout << "Vrijeme susreta: " << vrijeme_susreta << "s" << endl;
    }
    


int main() {
    float x1, y1;
    cout << "Povrsina koju radar treba obuhvatati: " << endl;;
    cout << "x osa: ";
    cin >> x1;
    cout << "y osa: ";
    cin >> y1;

   
    float x, y;
    float brzina;
    cout << "Lokacija objekta :" << endl;
    cout << "x: ";
    cin >> x;
    if (x > x1) {
        cout << "Objekat se ne moze locirati na radaru" << endl;
        cout << "Ponavljam.....";
        this_thread::sleep_for(chrono::milliseconds(2000));
        return main();
    }
    cout << "y: ";
    cin >> y;
    if (y > y1) {
        cout << "Objekat se ne moze locirati na radaru" << endl;
        cout << "Ponavljam.....";
        this_thread::sleep_for(chrono::milliseconds(2000));
        return main();
    }
    cout << "Brzina broda :";
    cin >> brzina;

    formula1(y1, x1, y, x);
    center(y1, x1);
    vrijeme(brzina);


    
   
}

