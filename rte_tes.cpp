#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

vector<string> split_string(const string& input) {
    vector<string> splitted_string;
    stringstream ss(input);
    string token;

    while(ss >> token) {
        splitted_string.push_back(token);
    }

    return splitted_string;
}

vector<int> vector_generator(const int& input) {
    vector<int> result;
    for(int i = 1;i <= input;i++) {
        result.push_back(i);
    }

    return result;
}

void cek_hadiah_yang_di_ambil(vector<int> N_vector, int X, int Y) {
    int banyak_hadiah_budi = 0;
    int banyak_hadiah_dono = 0;
    for(int i : N_vector) {
        if(i % X == 0 && i % Y == 0) {
            continue;
        } else if (i % X == 0) {
            banyak_hadiah_budi++;
        } else if (i % Y == 0) {
            banyak_hadiah_dono++;
        }
    }
    cout << banyak_hadiah_budi << " " << banyak_hadiah_dono << endl;
}

int main() {
    int Q;
    int N, X,Y;
    string jawaban;
    vector<string> jawaban_vector;
    vector<int> N_vector;

    cin >> Q;
    cin.ignore();
    for(int i = Q;i > 0;i--){
        getline(cin, jawaban);
        jawaban_vector = split_string(jawaban);
        N = stoi(jawaban_vector[0]);
        X = stoi(jawaban_vector[1]);
        Y = stoi(jawaban_vector[2]);
        N_vector = vector_generator(N);
        cek_hadiah_yang_di_ambil(N_vector,X,Y);
    }
    return 0;
}