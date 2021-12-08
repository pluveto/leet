/**
 * Internal method to insert into a subtree.
 * x is the item to insert.
 * t is the node that roots the subtree.
 * Set the new root of the subtree.*/
void insert(const Comparable &x, BinaryNode *&t) {
  if (t == nullptr)
    t = new BinaryNode{x, nullptr, nullptr};
  else if (x < t->element)
    insert(x, t->left);
  else if (t->element < x)
    insert(x, t->right);
  else
    ; // Duplicate; do nothing
}
/**
 * Internal method to insert into a subtree.
 * x is the item to insert by moving.
 * t is the node that roots the subtree.
 * Set the new root of the subtree.
 */
void insert(Comparable &&x, BinaryNode *&t) {
  if (t == nullptr)
    t = new BinaryNode{std::move(x), nullptr, nullptr};
  else if (x < t->element)
    insert(std::move(x), t->left);
  else if (t->element < x)
    insert(std::move(x), t->right);
  else
    ; // Duplicate; do nothing
}

/**
 * Internal method to remove from a subtree.
 * x is the item to remove.
 * t is the node that roots the subtree.
 * Set the new root of the subtree.
 */
void remove(const Comparable &x, BinaryNode *&t) {
  if (t == nullptr)
    return; // Item not found; do nothing
  if (x < t->element)
    remove(x, t->left);
  else if (t->element < x)
    remove(x, t->right);
  else if (t->left != nullptr && t->right != nullptr) // Two children
  {
    t->element = findMin(t->right)->element;
    remove(t->element, t->right);
  } else {
    BinaryNode *oldNode = t;
    t = (t->left != nullptr) ? t->left : t->right;
    delete oldNode;
  }
}