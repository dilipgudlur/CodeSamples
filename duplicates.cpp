
/*Trick: it is easy to make an O(n) solution based on map, but below is a O(1) solution which is more challenging
Constraint: The input has to lie between 1 and n for a size of n items in the array
1 <= a[i] <= n
This solution is based on trying to place each item in the array at the index specified by the value a[i]
In below example, at index0, t is 2, so a[t-1] or a[1] is checked. If it is negative that means we have 
already manipulated that element, if it is still positive, we change the element to its negatuve form indictaing that its been
manipulated already. Now if a duplicate is found and we check the element at the index pointed to by the duplicate, it 
would already reflect the value as negative since its a duplicate.
*/
int firstDuplicate(std::vector<int> a) {

    /*Solution with O(1) space*/
    for(int i=0; i < a.size(); i++){
        int t = abs(a[i]);
        if(a[t-1] < 0)
            return t;
        a[t-1] = - a[t-1];
    }
    return -1;
}

int main()
{
    vector<int> a = {2,3,3,2};
    cout << "First duplicate is " << firstDuplicate(a) << endl;
    cout<< "array is now" << endl;
    for(int i = 0;i < a.size();i++) {
        cout << a[i] << endl;
    }
    return 0;
} 
