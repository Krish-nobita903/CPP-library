#include<bits/stdc++.h>
using namespace std;
#define int long long int

int power(int x, int y, int p)
{
 
    // Initialize answer
    int res = 1;
 
    // Check till the number becomes zero
    while (y > 0) {
 
        // If y is odd, multiply x with result
        if (y % 2 == 1)
            res = (res * x)%p;
 
        // y = y/2
        y = y >> 1;
 
        // Change x to x^2
        x = (x * x)%p;
    }
    return res % p;
}

int add(int a,int b,int p)
{
    return (a+b)%p;
}

int subtract(int a,int b,int p)
{
    return (a-b)%p;
}

int multiply(int a,int b,int p)
{
    return (a*b)%p;
}


void multiplyfib(int a[3][3], int b[3][3])
{
    // Creating an auxiliary matrix to store elements
    // of the multiplication matrix
    int mul[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mul[i][j] = 0;
            for (int k = 0; k < 3; k++)
                mul[i][j] += a[i][k]*b[k][j];
        }
    }
 
    // storing the multiplication result in a[][]
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            a[i][j] = mul[i][j];  // Updating our matrix
}
 
// Function to compute F raise to power n-2.
int powerfib(int F[3][3], int n)
{
    int M[3][3] = {{1,1,1}, {1,0,0}, {0,1,0}};
 
    // Multiply it with initial values i.e with
    // F(0) = 0, F(1) = 1, F(2) = 1
    if (n==1)
        return F[0][0] + F[0][1];
 
    powerfib(F, n/2);
 
    multiplyfib(F, F);
 
    if (n%2 != 0)
        multiplyfib(F, M);
 
    // Multiply it with initial values i.e with
    // F(0) = 0, F(1) = 1, F(2) = 1
    return F[0][0] + F[0][1] ;
}
 
// Return n'th term of a series defined using below
// recurrence relation.
// f(n) is defined as
//    f(n) = f(n-1) + f(n-2) + f(n-3), n>=3
// Base Cases :
//    f(0) = 0, f(1) = 1, f(2) = 1
int fibonacci(int n)
{
 
    int F[3][3] = {{1,1,1}, {1,0,0}, {0,1,0}} ;
 
    //Base cases
    if(n==0)
        return 0;
    if(n==1 || n==2)
        return 1;
 
    return powerfib(F, n-2);
}

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* current = head;
        ListNode *prev = NULL, *next = NULL;
 
        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        return head;
    }

void addEdgeU(vector<int>adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}    

void addEdgeD(vector<int>adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}    

