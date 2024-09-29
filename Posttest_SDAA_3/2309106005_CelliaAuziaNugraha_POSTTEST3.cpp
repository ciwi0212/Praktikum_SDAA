#include <iostream>
#include <string>
using namespace std;

struct bunga {
    int kode;
    string nama;
    string warna;
    double harga;
    int stock;
    string asal;
    bunga *next;
};

void tambah_bunga(bunga *&head){
    bunga *newBunga = new bunga;
    cout<<"Masukkan kode bunga: "<<endl;
    cin>>newBunga->kode;
    cout<<"Masukkan nama bunga: "<<endl;
    cin>>newBunga->nama;
    cout<<"Masukkan warna bunga: "<<endl;
    cin>>newBunga->warna;
    cout<<"Masukkan harga bunga: "<<endl;
    cin>>newBunga->harga;
    cout<<"Masukkan stock bunga: "<<endl;
    cin>>newBunga->stock;
    cout<<"Masukkan asal bunga: "<<endl;
    cin>>newBunga->asal;

    if (head == nullptr){
        newBunga->next = nullptr;
        head = newBunga;
        return;
    }

    newBunga->next = head;
    head = newBunga;

    cout<<"Bunga berhasil ditambahkan!"<<endl;
};

void tampilkan_bunga(bunga *head){
    bunga *temp = head;
    int count = 1;

    if (temp == nullptr){
        cout<<"Data Bunga Tidak Ada"<<endl;
        return;
    }

    while (temp != nullptr){
        cout<<"\nData Bunga: \n"<<count<<endl;
        cout<<"Kode baru: "<<temp->kode<<endl;
        cout<<"Nama baru: "<<temp->nama<<endl;
        cout<<"Warna baru: "<<temp->warna<<endl;
        cout<<"Harga baru: "<<temp->harga<<endl;
        cout<<"Stock baru: "<<temp->stock<<endl;
        cout<<"Asal baru: "<<temp->asal<<endl;

        count += 1;
        temp = temp->next;
    }
};

void ganti_bunga(bunga *&head){
    int kode;
    tampilkan_bunga(head);

    bunga *temp = head;

    cout<<"Masukkan kode bunga: "<<endl;
    cin>>kode;

    while (temp->kode != kode){
        temp = temp->next;
    }

    cout<<"Data bunga ditemukan: "<<endl;
    cout<<"Masukkan nama bunga: "<<endl;
    cin>>temp->nama;
    cout<<"Masukkan warna bunga: "<<endl;
    cin>>temp->warna;
    cout<<"Masukkan harga bunga: "<<endl;
    cin>>temp->harga;
    cout<<"Masukkan stock bunga: "<<endl;
    cin>>temp->stock;
    cout<<"Masukkan asal bunga: "<<endl;
    cin>>temp->asal;
};

void hapus_bunga(bunga *&head){
    bunga *temp = head;
    head = head->next;
    delete temp;
};

int main(){
    int pilih;
    bunga *head = nullptr;

    do {
        cout<<"-----Manajemen Toko Bunga-----"<<endl;
        cout<<"1. Tambah Bunga"<<endl;
        cout<<"2. Tampilkan Data Bunga"<<endl;
        cout<<"3. Update Data Bunga"<<endl;
        cout<<"4. Hapus Data Bunga"<<endl;
        cout<<"5. Keluar"<<endl;
        cout<<"Pilih Menu (1-5): "<<endl;
        cin>>pilih;

    switch (pilih){
        case 1:
            tambah_bunga(head);
            break;
        case 2:
            tampilkan_bunga(head);
            break;
        case 3:
            ganti_bunga(head);
            break;
        case 4:
            hapus_bunga(head);
            break;
        case 5:
            cout<<"Keluar dari program"<<endl;
            break;

            default:
            cout<<"Pilihan tidak tersedia"<<endl;
    }
    } while (pilih != 5);
    return 0;
};