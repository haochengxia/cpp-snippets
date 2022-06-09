// 智能指针
// Created by Percy on 2022/6/9.
//

// holder 和 trule : holder类型独占一个对象 trule则可以使对象的拥有者从一个holder转变为另一个

// 异常引发内存泄露

//void do_something()
//{
//    Something* ptr = new Something;
//
//    ptr->perform();
//    ...
//
//    delete ptr;
//}

// 若delete之前抛出了异常，该对象不会被销毁

//void do_something1()
//{
//    Something* ptr = 0;
//    try {
//        ptr = new Something;
//
//        ptr->perform();
//        ...
//    }
//    catch (...) {
//        delete ptr;
//        throw;
//    }
//    delete ptr;
//}

// 一种解决方案如上，但是异常执行路径开始影响正常路径了

template <typename T>
class Holder;

template <typename T>
class Trule {
private:
    T* ptr;

public:
    Trule(Holder<T>& h) {
        ptr = h.get();
        h.relase();
    }

    Trule(Trule<T> const& t) {
        ptr = t.ptr;
        const_cast<Trule<T>&>(t).ptr = 0;
    }

    ~Trule() {
        delete ptr;
    }

private:
    Trule(Trule<T>&);
    Trule<T>& operator=(Trule<T>&);
    friend class Holder<T>;
};

template <typename T>
class Holder {
private:
    T* ptr;
public:
    Holder() : ptr(0) {}

    explicit Holder(T* p) : ptr(p) {}

    ~Holder() {
        delete ptr;
    }

    Holder<T>& operator= (T* p) {
        delete ptr;
        ptr = p;
        return *this;
    }

    T& operator* () const {
        return *ptr;
    }

    T* operator-> () const {
        return ptr;
    }

    T* get() const {
        return ptr;
    }

    void release() {
        ptr = 0;
    }

    void exchange_with (Holder<T>& h) {
        swap(ptr, h.ptr);
    }

    void exchange_with (T*& p) {
        swap(ptr, p);
    }

    Holder (Trule<T> const& t) {
        ptr = t.ptr;
        const_cast<Trule<T>&>(t).ptr = 0;
    }

    Holder<T>& operator= (Trule<T> const& t) {
        delete ptr;
        ptr = t.ptr;
        const_cast<Trule<T>&>(t).ptr = 0;
        return *this;
    }

private:
    Holder (Holder<T> const&);
    Holder<T>& operator= (Holder<T> const&);
};


// TODO: 实现引用计数
