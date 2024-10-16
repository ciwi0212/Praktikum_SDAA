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
};

struct node {
    bunga flower;
    node *next;
    node *prev;
};

node *stackhead = nullptr;
node *stacklast = nullptr;

node *queuehead = nullptr;
node *queuelast = nullptr;

const int jmlh_bunga = 6;
bunga arrBunga[jmlh_bunga] = {
    {101, "Mawar", "Merah", 50000, 10, "Eropa"},
    {102, "Melati", "Putih", 40000, 20, "Himalaya"},
    {103, "Tulip", "Kuning", 60000, 15, "Turki"},
    {104, "Anggrek", "Ungu", 75000, 5, "Indonesia"},
    {105, "Sakura", "Biru", 85000, 12, "Jepang"},
    {106, "Lily", "Biru", 19000, 20, "Eropa"}
};

bool stackkosong(){
    return stackhead == nullptr;
};

// -------------------- STACK ---------------------
void tambah_bunga_push(){
    int pilih;
    cout << "Daftar Bunga Yang Tersedia: " << endl;
    for(int i=0; i < jmlh_bunga; i++){
        cout << i+1 << ". " << arrBunga[i].nama << " - Rp" << arrBunga[i].harga << endl;
    }
    cout << "Pilih bunga yang ingin ditambahkan ke dalam stack (1-6): ";
    cin >> pilih;

    if(pilih < 1 || pilih > jmlh_bunga){
        cout << "Pilihan tidak ada dalam daftar!" << endl;
        return;
    }

    node *baru = new node;
    baru->flower = arrBunga[pilih - 1];
    baru->next = nullptr;

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
    } 

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
    };

