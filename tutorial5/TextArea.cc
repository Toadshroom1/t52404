#include "TextArea.h"
TextArea::TextArea(){

}
TextArea::TextArea(int x, int y, int width, int height, const string& id, const string& text, RGB fill, RGB border){
    dim.x = x;
    dim.y = y;
    dim.width = width;
    dim.height = height;
    this->id = id;
    this->text = text;
    this->fill = fill;
    this->border = border;
}
TextArea::TextArea(Rectangle dim, const string& id, const string& text, RGB fill, RGB border){
    this->dim = dim;
    this->id = id;
    this->text = text;
    this->fill = fill;
    this->border = border;
}
TextArea::TextArea(const TextArea& TA){
    this->dim = TA.getDim();
    this->id = TA.getID();
    this->text = TA.getText();
    this->fill = TA.getFill();
    this->border = TA.getBorder();
}
TextArea::TextArea(const TextArea& TA, int x, int y){
    this->dim = TA.getDim();
    dim.x = x;
    dim.y = y;
    this->id = TA.getID();
    this->text = TA.getText();
    this->fill = TA.getFill();
    this->border = TA.getBorder();
}
void TextArea::draw(Display *display, Window win, GC gc, int x, int y){
    int marginX = 5;
    int marginY = 15;
    XSetForeground(display, gc, fill.getColour());
    XFillRectangle(display, win, gc, dim.x + x, dim.y + y, dim.width, dim.height);
    XSetForeground(display, gc, border.getColour());
    XDrawRectangle(display, win, gc, dim.x + x, dim.y + y, dim.width, dim.height);
    XDrawString(display, win, gc, dim.x + x + marginX, dim.y + y + marginY, text.c_str(), text.length() + 1);
}
bool TextArea::overlaps(const TextArea& TA) const{return dim.overlaps(TA.getDim());}
bool TextArea::operator==(const string& id) const{return this->id == id;}
void TextArea::print() const{
    cout << left;
    cout << setw(20) << "TextArea ID: " << id << endl;
    cout << setw(20) << "Preferred Location: " << dim.x << ", " << dim.y << endl;
    cout << setw(20) << "Size: " << dim.width << " x " << dim.height << endl;
    cout << setw(20) << "Text: " << text << endl;
}