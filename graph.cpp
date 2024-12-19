#include "graph.h"

adrGedung createGedung(string nama, string deskripsi) { //membuat data gedung
    /* F.S. Mengembalikan alamat (pointer) dari sebuah gedung baru yang dibuat dengan nama dan deskripsi yang sesuai */
    adrGedung P = new gedung;
    nama(P) = nama;
    deskripsi(P) = deskripsi;
    safety(P) = true;
    flag(P) = true;
    nextG(P) = NULL;
    return P;
}

void initGraph(graph &G) { //menginisiasikan graph
    /* I.S. -
    F.S. terdefinisi sebuah graph G dimana firstVertex(G)=nil */
    firstG(G) = NULL;
    firstJ(G) = NULL;
}

void addGedung(graph &G, adrGedung V) { //menambahkan data gedung ke dalam graph
    /* I.S. Terdefinisi sebuah graph, G, dan sebuah pointer ke gedung, V, yang akan ditambahkan ke dalam graph
    F.S. Gedung baru yang direpresentasikan oleh pointer V telah ditambahkan sebagai elemen pertama dalam graph G */
    if (firstG(G) == NULL) {
        firstG(G) = V;
    } else {
       adrGedung P = firstG(G);
       while (nextG(P) != NULL) {
            P = nextG(P);
       }
       nextG(P) = V;
    }
}

adrJalan createJalan(graph G, string gedungAsal, string gedungTujuan,int jarak){
    /* Mengembalikan alamat (pointer) dari sebuah jalan baru yang menghubungkan ke gedung V dengan jarak tertentu */
    adrGedung A = searchGedung(G,gedungAsal);
    adrGedung T = searchGedung(G,gedungTujuan);
    adrJalan P=NULL;

    if (A == NULL && T == NULL){
        cout << "Gedung "<< gedungAsal<<" dan "<<gedungTujuan<<" tidak ditemukan"<<endl;
    } else if (A == NULL){
        cout << "Gedung "<< gedungAsal<<" tidak ditemukan"<<endl;
    } else if (T == NULL){
        cout << "Gedung "<< gedungTujuan<<" tidak ditemukan"<<endl;
    } else {
        P = new jalan;
        asalG(P) = A;
        destG(P) = T;
        jarak(P) = jarak;
        flagJ(P) = true;
        nextJ(P) = NULL;
    }
    return P;
}

adrGedung searchGedung(graph G, string nama){ //mencari alamat gedung dengan nama gedung = nama
    /* Mengembalikan alamat gedung yang sesuai dengan nama, atau NULL jika tidak ditemukan */
    adrGedung P = firstG(G);
    while (P != NULL) {
        if (nama(P) == nama) {
            return P;
        } else {
            P = nextG(P);
        }
    }
    return NULL;
}

void addJalan(graph &G, adrJalan E){ //menambahkan data jalan pada gedung
    /* I.S. Terdefinisi sebuah graph, G, dan sebuah pointer ke jalan, E, yang akan ditambahkan ke dalam graph
    F.S. Jalan baru yang direpresentasikan oleh pointer E telah ditambahkan ke daftar jalan pada simpul/gedung yang sesuai dalam graph G */
    if (firstJ(G)==NULL){
        firstJ(G) = E;
    } else {
        adrJalan P = firstJ(G);
        while (nextJ(P)!=NULL){
            P = nextJ(P);
        }
        nextJ(P) = E;
    }
}

void deleteJalan(graph &G, string gedungAsal, string gedungTujuan) {
/* I.S. Terdefinisi sebuah graph G yang berisi data jalan antar gedung, gedungAsal dan gedungTujuan adalah nama gedung yang jalannya ingin dihapus.
F.S. Jalan yang menghubungkan gedungAsal dan gedungTujuan dihapus dari graph G,  Jika jalan tidak ditemukan menampilkan pesan bahwa jalan tidak ada akan ditampilkan */
    adrJalan prev;
    adrJalan P;

    if (firstJ(G) == NULL) {
        cout << "Tidak ada jalan yang terhubung ke gedung ini" << endl;
    } else {
        prev = NULL;
        P = firstJ(G);

        while(P != NULL) {
            if (nama(asalG(P)) == gedungAsal && nama(destG(P)) == gedungTujuan) {
                if (prev == NULL) {
                    firstJ(G) = nextJ(P);
                } else {
                    nextJ(prev) = nextJ(P);
                }
                //cout << "Jalan dari " << gedungAsal << " ke " << gedungTujuan << " telah dihapus" << endl;
                break;
            }
            prev = P;
            P = nextJ(P);
        }

        if (P == NULL) {
            cout << "Jalan dari " << gedungAsal << " ke " << gedungTujuan << " tidak ditemukan" << endl;
        }
    }
}

