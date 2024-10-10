#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct bunga {
    int kode;
    string nama;
    string warna;
    double harga;
    int stock;
    string asal;
};

struct node {
    bunga flower;
    node *next;
    node *prev;
};

struct node *stackhead = nullptr;
struct node *stacklast = nullptr;

struct node *queuehead = nullptr;
struct node *queuelast = nullptr;

bool stackkosong(){
    return stackhead == nullptr;
};

// -------------------- STACK ---------------------
void tambah_bunga_push(){
    bunga newflower;
    cout<<"Masukkan kode bunga: "<<endl;
    cin>>newflower.kode;
    cout<<"Masukkan nama bunga: "<<endl;
    cin>>newflower.nama;
    cout<<"Masukkan warna bunga: "<<endl;
    cin>>newflower.warna;
    cout<<"Masukkan harga bunga: "<<endl;
    cin>>newflower.harga;
    cout<<"Masukkan stock bunga: "<<endl;
    cin>>newflower.stock;
    cout<<"Masukkan asal bunga: "<<endl;
    cin>>newflower.asal;

    node *baru = new node;
    baru->flower = newflower;
    baru->next =nullptr;

    if(stackkosong()){
        baru->prev = nullptr;
        stackhead = baru;
        stacklast = baru;
    } else {
        baru->prev = stacklast;
        stacklast->next = baru;
        stacklast = baru;
    }
    cout << "Data bunga berhasil ditambahkan ke stack" << endl;
};

void lihat_bunga_peek(){
    if(stackkosong()){
        cout << "Stack Underflow" << endl;
        return;
    } else {
        cout << "detail bunga terakhir: " << endl;
        cout << "Kode bunga: " << stacklast->flower.kode << endl;
        cout << "Nama bunga: " << stacklast->flower.nama << endl;
        cout << "Warna bunga: " << stacklast->flower.warna << endl;
        cout << "Harga bunga: " << stacklast->flower.harga << endl;
        cout << "Stock bunga: " << stacklast->flower.stock << endl;
        cout << "Asal bunga: " << stacklast->flower.asal << endl;

    }
};

void tampilkan_bunga_show(){
    if(stackkosong()){
        cout << "Stack Underflow" << endl;
        return;
    } else {
        node *temp = stackhead;
        int urutan = 1;
    while(temp != nullptr) {
    cout <<"\nData bunga ke- "<< urutan << ":" <<endl;
    cout << "Kode: " << temp->flower.kode <<endl;
    cout << "Nama: " << temp->flower.nama <<endl;
    cout << "Warna: " << temp->flower.warna <<endl;
    cout << "Harga: " << temp->flower.harga <<endl;
    cout << "Stock: " << temp->flower.stock <<endl;
    cout << "Asal: " << temp->flower.asal <<endl;
    temp = temp->next;
    urutan++;
        }
    }
};

void hapus_bunga_pop(){
    if(stackkosong()){
        cout << "Stack Underflow" << endl;
        return;
    } else if (stackhead == stacklast){
        delete stackhead;
        stackhead = nullptr;
        stacklast = nullptr;
    } else {
        node *temp = stacklast;
        stacklast = stacklast->prev;
        stacklast->next = nullptr;
        delete temp;
        cout << "Data bunga berhasil dihapus dari stack" << endl;
    }
};

void ubah_bunga_stack(){
    if(stackkosong()){
        cout << "Stack Kosong! Tidak ada data untuk diubah" << endl;
        return;
    }
    int kode;
    cout << "/n----------Data Bunga----------" << endl;
    tampilkan_bunga_show();

    cout << "masukkan kode bunga yang ingin diubah: " << endl;
    cin >> kode;

    node *temp = stackhead;

    while(temp != nullptr && temp->flower.kode != kode){
        temp = temp->next;
    }

    if (temp != nullptr){
        cout << "Data Bunga Ditemukan. Masukkan Data Baru: " << endl;
        cout<<"Masukkan nama bunga: "<<endl;
        cin>>temp->flower.nama;
        cout<<"Masukkan warna bunga: "<<endl;
        cin>>temp->flower.warna;
        cout<<"Masukkan harga bunga: "<<endl;
        cin>>temp->flower.harga;
        cout<<"Masukkan stock bunga: "<<endl;
        cin>>temp->flower.stock;
        cout<<"Masukkan asal bunga: "<<endl;
        cin>>temp->flower.asal;

        cout << "Data bunga berhasil diubah!" << endl;
    } else {
        cout << "Data bunga tidak ditemukan!" << endl;
    }
};


// ------------------------- QUEUE --------------------------
bool queuekosong(){
    return queuehead == nullptr;
};

void tambah_bunga_enqueue(){
    bunga newflower;
    cout<<"Masukkan kode bunga: "<<endl;
    cin>>newflower.kode;
    cout<<"Masukkan nama bunga: "<<endl;
    cin>>newflower.nama;
    cout<<"Masukkan warna bunga: "<<endl;
    cin>>newflower.warna;
    cout<<"Masukkan harga bunga: "<<endl;
    cin>>newflower.harga;
    cout<<"Masukkan stock bunga: "<<endl;
    cin>>newflower.stock;
    cout<<"Masukkan asal bunga: "<<endl;
    cin>>newflower.asal;

    node *baru = new node;
    baru->flower= newflower;
    baru->next = nullptr;

    if(queuekosong()){
        baru->prev = nullptr;
        queuehead = baru;
        queuelast = baru;
    } else {
        baru->prev = queuelast;
        queuelast->next = baru;
        queuelast = baru;
    }
    cout << "Data bunga berhasil ditambahkan ke queue" << endl;
    };

