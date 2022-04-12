//
// Created by user on 22/10/21.
//
#ifndef AVLTREEV2_AVL_BTREE_H
#define AVLTREEV2_AVL_BTREE_H
template <class T>
class node{
public:
    T info{};
    node<T>* llink = nullptr;
    node<T>* rlink = nullptr;
    int bf = 0;

    node() = default;
    explicit node(const T &_info, node<T>* _llink = nullptr, node<T>* _rlink = nullptr, int _height = 0):
            info(_info), llink(_llink), rlink(_rlink), bf(_height){}
};

template <class T>
class avl_btree{
public:
    using t_node = node<T>*;
    t_node root = nullptr;


public:
    avl_btree() = default;
    bool empty() const{ return root == nullptr;}
    void print_inorder(){secondary_inorder(root); std::cout<<"\n";}
    void insert(const T &value){ secondary_insert(value, root);}
    void _delete(const T &deletevalue){ root = secondary_delete(deletevalue, root);}
    int height() { return  secondary_height(root);}
    node<T>* lmost_leaf() {return secondary_lmost_leaf(root);}


private:
    int balance_factor(t_node &__Node_root);
    node<T>* secondary_insert(const T &value, t_node &__Node_root);
    node<T>* secondary_delete(const T& deletevalue, t_node &__Node_root);
    void secondary_inorder(t_node __Node_root);
    int b_height(t_node _Node_root); //unused function
    int secondary_height(t_node __Node_root);
    node<T>*  secondary_lmost_leaf(t_node __Node_root);
    node<T>* left(t_node &__Node_root);
    node<T>* right(t_node &__Node_root);
    node<T>* ll(t_node &__Node_root);
    node<T>* lr(t_node &__Node_root);
    node<T>* rr(t_node &__Node_root);
    node<T>* rl(t_node &__Node_root);
};


template<class T>
int avl_btree<T>::balance_factor(avl_btree::t_node &__Node_root) {
    //returns the balance factor of node n
    auto hl_tree = secondary_height(__Node_root->llink),
         hr_tree = secondary_height(__Node_root->rlink);

    //Increase in the height of the left subtree, return 2 in (unbalanced) case
    if (hl_tree > hr_tree)
        return (hl_tree == (hr_tree + 1))? 1: 2;
    //Increase in the height of the right subtree, return -2 in (unbalanced) case
    else if (hr_tree > hl_tree)
        return (hr_tree == (hl_tree + 1))? -1: -2;
    //(balance) case
    else return 0;
}

template<class T>
int avl_btree<T>::b_height(avl_btree::t_node __Node_root){
    return (__Node_root == nullptr)? -1:
           1 + std::max(b_height(__Node_root->llink), b_height(__Node_root->rlink));
}

template<class T>
void avl_btree<T>::secondary_inorder(avl_btree::t_node __Node_root) {
    if(__Node_root != nullptr){
        secondary_inorder(__Node_root->llink);
        std::cout << __Node_root->info << "{" << __Node_root->bf << "} ";
        secondary_inorder(__Node_root->rlink);
    }
}

template<class T>
node<T>* avl_btree<T>::left(avl_btree::t_node &__Node_root) {
    auto p = __Node_root->rlink;
    __Node_root->rlink = p->llink;
    p->llink = __Node_root;
    __Node_root->bf = balance_factor(__Node_root);
    p->bf = balance_factor(p);
    return p;
}

template<class T>
node<T>* avl_btree<T>::right(avl_btree::t_node &__Node_root) {
    auto p = __Node_root->llink;
    __Node_root->llink = p->rlink;
    p->rlink = __Node_root;
    __Node_root->bf = balance_factor(__Node_root);
    p->bf = balance_factor(p);
    return p;
}

template<class T>
node<T>* avl_btree<T>::ll(avl_btree::t_node &__Node_root) {
    //Rotate to right
    __Node_root = right(__Node_root);
    return __Node_root;
}

