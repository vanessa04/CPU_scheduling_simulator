#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

////////////////////////////
vector<int> cresting (vector<int> burst_times){
vector<int> testing;
int temp= burst_times.at(0);
vector<int> tempV= burst_times;

for (int j =0;j < burst_times.size();j++){
    for (int i =0;i < burst_times.size();i++){
        if (burst_times.at(i)< temp){
            temp  = burst_times.at(i);
            

        }
    }
}
return testing;
}

////////////////////////////////////////////////////////////////

int findSmallestArrival(vector<int> burst_times){
    int temp  = burst_times.at(0);
    int index = 0;
    for (int i =0;i < burst_times.size();i++){
        if (burst_times.at(i)< temp){
            index = i;
            temp  = burst_times.at(i);

        }

    }
    return index;
}
////////////////////////////////////////////////////////////////
vector<int> vectorInShortBurst(vector<int> pids,vector<int> arrival_times,vector<int> burst_times){
   vector<int> the_main_vector;
   int temp  = burst_times.at(0);
    int index = 0;
    vector<int> tempVector;
    tempVector= burst_times;

    for (int a= 0; a<pids.size(); a++){
        the_main_vector.push_back(pids.at(a));
        the_main_vector.push_back(arrival_times.at(a));
        the_main_vector.push_back(burst_times.at(a));

    }
    

    for (int j=0; j<burst_times.size();j++){
        for (int i =0;i < burst_times.size();i++){
            if (burst_times.at(i)< temp){
                the_main_vector.push_back(pids.at(i));
                the_main_vector.push_back(arrival_times.at(i));
                the_main_vector.push_back(burst_times.at(i));
                    temp= burst_times.at(i);
                }
        }
    } 
}


////////////////////////////////////////////////////////////////

vector<int> findCompleteTime (vector<int> burst_times ){
    vector<int> complete_time;
    complete_time.push_back(burst_times.at(0));
    for (int i = 1; i < burst_times.size(); i++){
    
        complete_time.push_back(burst_times.at(i) + complete_time.at(i-1));

}
    return complete_time;
}
////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////


int main(){



string result;
vector<int> pids;
vector<int> arrival_times;
vector<int> burst_times;
vector <int> complete_time;
vector <int> turn_around_time;
vector <int> waiting_time;
double average_turn_around_time=0.0,average_waiting_time=0.0,average_complete_time=0.0;
int n = pids.size();


    std::vector<int> numbers;
    ifstream inputFile("Ps.txt");        

   
    if (inputFile.good()) {
        
        int current_number = 0;
        while (inputFile >> current_number){
            numbers.push_back(current_number);
        }

        
        inputFile.close();

       
        cout << "The numbers are: ";
        for (int count = 0; count < numbers.size(); count++){
            cout << numbers[count] << " ";
        }

        cout << endl;
    }else {
        cout << "Error!";
        inputFile.close();

    }



//////////////////////////////////////////////////////////////////////////////////////

for(int i= 0; i< numbers.size() ; i=i+3){ 
pids.push_back(numbers.at(i));
}

for(int i= 1; i< numbers.size() ; i=i+3){ 
arrival_times.push_back(numbers.at(i));
}

for(int i= 2; i< numbers.size() ; i=i+3){ 
burst_times.push_back(numbers.at(i));
}
///////////////////////////////////////////////////

 int test= findSmallestArrival( burst_times);
 cout<<"test "<< test <<endl;




return 0;
}
