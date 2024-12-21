#include "graph.h"

int main()
{
    graph G;
    adrGedung P;
    adrJalan J;

    initGraph(G);

    // Menambahkan gedung
    P = createGedung("TULT", "Telkom University Landmark Tower");
    addGedung(G, P);

    P = createGedung("SPORT CENTER", "Pusat kegiatan olahraga dan kebugaran");
    addGedung(G, P);

    P = createGedung("TUCH", "Aula serbaguna untuk acara-acara besar");
    addGedung(G, P);

    P = createGedung("OPLIB", "Open Library atau perpustakaan");
    addGedung(G, P);

    P = createGedung("GKU", "Gedung Kuliah Umum");
    addGedung(G, P);

    P = createGedung("REKTORAT", "Kantor rektor");
    addGedung(G, P);

    P = createGedung("HOTEL LINGIAN", "Hotel untuk tamu universitas");
    addGedung(G, P);

    P = createGedung("STUDENT CENTER", "Tempat kegiatan mahasiswa");
    addGedung(G, P);

    P = createGedung("KU1", "Gedung Kuliah Umum 1");
    addGedung(G, P);

    P = createGedung("MSU", "Masjid Syamsul ‘Ulum");
    addGedung(G, P);


    // connecting
    // koneksi dari TULT
    connectingGedung(G, "TULT", "SPORT CENTER", 8);
    connectingGedung(G, "TULT", "TUCH", 10);
    connectingGedung(G, "TULT", "OPLIB", 12);

    // koneksi dari SPORT_CENTER
    connectingGedung(G, "SPORT CENTER", "TUCH", 9);
    connectingGedung(G, "SPORT CENTER", "GKU", 6);

    // koneksi dari TUCH
    connectingGedung(G, "TUCH", "OPLIB", 6);
    connectingGedung(G, "TUCH", "GKU", 10);

    // koneksi dari OPLIB
    connectingGedung(G, "OPLIB", "REKTORAT", 11);

    // koneksi dari GKU
    connectingGedung(G, "GKU", "REKTORAT", 5);
    connectingGedung(G, "GKU", "HOTEL LINGIAN", 5);

    // koneksi dari HOTEL_LINGIAN
    connectingGedung(G, "HOTEL LINGIAN", "REKTORAT", 7);
    connectingGedung(G, "HOTEL LINGIAN", "STUDENT CENTER", 9);

    // koneksi dari REKTORAT
    connectingGedung(G, "REKTORAT", "KU1", 5);

    // koneksi dari KU1
    connectingGedung(G, "KU1", "MSU", 7);

    // koneksi dari MSU
    connectingGedung(G, "MSU", "STUDENT CENTER", 15);

    cout << "Sebelum proses pengahapusan: "<<endl;
    cout << "Jumlah gedung: "<<countGedung(G)<<endl;
    showAllGedung(G);
    showAllJalan(G);

    //cout << "Cari rute untuk ke semua gedung dari gedung KU3"<<endl;
    //ruteSemuaGedung(G,"KU3");
    //deleteGedung(G,"KU3");

    //cout << "\nSetelah Penghapusan KU1: "<<endl;
    //deleteGedung(G,"TULT");
    //cout << "List gedung: "<<endl;
    //showAllGedung(G);
    //cout << "List jalan: "<<endl;
    //showAllJalan(G);
    ruteTerpendek(G,"TULT","KU1");
    //ruteAlternatif(G,"KU1","TULT","KU3");
    showAllGedung(G);

    return 0;

}
