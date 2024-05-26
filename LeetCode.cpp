#include <iostream>
#include <stack>
#include <queue>
#include <unordered_set>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
//Definition for singly-linked list.
  struct ListNode1 {
      int val1;
      ListNode1 *next1;
      ListNode1(int x1) : val1(x1), next1(NULL) {}
  };
class Solution {
public:
//stack and queue
//1) Max Nesting Depth of the Parenthese
 int maxDepth(string s) {
            stack<char> st;// Krijon një stek për të mbajtur karakteret e hapësirës
    int maxDepth = 0;// Niveli maksimal i thellësisë

        // Iteron nëpër karakteret e stringut s
    for (char c : s) {
        if (c == '(') {// Nëse gjejmë një hapësirë hyrëse
            st.push(c); // Shto hapësirën në stek
            if (st.size() > maxDepth) {// Kontrollo nivelin e thellësisë aktual
                maxDepth = st.size();// Nëse është më i madh se maxDepth, azhurno maxDepth
            }
        } else if (c == ')') {// Nëse gjejmë një hapësirë dalëse
            st.pop();// Hiq një hapësirë nga steku (paraqet përputhjen e një hapësire hyrëse me një dalëse)
        }
    }

    return maxDepth; // Kthe nivelin maksimal të thellësisë       
    }
//kompleksiteti kohor është (O(n)), ( n ) është gjatësia e vargut ( s ). Kjo ndodh sepse ne iterojmë përmes vargut një herë, duke kryer operacione me kohë konstante për secilin karakter.
//Kompleksiteti hapësinor është (O(n)) në rastin më të keq, ku ( n ) është gjatësia e vargut ( s ). Kjo ndodh kur të gjithë karakteret janë (, duke kërkuar një madhësi staku të barabartë me gjatësinë e vargut.

//2)Baseball Game
       int calPoints(vector<string>& operations) {
        vector<int> record;

        // Kalo nëpër secilën operacion të dhënë në listën e operacioneve.
        for (const string& op : operations) {
            if (op == "C") {
                // Operacioni 'C' invalidon pikën e fundit të regjistruar.
                if (!record.empty()) {// Kontrollon nëse ka pikë për të fshirë.
                    record.pop_back();
                }
            } else if (op == "D") {
                // Operacioni 'D' dyfishon pikën e fundit të regjistruar dhe e shton atë te regjistri.
                if (!record.empty()) {// Sigurohet që ka të paktën një pikë për të dyfishuar.
                    record.push_back(2 * record.back());
                }
            } else if (op == "+") {
                // Operacioni '+' shton dy pikët e fundit të regjistruara.
                if (record.size() >= 2) {// Kontrollon nëse ka të paktën dy pikë për t'u shtuar.
                    record.push_back(record[record.size() - 1] + record[record.size() - 2]);
                }
            } else {
                // Nëse operacioni është një numër, thjesht e konverton atë në int dhe e shton te regjistri.
                record.push_back(stoi(op));
            }
        }

        int totalSum = 0;
        // Llogarit shumën totale të pikëve të regjistruara.
        for (int score : record) {
            totalSum += score;
        }

        return totalSum;
    }
//Kompleksiteti kohor i këtij kodi është O(n).
//Kompleksiteti hapësinor i këtij kodi është O(n).

//3)First Unique Character in a string
     int firstUniqChar(string s) {
        unordered_map<char, int> charCount;// Krijon një mapë për të numëruar sa herë secili karakter gjendet në string

      // Llogarit numrin e shfaqjeve të secilit karakter në string
        for (char c : s) {
            charCount[c]++;// Shto 1 në numrin e shfaqjeve për karakterin c
        }
        
         // Kërko karakterin e parë të vetëm në string
        for (int i = 0; i < s.length(); ++i) {
            if (charCount[s[i]] == 1) { // Nëse numri i shfaqjeve të karakterit në mapë është 1
                return i;// Kthe indeksin e karakterit të parë të vetëm
            }
        }

        return -1;// Kthe -1 nëse nuk gjendet karakter i tillë
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
        
        // Iteron nëpër çdo karakter të vargut.
        for (char c : s) {
             // Kontrollon nëse stack nuk është bosh dhe karakteri i fundit në stack është i njëjtë me karakterin aktual.
            if (!st.empty() && st.top() == c) {
                st.pop(); // Nëse dy karakteret janë njësoj, i heq ata nga stack (heq vetëm njërin pasi janë të dy njësoj).
            } else {
                st.push(c); // Nëse nuk janë njësoj, shton karakterin aktual në stack.
            }
        }
        string result = "";
        // Tërheq karakteret nga stack dhe i shton në fillim të vargut të rezultatit për t'i kthyer në rendin e duhur.
        while (!st.empty()) {
            result = st.top() + result;// Shton karakterin e fundit të stack në fillim të vargut rezultant.
            st.pop();// Hiq karakterin nga stack.
        }
        
        return result;// Kthen vargun e përpunuar si rezultat.
        
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

//Linked List

//1)Convert Binary Number in a Linked List to Integer
 int getDecimalValue(ListNode* head) {
        int result = 0;
        
        // Përsërit derisa të kesh arritur në fund të listës
        while(head!=nullptr){
            // Zhvendos të gjithë bitat e rezultatit një pozicion majtas dhe bashko vlerën e bitit aktual
            result = (result<<1)|head->val;
            // Kalo te elementi pasardhës në listë
            head=head->next;
        }
        return result;
        
    }
//Kompleksittei kohore
//o(n)- n është numri i elementeve në listë. Çdo element i listës vizitohet një herë për të ndërtuar numrin binar.

//Kompleksiteti hapsinor
//O(1)-sepse pavarësisht nga madhësia e listës, përdor vetëm disa ndryshore të thjeshta dhe nuk kërkon memorie shtesë që varet nga hyrjet.

//2)Middle of the Linked Liste
 ListNode* middleNode(ListNode* head) {
        ListNode *slow=head;// Treguesi i ngadaltë fillon nga koka e listës
        ListNode *fast=head;// Treguesi i shpejtë gjithashtu fillon nga koka
        
        // Lëviz treguesin e shpejtë dy hapa për çdo hap të treguesit të ngadaltë
        while(fast!=nullptr&&fast->next!=nullptr){
            slow=slow->next; // Lëviz një hap përpara
            fast=fast->next->next;// Lëviz dy hapa përpara
        }
        // Kur treguesi i shpejtë arrin në fund të listës, treguesi i ngadaltë do të jetë në mes
        return slow;
 }
//Kompleksiteti kohore
//O(n)-Edhe pse duket qe treguesi i shpejtë lëviz dy herë më shpejt se ai i ngadaltë, ne e shqyrtojmë çdo nyje në listë vetëm një herë në praktikë

//Kompleksiteti hapsinor
//O(1)-pavarësisht madhësisë së listës, përdorim vetëm dy tregues të thjeshtë.


//3)Reverse Linked List
      ListNode* reverseList(ListNode* head) {
       ListNode* prev = nullptr;     // Tregon nyjen e mëparshme
        ListNode* current = head;     // Tregon nyjen aktuale që po procesohet
        ListNode* next = nullptr;     // Tregon nyjen pasardhëse

        while (current != nullptr) {
            next = current->next;    // Ruaj referencën e nyjes pasardhëse
            current->next = prev;    // Kthe lidhjen e nyjes aktuale
            prev = current;          // Lëviz treguesin e mëparshëm përpara
            current = next;          // Lëviz në nyjen pasardhëse
        }

        return prev;  // Kthe 'prev' që tani është koka e listës së kthyer
    }
//kompleksiteti kohore
//O(n)- n është numri i nyjeve në listë. Çdo nyje vizitohet vetëm një herë.

//Kompleksiteti hapsinor
//O(1)-sepse nuk perdor mmemorie shtese qe te rritet me madhesine e hyrjes, vetem treguesishtese qe nuk jane te varur nga madhesia e liste

  //4)Linked List Cycle
    bool hasCycle(ListNode1 *head) {
        if (!head || !head->next1) {
            return false;
        }

        ListNode1 *slow = head;       // Pointeri "tortoise" fillon nga koka dhe lëviz me një hap.
        ListNode1 *fast = head->next1;  // Pointeri "hare" fillon nga elementi i dytë dhe lëviz me dy hapa.

        while (fast != slow) {
            if (!fast || !fast->next1) {
                return false;  // Nëse pointeri "hare" arrin në fund të listës, nuk ka cikël.
            }
            slow = slow->next1;        // Lëviz pointerin "tortoise" përpara me një hap.
            fast = fast->next1->next1;  // Lëviz pointerin "hare" përpara me dy hapa.
        }

        return true;  // Nëse pointerat takohen, atëherë ekziston një cikël.
    }
//kompleksitetin kohore
//O(n)

//Kompleksiteti hapsinor
//O(1)

//5)Remove Linked List Elements
ListNode* removeElements(ListNode* head, int val) {
         // Krijon një nyje ndihmëse përpara listës aktuale
       ListNode* helper=new ListNode(0);
        helper->next=head;
        
        // Përdor dy pointer-a për të kontrolluar listën
        ListNode* current = helper;
        while(current->next!=nullptr){
            if(current->next->val==val){
                 // Nëse vlera e nyjes së ardhshme është e barabartë me 'val', heq këtë nyje
                ListNode* temp=current->next;
                current->next=current->next->next;
                delete temp;// Çliro memorien e nyjes së hequr
            }
            else{
                // Përndryshe, vazhdo me nyjen tjetër
                current=current->next;
            }
        }
        // Ruaj pointerin e ri të fillimit të listës
        ListNode* newHead=helper->next;
        delete helper;// Çliro memorien e nyjes ndihmëse
        return newHead;
}
//Kompleksiteti kohor
//O(n)

//Kompleksiteti hapsinor
//O(1)

  //Hash Tables
  //1)Permutation Difference between Two Strings
   int findPermutationDifference(string s, string t) {
        unordered_map<char, int> indexInS, indexInT;
        
        // Regjistro indeksin e çdo karakteri në s
        for (int i = 0; i < s.size(); ++i) {
            indexInS[s[i]] = i;
        }

        // Regjistro indeksin e çdo karakteri në t
        for (int i = 0; i < t.size(); ++i) {
            indexInT[t[i]] = i;
        }

        int totalDifference = 0;

        // Llogarit shumën e diferencave absolute
        for (int i = 0; i < s.size(); ++i) {
            totalDifference += abs(indexInS[s[i]] - indexInT[s[i]]);
        }

        return totalDifference;
    }
//Kompleksiteti kohore
//O(n)

//Kompleksiteti hapsinor
//O(1)-Hapësira e përdorur nga tabelat hash është konstante në raport me madhësinë e hyrjes, pasi ka vetëm 26 shkronja të vogla.

  //2)Number of Good Pairs
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        int total = 0;
        for (auto it : count) {
            total += it.second * (it.second - 1) / 2;
        }

        return total;
    }
//Kompleksiteti kohore
//O(n)

//Kompleksiteti hapsinor
//O(n)

