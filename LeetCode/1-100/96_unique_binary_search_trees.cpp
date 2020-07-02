// catalan number O(n)

class Solution
{
public:
    size_t ncr(int n, int r)
    {
        if (r > n - r)
            r = n - r;

        size_t res = 1;

        for (int i = 0; i < r; ++i)
        {
            res *= (n - i);
            res /= (i + 1);
        }

        return res;
    }

    int numTrees(int n)
    {
        // nth catalan number  :   2nCn/(n+1)
        return ncr(2 * n, n) / (n + 1);
    }
};

// dp solution  O(n^2)

class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> tab(n + 1, 0);
        tab[0] = 1;

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= i; ++j)
                tab[i] += tab[j - 1] * tab[i - j];
        }

        return tab[n];
    }
};

/**
    Let's consider the values 1 to N inclusive.
    
    Any value X can be our root node. Let's say we just have an empty tree
    so root = null. That is technically one unique subtree. Now let's say
    1 is our root node, X = 1, and N = 1. This is a super simple example.
    THe result for X = 1, when N = 1, is just 1 unique subtree.
    
    Now let's say X = 1, but now N = 2. How many unique subtrees exist now?
    Remember that X represents the root node value. For the left subtree
    you just have a null substree, which we said earlier is 1. SO the left subtree
    yeilds only 1 option. For the right subtree, you must place 2 there, so the number of
    options is also 1. 
    So when X = 1, answer is 1. But N = 2, so now we consider when X = 2.  THe left subtree
    would have node 1, so only 1 option. The right subtree is just null, so that is also
    1 option. We know that the result we want for N=2, is exactly 2. We can get this result
	by summing the result of X = 1 and X = 2 -> 1+1 = 2.
    
    We can generalize the num of options for left and right subtrees given X as...
        left = X-1, right = N-X
        T[X] = left * right
   
   Why multiply the left and right options? Because one subtree on the right
    can be used, but for the left subtree you can try every single unique subtree.
    Same occurs when you keep the left subtree the same, you can try every single 
    unique variation of the right subtree. 
    When we have a set of combinations, we multiply them to count all possible 
    variations between the two combinations.
    
    So based on these simple observations, we can assume that when N = 2: 
    numTrees(2) = numTrees(1) + numTrees(2) 
    numTrees(2) = 1 + 1 = 2
    
    But does this work for N = 3?
    When X = 1, N = 1 we get => 1 //Base Case Assumption
    
    When X = 1, N = 2 we get => 1
    When X = 2, N = 2 we get => 1 //Because only option for left and right subtrees -> 1*1
    
    When X = 1, N = 3 we get => 2 //Because only 1 option for left & 2 options for right -> 2*1
    When X = 2, N = 3 we get => 1
    When X = 3, N = 3 we get => 2
    
    For N = 2, we want te result to be 2, so we sum up the values we get X being 1 to N
    For N = 3, we want the result to be 5, so we sum up the values we get with X being 1 to N
    
    Now we can further generalize the solution as being...
    numTrees(N) = numTrees(1) + numTrees(2) + ... + numTrees(N);
    
    Let's denote each func. call in the above sum as -> numTrees(i)
    For any numTrees(i) where are simply trying X = 1, X = 2, ..., X = i
    So given N, just try every single value as X. And for every X, 
    calculate how many options are available on the left and right subtrees, given nodes 1 to X.
    So numTrees(i) is a subproblem where we cound all the unique trees given nodes 1 to i.
    i becomes the new N for these smaller subproblems.
    */