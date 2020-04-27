#pragma once
#include <list>
#include <iostream>
#include "Booking.h"
#include <algorithm>

template <class Item>
class Repo {
    std::list <Item> items;
    public:
        void addItem(Item item);
        std::list<Item> getAll();
        void update(Item oldItem, Item newItem);
        void del(Item item);
        int getSize();
};

template <class Item>
void Repo<Item>::addItem(Item item){
    this->items.push_back( item );
}
template <class Item>
std::list<Item> Repo<Item>::getAll() {
    return this->items;
}

template <class Item>
int Repo<Item>::getSize() 
{
    return this->items.size();
}

template <class Item>
void Repo<Item>::update(Item oldItem, Item newItem)
{
    auto el =std::find( this->items.begin(), this->items.end(), oldItem );
    *el = newItem;
}
template <class Item>
void Repo<Item>::del(Item item )
{
    auto el =std::find( this->items.begin(), this->items.end(), item );
    this->items.erase(el);
}
