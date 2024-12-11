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


    J = createJalan(G,"OPLIB","TULT",5);
    addJalan(G,J);

    J = createJalan(G,"KU1","TULT",1);
    addJalan(G,J);

    J = createJalan(G,"KU1","KU3",1);
    addJalan(G,J);

    J = createJalan(G,"OPLIB","KU3",1);
    addJalan(G,J);

    J = createJalan(G,"TULT","OPLIB",1);
    addJalan(G,J);

    cout << "Sebelum proses pengahapusan: "<<endl;
    showAllGedung(G);
    showAllJalan(G);

    cout << "\nSetelah Penghapusan KU1: "<<endl;
    deleteGedung(G,"TULT");
    cout << "List gedung: "<<endl;
    showAllGedung(G);
    cout << "List jalan: "<<endl;
    showAllJalan(G);

    return 0;

}
