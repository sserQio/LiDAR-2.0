#ifndef LIDARDRIVER_H
#define LIDARDRIVER_H

#include <vector>
#include <exception>
#include <cmath>

using namespace std;

class LidarDriver {
    private:
        // Ricordiamo la differenza tra lettura e scansione:
        // Il termine lettura identifica la singola misurazione di distanza a un dato angolo, mentre il termine
        // scansione identifica l’insieme di tutte le letture ai diversi angoli, acquisite in sequenza dal sensore.
        
        int BUFFER_DIM;   // Numero di scansioni effettive
        int angolo;       // Angolo totale da spaziare, questo valore è fisso a 180 gradi
        double ris_ang;   // Angolo che separa le letture consecutive
        int counter;      // Contatore per tenere traccia dello scan più nuovo -> E' l'indice per la colonna più vecchia
        int size;         // Contatore per vedere se il buffer è pieno
        int nLetture;     // Numero di letture
        vector<vector<double>> tabella;

    public:
        LidarDriver(int buffer_size, double ang_ris);

        const int get_BUFFER_DIM() const;              // Metodo per ottenere BUFFER_DIM
        const double get_ris_ang() const;              // Metodo per ottenere ris_ang
        const int get_counter() const;                 // Metodo per ottenere counter
        const vector<vector<double>>& get_tabella() const;  // Metodo per ottenere 
        // ---+---
        // Organizzando le scan in matrice usiamo coordinate x e y per navigare. La coordinata x indica una colonna.
        // Una colonna comprende tutte le letture. Una colonna è quindi una scan. Fornendo il parametro y possiamo quindi
        // scegliere quale lettura stampare 
        void print_lettura(int x, int y); // Metodo per stampare una singola lettura
        void print_scan(int x); // Metodo per stampare uno scan
        void print_all_scans(); // Metodo per stampare la matrice con tutti gli scan
        // void remove_scan(int x); // Rimuove una scan (colonna) a scelta all'indice x

        void new_scan(vector<double>& scan); // Accetta una nuova scansione e lo memorizza nel buffer e sovrascrive
                                             // la meno recente se il buffer è pieno. La meno recente è ad indice counter
        vector<double> get_scan();           // Ritorna l'ultima scan
        void clear_buffer();                 // Elimina tutte le scansioni salvate
        double get_distance(double target);  // Ritorna la lettura corrispondente a target nella scansione più recente 


        void increment_counter();
        void decrement_counter();
};

// Overload operatore
ostream& operator<<(ostream& os, const LidarDriver& d);
ostream& operator<<(ostream& os, const vector<double>& v);

#endif // LIDARDRIVER_H