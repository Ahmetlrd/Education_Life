
#include <iostream>
#include <vector>
using namespace std;

int decodeNumber(const string& PositionWord) {
    int sum = 0;
    int len = PositionWord.length();
    for (int i = 0; i < len; i++) {
        if (isdigit(PositionWord[i])) {
            int sayi = stoi(string(1, PositionWord[i]));
            sum += sayi;
        }
    }
    return sum;
}
string reverseWord(const string& word) {
    vector<string> kelimeler;
    
    string reverse;
    string kelime;
    int uzunluk = word.length();

    for (int i = uzunluk - 1; i >= 0; i--) {
        reverse.push_back( word[i]);
    }
    return  reverse;
}
string reverseLettersDecode(const string& message){
    string son;
    string word;
    vector <string> kelimeler;
    for (char c:message){
        if (c != ' '){
            word+=c;
        }
        else{
            kelimeler.push_back(word);
            word.clear();
        }
    }
    kelimeler.push_back(word);
    
    for (int i=kelimeler.size()-1;i>=0;i--){
        
        son+=kelimeler[i];
        if (i!=0){
            son+=" ";
        }
    }
    return son;
}
string caesarCipherShiftDecode(const string& message, int shift){
    string code;
    int len=message.length();
    for (int i=0;i<len;i++){
        if (isalpha(message[i]) && !isupper(message[i])) {
            if ((char(message[i])-shift)>=97){
                code+=char (char(message[i])-shift);
            }
            else {
                code+=(char (26+char(message[i])-shift));
            }
            
        }
        else if (isalpha(message[i])&&isupper(message[i])){
            if ((char(message[i])-shift)>=65){
                code+=char (char(message[i])-shift);
            }
            else {
                code+=(char (26+char(message[i])-shift));
            }
        }
        else {
            code+=message[i];
        }
    }
    return code;
}
string findKey(const string& decodedMessage, int position){
    string secret;
    string kelime;
    vector <string> words;
    for (char c:decodedMessage){
        if (c != ' '){
            kelime+=c;
        }
        else{
            words.push_back(kelime);
            kelime.clear();
        }
    }
    words.push_back(kelime);
    
    
    
    return words[position-1];
}
string removeLastPunctuation(string key){
    string m;
    
    if (!isalpha(key[key.length()-1])){
        for (int i=0;i<key.length()-1;i++){
            
            m+=key[i];
            
            
        }
    }
    else{
        m=key;
    }
    
    return m;
}
int main() {
    string input;
    int number;
    cout << "Enter your encoded message: ";
    getline(cin, input);
    cout<<"Choose your decoding strategy: "<<endl
    <<"1. Reverse Letters"<<endl
    <<"2. Caesar Cipher Shift"<<endl
    <<"Enter choice (1 or 2): ";
    cin>>number;
    while (number<1||number>2){
        cout<<"Invalid choice. Enter choice (1 or 2): ";
        cin>>number;
    }
    if (number==1){
        string word;
        string reversed;
        string gizli;
        reversed=reverseWord( input);
        
        string finally=reverseLettersDecode(reversed);

        cout<<"Enter the word to find the position of the key word: ";
        cin>>word;
        int sum=decodeNumber(word);
        gizli=findKey(finally,  sum);
        string gizlison=removeLastPunctuation(gizli);
        cout<<"Decoded Message: "<<finally<<endl;
        cout<<"Secret Key: "<<gizlison<<endl;
        

    }
    
    else{
        int shift;
        string gizli;

        cout<<"Enter Caesar Cipher Shift amount: ";
        cin>>shift;
        string word;
        cout<<"Enter the word to find the position of the key word: ";
        cin>>word;
        int sum=decodeNumber(word);
        


        string output=caesarCipherShiftDecode( input,  shift );
        gizli=findKey(output,  sum);
        string gizlison=removeLastPunctuation(gizli);
        cout<<"Decoded Message: "<<output<<endl;
        cout<<"Secret Key: "<<gizlison<<endl;

    }

    return 0;
}
    


