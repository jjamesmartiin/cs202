#include "Container.h"
#include <iostream>
using namespace std;

Container::Container(){
    Container::used = 0;
    
}

Container::size_type Container::size() const{
    return Container::used;
}

bool Container::empty() const{
    return Container::used == 0;
}

void Container::insert(const value_type& value){
    Container::data[Container::used] = value;
    Container::used += 1;
}

