#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "book.h"

using namespace std;


void addbooks(vector<Book> &books){
    string title, author;
    int year, pages;

    cin.ignore();
    cout << "Enter title: ";
    getline(cin, title);

    cout << "Enter author: ";
    getline(cin, author);

    cout << "Enter year: ";

    cin >> year;

    cout << "Enter pages: ";
    cin >> pages;

    Book asd={title,author,year,pages};
    books.push_back(asd);
}
void sırala(vector<Book> &books){
    for (int i=0;i<books.size()-1;i++){
        for(int j=0;j<books.size()-i-1;j++){
            if (books[j].getAuthor()>books[j+1].getAuthor()){
                swap(books[j],books[j+1]);
                
            }
        }
        
    }
}
void display(vector<Book> &books){
    

    if (books.size()==0){
        cout<<"The book collection is currently empty. Please add some books first."<<endl;
    }
    else{
        sırala(books);
        for (int i=0;i<books.size();i++){
            books[i].printInfo();
            cout<<"-------------------"<<endl;
        }
    }
}

void search(vector<Book>&books){
    string control;
    if(books.size()==0){
        cout<<"The book collection is currently empty. Please add some books first."<<endl;
    }
    
    else{
        int a=1;
        cin.ignore();

        cout<<"Enter the title to search: ";
        getline(cin,control);
        for (int i=0;i<books.size();i++){
            if (books[i].getTitle()==control){
                books[i].printInfo();
                a--;
            }
        
            
        }
        if(a){
            cout<<"Book not found!"<<endl;
        }
        

    }
}

int main(){
    
    int choice;
    vector<Book> books;
    while (true){
        cout<<"Menu:"<<endl<<"1. Add a new book"<<endl<<"2. Display all books"<<endl<<"3. Search for a book by title"<<endl<<"4. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        if (choice==1){
            addbooks(books);
            
        }
        else if (choice==2){
            display(books);
        }
        else if (choice ==3){
            search(books);
        }
        else if(choice==4){
            cout<<"Exiting..."<<endl;
            break;
        }
        else{
            cout<<"wrong choice..."<<endl;
        }
    }
    
    return 0;
}
