// Homework 1 Aersp 424
//Group Members: Andrea Gandhi, Alex Gleba, Claudia Hunt, Jonathon Hope
// Questions 2,3,4

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// PROBLEM 2 //////////////////////////////////
// single container (struct)
struct Flight{

//innitialize inputs for struct named, "Flight"
    string from;
    string to;
    int distance;

    Flight(const string& from, const string& to, int distance)
    : from(from), to(to), distance(distance) {}
};

// PROBLEM 3 & 4 /////////////////////////////////
class Plane{

        // initialize inputs for constructor 
        string from ;
        string to;

        private:
        // private class members
            double pos;
            double vel;
            double dist;
            bool at_SCE;
            string origin;
            string destination;
             //fix this container addition: how do I reference the container in a class

        public:
        //public class memmbers

            //constructor 
            Plane(const string& from, const string& to):from(from), to(to), pos(0), vel(0),
            dist(0), origin(from), destination(to), at_SCE(true){   /*assign string variables "from" and 
            "to" to "origin" and "destination" variables*/

            std::cout<<"Plane created at: "<< this << std::endl;  //print out the memory address of plane

            };

            //reference the memory address
            Plane() {
           std::cout<<"Plane created at: "<< this << std::endl;
           }
            
            //deconstructor 
            ~Plane(){
            std::cout<<"Plane Destroyed"<< std::endl;
            }
            std:: vector<Flight> flight_distance; 
            //getter functions 
            // make constant so that they always return the value of corresponding variable
            double get_pos() const {return pos;}
            std:: string get_origin() const {return origin;}
            std:: string get_destination() const {return destination;}
            bool get_at_SCE() const {return at_SCE;}
            double vel_func_get() const {return vel;}
            // set velocity
            void set_vel(double velocity) {vel = velocity;}
      

            // function that returns nothing
            void operate(double dt) { 
                // distance comm
                if (pos <= dist){
                    pos += vel*dt;
                    at_SCE = 0;
                    return;

                }
                else{
                    if (destination == "SCE"){   // yes
                            at_SCE = 1;                    
                        } else {

                        }
                        std::swap(origin, destination);
                        std::swap(from, to);
                        pos = 0.0;
                        return;
                    }  
                }
            
            } ;



int main(){

    //create object to reference memory address
    Plane plane;    

    // create a vector flight, then push the data of each flight into that vector
    std::vector<Flight> flight_distance; 
    flight_distance.emplace_back("SCE","PHL",160);
    flight_distance.emplace_back("SCE","ORD",640);
    flight_distance.emplace_back("SCE","EWR",220);

    // referencing flight_distance in the class Plane
    plane.flight_distance = flight_distance;

    return 0;
}

