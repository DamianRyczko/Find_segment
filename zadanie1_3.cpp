#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int vec_sum(vector<int> seg){
    int sum{0};
    for(int i = 0; i < seg.size(); i++){
        sum = sum + seg[i];
    }
    return sum;
}

int find_max_sum_segment(vector<int> vec){
    int max_sum = vec[0];

    for(int a = 0; a<vec.size(); a++){
        vector<int> segment{0};

        for(int j = a; j< vec.size(); j++){
            segment.push_back(vec[j]);
            int sum = vec_sum(segment);

            if(sum > max_sum){
                max_sum = sum;
                // cout << "now max wartosc: " << max_sum << " dla przedialu od "<< a << " do "<< j + 1 << endl;
            }
        }
    }
    return max_sum;
}

vector<int> read_file(string path){
    fstream input_file;
    input_file.open(path, ios::in);
    if(!input_file.good()){
        cout << "File does not exist!";
    }

    int liczba;
    vector<int> vec{};
    while (input_file >> liczba){
        vec.push_back(liczba);
    }

    input_file.close();

    return vec;
}

void test(string path, int expected_result){
    int max_sum = find_max_sum_segment(read_file(path));
    if(max_sum == expected_result)
        cout << "POPRAWNY " << " plik: " << path << " oczekiwano:" << expected_result << " obliczono:" << max_sum << endl;
    else
        cout << "BŁĘDNY " << " plik: " << path << " oczekiwano:" << expected_result << " obliczono:" << max_sum << endl;
}

int main(){
    // vector<int> vec = read_file("dane1_3.txt");
    // int max_sum = find_max_sum_segment(vec);
    // cout << "Max wartosc sehmentu to: " << max_sum;

    test("test_1.txt", 1);
    test("test_2.txt", 2);
    test("test_3.txt", 3);
    test("test_4.txt", 13);
    test("test_5.txt", -1);
    test("test_6.txt", 0);

    cin.get();

    return 0;
}
