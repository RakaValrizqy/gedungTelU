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
#include <queue>
#include <map>
#include <vector>
#include <climits>

using namespace std;
typedef struct gedung *adrGedung;
typedef struct jalan *adrJalan;
typedef struct elmQ *adrQ;

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

struct graph {
    adrGedung firstGedung;
    adrJalan firstJalan;
};

struct priorq {
    adrQ head;
    adrQ tail;
};

adrGedung createGedung(string nama, string deskripsi); //membuat data gedung
void initGraph(graph &G); //menginisiasikan graph
void addGedung(graph &G, adrGedung V); //menambahkan data gedung ke dalam graph
adrJalan createJalan(graph G, string gedungAsal, string gedungTujuan,int jarak); //membuat data jalan
adrGedung searchGedung(graph G, string nama); //mencari alamat gedung dengan nama gedung = nama
void addJalan(graph &G, adrJalan E);//menambahkan data jalan pada gedung
void deleteJalan(graph &G, string gedungAsal, string gedungTujuan); //menghapus data jalan
void ruteTerpendek(graph G, string gedungAsal, string gedungTujuan); //mencari dan menampilkan rute terpendek dari gedung dengan alamat V1 ke gedung dengan alamat V2
void ruteAlternatif(graph G, string gedungAsal, string gedungTujuan, string gedungEmergency); //mencari dan menampilkan rute alternatif terpendek dari gedung dengan alamat V1 ke gedung dengan alamat V2
void showAllGedung(graph G); // Menampilkan semua gedung yang ada dalam graph G
void showGedung(graph G, string nama); // Menampilkan informasi detail tentang satu gedung tertentu yang dicari
void showAllJalan(graph G);
adrJalan checkConnectedGedung(graph G, adrGedung V);
void deleteGedung(graph &G,string nama);
void connectingGedung(graph &G,string gedungAsal, string gedungTujuan, int jarak);
void ruteSemuaGedung(graph G, string nama);
int countGedung(graph G);
adrJalan checkJalanFromGedung(graph G, adrGedung V);
void deleteGedungTemporary(graph &G, string nama);
void restoreGedung(graph &G,string nama);
void createPriorQ(priorq &Q);
adrQ createElmQ(int jarak, adrGedung ged);
void pushPriorQ(priorq &Q, adrQ P);
adrQ popPriorQ(priorq &Q);
bool priorQIsEmpty(priorq Q);
void ruteTerpendekTest(graph G, string gedungAsal, string gedungTujuan);
#endif // GRAPH_H_INCLUDED
