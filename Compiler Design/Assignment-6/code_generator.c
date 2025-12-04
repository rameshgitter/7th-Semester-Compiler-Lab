/*
 * Three Address Code to 8086 Assembly Code Generator
 * Based on Aho-Sethi-Ullman code generation strategy
 * 
 * Usage: 
 *   ./code_generator input.txt output.asm
 *   or
 *   ./code_generator (uses default example)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_REGISTERS 4
#define MAX_VARS 100
#define MAX_CODE_LINES 500
#define MAX_LINE_LENGTH 256

// Register names
char *registers[] = {"AX", "BX", "CX", "DX"};

// Register Descriptor - tracks what is in each register
typedef struct {
    char variable[50];  // Variable name in register (empty string if free)
} RegisterDescriptor;

RegisterDescriptor regDesc[MAX_REGISTERS];

// Address Descriptor - tracks where each variable is located
typedef struct {
    char varName[50];
    int inMemory;       // 1 if in memory
    int regIndex;       // Register index (-1 if not in register)
} AddressDescriptor;

AddressDescriptor addrDesc[MAX_VARS];
int addrDescCount = 0;

// Generated code storage
char generatedCode[MAX_CODE_LINES][MAX_LINE_LENGTH];
int codeLineCount = 0;

// Function prototypes
void initDescriptors();
void emitCode(const char *code);
int getReg(const char *x, const char *y);
int findRegWithVar(const char *var);
int getEmptyReg();
void setRegContents(int regIndex, const char *var);
void clearVarFromRegs(const char *var);
int getOrCreateAddrDesc(const char *var);
void generateAssignment(const char *result, const char *op1, const char *op, const char *op2);
void generateSimpleAssignment(const char *result, const char *op1);
void generateConditional(const char *op1, const char *relop, const char *op2, const char *label);
void generateLabel(const char *label);
void generateGoto(const char *label);
void generateIndexedLoad(const char *result, const char *array, const char *index);
void generateIndexedStore(const char *array, const char *index, const char *value);
void generatePointerLoad(const char *result, const char *pointer);
void generatePointerStore(const char *pointer, const char *value);
void parseStatement(const char *stmt);
void trim(char *str);
void printGeneratedCode();
void writeGeneratedCode(const char *filename);
int readStatementsFromFile(const char *filename, char statements[][MAX_LINE_LENGTH]);
void createSampleInputFile();

int main(int argc, char *argv[]) {
    char statements[100][MAX_LINE_LENGTH];
    int stmtCount = 0;
    char *inputFile = NULL;
    char *outputFile = NULL;
    
    printf("======================================================================\n");
    printf("Three Address Code to 8086 Assembly Code Generator\n");
    printf("Based on Aho-Sethi-Ullman Strategy\n");
    printf("======================================================================\n\n");
    
    // Parse command line arguments
    if (argc == 1) {
        // No arguments - create and use sample file
        printf("No input file specified. Creating sample input file 'input.txt'...\n\n");
        createSampleInputFile();
        inputFile = "input.txt";
        outputFile = "output.asm";
    } else if (argc == 2) {
        inputFile = argv[1];
        outputFile = "output.asm";
    } else if (argc >= 3) {
        inputFile = argv[1];
        outputFile = argv[2];
    }
    
    printf("Input file:  %s\n", inputFile);
    printf("Output file: %s\n\n", outputFile);
    
    // Read statements from file
    stmtCount = readStatementsFromFile(inputFile, statements);
    
    if (stmtCount == 0) {
        fprintf(stderr, "Error: No valid statements found in input file.\n");
        return 1;
    }
    
    printf("Read %d statements from input file:\n", stmtCount);
    printf("----------------------------------------------------------------------\n");
    for (int i = 0; i < stmtCount; i++) {
        printf("%2d: %s\n", i + 1, statements[i]);
    }
    printf("----------------------------------------------------------------------\n\n");
    
    printf("Generating 8086 assembly code...\n\n");
    
    // Initialize
    initDescriptors();
    
    // Generate prologue
    emitCode("; Generated 8086 Assembly Code");
    emitCode("; Input: Three Address Code");
    emitCode("; Strategy: Aho-Sethi-Ullman Code Generation");
    emitCode("");
    emitCode(".MODEL SMALL");
    emitCode(".STACK 100H");
    emitCode("");
    emitCode(".DATA");
    emitCode("    ; Declare all variables as words");
    emitCode("    ; Add variable declarations here, e.g.:");
    emitCode("    ; a DW ?");
    emitCode("    ; b DW ?");
    emitCode("    ; c DW ?");
    emitCode("");
    emitCode(".CODE");
    emitCode("MAIN PROC");
    emitCode("    MOV AX, @DATA");
    emitCode("    MOV DS, AX");
    emitCode("");
    emitCode("    ; ===== Generated Code Begins =====");
    
    // Process each statement
    for (int i = 0; i < stmtCount; i++) {
        if (strlen(statements[i]) > 0 && statements[i][0] != ';') {
            char comment[MAX_LINE_LENGTH];
            /* Ensure we don't overflow comment: compute available space for statements[i] */
            int prefix_len = strlen("    ; ");
            int max_stmt = (int)sizeof(comment) - prefix_len - 1; /* leave room for NUL */
            if (max_stmt < 0) max_stmt = 0;
            snprintf(comment, sizeof(comment), "    ; %.*s", max_stmt, statements[i]);
            emitCode(comment);
            parseStatement(statements[i]);
        }
    }
    
    // Generate epilogue
    emitCode("    ; ===== Generated Code Ends =====");
    emitCode("");
    emitCode("    MOV AH, 4CH");
    emitCode("    INT 21H");
    emitCode("MAIN ENDP");
    emitCode("END MAIN");
    
    // Write to output file
    writeGeneratedCode(outputFile);
    
    // Also print to console
    printf("======================================================================\n");
    printf("GENERATED 8086 ASSEMBLY CODE\n");
    printf("======================================================================\n\n");
    printGeneratedCode();
    
    printf("\n======================================================================\n");
    printf("Code generation completed successfully!\n");
    printf("Output written to: %s\n", outputFile);
    printf("======================================================================\n");
    
    return 0;
}

