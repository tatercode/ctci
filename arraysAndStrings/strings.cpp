#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <cctype>
#include <cmath>

// O(n) space
bool isUniqueHashmap(const std::string& s) {
  std::unordered_map <char, int> count;

  for (int i = 0; i < s.length(); ++i){
    if (count.find(s.at(i)) != count.end()) {
      return false;
    }
    count[s.at(i)] = 1;
  }

  return true;
}

// O(1) space
bool isUniqueArray(const std::string& s) {
  if (s.length() > 256) { // Longer than amount of extended ascii chars
    return false;
  }

  bool char_set[256] = {false}; 

  for (char c : s) {
    if (char_set[int(c)]) {
      return false;
    } 
    char_set[int(c)] = true;
  }

  return true;
}

std::string printTrueOrFalse(const bool& val) {
  if (val) 
    return "true";
  else {
    return "false";
  }
  
}

bool checkPermutation(const std::string& s1, const std::string& s2) {
  if (s1.length() != s2.length()) 
    return false;
  
  std::unordered_map<char, int> s_map;

  for (char c : s1) {
    if (s_map.find(c) == s_map.end()) 
      s_map[c] = 1;
    else 
      ++s_map[c];
  }

  for (char c : s2) {
    if (s_map.find(c) == s_map.end()) 
      s_map[c] = 1;
    else 
      --s_map[c];
  }

  for (const auto& [key, value] : s_map) {
    if (value != 0) 
      return false;
  }

  return true;
}

void urlify(char* s, int true_length) {
  int space_count = 0;
  for (int i = 0; i < true_length; i++) {
    if (s[i] == ' ') {
      space_count++;
    }
  }

  int new_index = true_length + space_count * 2 - 1;

  for (int i = true_length - 1; i >= 0; i--) {
    if (s[i] == ' ') {
      s[new_index] = '0';
      s[new_index - 1] = '2';
      s[new_index - 2] = '%';
      new_index -= 3;
    } else {
      s[new_index] = s[i];
      new_index--;
    }
  }
}

bool palindromePermutation(std::string s) {
  std::unordered_map<char, int> letters;

  s.erase(std::remove_if(s.begin(), s.end(), ::isspace), s.end());
  std::transform(s.begin(), s.end(), s.begin(), 
                    [] (unsigned char c) { return std::tolower(c); });

  for (char c : s) {
    letters[c]++;
  }

  if (s.length() % 2 == 0) {
    for (auto& pair : letters) {
      if (pair.second % 2 != 0)
        return false;
    } 
  } else {
    bool oneOdd = false;
    for (auto& pair : letters) {
      if (pair.second % 2 != 0) {
        if (!oneOdd) {
          oneOdd = true;
          continue;
        }
        return false;
      }
    }
  }

  return true;
}

bool oneAway(const std::string& s1, const std::string& s2) {
  // Length check
  if (std::abs(int(s1.length() - s2.length())) > 1) {
    return false;
  }

  // Case 1: Replacement (same length)
  if (s1.length() == s2.length()) {
    int diff_count = 0;
    for (int i = 0; i < s1.length(); i++) {
      if (s1[i] != s2[i]) {
        diff_count++;
      }
    }
    return diff_count <= 1;
  }

  // Case 2: Insertion/Deletion (length diff is 1)
  const std::string& shorter = (s1.length() < s2.length()) ? s1 : s2;
  const std::string& longer = (s1.length() < s2.length()) ? s2 : s1;

  int i_short = 0;
  int i_long = 0;
  bool found_diff = false;

  while(i_short < shorter.length() && i_long < longer.length()) {
    if (shorter[i_short] != longer[i_long]) {
      if (found_diff) {
        return false; // Found a second difference
      }
      found_diff = true;
      i_long++; // On first difference, only advance the longer pointer
    } else {
      i_short++;
      i_long++;
    }
  }
  return true;
}

std::string stringCompression(std::string& s) {
  std::string new_s = "";

  char cur_letter = s[0];
  int count = 0;
  for (char c : s) {
    if (cur_letter != c) {
      new_s += cur_letter;
      new_s += std::to_string(count); 
      count = 0;
      cur_letter = c;
    }
    ++count;
  }

  new_s += cur_letter;
  new_s += std::to_string(count); 

  if (new_s.length() >= s.length()) {
    return s;
  }

  return new_s;
}


int main(int argc, char* argv[]) {

  for (int i = 0; i < argc; ++i) {
    std::cout << i << ": " << argv[i] << std::endl;
  }

  // bool resIsUnique = isUniqueArray(argv[1]);
  // std::cout << argv[1] << " is unique: " << printTrueOrFalse(resIsUnique) << std::endl;
  
  // bool resCheckPerm = checkPermutation(argv[1], argv[2]);
  // std::cout << argv[1] << " " << argv[2] << " are permutations: " << printTrueOrFalse(resCheckPerm) << std::endl;
  
  // The urlify function assumes the char array has enough space.
  // Modifying argv[1] is unsafe. Here's a safer way to test:
  // char str[] = "Mr John Smith    "; // 13 chars + 4 spaces for 2 replacements
  // std::cout << "Original string: \"" << str << "\"" << std::endl;
  // urlify(str, 13); // True length of "Mr John Smith" is 13
  // std::cout << "URLified string: \"" << str << "\"" << std::endl;

  // std::string val = "taco cat";
  // bool resPalindromPerm = palindromePermutation(val);
  // std::cout << val << " is a palindrome permutation: " << printTrueOrFalse(resPalindromPerm) << std::endl;
  
  std::string val = "aaabbbcccddeee";
  std::string resStringCompression = stringCompression(val);
  std::cout << val << " compressed: " << resStringCompression << std::endl;

  return 1;
}
