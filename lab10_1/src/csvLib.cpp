//
// Created by Franek on 04.01.2022.
//

#include <iostream>
#include <fstream>
#include "../include/csvLib.h"
#include "../include/MyException.h"

csvLib::csvLib(std::string path, char separator) : path(path), separator(separator){};

void csvLib::read(){
    using namespace std;

    ifstream input;
    try{
        input.open(this->path);
        if(input.is_open()) {
            char c;
            string temp;
            while(!input.eof()) {
                input.get(c);
                if(c != this->separator)
                    temp.push_back(c);
                else{
                    this->content.push_back(temp);
                    cout << this->content.back() << "\t";
                    temp = "";
                }
            }
            //ostatni jesli na koncu nie ma separatora
            if(temp != ""){
                temp.pop_back();
                this->content.push_back(temp);
                cout << this->content.back();
            }
            cout << endl;
            input.close();
        }
        else{
            throw invalid_argument("nie udalo sie otworzyc pliku!");
        }
    } catch(const invalid_argument& e) {
        std::cerr  << "Rodzaj bledu: " << e.what() << "\n";
        exit(1);
    }
    catch(...){
        std::cerr << "Wystapil jakis dziwny blad!\n";
    }
}

void csvLib::write(std::string newPath){
    using namespace std;

    if(newPath != "")
        this->path = newPath;

    ofstream output(this->path);
    try{
        if(output.is_open()) {
            vector<string>::iterator ptr;
            for (ptr = this->content.begin(); ptr < this->content.end(); ptr++)
                output << *ptr << "\t";
            output.close();
        } else {
            throw invalid_argument("nie udalo sie otworzyc pliku!");
        }
    } catch(const invalid_argument& e) {
        std::cerr  << "Rodzaj bledu: " << e.what() << "\n";
        exit(1);
    }
    catch(...){
        std::cerr << "Wystapil jakis dziwny blad!\n";
    }
}