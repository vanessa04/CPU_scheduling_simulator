#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

double fingAverage( vector<int> all_values){
   double total=0.0;
   int n= all_values.size();
   for (int i = 0; i < all_values.size(); i++){
   total = total + all_values.at(i); 
   }
   total=total/n;
return total;
}
//////////////////////////////////////////////////////////////////////////////////////


vector<int> findCompleteTime (vector<int> burst_times){
    vector<int> complete_time;
    complete_time.push_back(burst_times.at(0));
    for (int i = 1; i < burst_times.size(); i++){
    
        complete_time.push_back(burst_times.at(i) + complete_time.at(i-1));

}
    return complete_time;
}

//////////////////////////////////////////////////////////////////////////////////////

vector<int> findTurnAroundTime (vector<int> complete_time, vector<int> arrival_times){
    vector<int> turn_around_time;
    for(int i=0;i< arrival_times.size();i++){
    turn_around_time.push_back(complete_time.at(i)- arrival_times.at(i));

    }
    return turn_around_time;
}
//////////////////////////////////////////////////////////////////////////////////////

vector<int> findWaitingTime (vector<int> turn_around_time , vector<int> burst_times){
    vector<int> waiting_time;
    for(int i=0;i< burst_times.size();i++){
    waiting_time.push_back(turn_around_time.at(i)- burst_times.at(i));
    }
    return waiting_time;
}


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
  

//////////////////////////////////////////////////////////////////////////////////////


complete_time = findCompleteTime (burst_times);
turn_around_time= findTurnAroundTime (complete_time, arrival_times);
waiting_time = findWaitingTime (turn_around_time , burst_times);

cout<<"Pid   " << "AT   "<< "BT   " <<"CT   "<< "TAT   "<< "WT   " <<endl;
for (int i = 0; i < complete_time.size(); i++){
    cout<< "P"<< pids.at(i) <<"    " <<arrival_times.at(i)<< "    "<<burst_times.at(i)<< "    "<< complete_time.at(i)<< "    " <<turn_around_time.at(i)<< "    "<<waiting_time.at(i)<<endl;
}


//////////////////////////////////////////////////////////////////////////////////////


average_turn_around_time = fingAverage(complete_time);
average_waiting_time = fingAverage(waiting_time);
average_complete_time = fingAverage(turn_around_time);


cout<<"The average completion time is " <<average_turn_around_time<< endl;
cout << "The average waiting time is " << average_waiting_time<< endl;
cout << "The avg turn around time is "<< average_complete_time<< endl;


return 0;
}