void ruteTerpendek(graph G, string gedungAsal, string gedungTujuan){ //mencari dan menampilkan rute terpendek dari gedung dengan alamat V1 ke gedung dengan alamat V2
     /* I.S. Terdefinisi sebuah graph, G, dan dua gedung (V1 dan V2) yang merupakan titik awal dan tujuan untuk pencarian rute terpendek
    F.S. Menampilkan rute terpendek dari gedung V1 ke gedung V2, jika ada, atau memberi informasi bahwa tidak ada rute yang ditemukan */
     // Map untuk menyimpan jarak minimum ke setiap gedung
    map<adrGedung, int> dist;
    map<adrGedung, adrGedung> prev;
    priority_queue<pair<int, adrGedung>, vector<pair<int, adrGedung>>, greater<pair<int, adrGedung>>> pq;

    adrGedung V1 = searchGedung(G,gedungAsal);
    adrGedung V2 = searchGedung(G,gedungTujuan);
    if(V1 == NULL && V2 == NULL){
        cout << "Gedung "<< gedungAsal<<" dan "<<gedungTujuan<<" tidak ditemukan"<<endl;
    } else if (V1 == NULL){
        cout << "Gedung "<< gedungAsal<<" tidak ditemukan"<<endl;
    } else if (V2 == NULL){
        cout << "Gedung "<< gedungTujuan<<" tidak ditemukan"<<endl;
    } else {
        // Inisialisasi
        adrGedung current = firstG(G);
        while (current != nullptr) {
            dist[current] = INT_MAX; // Semua jarak awalnya infinity
            prev[current] = nullptr; // Belum ada jalur
            current = nextG(current);
        }

        dist[V1] = 0; // Jarak ke node asal adalah 0
        pq.push({0, V1}); // Tambahkan node awal ke priority queue

        // Dijkstra
        while (!pq.empty()) {
            pair<int,adrGedung> topEl = pq.top();
            int currentDist = topEl.first;
            adrGedung currentGedung = topEl.second;
            pq.pop();

            // Cek semua jalan dari gedung saat ini
            adrJalan jalan = checkJalanFromGedung(G, currentGedung);
            while (jalan != nullptr) {
                adrGedung tetangga = destG(jalan);
                int jarakBaru = currentDist + jarak(jalan);

                // Perbarui jika ditemukan jarak lebih pendek
                //cout << jarakBaru<<" "<<dist[tetangga]<<endl;
                if (jarakBaru < dist[tetangga]) {
                    dist[tetangga] = jarakBaru;
                    prev[tetangga] = currentGedung;
                    pq.push({jarakBaru, tetangga});
                }
                flagJ(jalan) = false;
                jalan = checkJalanFromGedung(G, currentGedung);
            }

        }

        // Cetak jalur terpendek
        if (dist[V2] == INT_MAX) {
            cout << "Tidak ada rute dari " << nama(V1) << " ke " << nama(V2) << endl;
        } else {
            cout << "Rute terpendek dari " << nama(V1) << " ke " << nama(V2) << " dengan jarak " << dist[V2] << ":\n";
            vector<string> path;
            for (adrGedung at = V2; at != nullptr; at = prev[at]) {
                path.push_back(nama(at));
            }
            for (auto it = path.rbegin(); it != path.rend(); ++it) {
                cout << *it;
                if (it + 1 != path.rend()) cout << " -> ";
            }

            cout << endl;
        }
        //mengembalikan status jalan
        adrJalan jalan = firstJ(G);
        while (jalan != NULL){
            flagJ(jalan) = true;
            jalan = nextJ(jalan);
        }


    }
}

void ruteAlternatif(graph G, string gedungAsal, string gedungTujuan, string gedungEmergency){ //mencari dan menampilkan rute alternatif terpendek dari gedung dengan alamat V1 ke gedung dengan alamat V2
    /*I.S. Terdefinisi sebuah graph, G, dan dua gedung (V1 dan V2) yang merupakan titik awal dan tujuan untuk pencarian rute alternatif terpendek
    F.S. Menampilkan rute alternatif terpendek dari gedung V1 ke gedung V2, jika ada, atau memberi informasi bahwa tidak ada rute alternatif yang ditemukan */
    adrGedung emerg = searchGedung(G,gedungEmergency);
    if(emerg == NULL){
        cout << "Gedung "<<gedungEmergency<<" tidak ditemukan."<<endl;
    } else {
        cout << "Rute terpendek dari "<<gedungAsal<<" ke gedung "<<gedungTujuan<<", menghindari gedung "<<gedungEmergency<<endl;
        deleteGedungTemporary(G,gedungEmergency);
        ruteTerpendek(G,gedungAsal,gedungTujuan);
        restoreGedung(G,gedungEmergency);
    }
}

void showAllGedung(graph G) { // Menampilkan semua gedung yang ada dalam graph G
    /* I.S. Terdefinisi sebuah graph, G, yang berisi data gedung-gedung
    F.S. Menampilkan semua gedung yang ada di dalam graph G */
    if (firstG(G) == NULL) {
        cout << "Tidak terdapat gedung" << endl;
    } else {
        adrGedung P = firstG(G);
        while (P != NULL) {
            cout << nama(P) << endl;
            P = nextG(P);
        }
    }
}

