#include <stdio.h>
#include <stdlib.h>

/* 
 * codebuffer is a valid pointer to 8080 assembly code
 * pc is the current offset into the code
 *
 * returns the number of bytes of the op
 */

int Disassemble8080op(unsigned char *codebuffer, int pc)
{
  unsigned char *code = &codebuffer[pc];
  int opbytes = 1;
  printf ("%04x ", pc);
  switch (*code)
  {
    case 0x00: printf("nop"); break;
    case 0x01: printf("lxi    b,#$%02x%02x", code[2], code[1]); opbytes=3; break; /*load register pair immediate - loads 16bit data in the register pair designated in the operand (b)*/
    case 0x02: printf("stax    b"); break; /*the content of the accumulator is stored in the memory location specified by the bc register pair*/
    case 0x03: printf("inx    b"); break; /*the content of the bc register pair is incremented by 1*/
    case 0x04: printf("inr    b"); break; /*the content of the b register is incremented by 1*/
    case 0x05: printf("dcr    b"); break; /*the content of the b register is decremented by 1*/
    case 0x06: printf("mvi    b,#$%02x",code[1]);opbytes=2; break; /*move immediate adds the value of byte 2 into the b register*/
    case 0x07: printf("rlc"); break; /*rotate instruction: rotates the eight bits in the accumulator and the 1 bit in the carry flag left one bit position: bit 7 goes into carry and also goes into bit 0*/
    case 0x08: printf("nop"); break;
    case 0x09: printf("dad    b"); break; /*double byte add instructions: adds the content of the bc register pair into hl register pair*/
    case 0x0a: printf("ldax    b"); break; /*8 bit transfer instruction - load accumulator indirect. the contents of the designated register pair (bc) point to a memory location. this instruction copies the contents of that memory loaction into the accumulator*/
    case 0x0b: printf("dcx    b"); break; /*the content of the bc register pair is decremented by 1*/
    case 0x0c: printf("inr    c"); break; /*the content of the c register is incremented by 1*/
    case 0x0d: printf("dcr    c"); break; /*the content of the c register is decremented by 1*/
    case 0x0e: printf("mvi    c,#$%02x",code[1]);opbytes=2; break; /*move immediate adds the value of byte 2 into the c register*/
    case 0x0f: printf("rrc"); break; /*rotate instruction: rotates the eight bits in the accumulator and the 1 bit in the carry flag right one bit position: bit 0 goes into carry and also goes into bit 7*/
    case 0x10: printf("nop"); break;
    case 0x11: printf("lxi    d,#$%02x%02x", code[2], code[1]); opbytes=3; break; /*load register pair immediate - loads 16bit data in the register pair designated in the operand (de)*/
    case 0x12: printf("stax    d"); break; /*the content of the accumulator is stored in the memory location specified by the de register pair*/
    case 0x13: printf("inx    d"); break; /*the content of the de register pair is incremented by 1*/
    case 0x14: printf("inr    d"); break; /*the content of the d register is incremented by 1*/
    case 0x15: printf("dcr    d"); break; /*the content of the d register is decremented by 1*/
    case 0x16: printf("mvi    d,#$%02x",code[1]);opbytes=2; break; /*move immediate adds the value of byte 2 into the d register*/
    case 0x17: printf("ral"); break; /*rotate instruction: rotates the eight bits in the accumulator and the 1 bit in the carry flag left one bit position: bit 7 goes into carry and carry goes into bit 0*/
    case 0x18: printf("nop"); break;
    case 0x19: printf("dad    d"); break; /*double byte add instructions: adds the content of the de register pair into hl register pair*/
    case 0x1a: printf("ldax    d"); break; /*8 bit transfer instruction - load accumulator indirect. the contents of the designated register pair (de) point to a memory location. this instruction copies the contents of that memory loaction into the accumulator*/
    case 0x1b: printf("dcx    d"); break; /*the content of the de register pair is decremented by 1*/
    case 0x1c: printf("inr    e"); break; /*the content of the e register is incremented by 1*/
    case 0x1d: printf("dcr    e"); break; /*the content of the e register is decremented by 1*/
    case 0x1e: printf("mvi    e,#$%02x",code[1]);opbytes=2; break; /*move immediate adds the value of byte 2 into the e register*/
    case 0x1f: printf("rar"); break; /*rotate instruction: rotates the eight bits in the accumulator and the 1 bit in the carry flag right one bit position: bit 0 goes into carry and carry goes into bit 7*/
    case 0x20: printf("rim"); break; /*read interrupt mask in 8085 is a nop in the 8080*/
    case 0x21: printf("lxi    h,#$%02x%02x", code[2], code[1]); opbytes=3; break; /*load register pair immediate - loads 16bit data in the register pair designated in the operand (hl)*/
    case 0x22: printf("shld ,#$%02x%02x", code[2], code[1]); opbytes=3; break; /*store h and l register direct: the contents of register l are stored into the memory location specified by the 16 bit address in the operand and the contents of h register are stored into the next memory location by incrementing the operand*/
    case 0x23: printf("inx    h"); break; /*the content of the hl register pair is incremented by 1*/
    case 0x24: printf("inr    h"); break; /*the content of the h register is incremented by 1*/
    case 0x25: printf("dcr    h"); break; /*the content of the h register is decremented by 1*/
    case 0x26: printf("mvi    h,#$%02x",code[1]);opbytes=2; break; /*move immediate adds the value of byte 2 into the h register*/
    case 0x27: printf("daa"); break; /*special accumulator and flag instuction: decimal adjust accumulator - the contents of the accumulator are changed from a binary value to two 4-bit binary coded decimal digits*/
    case 0x28: printf("nop"); break;
    case 0x29: printf("dad    h"); break; /*double byte add instructions: adds the content of the hl register pair into hl register pair*/
    case 0x2a: printf("lhld ,#$%02x%02x", code[2], code[1]); opbytes=3; break; /*load register pair direct - loads contents of the 16bit memory location data in the hl register pair*/
    case 0x2b: printf("dcx    h"); break; /*the content of the hl register pair is decremented by 1*/
    case 0x2c: printf("inr    l"); break; /*the content of the l register is incremented by 1*/
    case 0x2d: printf("dcr    l"); break; /*the content of the l register is decremented by 1*/
    case 0x2e: printf("mvi    l,#$%02x",code[1]);opbytes=2; break; /*move immediate adds the value of byte 2 into the l register*/
    case 0x2f: printf("cma"); break; /*the content of the accumulator is complemented*/
    case 0x30: printf("sim"); break; /*send interrupt mask in 8085 is a nop in the 8080*/
    case 0x31: printf("lxi    sp,#$%02x%02x", code[2], code[1]); opbytes=3; break; /*load register pair immediate - loads 16bit data in the register pair designated in the operand stack pointer*/
    case 0x32: printf("sta ,#$%02x%02x", code[2], code[1]); opbytes=3; break; /*store accumulator: the contents of accumulator are stored into the memory location specified by the 16 bit address in the operand*/
    case 0x33: printf("inx    sp"); break; /*the content of the stack pointer is incremented by 1*/
    case 0x34: printf("inr    m"); break; /*the content of the hl register is incremented by 1*/
    case 0x35: printf("dcr    m"); break; /*the content of the hl register is decremented by 1*/
    case 0x36: printf("mvi    m,#$%02x",code[1]);opbytes=2; break; /*move immediate adds the value of byte 2 into the hl register*/
    case 0x37: printf("stc"); break; /*sets the carry flag*/
    case 0x38: printf("nop"); break;
    case 0x39: printf("dad    sp"); break; /*double byte add instructions: adds the content of the stack pointer into hl register pair*/
    case 0x3a: printf("lda    ,#$%02x%02x", code[2], code[1]); opbytes=3; break; /*load accumulator - loads contents from the given 16 bit address into the accumulator*/
    case 0x3b: printf("dcx    sp"); break; /*the content of the stack pointer is decremented by 1*/
    case 0x3c: printf("inr    a"); break; /*the content of the a register is incremented by 1*/
    case 0x3d: printf("dcr    a"); break; /*the content of the a register is decremented by 1*/
    case 0x3e: printf("mvi    a,#$%02x",code[1]);opbytes=2; break; /*move immediate adds the value of byte 2 into the a register*/
    case 0x3f: printf("cmc"); break; /*complement the carry flag*/
    case 0x40: printf("mov    b,b"); break; /*move the value of b register into b*/
    case 0x41: printf("mov    b,c"); break; /*move the value of c register into b*/
    case 0x42: printf("mov    b,d"); break; /*move the value of d register into b*/
    case 0x43: printf("mov    b,e"); break; /*move the value of e register into b*/
    case 0x44: printf("mov    b,h"); break; /*move the value of h register into b*/
    case 0x45: printf("mov    b,l"); break; /*move the value of l register into b*/
    case 0x46: printf("mov    b,m"); break; /*move the contents of the address at the hl register into b*/
    case 0x47: printf("mov    b,a"); break; /*move the value of a register into b*/
    case 0x48: printf("mov    c,b"); break; /*move the value of b register into c*/
    case 0x49: printf("mov    c,c"); break; /*move the value of c register into c*/
    case 0x4a: printf("mov    c,d"); break; /*move the value of d register into c*/
    case 0x4b: printf("mov    c,e"); break; /*move the value of e register into c*/
    case 0x4c: printf("mov    c,h"); break; /*move the value of h register into c*/
    case 0x4d: printf("mov    c,l"); break; /*move the value of l register into c*/
    case 0x4e: printf("mov    c,m"); break; /*move the contents of the address at the hl register into c*/
    case 0x4f: printf("mov    c,a"); break; /*move the value of a register into c*/
    case 0x50: printf("mov    d,b"); break; /*move the value of b register into d*/
    case 0x51: printf("mov    d,c"); break; /*move the value of c register into d*/
    case 0x52: printf("mov    d,d"); break; /*move the value of d register into d*/
    case 0x53: printf("mov    d,e"); break; /*move the value of e register into d*/
    case 0x54: printf("mov    d,h"); break; /*move the value of h register into d*/
    case 0x55: printf("mov    d,l"); break; /*move the value of l register into d*/
    case 0x56: printf("mov    d,m"); break; /*move the contents of the address at the hl register into d*/
    case 0x57: printf("mov    d,a"); break; /*move the value of a register into d*/
    case 0x58: printf("mov    e,b"); break; /*move the value of b register into e*/
    case 0x59: printf("mov    e,c"); break; /*move the value of c register into e*/
    case 0x5a: printf("mov    e,d"); break; /*move the value of d register into e*/
    case 0x5b: printf("mov    e,e"); break; /*move the value of e register into e*/
    case 0x5c: printf("mov    e,h"); break; /*move the value of h register into e*/
    case 0x5d: printf("mov    e,l"); break; /*move the value of l register into e*/
    case 0x5e: printf("mov    e,m"); break; /*move the contents of the address at the hl register into e*/
    case 0x5f: printf("mov    e,a"); break; /*move the value of a register into e*/
    case 0x60: printf("mov    h,b"); break; /*move the value of b register into h*/
    case 0x61: printf("mov    h,c"); break; /*move the value of c register into h*/
    case 0x62: printf("mov    h,d"); break; /*move the value of d register into h*/
    case 0x63: printf("mov    h,e"); break; /*move the value of e register into h*/
    case 0x64: printf("mov    h,h"); break; /*move the value of h register into h*/
    case 0x65: printf("mov    h,l"); break; /*move the value of l register into h*/
    case 0x66: printf("mov    h,m"); break; /*move the contents of the address at the hl register into h*/
    case 0x67: printf("mov    h,a"); break; /*move the value of a register into h*/
    case 0x68: printf("mov    l,b"); break; /*move the value of b register into l*/
    case 0x69: printf("mov    l,c"); break; /*move the value of c register into l*/
    case 0x6a: printf("mov    l,d"); break; /*move the value of d register into l*/
    case 0x6b: printf("mov    l,e"); break; /*move the value of e register into l*/
    case 0x6c: printf("mov    l,h"); break; /*move the value of h register into l*/
    case 0x6d: printf("mov    l,l"); break; /*move the value of l register into l*/
    case 0x6e: printf("mov    l,m"); break; /*move the contents of the address at the hl register into l*/
    case 0x6f: printf("mov    l,a"); break; /*move the value of a register into l*/
    case 0x70: printf("mov    m,b"); break; /*move the value of b register into contents of the address at hl*/
    case 0x71: printf("mov    m,c"); break; /*move the value of c register into contents of the address at hl*/
    case 0x72: printf("mov    m,d"); break; /*move the value of d register into contents of the address at hl*/
    case 0x73: printf("mov    m,e"); break; /*move the value of e register into contents of the address at hl*/
    case 0x74: printf("mov    m,h"); break; /*move the value of h register into contents of the address at hl*/
    case 0x75: printf("mov    m,l"); break; /*move the value of l register into contents of the address at hl*/
    case 0x76: printf("HLT"); break; /*Halt Processor*/
    case 0x77: printf("MOV    M,A"); break; /*Move the Value of A register into contents of the Address at HL*/
    case 0x78: printf("mov    a,b"); break; /*move the value of B register into A*/
    case 0x79: printf("mov    a,c"); break; /*move the value of C register into A*/
    case 0x7a: printf("mov    a,d"); break; /*move the value of D register into A*/
    case 0x7b: printf("mov    a,e"); break; /*move the value of E register into A*/
    case 0x7c: printf("mov    a,h"); break; /*move the value of H register into A*/
    case 0x7d: printf("mov    a,l"); break; /*move the value of L register into A*/
    case 0x7e: printf("mov    a,m"); break; /*move the contents of the address at the hl register into A*/
    case 0x7f: printf("mov    a,a"); break; /*move the value of A register into A*/
    case 0x80: printf("ADD    B"); break; /*Adds the value of B to the accumulator*/
    case 0x81: printf("ADD    C"); break; /*Adds the value of C to the accumulator*/
    case 0x82: printf("ADD    D"); break; /*Adds the value of D to the accumulator*/
    case 0x83: printf("ADD    E"); break; /*Adds the value of E to the accumulator*/
    case 0x84: printf("ADD    H"); break; /*Adds the value of H to the accumulator*/
    case 0x85: printf("ADD    L"); break; /*Adds the value of L to the accumulator*/
    case 0x86: printf("ADD    M"); break; /*Adds the value of the contents of the memory address at HL to the accumulator*/
    case 0x87: printf("ADD    A"); break; /*Adds the value of A to the accumulator*/
    case 0x88: printf("ADC    B"); break; /*Adds the value of B to the accumulator with Carry*/
    case 0x89: printf("ADC    C"); break; /*Adds the value of C to the accumulator with Carry*/
    case 0x8a: printf("ADC    D"); break; /*Adds the value of D to the accumulator with Carry*/
    case 0x8b: printf("ADC    E"); break; /*Adds the value of E to the accumulator with Carry*/
    case 0x8c: printf("ADC    H"); break; /*Adds the value of H to the accumulator with Carry*/
    case 0x8d: printf("ADC    L"); break; /*Adds the value of L to the accumulator with Carry*/
    case 0x8e: printf("ADC    M"); break; /*Adds the value of the contents of the memory address at HL to the accumulator with Carry*/
    case 0x8f: printf("ADC    A"); break; /*Adds the value of A to the accumulator with Carry*/
    case 0x90: printf("SUB    B"); break; /*Subtracts the value of B to the accumulator*/
    case 0x91: printf("SUB    C"); break; /*Subtracts the value of C to the accumulator*/
    case 0x92: printf("SUB    D"); break; /*Subtracts the value of D to the accumulator*/
    case 0x93: printf("SUB    E"); break; /*Subtracts the value of E to the accumulator*/
    case 0x94: printf("SUB    H"); break; /*Subtracts the value of H to the accumulator*/
    case 0x95: printf("SUB    L"); break; /*Subtracts the value of L to the accumulator*/
    case 0x96: printf("SUB    M"); break; /*Subtracts the value of the contents of the memory address at HL to the accumulator*/
    case 0x97: printf("SUB    A"); break; /*Subtracts the value of A to the accumulator*/
    case 0x98: printf("SBB    B"); break; /*Subtracts the value of B to the accumulator with Borrow*/
    case 0x99: printf("SBB    C"); break; /*Subtracts the value of C to the accumulator with Borrow*/
    case 0x9a: printf("SBB    D"); break; /*Subtracts the value of D to the accumulator with Borrow*/
    case 0x9b: printf("SBB    E"); break; /*Subtracts the value of E to the accumulator with Borrow*/
    case 0x9c: printf("SBB    H"); break; /*Subtracts the value of H to the accumulator with Borrow*/
    case 0x9d: printf("SBB    L"); break; /*Subtracts the value of L to the accumulator with Borrow*/
    case 0x9e: printf("SBB    M"); break; /*Subtracts the value of the contents of the memory address at HL to the accumulator with Borrow*/
    case 0x9f: printf("SBB    A"); break; /*Subtracts the value of A to the accumulator with Borrow*/
    case 0xa0: printf("ANA    B"); break; /*Ands the value of B to the accumulator*/
    case 0xa1: printf("ANA    C"); break; /*Ands the value of C to the accumulator*/
    case 0xa2: printf("ANA    D"); break; /*Ands the value of D to the accumulator*/
    case 0xa3: printf("ANA    E"); break; /*Ands the value of E to the accumulator*/
    case 0xa4: printf("ANA    H"); break; /*Ands the value of H to the accumulator*/
    case 0xa5: printf("ANA    L"); break; /*Ands the value of L to the accumulator*/
    case 0xa6: printf("ANA    M"); break; /*Ands the value of the contents of the memory address at HL to the accumulator*/
    case 0xa7: printf("ANA    A"); break; /*Ands the value of A to the accumulator*/
    case 0xa8: printf("XRA    B"); break; /*ExclusiveOr (XOR) the value of B to the accumulator*/
    case 0xa9: printf("XRA    C"); break; /*ExclusiveOr (XOR) the value of C to the accumulator*/
    case 0xaa: printf("XRA    D"); break; /*ExclusiveOr (XOR) the value of D to the accumulator*/
    case 0xab: printf("XRA    E"); break; /*ExclusiveOr (XOR) the value of E to the accumulator*/
    case 0xac: printf("XRA    H"); break; /*ExclusiveOr (XOR) the value of H to the accumulator*/
    case 0xad: printf("XRA    L"); break; /*ExclusiveOr (XOR) the value of L to the accumulator*/
    case 0xae: printf("XRA    M"); break; /*ExclusiveOr (XOR) the value of the contents of the memory address at HL to the accumulator*/
    case 0xaf: printf("XRA    A"); break; /*ExclusiveOr (XOR) the value of A to the accumulator*/
    case 0xb0: printf("ORA    B"); break; /*ORs the value of B to the accumulator*/
    case 0xb1: printf("ORA    C"); break; /*ORs the value of C to the accumulator*/
    case 0xb2: printf("ORA    D"); break; /*ORs the value of D to the accumulator*/
    case 0xb3: printf("ORA    E"); break; /*ORs the value of E to the accumulator*/
    case 0xb4: printf("ORA    H"); break; /*ORs the value of H to the accumulator*/
    case 0xb5: printf("ORA    L"); break; /*ORs the value of L to the accumulator*/
    case 0xb6: printf("ORA    M"); break; /*ORs the value of the contents of the memory address at HL to the accumulator*/
    case 0xb7: printf("ORA    A"); break; /*ORs the value of A to the accumulator*/
    case 0xb8: printf("CMP    B"); break; /*Compares the value of B to the accumulator*/
    case 0xb9: printf("CMP    C"); break; /*Compares the value of C to the accumulator*/
    case 0xba: printf("CMP    D"); break; /*Compares the value of D to the accumulator*/
    case 0xbb: printf("CMP    E"); break; /*Compares the value of E to the accumulator*/
    case 0xbc: printf("CMP    H"); break; /*Compares the value of H to the accumulator*/
    case 0xbd: printf("CMP    L"); break; /*Compares the value of L to the accumulator*/
    case 0xbe: printf("CMP    M"); break; /*Compares the value of the contents of the memory address at HL to the accumulator*/
    case 0xbf: printf("CMP    A"); break; /*Compares the value of A to the accumulator*/
    case 0xc0: printf("RNZ"); break; /*If NZ Return*/
    case 0xc1: printf("POP B"); break; /*puts the 16 bit value on the stack into BC register pair*/
    case 0xc2: printf("JNZ    ,#$%02x%02x", code[2], code[1]); opbytes=3; break; /*Jump to Addr if NZ*/
    case 0xc3: printf("JMP    ,#$%02x%02x", code[2], code[1]); opbytes=3; break; /*Jump to Addr*/
    case 0xc4: printf("CNZ    ,#$%02x%02x", code[2], code[1]); opbytes=3; break; /*Call Addr if NZ*/
    case 0xc5: printf("PUSH   B"); break; /*puts the 16 bit value in BC on the stack*/
    case 0xc6: printf("ADI    ,#$%02x", code[1]); opbytes=2; break; /*Add immediate operand to A*/
    case 0xc7: printf("RST    0"); break; /*Restart  - Call 0*/
    case 0xc8: printf("RZ"); break; /*If Z Return*/
    case 0xc9: printf("RET"); break; /*Return*/
    case 0xca: printf("JZ    ,#$%02x%02x", code[2], code[1]); opbytes=3; break; /*If Z jump to address*/
    case 0xcb: printf("nop"); break;
    case 0xcc: printf("CZ    ,#$%02x%02x", code[2], code[1]); opbytes=3; break; /*If Z call address*/
    case 0xcd: printf("CALL    ,#$%02x%02x", code[2], code[1]); opbytes=3; break; /*call address*/
    case 0xce: printf("ACI    ,#$%02x", code[1]); opbytes=2; break; /*Add immediate operand to A with Carry*/
    case 0xcf: printf("RST    1"); break; /*Restart  - Call $8*/
    case 0xd0: printf("RNC"); break; /*Return if Carry Flag is not set*/
    case 0xd1: printf("POP D"); break; /*puts the 16 bit value on the stack into DE register pair*/
    case 0xd2: printf("JNC    ,#$%02x%02x", code[2], code[1]); opbytes=3; break; /*If not carry jump to address*/
    case 0xd3: printf("OUT    ,#$%02x", code[1]); opbytes=2; break; /*Special*/
    case 0xd4: printf("CNC    ,#$%02x%02x", code[2], code[1]); opbytes=3; break; /*If not carry call address*/
    case 0xd5: printf("PUSH   D"); break; /*puts the 16 bit value in DE on the stack*/
    case 0xd6: printf("SUI    ,#$%02x", code[1]); opbytes=2; break; /*Subtract Immediate from A*/
    case 0xd7: printf("RST    2"); break; /*Restart  - Call $10*/
    case 0xd8: printf("RC"); break; /*If carry Return*/
    case 0xd9: printf("nop"); break;
    case 0xda: printf("JC    ,#$%02x%02x", code[2], code[1]); opbytes=3; break; /*If carry jump to address*/
    case 0xdb: printf("IN    ,#$%02x", code[1]); opbytes=2; break; /*Special*/
    case 0xdc: printf("CC    ,#$%02x%02x", code[2], code[1]); opbytes=3; break; /*If Carry call address*/
    case 0xdd: printf("nop"); break;
    case 0xde: printf("SBI    ,#$%02x", code[1]); opbytes=2; break; /*Subtract Immediate from A with Borrow*/
    case 0xdf: printf("RST    3"); break; /*Restart  - Call $18*/
    case 0xe0: printf("RPO"); break; /*Return if Parity Flag is not set*/
    case 0xe1: printf("POP H"); break; /*puts the 16 bit value on the stack into HL register pair*/
    case 0xe2: printf("JPO    ,#$%02x%02x", code[2], code[1]); opbytes=3; break; /*If not parity jump to address*/
    case 0xe3: printf("XTHL"); break; /*Swap H:L with top word on stack*/
    case 0xe4: printf("CPO    ,#$%02x%02x", code[2], code[1]); opbytes=3; break; /*If not parity call address*/
    case 0xe5: printf("PUSH   H"); break; /*puts the 16 bit value in HL on the stack*/
    case 0xe6: printf("ANI    ,#$%02x", code[1]); opbytes=2; break; /*AND Immediate with A*/
    case 0xe7: printf("RST    4"); break; /*Restart  - Call $20*/
    case 0xe8: printf("RPE"); break; /*Return if PE*/
    case 0xe9: printf("PCHL"); break; /*Load the program counter with HL contents*/
    case 0xea: printf("JPE    ,#$%02x%02x", code[2], code[1]); opbytes=3; break; /*If parity jump to address*/
    case 0xeb: printf("XCHG"); break; /*Exchange DE and HL content*/
    case 0xec: printf("CPE    ,#$%02x%02x", code[2], code[1]); opbytes=3; break; /*If parity call address*/
    case 0xed: printf("nop"); break;
    case 0xee: printf("XRI    ,#$%02x", code[1]); opbytes=2; break; /*XOR Immediate with A*/
    case 0xef: printf("RST    5"); break; /*Restart  - Call $28*/
    case 0xf0: printf("RP"); break; /*Return if Parity*/
    case 0xf1: printf("POP PSW"); break; /*Pop program status word*/
    case 0xf2: printf("JP    ,#$%02x%02x", code[2], code[1]); opbytes=3; break; /*If not sign flag jump to address*/
    case 0xf3: printf("DI"); break; /*Disable Interrupts */
    case 0xf4: printf("CP    ,#$%02x%02x", code[2], code[1]); opbytes=3; break; /*If not sign call address*/
    case 0xf5: printf("PUSH PSW"); break; /*Push program status word*/
    case 0xf6: printf("ORI    ,#$%02x", code[1]); opbytes=2; break; /*OR Immediate with A*/
    case 0xf7: printf("RST    6"); break; /*Restart  - Call $30*/
    case 0xf8: printf("RM"); break; /*Return if M*/
    case 0xf9: printf("SPHL"); break; /*Load the Stack Pointer with HL contents*/
    case 0xfa: printf("JM    ,#$%02x%02x", code[2], code[1]); opbytes=3; break; /*If M jump to to address*/
    case 0xfb: printf("EI"); break; /*Enable Interrupts */
    case 0xfc: printf("CM    ,#$%02x%02x", code[2], code[1]); opbytes=3; break; /*If M call address*/
    case 0xfd: printf("nop"); break;
    case 0xfe: printf("CRI    ,#$%02x", code[1]); opbytes=2; break; /*Compare Immediate with A*/
    case 0xff: printf("RST    7"); break; /*Restart  - Call $38*/
  }

  printf("\n");

  return opbytes;
}

int main (int argc, char**argv)
{
  FILE *f= fopen(argv[1], "rb");
  if (f==NULL)
  {
    printf("error: Couldn't open %s\n", argv[1]);
    exit(1);
  }

  //Get the file size and read it into a memory buffer
  fseek(f, 0L, SEEK_END);
  int fsize = ftell(f);
  fseek(f, 0L, SEEK_SET);

  unsigned char *buffer=malloc(fsize);

  fread(buffer, fsize, 1,f);
  fclose(f);

  int pc =0;
  while (pc < fsize)
  {
    pc += Disassemble8080op(buffer, pc);
  }
  return 0;
}
