#include <iostream>
#include <string>
#include <unordered_map>

typedef std::unordered_map<std::string, int> umsi;
typedef std::unordered_map<int, std::string> umis;

#define DEF "def"
#define CALC "calc"
#define CLEAR "clear"
#define UNKNOWN "unknown"

umsi var_to_val;
umis val_to_var;

void def() {
    std::string var;
    int val;

    std::cin >> var >> val;

    if(var_to_val.count(var) != 0)
        val_to_var.erase(var_to_val[var]);

    var_to_val[var] = val;
    val_to_var[val] = var;
}

void calc() {
    bool is_unknown = false;
    int res = 0;
    
    std::string operand, op;
    std::cin >> operand;
    std::cout << operand << ' ';

    if(var_to_val.count(operand) == 0) is_unknown = true;
    else res = var_to_val[operand];

    while(std::cin >> op, op != "=") {
        std::cin >> operand;
        std::cout << op << ' ' << operand << ' ';

        if(var_to_val.count(operand) == 0) {
            is_unknown = true;
            continue;
        }

        if(op == "+") res += var_to_val[operand];
        else if(op == "-") res -= var_to_val[operand];
        else throw "Unknown operator";
    }

    std::cout << "= ";

    if(is_unknown || val_to_var.count(res) == 0)
        std::cout << UNKNOWN << '\n';
    else
        std::cout << val_to_var[res] << '\n';
}

void clear() {
    var_to_val.clear();
    val_to_var.clear();
}

void process(const std::string &op) {
    
    if(op == DEF) def();
    else if(op == CALC) calc();
    else if(op == CLEAR) clear();
    else throw "Unknown operation";

}

int main() {
    /*
        sequence of up to 2000 commands
        1 per line ending

        each command is
            definition, calculation, or clear
            def x y
                no 2 vars ever have same numeric val
                at same time
                if var defined prev, defining it again 
                erases old definition
            calc a + b - c + d ... =
                variables and + - ending =
            clear
                program forgets all its definitions

        use a hash table to store definitions
            unordered_map<string, int> map variable to its value
        calc
            process variables (output var and operators)
            if at least 1 variable is unknown (not in 
            hash table, output unknown) if there
            isn't a word for the result
    */

    std::string op;

    while(std::cin >> op) {
        process(op);
    }


    return 0;
}