#include "arrayList.h"

template<typename T>
void ArrayList<T>::add(T item){
    this->data[this->idx] = item;
    this->next[this->idx] = this->head;
    this->head = this->idx++;
    this->number++;
}
template<class T>
void ArrayList<T>::splice(int position){
    this->next[position] = this->next[this->next[position]];
    this->next[this->next[position]] = this->rear;
    this->number--;
}
template<class T>
int ArrayList<T>::find(T item){
    for(int i = this->head;i != this->rear;i = this->next[i]) {
        if(this->data[i] == item){
            return i;
        }
    }
    return this->rear;
}

template<class T>
ArrayList<T>::ArrayList(){
    this->idx = 0;
    this->number = 0;
    this->head = this->rear;
}

template<class T>
void ArrayList<T>::reset(){
    this->number = 0;
    this->head = this->rears;
}

template<class T>
int ArrayList<T>::getNextCount(int count){
    return this->next[count];
}

template<class T>
T ArrayList<T>::getData(int count){
    cout << "data is ";
    return this->data[count];
}

template<class T>
void ArrayList<T>::show(){
    for(int i = this->head;i != this->rear;i = this->next[i]){
        cout << "data:  " << this->data[i] << endl;
        cout << "next:  " << this->next[i] << endl;
        cout << "--------------------------" << endl;
    }
}