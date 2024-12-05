#include "graph.h"

adrGedung createGedung(string nama, string deskripsi) { //membuat data gedung
    /* F.S. Mengembalikan alamat (pointer) dari sebuah gedung baru yang dibuat dengan nama dan deskripsi yang sesuai */

}

void initGraph(graph &G) { //menginisiasikan graph
    /* I.S. -
    F.S. terdefinisi sebuah graph G dimana firstVertex(G)=nil */

}

void addGedung(graph &G, adrGedung V) { //menambahkan data gedung ke dalam graph
    /* I.S. Terdefinisi sebuah graph, G, dan sebuah pointer ke gedung, V, yang akan ditambahkan ke dalam graph
    F.S. Gedung baru yang direpresentasikan oleh pointer V telah ditambahkan sebagai elemen pertama dalam graph G */

}

adrJalan createJalan(adrGedung V,int jarak){ //membuat data jalan
    /* Mengembalikan alamat (pointer) dari sebuah jalan baru yang menghubungkan ke gedung V dengan jarak tertentu */

}

adrGedung searchGedung(graph &G, string nama){ //mencari alamat gedung dengan nama gedung = nama
    /* Mengembalikan alamat gedung yang sesuai dengan nama, atau NULL jika tidak ditemukan */

}

void addJalan(graph &G, adrJalan E){ //menambahkan data jalan pada gedung
    /* I.S. Terdefinisi sebuah graph, G, dan sebuah pointer ke jalan, E, yang akan ditambahkan ke dalam graph
    F.S. Jalan baru yang direpresentasikan oleh pointer E telah ditambahkan ke daftar jalan pada simpul/gedung yang sesuai dalam graph G */

}

void ruteTerpendek(graph G, adrGedung V1, adrGedung V2){ //mencari dan menampilkan rute terpendek dari gedung dengan alamat V1 ke gedung dengan alamat V2
     /* I.S. Terdefinisi sebuah graph, G, dan dua gedung (V1 dan V2) yang merupakan titik awal dan tujuan untuk pencarian rute terpendek
    F.S. Menampilkan rute terpendek dari gedung V1 ke gedung V2, jika ada, atau memberi informasi bahwa tidak ada rute yang ditemukan */

}

void ruteAlternatif(graph G, adrGedung V1, adrGedung V2){ //mencari dan menampilkan rute alternatif terpendek dari gedung dengan alamat V1 ke gedung dengan alamat V2
    /*I.S. Terdefinisi sebuah graph, G, dan dua gedung (V1 dan V2) yang merupakan titik awal dan tujuan untuk pencarian rute alternatif terpendek
    F.S. Menampilkan rute alternatif terpendek dari gedung V1 ke gedung V2, jika ada, atau memberi informasi bahwa tidak ada rute alternatif yang ditemukan */

}

void showAllGedung(graph G) { // Menampilkan semua gedung yang ada dalam graph G
    /* I.S. Terdefinisi sebuah graph, G, yang berisi data gedung-gedung
    F.S. Menampilkan semua gedung yang ada di dalam graph G */

}

void showGedung(graph G, string nama){ // Menampilkan informasi detail tentang satu gedung tertentu yang dicari
    /*I.S. Terdefinisi sebuah graph, G, dan sebuah nama gedung yang ingin ditampilkan
    F.S. Menampilkan informasi gedung yang sesuai dengan nama yang diberikan, atau memberi informasi bahwa gedung dengan nama tersebut tidak ditemukan */
}