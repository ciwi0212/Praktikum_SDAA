#include <iostream>
using namespace std;

void menaraHanoi (int n,  char tower_asal, char tower_tujuan, char tower_bantu) {

    // jika hanya ada 1 disk
    if (n == 1) {
        cout << "Pindahkan disk 1 dari tower " << tower_asal;
        cout << " ke tower " << tower_tujuan << endl;
        return;
    }

    //jika terdapat lebih dari 1 disk
    //pindahkan disk dari tower asal ke tower tujuan 
    menaraHanoi (n - 1, tower_asal, tower_bantu, tower_tujuan);
    cout << "Pindahkan disk " << n << " dari tower " << tower_asal;
    cout << " ke tower " << tower_tujuan << endl;

    //pindahkan disk dari tower bantu ke tower tujuan
    menaraHanoi (n - 1, tower_bantu, tower_tujuan, tower_asal); 
}

int main(){
    int n = 3; //n = disk
    menaraHanoi(n, 'A', 'C', 'B');
    return 0;
}