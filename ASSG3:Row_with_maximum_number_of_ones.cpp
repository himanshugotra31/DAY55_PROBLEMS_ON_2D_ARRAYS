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
    //here, in this question remember that the matrix is sorted row-wise and column wise
    //also see that the contraints range is from 0-1, so a[i][j] can either be 0 or 1
    //here, we want to return the Row with maximum number of ones
    //Here, we will be traversing from a[0][n-1] and check for 1 if a[i][j] is greater than 1 then we will skip that column and if a[i][j] is smaller than 1, then we will skip that row
    //if a[i][j]=1 then we will be skipping that column, since the matrix is sorted, so it can only have 1 at all other indexes of that column, since the constraints are 0 and 1 only
    //Time Complexity for this code is O(N+M)


    int n=A.size();                         //n=number of rows in vector 'A'
    int m=A[0].size();                      //m=number of columns in vector 'A'
    int i=0,j=m-1;                          //here i=first row number  and j=last column number
    int ans=-1;                             //ans=Row with maximum number of ones
    
    while(i<=n-1 and j>=0)                  //here we are decreasing our search space on every itertion
    {
        if(A[i][j]==1)                      //here, if A[i][j] is equal to 1 then is no need to traverse that COLUMN, since our matrix is sorted row-wise and column-wise, so all th elements in the rest of that column is equal to 1, we will just move to the previous column
        {
            j--;
            ans=i;
        }
        else if(A[i][j]<1)                  //here, if A[i][j] is smaller then the 1 then there is no need to traverse that ROW, since our matrix is sorted row-wise and column-wise, we will just move to next row
        {
            i++;
        } 
    }
    return ans;
}

