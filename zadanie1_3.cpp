#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int segment_value(vector<int> seg){
    int suma{0};
    for(int i = 0;i<=seg.size()-1;i++){
        suma = suma + seg[i];
    }
    return suma;
}
int find_segments(vector<int> tab){
    int suma;
    int suma_max = tab[0];

    for(int a=0;a<=tab.size()-1;a++){
        vector<int> segment{0};

        for(int j = a;j<=tab.size()-1;j++){
             segment.push_back(tab[j]);
            suma = segment_value(segment);

                 if(suma>suma_max){
                    suma_max=suma;
                    cout<<"now max wartosc: "<<suma_max<<" dla przedialu od "<<a<<" do "<<j<<endl;
                 }
        }

    }
    return suma_max;
}

int main(){
    fstream input_file;

    input_file.open("dane1_3.txt", ios::in);
        if(input_file.good()==false){
            cout<<"File does not exist!";
            return 0;
        }

    int liczba;
    vector<int> table{};

    while (input_file >> liczba){
        table.push_back(liczba);
    }
    input_file.close();

    int suma_max = find_segments(table);

    cout<<"Max wartosc sehmentu to: "<<suma_max;

    return 0;
}