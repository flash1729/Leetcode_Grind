# Leetcode_Grind
Collection of LeetCode questions to ace the coding interview!

<h2><a href="https://leetcode.com/problems/longest-common-prefix">14. Longest Common Prefix</a></h2> <img src='https://img.shields.io/badge/Difficulty-Easy-brightgreen' alt='Difficulty: Easy' /><hr><p>Write a function to find the longest common prefix string amongst an array of strings.</p>

<p>If there is no common prefix, return an empty string <code>&quot;&quot;</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> strs = [&quot;flower&quot;,&quot;flow&quot;,&quot;flight&quot;]
<strong>Output:</strong> &quot;fl&quot;
</pre>

This one is about making the lexicographical sorting int he case of string arrays...
The given string array gets sorted lexicographically and then its not always the case that it will get sorted according to length.
### Lexicographical Sorting Note (C++ `std::sort`)

* **std::sort** with `std::string` arrays/orders lexicographically (dictionary order).
* **Implication:** Sorting by lexicographical order **does not** imply sorting by **string length**.
* **Dual Sorting Requirement:** For both lexicographical and length-based ordering, consider custom comparator.

```
// This is for sorting using a compatator to sort according to length

std::sort(words.begin(), words.end(), 
        [](const std::string& a, const std::string& b) {
            return a.length() < b.length();
        }
    );

```
