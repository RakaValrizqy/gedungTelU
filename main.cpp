#include "graph.h"

int main()
{
    graph G;
    adrGedung P;

    initGraph(G);
    P = createGedung("TULT", "Telkom University Landmark Tower");
    addGedung(G, P);

    P = createGedung("KU1", "Gedung Perkuliahan Umum 1");
    addGedung(G, P);

    P = createGedung("KU3", "Gedung Tokong Nanas");
    addGedung(G, P);
    showAllGedung(G);

    P = createGedung("OPLIB", "Perpustakaan");
    addGedung(G, P);
    showAllGedung(G);

    cout << searchGedung(G, "OPLIB") << endl;
    cout << searchGedung(G, "FEB");
    return 0;

}
