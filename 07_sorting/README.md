# 07 - Sorting Algorithms

This directory contains C++ implementations of classic sorting problems using STL `sort()`, `stable_sort()`, custom comparator functions, and additional techniques like duplicate removal or digit reversal.

| No | Title                  | Problem Link                                          | Algorithm Type         | Description |
|----|------------------------|-------------------------------------------------------|------------------------|-------------|
| 1  | Word Sort              | [1181](https://www.acmicpc.net/problem/1181)         | Custom sort + erase    | Sort strings by length, then lexicographically. Remove duplicates. |
| 2  | Age Order              | [10814](https://www.acmicpc.net/problem/10814)       | Stable sort + struct   | Sort members by age. Keep input order for same age using `stable_sort`. |
| 3  | Sort Coordinates       | [11650](https://www.acmicpc.net/problem/11650)       | Custom sort + struct   | Sort coordinates by x, then y. |
| 4  | Reverse Element Sort   | [5648](https://www.acmicpc.net/problem/5648)         | Reverse + sort         | Reverse each number’s digits and sort the result. |

---

All files are written in English with clear structure and comment style, using `vector`, `struct`, `sort()`, and C++ STL idioms.