void createSampleInputFile() {
    FILE *fp = fopen("input.txt", "w");
    if (fp == NULL) {
        fprintf(stderr, "Error: Cannot create input.txt\n");
        return;
    }
    
    fprintf(fp, "; Sample Three Address Code\n");
    fprintf(fp, "; Example 1: Basic arithmetic operations\n");
    fprintf(fp, "t = a - b\n");
    fprintf(fp, "u = a - c\n");
    fprintf(fp, "v = t + u\n");
    fprintf(fp, "d = v + u\n");
    fprintf(fp, "\n");
    fprintf(fp, "; Example 2: If statement\n");
    fprintf(fp, "x = y + z\n");
    fprintf(fp, "if x < 0 goto L1\n");
    fprintf(fp, "a = x + 1\n");
    fprintf(fp, "goto L2\n");
    fprintf(fp, "L1:\n");
    fprintf(fp, "a = x - 1\n");
    fprintf(fp, "L2:\n");
    fprintf(fp, "result = a * 2\n");
    
    fclose(fp);
    printf("Sample input file 'input.txt' created with example code.\n");
}

int readStatementsFromFile(const char *filename, char statements[][MAX_LINE_LENGTH]) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Cannot open file '%s'\n", filename);
        return 0;
    }
    
    int count = 0;
    char line[MAX_LINE_LENGTH];
    
    while (fgets(line, sizeof(line), fp) != NULL && count < 100) {
        trim(line);
        
        // Skip empty lines and comments
        if (strlen(line) > 0 && line[0] != ';') {
            strcpy(statements[count++], line);
        }
    }
    
    fclose(fp);
    return count;
}

