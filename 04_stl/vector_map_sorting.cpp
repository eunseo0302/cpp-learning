#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

int main() {
    std::vector<int> myvec = {40, 20, 30};
    std::map<std::string, std::string> capitals;
    
    myvec.push_back(1);
    myvec.push_back(200);
    myvec.push_back(70);
    
    std::sort(myvec.begin(), myvec.end());
    
    for (std::vector<int>::const_iterator it = myvec.begin(); it != myvec.end(); it++) {
        printf("%d ", *it);
    }
    
    capitals["korea"] = "seoul";
    capitals["china"] = "beijing";
    capitals["usa"] = "washington";
    
    //capitals.erase("korea");
    
    if (capitals.count("korea") == 1) {
        printf("korea가 존재합니다\n");
    }
    
    else {
        printf("korea가 존재하지 않습니다\n");
    }
    
    for (auto it = capitals.begin(); it != capitals.end(); it++) {
        printf("first: %s\n", it->first.c_str());
        printf("second: %s\n", it->second.c_str());
        printf("capitals[%s]->%s\n", it->first.c_str(), it->second.c_str());
    }
    
    printf("%s", capitals["korea"].c_str());
    
    return 0;
}

Add STL practice with vector, map, and sort algorithm
