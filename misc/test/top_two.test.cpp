#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include <array>
#include <cassert>
#include <iostream>

#include "../top_two.hpp"

void test1_top_two_add() {
    TopTwo<int, 1000> t;
    {
        // (1, -inf)
        bool f = t.add(1);
        assert(f == true and t.a == 1 and t.b == -1000);
    }
    {
        // (1, 1)
        bool f = t.add(1);
        assert(f == true and t.a == 1 and t.b == 1);
    }
    {
        // (1, 1)
        bool f = t.add(0);
        assert(f == false and t.a == 1 and t.b == 1);
    }
    {
        // (1, 1)
        bool f = t.add(1);
        assert(f == false and t.a == 1 and t.b == 1);
    }
    {
        // (2, 1)
        bool f = t.add(2);
        assert(f == true and t.a == 2 and t.b == 1);
    }
    {
        // (4, 2)
        bool f = t.add(4);
        assert(f == true and t.a == 4 and t.b == 2);
    }
    {
        // (4, 3)
        bool f = t.add(3);
        assert(f == true and t.a == 4 and t.b == 3);
    }
    {
        // (4, 3)
        bool f = t.add(3);
        assert(f == false and t.a == 4 and t.b == 3);
    }
}

void test2_top_two_swap() {
    TopTwo<int, 1000> t(0, 1);
    assert(t.a == 1 and t.b == 0);
}

int main() {
    test1_top_two_add();
    test2_top_two_swap();
    int a, b;
    std::cin >> a >> b;
    std::cout << a + b << '\n';
    return 0;
}
