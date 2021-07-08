
#include "number.h"


Number::Block::Block (const std::string & str = "") : block("") {
    if (str.size() > blocksize) {
        throw std::invalid_argument("Block() : wrong size");
    }
    if (str.size() < blocksize) {
        block = std::string(blocksize - str.size(), '0');
    }
    block += str;
}


bool Number::Block::isZero () const {
	for (unsigned j = 0; j < blocksize; ++j)
    	if (block[j] != '0')
        	return false;
        return true;
}

bool Number::Block::operator == (const Block & rhs) {
    const std::string & rhs_block = rhs.getBlock();
	for (unsigned j = 0; j < blocksize; ++j)
	    if (block[j] != rhs_block[j])
		    return false;
	return true;
}

bool Number::Block::operator != (const Block & rhs) {
    return !(*this == rhs);
}

    /// over <--> extra 1-9 at rightest place
Number::Block Number::blocksum (const Block & lhs, const Block & rhs, char & over)
{
	std::string l = lhs.getBlock(), r = rhs.getBlock();
    std::string sum(blocksize, '0');
    for (unsigned j = blocksize - 1; ; --j) {
        char digit_sum = over + l[j] - '0' + r[j] - '0';
        sum[j] = '0' + digit_sum % 10;
        over = digit_sum / 10;
        if (j == 0) break;
    }
    return Block(sum);
}


/// take <---> take 1 from bigger digit
Number::Block Number::blocksub (const Block & lhs, const Block & rhs, bool& take)
{
    



}


Number::Number (const std::string & num) {
    unsigned cntblocks = num.size() / blocksize;
    if (num.size() % blocksize != 0 || num.size() == 0)
        cntblocks++;

    data_size = cntblocks;
    data.resize(data_size);
    unsigned blockID = data_size - 1;
    unsigned r = num.size();
    
    if (num[0] == '-') sign = true;
	for ( ; r > 1; blockID--) {
        unsigned l = (r >= blocksize) ?
                 r - blocksize : 1;
        data[blockID] = Block(num.substr(l, r - l));
		r = l;
    }
}

/// remove extra zero blocks
void Number::correctNumber() {
    unsigned j = 0;
	for ( ; data[j].isZero(); ++j);
	if (j == 0) return;
	for (unsigned i = 0; i + j < data_size; ++i) {
        data[i] = data[i + j];
	}
	data.resize(data_size - j);
	data_size = data.size();
}

Number operator + (const Number & lhs, const Number &rhs) {
    if (rhs.getSign() == true) return lhs 
    const std::vector<Block> & rhs_data = rhs.getData();
    unsigned rhs_size = rhs_data.size();
    unsigned sum_size = std::max(data_size, rhs_size) + 1;
    std::vector<Block> sum(sum_size);
        
    char over = 0;
    for (size_t k = 0; k < sum_size; ++k) {
        unsigned pos = sum_size - 1 - k;
        unsigned data_pos = data_size - 1 - k;
        unsigned rhs_pos = rhs_size - 1 - k;
            
        Block arg_1, arg_2;
        if (k >= data_size && k >= rhs_size)
        {
            arg_1 = Block(std::string(""));
            arg_2 = Block(std::string(1, '0' + over));
        } 
        else if (k >= data_size)
        {
            arg_1 = Block(std::string(""));
            arg_2 = rhs_data[rhs_pos];
        }
        else if (k >= rhs_size)
        {
            arg_1 = data[data_pos];
            arg_2 = Block(std::string(""));
        }
        else
        {
            arg_1 = data[data_pos];
            arg_2 = rhs_data[rhs_pos]; 
        }
        sum[pos] = blocksum(arg_1, arg_2, over);
    }

    Number result(sum);
	result.correctNumber();
    return result;
}


Number Number::operator - (const Number &rhs) {
/*    const std::vector<Block> & rhs_data = rhs.getData();
    unsigned rhs_size = rhs_data.size();
    unsigned sub_size = std::max(data_size, rhs_size) + 1;
    std::vector<Block> sub(sub_size);

    bool take = false; /// take from elder block
    for (unsigned k = 0; k < sub_size; ++k)
	{
        unsigned pos = sub_size - 1 - k;
        unsigned 
	}
*/
    Number.result();
	result.correctNumber();
	return result;
}


bool Number::operator == (const Number & rhs) {
    if (sign != rhs.getSign()) return false;
	const std::vector<Block> & rhs_data = rhs.getData();
	unsigned i = 0, j = 0;
	for ( ; data[i].isZero(); ++i);
	for ( ; rhs_data[j].isZero(); ++j);
	for ( ; j < rhs_data.size(); ++j)
	    if (data[j] != rhs_data[j])
		    return false;
	return true;
}


bool Number::operator != (const Number & rhs) {
    return !(*this == rhs);
}


std::ostream & operator << (std::ostream & os, const Number::Block & rhs)
{
    unsigned j = 0;
	const std::string & block = rhs.getBlock();
	for ( ; block[j] == '0'; ++j);
	for ( ; j < block.size(); ++j)
	{
        os << block[j];
    }
	return os;
}


std::ostream & operator << (std::ostream & os, const Number& rhs)
{
    unsigned i = 0;
	const std::vector<Number::Block> data = rhs.getData();
    if (data[0].isZero()) ++i;
    for ( ; i < data.size(); ++i) {
        os << data[i];
	} 
    return os;
}
