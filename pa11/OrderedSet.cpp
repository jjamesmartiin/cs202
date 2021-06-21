#include "OrderedSet.h"
using namespace std;

OrderedSet::OrderedSet(){
}

void OrderedSet::insert(const value_type& value){
    if(used != 4){
        data[used] = value;
    }
    else {
        int temp;
        data[4] = value;
        for (size_t i = 0; i < 5; i++)
        {
            for (size_t j = i+1; j < 5; j++)
            {
                if(data[i] > data[j])
                {
                    temp = data[i];
                    data[i] = data[j];
                    data[j] = temp;
                }
            }
        }
    }
    used++;
}
void OrderedSet::erase(const value_type& target){
    for (size_t i = 0; i < used; i++)
    {
        data[i] = -1;
    }
    used = 0;
}

bool OrderedSet::contains(const value_type& target) const{
    bool trueOrFalse = false;
    if (target != -1) // ignore -1
    {
        for (size_t i = 0; i < Container::used; i++)
        {
            if (Container::data[i] == target)
            {
                trueOrFalse = true;
            }
        }
    }
    return trueOrFalse;
}
