#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;
//inputları alma
void getTripDetails(string& startCity, string& destinationCity, float& distance, float& gasPrice, int& passengers, int& daysInAdvance, string& isWeekend) {
    cout << "Enter the starting city: ";
    cin >> startCity;
    cout << "Enter the destination city: ";
    cin >> destinationCity;
    cout << "Enter the trip distance in kilometers: ";
    cin >> distance;
    cout << "Enter the price of gasoline per liter: ";
    cin >> gasPrice;
    cout << "Enter the number of passengers: ";
    cin >> passengers;
    cout << "Enter days booked in advance: ";
    cin >> daysInAdvance;
    cout << "Is the trip on a weekend? (yes/no): ";
    cin >> isWeekend;
    
}


//fee hesaplama

float calculateEnvironmentalFee(float distance, float
                                average_fuel_consumption_per_100km){
    
    if (average_fuel_consumption_per_100km>8){
        return 0.002*distance;
        
        
    }
    else{
        return 0.001*distance;
    }
    
}



//araba fiyat
float calculateCarCost( const float distance, const float gasPrice,const float average_fuel_consumption_per_100km)
{
    float TotalCarCost,FuelCost,EnviromentalFee;
    EnviromentalFee=calculateEnvironmentalFee(distance,average_fuel_consumption_per_100km);
    
    FuelCost= (distance / 100) * average_fuel_consumption_per_100km *gasPrice;
    
    if(FuelCost>2700){
        FuelCost=FuelCost/2;
    
    }
    
    TotalCarCost=(EnviromentalFee*distance)+FuelCost;
    
    return TotalCarCost;
}


//tiered rate hesaplama
float calculateTieredDistanceRate(float basePrice, float distance,
                                  string type){
    
    
    if (type == "bus") {
        if (distance > 300) {
            basePrice *= 1.15;
            
        }
        else if (distance <= 300 && distance > 200) {
            basePrice *= 1.10;
        }
        else if (distance > 100) {
            basePrice *= 1.05;
            
        }
    

            
        }
    
    if (type=="train"){
        if (distance>300){
            basePrice=basePrice*1.30;
        }
        else if(distance<=300 && distance>200){
            basePrice=basePrice*1.15;
        }
        else if(distance>100){
            basePrice  = basePrice*1.10;
            
        }
    }
    return basePrice;
}


//booking discount
float applyEarlyBookingDiscount(float cost, int daysInAdvance){
    
    if (daysInAdvance>=30){
        cost=cost-cost/10;
    }
    return cost;
}

//apply day of piercing

float applyDayOfWeekPricing(float cost, string isWeekend){
    
    if (isWeekend=="yes"){
        cost=cost+cost/10;
        
    }
    return cost;
}

float minVal (float car1, float car2,float bus,float train){
    float minVal = std::min({car1, car2, bus, train});
    return minVal;
}


int main() {
    string startCity, destinationCity;
    float distance, gasPrice,firstcar=7.9,secondcar=8.2,car1,car2,bus=510,train=470;
    int passengers, daysInAdvance;
    string isWeekend,arac;
    
    getTripDetails(startCity, destinationCity, distance, gasPrice, passengers, daysInAdvance, isWeekend);
    car1=calculateCarCost(distance,  gasPrice,firstcar);
    car2=calculateCarCost(distance,  gasPrice,secondcar);
    bus=calculateTieredDistanceRate( bus,  distance,  "bus");
    train=calculateTieredDistanceRate( train,  distance,  "train");

    bus*=passengers;
    train*=passengers;
    bus=applyEarlyBookingDiscount(bus,  daysInAdvance);
    bus=applyDayOfWeekPricing(bus,  isWeekend);
    train=applyEarlyBookingDiscount(train,  daysInAdvance);
    train=applyDayOfWeekPricing(train,  isWeekend);
    cout << fixed << setprecision(2);
    float minval=minVal(car1,car2,bus,train);
    if (minval==car1){
        arac="Car 1";
    }
    else if (minval==car2){
        arac="Car 2";
    }
    else if (minval==bus){
        arac="Bus";
    }
    else if (minval==train){
        arac="Train";
    }
    cout<<"Cost for Car 1: "<<car1<<" TL"<<endl;
    cout<<"Cost for Car 2: "<<car2<<" TL"<<endl;

    cout<<"Cost for Bus: "<<bus<<" TL"<<endl;

    cout<<"Cost for Train: "<<train<<" TL"<<endl;

    cout<<"The most cost-effective transportation option to travel from "<<startCity<<" to "
    <<destinationCity<<": "<<arac<<" with a cost of "<<minval<<" TL"<<endl;
    return 0;
}
