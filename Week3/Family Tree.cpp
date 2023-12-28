#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>

class nutTree {
public:
   std::string name;
   std::vector<nutTree*> nodeCon;

   nutTree(const std::string& name) : name(name) {}
};

nutTree* bFT(const std::vector<std::pair<std::string, std::string> >& relations) {
   std::map<std::string, nutTree*> pDict;
   nutTree* root = NULL;

   for (size_t i = 0; i < relations.size(); i++) {
       const std::string& child = relations[i].first;
       const std::string& parent = relations[i].second;

       if (pDict.find(parent) == pDict.end()) {
           pDict[parent] = new nutTree(parent);
       }

       if (pDict.find(child) == pDict.end()) {
           pDict[child] = new nutTree(child);
       }

       pDict[parent]->nodeCon.push_back(pDict[child]);
   }

   for (std::map<std::string, nutTree*>::iterator it = pDict.begin(); it != pDict.end(); it++) {
       nutTree* person = it->second;
       bool hasParent = false;

       for (std::map<std::string, nutTree*>::iterator nodeIt = pDict.begin(); nodeIt != pDict.end(); nodeIt++) {
           nutTree* node = nodeIt->second;
           for (size_t j = 0; j < node->nodeCon.size(); j++) {
               if (node->nodeCon[j] == person) {
                   hasParent = true;
                   break;
               }
           }
       }

       if (!hasParent) {
           root = person;
           break;
       }
   }

   return root;
}

int countDescendants(nutTree* node) {
   if (node->nodeCon.empty()) {
       return 0;
   }

   int totalDescendants = node->nodeCon.size();
   for (size_t i = 0; i < node->nodeCon.size(); i++) {
       totalDescendants += countDescendants(node->nodeCon[i]);
   }

   return totalDescendants;
}

int countGenerations(nutTree* node) {
   if (node->nodeCon.empty()) {
       return 0;
   }

   int maxGenerations = 0;
   for (size_t i = 0; i < node->nodeCon.size(); i++) {
       maxGenerations = std::max(maxGenerations, countGenerations(node->nodeCon[i]));
   }

   return maxGenerations + 1;
}

int main() {
   std::vector<std::pair<std::string, std::string> > relations;
   std::string line;

   while (true) {
       std::getline(std::cin, line);
       if (line == "***") {
           break;
       }

       std::string child, parent;
       std::istringstream iss(line);
       iss >> child >> parent;
       relations.push_back(std::make_pair(child, parent));
   }

   nutTree* root = bFT(relations);

   while (true) {
       std::string cmd, prm;
       std::cin >> cmd >> prm;

       if (cmd == "descendants") {
           nutTree* node = root;

           while (node->name != prm) {
               for (size_t i = 0; i < node->nodeCon.size(); i++) {
                   if (prm == node->nodeCon[i]->name) {
                       node = node->nodeCon[i];
                       break;
                   }
               }
           }

           std::cout << countDescendants(node) << std::endl;
       }
       else if (cmd == "generation") {
           nutTree* node = root;

           while (node->name != prm) {
               for (size_t i = 0; i < node->nodeCon.size(); i++) {
                   if (prm == node->nodeCon[i]->name) {
                       node = node->nodeCon[i];
                       break;
                   }
               }
           }

           std::cout << countGenerations(node) << std::endl;
       }
       else {
           break;
       }
   }

   return 0;
}

