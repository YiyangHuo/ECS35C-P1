#include <utility>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

class Book{
public:
    Book(int isbn, string language, string type):_isbn(isbn), _language(move(language)), _type(move(type))
    {
    }
    bool operator < (const Book& rhs){
        return this->_isbn < rhs._isbn;
    }
    bool operator > (const Book& rhs){
        return !(*this < rhs);
    }
    int _isbn;
    string _language;
    string _type; // 0 for new 1 for used 2 for digital

};
vector<Book> getList( string & newbooks){
    fstream file(newbooks);
    vector<Book> rtrlist;
    string line;
    vector<string> templist;
    string temp;
    while (getline(file, line)){
        for(int i =0 ; i< line.size(); i++){
            temp.push_back(line[i]);
            if(line[i] == ',' || (i+1) == line.size()){
                if(temp[temp.size()-1] == ','){
                    temp.pop_back();
                }
                templist.push_back(temp);
                temp = "";
                if(templist.size() == 3) {
                    rtrlist.push_back(Book(stoi(templist[0]), templist[1], templist[2]));
                    templist.clear();
                }
            }



        }
    }
    file.close();
    file.clear();
    return rtrlist;
}

int main(int argc, char** argv) {
    string newbooks = argv[1];
    string request = argv[2];
    vector<Book> booklist = getList(newbooks);
    sort(booklist.begin(), booklist.end());
    cout<<"Choice of search method ([l]inear, [b]inary)?"<<endl;

    return 0;
}




