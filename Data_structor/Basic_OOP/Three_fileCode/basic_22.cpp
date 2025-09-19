#include"basic_22.hpp"
#include<iostream>

void basic_22 :: read(void)
{
    cout <<" Enter a binary number " << endl;
    cin >> s;
}

void basic_22 :: chk_bin(void)
{
    for(int i = 0; i < s.length(); i++){
        if(s.at(i) != '0' && s.at(i) != '1'){
            cout << "Incorrect binary format" << endl;
            exit(0);
        }
    }
}

void basic_22 :: ones_copliment(void){
    chk_bin();
    for(int i = 0; i < s.length(); i++){
        if(s.at(i) == '0'){
            s.at(i) = '1';
        }
        else{
            s.at(i) = '0';
        }
    }
}

void basic_22 :: display(void){
    cout << "Dislaying your binary number" << endl;
    for(int i = 0; i < s.length(); i++){
        cout << s.at(i);
    }
    cout<<endl;
}