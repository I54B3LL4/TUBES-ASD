#include <iostream>
#include "list_parent.h"
#include "list_child.h"

using namespace std;

void mainMenu();//ISABELLA VICHITA KACARIBU (1301154637)//
List_child L2;
List_parent L1;
address_parent P1 = NULL;
address_child P2 = NULL;
infotype_parent x1;
infotype_child x2;

int main(){//ISABELLA VICHITA KACARIBU (1301154637)//
    createList(L1);
    createList(L2);
    mainMenu();
    return 0;
}
int pil;
char y;
char a;
int NL1; int NL2; int NL3; int NL4;
int TotalG;
int MaxG;

void mainMenu(){//ISABELLA VICHITA KACARIBU (1301154637)//
    int pil = 0;
    while (pil != 8){
            hoho:
    system("cls");
    cout << "===Selamat Datang di Program Sekolah===" << endl;
    cout << "Pilihan Menu:" << endl;
    cout << "1. Input Data" << endl;
    cout << "2. Search & View" << endl;
    cout << "3. Search & Edit" << endl;
    cout << "4. Search & Delete" << endl;
    cout << "5. View" << endl;
    cout << "6. Keterangan Guru" << endl;
    cout << "7. Keterangan Siswa" << endl;
    /*cout << "8. sorting" << endl;*/
    cout << endl;
    cout << "Tentukan Pilihan Anda:" << endl; cin >> pil;

    switch(pil){
        case 1 :
            system("cls");
            int pil;
                hihi:
                cout << "INSERT DATA" <<endl; cout <<endl;
                cout << "1. Insert Guru" <<endl;
                cout << "2. Insert Siswa"<<endl; cout <<endl;
                cout << "Masukkan Pilihan Anda = ";cin >> pil;
                if (pil == 1){//ISABELLA VICHITA KACARIBU (1301154637)//
                    system("cls");
                    address_parent P1;
                    char y;
                    do{
                    cout <<"ISILAH DATA-DATA BERIKUT"<<endl;cout <<endl;
                    cout <<"NIP guru               : "; cin >> x1.NIP  ;
                    cout <<"Nama Guru              : "; cin >> x1.NamaG  ;
                    cout <<"Alamat Guru            : "; cin >> x1.AlamatG ;
                    cout <<"Kategori Guru          : "; cin >> x1.KategoriG ;
                    cout <<"Bidang Guru            : "; cin >> x1.BidangAjar ;
                    cout <<"Kelas 10               : "; cin >> x1.JumlahKelas1 ;
                    cout <<"Kelas 11               : "; cin >> x1.JumlahKelas2 ;
                    cout <<"Kelas 12               : "; cin >> x1.JumlahKelas3 ;cout << endl;

                    P1 = alokasi(x1);
                    insertposisi(L1,P1);
                    printInfo(L1);
                    cout << "Jika ingin menambah, Silahkan ketik =y= dan jika tidak, silahkan ketik =n="<<endl;
                    cin >> y ;
                    if (y == 'n')
                        goto hihi;
                    }while (y!= 'n');
                }
                else if (pil == 2){//ARLI MUTIARA GUSRIYANTI (1301154538)//
                    system("cls");
                    address_child P2;
                    address_parent P1;
                    infotype_parent x;
                    do{
                    cout << "Masukkan NIP Guru : "; cin >> x1.NIP;
                    P1 = findElm(L1,x1);
                    cout<<"=====ISILAH DATA-DATA BERIKUT====="<<endl; cout <<endl;
                    cout<<"NIS siswa                : "; cin >> x2.NIS ;
                    cout<<"Nama siswa               : "; cin >> x2.NamaS ;
                    cout<<"Alamat Siswa             : "; cin >> x2.AlamatS ;
                    cout<<"Kategori Siswa           : "; cin >> x2.KategoriS ;
                    cout<<"Jurusan Siswa            : "; cin >> x2.Jurusan ;
                    cout<<"Nilai Siswa Ujian 1      : "; cin >> x2.Nilai1 ;
                    cout<<"Nilai Siswa Ujian 2      : "; cin >> x2.Nilai2 ;
                    cout<<"Nilai Siswa Ujian 3      : "; cin >> x2.Nilai3 ;cout<<endl;
                    cout<<"=====DATA SUDAH TERSIMPAN====="<<endl; cout<<endl;
                    P2 = alokasi(x2);
                    address_child A = findElm(child(P1),x2);
                    if (A != NULL){
                        info(A) = x2;
                    } else{
                    insertFirst(child(P1),P2);
                    }
                    printInfo(child(P1));
                    cout << "Jika ingin menambah, Silahkan ketik =y= dan jika tidak, silahkan ketik =n="<<endl; cout<<endl;
                    cin >> y ;
                    if (y == 'n')
                        goto hoho;
                    }while (y!= 'n');
                }
        case 2 ://ISABELLA VICHITA KACARIBU (1301154637)//
            system("cls");
            cout<< "Masukkan NIP Guru: ";
            cin >> x1.NIP;
            P1 = findElm(L1, x1);
            L2 = child(P1);

            P2 = first(L2);
            cout<< P2;
            if (P1 != NULL){
            cout <<"=====ISI DARI PENCARIAN====="<<endl; cout<<endl;
            cout <<"NIP GURU                 = " <<P1 ->info.NIP <<endl;
            cout <<"NAMA GURU                = " <<P1 ->info.NamaG<<endl;
            cout <<"ALAMAT GURU              = " <<P1 ->info.AlamatG<<endl;
            cout <<"KATEGORI GURU            = " <<P1 ->info.KategoriG<<endl;
            cout <<"BIDANG AJAR GURU         = " <<P1 ->info.BidangAjar<<endl;
            cout <<"Kelas 10                 = " <<P1 ->info.JumlahKelas1<<endl;
            cout <<"Kelas 11                 = " <<P1 ->info.JumlahKelas2<<endl;
            cout <<"Kelas 12                 = " <<P1 ->info.JumlahKelas3<<endl;
            printInfo(child(P1));
            cout <<"=====TERIMAKASIH====="<<endl;
            getch();
            }
        break;
        case 3 ://ARLI MUTIARA GUSRIYANTI (1301154538)// & //ISABELLA VICHITA KACARIBU (1301154637)//
            system("cls");
            cout<< "Masukkan NIP yang ingin diubah : ";
            cin >> x1.NIP;
            P1 = findElm(L1, x1);
            if (P1 == NULL){
                cout <<"Maaf NIP tidak ditemukan"<<endl;
            } else{
            cout <<"===DATA LAMA==="<<endl; cout<<endl;
            cout <<"NIP GURU                 = " <<P1 ->info.NIP <<endl;
            cout <<"NAMA GURU                = " <<P1 ->info.NamaG<<endl;
            cout <<"ALAMAT GURU              = " <<P1 ->info.AlamatG<<endl;
            cout <<"KATEGORI GURU            = " <<P1 ->info.KategoriG<<endl;
            cout <<"BIDANG AJAR GURU         = " <<P1 ->info.BidangAjar<<endl;
            cout <<"Kelas 10                 = " <<P1 ->info.JumlahKelas1<<endl;
            cout <<"Kelas 11                 = " <<P1 ->info.JumlahKelas2<<endl;
            cout <<"Kelas 12                 = " <<P1 ->info.JumlahKelas3<<endl; cout <<endl;
            printInfo(child(P1));
            cout <<"NIS siswa                : "; cin >> x2.NIS ;
            cout <<"Nama siswa               : "; cin >> x2.NamaS ;
            cout <<"Alamat Siswa             : "; cin >> x2.AlamatS ;
            cout <<"Kategori Siswa           : "; cin >> x2.KategoriS ;
            cout <<"Jurusan Siswa            : "; cin >> x2.Jurusan ;
            cout <<"Nilai Siswa Ujian 1      : "; cin >> x2.Nilai1 ;
            cout <<"Nilai Siswa Ujian 2      : "; cin >> x2.Nilai2 ;
            cout <<"Nilai Siswa Ujian 3      : "; cin >> x2.Nilai3 ; cout <<endl;
            }
        break;

    case 4 ://ARLI MUTIARA GUSRIYANTI (1301154538)//
        system("cls");
        cout<< "Masukkan NIP Guru: ";
        cin >> x1.NIP;
        P1 = findElm(L1, x1);


        if(P1 != NULL){
             deleteposisi(L1, P1);
             cout<<"TERIMAKASIH";
        }else{
            cout<<"Data Tidak DItemukan";
        }
        getch();
    break;
    case 5 ://ARLI MUTIARA GUSRIYANTI (1301154538)//
        system("cls");
        P1 = first(L1);
        if(P1 != NULL){
        printInfo(L1);
        }else{
           cout<<"Data Kosong";
        }
        getch();
    break;

    case 6 ://ISABELLA VICHITA KACARIBU (1301154637)//
        system("cls");
        haha:
        cout << "KETERANGAN GURU" <<endl; cout <<endl;
        cout << "1. Jumlah Kelas Perguru" <<endl;
        cout << "2. jumlah Kelas paling banyak"<<endl; cout <<endl;
        cout << "Masukkan Pilihan Anda = ";cin >> pil; cout <<endl;
        if ( pil == 1){//ARLI MUTIARA GUSRIYANTI (1301154538)//
            system("cls");
            address_child P2;
            address_parent P1;
            infotype_parent x;

            do{
            cout << "Masukkan NIP Guru : "; cin >> x1.NIP;
            P1 = findElm(L1,x1);
            cout <<"=====ISI DARI PENCARIAN====="<<endl; cout<<endl;
            cout <<"NIP GURU                 = " <<P1 ->info.NIP<<endl;
            cout <<"NAMA GURU                = " <<P1 ->info.NamaG<<endl;
            cout <<"ALAMAT GURU              = " <<P1 ->info.AlamatG<<endl;
            cout <<"KATEGORI GURU            = " <<P1 ->info.KategoriG<<endl;
            cout <<"BIDANG AJAR GURU         = " <<P1 ->info.BidangAjar<<endl;
            cout <<"Kelas 10                 = " <<P1 ->info.JumlahKelas1<<endl;
            NL1 = P1 ->info.JumlahKelas1;
            cout <<"Kelas 11                 = " <<P1 ->info.JumlahKelas2<<endl;
            NL2 = P1 ->info.JumlahKelas1;
            cout <<"Kelas 12                 = " <<P1 ->info.JumlahKelas3<<endl;
            NL3 = P1 ->info.JumlahKelas1;
            NL4 = NL1+NL2;
            TotalG = NL4+NL3;
            cout <<"Jumlah Kelas Perguru     = " <<TotalG; cout<<endl;
            goto haha;
            }while (y!= 'n');
        }
        else if (pil == 2){//ISABELLA VICHITA KACARIBU (1301154637)//
            system("cls");
            address_child P2;
            address_parent P1;
            infotype_parent x;
            int MaxG;
            do{
            cout << "Masukkan NIP Guru : "; cin >> x1.NIP;
            P1 = findElm(L1,x1);
            cout <<"=====ISI DARI PENCARIAN====="<<endl; cout<<endl;
            cout <<"NIP GURU                 = " <<P1 ->info.NIP<<endl;
            cout <<"NAMA GURU                = " <<P1 ->info.NamaG<<endl;
            cout <<"ALAMAT GURU              = " <<P1 ->info.AlamatG<<endl;
            cout <<"KATEGORI GURU            = " <<P1 ->info.KategoriG<<endl;
            cout <<"BIDANG AJAR GURU         = " <<P1 ->info.BidangAjar<<endl;
            cout <<"Kelas 10                 = " <<P1 ->info.JumlahKelas1<<endl;
            NL1 = P1 ->info.JumlahKelas1;
            cout <<"Kelas 11                 = " <<P1 ->info.JumlahKelas2<<endl;
            NL2 = P1 ->info.JumlahKelas1;
            cout <<"Kelas 12                 = " <<P1 ->info.JumlahKelas3<<endl;
            NL3 = P1 ->info.JumlahKelas1;
            if ( P1 != 0){
            if (NL1>NL2 && NL1>NL3){
                MaxG = NL1;
                cout <<"Jumlah Kelas Paling Banyak     = " <<MaxG<<endl;

            } else if (NL2>NL1 && NL2>NL3){
                MaxG = NL1;
                cout <<"Jumlah Kelas Paling Banyak     = " <<MaxG<<endl;

            } else if (NL3>NL1 && NL3>NL2){
                MaxG = NL1;
                cout <<"Jumlah Kelas Paling Banyak     = " <<MaxG<<endl;

            }
            }
            if (y == 'n')
                goto haha;
            }while (y!= 'n');
        }
    break;
    /*case 7 : Reporting Siswa();
    break;*/

    /*case 8 : Sorting();
    break;
    }
    }
    }**/
}
}
}
