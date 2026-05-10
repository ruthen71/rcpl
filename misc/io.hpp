#pragma once

#include <iostream>

// I/O
// input
template <class... T> void in(T&... a) { (std::cin >> ... >> a); }
void scan() {}
template <class Head, class... Tail> void scan(Head& head, Tail&... tail) {
    in(head);
    scan(tail...);
}
// output
template <class... T> void out(const T&... a) { (std::cout << ... << a); }
void print() { out('\n'); }
template <class Head, class... Tail> void print(Head&& head, Tail&&... tail) {
    out(head);
    if (sizeof...(Tail)) out(' ');
    print(tail...);
}
// output for interactive problems
void printi() { std::cout << std::endl; }
template <class Head, class... Tail> void printi(Head&& head, Tail&&... tail) {
    out(head);
    if (sizeof...(Tail)) out(' ');
    printi(tail...);
}
