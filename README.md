# LRU Cache Implementation

This project implements a **Least Recently Used (LRU) Cache** using C++. It is designed as a part of Data Structures and Algorithms (DSA) practice and showcases how caching strategies can be efficiently implemented using a combination of a hash map and a doubly linked list.

---

## 📌 What is an LRU Cache?

An **LRU Cache** is a type of cache that discards the **least recently used** items first when it reaches its maximum capacity.

- **Use case**: Useful in scenarios like memory management, CPU caching, or page replacement algorithms.
- **Goal**: Provide `O(1)` time complexity for both `get()` and `put()` operations.

---

## 🧠 Core Concepts Used

- **Doubly Linked List**: To store cache keys in order of usage.
- **Hash Map (unordered_map)**: To provide quick access to list nodes.
- **Pointers/References**: To move nodes efficiently within the list.

---

## ⚙️ Features

- ✅ `get(key)`: Returns the value of the key if present, else `-1`.
- ✅ `put(key, value)`: Inserts or updates the key with the given value. If the cache exceeds capacity, it evicts the least recently used item.
- ✅ Constant time complexity `O(1)` for both operations.

---

## 🧾 Example

```cpp
LRUCache cache(2); // capacity = 2

cache.put(1, 10);
cache.put(2, 20);
cache.get(1);      // returns 10, makes key 1 most recently used
cache.put(3, 30);  // evicts key 2
cache.get(2);      // returns -1 (not found)
cache.get(3);      // returns 30
```
## 📸 LRU Cache Output Demo

The following screenshot shows sample output after inserting and accessing keys from the cache:

![LRU Cache Output Screenshot](https://github.com/Ha-r-i/LRU-Cache/blob/main/.vscode/image.png?raw=true)



