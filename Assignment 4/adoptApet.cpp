#include <iostream>
#include <queue>
#include <string>
using namespace std;
//Time Spent : 29 minutes
// Technique: Maintain a queue
struct Pet {
    string name;
    string species;
    int timeInShelter;

    Pet(string n, string s, int t) : name(n), species(s), timeInShelter(t) {}
};

int main() {
    queue<Pet> dogQueue, catQueue;
    queue<string> adoptionOrder;

    // Initial pets in the shelter
    dogQueue.push(Pet("Sadie", "dog", 4));
    catQueue.push(Pet("Woof", "cat", 7));
    dogQueue.push(Pet("Chirpy", "dog", 2));
    dogQueue.push(Pet("Lola", "dog", 1));

    int numQueries;
    cin >> numQueries;

    for (int i = 0; i < numQueries; i++) {
        string name, type;
        cin >> name >> type;

        if (type == "person") {
            string preferredSpecies;
            cin >> preferredSpecies;

            if (preferredSpecies == "dog" && !dogQueue.empty()) {
                adoptionOrder.push(dogQueue.front().name);
                dogQueue.pop();
            } else if (preferredSpecies == "cat" && !catQueue.empty()) {
                adoptionOrder.push(catQueue.front().name);
                catQueue.pop();
            } else if (!dogQueue.empty()) {
                adoptionOrder.push(dogQueue.front().name);
                dogQueue.pop();
            } else if (!catQueue.empty()) {
                adoptionOrder.push(catQueue.front().name);
                catQueue.pop();
            }
        } else {
            string species;
            cin >> species;
            if (species == "dog") {
                dogQueue.push(Pet(name, species, 0));
            } else {
                catQueue.push(Pet(name, species, 0));
            }
        }
    }

    // Print adoption order
    while (!adoptionOrder.empty()) {
        cout << adoptionOrder.front() << ", " << (adoptionOrder.front() == "Sadie" ? "dog" : "cat") << endl;
        adoptionOrder.pop();
    }

    return 0;
}
