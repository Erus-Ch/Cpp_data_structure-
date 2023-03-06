//preOrder
    public void preOrder(int index) 
	{
        if (arr == null && arr.length == 0) {
            System.out.println("none");
            return;
        }
        System.out.println(arr[index]);
        if ((index * 2 + 1) < arr.length) {
            preOrder(index * 2 + 1);
        }
        if ((index * 2 + 2) < arr.length) {
            preOrder(index * 2 + 2);
        }

//midOrder
public void infixOrder(int index) 
	{
        if (arr == null && arr.length == 0) {
            System.out.println("none");
            return;
        }
        if ((index * 2 + 1) < arr.length) {
            infixOrder(index * 2 + 1);
        }
        if (index < arr.length) {
            System.out.print(arr[index] + "\t");
        }

        if ((index * 2 + 2) < arr.length) {
            infixOrder(index * 2 + 2);
        }
    }
//postOrder
public void postOrder(int index) 
	{
        if (arr == null && arr.length == 0) {
            System.out.println("none");
            return;
        }
        if ((index * 2 + 1) < arr.length) {
            postOrder(index * 2 + 1);
        }
        if ((index * 2 + 2) < arr.length) {
            postOrder(index * 2 + 2);
        }
        if (index < arr.length) {
            System.out.println(arr[index]+"\t");
        }
