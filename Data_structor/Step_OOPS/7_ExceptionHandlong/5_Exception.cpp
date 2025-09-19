#include<iostream>
#include<exception>
using namespace std;

// class exception{
//     protected:
//         string msg;
    
//     public:
//         exception(string msg){
//             this->msg = msg;
//         }

//         string what(){
//             return msg;
//         }
// };

int main(){
    try{
    int *p = new int[1000000000];
    cout <<"Momory allocation is sucessfully\n";
    delete []p;
    }
    catch(const bad_alloc &e){
        cout << "Exception occurance due to line 9: " << e.what()<<endl;
    }
}