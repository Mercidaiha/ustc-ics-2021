/*
 * @Author       : Chivier Humber
 * @Date         : 2021-09-15 21:15:24
 * @LastEditors  : Chivier Humber
 * @LastEditTime : 2021-11-23 16:08:51
 * @Description  : file content
 */
#include "common.h"
#include "memory.h"

namespace virtual_machine_nsp {
    void memory_tp::ReadMemoryFromFile(std::string filename, int beginning_address) {
        // Read from the file
        // TO BE DONE
        std::ifstream memoryfile;   //读入memoryfile  
        memoryfile.open(filename);   //打开名字对应文件 
        int ptr = beginning_address; //起始地址 
        int line_count = std::count(std::istreambuf_iterator<char>(memoryfile),std::istreambuf_iterator<char>(), '\n'); //查找，以\n结尾，即为行数 
        memoryfile.close();     //结束该操作 
        memoryfile.open(filename); 
        char instru[17];   //16位指令 
        for (int i = 0; i < line_count; i++) {
            memoryfile >>instru;   
            memory[ptr] = 0;
            for (int j = 0; instru[j]; j++) {
                memory[ptr]+=(instru[j]-48)* pow(2,16-j-1);
            }
            ptr++;
        }
        memoryfile.close();
    }

    int16_t memory_tp::GetContent(int address) const {
        // get the content
        // TO BE DONE
        return memory[address];
    }

    int16_t& memory_tp::operator[](int address) {
        // get the content
        // TO BE DONE
        return memory[address];
    }    
}; // virtual machine namespace
