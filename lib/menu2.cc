#include <iostream>
#include <cstring>
class AppState{};


typedef void (*Callback) (AppState*);

class MenuItem{

    public:
    char *title;
    Callback clickCallback;
    MenuItem(const char* title, Callback callback){
        strcpy(this->title, title);
        this->clickCallback = callback;
    }
    MenuItem(){}
};

class Menu{
    private:
        int current = 0;
        int at = 0;
        int size;
        MenuItem *items;
    public:
        Menu(int size){
            this->size = size;
            this->items = new MenuItem[size];
        }
        void addItem(MenuItem item){
            std::cout << "ADD " << item.title;
            // if(at >= size)throw "Bad Menu Size";
            // this->items[at++] = item;
        }
        void render(){
            system("clear");
            for(int i = 0; i < this->at; i++){
                std::cout << this->items[i].title;
            }
        }
};