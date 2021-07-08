#include <iostream>
#include <vector>
#include <omp.h>

#include <ctime>

void prepare_num(std::string & a, std::string & b, unsigned num_len);
void reverse (std::string & str);

/// ./prog threads num_len
int main(int argc, char * argv[])
{
    if (argc < 3) 
    {
        std::cout << "Too few arguments!\n";
	return 1;
    }

    srand(time(NULL));

    unsigned threads = atol(argv[1]);
    unsigned num_len = atol(argv[2]);

    std::string a(num_len);
    std::string b(num_len);
    std::string sum(num_len + 1);
    prepare_num(a, b, num_len);
    
    
    std::vector<bool> digit_transfer(threads, false);
    unsigned chunk_size = num_len / threads;
    double start = omp_get_wtime();

#pragma omp parallel thread_num(threads)
{
    unsigned tid = omp_get_thread_num();
    unsigned l = tid * chunk_size;
    unsigned r = (tid == threads - 1) ? (num_len) : (l + chunk_size);

    unsigned little_size, rest; /// 5+5=10, 4+5=9 --> rest=1, rest=0
    if (tid == threads - 1)
    {
        little_size = num_len - l;
    }
    else
    {
        little_size = chunk_size;
    }
    std::string little_sum_1(little_size);
    std::string little_sum_2(little_size);
    
    

#pragma omp barrier
    
    
}

    /// remove extra zeros
    for ( ; max_size > 1 && sum[max_size - 1] == '0'; --max_size);
    reverse(sum);
    
    double finish = omp_get_wtime();
    std::cout << "threads = " << threads << "\n";
    std::cout << "a + b   = " << sum << "\n";
    std::cout << "time    = " << finish - start << "\n";
    return 0;
}






void prepare_num(std::string & a, std::string & b, unsigned num_len)
{
    a[0] = '1' + rand() % 9;
    b[0] = '1' + rand() % 9;
    for (unsigned i = 1; i < num_len; ++i)
    {
        a[i] = '0' + rand() % 10;
        b[i] = '0' + rand() % 10;
    }
    //std::cout << "a = " << a << "\n";
    //std::cout << "b = " << b << "\n";
    reverse(a);
    reverse(b);
}

void reverse (std::string & str)
{
    for (unsigned i = 0; i < str.size() / 2; ++i)
    {
        char tmp = str[i];
	str[i] = str[str.size() - 1 - i];
	str[str.size() - 1 - i] = tmp;
    }
}
