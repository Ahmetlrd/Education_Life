#include <iostream>
#include <string>
#include "strutils.h"
#include <fstream>
#include <vector>

using namespace std;
struct WeatherData{
    string date;
    double temperature;
    double precipitation;
};
WeatherData parseLine(const string& line){
    string dateStr;
            double temperature, precipitation;

            int pos = line.find(',');
            dateStr = line.substr(0, pos);
    string newline=line.substr(pos+2);
    pos=newline.find(',');
    temperature=atof(newline.substr(0,pos));
    string finally=newline.substr(pos+2);
    pos=finally.find(',');
    precipitation=atof(finally.substr(0,pos));
    

            

            WeatherData data = {dateStr, temperature, precipitation};
            
    return data;
        }
string getFormattedDate(const string& date){
    int tarih;
    const string months[] = { "January", "February", "March",
    "April", "May", "June", "July", "August", "September",
        "October", "November", "December" };
    int bas, son;
    bas=date.find('-');
    son=date.rfind('-');
    tarih=atoi(date.substr(bas+1,son));
    string genel;
    genel+=months[tarih-1];
    genel+=" ";
    
    genel+=date.substr(son+1);

    
    
    genel+=", ";
    genel+=date.substr(0,bas);
    return genel;
}
double averageTemperature(const vector<WeatherData>& data){
    double total=0;
    for (int i =0;i<data.size();i++){
        total+=data[i].temperature;
    }
    return total/data.size();
    
}
double totalPrecipitation(const vector<WeatherData>& data){
    double total=0;
    for (int i =0;i<data.size();i++){
        total+=data[i].precipitation;
    }
    return total;
}
int countDryDays(const vector<WeatherData>& data){
    int count=0;
    for (int i =0;i<data.size();i++){
        if (data[i].precipitation==0){
            count++;
        }
    }
    return count;
}
WeatherData findExtremesTemperature(const vector<WeatherData>& data, bool findMax) {
    double cons = data[0].temperature;
    WeatherData extreme = data[0];
    
    if (findMax) {
        for (int i = 1; i < data.size(); i++) {
            if (data[i].temperature > cons) {
                cons = data[i].temperature;
                extreme = data[i];
                

            }
        }
    } else {
        for (int i = 1; i < data.size(); i++) {
            if (data[i].temperature < cons) {
                cons = data[i].temperature;
                extreme = data[i];
            }
        }
    }
    
    return extreme;
}

WeatherData maxPrecipitation(const vector<WeatherData>& data){
    double cons = data[0].precipitation;
    WeatherData extreme = data[0];
    
    
        for (int i = 1; i < data.size(); i++) {
            if (data[i].precipitation > cons) {
                cons = data[i].precipitation;
                extreme = data[i];
                

            }
        }
    return extreme;
}
bool containsNonDigit(const std::string& str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}
int main(){
    cout<<"Welcome to the Weather Data Analysis Program!"<<endl<<"1. Load data file"<<endl<<"2. Display average temperature"
    <<endl<<"3. Display total precipitation"<<endl<<"4. Display the number of dry days"<<endl<<"5. Display the hottest day"<<endl<<"6. Display the coldest day"<<endl<<"7. Display the day with the highest precipitation"<<endl<<"8. Close the program"<<endl<<endl;
    string choice;
    cout<<"Choose an option: ";
    cin>>choice;
    int control=0;
    
    
    
    
    while (control==0){
        if (atoi(choice)==1&&containsNonDigit(choice)){
            string filename;
            cout<<"Enter the file name: ";
            cin>>filename;
            ifstream inputfile(filename);
            if (!inputfile) {
                cout << "Cannot open the file!"<<endl;
                cout<<"Choose an option: ";
                cin>>choice;
                
            }
            else{
                cout<<"Data loaded successfully."<<endl;
                string line;
                vector<WeatherData> data;

                while (getline(inputfile, line)) {
                    data.push_back(parseLine(line));
                }
                
                
                
               
                
                cout<<"Choose an option: ";
                cin>>choice;
                int cont=0;
                while(cont==0){
                    if(atoi(choice)==2&&containsNonDigit(choice)){
                        
                        cout<<"Average Temperature: "<<averageTemperature(data)<< " Celsius"<<endl;
                        
                        cout<<"Choose an option: ";
                        cin>>choice;
                    }
                    else if(atoi(choice)==3&&containsNonDigit(choice)){
                        cout<<"Total Precipitation: "<<totalPrecipitation(data)<<" mm"<<endl;
                        cout<<"Choose an option: ";
                        cin>>choice;
                    }
                    else if(atoi(choice)==4&&containsNonDigit(choice)){
                        cout<<"Number of Dry Days: "<<countDryDays(data)<<endl;
                        cout<<"Choose an option: ";
                        cin>>choice;
                    }
                    else if(atoi(choice)==5&&containsNonDigit(choice)){
                        

                        cout<<"Hottest Day: "<< getFormattedDate(findExtremesTemperature(data,true).date) <<" with "<<findExtremesTemperature(data,true).temperature<<" Celsius"<<endl;
                        cout<<"Choose an option: ";
                        cin>>choice;
                    }
                    else if(atoi(choice)==6&&containsNonDigit(choice)){
                        cout<<"Coldest Day: "<< getFormattedDate(findExtremesTemperature(data,false).date) <<" with "<<findExtremesTemperature(data,false).temperature<<" Celsius"<<endl;                        cout<<"Choose an option: ";
                        cin>>choice;
                    }
                    else if(atoi(choice)==7&&containsNonDigit(choice)){
                        cout<<"Highest Precipitation Day: "<< getFormattedDate(maxPrecipitation(data).date) <<" with "<<maxPrecipitation(data).precipitation<<" mm"<<endl;                        cout<<"Choose an option: ";
                        cin>>choice;
                    }
                    else if (atoi(choice)==8&&containsNonDigit(choice)){
                        cont++;
                        inputfile.close();
                    }
                    else if(atoi(choice)==1&&containsNonDigit(choice)){
                        break;
                    }
                    else{
                        cout<<"Invalid option. Please enter a valid option."<<endl;
                        cout<<"Choose an option: ";
                        cin>>choice;
                    }
                    
                }
            }
            
        }
        else{
            
            
            if (atoi(choice)==8&&containsNonDigit(choice)){
                control++;
                cout<<"Exiting program..."<<endl;
            }
            else if (atoi(choice)>0&&atoi(choice)<9&&containsNonDigit(choice)){
                cout<<"Please load a data file first."<<endl;
                cout<<"Choose an option: ";
                cin>>choice;
            }
            else{
                cout<<"Invalid option. Please enter a valid option."<<endl;
                cout<<"Choose an option: ";
                cin>>choice;
            }
            
        }
        
        
        
    }
        return 0;
    }



