#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc,argv);

    inf.readInt(1, 2000, "H");
    inf.readEoln();

    int n = inf.readInt(3, 2000, "N");
    inf.readEoln();

    inf.readInt(2, n-1, "M");
    inf.readEoln();

    for (int i = 0; i < n; i++) {
        if(i!=n-1){
            inf.readInt(-800, 800, "a");
            inf.readSpace();
        }
        else{
            inf.readInt(-800, 800, "a");
        }
    }
    
    inf.readEoln();
    inf.readEof();
}