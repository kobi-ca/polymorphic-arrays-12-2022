#include <cstdio>

class A {
public:
    A() {}
    virtual void f() { puts("A::f"); }
    virtual ~A() = default;
    double m_d;
};
class B : public A {
public:
    B() {}
    void f() override { puts("B::f"); }
    int x;
};

void func(A* arr) {
    arr[3].m_d = 1.2;
    arr[2].f();
}

int main()
{
    A* ptr = new B[5];
    func(ptr);
    //delete[] ptr;
    return 0;
}
