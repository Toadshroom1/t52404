#ifndef TEXTAREA_H
#define TEXTAREA_H
#include "defs.h"
#include "RGB.h"
class TextArea
{
private:
    Rectangle dim;
    string text, id;
    RGB fill, border;
public:
    //Constructors
    TextArea();
    TextArea(int x, int y, int width, int height, const string& id, const string& text, RGB fill = RGB::WHITE(), RGB border = RGB::BLACK());
    TextArea(Rectangle dim, const string& id, const string& text, RGB fill = RGB::WHITE(), RGB border = RGB::BLACK());
    TextArea(const TextArea& TA);
    TextArea(const TextArea& TA, int x, int y);
    //Getters/setters
    Rectangle getDim() const{return dim;}
    string getText() const{return text;}
    string getID() const{return id;}
    RGB getFill() const{return fill;}
    RGB getBorder() const{return border;}
    void setHeight(int height){dim.height = height;}
    void setText(const string& text){this->text = text;}
    void setFill(const RGB& fill){this->fill = fill;}
    void setBorder(const RGB& border){this->border = border;}
    //Draw
    void draw(Display *display, Window win, GC gc, int x, int y);
    //Comperasions
    bool overlaps(const TextArea& TA) const;
    bool operator==(const string& id) const;
    //Print function
    void print() const;
};
#endif