template<class T>
node<T>* avl_btree<T>::rr(avl_btree::t_node &__Node_root) {
    //Rotate to left
    __Node_root = left(__Node_root);
    return  __Node_root;
}

template<class T>
node<T>* avl_btree<T>::lr(avl_btree::t_node &__Node_root) {
    __Node_root->llink = left(__Node_root->llink);
    __Node_root = right(__Node_root);
    return __Node_root;
}

template<class T>
node<T>* avl_btree<T>::rl(avl_btree::t_node &__Node_root) {
    __Node_root->rlink = right(__Node_root->rlink);
    __Node_root = left(__Node_root);
    return  __Node_root;
}

template<class T>
node<T>* avl_btree<T>::secondary_insert(const T &value, avl_btree::t_node  &__Node_root) {

    if(__Node_root == nullptr)
        __Node_root = new node<T>(value);
    else{
        if (__Node_root->info > value){
            __Node_root->llink = secondary_insert(value, __Node_root->llink);
            if(balance_factor(__Node_root) == 2)
                (value < __Node_root->llink->info)?
                        __Node_root = ll(__Node_root):
                        __Node_root = lr(__Node_root);
        }
        else if(__Node_root->info < value){
            __Node_root->rlink = secondary_insert(value, __Node_root->rlink);
            if(balance_factor(__Node_root) == -2)
                (value > __Node_root->rlink->info)?
                        __Node_root = rr(__Node_root):
                        __Node_root = rl(__Node_root);
        }
        else
            std::cerr<< "invalid input: Not allow duplicate value. \n";
    }
    __Node_root->bf = balance_factor(__Node_root);
    return  __Node_root;
}

template<class T>
node<T> *avl_btree<T>::secondary_delete(const T &deletevalue, avl_btree::t_node &__Node_root) {
    if(__Node_root != nullptr){
        if (__Node_root->info > deletevalue){
            __Node_root->llink = secondary_delete(deletevalue, __Node_root->llink);
            if (balance_factor(__Node_root) == -2)
                (balance_factor(__Node_root->rlink) <= 0)?
                        __Node_root = rr(__Node_root):
                        __Node_root = rl(__Node_root);
        }
        else if (__Node_root->info < deletevalue){
            __Node_root->rlink = secondary_delete(deletevalue, __Node_root->rlink);
            if (balance_factor(__Node_root) == 2)
                (balance_factor(__Node_root->llink) >= 0)?
                        __Node_root = ll(__Node_root):
                        __Node_root = lr(__Node_root);
        }
        else{
            if(__Node_root->rlink == nullptr)
                return __Node_root->llink;

            else{
                auto temp = __Node_root->rlink;
                while(temp->llink != nullptr)
                    temp = temp->llink;
                __Node_root->info = temp->info;
                __Node_root->rlink = secondary_delete(temp->info, __Node_root->rlink);
                if (balance_factor(__Node_root) == 2)
                    (balance_factor(__Node_root->llink) >= 0)?
                            __Node_root = ll(__Node_root):
                            __Node_root = lr(__Node_root);
            }
        }
    }
    else return nullptr;
    __Node_root->bf = balance_factor(__Node_root);
    return __Node_root;
}

template<class T>
int avl_btree<T>::secondary_height(avl_btree::t_node __Node_root){
    if (__Node_root == nullptr)
        return -1;
    else if(__Node_root->bf == 1)
        return  1 + secondary_height(__Node_root->llink);
    else
        return  1 + secondary_height(__Node_root->rlink);
}

template<class T>
node<T> *avl_btree<T>::secondary_lmost_leaf(avl_btree::t_node __Node_root) {
    t_node temp = nullptr;
    for(auto i = __Node_root; i != nullptr; i = i->llink)
        temp = i;
    return temp;
}

#endif //AVLTREEV2_AVL_BTREE_H