void writeGeneratedCode(const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        fprintf(stderr, "Error: Cannot create output file '%s'\n", filename);
        return;
    }
    
    for (int i = 0; i < codeLineCount; i++) {
        fprintf(fp, "%s\n", generatedCode[i]);
    }
    
    fclose(fp);
}

void initDescriptors() {
    // Initialize register descriptors
    for (int i = 0; i < MAX_REGISTERS; i++) {
        regDesc[i].variable[0] = '\0';
    }
    
    // Initialize address descriptors
    addrDescCount = 0;
}

void emitCode(const char *code) {
    if (codeLineCount < MAX_CODE_LINES) {
        strncpy(generatedCode[codeLineCount++], code, MAX_LINE_LENGTH - 1);
        generatedCode[codeLineCount - 1][MAX_LINE_LENGTH - 1] = '\0';
    }
}

int getReg(const char *x, const char *y) {
    (void)x; // x is unused in current strategy; silence compiler warning
    // Find register with y that can be reused
    int yReg = findRegWithVar(y);
    if (yReg != -1) {
        return yReg;
    }
    
    // Try to get empty register
    int emptyReg = getEmptyReg();
    if (emptyReg != -1) {
        return emptyReg;
    }
    
    // Default to AX (simple strategy)
    return 0;
}

int findRegWithVar(const char *var) {
    for (int i = 0; i < MAX_REGISTERS; i++) {
        if (strcmp(regDesc[i].variable, var) == 0) {
            return i;
        }
    }
    return -1;
}

int getEmptyReg() {
    for (int i = 0; i < MAX_REGISTERS; i++) {
        if (strlen(regDesc[i].variable) == 0) {
            return i;
        }
    }
    return -1;
}

void setRegContents(int regIndex, const char *var) {
    if (regIndex >= 0 && regIndex < MAX_REGISTERS) {
        strncpy(regDesc[regIndex].variable, var, 49);
        regDesc[regIndex].variable[49] = '\0';
    }
}

void clearVarFromRegs(const char *var) {
    for (int i = 0; i < MAX_REGISTERS; i++) {
        if (strcmp(regDesc[i].variable, var) == 0) {
            regDesc[i].variable[0] = '\0';
        }
    }
}

int getOrCreateAddrDesc(const char *var) {
    for (int i = 0; i < addrDescCount; i++) {
        if (strcmp(addrDesc[i].varName, var) == 0) {
            return i;
        }
    }
    
    if (addrDescCount < MAX_VARS) {
        strcpy(addrDesc[addrDescCount].varName, var);
        addrDesc[addrDescCount].inMemory = 1;
        addrDesc[addrDescCount].regIndex = -1;
        return addrDescCount++;
    }
    
    return -1;
}

void generateAssignment(const char *result, const char *op1, const char *op, const char *op2) {
    char code[MAX_LINE_LENGTH];
    int reg = getReg(result, op1);
    
    // Load first operand
    if (strcmp(regDesc[reg].variable, op1) != 0) {
        sprintf(code, "    MOV %s, %s", registers[reg], op1);
        emitCode(code);
    }
    
    // Perform operation
    if (strcmp(op, "+") == 0) {
        sprintf(code, "    ADD %s, %s", registers[reg], op2);
        emitCode(code);
    } else if (strcmp(op, "-") == 0) {
        sprintf(code, "    SUB %s, %s", registers[reg], op2);
        emitCode(code);
    } else if (strcmp(op, "*") == 0) {
        // For multiplication: result in AX (assuming AX:DX for result)
        if (reg != 0) {
            sprintf(code, "    MOV AX, %s", registers[reg]);
            emitCode(code);
        }
        sprintf(code, "    IMUL %s", op2);
        emitCode(code);
        reg = 0; // Result in AX
    } else if (strcmp(op, "/") == 0) {
        // For division: dividend in AX, result in AX
        if (reg != 0) {
            sprintf(code, "    MOV AX, %s", registers[reg]);
            emitCode(code);
        }
        emitCode("    CWD             ; Sign extend AX to DX:AX");
        sprintf(code, "    IDIV %s", op2);
        emitCode(code);
        reg = 0; // Result in AX
    }
    
    // Update register descriptor
    clearVarFromRegs(result);
    setRegContents(reg, result);
    
    // Store to memory
    sprintf(code, "    MOV %s, %s", result, registers[reg]);
    emitCode(code);
}

