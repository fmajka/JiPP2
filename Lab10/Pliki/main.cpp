#include <iostream>
#include <fstream>
#include <vector>
#include <array>

#define FILENAME "../data.csv"
#define DATA_TYPES 4
#define SEPARATOR ','
#define PRINT_READ false

//std::vector<std::array<std::string, 4> >;
std::vector <std::string> data[DATA_TYPES];

void read(std::string filename){
    using namespace std;

    ifstream input;
        input.open(filename);

        if(input.is_open()) {
            int n = 0;          //indeks tablicy z danymi
            char c;         //kolejny wczytany znak
            string temp;    //ciag do wpisania do wektora danych

            while (!input.eof()) {
                input.get(c);
                if (c != SEPARATOR && c != '\n')
                    temp.push_back(c);
                else {
                    data[n].push_back(temp);
                    //wypisz przeczytane informacje (debug)
                    if(PRINT_READ){
                        cout << data[n].back();
                        if(c == SEPARATOR)
                            cout << "\t";
                        else
                            cout << "\n";
                    }
                    n = (n+1) % DATA_TYPES;
                    temp = "";
                }
            }

            //ostatni jesli na koncu nie ma separatora
            if (temp != "") {
                temp.pop_back();
                data[n].push_back(temp);
                if(PRINT_READ)
                    cout << data[n].back();
            }
            if(PRINT_READ)
                cout << endl;
            input.close();
            cout << "Wczytano z: " << filename << endl;
        }
        else{
            cout << "Nie udalo sie otworzyc pliku do odczytu!" << endl;
        }
}

void write(std::string filename, bool autobus){
    using namespace std;

    ofstream output;
    output.open(filename);

    if(output.is_open()) {
        vector<string>::iterator ptr[DATA_TYPES];
        //inicjalizacja
        for(int i=0;i<DATA_TYPES;i++){
            ptr[i] = data[i].begin();
            //wypisz pierszą linijkę z informacjami
            output << *ptr[i] << "\t";
            ptr[i]++;
        }
        output << "\n";
        //zapisuj po kolei
        while(ptr[0] < data[0].end()){
            bool skip = false;
            for(int i=0;i<DATA_TYPES;i++) {
                //przy pierwszym elemencie wiersza sprawdz, czy wypisuje wlasciwe dane
                if(i == 0)
                    if((autobus && ptr[i]->length() < 3) || (!autobus && ptr[i]->length() == 3))
                        skip = true;

                if(!skip)
                    output << *ptr[i] << "\t";
                ptr[i]++;
            }
            if(!skip)
                output << "\n";
        }
        output.close();
        cout << "Zapisano do: " << filename << endl;
    } else {
        cout << "Nie udalo sie otworzyc pliku do zapisu!" << endl;
    }
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    read(FILENAME);
    write("../tramwaje.csv", false);
    write("../autobusy.csv", true);
    return 0;
}
