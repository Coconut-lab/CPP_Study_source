//
// Created by Â÷ÇöÁø on 2025. 6. 5..
//

#ifndef MYSTACK_H
#define MYSTACK_H

void MyStack::push(int n) {
    if (tos==99) {
        throw "stack full";
    }
    tos++; data[tos] = n;
}

int MyStack::pop() {
    if (tos==-1) {
        throw "stack empty";
    }
    int rData = data[tos--];
    return rData;
}

#endif //MYSTACK_H
