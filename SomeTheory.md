## **Using `auto cmp` and Custom Comparators in C++**

### **Overview**

In competitive programming or advanced C++ projects, sorting and ordering custom data structures like `priority_queue` often require a **custom comparator**. Using **lambda functions** (`auto cmp`) is a modern and concise way to define such comparators.

---

### **1. What is a Comparator?**

A comparator determines the order in which elements are arranged. In `priority_queue`, this order can be customized by defining a comparator function or lambda.

---

### **2. Key Syntax for `priority_queue`**

The general syntax for `priority_queue` with a custom comparator is:

```cpp
priority_queue<Type, Container, Comparator>
```

- **Type**: The data type of elements (e.g., `int`, `pair<char, int>`).
- **Container**: The underlying container (default is `vector`).
- **Comparator**: A function/lambda to define custom ordering.

---

### **3. Using `auto cmp` with `priority_queue`**

#### **Custom Comparator with Lambda**
```cpp
auto cmp = [](const pair<char, int>& a, const pair<char, int>& b) {
    return a.second < b.second; // Descending order based on second value
};

// Declaring a priority queue with the custom comparator
priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> pq(cmp);
```

---

### **4. Practical Example**

#### **Problem**:
Sort a string based on the frequency of characters in descending order.

#### **Code**:
```cpp
#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

string frequencySort(string s) {
    // Step 1: Count frequencies
    unordered_map<char, int> freq;
    for (char ch : s) {
        freq[ch]++;
    }

    // Step 2: Define custom comparator for priority queue
    auto cmp = [](const pair<char, int>& a, const pair<char, int>& b) {
        return a.second < b.second; // Higher frequency first
    };

    // Step 3: Create priority queue with custom comparator
    priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> pq(cmp);

    // Step 4: Add all character-frequency pairs to the priority queue
    for (const auto& [ch, count] : freq) {
        pq.push({ch, count});
    }

    // Step 5: Construct result string
    string result;
    while (!pq.empty()) {
        auto [ch, count] = pq.top();
        pq.pop();
        result.append(count, ch); // Append 'ch' 'count' times
    }

    return result;
}

int main() {
    string s = "tree";
    cout << "Sorted by frequency: " << frequencySort(s) << "\n";
    return 0;
}
```

#### **Output for Input `s = "tree"`**:
```plaintext
Sorted by frequency: eert
```

---

### **5. Usable Situations**

1. **Sorting Custom Data**:
   - Sorting elements in non-default ways, such as:
     - Based on the second value of a pair.
     - Prioritizing by a custom ranking or score.

2. **Dynamic Scheduling**:
   - Use in priority-based systems (e.g., CPU scheduling, job queues).

3. **Competitive Programming**:
   - Problems involving sorting frequencies, distances, or priorities.

4. **Graph Algorithms**:
   - When using priority queues in **Dijkstra's algorithm** or **Prim's MST**, you can define comparators for custom edge weights.

---

### **Key Points to Remember**

1. **Comparator Logic**:
   - `return a < b`: Ascending order.
   - `return a > b`: Descending order.
   - Customize based on specific fields in complex data types like `pair` or structs.

2. **`decltype(cmp)`**:
   - Lambdas have unnamed types, so use `decltype(cmp)` to deduce their type.

3. **Efficiency**:
   - Priority queues are efficient for dynamic sorting (logarithmic insertion and deletion).

4. **Limitations**:
   - Ensure that your comparator maintains a strict ordering. Incorrect logic can break the behavior of the `priority_queue`.

---

Let me know if you'd like to expand this further or include other examples! 😊
