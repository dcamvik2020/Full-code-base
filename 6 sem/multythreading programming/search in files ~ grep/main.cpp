#include <iostream>

/// find expression in files recursively from directory
/// UPD : expr may be regular expression

void Usage ()
{
  std::cout << "Usage :\n"
	    <<   "\t./search dir expr\n"
	    << "dir    directory for searching\n"
	    << "expr   line/regular expression to find in ALL files\n";
  
}

void search (const std::string & dir_name, const std::string & expr_match)
{
  
  
}

/// ./search dir expr
int main (int argc, char * argv[]) {
  if (argc < 3) {
    Usage();
    return 0;
  }

  std::string dir_name(argv[1]);
  std::string expr_match(argv[2]);

  search(dir_name, expr_match);

  return 0;
}
