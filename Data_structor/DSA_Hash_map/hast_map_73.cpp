#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){
    map<string, int> marksMap;
    marksMap["Harshit"] = 98;
    marksMap["Jack"] = 59;
    marksMap["Rohit"] = 2;
    marksMap.insert({{"Komal",45},{"Kurro",46}});
    map<string, int> :: iterator iter;
    for(iter = marksMap.begin(); iter != marksMap.end(); iter++){
        cout << (*iter).first << " " << (*iter).second <<"\n";
    }
    cout << "The size is: " << marksMap.size() << endl;
    cout << "The max size is: " << marksMap.max_size() << endl;
    cout << "The empty's return value is " << marksMap.empty() << endl;
    return 0;
}