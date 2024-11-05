# C++ Standard Template Library (STL)

The **C++ Standard Template Library (STL)** offers a wide array of tools to make coding easier and more efficient. It includes a variety of **data structures, algorithms, iterators, and utilities** that simplify complex coding tasks and boost performance. Below is a breakdown of the main components of the STL:

---

## 1. Containers
Containers are used to store collections of data and are broadly categorized into **Sequence Containers**, **Associative Containers**, and **Container Adapters**.

### Sequence Containers
- `std::vector` — Dynamic array, supports random access.
- `std::deque` — Double-ended queue, allows fast insertions and deletions at both ends.
- `std::list` — Doubly linked list.
- `std::forward_list` — Singly linked list (C++11).
- `std::array` — Fixed-size array (C++11).

### Associative Containers
- `std::set` — Stores unique elements in sorted order.
- `std::multiset` — Allows duplicates in sorted order.
- `std::map` — Stores key-value pairs sorted by key.
- `std::multimap` — Allows duplicate keys in sorted order.

### Unordered Associative Containers (Hash-Based, C++11)
- `std::unordered_set` — Stores unique elements with fast access through hashing.
- `std::unordered_multiset` — Allows duplicates with fast access through hashing.
- `std::unordered_map` — Stores key-value pairs with fast access by hashing the key.
- `std::unordered_multimap` — Allows duplicate keys with fast access through hashing.

### Container Adapters
- `std::stack` — LIFO stack (Last-In-First-Out).
- `std::queue` — FIFO queue (First-In-First-Out).
- `std::priority_queue` — Max-heap by default; stores elements in priority order.

---

## 2. Iterators
Iterators enable traversal through container elements, acting like pointers to elements.

- `begin()` and `end()` — Start and end of a container.
- `rbegin()` and `rend()` — Reverse start and end.
- `cbegin()`, `cend()`, `crbegin()`, `crend()` — Constant iterators.

### Iterator Categories
- **Input Iterator** — For read-only traversal.
- **Output Iterator** — For write-only traversal.
- **Forward Iterator** — For single-pass, read/write traversal.
- **Bidirectional Iterator** — For forward/backward traversal.
- **Random Access Iterator** — For direct access to elements (e.g., `std::vector`).

---

## 3. Algorithms
The STL provides a variety of algorithms that work with containers through iterators, enabling operations without directly modifying the containers.

- **Non-Modifying Algorithms** — `find`, `count`, `equal`, `search`, `mismatch`, etc.
- **Modifying Algorithms** — `copy`, `fill`, `transform`, `swap`, `replace`, etc.
- **Sorting and Related Algorithms** — `sort`, `stable_sort`, `partial_sort`, `nth_element`, `partition`, etc.
- **Numeric Algorithms** — `accumulate`, `inner_product`, `adjacent_difference`, `partial_sum`.
- **Set Algorithms** — `set_union`, `set_intersection`, `set_difference`, `set_symmetric_difference`.

---

## 4. Functors and Function Objects
Functors are classes that define the `operator()` to enable function-like behavior. The STL provides several predefined function objects in `<functional>`:

- **Arithmetic Functors** — `std::plus`, `std::minus`, `std::multiplies`, `std::divides`, etc.
- **Relational Functors** — `std::equal_to`, `std::not_equal_to`, `std::greater`, `std::less`, etc.
- **Logical Functors** — `std::logical_and`, `std::logical_or`, `std::logical_not`.

---

## 5. Utilities
These are helper functions and types that aid in various programming tasks.

- `std::pair` — Holds a pair of values.
- `std::tuple` — Fixed-size collection of values of heterogeneous types (C++11).
- `std::optional` — Represents optional values (C++17).
- `std::variant` — Holds a value of one of several types (C++17).
- `std::any` — Type-safe container for any single value (C++17).

---

## 6. Smart Pointers (C++11 and beyond)
Smart pointers manage dynamic memory automatically, aiding in resource management.

- `std::unique_ptr` — Exclusive ownership of a dynamically allocated object.
- `std::shared_ptr` — Shared ownership using reference counting.
- `std::weak_ptr` — Weak reference to an object managed by `std::shared_ptr`, prevents circular references.

---

## 7. Other Utilities
Additional classes and functions that facilitate various programming tasks:

- `std::move` — Transfers object ownership.
- `std::forward` — Perfect forwarding.
- `std::reference_wrapper` — Wraps references for STL container compatibility.
- `std::chrono` — Time utilities (C++11).
- `std::ratio` — Compile-time rational arithmetic support (C++11).
- `std::thread`, `std::mutex` — Threading and concurrency (C++11).
- `std::filesystem` — File system manipulation (C++17).

---

## 8. Random Number Library (C++11)
Random number generation utilities for creating random data:

- **Random Engines** — `std::default_random_engine`, `std::mt19937`, `std::ranlux24`, etc.
- **Distributions** — `std::uniform_int_distribution`, `std::normal_distribution`, `std::bernoulli_distribution`, etc.

---

These components together offer powerful tools that are essential for building efficient, reusable, and reliable code in C++.
