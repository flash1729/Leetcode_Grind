class NumberContainers {
public:
    unordered_map<int, int> ncsys; // Stores index → number mapping
    unordered_map<int, set<int>> revmap; // Stores number → sorted set of indices

    NumberContainers() {}

    void change(int index, int number) {
        // If index already exists in ncsys, remove it from its previous number mapping
        if (ncsys.find(index) != ncsys.end()) {
            int oldNumber = ncsys[index];
            revmap[oldNumber].erase(index);
            if (revmap[oldNumber].empty()) {
                revmap.erase(oldNumber); // Clean up empty sets
            }
        }

        // Insert new mapping
        ncsys[index] = number;
        revmap[number].insert(index);
    }

    int find(int number) {
        // If the number exists, return the smallest index (first element in the set)
        if (revmap.find(number) != revmap.end() && !revmap[number].empty()) {
            return *revmap[number].begin();
        }
        return -1; // Return -1 if the number does not exist
    }
};