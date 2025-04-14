//Ahmet Çavuşoğlu 32394

#include <iostream>
#include <vector>

using namespace std;
// This struct like represents a dictionary entry. Each entry has a code (number) and the data (string)
struct dict{
    int code;
    string data;
    dict(string s="",int c=-1):code(c),data(s){}
    bool operator==(const dict& other){
           return data == other.data;
    }
    bool operator!=(const dict& other){
        return data != other.data;
    }
    
};
// Hash table is general now, so I can use it with other structs too. It store the entries and tells if used or not
template <class  T>
class hashtable{
private:
    T entries[4096];
    bool isUsed[4096];
    // Compute hash to find index in the array
    int computeHash(string key){
        int hashval=0;
        for(int i=0;i<key.length();i++){
            hashval=(hashval+i)%4096;
        }
        return hashval;
    }
public:
    //constructr
    hashtable(){
        for (int i=0;i<4096;i++){
            isUsed[i]=false;
        }
    }
    // Insert new item into the table
    bool insert(T item){
        int index=computeHash(item.data);
        while(isUsed[index]==true){
            if(entries[index]==item){
                return false;
            }
            index=(index+1)%4096;
        }
        entries[index]=item;
        isUsed[index]=true;
        return true;
    }
    // Get the code of a string from the table for being easy to use
    int getCode(string key) {
            int index = computeHash(key);
            while (isUsed[index]) {
                if (entries[index].data == key) return entries[index].code;
                index = (index + 1) % 4096;
            }
            return -1;
        }
        // Check if a key is in table
        bool contains(string key) {
            return getCode(key) != -1;
        }
    // Get the string by code for being easy to use
    string getData(int code){
        return entries[code].data;
    }
    
    
};

int main() {
    
    hashtable<dict> dictionary;
    // Fill dictionary with ASCII char (0-255)
    for (int i=0;i<256;i++){
        string s="";
        s+=char(i);
        dictionary.insert(dict(s,i));
        
    }
    
    int choice;
    string input;
    int nextcode=256;
    cout<<"To compress a file, press 1. To decompress a file, press 2: ";
    cin>>choice;
    // if else statements for choses.
    //this is compress choice
    if (choice==1){
        cout << "Enter the input string: ";
        cin.ignore();
        getline(cin, input);
        string current="";
        vector<int>outputs;
        for(char i:input){
            string combinedstring=current+i;
            // If word exist, I continue growing it
            if(dictionary.contains(combinedstring)){
                current=combinedstring;
            }
            else{
                // If not exist, I output current one and add the new word
                if (current!="") {
                    outputs.push_back(dictionary.getCode(current));
                    
                }
                dictionary.insert(dict(combinedstring,nextcode));
                nextcode++;
                current=i;
            }
        }
        // Add last part if still remaining
        if (current!="") {
            outputs.push_back(dictionary.getCode(current));
                }
        cout<<"Compressed output: ";
        for(int i=0;i<outputs.size();i++){
            cout<<outputs[i]<<" ";
            
        }
        cout<<endl;
    }
    // Decompress choice
    else if(choice==2){
        cout<<"Enter the compressed string: ";
        cin.ignore();
        string input;
        getline(cin, input);

        vector<int> outputs;
        string current = "";
        for (char ch : input){
            if(ch == ' '){
                outputs.push_back(stoi(current));
                current = "";
            } else {
                current += ch;
            }
        }
        if (current!="") {
            outputs.push_back(stoi(current));
        }

        string dict[4096];
        // Fill dictionary with ASCII chars
        for (int i = 0; i < 256; i++) {
            dict[i] = string(1, char(i));
        }

        string result = "";
        int nextcode = 256;
        string previous = "";
        for (int i = 0; i < outputs.size(); i++) {
            int code = outputs[i];
            string entry;
            // If code is in dictionary, I take it
            if (code < nextcode && !dict[code].empty()) {
                entry = dict[code];
                
            } // If special case where code == next
            
            else if (code == nextcode) {
                entry = previous + previous[0];
            } else {
                cout << "Invalid error..." << endl;
                return -1;
            }

            result += entry;
            // I add new element to the dictionary
            if (!previous.empty()) {
                dict[nextcode] = previous + entry[0];
                nextcode ++;
            }


            previous = entry;
        }

        cout << "Decompressed string: " << result << endl;
    }

    else{
        return 0;
    }
                   
                   
    return 0;
}
