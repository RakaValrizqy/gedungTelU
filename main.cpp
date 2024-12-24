#include "graph.h"

int main()
{
    graph G;
    adrGedung P;
    adrJalan J;

    initGraph(G);

    string namaGedung, gedungAsal, gedungTujuan, gedungEmergency;
    int jarak;

    // Menambahkan gedung
    P = createGedung("TULT", "Telkom University Landmark Tower");
    addGedung(G, P);


    P = createGedung("SPORT_CENTER", "Pusat kegiatan olahraga dan kebugaran");
    addGedung(G, P);

    P = createGedung("TUCH", "Aula serbaguna untuk acara-acara besar");
    addGedung(G, P);

    P = createGedung("OPLIB", "Open Library atau perpustakaan");
    addGedung(G, P);

    P = createGedung("GKU", "Gedung Kuliah Umum");
    addGedung(G, P);

    P = createGedung("REKTORAT", "Kantor rektor");
    addGedung(G, P);

    P = createGedung("HOTEL_LINGIAN", "Hotel untuk tamu universitas");
    addGedung(G, P);

    P = createGedung("STUDENT_CENTER", "Tempat kegiatan mahasiswa");
    addGedung(G, P);

    P = createGedung("KU1", "Gedung Kuliah Umum 1");
    addGedung(G, P);

    P = createGedung("MSU", "Masjid Syamsul ‘Ulum");
    addGedung(G, P);



    // connecting
    // koneksi dari TULT
    connectingGedung(G, "TULT", "SPORT_CENTER", 8);
    connectingGedung(G, "TULT", "TUCH", 10);
    connectingGedung(G, "TULT", "OPLIB", 12);

    // koneksi dari SPORT_CENTER
    connectingGedung(G, "SPORT_CENTER", "TUCH", 9);
    connectingGedung(G, "SPORT_CENTER", "GKU", 6);

    // koneksi dari TUCH
    connectingGedung(G, "TUCH", "OPLIB", 6);
    connectingGedung(G, "TUCH", "GKU", 10);

    // koneksi dari OPLIB
    connectingGedung(G, "OPLIB", "REKTORAT", 11);

    // koneksi dari GKU
    connectingGedung(G, "GKU", "REKTORAT", 5);
    connectingGedung(G, "GKU", "HOTEL_LINGIAN", 5);

    // koneksi dari HOTEL_LINGIAN
    connectingGedung(G, "HOTEL_LINGIAN", "REKTORAT", 7);
    connectingGedung(G, "HOTEL_LINGIAN", "STUDENT_CENTER", 9);

    // koneksi dari REKTORAT
    connectingGedung(G, "REKTORAT", "KU1", 5);

    // koneksi dari KU1
    connectingGedung(G, "KU1", "MSU", 7);

    // koneksi dari MSU
    connectingGedung(G, "MSU", "STUDENT_CENTER", 15);




    // cout << "Sebelum proses pengahapusan: "<<endl;
    // cout << "Jumlah gedung: "<<countGedung(G)<<endl;
    // showAllGedung(G);
    // showAllJalan(G);

    // cout << "Cari rute untuk ke semua gedung dari gedung GKU"<<endl;
    // ruteSemuaGedung(G,"GKU");
    // deleteGedung(G,"GKU");

    //cout << "\nSetelah Penghapusan KU1: "<<endl;
    //deleteGedung(G,"TULT");
    //cout << "List gedung: "<<endl;
    //showAllGedung(G);
    //cout << "List jalan: "<<endl;
    //showAllJalan(G);
    //ruteTerpendek(G,"TULT","KU1");
    //ruteTerpendekTest(G,"TULT","KU1");
    //ruteAlternatif(G,"KU1","TULT","KU3");
    //showAllGedung(G);



    int pilih;
    do {
        displayMenu();
        cin >> pilih;

        if (pilih == 1) {
            cout << "\n-------------------------------------------------------" << endl;
            cout << "Daftar semua gedung :\n";
            cout << "Jumlah gedung " "'" <<countGedung(G) << "'" <<endl;
            showAllGedung(G);
            cout << "-------------------------------------------------------\n" << endl;
        } else if (pilih == 2) {
            cout << "\n-------------------------------------------------------" << endl;
            cout << "Daftar semua jalan :\n";
            showAllJalan(G);
            cout << "-------------------------------------------------------\n" << endl;
        } else if (pilih == 3) {
            cout << "\n-------------------------------------------------------" << endl;
            cout << "Masukkan nama gedung yang dicari : ";
            cin >> namaGedung;
            showGedung(G, namaGedung);
            cout << "-------------------------------------------------------\n" << endl;
        } else if (pilih == 4) {
            cout << "\n-------------------------------------------------------" << endl;
            cout << "Masukkan nama gedung asal : ";
            cin >> gedungAsal;
            cout << "Masukkan nama gedung tujuan : ";
            cin >> gedungTujuan;
            ruteTerpendek(G, gedungAsal, gedungTujuan);
            cout << "-------------------------------------------------------\n" << endl;
        } else if (pilih == 5) {
            cout << "\n-------------------------------------------------------" << endl;
            cout << "Masukkan nama gedung asal : ";
            cin >> gedungAsal;
            cout << "Masukkan nama gedung tujuan : ";
            cin >> gedungTujuan;
            cout << "Masukkan nama gedung emergency (yang ingin dihindari): ";
            cin >> gedungEmergency;
            ruteAlternatif(G, gedungAsal, gedungTujuan, gedungEmergency);
            cout << "-------------------------------------------------------\n" << endl;
        } else if (pilih == 6) {
            cout << "\n-------------------------------------------------------" << endl;
            cout << "Masukkan nama gedung asal : ";
            cin >> gedungAsal;
            cout << "Masukkan nama gedung tujuan : ";
            cin >> gedungTujuan;
            deleteJalan(G, gedungAsal, gedungTujuan);
            cout << "-------------------------------------------------------\n" << endl;
        } else if (pilih == 7) {
            cout << "\n-------------------------------------------------------" << endl;
            cout << "Masukkan nama gedung yang ingin dihapus : ";
            cin >> namaGedung;
            deleteGedung(G, namaGedung);
            cout << "-------------------------------------------------------\n" << endl;
        } else if (pilih == 8) {
            cout << "\n-------------------------------------------------------" << endl;
            cout << "Masukkan nama gedung awal : ";
            cin >> namaGedung;
            ruteSemuaGedung(G, namaGedung);
            cout << "-------------------------------------------------------\n" << endl;
        } else if (pilih == 0) {
            cout << "|======================================================|\n";
            cout << "|                Keluar dari program ...               |\n";
            cout << "|======================================================|\n";
        } else {
            cout << "Pilihan tidak valid, silakan coba lagi." << endl;
        }

    } while (pilih != 0);

    return 0;
}


