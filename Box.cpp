#include <iostream>
using namespace std;

// Box class definition
class Box {
private:
    // Private member variables
    int length;
    int breadth;
    int height;

public:
    // Default Constructor
    // This is called when a Box object is created without any parameters
    // It initializes all dimensions to 1
    Box() {
        length = 1;
        breadth = 1;
        height = 1;
        cout << "Default constructor called!" << endl;
    }

    // Parameterized Constructor
    // This is called when a Box object is created with specific dimensions
    // Parameters: l (length), b (breadth), h (height)
    Box(int l, int b, int h) {
        length = l;
        breadth = b;
        height = h;
        cout << "Parameterized constructor called!" << endl;
    }

    // Copy Constructor
    // This is called when a new Box object is created by copying an existing one
    // Parameter: box (reference to the Box object to be copied)
    Box(const Box& box) {
        length = box.length;
        breadth = box.breadth;
        height = box.height;
        cout << "Copy constructor called!" << endl;
    }

    // Destructor
    // This is automatically called when a Box object is destroyed
    // It's called when the object goes out of scope or is explicitly deleted
    ~Box() {
        cout << "Destructor called for box with volume: " << volume() << endl;
    }

    // Member function to calculate volume
    // Returns the product of length, breadth, and height
    int volume() {
        return length * breadth * height;
    }
};

int main() {
    cout << "Creating first box using default constructor..." << endl;
    Box box1;  // Default constructor called

    cout << "\nCreating second box using parameterized constructor..." << endl;
    Box box2(2, 3, 4);  // Parameterized constructor called

    cout << "\nCreating third box using copy constructor..." << endl;
    Box box3(box2);  // Copy constructor called

    // Print volumes of all boxes
    cout << "\nVolumes of the boxes:" << endl;
    cout << "Box 1 volume: " << box1.volume() << endl;
    cout << "Box 2 volume: " << box2.volume() << endl;
    cout << "Box 3 volume: " << box3.volume() << endl;

    cout << "\nProgram ending - destructors will be called automatically" << endl;
    return 0;
} 