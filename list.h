#pragma once

template <class T>
struct elem {
    T value;
    struct elem<T>* link;
    
    elem() {}
    elem(const T& val) : value(val), link(nullptr) {}
};

template <class T>
class List {
    struct elem<T>* head;
    int noe;
public:
    List();
    ~List();
    inline int Count() { return this->noe; }
    void Add(const T&);
    void RemoveAt(int);
    T& operator[](int);
};

template <class T>
List<T>::List() {
    this->noe = 0;
    this->head = nullptr;
}

template <class T>
List<T>::~List() {
    struct elem<T> *Element = this->head;
    while (Element != nullptr) {
        struct elem<T> *prev = Element;
        Element = Element->link;
        delete prev;
    }
}

template <class T>
void List<T>::Add(const T& element) {
    struct elem<T>* newElement = new elem<T>(element);

    if (this->head == nullptr) {
        this->head = newElement;
    } else {
        struct elem<T>* Element = this->head;
        while (Element->link != nullptr)
            Element = Element->link;
        Element->link = newElement;
    }
    this->noe++;
}

template <class T>
void List<T>::RemoveAt(int i) {
    if (i >= noe)
        return;

    struct elem<T> *e = this->head, *prev = nullptr;

    if (i == 0) {
        this->head = this->head->link;
        delete e;
    } else {
        while (i != 0) {
            prev = e;
            e = e->link;
            i--;
        }
        prev->link = e->link;
        delete e;
    }
    this->noe--;
}

template <class T>
T& List<T>::operator[](int n) {
    if (n >= this->noe)
        throw 1;

    struct elem<T> *e = this->head;
    while (n != 0) {
        e = e->link;
        n--;
    }
    return e->value;
}

