#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include <iostream>
#define nama(V) V->nama
#define deskripsi(V) V->deskripsi
#define safety(V) V->safety
#define flag(V) V->flag
#define nextG(V) V->nextGedung
#define firstJ(V) V->firstJalan
#define asalG(E) E->asalGedung
#define destG(E) E->destGedung
#define jarak(E) E->jarak
#define flagJ(E) E->flag
#define nextJ(E) E->nextJalan
#define firstG(G) G.firstGedung
#define firstJ(G) G.firstJalan
#define head(Q) Q.head
#define tail(Q) Q.tail
#include <map>
#include <climits>

using namespace std;
typedef struct gedung *adrGedung;
typedef struct jalan *adrJalan;
typedef struct elmQ *adrQ;
typedef struct elmRute *adrRute;

struct gedung {
    string nama;
    string deskripsi;
    bool safety;
    bool flag;
    adrGedung nextGedung;
};

struct jalan{
    adrGedung asalGedung;
    adrGedung destGedung;
    int jarak;
    bool flag;
    adrJalan nextJalan;
};

struct elmQ {
    int jarak;
    adrGedung ged;
    adrQ next;
};

struct elmRute{
    adrGedung ged;
    adrRute next;
};

struct graph {
    adrGedung firstGedung;
    adrJalan firstJalan;
};

struct priorq {
    adrQ head;
    adrQ tail;
};

struct rute {
    adrRute first;
};


adrGedung createGedung(string nama, string deskripsi); // membuat data gedung
void initGraph(graph &G); // menginisiasikan graph
void addGedung(graph &G, adrGedung V); // menambahkan data gedung ke dalam graph
adrJalan createJalan(graph G, string gedungAsal, string gedungTujuan,int jarak); // membuat data jalan
adrGedung searchGedung(graph G, string nama); //mencari alamat gedung dengan nama gedung = nama
void addJalan(graph &G, adrJalan E);//menambahkan data jalan pada gedung
void deleteJalan(graph &G, string gedungAsal, string gedungTujuan); // menghapus data jalan
void ruteTerpendek(graph G, string gedungAsal, string gedungTujuan); // mencari dan menampilkan rute terpendek dari gedung dengan alamat V1 ke gedung dengan alamat V2
void ruteAlternatif(graph G, string gedungAsal, string gedungTujuan, string gedungEmergency); // mencari dan menampilkan rute alternatif terpendek dari gedung dengan alamat V1 ke gedung dengan alamat V2
void showAllGedung(graph G); // menampilkan semua gedung yang ada dalam graph G
void showGedung(graph G, string nama); // menampilkan informasi detail tentang satu gedung tertentu yang dicari
void showAllJalan(graph G); // menampilkan semua jalan yang ada dalam graph G
adrJalan checkConnectedGedung(graph G, adrGedung V); // memeriksa apakah gedung terhubung dengan jalan dalam graph G
void deleteGedung(graph &G,string nama); // menghapus sebuah gedung dari graph G
void connectingGedung(graph &G,string gedungAsal, string gedungTujuan, int jarak); // menambahkan koneksi antara dua gedung dengan jarak tertentu
adrGedung searchPersimpanganUtama(graph G); // mencari alamat gedung dengan jumlah jalan keluar terbanyak
int countGedung(graph G); // menghitung jumlah gedung dalam graph G
adrJalan checkJalanFromGedung(graph G, adrGedung V); // memeriksa semua jalan yang berasal dari sebuah gedung
void deleteGedungTemporary(graph &G, string nama); // menghapus sementara sebuah gedung dan jalan yang terhubung
void restoreGedung(graph &G,string nama); // memulihkan gedung dan jalan yang sebelumnya dihapus sementara
void createPriorQ(priorq &Q); // membuat priority queue baru
adrQ createElmQ(int jarak, adrGedung ged); // membuat elemen baru dalam priority queue
void pushPriorQ(priorq &Q, adrQ P); // menambahkan elemen baru ke priority queue
adrQ popPriorQ(priorq &Q); // menghapus elemen dengan prioritas tertinggi dari queue
bool priorQIsEmpty(priorq Q); // mengecek apakah priority queue kosong
void displayMenu(); // menampilkan menu pilihan untuk program utama
adrRute createElmRute(adrGedung V); // membuat elemen rute baru dengan gedung V
void createRute(rute &R); // membuat rute kosong
void insertFirstRute(rute &R, adrRute AR); // menambahkan elemen di awal rute
void showRute(rute R); // menampilkan elemen-elemen rute secara berurutan

#endif // GRAPH_H_INCLUDED
