//
// Created by br14n on 12/4/22.
//

#ifndef BST__BS_TREE_H
#define BST__BS_TREE_H
template <class T>
class node{
public:
    T info{};
    node<T>* llink = nullptr;
    node<T>* rlink = nullptr;

    node() = default;
    explicit node(const T & _info, node<T>* _llink = nullptr, node<T>* _rlink = nullptr):
            info(_info), llink(_llink), rlink(_rlink){}
};

template <class T>
class _bs_tree{
public:
    using t_node = node<T>*;
    t_node root = nullptr;

    _bs_tree() = default;
    bool is_empty() const { return root == nullptr;}
    bool insert(const T& value);
    void print_inorder() { secondary_inorder(root);}
    node<T>* leftchild(const T& value)  { return ptr_element(value)->llink;}
    node<T>* rightchild(const T& value) { return ptr_element(value)->rlink;}
    node<T>* parent(const T& value);
    bool __NULL(const T& value){ return ptr_element(value) == nullptr;}

private:
    node<T>* ptr_element(const T &value);
    node<T>* parent_simulate(const T& value);
    void secondary_inorder(t_node __Node);
};

template<class T>
node<T> *_bs_tree<T>::parent_simulate(const T &value) {
    auto current_node = root;
    auto trail_node = current_node;

    if(!is_empty()){
        while(current_node != nullptr){
            trail_node = current_node;
            if (current_node->info == value)
                break;
            else if (current_node->info > value)
                current_node = current_node->llink;
            else
                current_node = current_node->rlink;
        }
    }
    return  trail_node;
}

template<class T>
bool _bs_tree<T>::insert(const T &value) {
    auto new_node = new node<T>(value);
    auto current_node = parent_simulate(value);
    if(is_empty())
        root = new_node;
    else{
        if (current_node->info != value){
            (current_node->info > value) ?
                    current_node->llink = new_node :
                    current_node->rlink = new_node;
        }
        else return false;
    }
    return true;
}

template<class T>
void _bs_tree<T>::secondary_inorder(t_node __Node) {
    if(__Node != nullptr){
        secondary_inorder(__Node->llink);
        std::cout<< __Node->info <<" ";
        secondary_inorder(__Node->rlink);
    }

}

template<class T>
node<T> *_bs_tree<T>::ptr_element(const T &value) {
    auto current = root;
    if (!is_empty()){
        while(current != nullptr){
            if (current->info == value)
                return current;
            else if (current->info > value)
                current = current->llink;
            else
                current = current->rlink;
        }
    }
    return nullptr;
}

template<class T>
node<T> *_bs_tree<T>::parent(const T &value) {
    auto current_node = root;
    auto trail_node = current_node;

    if(!is_empty()){
        while((current_node->info != value) and (current_node != nullptr)){
            trail_node = current_node;

            (current_node->info > value)?
                    current_node = current_node->llink:
                    current_node = current_node->rlink;
        }
    }
    return  trail_node;
}


#endif //BST__BS_TREE_H
