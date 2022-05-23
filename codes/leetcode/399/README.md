# 399

## Tips
`Union Find`

# SOP
1. Use the `Union Find` to find the relationship between nodes, and then save the values into parents table.
   - When initializing the table's value, we assume the second element of the equation has a value of 1, and the first element of the equation has a value of k, which is the input value.
2.  After setting up the table, we traverse the queries and use the `find` method to check if there is a relationship between queries and save the result in the answer vector.

