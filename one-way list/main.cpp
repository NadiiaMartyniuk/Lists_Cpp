#include <iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<sstream>

using namespace std;

struct element{
    int number;
    element* next;
};

struct single_list{
    element* head;
    element* tail;
    int counter;
};

void add_tail(single_list&l, int value);
void add_head(single_list&l, int value);
void add_position(single_list&l, int value, int position);
void delete_tail(single_list&l);
void delete_head(single_list&l);
void delete_position(single_list&l, int position);
void show(single_list l);
void IsEmpty(single_list l);
void IsEmpty(single_list l, int znacz);
int IsEmpty(single_list l, float zna);
void get_first_element(single_list l);
void get_last_element(single_list l);
void delete_list(single_list& l);
float Srednia(single_list l);
int Maksymalny(single_list l, int &maxymalnyj);

int main()
{
    single_list l;
    l.head = nullptr;
    l.tail = nullptr;
    l.counter = 0;
    srand( time( NULL ) );
    int opcja, znacz=1;
    int value, position, maxymalnyj;
    float zna=0;
    opcja=0;
    while(opcja!=14){
    cout<<"MENU GLOWNE"<<endl;
    cout<<"1) sprawdzenie czy lista jest pusta"<<endl;
    cout<<"2) dodanie elementu na koniec listy"<<endl;
    cout<<"3) dodanie elementu na poczatek listy"<<endl;
    cout<<"4) dodanie elementu na okreslona pozycje"<<endl;
    cout<<"5) usuniecie elementu z konca listy"<<endl;
    cout<<"6) usuniecie elementu z poczatku listy"<<endl;
    cout<<"7) usuniecie elementu znajdujacego sie na okreslonej pozycji"<<endl;
    cout<<"8) pobranie pierwszego elementu z listy"<<endl;
    cout<<"9) pobranie ostatniego elementu z listy"<<endl;
    cout<<"10) policzenie sredniej arytmetycznej elementow w liscie"<<endl;
    cout<<"11) znalezienie elementu maksymalnego w liscie"<<endl;
    cout<<"12) wyswietlenie calej listy"<<endl;
    cout<<"13) usuniecie calej listy wraz ze zwolnieniem pamiec"<<endl;
    cout<<"14) wyjscie z programu"<<endl<<endl;
    cout<<"Opcja: ";
    cin>>opcja;
    cout<<endl;
    switch (opcja){
    case 1:
        IsEmpty(l, znacz);
        break;
    case 2:
        value = (rand() % 50) + 1;
        add_tail(l, value);
        cout<<"Element zostal dodany na koniec listy"<<endl;
        break;
    case 3:
        value = (rand() % 50) + 1;
        add_head(l, value);
        cout<<"Element zostal dodany na poczatek listy"<<endl;
        break;
    case 4:
        value = (rand() % 50) + 1;
        cout<<"Na jaka pozycje chcesz dodacz element ? ";
        cin>>position;
        if (position<l.counter){
            add_position(l, value, position);
            cout<<"Element zostal dodany "<<endl;
        }
        else {
            if (position==0) {
                add_head(l, value);
                cout<<"Element zostal dodany "<<endl;
            }
            else cout<<"Podana nie poprawna pozycja"<<endl;
        }
        break;
    case 5:
        if(IsEmpty(l, zna)) {
                delete_tail(l);
                cout<<"Element z konca listy zostal usuniety"<<endl;
        }
        else cout<<"Lista jest pusta"<<endl;
        break;
    case 6:
        if(IsEmpty(l, zna)) {
                delete_head(l);
                cout<<"Element z poczatku listy zostal usuniety"<<endl;
        }
        else cout<<"Lista jest pusta"<<endl;
        break;
    case 7:
        if(IsEmpty(l, zna)) {
                cout<<"Z jakiej pozycji chcesz usunacz element ? ";
                cin>>position;
                if (position<l.counter){
                    delete_position(l, position);
                    cout<<"Element zostal usuniety"<<endl;
                }
                else cout<<"Nie ma takiej pozycji"<<endl;
        }
        else cout<<"Lista jest pusta"<<endl;
        break;
    case 8:
        get_first_element(l);
        break;
    case 9:
        get_last_element(l);
        break;
    case 10:
        if(IsEmpty(l, zna)) {
                cout<<"Srednia = "<<Srednia(l)<<endl;
        }
        else cout<<"Lista jest pusta"<<endl;
        break;
    case 11:
        if(IsEmpty(l, zna)) {
                cout<<"Maksymalny element znajduje sie na pozycji "<<Maksymalny(l, maxymalnyj)<<" i jest to element "<<maxymalnyj<<endl;
        }
        else cout<<"Lista jest pusta"<<endl;
        break;
    case 12:
        IsEmpty(l);
        cout<<"Lista: ";
        show(l);
        cout<<endl;
        break;
    case 13:
        delete_list(l);
        cout<<"Lista zostala usunieta, wraz ze zwolnieniem pamieci"<<endl;
        break;
    case 14:
        cout<<"Pa !"<<endl;
        break;
    default:
        cout<<"Nie ma takiej opcji"<<endl;
    }
    cout<<endl;
    }
    return 0;
}

