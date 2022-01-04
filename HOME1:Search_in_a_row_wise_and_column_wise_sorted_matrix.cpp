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
    //Time Complexity for this code is O(N+M)
    int n=A.size();                         //n=number of rows in vector 'A'
    int m=A[0].size();                      //m=number of columns in vector 'A'
    int i=0,j=m-1;                          //here i=first row number  and j=last column number
    int ans=0;                              //ans=final answer
    int ans_i=0;                            //ans_i=row number where B is present
    int ans_j=0;                            //ans_j=column number where B is present
    while(i<=n-1 and j>=0)                  //here we are decreasing our search space on every itertion
    {
        if(ans_i!=0 and ans_j!=0 and B!=A[i][j])            //here, we are breaking the loop because, since we know our matrix is sorted row-wise and column wise, so by writing this line we are only traversing to the smallest and last index where B is present and after that our loop will break 
        {
            break;
        }
        if(A[i][j]>B)                                       //here, if A[i][j] is greater then the B then there is no need to traverse that COLUMN, since our matrix is sorted row-wise and column-wise, we will just move to the previous column
        {
            j--;
        }
        else if(A[i][j]<B)                                  //here, if A[i][j] is smaller then the B then there is no need to traverse that ROW, since our matrix is sorted row-wise and column-wise, we will just move to next row
        {
            i++;
        }
        else                                                //here, if A[i][j] is equal to B then we will make  ans_i=i+1 and ans_j=j+1 because our test case understands that matrix starts from [1][1], so we always add 1 to the answer and then we did j--, because we want to search B at lowest index, obviously we can't do i++, since we want to find B at lowest index, you can think about by taking an example of matrix on your notebook
        {
            ans_i=i+1;
            ans_j=j+1;
            j--;
        }
        
    }
    if(ans_i!=0 and ans_j!=0)                              //here, we are just returning answer in the form we were asked to
    {
        ans=(ans_i*1009)+ans_j;
    }
    else                                                  //if the element is not there, then ans=-1   
    {
        ans=-1;
    }
    return ans;

}
//Time Complexity for this code is O(N+M)
//NOTE-BOOK 2, PAGE 267-271