void showGedung(graph G, string nama){ // Menampilkan informasi detail tentang satu gedung tertentu yang dicari
    /*I.S. Terdefinisi sebuah graph, G, dan sebuah nama gedung yang ingin ditampilkan
    F.S. Menampilkan informasi gedung yang sesuai dengan nama yang diberikan, atau memberi informasi bahwa gedung dengan nama tersebut tidak ditemukan */

}

void showAllJalan(graph G){
    if (firstJ(G)==NULL){
        cout << "Tidak terdapat jalan" << endl;
    } else {
        adrJalan P = firstJ(G);
        while (P != NULL){
            cout << nama(asalG(P))<<" -> "<< nama(destG(P))<<" "<<jarak(P)<<"km"<<endl;
            P = nextJ(P);
        }
    }
}

adrJalan checkConnectedGedung(graph G, adrGedung V){
    if (firstJ(G)!=NULL){
        adrJalan P = firstJ(G);
        while (P != NULL){
            if (asalG(P)==V || destG(P)==V){
                return P;
            }
            P = nextJ(P);
        }
    }
    return NULL;
}

void deleteGedung(graph &G,string nama){
    if (firstG(G)!=NULL){
        adrGedung V = searchGedung(G,nama);
        if (V == NULL){
            cout << "Gedung tidak ditemukan"<<endl;
        } else {
            adrJalan E = checkConnectedGedung(G,V);
            while (E != NULL){
                deleteJalan(G,nama(asalG(E)),nama(destG(E)));
                E = checkConnectedGedung(G,V);
            }
            adrGedung P = firstG(G);
            adrGedung prev = NULL;
            while (P != NULL){
                if (nama(P)==nama){
                    break;
                }
                prev = P;
                P = nextG(P);
            }
            if (P == firstG(G)){
                firstG(G) = nextG(V);
            } else if (nextG(P)==NULL){
                nextG(prev) = NULL;
            } else {
                nextG(prev) = nextG(P);
            }
        }
    }

}

void connectingGedung(graph &G,string gedungAsal, string gedungTujuan, int jarak){
    adrGedung A = searchGedung(G,gedungAsal);
    adrGedung T = searchGedung(G,gedungTujuan);

    adrJalan J = createJalan(G,gedungAsal,gedungTujuan,jarak);
    if (J != NULL){
        addJalan(G,J);
        J = createJalan(G,gedungTujuan,gedungAsal,jarak);
        addJalan(G,J);
    }
}

int countGedung(graph G){
    int n = 0;
    if (firstG(G)!=NULL){
        adrGedung P = firstG(G);
        while (P != NULL && safety(P)==true){
            n++;
            P = nextG(P);
        }
    }
    return n;
}

void ruteSemuaGedung(graph G, string nama){
    adrGedung P = searchGedung(G,nama);
    int n = countGedung(G);
    int total = 0;
    if (P == NULL){
        cout << "Gedung tidak ditemukan"<<endl;
    } else {
        flag(P) = false;
        cout << nama(P)<<" -> ";
        for (int i=0; i<n-1; i++){
            adrJalan J = firstJ(G);
            adrJalan min;
            int minc = 9000;
            while(J != NULL){
                if(asalG(J)==P && jarak(J)<minc && flag(destG(J)) ==true){
                    minc = jarak(J);
                    min = J;
                }
                J = nextJ(J);
            }
            flag(destG(min)) = false;
            total += jarak(min);
            cout << nama(destG(min))<<" -> ";
            P = destG(min);
        }
        cout << total <<" km"<<endl;
    }
}

adrJalan checkJalanFromGedung(graph G, adrGedung V){
    if (firstJ(G)!=NULL){
        adrJalan P = firstJ(G);
        while (P != NULL){
            if (asalG(P)==V && flagJ(P)!= false && safety(destG(P))==true){
                return P;
            }
            P = nextJ(P);
        }
    }
    return NULL;
}

void deleteGedungTemporary(graph &G, string nama){
    adrGedung P = searchGedung(G,nama);
    if (P == NULL){
        cout << "Gedung tidak ditemukan"<<endl;
    } else{
        adrJalan J = firstJ(G);
        while (J != NULL){
            if (asalG(J)==P || destG(J)==P){
                flagJ(J) = false;
            }
            J =nextJ(J);
        }
        safety(P) = false;
    }
}
void restoreGedung(graph &G,string nama){
    adrGedung P = searchGedung(G,nama);
    if (P == NULL){
        cout << "Gedung tidak ditemukan"<<endl;
    } else{
        adrJalan J = firstJ(G);
        while (J != NULL){
            if (asalG(J)==P || destG(J)==P){
                flagJ(J) = true;
            }
            J =nextJ(J);
        }
        safety(P) = true;
    }
}
