#include <map>
#include <string>
#include <vector>

typedef std::map<int, int> intint_map;
typedef std::map<std::string, int> strint_map;

typedef std::vector<int> int_vector;
typedef std::vector<std::string> string_vector;

typedef intint_map::iterator ii_map_iter;
typedef strint_map::iterator si_map_iter;

typedef int_vector::iterator ivter;
typedef string_vector::iterator svter;

int main() {
  intint_map iim;
  iim[0xABCD] = 0xF0F1;

  strint_map sim;
  sim["world"] = 42;

  int_vector iv;
  iv.push_back(3);

  string_vector sv;
  sv.push_back("hello");

  ii_map_iter iimI = iim.begin();
  si_map_iter simI = sim.begin();

  ivter ivI = iv.begin();
  svter svI = sv.begin();

  return 0; // Set break point at this line.
}
