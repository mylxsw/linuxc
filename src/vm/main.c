#include <stdio.h>
#include <stdbool.h>

#define FETCH(ip)   (test_instructions[(ip)])
#define STACK_SIZE 256
static int stack[STACK_SIZE];

typedef enum {
    HLT,    // Halts Program
    PSH,    // Pushes <val> to stack
    ADD,    // Adds top two vals on stack
    POP,    // pops value from stack
    MUL,    // multiplies top two vals on stack
    DIV,    // divides top two vals on stack
    SUB,    // subtracts top two vals on stack
    SLT,    // pushes (reg_a < reg_b) to stack
    MOV,    // movs the value in reg_a to reg_b
    SET,    // set the reg to value
    LOG,    // prints out a
    IF,     // if the register == val branch to the ip
    IFN,    // if the register != val branch to the ip
    GLD,    // loads a register to the stack
    GPT,    // pushes top of stack to the given register
    NOP     // nothing
} InstructionSet;

typedef enum {
    A, B, C, D, E, F, I, J, // General Purpose
    EX,                     // Excess
    EXA,                    // More Excess
    IP,                     // Instruction Pointer
    SP,                     // Stack Pointer
    REGISTER_SIZE
} Registers;

static bool running = true;
static int registers[REGISTER_SIZE];


int test_a[] = {
    PSH, 5,
    PSH, 2,
    ADD,
    PSH, 10,
    PSH, 12,
    ADD,
    ADD,
    POP,
    HLT
};

int test_b[] = {
    PSH, 5,
    PSH, 2,
    MUL,
    PSH, 10, 
    PSH, 20,
    MUL,
    ADD,
    HLT
};

int test_instructions[] = {
    SET, A, 21,
    GLD, A,
    PSH, 1,
    SUB,
    GPT, A,
    IFN, A, 0, 2,
    LOG, A,
    LOG, B,
    HLT 
}; 

#define SP          (registers[SP])
#define IP          (registers[IP])

void print_stack() {
    for (int i = 0; i < SP; i ++) {
        printf("0x%04d ", stack[i]);
        if ((i + 1) % 4 == 0) {
            printf("\n");
        }
    }
    
    if (SP != 0) {
        printf("\n");
    }
}

void print_registers() {
    printf("Register Dump:\n");
    for (int i = 0; i < REGISTER_SIZE; i ++) {
        printf("%04d ", registers[i]);
        if ((i + 1) % 4 == 0) {
            printf("\n");
        }
    }
}

int find_empty_register() {
    for (int i = 0; i < REGISTER_SIZE; i ++) {
        if (i != registers[EX] && i != registers[EXA]) {
            return i;
        }
    }

    return EX;
}


void eval(int instr) {
    switch(instr) {
        case HLT:
            running = false;
            printf("Finished Execution\n");
            break;
        case PSH: 
            SP = SP + 1;
            IP = IP + 1;
            stack[SP] = FETCH(IP);
            break;
        case POP:
            SP = SP - 1;
            break;
        case ADD: {
            registers[A] = stack[SP];
            SP = SP -1;

            registers[B] = stack[SP];
            registers[C] = registers[A] + registers[B];

            stack[SP] = registers[C];
            printf("%d + %d = %d\n", registers[A], registers[B], registers[C]);
            break;
        }
        case MUL: {
            registers[A] = stack[SP];
            SP = SP - 1;

            registers[B] = stack[SP];
            registers[C] = registers[B] * registers[A];
            
            stack[SP] = registers[C];
            printf("%d * %d = %d\n", registers[B], registers[A], registers[C]);
            break;
        }
        case DIV: {
            registers[A] = stack[SP];
            SP = SP - 1;

            registers[B] = stack[SP];
            registers[C] = registers[B] / registers[A];

            stack[SP] = registers[C];
            printf("%d / %d = %d\n", registers[B], registers[A], registers[C]);
            break;
        }
        case SUB: {
            registers[A] = stack[SP];
            SP = SP - 1;

            registers[B] = stack[SP];

            registers[C] = registers[B] - registers[A];
            stack[SP] = registers[C];
            printf("%d - %d = %d\n", registers[B], registers[A], registers[C]);
            break;
        }
        case SLT:
            SP = SP - 1;
            stack[SP] = stack[SP + 1] < stack[SP];
            break;
        case MOV:
            registers[FETCH(IP + 2)] = registers[FETCH(IP + 1)];
            IP = IP + 2;
            break;
        case SET:
            registers[FETCH(IP + 1)] = FETCH(IP + 2);
            IP = IP + 2;
            break;
        case LOG:
            printf("%d\n", registers[FETCH(IP + 1)]);
            IP = IP + 1;
            break;
        case IF:
            if (registers[FETCH(IP + 1)] == FETCH(IP + 2)) {
                registers[IP + 1] = FETCH(IP + 3);
            }

            IP = IP + 3;
            break;
        case IFN:
            if (registers[FETCH(IP + 1)] != FETCH(IP + 2)) {
                registers[EX] = FETCH(IP + 3);
                registers[IP] = registers[EX];
            } else {
                IP = IP + 3;
            }
            break;
        case GLD:
            SP = SP + 1;
            IP = IP + 1;
            stack[SP] = registers[FETCH(IP)];
            break;
        case GPT:
            registers[FETCH(IP + 1)] = stack[SP];
            IP = IP + 1;
            break;
        case NOP:
            printf("Do Nothing\n");
            break;
        default:
            printf("Unknown Instruction %d\n", instr);
            break;
    }
}


int main(int argc, char * argv[]) {
    SP = -1;

    while (running) {
        eval(FETCH(IP));
        IP = IP + 1;
    }


    return 0;
}

