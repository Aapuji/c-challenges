#pragma once

#include <queue>
#include <string>

class charstream {
    private:
        std::queue<char> stream;
    
    public:
        charstream();
        
        charstream(std::string str);
        
        charstream(const char *s);
        
        void push(char c);
        
        void push(std::string str);
        
        charstream operator[](int i);
        
        char front();
        
        char next();
        
        std::string flush();
        
        void clear();
        
        operator std::string();
        
        charstream operator=(std::string str);
};
