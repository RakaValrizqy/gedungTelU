#include "graph.h"

int main()
{
    graph G;
    adrGedung P;
    adrJalan J;

    initGraph(G);
    P = createGedung("TULT", "Telkom University Landmark Tower");
    addGedung(G, P);

    P = createGedung("KU1", "Gedung Perkuliahan Umum 1");
    addGedung(G, P);

    P = createGedung("KU3", "Gedung Tokong Nanas");
    addGedung(G, P);

    P = createGedung("OPLIB", "Perpustakaan");
    addGedung(G, P);

    P = createGedung("Student_Center", "Student_Center");
    addGedung(G, P);

    //connecting
    connectingGedung(G,"TULT","KU3",5);
    connectingGedung(G,"OPLIB","KU3",7);

    connectingGedung(G,"KU1","KU3",3);
    connectingGedung(G,"TULT","OPLIB",10);

    connectingGedung(G,"TULT","Student_Center",10);
    connectingGedung(G,"KU3","Student_Center",6);
    connectingGedung(G,"KU1","Student_Center",6);

    cout << "Sebelum proses pengahapusan: "<<endl;
    cout << "Jumlah gedung: "<<countGedung(G)<<endl;
    showAllGedung(G);
    showAllJalan(G);

    cout<<endl;
    cout << "Cari rute untuk ke semua gedung dari gedung KU3"<<endl;
    ruteSemuaGedung(G,"KU3");

    //cout << "\nSetelah Penghapusan KU1: "<<endl;
    //deleteGedung(G,"TULT");
    //cout << "List gedung: "<<endl;
    //showAllGedung(G);
    //cout << "List jalan: "<<endl;
    //showAllJalan(G);

    return 0;

}
