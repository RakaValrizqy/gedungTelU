#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include <iostream>
#define nama(V) V->nama
#define deskripsi(V) V->deskripsi
#define safety(V) V->safety
#define nextG(V) V->nextGedung
#define firstJ(V) V->firstJalan
#define asalG(E) E->asalGedung
#define destG(E) E->destGedung
#define jarak(E) E->jarak
#define nextJ(E) E->nextJalan
#define firstG(G) G.firstGedung
#define firstJ(G) G.firstJalan

using namespace std;
typedef struct gedung *adrGedung;
typedef struct jalan *adrJalan;

struct gedung {
    string nama;
    string deskripsi;
    bool safety;
    adrGedung nextGedung;
};

struct jalan{
    adrGedung asalGedung;
    adrGedung destGedung;
    int jarak;
    adrJalan nextJalan;
};

struct graph {
    adrGedung firstGedung;
    adrJalan firstJalan;
};

adrGedung createGedung(string nama, string deskripsi); //membuat data gedung
void initGraph(graph &G); //menginisiasikan graph
void addGedung(graph &G, adrGedung V); //menambahkan data gedung ke dalam graph
adrJalan createJalan(graph G, string gedungAsal, string gedungTujuan,int jarak); //membuat data jalan
adrGedung searchGedung(graph &G, string nama); //mencari alamat gedung dengan nama gedung = nama
void addJalan(graph &G, adrJalan E);//menambahkan data jalan pada gedung
void ruteTerpendek(graph G, adrGedung V1, adrGedung V2); //mencari dan menampilkan rute terpendek dari gedung dengan alamat V1 ke gedung dengan alamat V2
void ruteAlternatif(graph G, adrGedung V1, adrGedung V2); //mencari dan menampilkan rute alternatif terpendek dari gedung dengan alamat V1 ke gedung dengan alamat V2
void showAllGedung(graph G); // Menampilkan semua gedung yang ada dalam graph G
void showGedung(graph G, string nama); // Menampilkan informasi detail tentang satu gedung tertentu yang dicari
void showAllJalan(graph G);


#endif // GRAPH_H_INCLUDED