void generateSimpleAssignment(const char *result, const char *op1) {
    char code[MAX_LINE_LENGTH];
    int reg = getReg(result, op1);
    
    if (strcmp(regDesc[reg].variable, op1) != 0) {
        sprintf(code, "    MOV %s, %s", registers[reg], op1);
        emitCode(code);
    }
    
    sprintf(code, "    MOV %s, %s", result, registers[reg]);
    emitCode(code);
    
    setRegContents(reg, result);
}

void generateConditional(const char *op1, const char *relop, const char *op2, const char *label) {
    char code[MAX_LINE_LENGTH];
    
    sprintf(code, "    MOV AX, %s", op1);
    emitCode(code);
    sprintf(code, "    CMP AX, %s", op2);
    emitCode(code);
    
    const char *jumpInstr = "JE";
    if (strcmp(relop, "<") == 0) jumpInstr = "JL";
    else if (strcmp(relop, "<=") == 0) jumpInstr = "JLE";
    else if (strcmp(relop, ">") == 0) jumpInstr = "JG";
    else if (strcmp(relop, ">=") == 0) jumpInstr = "JGE";
    else if (strcmp(relop, "==") == 0) jumpInstr = "JE";
    else if (strcmp(relop, "!=") == 0) jumpInstr = "JNE";
    
    sprintf(code, "    %s %s", jumpInstr, label);
    emitCode(code);
}

void generateLabel(const char *label) {
    char code[MAX_LINE_LENGTH];
    sprintf(code, "%s:", label);
    emitCode(code);
}

void generateGoto(const char *label) {
    char code[MAX_LINE_LENGTH];
    sprintf(code, "    JMP %s", label);
    emitCode(code);
}

void generateIndexedLoad(const char *result, const char *array, const char *index) {
    char code[MAX_LINE_LENGTH];
    
    sprintf(code, "    MOV BX, %s", index);
    emitCode(code);
    emitCode("    SHL BX, 1       ; Multiply by 2 for word addressing");
    sprintf(code, "    MOV AX, %s[BX]", array);
    emitCode(code);
    sprintf(code, "    MOV %s, AX", result);
    emitCode(code);
    
    setRegContents(0, result);
}

void generateIndexedStore(const char *array, const char *index, const char *value) {
    char code[MAX_LINE_LENGTH];
    
    sprintf(code, "    MOV BX, %s", index);
    emitCode(code);
    emitCode("    SHL BX, 1       ; Multiply by 2 for word addressing");
    sprintf(code, "    MOV AX, %s", value);
    emitCode(code);
    sprintf(code, "    MOV %s[BX], AX", array);
    emitCode(code);
}

void generatePointerLoad(const char *result, const char *pointer) {
    char code[MAX_LINE_LENGTH];
    
    sprintf(code, "    MOV BX, %s", pointer);
    emitCode(code);
    emitCode("    MOV AX, [BX]");
    sprintf(code, "    MOV %s, AX", result);
    emitCode(code);
    
    setRegContents(0, result);
}

void generatePointerStore(const char *pointer, const char *value) {
    char code[MAX_LINE_LENGTH];
    
    sprintf(code, "    MOV BX, %s", pointer);
    emitCode(code);
    sprintf(code, "    MOV AX, %s", value);
    emitCode(code);
    emitCode("    MOV [BX], AX");
}

