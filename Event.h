//
// Created by Lorenzo Nuti and Paolo Valcepina on 13/04/17.
//

#ifndef CATULA_EVENT_H
#define CATULA_EVENT_H

#include <list>

template<typename T, typename M, typename A=void, typename B=void>
class Event {
public:
    Event(M method) : method(method) {}

    void add(T object) {
        list.push_back(object);
    }

    void remove(T object) {
        list.remove(object);
    }

    void notify(A param1, B param2) const {
        for (auto it = list.begin(), end = list.end(); it != end; it++) {
            ((*it)->*(method))(param1, param2);
        }
    }

    void operator+=(T object) {
        add(object);
    }

    void operator-=(T object) {
        remove(object);
    }

private:
    std::list<T> list;
    M method;
};

template<typename T, typename M, typename A>
class Event<T, M, A, void> {
public:
    Event(M method) : method(method) {}

    void add(T object) {
        list.push_back(object);
    }

    void remove(T object) {
        list.remove(object);
    }

    void notify(A param) const {
        for (auto it = list.begin(), end = list.end(); it != end; it++) {
            ((*it)->*(method))(param);
        }
    }

    void operator+=(T object) {
        add(object);
    }

    void operator-=(T object) {
        remove(object);
    }

private:
    std::list<T> list;
    M method;
};

template<typename T, typename M>
class Event<T, M, void, void> {
public:
    Event(M method) : method(method) {}

    void add(T object) {
        list.push_back(object);
    }

    void remove(T object) {
        list.remove(object);
    }

    void notify() const {
        for (auto it = list.begin(), end = list.end(); it != end; it++) {
            ((*it)->*(method))();
        }
    }

    void operator+=(T object) {
        add(object);
    }

    void operator-=(T object) {
        remove(object);
    }

private:
    std::list<T> list;
    M method;
};


#endif //CATULA_EVENT_H
