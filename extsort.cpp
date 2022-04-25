#include <bits/stdc++.h>
using namespace std;


void merge(vector<vector<int>> &file, vector<int> &temp){
    vector<int> pointer;
    int min, k, i, j,num = 0;

    for (i = 0; i < file.size(); i++){
        pointer.push_back(0);
        num += file[i].size();
    }
    for (i = 0; i < num; i++){
        min = INT_MAX;
        k = 0;

        for (j = 0; j < pointer.size(); j++){
            if (pointer[j] < file[j].size() && file[j][pointer[j]] < min){
                min = file[j][pointer[j]];
                k = j;
            }
        }

        temp.push_back(min);
        pointer[k]++;
    }
}

void external_sort(vector<vector<int>>& file, int buffer){
    for (int i = 0; i < file.size(); i++){
        sort(file[i].begin(), file[i].end());
    }

    while (file.size() > 1){
        int k = 0, i = 0;
        vector<vector<int>> sorted_file;
        vector<vector<int>> temp;
        vector<int> temp1;

        while (i < file.size()){
            temp.clear();
            for (k = 0; k < buffer - 1 && i + k < file.size(); k++){
                temp.push_back(file[i + k]);
            }
            temp1.clear();
            merge(temp, temp1);
            sorted_file.push_back(temp1);
            i += k;
        }
        file = sorted_file;
    }
}

int main(){
    int buffer, page_size, total_records;
    cin >> buffer;
    cin >> page_size;
    cin >> total_records;

    vector<vector<int>> file;

    int k = 0, i = 0, a;
    vector<int> temp;

    while (i < total_records){
        temp.clear();
        for (k = 0; k < page_size && i + k < total_records; k++){
            cin >> a;
            temp.push_back(a);
        }
        file.push_back(temp);
        i += k;
    }
    external_sort(file, buffer);
    for (i = 0; i < file[0].size(); i++){
        cout << file[0][i] << "\n";
    }
    return 0;
}