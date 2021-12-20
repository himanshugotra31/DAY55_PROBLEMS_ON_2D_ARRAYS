// Problem Description
// Given a matrix of integers A of size N x M and an integer B.

// In the given matrix every row and column is sorted in increasing order. Find and return the position of B in the matrix in the given form:
// If A[i][j] = B then return (i * 1009 + j)
// If B is not present return -1.

// Note 1: Rows are numbered from top to bottom and columns are numbered from left to right.
// Note 2: If there are multiple B in A then return the smallest value of i*1009 +j such that A[i][j]=B.


// Problem Constraints

// 1 <= N, M <= 1000
// -100000 <= A[i] <= 100000
// -100000 <= B <= 100000


// Input Format

// The first argument given is the integer matrix A.
// The second argument given is the integer B.


// Output Format

// Return the position of B and if it is not present in A return -1 instead.


// Example Input

// A = [ [1, 2, 3]
//           [4, 5, 6]
//           [7, 8, 9] ]
// B = 2


// Example Output

// 1011


// Example Explanation

// A[1][2]= 2
// 1*1009 + 2 =1011 


int Solution::solve(vector<vector<int> > &A, int B) 
{
    //Time Complexity for this code is O(N)
    long int n=A.size();                        //n=number of rows in given matrix
    long int m=A[0].size();                     //m=number of columns in given matrix
    long int i=0;                               //intialising i to keep a count on rows
    long int j=0;                               //intialising j to keep a count on columns
    for(long int k=0;k<n*m;k++)                 //we are running this loop from 0 to n*m to access every element
    {
        if(A[i][j]==B)
        {
            int ans;
            ans=((i+1)*1009)+(j+1);
            return ans;                         //if B is present then our loop stops and return ans;
        }
        if(j==m-1)                              //here, if j came to last column of a row then it will enter to this statement then this statement will make j=0 and make i+i+1
        {
            j=0;
            i+=1;
        }                                      //if the row is not completed then this statement will keep on adding j i.e. j=j+1                 
        else
        {
            j++;
        }
    }
    return -1;                                 //if B is not present then after traversing whole matrix our loop ends and return -1;

}
//Time Complexity for this code is O(N)