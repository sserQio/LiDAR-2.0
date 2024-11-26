#include <iostream>
#include "../include/LidarDriver.h"

using namespace std;

LidarDriver::LidarDriver(int buffer_size, double ang_ris){
    angolo = 180;
    BUFFER_DIM = buffer_size;
    ris_ang = ang_ris;
    size = 0;
    counter = 0;
    nLetture = static_cast<int>(angolo / ris_ang) + 1;
    for (double x = 0; x < BUFFER_DIM; x++){
        tabella.push_back(vector<double> ());
    }
}

const int LidarDriver::get_BUFFER_DIM() const{
    return BUFFER_DIM;
}

const double LidarDriver::get_ris_ang() const{
    return ris_ang;
}

const int LidarDriver::get_counter() const{
    return counter;
}

const vector<vector<double>>& LidarDriver::get_tabella() const{
    return tabella;
}

void LidarDriver::print_lettura(int x, int y){
    if (x >= tabella.size()) throw out_of_range("Eccezione, indice x fuori range");
    if (y >= nLetture) throw out_of_range("Eccezione, indice y fuori range");
    cout << "La lettura del valore a coordinate x: " << x << ", y: " << y << " dello scan è " << LidarDriver::tabella.at(x).at(y) << endl;
}

void LidarDriver::print_scan(int x){
    if (x >= tabella.size()) throw out_of_range("Eccezione, indice x fuori range");
    for (int i = 0; i < nLetture; i++) {
        cout << LidarDriver::tabella.at(x).at(i) << endl;
    }
}

void LidarDriver::print_all_scans(){
    if (size != 0){     // Se le colonne non sono tutte a 0                   
        for (int y = 0; y < nLetture; y++){
            for (int x = 0; x < size; x++){
                cout << tabella.at(x).at(y) << " ";
            }
            cout << endl;
        }
    } else {
        cout << "Il buffer è vuoto, inserire scans" << endl;
    }
}

void LidarDriver::new_scan(vector<double>& v){
    if (v.size() > nLetture) {
        for (int i = nLetture; i < v.size(); i++) v.pop_back();     // Nuovo scan da inserire ha più letture di quante dovrebbe averne
    }
    if (v.size() < nLetture){                                       // Nuovo scan da inserire ha meno letture di quante dobrebbe averne
        for (int i = v.size(); i < nLetture; i++) v.push_back(0);
    }
    tabella[counter] = v;
    if (size != BUFFER_DIM) size++;
    increment_counter();
}

void LidarDriver::clear_buffer(){
    tabella.erase(tabella.begin(), tabella.end());
    counter = 0;
    for (int i = 0; i < BUFFER_DIM; i++) tabella.push_back(vector<double> ());
}

double LidarDriver::get_distance(double target){
    if(target>180) throw out_of_range("Angolo superiore a 180");

    if (target == 0) return tabella[counter - 1][target];   // Angolo richiesto è 0, ritorna la lettura
                                                            // dello scan più recente in posizione 0
    if (fmod(target, get_ris_ang()) == 0) {                 // Angolo trovato esattamente
        return tabella[counter - 1][target];
    }

    double parteIntera = static_cast<int>(target);     // Converte il numero in intero
    double parteDecimale = target - parteIntera;
    if(parteDecimale >= 0.5){
        int roundingUp = target + (1 - parteDecimale); // Otteniamo il numero esatto arrotondato per eccesso
        return tabella[counter - 1][roundingUp];
    } else {
        int roundingDown = target - parteDecimale;     // Otteniamo il numero esatto arrotondato per difetto
        return tabella[counter - 1][roundingDown];
    }
}

void LidarDriver::increment_counter(){
    if (counter == BUFFER_DIM - 1) counter = 0;
    else counter++;
}

void LidarDriver::decrement_counter() {
    if (counter != 0) {
        counter--;
    } else {
        counter = BUFFER_DIM - 1;
    }
}

ostream& operator<<(ostream& os, const LidarDriver& d){ 
    const vector<vector<double>>& appoggio = d.get_tabella();
    int b = d.get_BUFFER_DIM();
    int c = d.get_counter();
    if (c != 0) {
        c--;
    } else {
        c = b - 1;
    }
    const vector<double>& app = appoggio[c]; // Reference all'ultima colonna salvata (ultima modificata, 
    os << app;                               // non ultima per indice)
    return os;
}

ostream& operator<<(ostream& os, const vector<double>& v){
    for (int i = 0; i < v.size(); i++){
        os << v[i] << endl;
    }
    return os;
}