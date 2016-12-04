//ARLI MUTIARA GUSRIYANTI (1301154538)//
#include "list_child.h"

void createList(List_child &L) {
    L.first = NULL;
    L.last = NULL;
}

address_child alokasi(infotype_child x) {
    address_child P = new elmlist_child;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void dealokasi(address_child &P){
    delete(P);
}

void insertFirst(List_child &L, address_child P) {
    if(L.first == NULL) {
        L.last = P;
        L.first = P;
    } else {
        P->next = L.first;
        prev(L.first) = P;
        L.first = P;
    }
}

/**void P_inputdata(P_infotype &SISWA){
char benar;
databaru:
cout << "MASUKKAN DATA GURU";
cout << endl;
cout << "NIS siswa : "; cin >> SISWA.NIS;

}*/

void insertLast(List_child &L, address_child P)
{
   if (L.first == NULL )
   {
       L.first = P;
       L.last = P;
    }else
    {
        P -> prev = L.last;
        L.last -> next = P;
        L.last = P;
    }
}

void insertAfter(address_child Prec, address_child P) {
    prev(next(Prec)) = P;
    next(P) = next(Prec);
    prev(P) = Prec;
    next(Prec) = P;
}

void printInfo(List_child L) {
    address_child P = L.first;
    while(P != NULL) {
        cout<<"NIS                      -> "<< P->info.NIS <<endl;
        cout<<"Nama siswa               -> "<< P->info.NamaS <<endl;
        cout<<"Alamat Siswa             -> "<< P->info.AlamatS <<endl;
        cout<<"Kategori Siswa           -> "<< P->info.KategoriS <<endl;
        cout<<"Jurusan Siswa            -> "<< P->info.Jurusan <<endl;
        cout<<"Nilai Siswa Ujian 1      -> "<< P->info.Nilai1 <<endl;
        cout<<"Nilai Siswa Ujian 2      -> "<< P->info.Nilai2 <<endl;
        cout<<"Nilai Siswa Ujian 3      -> "<< P->info.Nilai3 <<endl;
        cout<<endl;
        P = P->next;
    }
}

void deleteFirst(List_child &L, address_child &P)
{
    P = L.first;
    if (P != NULL)
{
    if (L.first == NULL)
    {
        L.first = NULL;
        L.last = NULL;
    }
    else
    {
        P= L.first;
        L.first = P -> next;
        P -> next = NULL;
        L.first -> prev = NULL;
    }
  }
}

void deleteLast(List_child &L, address_child &P){
P = L.first ;
if (P != NULL)
{
    if (L.first == NULL)
    {
        L.first = NULL;
        L.last = NULL;
    }else
    {
        P = L.last;
        L.last = L.last -> prev;
        P -> prev = NULL;
        L.last -> next = NULL;
    }
}
}

void deleteAfter(List_child L, address_child Prec, address_child &P){
    P = L.last;
    L.last = prev(last(L));
    prev(P) = NULL;
    next(L.last) = NULL;
}

address_child findElm(List_child L, infotype_child x) {
    address_child P = first(L);
    while(P != NULL) {
        if(P->info.NIS == x.NIS) {
            return P;
        }
        P = next(P);
    }
    return P;
}
