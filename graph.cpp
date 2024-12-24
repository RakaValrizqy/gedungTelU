#include "graph.h"

adrGedung createGedung(string nama, string deskripsi) { // membuat data gedung
    /* Mengembalikan alamat (pointer) dari sebuah gedung baru yang dibuat dengan nama dan deskripsi yang sesuai */

    adrGedung P = new gedung;
    nama(P) = nama;
    deskripsi(P) = deskripsi;
    safety(P) = true;
    flag(P) = true;
    nextG(P) = NULL;
    return P;
}


void initGraph(graph &G) { // menginisiasikan graph
    /* I.S. -
    F.S. terdefinisi sebuah graph G dimana firstVertex(G)=nil */

    firstG(G) = NULL;
    firstJ(G) = NULL;
}


void addGedung(graph &G, adrGedung V) { // menambahkan data gedung ke dalam graph
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


adrJalan createJalan(graph G, string gedungAsal, string gedungTujuan,int jarak){ // membuat data jalan
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


adrGedung searchGedung(graph G, string nama){ // mencari alamat gedung dengan nama gedung = nama
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


void addJalan(graph &G, adrJalan E){ // menambahkan data jalan pada gedung
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


void deleteJalan(graph &G, string gedungAsal, string gedungTujuan) { // menghapus jalan
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


void ruteTerpendek(graph G, string gedungAsal, string gedungTujuan){ // mencari dan menampilkan rute terpendek dari gedung dengan alamat V1 ke gedung dengan alamat V2
    /* I.S. Terdefinisi sebuah graph, G, dan dua gedung (V1 dan V2) yang merupakan titik awal dan tujuan untuk pencarian rute terpendek
    F.S. Menampilkan rute terpendek dari gedung V1 ke gedung V2, jika ada, atau memberi informasi bahwa tidak ada rute yang ditemukan */

     // Map untuk menyimpan jarak minimum ke setiap gedung
    map<adrGedung, int> dist;
    map<adrGedung, adrGedung> prev;
    priorq pq;

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
        while (current != NULL) {
            dist[current] = INT_MAX; // Semua jarak awalnya infinity
            prev[current] = NULL; // Belum ada jalur
            current = nextG(current);
        }

        createPriorQ(pq);
        dist[V1] = 0; // Jarak ke node asal adalah 0
        adrQ v1 = createElmQ(0,V1);
        pushPriorQ(pq,v1);

        // Dijkstra
        while (!priorQIsEmpty(pq)) {
            adrQ currentQ = popPriorQ(pq);

            // Cek semua jalan dari gedung saat ini
            adrJalan jalan = checkJalanFromGedung(G, currentQ->ged);
            while (jalan != NULL) {
                adrGedung tetangga = destG(jalan);
                int jarakBaru = currentQ->jarak + jarak(jalan);

                // Perbarui jika ditemukan jarak lebih pendek
                if (jarakBaru < dist[tetangga]) {
                    dist[tetangga] = jarakBaru;
                    prev[tetangga] = currentQ->ged;
                    adrQ Z = createElmQ(jarakBaru,tetangga);
                    pushPriorQ(pq,Z);
                    //cout << nama(tetangga)<<endl;
                }
                flagJ(jalan) = false;
                jalan = checkJalanFromGedung(G, currentQ->ged);
            }
        }


        // Cetak jalur terpendek
        if (dist[V2] == INT_MAX) {
            cout << "Tidak ada rute dari " << nama(V1) << " ke " << nama(V2) << endl;
        } else {
            cout << "Rute terpendek dari " << nama(V1) << " ke " << nama(V2) << " dengan jarak " << dist[V2] << ":\n";
            adrGedung V = V2;
            rute Rute;
            createRute(Rute);
            while(V != NULL){
                adrRute R = createElmRute(V);
                insertFirstRute(Rute,R);
                V = prev[V];
            }
            showRute(Rute);
        }
        //mengembalikan status jalan
        adrJalan jalan = firstJ(G);
        while (jalan != NULL){
            flagJ(jalan) = true;
            jalan = nextJ(jalan);
        }


    }
}


void ruteAlternatif(graph G, string gedungAsal, string gedungTujuan, string gedungEmergency){ // mencari dan menampilkan rute alternatif terpendek dari gedung dengan alamat V1 ke gedung dengan alamat V2
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


void showAllGedung(graph G) { // menampilkan semua gedung yang ada dalam graph G
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

void showGedung(graph G, string nama){ // menampilkan informasi detail tentang satu gedung tertentu yang dicari
    /*I.S. Terdefinisi sebuah graph, G, dan sebuah nama gedung yang ingin ditampilkan
    F.S. Menampilkan informasi gedung yang sesuai dengan nama yang diberikan, atau memberi informasi bahwa gedung dengan nama tersebut tidak ditemukan */

    adrGedung P = searchGedung(G, nama);

    if (P == NULL) {
        cout << "Gedung dengan nama " << nama << " tidak ditemukan." << endl;
    } else {
        cout << "Nama Gedung       : " << nama(P) << endl;
        cout << "Deskripsi Gedung  : " << deskripsi(P) << endl;
    }
}


void showAllJalan(graph G){ // menampilkan semua jalan yang ada dalam graph G
    /* I.S. Terdefinisi sebuah graph, G, yang berisi data jalan antar gedung
    F.S. Menampilkan semua jalan yang ada di dalam graph G beserta jaraknya */

    if (firstJ(G)==NULL){
        cout << "Tidak terdapat jalan" << endl;
    } else {
        adrJalan P = firstJ(G);
        while (P != NULL){
            cout << nama(asalG(P))<<" -> "<< nama(destG(P))<<" : "<<jarak(P)<<" Km"<<endl;
            P = nextJ(P);
        }
    }
}


adrJalan checkConnectedGedung(graph G, adrGedung V){ // memeriksa apakah gedung terhubung dengan jalan dalam graph G
    /* Mengembalikan pointer ke jalan jika ada yang terhubung dengan gedung V, atau NULL jika tidak ada */

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


void deleteGedung(graph &G,string nama){ // menghapus sebuah gedung dari graph G
    /* I.S. Terdefinisi sebuah graph, G, dan sebuah nama gedung yang ingin dihapus
    F.S. Menghapus gedung dengan nama yang sesuai dari graph G beserta semua jalan yang terhubung dengannya */

    if (firstG(G)!=NULL){
        adrGedung V = searchGedung(G,nama);
        if (V == NULL){
            cout << "Gedung " << nama << " tidak ditemukan"<<endl;
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
            cout << "Gedung " << nama << " berhasil dihapus" << endl;
        }
    }
}


void connectingGedung(graph &G,string gedungAsal, string gedungTujuan, int jarak){ // menambahkan koneksi antara dua gedung dengan jarak tertentu
    /* I.S. Terdefinisi sebuah graph, G, dua nama gedung (gedungAsal dan gedungTujuan), dan jarak antar gedung
    F.S. Menambahkan koneksi dua arah antara gedungAsal dan gedungTujuan dengan jarak yang sesuai */

    adrGedung A = searchGedung(G,gedungAsal);
    adrGedung T = searchGedung(G,gedungTujuan);

    adrJalan J = createJalan(G,gedungAsal,gedungTujuan,jarak);
    if (J != NULL){
        addJalan(G,J);
        J = createJalan(G,gedungTujuan,gedungAsal,jarak);
        addJalan(G,J);
    }
}


int countGedung(graph G){ // menghitung jumlah gedung dalam graph G
    /* Mengembalikan jumlah gedung yang ada dalam graph G */

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


adrGedung searchPersimpanganUtama(graph G){
    adrGedung P = firstG(G);
    adrGedung maxJalan = P;
    int nJalanMax = 0;
    int nJalan;
    adrJalan J;
    while (P!=NULL){
        J = firstJ(G);
        nJalan = 0;
        while(J!=NULL){
            if (asalG(J)==P){
                nJalan++;
            }
            J=nextJ(J);
        }
        if (nJalan > nJalanMax){
            maxJalan = P;
            nJalanMax = nJalan;
        }
        P = nextG(P);
    }
    return maxJalan;
}


adrJalan checkJalanFromGedung(graph G, adrGedung V){ // memeriksa semua jalan yang berasal dari sebuah gedung
    /* Mengembalikan pointer ke jalan pertama yang terhubung dari gedung V dengan kondisi flag jalan aktif dan tujuan aman */

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


void deleteGedungTemporary(graph &G, string nama){ // menghapus sementara sebuah gedung dan jalan yang terhubung
    /* I.S. Terdefinisi sebuah graph, G, dan nama gedung, nama, yang ingin dihapus sementara
    F.S. Gedung dengan nama yang sesuai dihapus sementara dengan jalan yang terhubung di-disable (flag jalan diatur false) */

    adrGedung P = searchGedung(G,nama);
    if (P == NULL){
        cout << "Gedung tidak ditemukan" << endl;
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


void restoreGedung(graph &G,string nama){ // memulihkan gedung dan jalan yang sebelumnya dihapus sementara
    /* I.S. Terdefinisi sebuah graph, G, dan nama gedung, nama, yang ingin dipulihkan
    F.S. Gedung dengan nama yang sesuai dikembalikan ke kondisi aktif dengan jalan yang terhubung di-enable kembali (flag jalan diatur true) */

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


void createPriorQ(priorq &Q){ // membuat priority queue baru
    /* I.S. Sebuah priority queue, Q, belum terdefinisi
    F.S. Sebuah priority queue baru dibuat dengan head dan tail diinisialisasi NULL */

    head(Q) = NULL;
    tail(Q) = NULL;
}


adrQ createElmQ(int jarak, adrGedung ged){ // membuat elemen baru dalam priority queue
    /* Mengembalikan pointer elemen queue yang baru dibuat dengan jarak dan gedung yang sesuai */

    adrQ P = new elmQ;
    P->jarak = jarak;
    P->ged = ged;
    P->next = NULL;
    return P;
}


void pushPriorQ(priorq &Q, adrQ P){ // menambahkan elemen baru ke priority queue
    /* I.S. Terdefinisi sebuah priority queue, Q, dan elemen baru, P
    F.S. Elemen P ditambahkan ke dalam queue berdasarkan prioritas jarak yang terurut naik */

    if (head(Q) == NULL || P->jarak < head(Q)->jarak) {
        P->next = head(Q);
        head(Q) = P;
        if (tail(Q) == NULL) {
            tail(Q) = P;
        }
    } else {
        adrQ R = head(Q);
        while (R->next != NULL && R->next->jarak <= P->jarak) {
            R = R->next;
        }
        P->next = R->next;
        R->next = P;
        if (P->next == NULL) {
            tail(Q) = P;
        }
    }
}


adrQ popPriorQ(priorq &Q){ // menghapus elemen dengan prioritas tertinggi dari queue
    /* Mengembalikan elemen dengan prioritas tertinggi dari queue dan menghapusnya */

    if (head(Q)==NULL&&tail(Q)==NULL){
        return NULL;
    } else if(head(Q)==tail(Q)){
        adrQ P = head(Q);
        head(Q) = NULL;
        tail(Q) = NULL;
        return P;
    } else {
        adrQ P = head(Q);
        head(Q) = head(Q)->next;
        P->next = NULL;
        return P;
    }
}


bool priorQIsEmpty(priorq Q){ // mengecek apakah priority queue kosong
    /* Mengembalikan true jika priority queue Q kosong, dan false jika tidak */

    return head(Q)==NULL&&tail(Q)==NULL;
}

adrRute createElmRute(adrGedung V){
    adrRute P = new elmRute;
    P->ged = V;
    P->next = NULL;
    return P;
}

void createRute(rute &R){
    R.first = NULL;
}

void insertFirstRute(rute &R, adrRute AR){
    if (R.first==NULL){
        R.first=AR;
    } else {
        AR->next = R.first;
        R.first = AR;
    }
}

void showRute(rute R){
    adrRute P = R.first;
    while(P->next!=NULL){
        cout << nama(P->ged)<<" -> ";
        P = P->next;
    }
    cout << nama(P->ged)<<endl;
}



void displayMenu() { // menampilkan menu pilihan untuk program utama
    cout << "|======================================================|\n";
    cout << "|                         MENU                         |\n";
    cout << "|======================================================|\n";
    cout << "| 1. Menampilkan Semua Gedung                          |\n";
    cout << "| 2. Menampilkan Semua Jalan                           |\n";
    cout << "| 3. Cari Gedung                                       |\n";
    cout << "| 4. Cari Rute Terpendek                               |\n";
    cout << "| 5. Cari Rute Alternatif                              |\n";
    cout << "| 6. Menghapus Jalan                                   |\n";
    cout << "| 7. Menghapus Gedung                                  |\n";
    cout << "| 8. Cari Persimpangan Utama                           |\n";
    cout << "| 0. Keluar                                            |\n";
    cout << "|======================================================|\n";
    cout << "Pilih menu: ";
}

