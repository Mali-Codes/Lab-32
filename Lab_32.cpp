#include "Car.h"
#include <cstdlib>
#include <ctime>
#include <deque>
using namespace std;





void fourlanes() {
    const int lanes = 4;
    const int initalQueue = 2;

    deque<Car> tollbooth[lanes];

    for (int i = 0; i < lanes; i++) {
        for (int j = 0; j < initalQueue; j++) {
            Car c;
            tollbooth[i].push_back(c);
        }
    }

    for (int i = 0; i < lanes; i++) {
        cout << "  Lane " << i << ": " << tollbooth[i].size() << " cars \n";
    }

    cout << "Created" << lanes << "lanes" << endl;

    cout << "test the queue" << endl;

    cout << "First car in lane 2: ";
    tollbooth[2].front().print();

    cout << "First car in lane 0: ";
    tollbooth[0].front().print();
}

void testprobabilities() {
    const int lanes = 4;
    const int initalQueue = 2;
    const double payTollProb = 46;
    const double newCarProb = 39;
    const double laneSwitchProb = 15;

    deque<Car> tollbooth[lanes];

    for (int i = 0; i < lanes; i++) {   // from 4 lanes function

        for (int j = 0; j < initalQueue; j++) {
            Car c;
            tollbooth[i].push_back(c);
        }
    }

    cout << "Inital lanes: \n";
    for (int i = 0; i < lanes; i++) {
        cout << "lane " << i << ": " << tollbooth[i].size() << " cars \n";
    }

    cout << "siming one time period\n";

    for (int i = 0; i < lanes; i++) {
        cout << "Lane: " << i << ": ";

        if (tollbooth[i].empty()){
            
            int action = rand() % 2;

            if (action == 0) {
                Car newCar;
                tollbooth[i].push_back(newCar);
                cout << "New car joined \n";
            } else {
                cout << "No action\n";
            }
            continue;
            }
    

        int randValue = rand() % 100 ;

        if (randValue < payTollProb) {
            cout << "toll paid " << randValue << "\n";
            tollbooth[i].pop_front();
        } 
        else if (randValue < payTollProb + newCarProb) {
            cout << "New car joined" << randValue << "\n";
            Car newCar;
            tollbooth[i].push_back(newCar);

        }
        else {
            cout << "Car switching lane " << randValue<< "\n";

            int newLane = rand() % lanes;
            while (newLane == i) {
                newLane = rand() % lanes;
            }

            Car switchingCar = tollbooth[i].back();
            tollbooth[i].pop_back();
            tollbooth[newLane].push_back(switchingCar);

            cout << " switched from lane " << i << " to lane " << newLane<< "\n";
        }
    }

    cout << "after p1 \n";

    for (int i = 0; i < lanes; i++) {

        cout << "Lane " << i << ": " << tollbooth[i].size() << " cars \n";
    }
}








int main() {

    const int initalSize = 2;

    const int lanes = 4;
    const int MaxTime = 20;

    const int initalQueue = 2;
    const double payTollProb = 46;
    const double newCarProb = 39;
    const double laneSwitchProb = 15;



    srand(time(0));

    deque<Car> tollbooth[lanes];

    for (int i = 0; i < lanes; i++) { // fill lines with 2
        for (int j = 0; j < initalSize; j++) {
            Car c;
            tollbooth[i].push_back(c);
        }
    }

    cout << "Start queue" << endl;
    
    for (int i = 0; i < lanes; i++) {           //similar form to every othr time we have displayed the lanes
        cout << "Lane " << i << ": " << tollbooth[i].size() << " cars\n";
        for (auto& car : tollbooth[i]) {
            cout << "    ";
            car.print();
        }
    }

    int time = 1;
// movement
    while (time <= MaxTime) {
        for (int i = 0; i < lanes; i++) {
            cout << "Lane " << i << ": ";  
        
        if (tollbooth[i].empty()) {
                int action = rand() % 2;
                if (action == 0) {
                    Car newCar;
                    tollbooth[i].push_back(newCar);
                    cout << "New car joined empty lane\n";
                    cout << "    ";
                    newCar.print();
                } else {
                    cout << "No action (empty lane)\n";
                }
                continue;  // Skip to next lane
            }
        if (tollbooth[i].empty()){
            
            int action = rand() % 2;

            if (action == 0) {
                Car newCar;
                tollbooth[i].push_back(newCar);
                cout << "New car joined \n";
            } else {
                cout << "No action\n";
            }
            continue;
            }
    

        int randValue = rand() % 100;
            
            if (randValue < payTollProb) {
                cout << "toll paid " <<  "\n";
                tollbooth[i].pop_front();
            } 
            else if (randValue < payTollProb + newCarProb) {
                cout << "New car joined " << "\n";
                Car newCar;
                tollbooth[i].push_back(newCar);
            }
            else {
                cout << "Car switching lane "  << "\n";
                
                int newLane = rand() % lanes;
                while (newLane == i) {
                    newLane = rand() % lanes;
                }
                
                Car switchingCar = tollbooth[i].back();
                tollbooth[i].pop_back();
                tollbooth[newLane].push_back(switchingCar);
                
                cout << " switched from lane " << i << " to lane " << newLane << "\n";
            }
        }
        
        
        cout << "\n--- Current ---\n";
        for (int i = 0; i < lanes; i++) {
            cout << "Lane " << i << ": " << tollbooth[i].size() << " cars\n";
        }
        
        time++;
    }
}

        


    
    


// int time = 1;

//     while (!tollbooth.empty()) {
//         cout << "\nTime " << time << ":\n";

//         int action = rand() % 2;

//         if (action == 0) {
//             Car newCar;
//             tollbooth.push_back(newCar);
//             cout << "    New car arrived: ";
//             newCar.print();
//         }
//         else {
//             cout << "Paid toll: ";
//             tollbooth.front().print();
//             tollbooth.pop_front(); // take it out 
//         }

//         cout << "Queue: \n";

//         if (tollbooth.empty()) {
//             cout << "empty queue \n";
//         } else {
//             for (auto& car : tollbooth) {
//                 cout << "    ";
//                 car.print();
//             }
//         }
        
//         time ++;
    
//     }


