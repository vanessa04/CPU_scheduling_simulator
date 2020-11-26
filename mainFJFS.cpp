#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;


int  DNA_to_mRNA(int Input){
    int NenInt =0;

    for (int i=0; i< Input.length(); i++ ){
        // is Converting all the characters to upper letter characters
        int Upper  = toupper(Input[i]);
        // is taking the upper letter char and passing them throught a function that will return a defferen char
        char converToNewDNA = DNAbase_to_mRNAbase( Upper);
        NewString += converToNewDNA;
    }
return NewString;

}




int main(){
ifstream fin("Ps.txt");
    if (fin.fail()) {
        cerr << "File cannot be read, opened, or does not exist.\n";
        exit(1);
    }
    string strand;
    while(getline(fin, strand)) {
        string result =  DNA_to_mRNA(strand);
        cout << result << endl;
    }
    fin.close();

return 0;
}