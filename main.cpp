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
    showAllGedung(G);

    J = createJalan(G,"OPLIB","TULT",5);
    addJalan(G,J);

    J = createJalan(G,"KU1","TULT",1);
    addJalan(G,J);

    showAllJalan(G);
    return 0;

}
