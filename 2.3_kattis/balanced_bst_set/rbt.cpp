#include <iostream>


int main() {
    /*
        insert new node as red
        
        algo used for maintaining rb property:
        1. while parent of newNode p is red
        2. if p is left child of grandparent gP of z
            i
                a. if color of right child of gP of z is 
                red, set the color both the children of gP 
                as black and color gP as red
                b. assign gP to newNode
            ii
                a. if newNode is the right child of p,
                assign p to newNode
                b. left rotate newNode
            iii
                a. set color of p as black 
                and color of gP as red
                b. right rotate gP
        3. else
            a. 
        4. set root of tree as black

    */    

    return 0;
}