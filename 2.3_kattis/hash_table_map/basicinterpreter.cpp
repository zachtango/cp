#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <sstream>
#include <vector>
#include <iterator>

typedef std::map<int, std::string> m;
typedef std::unordered_map<char, int> um;
typedef std::vector<std::string> vs;
typedef std::stringstream ss;

#define ADD '+'
#define SUB '-'
#define MULT '*'
#define DIV '/'
#define ASCII_NUMBER_OFFSET 48
#define EQUAL "="
#define GREATER ">"
#define LESSER "<"
#define GREATER_EQUAL ">="
#define LESSER_EQUAL "<="
#define UNEQUAL "<>"
#define LET "LET"
#define PRINT "PRINT"
#define PRINTLN "PRINTLN"
#define IF "IF"

m instructions;
um variables;
int start_label, end_label, current_label;

int get_operand_val(const std::string &operand) {
    if(operand.size() != 1)
        return std::stoi(operand);

    if(operand[0] >= '0' && operand[0] <= '9')
        return operand[0] - ASCII_NUMBER_OFFSET;

    return variables[operand[0]];
}

std::string get_print_val(const std::string &s) {
    if(s[0] == '\"' && s[s.size() - 1] == '\"')
        return s.substr(1, s.size() - 2);

    return std::to_string(variables[s[0]]);
}

vs split_statement(const std::string &s, char delim = ' ') {
    vs tokens;
    ss stream(s);
    std::string token;

    while(std::getline(stream, token, delim))
        tokens.push_back(token);

    return tokens;
}

void let(const std::string &s) {
    char v = s[0];

    std::string a = s.substr(4);

    vs tokens = split_statement(a);
    
    if(tokens.size() == 1) {
        variables[v] = get_operand_val(tokens[0]);
        return;
    }

    char op = tokens[1][0];
    int operand1 = get_operand_val(tokens[0]),
        operand2 = get_operand_val(tokens[2]);
    
    int res;
    switch(op) {
        case ADD:
            res = operand1 + operand2;
            break;
        case SUB:
            res = operand1 - operand2;
            break;
        case MULT:
            res = operand1 * operand2;
            break;
        case DIV:
            res = operand1 / operand2;
            break;
        default:
            throw "Unknown operation";
    }

    variables[v] = res;
}

void if_then(const std::string &s) {
    vs tokens = split_statement(s);
    
    int operand1 = get_operand_val(tokens[0]),
        operand2 = get_operand_val(tokens[2]);
    
    std::string op = tokens[1];

    bool res;
    if(op == EQUAL) res = operand1 == operand2;    
    else if(op == GREATER) res = operand1 > operand2;
    else if(op == LESSER) res = operand1 < operand2;
    else if(op == GREATER_EQUAL) res = operand1 >= operand2;
    else if(op == LESSER_EQUAL) res = operand1 <= operand2;
    else if(op == UNEQUAL) res = operand1 != operand2;

    if(res) {
        int label = std::stoi(tokens[5]);
        if(label == start_label)
            current_label = -1;
        else
            current_label = std::prev(instructions.find(label))->first;
    }
}

void print(const std::string &s, bool nl = false) {
    std::cout << get_print_val(s);

    if(nl) std::cout << '\n';
}

bool interpret() {
    std::string line = instructions[current_label],
        instr = line.substr(0, line.find(' ')),
        s = line.substr(line.find(' ') + 1);
        
    // std::cout << "instr: " << instr << std::endl;
    // std::cout << "s: " << s << std::endl;

    if(instr == LET) let(s);
    else if(instr == IF) if_then(s);
    else if(instr == PRINT) print(s);
    else if(instr == PRINTLN) print(s, true);
    else throw "Unknown instr";

    if(current_label == end_label)
        return false;

    if(current_label == -1)
        current_label = start_label;
    else
        current_label = 
            std::next(instructions.find(current_label))->first;
    
    return true;
}

int main() {
    /*
        write interpreter for restricted dialect
        of BASIC

        each input has one statement
            begins with non-negative integer (label)
            
            following the label is a single space
            and one of the commands:

                LET X = <ARITHMETIC>
                - assign X to res of arithmetic statement
                - all 32 bit signed int
                - all vars in global scope and initialized to zero
                    before program exec
                - statement is one of
                    X, X + Y, X - Y, X * Y or X / Y
                    X and Y are either a variable or integer
                IF <CONDITION> THEN GOTO L
                - if condition is true, go to statement labeled L
                    (L is valid label)
                - condition is one of
                    X = Y, X > Y, X < Y, X <> Y, X <= Y, X >= Y
                    <> is inequality
                PRINT <PRINT>
                - produce output without an appended newline
                - PRINT is
                    variable name or literal string
                    delimited by double quotes
                PRINTLN <PRINT>
                - produce output with appended newline

        algo:
        store labels and their instr in 
        set<int, string> so the program gets ordered
        least to greatest

        store variables and their values in hash table
        unordered_set<string, int> variables

        process each instruction
            LET:
                get variable
                process arithmetic statement (res)
                set var = to arithmetic statement
            IF:
                get condition
                process conditioin
                if true set next instr to be instr[L]
                else set next instr to be next label
            print:
                get print_statement
                if print_statement is a variable, print variable
                if string print string
    */

    std::string line;
    int label;

    while(std::cin >> label) {
        getchar();
        std::getline(std::cin, line);

        instructions[label] = line;
    }

    current_label = instructions.begin()->first;
    start_label = current_label;
    end_label = instructions.rbegin()->first;

    while(interpret()) {}

    return 0;
}