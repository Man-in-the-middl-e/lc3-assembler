#pragma once

#include <array>
#include <string>

enum class InsturctionOpCode : uint8_t {
    BR = 0b0000,
    ADD = 0b0001,
    LD = 0b0010,
    ST = 0b0011,
    JSSR = 0b0100,
    AND = 0b0101,
    LDR = 0b0110,
    STR = 0b0111,
    RTI = 0b1000,
    NOT = 0b1001,
    LDI = 0b1010,
    STI = 0b1011,
    RET = 0b1100,
    NON = 0b1101,
    LEA = 0b1110,
    TRAP = 0b1111,
};

class Instruction {
  public:
    Instruction(uint16_t instruction) : m_instruction(instruction) {}
    uint16_t getBits(uint8_t from, uint8_t to);

  private:
    uint16_t m_instruction;
};

class CPU {
  public:
    CPU() = default;
    bool load(const std::string& fileToRun);
    bool emulate();

  private:
    void dumpMemory(uint16_t start, uint16_t size);
    InsturctionOpCode getOpCode(uint16_t instruction) const;

  private:
    static constexpr uint16_t MEMORY_CAPACITY =
        std::numeric_limits<uint16_t>::max();
    static constexpr uint8_t NUMBER_OF_REGISTERS = 8;

  private:
    std::array<uint16_t, MEMORY_CAPACITY> m_memory;
    std::array<uint8_t, NUMBER_OF_REGISTERS> m_registers;
    uint16_t m_pc;
};