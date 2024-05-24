#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>

// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
//stack and queue
//1) Max Nesting Depth of the Parenthese
    int maxDepth(string s) {
            stack<char> st;
    int maxDepth = 0;

    for (char c : s) {
        if (c == '(') {
            st.push(c); 
            if (st.size() > maxDepth) {
                maxDepth = st.size();
            }
        } else if (c == ')') {
            st.pop();
        }
    }

    return maxDepth;        
    }
//kompleksiteti kohor është (O(n)), ( n ) është gjatësia e vargut ( s ). Kjo ndodh sepse ne iterojmë përmes vargut një herë, duke kryer operacione me kohë konstante për secilin karakter.
//Kompleksiteti hapësinor është (O(n)) në rastin më të keq, ku ( n ) është gjatësia e vargut ( s ). Kjo ndodh kur të gjithë karakteret janë (, duke kërkuar një madhësi staku të barabartë me gjatësinë e vargut.

//2)Baseball Game
    int calPoints(vector<string>& operations) {
        vector<int> record;

        for (const string& op : operations) {
            if (op == "C") {
                if (!record.empty()) {
                    record.pop_back();
                }
            } else if (op == "D") {
                if (!record.empty()) {
                    record.push_back(2 * record.back());
                }
            } else if (op == "+") {
                if (record.size() >= 2) {
                    record.push_back(record[record.size() - 1] + record[record.size() - 2]);
                }
            } else {
                record.push_back(stoi(op));
            }
        }

        int totalSum = 0;
        for (int score : record) {
            totalSum += score;
        }

        return totalSum;
    }
//Kompleksiteti kohor i këtij kodi është O(n).
//Kompleksiteti hapësinor i këtij kodi është O(n).

//3)First Unique Character in a string
    int firstUniqChar(string s) {
        unordered_map<char, int> charCount;

        for (char c : s) {
            charCount[c]++;
        }
        for (int i = 0; i < s.length(); ++i) {
            if (charCount[s[i]] == 1) {
                return i;
            }
        }

        return -1;
    }
//Kompleksiteti kohor (O(n))
//Kompleksiteti hapësinor (O(1)

//4)Remove Outermost parentheses
    string removeOuterParentheses(string s) {
        string result = "";
        int opened = 0;

        for (char c : s) {
            if (c == '(') {
                if (opened > 0) {
                    result += c; // Shto '(' në rezultat vetëm nëse është brenda stringut paraprak të jashtëm
                }
                opened++;
            } else if (c == ')') {
                opened--;
                if (opened > 0) {
                    result += c; // Shto ')' në rezultat vetëm nëse është brenda stringut paraprak të jashtëm
                }
            }
        }

        return result;
        
    }
//Kompleksiteti kohor (O(n))
//Kompleksiteti hapësinor (O(n))

//5) Remove All Adjecent Duplicates in String
    string removeDuplicates(string s) {
        stack<char> st;
        
        for (char c : s) {
            if (!st.empty() && st.top() == c) {
                st.pop();
            } else {
                st.push(c); 
            }
        }
        string result = "";
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }
        
        return result;
        
    }
//Kompleksiteti kohor (O(n))
//Kompleksiteti hapsinor (O(n))

//Binary Search Tree

//1) Range Sum of BST
    int rangeSumBST(TreeNode* root, int low, int high) {
        // Kontrollon nëse nyja aktuale është bosh kthen 0 si shumë e nën-pemës.
          if (!root)
              return 0; 
        
        // Kontrollon nëse vlera e nyjes është më e vogël se 'low'.
        // Nëse po, nuk ka nevojë të kërkohet në nën-pemën majtas pasi të gjitha vlerat do të jenë më të vogla.
        if (root->val < low)
            return rangeSumBST(root->right, low, high);
        
        // Kontrollon nëse vlera e nyjes është më e madhe se 'high'.
        // Nëse po, nuk ka nevojë të kërkohet në nën-pemën djathtas pasi të gjitha vlerat do të jenë më të mëdha.
        if (root->val > high) 
            return rangeSumBST(root->left, low, high);
        
        // Nëse vlera e nyjes është brenda intervalit [low, high], shto vlerën e nyjes në shumën totale,
        // dhe vazhdo të kërkosh në të dy nën-pemet (majtas dhe djathtas) për vlera të tjera që mund të jenë brenda intervalit.
        return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
        
    }
