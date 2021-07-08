//#pragma once

#ifndef NUMBER_H
#define NUMBER_H

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

/// Number = std::vector<block>
class Number {
private:
    static const unsigned blocksize = 16;
    
    class Block {
    private:
        std::string block;
    public:
        Block (const std::string & str);
		Block (const Block & rhs) {
            block = rhs.getBlock();
		}

        bool isZero () const;
        std::string & getBlock () {return block;}
		const std::string & getBlock () const {return block;}

        Block & operator = (const Block & rhs) {
			block = rhs.getBlock();
			return *this;
        }
        
        bool operator == (const Block & rhs);
		bool operator != (const Block & rhs);

        ~Block () {}
    };

    /// over <--> extra 1-9 at rightest place
    Block blocksum (const Block & lhs, const Block & rhs, char& over);
    Block blocksub (const Block & lhs, const Block & rhs, bool& take);
    
    bool sign;
	unsigned data_size;
    std::vector<Block> data;
    void correctNumber();
public:
    Number (const std::string & num = "");
	Number (const std::vector<Block> & blocks)
		: sign(false), data_size(blocks.size()), data(blocks) {}
    Number (const Number & rhs) {
        sign = rhs.getSign();
		data = rhs.getData();
		data_size = data.size();
	}

    bool getSign() const {return sign;}
    const std::vector<Block> & getData () const {return data;}
    std::vector<Block> & getData () {return data;}

    friend Number operator + (const Number & lhs, const Number &rhs);
    Number operator - (const Number &rhs);
	Number & operator = (const Number & rhs) {
	    sign = rhs.getSign();
		data = rhs.getData();
        data_size = data.size();
		return *this;
	}

    bool operator == (const Number & rhs);
    bool operator != (const Number & rhs);
    
	~Number () {}

    friend std::ostream & operator << (std::ostream & os, const Block & rhs);
    friend std::ostream & operator << (std::ostream & os, const Number& rhs);
};

#endif
