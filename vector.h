//
// Created by Shawn Yang on 10/12/18.
//

#ifndef POLYNOMIAL_CALC_VECTOR_H
#define POLYNOMIAL_CALC_VECTOR_H

template <class T>
class Vector {
    int s;
    T *data;

public:
    Vector();
    // cpy constructor
    Vector(Vector<T> &);
    void push_back(const T&);
    T& at(int);
    int size();
    void erase(int i);

};

template<class T>
Vector<T>::Vector() {
    s=0;
    data = new T[1000];
}

template <class T>
Vector<T>::Vector(Vector<T> & vec) {
    s = vec.size();
    data = new T [1000];
    for (int i=0; i<vec.size();i++){
        data[i]=vec.at(i);
    }
}


template<class T>
void Vector<T>::push_back(const T &obj) {
    if (s==1000){
        // allocate more space
    }
    else{
        data[s++] = obj;
    }
}

template<class T>
T& Vector<T>::at(int i) {
    if (i >= s){
        // out of bound
    }

    return data[i];
}

template <class T>
int Vector<T>::size() {
    return s;
}

template <class T>
void Vector<T>::erase(int index) {
    if (index>=s){
        //out of bound
    }
    for (int i=index; i<s-1; i++){
        data[i]=data[i+1];
    }
    s--;
}


#endif //POLYNOMIAL_CALC_VECTOR_H
