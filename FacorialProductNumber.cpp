#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool comp(char a, char b){
    return a > b;
}

int main() {
    int n;
    string x;
    vector<int> array;
    cin>>n;
    cin>>x;
    for(char i:x){
        
        if (i=='1'|| i=='0'){            
            continue;
        }else if(i=='4'){
            array.push_back('3');
            array.push_back('2');
            array.push_back('2');
        }else if(i=='6'){
            array.push_back('5');
            array.push_back('3');
        }else if(i=='8'){
            array.push_back('7');
            array.push_back('2');
            array.push_back('2');
            array.push_back('2');
        }else if(i=='9'){
            array.push_back('7');
            array.push_back('3');
            array.push_back('3');
            array.push_back('2');
        }else {
            array.push_back(i);
        }
    }

    sort(array.begin(),array.end(),comp);
    for (char i:array){
        cout<<i;
    }

    
    
    return 0;
}