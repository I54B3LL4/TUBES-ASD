//ISABELLA VICHITA KACARIBU (1301154637)//
#include "List_parent.h"

void createList(List_parent &L){
    L.first = NULL;

}

address_parent alokasi(infotype_parent x){
    address_parent P;
    P = new elmlist_parent;
    P->info = x;
    P->next = NULL;
    createList(P->child);
    return P;
}

void dealokasi(address_parent &P){
    delete (P);
}

void insertposisi(List_parent &L, address_parent P){
    if (first(L) == NULL){
            cout<<"first";
        insertFirst(L,P);
    } else{
    address_parent Q;
    Q = first(L);
    while((info(Q).NIP < info(P).NIP) && (next(Q) != first(L))){
        Q = next(Q);
    }
    if(Q == first(L)&&(info(Q).NIP > info(P).NIP)){
        cout<<"first";
        insertFirst(L,P);
    } else if (Q == last(L)&& (info(Q).NIP < info(P).NIP)){
        cout<<"last";
        insertLast(L,P);
    } else{
        address_parent prec;
        prec = first(L);
        while (next(prec) != Q){
            prec = next(prec);
        }
        cout<<"After";
        insertAfter(L,prec,P);
    }
    }
}

void insertFirst(List_parent &L, address_parent P) {
    address_parent Q;
    if(L.first == NULL) {
        L.first = P;
        P->next = first(L);
    } else {
        Q = L.first;
        while(Q->next != L.first) {
            Q = next(Q);
        }
        P->next = L.first;
        Q->next = P;
        L.first = P;
    }
}

void insertLast(List_parent &L, address_parent P){
    if (L.first == NULL){
        L.first = P;
    } else {
        address_parent A = L.first;
        while ((A -> next) != NULL){
            A = A -> next;
        }
        A -> next = P;
        P -> next = NULL;
    }
}

void insertAfter(List_parent &L, address_parent Prec, address_parent P){

    P -> next = next(Prec);
    next(Prec) = P;
}

address_parent findElm(List_parent L, infotype_parent x) {
    address_parent P ;
    P = L.first;
    while (P != NULL ){
        if(P->info.NIP == x.NIP) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void deleteposisi(List_parent &L, address_parent &P){
    if (P == first(L)){
        cout<<"first";
        deleteFirst(L,P);
    } else if (P == last(L)){
        cout<<"Last";
        deleteLast(L,P);
    }else{
        cout<<"after";
        address_parent prec;
        prec = first(L);
        while (next(prec) != P){
            prec = next(prec);
        }
        deleteAfter(L,prec, P);
    }
}
void deleteFirst(List_parent &L, address_parent &P){
    if (L.first != NULL){
        P = L.first;
        if (P -> next == NULL){
            L.first = NULL;
        } else{
             address_parent Q;
            Q = first(L);
            while(next(Q)!=first(L)){
                Q = next(Q);
            }
            L.first = P -> next;
            next(Q) = first(L);
            P->next = NULL;

        }
    }
}

void deleteLast(List_parent &L, address_parent &P){
    if (L.first != NULL){
        address_parent A = L.first;
        if (A -> next == NULL){
            L.first = NULL;
            A = L.first;
        } else {
            while (((A -> next)-> next) != NULL){
            A = A -> next;
        }
        P = A;
        P -> next = NULL;
        }
    }
}

void deleteAfter(List_parent &L, address_parent Prec, address_parent &P){
    P = next(Prec);
    next(Prec) = P -> next;
    P -> next = NULL;
}

void printInfo(List_parent L) {
    /**
    * FS : menampilkan info seluruh elemen list L
    */
    address_parent P = first(L);
    if(first(L)!=NULL) {
        do {
            cout<<"NIP parent                 -> "<< P->info.NIP <<endl;
            cout<<"Nama parent                -> "<< P->info.NamaG <<endl;
            cout<<"Alamat parent              -> "<< P->info.AlamatG <<endl;
            cout<<"Kategori parent            -> "<< P->info.KategoriG <<endl;
            cout<<"Bidang parent              -> "<< P->info.BidangAjar <<endl;
            cout<<"Kelas 10                   -> "<< P ->info.JumlahKelas1<<endl;
            cout<<"Kelas 11                   -> "<< P ->info.JumlahKelas2<<endl;
            cout<<"Kelas 12                   -> "<< P ->info.JumlahKelas3<<endl;
            cout<<endl;

            printInfo(P->child);
            P = P->next;
        } while(P != L.first);
    }
}
