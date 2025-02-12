#include "TAArray.h"
TAArray::TAArray(){
    size = 0;
    elements = new TextArea*[MAX_COMPONENTS];
    for (int i = 0; i < MAX_COMPONENTS; i++) {
        elements[i] = nullptr;
    }
}
TAArray::~TAArray(){
    for (int i = 0; i < size; i++){
        if (elements[i]){
            delete elements[i];
            elements[i] = nullptr;
        }
    }
    if(elements){
        delete [] elements;
        elements = nullptr;
    }
}
bool TAArray::add(TextArea* TA){
    if(isFull()) return false;
    for (int i = 0; i < size; i++){
        //if(TA->overlaps(*elements[i])) return false;
    }
    elements[size++] = TA;
    return true;
}
bool TAArray::add(TextArea* TA, int index){
    if(isFull()) return false;
    if(index < 0 || index > size) return false;
    for (int i = 0; i < size; i++){
        //if(TA->overlaps(*elements[i])) return false;
    }
    for (int i = size; i > index; i--) {
        elements[i] = elements[i - 1];
    }
    elements[index] = TA;
    size++;
    return true;
}
TextArea* TAArray::get(int i) const{
    if(i < 0 || i >= size) return nullptr;
    return elements[i];
}
TextArea* TAArray::get(const string& id) const{
    for(int i = 0; i < size; i++){
        if(*elements[i] == id) return elements[i];
    }
    return nullptr;
}
TextArea* TAArray::remove(int i){
    if(i < 0 || i >= size) return nullptr;
    TextArea* t = elements[i];
    while (i < size - 1){
        elements[i] = elements[i + 1];
        ++i;
    }
    elements[--size] = nullptr;
    return t;
}
TextArea* TAArray::remove(const string& id){
    for(int i = 0; i < size; i++){
        if(*elements[i] == id) return remove(i);
    }
    return nullptr;
}
TAArray TAArray::getFlowingTextAreas(int width, int height, int marginX, int marginY){
    int flowX = marginX;
    int flowY = marginY;
    int rowHeight = 0;
    TAArray FlowingTextAreas;
    for(int i = 0; i < size; i++){
        if(flowX + elements[i]->getDim().x > width - marginX){
            flowX = marginX;
            flowY += rowHeight + marginY;
            rowHeight = 0;
        }
        else if(flowY + elements[i]->getDim().y > height - marginY) break;
        FlowingTextAreas.add(new TextArea(*elements[i], flowX, flowY));
        flowX += elements[i]->getDim().width + marginX;
        rowHeight = max(rowHeight, elements[i]->getDim().height);
    }
    return FlowingTextAreas;
}
void TAArray::print() const{
    for(int i = 0; i < size; i++){
        if(elements[i]) elements[i]->print();
    }
}