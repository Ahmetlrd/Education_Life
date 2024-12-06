#include <iostream>
#include<iomanip>
using namespace std;

int main()
{
    unsigned short choice;
    int pearl,acromantula,tincture;
    int lavender,crocodile,peppermint;
    int salamander,powdered;
    float point,initial,eva,time,rate;
    cout<<fixed<<setprecision(2);

    cout<<"Welcome to the Hogwarts Potion Brewing Challenge!"<<endl;
    cout<<"Which potion are you brewing?"<<endl;
    cout<<"1. Potion of Invisibility"<<endl;
    cout<<"2. Calming Draught"<<endl;
    cout<<"3. Strengthening Solution"<<endl;
    cout<<"Enter choice (1-3): ";
    cin>>choice;
    if (choice==1)
    {

        cout<<"Enter the amount of Pearl Dust (in grams): ";
        cin>>pearl;
        cout<<"Enter the amount of Acromantula Venom (in ml): ";
        cin>>acromantula;
        cout<<"Enter the amount of Tincture of Demiguise (drops): ";
        cin>>tincture;
        point=100+pearl-(3*acromantula)+(4*tincture);
        initial=pearl+acromantula+tincture+500;
        eva=initial-300;
        rate=40*100/point;
        time=eva/rate;
        cout<<"\nFor your potion: "<<endl;

        cout<<"Adjusted Boiling Point: "<<point<<" C ("<< point*1.8+32<<" F)"<<endl;
        cout<<"Total Initial Volume: "<<initial<<" ml"<<endl;
        cout<<"Evaporated Volume: "<<eva<<" ml"<<endl;
        cout<<"Boiling Time Required: "<<time<<" minutes"<<endl;
        cout<<"Ensure your potion is brewed at this precise volume and time for perfect results!"<<endl;
    }
    else if(choice==2)
    {

        cout<<"Enter the amount of Lavender (in grams): ";
        cin>>lavender;
        cout<<"Enter the number of Crocodile Hearts: ";
        cin>>crocodile;
        cout<<"Enter the amount of Peppermint (in leaves, 1 leaf = 1ml): ";
        cin>>peppermint;
        point=100-(lavender*0.2)+(5*crocodile)-peppermint;
        initial=lavender+crocodile*5+peppermint+500;
        eva=initial-300;
        rate=40*100/point;
        time=eva/rate;
        cout<<"\nFor your potion: "<<endl;

        cout<<"Adjusted Boiling Point: "<<point<<" C ("<< point*1.8+32<<" F)"<<endl;
        cout<<"Total Initial Volume: "<<initial<<" ml"<<endl;
        cout<<"Evaporated Volume: "<<eva<<" ml"<<endl;
        cout<<"Boiling Time Required: "<<time<<" minutes"<<endl;
        cout<<"Ensure your potion is brewed at this precise volume and time for perfect results!"<<endl;
    }
    else if (choice==3)
    {

        cout<<"Enter the amount of Salamander Blood (in ml): ";
        cin>>salamander;
        cout<<"Enter the amount of Powdered Griffin Claw (in grams): ";
        cin>>powdered;
        point=100-(salamander*2)+(3*powdered);
        initial=salamander+powdered+500;
        eva=initial-300;
        rate=40*100/point;
        time=eva/rate;
        cout<<"\nFor your potion: "<<endl;
        cout<<"Adjusted Boiling Point: "<<point<<" C ("<< point*1.8+32<<" F)"<<endl;
        cout<<"Total Initial Volume: "<<initial<<" ml"<<endl;
        cout<<"Evaporated Volume: "<<eva<<" ml"<<endl;
        cout<<"Boiling Time Required: "<<time<<" minutes"<<endl;
        cout<<"Ensure your potion is brewed at this precise volume and time for perfect results!"<<endl;
    }
    else{
        cout<<"Invalid choice. Please restart the program and select a valid potion."<<endl;
    }
    

    return 0;
}

