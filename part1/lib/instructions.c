#include <instructions.h>
#include <cpu.h>

instruction instructions[0x100] = {
    [0x00] = {IN_NOP, AM_IMP},
    [0x01] = {IN_LD, AM_R_D16, RT_BC},
    [0x02] = {IN_LD, AM_MR_R, RT_BC, RT_A},

    [0x05] = {IN_DEC, AM_R, RT_B},
    [0x06] = {IN_LD, AM_R_D8, RT_B},

    [0x08] = {IN_LD, AM_A16_R, RT_NONE, RT_SP},

    [0x0A] = {IN_LD, AM_R_MR, RT_A, RT_BC},

    [0x0E] = {IN_LD, AM_R_D8, RT_C},

    //0x1X
    [0x11] = {IN_LD, AM_R_D16, RT_DE},
    [0x12] = {IN_LD, AM_MR_R, RT_DE, RT_A},
    [0x15] = {IN_DEC, AM_R, RT_D},
    [0x16] = {IN_LD, AM_R_D8, RT_D},
    [0x1A] = {IN_LD, AM_R_MR, RT_A, RT_DE},
    [0x1E] = {IN_LD, AM_R_D8, RT_E},

    //0x2X
    [0x21] = {IN_LD, AM_R_D16, RT_HL},
    [0x22] = {IN_LD, AM_HLI_R, RT_HL, RT_A},
    [0x25] = {IN_DEC, AM_R, RT_H},
    [0x26] = {IN_LD, AM_R_D8, RT_H},
    [0x2A] = {IN_LD, AM_R_HLI, RT_A, RT_HL},
    [0x2E] = {IN_LD, AM_R_D8, RT_L},

    //0x3X
    [0x31] = {IN_LD, AM_R_D16, RT_SP},
    [0x32] = {IN_LD, AM_HLD_R, RT_HL, RT_A},
    [0x35] = {IN_DEC, AM_R, RT_HL},
    [0x36] = {IN_LD, AM_MR_D8, RT_HL},
    [0x3A] = {IN_LD, AM_R_HLD, RT_A, RT_HL},
    [0x3E] = {IN_LD, AM_R_D8, RT_A},

    //0x4X
    [0x40] = {IN_LD, AM_R_R, RT_B, RT_B},
    [0x41] = {IN_LD, AM_R_R, RT_B, RT_C},
    [0x42] = {IN_LD, AM_R_R, RT_B, RT_D},
    [0x43] = {IN_LD, AM_R_R, RT_B, RT_E},
    [0x44] = {IN_LD, AM_R_R, RT_B, RT_H},
    [0x45] = {IN_LD, AM_R_R, RT_B, RT_L},
    [0x46] = {IN_LD, AM_R_MR, RT_B, RT_HL},
    [0x47] = {IN_LD, AM_R_R, RT_B, RT_A},
    [0x48] = {IN_LD, AM_R_R, RT_C, RT_B},
    [0x49] = {IN_LD, AM_R_R, RT_C, RT_C},
    [0x4A] = {IN_LD, AM_R_R, RT_C, RT_D},
    [0x4B] = {IN_LD, AM_R_R, RT_C, RT_E},
    [0x4C] = {IN_LD, AM_R_R, RT_C, RT_H},
    [0x4D] = {IN_LD, AM_R_R, RT_C, RT_L},
    [0x4E] = {IN_LD, AM_R_MR, RT_C, RT_HL},
    [0x4F] = {IN_LD, AM_R_R, RT_C, RT_A},

    //0x5X
    [0x50] = {IN_LD, AM_R_R,  RT_D, RT_B},
    [0x51] = {IN_LD, AM_R_R,  RT_D, RT_C},
    [0x52] = {IN_LD, AM_R_R,  RT_D, RT_D},
    [0x53] = {IN_LD, AM_R_R,  RT_D, RT_E},
    [0x54] = {IN_LD, AM_R_R,  RT_D, RT_H},
    [0x55] = {IN_LD, AM_R_R,  RT_D, RT_L},
    [0x56] = {IN_LD, AM_R_MR, RT_D, RT_HL},
    [0x57] = {IN_LD, AM_R_R,  RT_D, RT_A},
    [0x58] = {IN_LD, AM_R_R,  RT_E, RT_B},
    [0x59] = {IN_LD, AM_R_R,  RT_E, RT_C},
    [0x5A] = {IN_LD, AM_R_R,  RT_E, RT_D},
    [0x5B] = {IN_LD, AM_R_R,  RT_E, RT_E},
    [0x5C] = {IN_LD, AM_R_R,  RT_E, RT_H},
    [0x5D] = {IN_LD, AM_R_R,  RT_E, RT_L},
    [0x5E] = {IN_LD, AM_R_MR, RT_E, RT_HL},
    [0x5F] = {IN_LD, AM_R_R,  RT_E, RT_A},

    //0x6X
    [0x60] = {IN_LD, AM_R_R,  RT_H, RT_B},
    [0x61] = {IN_LD, AM_R_R,  RT_H, RT_C},
    [0x62] = {IN_LD, AM_R_R,  RT_H, RT_D},
    [0x63] = {IN_LD, AM_R_R,  RT_H, RT_E},
    [0x64] = {IN_LD, AM_R_R,  RT_H, RT_H},
    [0x65] = {IN_LD, AM_R_R,  RT_H, RT_L},
    [0x66] = {IN_LD, AM_R_MR, RT_H, RT_HL},
    [0x67] = {IN_LD, AM_R_R,  RT_H, RT_A},
    [0x68] = {IN_LD, AM_R_R,  RT_L, RT_B},
    [0x69] = {IN_LD, AM_R_R,  RT_L, RT_C},
    [0x6A] = {IN_LD, AM_R_R,  RT_L, RT_D},
    [0x6B] = {IN_LD, AM_R_R,  RT_L, RT_E},
    [0x6C] = {IN_LD, AM_R_R,  RT_L, RT_H},
    [0x6D] = {IN_LD, AM_R_R,  RT_L, RT_L},
    [0x6E] = {IN_LD, AM_R_MR, RT_L, RT_HL},
    [0x6F] = {IN_LD, AM_R_R,  RT_L, RT_A},

    //0x7X
    [0x70] = {IN_LD, AM_MR_R,  RT_HL, RT_B},
    [0x71] = {IN_LD, AM_MR_R,  RT_HL, RT_C},
    [0x72] = {IN_LD, AM_MR_R,  RT_HL, RT_D},
    [0x73] = {IN_LD, AM_MR_R,  RT_HL, RT_E},
    [0x74] = {IN_LD, AM_MR_R,  RT_HL, RT_H},
    [0x75] = {IN_LD, AM_MR_R,  RT_HL, RT_L},
    [0x76] = {IN_HALT},
    [0x77] = {IN_LD, AM_MR_R,  RT_HL, RT_A},
    [0x78] = {IN_LD, AM_R_R,  RT_A, RT_B},
    [0x79] = {IN_LD, AM_R_R,  RT_A, RT_C},
    [0x7A] = {IN_LD, AM_R_R,  RT_A, RT_D},
    [0x7B] = {IN_LD, AM_R_R,  RT_A, RT_E},
    [0x7C] = {IN_LD, AM_R_R,  RT_A, RT_H},
    [0x7D] = {IN_LD, AM_R_R,  RT_A, RT_L},
    [0x7E] = {IN_LD, AM_R_MR, RT_A, RT_HL},
    [0x7F] = {IN_LD, AM_R_R,  RT_A, RT_A},

    [0xAF] = {IN_XOR, AM_R, RT_A},

    [0xC3] = {IN_JP, AM_D16},

    //0xEX
    [0xE2] = {IN_LD, AM_MR_R, RT_C, RT_A},
    [0xEA] = {IN_LD, AM_A16_R, RT_NONE, RT_A},


    //0xFX
    [0xF2] = {IN_LD, AM_R_MR, RT_A, RT_C},
    [0xF3] = {IN_DI},
    [0xFA] = {IN_LD, AM_R_A16, RT_A},
};

instruction *instruction_by_opcode(u8 opcode) {
    return &instructions[opcode];
}

char *inst_lookup[] = {
    "<NONE>",
    "NOP",
    "LD",
    "INC",
    "DEC",
    "RLCA",
    "ADD",
    "RRCA",
    "STOP",
    "RLA",
    "JR",
    "RRA",
    "DAA",
    "CPL",
    "SCF",
    "CCF",
    "HALT",
    "ADC",
    "SUB",
    "SBC",
    "AND",
    "XOR",
    "OR",
    "CP",
    "POP",
    "JP",
    "PUSH",
    "RET",
    "CB",
    "CALL",
    "RETI",
    "LDH",
    "JPHL",
    "DI",
    "EI",
    "RST",
    "IN_ERR",
    "IN_RLC", 
    "IN_RRC",
    "IN_RL", 
    "IN_RR",
    "IN_SLA", 
    "IN_SRA",
    "IN_SWAP", 
    "IN_SRL",
    "IN_BIT", 
    "IN_RES", 
    "IN_SET"
};

char *inst_name(in_type t) {
    return inst_lookup[t];
}
