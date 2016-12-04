//ISABELLA VICHITA KACARIBU (1301154637)//
#ifndef LIST_PARENT_H_INCLUDED
#define LIST_PARENT_H_INCLUDED
#include <stdlib.h>
#include <conio.h>
#include <iostream>
using namespace std;

#include "list_child.h"

#define first(L) L.first
#define next(P) P->next
#define info(P) P->info
#define child(P) P->child

struct parent{
    int NIP;
    string NamaG;
    string AlamatG;
    string KategoriG;
    string BidangAjar;
    int JumlahKelas1;
    int JumlahKelas2;
    int JumlahKelas3;

};
typedef parent infotype_parent;
typedef struct elmlist_parent *address_parent;

struct elmlist_parent {
    infotype_parent info;
    address_parent next;
    /** list child **/
    List_child child;
};

struct List_parent {
    address_parent first;
    address_parent last;
};

void createList(List_parent &L);
address_parent alokasi(infotype_parent x);
void dealokasi(address_parent &P);
void insertposisi(List_parent &L, address_parent P);
void insertFirst(List_parent &L, address_parent P);
void insertAfter(List_parent &L, address_parent Prec, address_parent P);
void insertLast(List_parent &L, address_parent P);
address_parent findElm(List_parent L, infotype_parent x);
void deleteposisi(List_parent &L, address_parent &P);
void deleteFirst(List_parent &L, address_parent &P);
void deleteLast(List_parent &L, address_parent &P);
void deleteAfter(List_parent &L, address_parent Prec, address_parent &P);
void printInfo(List_parent L);
address_parent sentinelSearch(List_parent L, infotype_parent x);
#endif // LIST_parent_H_INCLUDED
