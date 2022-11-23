// main.cpp文件
#include "animal.h"
int main()
{
    mammal* n_cat = new cat("tomcat", 18, 40.5);
    cout << "--------------------------------" << endl;
    mammal* n_dog = new dog("tomcat", 18, 40.5);
    cout << "--------------------------------" << endl;
    mammal* n_horse = new horse("马马", 20, 80);
    cout << "--------------------------------" << endl;
    mammal* n_pig = new pig("猪猪", 25, 100.1);
    cout << "--------------------------------" << endl;
    delete n_cat;
    delete n_dog;
    delete n_horse;
    delete n_pig;
    cout << "--------------------------------" << endl;
    cat   cc("tomcat", 18, 40.5);
    dog   dd("tomcat", 18, 40.5);
    horse hh("马马", 20, 80);
    pig   pp("猪猪", 25, 100.1);
    return 0;
}