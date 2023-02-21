//
// Created by kobi on 11/30/22.
//

#include <vector>
#include <cstdio>
#include <memory>

class A {
public:
    virtual void f() { puts("A::f"); }
    virtual ~A() = default;
    double m_d{};
};
class B : public A {
public:
    void f() override { puts("B::f"); }
    int x{};
};

void func(A* arr) {
    arr[3].m_d = 1.2;
    arr[2].f();
}

int main() {
    // not freed
    auto v1 = std::vector<A*>{new B, new B};
    v1[0]->f();
    func(*v1.data()); // stupid but ... oops ...
    // better
    std::vector<std::unique_ptr<A>> v2;
    v2.push_back(std::make_unique<B>());
    v2.front()->f();
    // func(v2.data()); will not compile
    // OK. but manual new/delete
    B* v3 = new B[10];
    // func(v3); // oops ..
    delete []v3;
    // ok
    std::unique_ptr<B[]> v4 = std::make_unique<B[]>(10);
    v4[1].f();
    // func(v4.get()); // yet another oops...
    // would not compile
    // std::unique_ptr<A[]> v5 = std::make_unique<B[]>(10);
}
