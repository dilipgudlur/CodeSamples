#include <iostream>
#include <stack>
#include <queue>
#include <limits.h>

using namespace std;

/*3.6 Animal Shelter: An animal shelter, which holds only dogs and cats, operates on a strictly"first in, first out" basis. 
People must adopt either the "oldest" (based on arrival time) of all animals at the shelter, or they can select whether they 
would prefer a dog or a cat (and will receive the oldest animal of that type). They cannot select which specific animal they 
would like. Create the data structures to maintain this system and implement operations such as enqueue, dequeueAny, dequeueDog, and dequeueCat. 
You may use the built-in Linkedlist data structure. 
*/
//This is still incomplete
class Animal {
protected:
    int order = 0;
    string animalType;
    
    
public:
    Animal(string name) {
        animalType = name;
    }
    void enqueue(string name); //pushes an element into the queue
    void dequeueAny(); //removes an element from the queue
    //virtual void dequeueDog() = 0; //to be implemented by Dog class
    //virtual void dequeueCat() = 0; //to be implemented by Cat class
};

void Animal::enqueue(string name) {
}

void Animal::dequeueAny() {
}

//Dog needs access to members of Animal
class Dog : protected Animal {
private:
    queue<Dog> dogQueue;
public:
    void dequeueDog();
};

void Dog::dequeueDog() {
}

//Cat needs access to members of Animal
class Cat : protected Animal {
private:
    queue<Cat> catQueue;
public:
    void dequeueCat();
};

void Cat::dequeueCat() {
}


int main() {

    queue<Animal> animalQueue;
    string input[] = {"dog","dog","dog","cat","cat"};
    animalQueue.push(input[0]);
    animalQueue.push(input[1]);
    animalQueue.push(input[2]);
    animalQueue.push(input[3]);
    animalQueue.push(input[4]);
    return 0;   
}
