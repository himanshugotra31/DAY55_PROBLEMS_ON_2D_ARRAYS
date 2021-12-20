// Problem Description

// Given a binary sorted matrix A of size N x N. Find the row with the maximum number of 1.

// NOTE:

//     If two rows have the maximum number of 1 then return the row which has a lower index.
//     Rows are numbered from top to bottom and columns are numbered from left to right.
//     Assume 0-based indexing.
//     Assume each row to be sorted by values.
//     Expected time complexity is O(rows).



// Problem Constraints

// 1 <= N <= 1000

// 0 <= A[i] <= 1



// Input Format

// The only argument given is the integer matrix A.


// Output Format

// Return the row with the maximum number of 1.


// Example Input

// Input 1:

//  A = [   [0, 1, 1]
//          [0, 0, 1]
//          [0, 1, 1]   ]

// Input 2:

//  A = [   [0, 0, 0, 0]
//          [0, 1, 1, 1]    ]



// Example Output

// Output 1:

//  0

// Output 2:

//  1



// Example Explanation

// Explanation 1:

//  Row 0 has maximum number of 1s.

// Explanation 2:

//  Row 1 has maximum number of 1s.


int Solution::solve(vector<vector<int> > &A) 
{

    //Time Complexity for this code is 0(N)
    int n=A.size();                         //n=number of rows and columns, since the matrix is n*n
    int count=0;                            //'count' will keep count number of 1 for every row
    int max_count=0;                        //'max_count' will store which row has maximum number of 1
    int i=0;                                //iterated to keep a count on number of rows
    int j=0;                                //iterated to keep a count on number of rows
    int ans=0;                              //it will store the value of which is storing most number of 1            
    
    for(int k=0;k<n*n;k++)                  //this loop will traverse our whole matrix
    {
        if(A[i][j]==1)                      //here, if A[i][j]==1 then it will add 1 to count
        {
            count+=1;
        }
        if(j==n-1)                          //here, if j came to last column of a row then it will enter to this statement
        {
            if(count>max_count)             //rest all the statements we can understand just by reading them
            {
                max_count=count;
                ans=i;
            }
            j=0;
            i+=1;
            count=0;
        }
        else
        {
            j++;
        }
    }
    return ans;
}

