#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <ctime>


using std::string;
using namespace::std;


int main(){
    int n;
    string x;
    chrono::steady_clock::time_point start,stop;
    time_t curr = time(0);     
    
    vector<string>hist;
    int totalmin=0;
    int sessno=0;
    

    while(true){
        cout<<"\t\tWELCOME\n\n\t"<<ctime(&curr)<<"\nWhat will you do :) ?\n\n1.Start session\n2.End session\n3.History\n5.Exit\n\n=>";
        cin>>n;

    switch (n){
        case 1: 
            cout<<"\nWhat subject will you do today ? \n=> "<<endl;
            cin>>x;
            start=chrono::steady_clock::now();
            break;
    
        case 2:
            stop=chrono::steady_clock::now();
            {
            auto durtn=chrono::duration_cast<chrono::minutes>(stop-start);
            int mins=durtn.count();
            
            cout<<"You studied "<<x<<"for "<<mins<<" minutes!"<<endl;
            
            hist.push_back(x + "-" + to_string(mins)+"minutes");
            totalmin=totalmin+mins;
            sessno++;
            }
            break;
        
        case 3:
            if (hist.empty()){
            cout<<"No sessions yet.Go study for sometime!\n";
            }
            else{
            cout<<"\t\tHISTORY\n";
            for(const auto& entry:hist){
                            cout<<entry<<endl;
                        }
        }
    
        case 4:
            cout<<"\t\tBYEEEE"<<endl;    
            return 0;
        
    
        default:
            cout<<"Hey no fair ! Pick one from 1-4";
            break;
    }
}
}
