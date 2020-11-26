#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <string>
using namespace std;




int main(){
string result;
vector<int> pids;
vector<int> arrival_times;
vector<int> burst_times;


    std::vector<int> numbers;
    ifstream inputFile("Ps.txt");        // Input file stream object

    // Check if exists and then open the file.
    if (inputFile.good()) {
        // Push items into a vector
        int current_number = 0;
        while (inputFile >> current_number){
            numbers.push_back(current_number);
        }

        // Close the file.
        inputFile.close();

        // Display the numbers read:
        cout << "The numbers are: ";
        for (int count = 0; count < numbers.size(); count++){
            cout << numbers[count] << " ";
        }

        cout << endl;
    }else {
        cout << "Error!";
        inputFile.close();
    }


for(int i= 0; i< numbers.size() ; i=i+3){ 
pids.push_back(numbers.at(i));
}

for(int i= 1; i< numbers.size() ; i=i+3){ 
arrival_times.push_back(numbers.at(i));
}

for(int i= 2; i< numbers.size() ; i=i+3){ 
burst_times.push_back(numbers.at(i));
}



// //To Print my Vectors

// cout << "Pid: ";
//         for (int count = 0; count < pids.size(); count++){
//             cout <<  pids[count] << " "<<endl;
//         }



// cout << "arrival_times: ";
//         for (int count = 0; count < arrival_times.size(); count++){
//             cout <<  arrival_times[count] << " "<<endl;;
//         }

// cout << "burst_times: ";
//         for (int count = 0; count < burst_times.size(); count++){
//             cout <<  burst_times[count] << " "<<endl;;
//         }




// //Testing the waters

// ifstream fin("Ps.txt");
//     if (fin.fail()) {
//         cerr << "File cannot be read, opened, or does not exist.\n";
//         exit(1);
//     }
//     string strand;
//     while(getline(fin, strand)) {
        
      
//         for(int i =0; i< strand.length(); i++){
//               cout<<strand[i]<< " check the i is "<< i << endl;

//           if (isdigit(strand[i])){
//              stringstream ss;
//              string a;
//              cout<<"i is "<< i << endl;
//              ss << strand[i];
//              ss>>a;
//              if (strand[i++]!= ' '){
//                  string sed;
//             ss << strand[i];
//              ss>> sed;
//               cout<<"*** sed "<< sed << endl;
//              a+=sed;
//              cout<<"i is sed "<< i << endl;
//              i--;
//              cout<<"i is --"<< i << endl;
//              }
             
//         ar.push_back(a);
//         }
        
// }
        
        

//         //cout << result << endl;

//     // for (int i =0; i<ar.length(); i++){
//     //     if (isdigit(result[i]))
//     //     cout<<result[i];
//     // }
//         //cout<< result[i]<<"=";

// // }
        
//     }

//     for (int i =0; i<ar.size(); i++){
        
//         cout<<ar.at(i)<< "|";
//     }
       


// // for (int i =0; i<result.length(); i++){
// // cout<< result[i]<<"=";

// // }



//     // cout<< result.length()<< endl;
//     fin.close();

return 0;
}