  //3)Jewels and Stones
   int numJewelsInStones(string jewels, string stones) {
        unordered_set<char>jewelSet(jewels.begin(),jewels.end());
        int jewelCount=0;
        for(char stone:stones){
            if (jewelSet.count(stone)>0){
                jewelCount++;
            }
        }
        return jewelCount;
    }
//Kompleksiteti kohore dhe hapsinor
//O(n)
 };

void printInOrder(TreeNode* node) {
    if (!node)
        return;
    printInOrder(node->left);
    cout << node->val << " ";
    printInOrder(node->right);
}
void printIncreasingOrder(TreeNode* node) {
    while (node != NULL) {
        cout << node->val << " ";
        node = node->right;
    }
}
void printTree(TreeNode* root) {
    if (root != nullptr) {
        cout << root->val << " ";
        printTree(root->left);
        printTree(root->right);
    }
}

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
ListNode* createLinkedList(const vector<int>& values) {
    ListNode* head = nullptr;
    ListNode* current = nullptr;
    for (int value : values) {
        if (head == nullptr) {
            head = new ListNode(value);
            current = head;
        } else {
            current->next = new ListNode(value);
            current = current->next;
        }
    }
    return head;
}
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
    cout << "11. Convert Binary Number in a Linked List to Integer\n";
    cout << "12. Middle of the Linked Liste\n";
    cout << "13. Rverse Linked List\n";
    cout << "14. Linked List Cycle\n";
    cout << "15. Remove Linked List Elements\n";
    cout << "16.  Permutation Difference between Two Strings\n";
    cout << "17. Number Of Good Pairs\n";
    cout << "18. Jewels and Stones\n";
 
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
         cout<<"An integer record a new score."<<endl;
         cout<<"'+'-Record a new score that is the sum of the previous two scores."<<endl;
         cout<<"'D'-Recoed a new score that is the double of the previous score."<<endl;
         cout<<"'C'-Invaildate the previous score, removing it from the record."<<endl;
            cout << "Enter the number of operations: ";
            cin >> n;
            vector<string> operations(n);
            cout << "Enter operations:\n";
            for (int i = 0; i < n; ++i) {
                cin >> operations[i];
            }
         cout<<"[";
          for (int i = 0; i < n; ++i) {
                cout<<"'" <<operations[i]<<"'"<<",";
            }
            cout<<"]" <<endl;
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
           TreeNode* root = new TreeNode(10);
            root->left = new TreeNode(5);
            root->right = new TreeNode(15);
            root->left->left = new TreeNode(3);
            root->left->right = new TreeNode(7);
            root->right->right = new TreeNode(18);
           cout << "InOrder Traversal of BST: ";
           printInOrder(root);
           cout << endl;
           int low = 7;
           int high = 15;
           int result = solution.rangeSumBST(root, low, high);
           cout << "Range Sum of BST: " << result << std::endl;
           delete root->left->left;
           delete root->left->right;
           delete root->left;
           delete root->right->right;
           delete root->right;
           delete root;
            break;
        }
       case 7: {
            TreeNode* root = new TreeNode(5);
            root->left = new TreeNode(3);
            root->right = new TreeNode(6);
            root->left->left = new TreeNode(2);
            root->left->right = new TreeNode(4);
            root->right->right = new TreeNode(8);
            root->left->left->left = new TreeNode(1);
            root->right->right->left = new TreeNode(7); 
            root->right->right->right = new TreeNode(9); 

           cout << "Increasing Order BST: ";
            printInOrder(root);
            cout << endl;
            delete root->left->left->left;
            delete root->left->left->right; 
            delete root->left->left;
            delete root->left->right;
            delete root->left;
            delete root->right->right->left; 
            delete root->right->right;
            delete root->right;
            delete root;
            break;
        }
        case 8: {
  TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    cout << "Input Tree: ";
    printTree(root);
    cout << endl;
    int val;
    cout << "Enter the value to search for in BST: ";
    cin >> val;
    TreeNode* result = solution.searchBST(root, val);
    cout << "Output for the value " << val << ": ";
    if (result != nullptr) {
        printTree(result);
        cout << endl;
    } else {
        cout << "Value not found in the BST." << endl;
    }
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
            break;
        }
        case 9: {
           TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    int k; 
    cout << "Input Tree: ";
    printInOrder(root); 
         cout<<endl;
           cout<<"Put an integer:";
         cin>>k;
    cout << "\nSum " << k << " found in the BST: " << (solution.findTarget(root, k) ? "true" : "false") << endl;

    delete root->left->left;
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

            break;
        }
        case 10: {
           vector<int> nums = {-10, -3, 0, 5, 9};

    cout << "Input: nums = [";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    TreeNode* bstRoot = solution.sortedArrayToBST(nums);

    cout << "Output: [";
    printInOrder(bstRoot);
    cout << "]" << endl;

            break;
        }
     case 11: {
         string input;
         cout << "Enter a binary number: ";
         cin >> input;
       vector<int> listValues;
      for (char ch : input) {
        if (ch == '0' || ch == '1') {
            listValues.push_back(ch - '0');
        }
    }
       ListNode* head = createLinkedList(listValues);
     
       cout << "Input: head = [";
       for (size_t i = 0; i < listValues.size(); ++i) {
           cout << listValues[i];
           if (i < listValues.size() - 1) cout << ",";
       }
       cout << "]" <<endl;
     
       int decimalValue = solution.getDecimalValue(head);
       cout << "Output: " << decimalValue << endl;
      break;
     }
     case 12:{
      ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
      cout << "Complete list before finding middle: ";
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
    ListNode* middle = solution.middleNode(head);
    cout << "Middle node is: " << middle->val << endl;
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
     break;
    }
     case 13: {
    // Krijon listën e lidhur
    vector<int> values;
    int numValues, val;
    cout << "Enter number of elements in linked list: ";
    cin >> numValues;
    cout << "Enter elements of linked list:\n";
    for (int i = 0; i < numValues; ++i) {
        cin >> val;
        values.push_back(val);
    }

    ListNode* head = createLinkedList(values);
    cout << "Original list: ";
    for (ListNode* curr = head; curr != nullptr; curr = curr->next) {
        cout << curr->val << " ";
    }
    cout << endl;

    // Thërret funksionin për të kthyer listën
    ListNode* reversedHead = solution.reverseList(head);
    cout << "Reversed list: ";
    for (ListNode* curr = reversedHead; curr != nullptr; curr = curr->next) {
        cout << curr->val << " ";
    }
    cout << endl;

    // Çliro memorien e listës së lidhur
    while (reversedHead != nullptr) {
        ListNode* temp = reversedHead;
        reversedHead = reversedHead->next;
        delete temp;
    }
    break;
}
   case 14: {
    int numNodes, nodeValue;
    cout << "Enter the number of nodes in the linked list: ";
    cin >> numNodes;
    if (numNodes == 0) {
        cout << "false" << endl;
        break;
    }

    vector<ListNode1*> nodes(numNodes);
    for (int i = 0; i < numNodes; ++i) {
        cin >> nodeValue;
        nodes[i] = new ListNode1(nodeValue);
        if (i > 0) {
            nodes[i - 1]->next1 = nodes[i];
        }
    }

    int cycleIndex;
    cout << "Enter the index of the node to create a cycle (-1 for no cycle): ";
    cin >> cycleIndex;
    if (cycleIndex != -1 && cycleIndex >= 0 && cycleIndex < numNodes) {
        nodes[numNodes - 1]->next1 = nodes[cycleIndex];
    }

    bool hasCycle = solution.hasCycle(nodes[0]);
    cout << (hasCycle ? "true" : "false") << endl;

    if (cycleIndex == -1) {
        for (ListNode1* node : nodes) {
            delete node;
        }
    } else {
        cout << "Manual cleanup required due to cycle." << endl;
    }
    break;
}

     case 15:{
      int n, value, valToRemove;

    cout << "Enter the number of nodes in the linked list: ";
    cin >> n;

    ListNode* head = nullptr;
    ListNode* current = nullptr;

    cout << "Enter the values of the nodes:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        ListNode* newNode = new ListNode(value);
        if (head == nullptr) {
            head = newNode;
            current = head;
        } else {
            current->next = newNode;
            current = current->next;
        }
    }

    cout << "Enter the value to remove: ";
    cin >> valToRemove;

    cout << "Original list: ";
    printList(head);

    head = solution.removeElements(head, valToRemove);

    cout << "Modified list after removing " << valToRemove << ": ";
    printList(head);

    // Çliroje listën e mbetur
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
      break;
     }
     case 16:{
      string s,t;
      cout<<"s=";
      cin>>s;
      cout<<endl;
      cout<<"t=";
      cin>>t;
      cout<<endl;
      cout << "Permutation difference: " << solution.findPermutationDifference(s, t) <<endl;
      break;
     }
     case 17:{
       int size;
    cout << "size: ";
    cin >> size;

    vector<int> nums(size);
    cout << "Set the elements: ";
    for (int i = 0; i < size; ++i) {
        cin >> nums[i];
    }

    // Thirr metoden numIdenticalPairs
    int result = solution.numIdenticalPairs(nums);

    // Shfaq rezultatin
    cout << "Number Of Good Pairs: " << result << endl;

      break;
     }
     case 18:{
      string jewels1;
    string stones1;
    cout<<"Jewels: ";
    cin>>jewels1;
    cout<<endl;
    cout<<"Stones: ";
    cin>>stones1;
    cout<<endl;
    int rezultati = solution.numJewelsInStones(jewels1, stones1);
    cout<<"Number of jewels "<<rezultati<<endl;
      break;
     }

        default:
            cout << "Invalid choice." << endl;
            break;
    }
    return 0;
}

