#ifndef TAARRAY_H
#define TAARRAY_H
#include "defs.h"
#include "TextArea.h"
class TAArray{
    private:
        TextArea** elements;
        int size;
    public:
        //Constructors/dewstructors
        TAArray();
        ~TAArray();
        //Adds a TextArea to the dynamic list
        bool add(TextArea* TA);
        bool add(TextArea* TA, int i);
        //Retrives a TextArea from the dynamic list from a name or index
        TextArea* get(int i) const;
        TextArea* get(const string& name) const;
        //Removes and retrives a TextArea from the dynamic list from a name or index
        TextArea* remove(int i);
        TextArea* remove(const string& name);
        //Getters
        bool isFull() const{return size >= MAX_COMPONENTS;}
        int getSize() const{return size;}
        //Creates the flowing layout
        TAArray getFlowingTextAreas(int width, int height, int marginX, int marginY);
        //Print function
        void print() const;
};
#endif