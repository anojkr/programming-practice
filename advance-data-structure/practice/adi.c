void
deletedata (struct node *root, int d)
{
  front = 0;
  rear = 0;

  struct node *t1 = root;
  //pointer to key node t1
  while (t1)
    {
      if (t1->data == d)
	{
	  break;
	}
      if (t1->left)
	{
	  q[++rear] = t1->left;
	}
      if (t1->right)
	{
	  q[++rear] = t1->right;
	}
      t1 = q[++front];
    }
  front = 0;
  rear = 0;
  struct node *t4 = NULL;
  struct node *t2 = root;
  //pointer to last node t2
  while (t2)
    {
      if (t2->left)
	{
	  q[++rear] = t2->left;
	}
      if (t2->right)
	{
	  q[++rear] = t2->right;
	}
      t2 = q[++front];
    }

  //pointer to one previous node than the last node t3
  front = 0;
  rear = 0;
  struct node *t3 = root;
  while (t3)
    {
      if (t3->left)
	{
	  q[++rear] = t3->left;
	}
      if (t3->right)
	{
	  q[++rear] = t3->right;
	}
      t4 = q[++front];
      if (t4 == t2)
	{
	  break;
	}
      else
	{
	  t3 = q[++front];
	}
    }

  front = 0;
  rear = 0;
  t1->data = t2->data;
  if (t4->left == t2)
    {
      t4->left = NULL;
      free (t2);
    }
  if (t4->right == t2)
    {
      t4->right = NULL;
      free (t2);
    }
  front = 0;
  rear = 0;
}