//kompleksiteti kohor 
//rasti me i mire O(log n)-nëse pema është e balancuar mirë.
//rasti me i keq O(n)-ëse struktura e pemës është e thellë dhe jo e balancuar (si një listë e lidhur), funksioni do të vizitojë çdo nyje të pemës.

//Kompleksiteti hapsinor
//rasti me i mire O(log n)-Nëse pema është relativisht e balancuar
//rasti me i keq O(n)-kur pema është degraduar në një listë të lidhur



//2)Increasing Order Search Tree
    TreeNode* increasingBST(TreeNode* root) {
        // Krijon një nyje ndihmëse për të ndihmuar në rirenditjen.
         TreeNode* answer = new TreeNode(0); 
        // Përdor një pointer ndihmës për të mbajtur vendin aktual ku duhet të shtohet nyja e ardhshme.
        TreeNode* curr = answer;
        // Thirr funksionin ndihmës 'inorder' për të filluar rirenditjen.
        inorder(root, curr);
        // Kthen pemen e re që fillon nga nyja pas nyjes ndihmëse.
        return answer->right;
    }
    
    // Funksioni 'inorder' që viziton pemën.
    void inorder(TreeNode* node, TreeNode*& curr) {
         // Kontrollon nëse nyja është bosh. Nëse po, kthehu.
        if (!node) return;
        
        inorder(node->left, curr);// Vizito nën-pemën e majtë parë. 
        node->left = nullptr; // Heq lidhjen e majtë të nyjes aktuale pasi ajo nuk është e nevojshme në pemën e re.
        curr->right = node;// Lidh nyjen aktuale me të djathtën e 'curr'.
        curr = node;  // Zhvendos 'curr' për të treguar te nyja e fundit e shtuar.
        inorder(node->right, curr); // Vizito nën-pemën e djathtë.
    }
//Kompleksiteti kohor
// O(n)-Funksioni inorder viziton çdo nyje të pemës një herë. n është numri i nyjeve në pemë. 

//Kompleksiteti hapsinor
//rasti me i keq O(n)-kur pema degradohet në një listë të gjatë (e gjithë pema është në një anë)
//kur pema eshte e balancuar O(logn)

//3)Search in a Binary Search Tree
    TreeNode* searchBST(TreeNode* root, int val) {
        
         // Nëse arrin në një nyje bosh, kthe nullptr
        if(root==nullptr){
            return nullptr;
        }
        
        // Nëse gjen vlerën, kthe nyjen aktuale
        if(root->val==val){
            return root;
        }
        
         // Nëse vlera është më e madhe se vlera e nyjes, vazhdo kërkimin në nënpemën e djathtë
        else if(val>root->val){
            return searchBST(root->right, val);
        }
        
        // Nëse vlera është më e vogël, vazhdo kërkimin në nënpemën e majtë
        else{
            return searchBST(root->left, val);
        }
    }
//kompleksiteti kohore:
//rasti me i mire O(log n)-kur pema eshte e balancuar
//rasti me i keq O(n)-Kur pemë degradohet në një strukturë të ngjashme me listën e lidhur (p.sh., kur të gjitha elementet janë në një vijë të vetme)

//Kompleksiteti hapsinor
//rasti me i mire O(log n)
//rasti me i keq O(n)

//4)Two Sum IV-Input is a BST
    bool findTarget(TreeNode* root, int k) {
       vector<int>vals; // Lista për të ruajtur vlerat e pemës në rend rritës.
        stack<TreeNode*> stack;// Stack për ndihmë në përsiatjen in-order.
        TreeNode* current = root;// Fillon me rrënjën e pemës.

        // Ky cikël realizon përsiatjen in-order përmes një stack-u.
        while (current != nullptr || !stack.empty()) {
            // Shkon deri në elementin më të majtë.
            while (current != nullptr) {
                stack.push(current);// Shton nyjet në stack për t'u rikthyer më vonë.
                current = current->left;// Lëviz majtas.
            }
            
            // Merr nyjen nga stack-u dhe e trajton si nyja aktuale.
            current = stack.top();
            stack.pop();
            vals.push_back(current->val);// Shton vlerën e nyjes në listë.
            current = current->right;// Lëviz djathtas.
        }

        // Krijon dy pointer-at për të kërkuar dy numrat që plotësojnë kushtin e shumës.
        int left = 0;// Fillon nga fillimi i listës.
        int right = vals.size() - 1;// Fillon nga fundi i listës.

        // Ekzekuton algoritmin dy-pointer.
        while (left < right) {
            int sum =vals[left] + vals[right]; // Llogarit shumën e dy elementëve.
            
             // Nëse shuma është e barabartë me k, kthen true.
            if (sum == k) {
                return true;
                
                // Nëse shuma është më e vogël, rrit pointer-in e majtë.
            } else if (sum < k) {
                left++;
                
                // Nëse shuma është më e madhe, zvogëlon pointer-in e djathtë.
            } else {
                right--;
            }
        }
        // Nëse nuk gjendet asnjë çift, kthen false.
        return false;
    }
