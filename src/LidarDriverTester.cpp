#include <iostream>
#include "../include/LidarDriver.h"

int main(){
    LidarDriver c(3, 0.5);

    try {
        cout << "Creo un oggetto LidarDriver, impostato per contenere 3 scan da 10 valori. L'oggetto è vuoto" << endl;
        cout << "Provo a effettuare una stampa dell'oggetto" << endl;
        c.print_all_scans(); // Non stampa, chiede di inserire scans

        cout << "Creo il primo vettore" << endl;
        vector<double> nuova_colonna(361);
        for (int i = 0; i < 361; i++) {
            nuova_colonna[i] = i;
        }
        cout << "Inserisco il primo vettore" << endl;
        c.new_scan(nuova_colonna);
        cout << "Stampo l'oggetto LidarDriver" << endl;
        c.print_all_scans();
        cout << "Il counter in questo momento è: " << c.get_counter() << endl;

        cout << endl;

        cout << "Creo il secondo vettore" << endl;
        vector<double> nuova_colonna1(361);
        for (int i = 0; i < 361; i++) {
           nuova_colonna1[i] = i + 100;
        }
        cout << "Inserisco il secondo vettore" << endl;
        c.new_scan(nuova_colonna1);
        cout << "Stampo l'oggetto LidarDriver" << endl;
        c.print_all_scans();
        cout << "Il counter in questo momento è: " << c.get_counter() << endl;

        cout << endl;

        cout << "Creo il terzo vettore" << endl;
        vector<double> nuova_colonna2(361);
        for (int i = 0; i < 361; i++) {
            nuova_colonna2[i] = i + 200;
        }
        cout << "Inserisco il terzo vettore" << endl;
        c.new_scan(nuova_colonna2);
        cout << "Stampo l'oggetto LidarDriver" << endl;
        c.print_all_scans();
        cout << "Il counter in questo momento è: " << c.get_counter() << endl;
        cout << "Poichè il buffer è pieno, il counter torna all'indice 0 e il prossimo vettore" << endl;
        cout << "inserito sovrascriverà quello all'indice 0" << endl;

        cout << endl;

        cout << "Quarto vettore" << endl;
        vector<double> nuova_colonna3(361);
        for (int i = 0; i < 361; i++) {
            nuova_colonna3[i] = i + 300;
        }
        c.new_scan(nuova_colonna3);
        c.print_all_scans();
        cout << endl;
        cout << "Counter: " << c.get_counter() << endl;

        cout << "Eseguo la stampa dell'ultima scansione salvata attraverso l'overload dell'operatore <<" << endl;
        cout << c << endl;

        cout << "Stampiamo un po di angoli:" << endl;
        cout << "Angolo 0: " << c.get_distance(0) << endl;
        cout << "Angolo 0.45: "<< c.get_distance(0.45) << endl;
        cout << "Angolo 0.5: " << c.get_distance(0.5) << endl;
        cout << "Angolo 0.7: "<< c.get_distance(0.7) << endl;
        cout << "Angolo 1: "<< c.get_distance(1) << endl;
        cout << "Angolo 12.5: "<< c.get_distance(12.5) << endl;
        cout << "Angolo 40: "<< c.get_distance(40) << endl;
        cout << "Angolo 181: "<< c.get_distance(181) << endl; // Angolo 181 è oltre il limite massimo, Out of Range

    } catch (const out_of_range& e) {
        cout << "Eccezione: Index Out of Range" << endl;
        
    }
    
    return 0;
}