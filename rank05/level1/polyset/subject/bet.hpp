#pragma once


#include "bag.hpp"
#include "searchable_bag.hpp"

class set
{
    private : 
        searchable_bag& sb;
    public :
        set() = delete;
        set(searchable_bag& copie) : sb(copie){}
        set(const set& copie) : sb(copie.sb){}
        ~set(){}
        set& operator =(set&copie)
        {
            if (this != &copie)
            {
                this->sb = copie.sb;
            }
            return (*this);
        }
        //---------------------------------
        bool has (int value) const
        {
            return (sb.has(value));
        }
        const searchable_bag& get_bag() const 
        {
            return (this->sb);
        }
        //---------------------------------------
        void insert(int value)
        {
            if (!this->has(value))
                sb.insert(value);
        }
	    void insert(int *data , int size)
        {
            for (int i = 0; i < size; i++)
            {
                insert(data[i]);
            }
        }
        //-------------
	    void print() const
        {
            sb.print();
        }
	    void clear()
        {
            sb.clear();
        }

};