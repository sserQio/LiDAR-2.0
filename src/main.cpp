#include <iostream>
#include "../include/LidarDriver.h"

int main(){
    LidarDriver c(3, 18); // CAMBIARE IN 0.5
    try {
    cout << "Stampo 3 colonne, 10 righe" << endl;
    c.print_all_scans(); // Non stampa, chiede di inserire scans
    cout << "Creo nuovo vettore" << endl;
    vector<double> nuova_colonna(15);
    for (int i = 0; i < 15; i++) {
        nuova_colonna[i] = i + 4;
    }
    c.new_scan(nuova_colonna);
    c.print_all_scans();
    cout << "Counter: " << c.get_counter() << endl;

    cout << endl;

    cout << "Secondo vettore" << endl;
    vector<double> nuova_colonna1(8);
    for (int i = 0; i < 8; i++) {
        nuova_colonna1[i] = i + 5;
    }
    c.new_scan(nuova_colonna1);
    c.print_all_scans();
    cout << "Counter: " << c.get_counter() << endl;

    cout << endl;

    cout << "Terzo vettore" << endl;
    vector<double> nuova_colonna2(10);
    for (int i = 0; i < 10; i++) {
        nuova_colonna2[i] = i + 6;
    }
    c.new_scan(nuova_colonna2);
    c.print_all_scans();
    cout << endl;
    cout << "Counter: " << c.get_counter() << endl;

    cout << "Quarto vettore" << endl;
    vector<double> nuova_colonna3(10);
    for (int i = 0; i < 10; i++) {
        nuova_colonna3[i] = i + 7;
    }
    c.new_scan(nuova_colonna3);
    c.print_all_scans();
    cout << endl;
    cout << "Counter: " << c.get_counter() << endl;

    cout << c << endl;

    } catch (const out_of_range& e) {
        cout << "Eccezione: Index Out of Range" << endl;
    }
    
    return 0;
}