void hapus_bunga_pop(){
    if(stackkosong()){
        cout << "Stack Underflow" << endl;
        return;
    }
    if (stackhead == stacklast){
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
    int pilih;
    cout << "Daftar bunga yang tersedia: " << endl;
    for(int i = 0; i < jmlh_bunga; i++){
        cout << i+1 << ". " << arrBunga[i].nama << " - Rp" << arrBunga[i].harga << endl;
    }
    cout << "Pilih bunga yang ingin ditambahkan ke queue (1-5): ";
    cin >> pilih;

    if(pilih < 1 || pilih > jmlh_bunga){
        cout << "Pilihan tidak tersedia!" << endl;
        return;
    }

    node *baru = new node;
    baru->flower= arrBunga[pilih - 1];
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
    } 
    if (queuehead == queuelast){
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

// ---------------------SORTING--------------------------
node* getMiddle(node* head){
    if(head == nullptr) return head;
    node* slow = head;
    node* fast = head->next;

    while(fast != nullptr){
        fast = fast->next;
        if(fast != nullptr){
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
};

node* sortedmerge(node* a, node* b, bool descending){
    if (!a) return b;
    if (!b) return a;

    node* result = nullptr;

    if(!descending){
        if (a->flower.harga <= b->flower.harga){
            result = a;
            result->next = sortedmerge(a->next, b, descending);
            if(result->next) result->next->prev = result;
        } else {
            result = b;
            result->next = sortedmerge(a, b->next, descending);
            if(result->next) result->next->prev = result;
        }
    } else {
        if (a->flower.harga >= b->flower.harga){
        result = a;
        result->next = sortedmerge(a->next, b, descending);
        if(result->next) result->next->prev = result;
    } else {
        result = b;
        result->next = sortedmerge(a, b->next, descending);
        if(result->next) result->next->prev = result;
        }            
    }
    return result;
};

void mergesort(node*& head, bool descending = false){
    if(!head || !head->next) return;

    node* middle = getMiddle(head);
    node* nextofmiddle = middle->next;

    middle->next = nullptr;
    if(nextofmiddle) nextofmiddle->prev = nullptr;

    mergesort(head, descending);
    mergesort(nextofmiddle, descending);

    head = sortedmerge(head, nextofmiddle, descending);
};

node* partition(node* low, node* high, bool descending){
    double pivot = high->flower.harga;
    node* i = low->prev;

    for(node* j = low; j != high; j->next){
        if((! descending && j->flower.harga <= pivot) || (! descending && j->flower.harga >= pivot)){
            i = (i == nullptr) ? low : i->next;
            swap(i->flower, j->flower);
        }
    }
    i = (i == nullptr) ? low : i->next;
    swap(i->flower, high->flower);
    return i;
};

void quicksort(node* low, node* high, bool descending = false){
    if(high != nullptr && low != high && low != high->next){
        node* pivot = partition(low, high, descending);
        quicksort(low, pivot->prev, descending);
        quicksort(pivot->next, high, descending);
    }
};

void showsortstack() {
    if (stackkosong()) {
        cout << "Stack kosong!" << endl;
        return;
    }

    node* temp = stackhead;
    cout << "Bunga di stack setelah diurutkan: " << endl;
    while (temp != nullptr) {
        cout << temp->flower.nama << " - Harga: " << temp->flower.harga << endl;
        temp = temp->next;
    }
};

void showsortqueue() {
    if (queuekosong()) {
        cout << "Queue kosong!" << endl;
        return;
    }

    node* temp = queuehead;
    cout << "Bunga di queue setelah diurutkan: " << endl;
    while (temp != nullptr) {
        cout << temp->flower.nama << " - Harga: " << temp->flower.harga << endl;
        temp = temp->next;
    }
};

void sortstackmerge(bool descending = false) {
    mergesort(stackhead, descending);
    showsortstack();
};

void sortqueuequick(bool descending = false) {
    if (!queuekosong()) {
        quicksort(queuehead, queuelast, descending);
        showsortqueue();
    }
};

int main(){
   int pilihan;
   do{
        cout<<"-----Manajemen Toko Bunga-----"<<endl;
        cout<<"1. Menu Stack"<<endl;
        cout<<"2. Menu Queue"<<endl;
        cout<<"3. Keluar"<<endl;
        cout<<"Pilih Menu: "<<endl;
        cin>>pilihan;

        switch(pilihan){
            case 1: {
                int pilihstack;
                do{
                    cout<<"-----Menu Stack-----"<<endl;
                    cout<<"1. Tambah Data Bunga (Push)"<<endl;
                    cout<<"2. Hapus Data Bunga (Pop)"<<endl;
                    cout<<"3. Tampilkan Data Bunga Terakhir (Peek)"<<endl;
                    cout<<"4. Tampilkan Semua Data Bunga (Show)"<<endl;
                    cout<<"5. Update Data Bunga"<<endl;
                    cout<<"6. Sorting Bunga (Ascending)"<<endl;
                    cout<<"7. Kembali"<<endl;
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
                            sortstackmerge();
                            break;
                        case 7:
                            cout<<"Kembali ke Menu Utama"<<endl;
                            break;
                        default:
                            cout<<"Pilihan Tidak Ada!"<<endl;
                            break;
                    }
                } while(pilihstack != 0);
                break;
            }
            case 2: {
                int pilihqueue;
                do{
                    cout<<"-----Menu Queue-----"<<endl;
                    cout<<"1. Tambah Data Bunga (Enqueue)"<<endl;
                    cout<<"2. Hapus Data Bunga (Dequeue)"<<endl;
                    cout<<"3. Tampilkan  Semua Data Bunga"<<endl;
                    cout<<"4. Update Data Bunga"<<endl;
                    cout<<"5. Sorting Bunga (Descending)"<<endl;
                    cout<<"6. Kembali"<<endl;
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
                            sortqueuequick();
                            break;
                        case 6:
                            cout<<"Kembali ke Menu Utama"<<endl;
                            break;

                        default:
                        cout<<"Pilihan Tidak Ada!"<<endl;
                            break;
                    }
                } while(pilihqueue != 0);
                break;
            }
            case 6:
                cout << "Keluar dari program" << endl;
                break;

            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
        }    
   } while(pilihan != 0);

   return 0; 
}