void parseStatement(const char *stmt) {
    char temp[MAX_LINE_LENGTH];
    strncpy(temp, stmt, MAX_LINE_LENGTH - 1);
    temp[MAX_LINE_LENGTH - 1] = '\0';
    trim(temp);
    
    if (strlen(temp) == 0) return;
    
    // Handle label
    if (temp[strlen(temp) - 1] == ':') {
        temp[strlen(temp) - 1] = '\0';
        generateLabel(temp);
        return;
    }
    
    // Handle goto
    if (strncmp(temp, "goto", 4) == 0) {
        char *label = temp + 4;
        while (*label && isspace(*label)) label++;
        generateGoto(label);
        return;
    }
    
    // Handle if statement
    if (strncmp(temp, "if", 2) == 0) {
        char op1[50], relop[10], op2[50], label[50];
        char *ptr = temp + 2;
        
        // Skip whitespace
        while (*ptr && isspace(*ptr)) ptr++;
        
        // Parse: if op1 relop op2 goto label
        if (sscanf(ptr, "%s %s %s goto %s", op1, relop, op2, label) == 4) {
            generateConditional(op1, relop, op2, label);
        }
        return;
    }
    
    // Handle assignment
    char *eqSign = strchr(temp, '=');
    if (eqSign != NULL) {
        char left[100], right[200];
        
        *eqSign = '\0';
        strcpy(left, temp);
        strcpy(right, eqSign + 1);
        trim(left);
        trim(right);
        
        // Check for array store: a[i] = b
        char *lbracket = strchr(left, '[');
        if (lbracket != NULL) {
            char array[50], index[50];
            *lbracket = '\0';
            strcpy(array, left);
            trim(array);
            
            char *rbracket = strchr(lbracket + 1, ']');
            if (rbracket != NULL) {
                *rbracket = '\0';
                strcpy(index, lbracket + 1);
                trim(index);
                generateIndexedStore(array, index, right);
            }
            return;
        }
        
        // Check for pointer store: *p = a
        if (left[0] == '*') {
            char pointer[50];
            strcpy(pointer, left + 1);
            trim(pointer);
            generatePointerStore(pointer, right);
            return;
        }
        
        // Check for array load: a = b[i]
        char *rbracket = strchr(right, '[');
        if (rbracket != NULL) {
            char array[50], index[50];
            strncpy(array, right, rbracket - right);
            array[rbracket - right] = '\0';
            trim(array);
            
            char *rbracket2 = strchr(rbracket, ']');
            if (rbracket2 != NULL) {
                strncpy(index, rbracket + 1, rbracket2 - rbracket - 1);
                index[rbracket2 - rbracket - 1] = '\0';
                trim(index);
                generateIndexedLoad(left, array, index);
            }
            return;
        }
        
        // Check for pointer load: a = *p
        if (right[0] == '*') {
            char pointer[50];
            strcpy(pointer, right + 1);
            trim(pointer);
            generatePointerLoad(left, pointer);
            return;
        }
        
        // Check for binary operations
        char *opPtr = NULL;
        char op = '\0';
        
        for (int i = 0; right[i]; i++) {
            if (right[i] == '+' || right[i] == '-' || right[i] == '*' || right[i] == '/') {
                if (i > 0 && !isspace(right[i-1]) && !isalnum(right[i-1])) continue;
                opPtr = &right[i];
                op = right[i];
                break;
            }
        }
        
        if (opPtr != NULL) {
            char op1[50], op2[50], opStr[2];
            *opPtr = '\0';
            strcpy(op1, right);
            strcpy(op2, opPtr + 1);
            trim(op1);
            trim(op2);
            opStr[0] = op;
            opStr[1] = '\0';
            
            generateAssignment(left, op1, opStr, op2);
        } else {
            // Simple assignment
            generateSimpleAssignment(left, right);
        }
    }
}

void trim(char *str) {
    char *start = str;
    while (*start && isspace(*start)) start++;
    
    if (start != str) {
        memmove(str, start, strlen(start) + 1);
    }
    
    char *end = str + strlen(str) - 1;
    while (end > str && isspace(*end)) {
        *end = '\0';
        end--;
    }
}

void printGeneratedCode() {
    for (int i = 0; i < codeLineCount; i++) {
        printf("%s\n", generatedCode[i]);
    }
}
