#include "TAArray.h"
TAArray::TAArray(){
    size = 0;
    elements = new TextArea*[MAX_COMPONENTS];
}
TAArray::~TAArray(){
    for (int i = 0; i < size; i++){
        if (elements[i] != nullptr){
            delete elements[i];
            elements[i] = nullptr;
        }
    }
    delete [] elements;
    elements = nullptr;
}
bool TAArray::addTextArea(TextArea* TA){
    if(isFull()) return false;
    for (int i = 0; i < size; i++){
        //if(TA->overlaps(*elements[i])) return false;
    }
    elements[size++] = TA;
    return true;
}
bool TAArray::addTextArea(TextArea* TA, int index){
    if(isFull()) return false;
    for (int i = 0; i < size; i++){
        //if(TA->overlaps(*elements[i])) return false;
    }
    TextArea* temp1 = TA;
    TextArea* temp2;
    for (int i = index; i < size; i++){
        temp2 = elements[i];
        elements[i] = temp1;
        temp1 = temp2;
    }
    size++;
    return true;
}
TextArea* TAArray::getTextArea(int i) const{
    if(i < 0 || i >= size) return nullptr;
    return elements[i];
}
TextArea* TAArray::getTextArea(const string& id) const{
    for(int i = 0; i < size; i++){
        if(*elements[i] == id) return elements[i];
    }
    return nullptr;
}
TextArea* TAArray::removeTextArea(int i){
    if(i < 0 || i >= size) return nullptr;
    TextArea* t = elements[i];
    while (i < size - 1){
        elements[i] = elements[i + 1];
        ++i;
    }
    --size;
    return t;
}
TextArea* TAArray::removeTextArea(const string& id){
    for(int i = 0; i < size; i++){
        if(*elements[i] == id) return removeTextArea(i);
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
        FlowingTextAreas.addTextArea(new TextArea(*elements[i], flowX, flowY));
        flowX += elements[i]->getDim().width + marginX;
        rowHeight = max(rowHeight, elements[i]->getDim().height);
    }
    return FlowingTextAreas;
}
void TAArray::print() const{
    for(int i = 0; i < size; i++){
        elements[i]->print();
    }
}