//Kompleksiteti kohore;
//O(n)
//kompleksiteti kohore:
//O(n)

//5)Connvert Sorted Array to Binary Search Tree
    TreeNode* sortedArrayToBST(vector<int>& nums) {
          return constructBST(nums, 0, nums.size() - 1);
    }

    TreeNode* constructBST(vector<int>& nums, int start, int end) {
        if (start > end) {
            return nullptr; // Baza e rekursivitetit: nëse fillimi është më i madh se fundi, kthe nullptr.
        }

        int mid = start + (end - start) / 2; // Gjej elementin mesatar për të shmangur overflow.
        TreeNode* node = new TreeNode(nums[mid]); // Krijo një nyje të re me vlerën mesatare.

        // Ndërto nën-pemën e majtë duke përdorur gjysmën e majtë të array-it
        node->left = constructBST(nums, start, mid - 1);
        // Ndërto nën-pemën e djathtë duke përdorur gjysmën e djathtë të array-it
        node->right = constructBST(nums, mid + 1, end);

        return node; // Kthe nyjen që tani ka nën-pema të ndërtuara.
    }
//Kompleksiteti kohore 
//O(n)

//Kompleksiteti hapsinor
//Rasti me i mire O(log n)-ema e krijuar është e balancuar, kështu që thellësia e rekursivitetit do të jetë logaritmike në lidhje me numrin e elementeve.
//rasti me i keq O(n)-do element i array-t përdoret për të krijuar një nyje të pemës, kështu që hapësira totale përfshin të gjitha nyjet e pemës.
};

int main() {
    Solution solution;
    int choice;

    cout << "Choose an option:\n";
    cout << "1. Max Nesting Depth of the Parentheses\n";
    cout << "2. Baseball Game\n";
    cout << "3. First Unique Character in a String\n";
    cout << "4. Remove Outermost Parentheses\n";
    cout << "5. Remove All Adjacent Duplicates in String\n";
    cout << "6. Range Sum of BST\n";
    cout << "7. Increasing Order Search Tree\n";
    cout << "8. Search in a Binary Search Tree\n";
    cout << "9. Two Sum IV - Input is a BST\n";
    cout << "10. Convert Sorted Array to Binary Search Tree\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            string s;
            cout << "Enter the parentheses string: ";
            cin >> s;
            cout << "Maximum depth: " << solution.maxDepth(s) << endl;
            break;
        }
        case 2: {
            int n;
            cout << "Enter the number of operations: ";
            cin >> n;
            vector<string> operations(n);
            cout << "Enter operations:\n";
            for (int i = 0; i < n; ++i) {
                cin >> operations[i];
            }
            cout << "Total points: " << solution.calPoints(operations) << endl;
            break;
        }
        case 3: {
            string s;
            cout << "Enter the string: ";
            cin >> s;
            int index = solution.firstUniqChar(s);
            if (index != -1) {
                cout << "First unique character is at index: " << index << endl;
            } else {
                cout << "No unique character found." << endl;
            }
            break;
        }
        case 4: {
            string s;
            cout << "Enter the parentheses string: ";
            cin >> s;
            cout << "Resulting string: " << solution.removeOuterParentheses(s) << endl;
            break;
        }
        case 5: {
            string s;
            cout << "Enter the string: ";
            cin >> s;
            cout << "Resulting string after removing duplicates: " << solution.removeDuplicates(s) << endl;
            break;
        }
        case 6: {
            cout << "Range Sum of BST not implemented in the main function." << endl;
            break;
        }
        case 7: {
            cout << "Increasing Order Search Tree not implemented in the main function." << endl;
            break;
        }
        case 8: {
            cout << "Search in a Binary Search Tree not implemented in the main function." << endl;
            break;
        }
        case 9: {
            cout << "Two Sum IV - Input is a BST not implemented in the main function." << endl;
            break;
        }
        case 10: {
            cout << "Convert Sorted Array to Binary Search Tree not implemented in the main function." << endl;
            break;
        }
        default:
            cout << "Invalid choice." << endl;
            break;
    }
    return 0;
}

