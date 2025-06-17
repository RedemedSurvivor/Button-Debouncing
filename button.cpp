#include <iostream>                    // Include the input/output stream library for console I/O
#include <random>                      // Include the random number generation library

using namespace std;                   // Use the standard namespace

// Create a random number generator globally (so it's not reinitialized every function call)
random_device rd;                      // Seed from hardware entropy source
mt19937 gen(rd());                     // Mersenne Twister RNG engine, seeded with rd()
uniform_int_distribution<int> dist(0, 1); // Distribution to generate either 0 or 1

// Simulate reading the raw button state at time t (in ms)
bool readRawButton(int t) {
    if ((t >= 20 && t <= 70) || (t >= 150 && t <= 170)) {          // If t is between 20ms and 70ms (bouncing period)
        return dist(gen);              // Return random true/false to simulate bouncing
    } else if (t > 70 && t<150) {               // If t is after 70ms (button is stably pressed)
        return true;                   // Return true (pressed)
    } else {                           // If t is before 20ms (button not pressed)
        return false;                  // stable release
    }
}

bool debounce_button(bool raw_input){

    static bool last_state = false;           // Initialize last state to false (not pressed)
    static int stable_count = 0;     
    static bool debounce_output= false;  // Static variable to count stable states

    if (raw_input == debounce_output) {
        stable_count = 0;  // no change detected, no need to debounce
    } else {
        stable_count++;    // potential state change, count stability
        if (stable_count >= 3) {
            debounce_output = raw_input; // apply state change
            stable_count = 0;            // reset counter after update
        }
    }

    return debounce_output;           // Return the debounced output state

    }




int main() {

bool button_state;

for (int t = 0; t <= 200; t += 10) {
    bool raw_state = readRawButton(t);
    bool debounced_state = debounce_button(raw_state);
    
    cout << "t=" << t << "ms; raw=" << boolalpha << raw_state 
         << "; debounced=" << debounced_state << endl;
}


   // cout << "Final button state: " << boolalpha << button_state << endl; // Print final button state

    return 0;                          // Indicate successful program termination
}