void hapus_bunga_dequeue(){
    if(queuekosong()){
        cout << "Queue Underflow" << endl;
        return;
    } else if (queuehead == queuelast){
        delete queuehead;
        queuehead = nullptr;
        queuelast = nullptr;
    } else {
        node *temp = queuehead;
        queuehead = queuehead->next;
        queuehead->prev = nullptr;
        delete temp;
        cout << "Data bunga berhasil dihapus dari queue" << endl;
    }
};

void tampil_bunga_show_queue(){
    if (queuekosong()){
        cout << "Queue Underflow" << endl;
        return;
    } else {
        node *temp = queuehead;
        while(temp != nullptr){
            cout << "\nData Bunga:" << endl;
            cout << "Kode: " << temp->flower.kode << endl;
            cout << "Nama: " << temp->flower.nama << endl;
            cout << "Warna: " << temp->flower.warna << endl;
            cout << "Harga: " << temp->flower.harga << endl;
            cout << "Stock: " << temp->flower.stock << endl;
            cout << "Asal: " << temp->flower.asal << endl;
            temp = temp->next;
        }
    }
};

void ubah_bunga_queue(){
    if(queuekosong()){
        cout << "Queue Underflow" << endl;
        return;
    }
    int kode;
    cout << "/n----------Data Bunga----------" << endl;
    tampil_bunga_show_queue();

    cout << "masukkan kode bunga yang ingin diubah: " << endl;
    cin >> kode;

    node *temp = queuehead;

    while(temp != nullptr && temp->flower.kode != kode){
        temp = temp->next;
    }
    if (temp != nullptr){
        cout << "Data Bunga Ditemukan. Masukkan Data Baru: " << endl;
        cout<<"Masukkan nama bunga: "<<endl;
        cin>>temp->flower.nama;
        cout<<"Masukkan warna bunga: "<<endl;
        cin>>temp->flower.warna;
        cout<<"Masukkan harga bunga: "<<endl;
        cin>>temp->flower.harga;
        cout<<"Masukkan stock bunga: "<<endl;
        cin>>temp->flower.stock;
        cout<<"Masukkan asal bunga: "<<endl;
        cin>>temp->flower.asal;
        cout << "Data bunga berhasil diubah!" << endl;
    } else {
        cout << "Data bunga tidak ditemukan!" << endl;
    }
};


int main(){
    int pilihstack, pilihqueue;
    do{
        system("cls");
        cout<<"-----Manajemen Toko Bunga-----"<<endl;
        cout<<"1. Menu Stack"<<endl;
        cout<<"2. Menu Queue"<<endl;
        cout<<"3. Keluar"<<endl;
        cout<<"Pilih Menu: "<<endl;
        cin>>pilihstack;

        switch(pilihstack){
            case 1:
                do{
                    system("cls");
                    cout<<"-----Menu Stack-----"<<endl;
                    cout<<"1. Tambah Data Bunga (Push)"<<endl;
                    cout<<"2. Hapus Data Bunga (Pop)"<<endl;
                    cout<<"3. Tampilkan Data Bunga Terakhir (Peek)"<<endl;
                    cout<<"4. Tampilkan Semua Data Bunga (Show)"<<endl;
                    cout<<"5. Update Data Bunga"<<endl;
                    cout<<"6. Kembali"<<endl;
                    cout<<"Pilih Operasi Stack: "<<endl;
                    cin>>pilihstack;

                    switch(pilihstack){
                        case 1:
                            tambah_bunga_push();
                            break;
                        case 2:
                            hapus_bunga_pop();
                            break;
                        case 3:
                            lihat_bunga_peek();
                            break;
                        case 4:
                            tampilkan_bunga_show();
                            break;
                        case 5:
                            ubah_bunga_stack();
                            break;
                        case 6:
                            cout<<"Kembali ke Menu Utama"<<endl;
                            break;

                        default:
                            cout<<"Pilihan Tidak Ada!"<<endl;
                            break;

                    }
                } while (pilihstack != 0);
                break;

            case 2:
                do {
                    system("cls");
                    cout<<"-----Menu Queue-----"<<endl;
                    cout<<"1. Tambah Data Bunga (Enqueue)"<<endl;
                    cout<<"2. Hapus Data Bunga (Dequeue)"<<endl;
                    cout<<"3. Tampilkan  Semua Data Bunga"<<endl;
                    cout<<"4. Update Data Bunga"<<endl;
                    cout<<"5. Kembali"<<endl;
                    cout<<"Pilih Operasi Queue: "<<endl;
                    cin>>pilihqueue;

                    switch(pilihqueue){
                        case 1:
                            tambah_bunga_enqueue();
                            break;
                        case 2:
                            hapus_bunga_dequeue();
                            break;
                        case 3:
                            tampil_bunga_show_queue();
                            break;
                        case 4:
                            ubah_bunga_queue();
                            break;
                        case 5:
                            cout<<"Kembali ke Menu Utama"<<endl;
                            break;

                        default:
                        cout<<"Pilihan Tidak Ada!"<<endl;
                            break;
                    }
                } while (pilihqueue != 0);
                break;

            case 5:
                cout << "Terima kasih telah menggunakan aplikasi ini." << endl;
                break;

            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
        }
    } while (pilihstack != 0);
    
    return 0;
}