void add_tail(single_list& l, int value){
    element* el = new element;
    el->number = value;
    el->next = nullptr;
    if (l.tail != nullptr)
        l.tail->next = el;
    else
        l.head = el; // Update l.head when the list is empty
    l.tail = el;
    l.counter++;
}

void add_head(single_list& l, int value){
    element* el = new element;
    el->number = value;
    el->next = l.head;
    l.head = el;
    if (l.tail == nullptr)
        l.tail = el; // Update l.tail when the list is empty
    l.counter++;
}

void add_position(single_list&l, int value, int position){
    element* el = new element;
    el=new element;
    el->number=value;
    element* temp = l.head;
    int i=1;
    while(i<position-1){
        temp=temp->next;
        i++;
    }
    el->next=temp->next;
    temp->next=el;
    l.counter++; //
}

void delete_tail(single_list& l) {
    element* temp = l.tail;
    if (l.counter == 1) {
        l.tail = nullptr;
        l.head = nullptr;
    } else {
        element* bef_temp = l.head;
        int i = 1;
        while (i < l.counter - 1) {
            bef_temp = bef_temp->next;
            i++;
        }
        l.tail = bef_temp;
        l.tail->next = nullptr;
    }
    delete temp;
}

void delete_head(single_list& l) {
    element* temp = l.head;
    l.head = l.head->next;
    if (l.counter == 1)
        l.tail = nullptr;
    delete temp;
    l.counter--;
}

void delete_position(single_list& l, int position) {
    if (position == 1) {
        delete_head(l);
        return;
    }
    element* prev = l.head;
    int i = 1;
    while (i < position - 2) {
        prev = prev->next;
        i++;
    }
    element* temp = prev->next;
    prev->next = temp->next;
    delete temp;
    l.counter--;
}


void show(single_list l){
    int i = 1;
    element* temp = l.head;
    while (temp != nullptr) {
        cout << temp->number << " ";
        temp = temp->next;
        i++;
    }
}

void IsEmpty(single_list l){
    if (l.head == nullptr){
        cout<<"Lista jest pusta"<<endl;
    }
}

void IsEmpty(single_list l, int znacz){
    if (l.head == nullptr){
        cout<<"Lista jest pusta"<<endl;
    }
    else cout<<"Lista NIE jest pusta"<<endl;
}

int IsEmpty(single_list l, float zna){
    if (l.head == nullptr) return 0;
    return 1;
}

void get_first_element(single_list l) {
    if (l.head != nullptr) {
        cout<< "Pierwszy element "<<l.head->number<<endl;
    } else {
        cout<<"Lista jest pusta"<<endl;
    }
}

void get_last_element(single_list l) {
    if (l.tail != nullptr) {
        cout<< "Ostatni element "<<l.tail->number<<endl;
    } else {
        cout<<"Lista jest pusta"<<endl;
    }
}

void delete_list(single_list& l) {
    element* current = l.head;
    while (current != nullptr) {
        element* next = current->next;
        delete current;
        current = next;
    }
    l.head = nullptr;
    l.tail = nullptr;
    l.counter = 0;
}

float Srednia(single_list l){
    int i = 1;
    int sum;
    sum=0;
    element* temp = l.head;
    while (temp != nullptr) {
        sum+= temp->number;
        temp = temp->next;
        i++;
    }
    i--;
    return sum/i*1.0;
}

int Maksymalny(single_list l, int &maxymalnyj) {
    int i = 1;
    int maxymalny = 0;
    int pozycja = 0;
    element* temp = l.head;
    maxymalny = temp->number;
    while (temp != nullptr) {
        if (maxymalny < temp->number) {
            maxymalny = temp->number;
            pozycja = i;
        }
        temp = temp->next;
        i++;
    }

    maxymalnyj = maxymalny;
    return pozycja;
}

