//Author: Aniruddh Kathiriya
//Assignment 9

#include <iostream>
#include <stdlib.h>
#include "bintree.h"
using namespace main_savitch_10;
binary_tree_node<int>* create_bst(){
	//Post Condition: Returns a unbalanced tree 
	binary_tree_node<int>* t1 = new binary_tree_node<int>(1);
	binary_tree_node<int>* t2 = new binary_tree_node<int>(2);
	binary_tree_node<int>* t3 = new binary_tree_node<int>(3);
	binary_tree_node<int>* t4 = new binary_tree_node<int>(4);
	binary_tree_node<int>* t5 = new binary_tree_node<int>(5);
	binary_tree_node<int>* t6 = new binary_tree_node<int>(6);
	binary_tree_node<int>* t7 = new binary_tree_node<int>(7);
	binary_tree_node<int>* t8 = new binary_tree_node<int>(8);
	binary_tree_node<int>* t9 = new binary_tree_node<int>(9);
	binary_tree_node<int>* t10 = new binary_tree_node<int>(10);
	binary_tree_node<int>* t11 = new binary_tree_node<int>(11);
	
	 t2->set_left(t1);
	t2->set_right(t3);
	t5->set_left(t4);
	t5->set_right(t6);
	t8->set_left(t7);
	t8->set_right(t9);
	t9->set_right(t11);
	t11->set_left(t10);
	
	t6->set_right(t8);
	t4->set_left(t2);
	
	return t5;
}
template <class T>
std::size_t treeheight(binary_tree_node<T>* tree){
	//Post condition: Returns a height of the tree + 1
	if(tree==NULL){
		return 0;
	}
	size_t heightLeft= 1+treeheight(tree->left());
	size_t heightRight= 1+treeheight(tree->right());
	
	if(heightLeft>heightRight){
		return heightLeft;
	}else{
		return heightRight;
	}
}
template <class Item>
void printD(Item data,size_t h){
	
	if(data != NULL)
		std::cout<<data<<" ";
	else
		std::cout<<"[NULL]"<<" ";
	
}

template <class Process, class BTNode>
void orderLevel(Process f, BTNode* tree,size_t height){
	//Post Condition: Process tree level by level, sends break line after each level, prints level number, would not display childrens of null node
	
	size_t h=0;
	if(tree==NULL){
			f(NULL,h);
			return;
	}
		
	std::queue<BTNode*> q;
	q.push(tree);
	while (1){
        // nodeSize =number of nodes at the current level.
        size_t nodeSize = q.size();
		if (nodeSize == 0)
            break;
		std::cout<<"Level "<<h<<": ";
		while(nodeSize>0){
			BTNode* temp=q.front();
			if(temp!=NULL){
				f(q.front()->data(),h);
			}else{
				f(NULL,h);
			}
			q.pop();
			
			if(temp!=NULL && (temp->left()!=NULL || temp->right()!=NULL)){
				if(temp->left()!=NULL){
					q.push(temp->left());
				}else{
					q.push(NULL);
				}
				if(temp->right()!=NULL){
					q.push(temp->right());
				}else{
					q.push(NULL);
				}
			}else if(temp!=NULL && temp->left()==NULL && temp->right()==NULL && h<height-1){
				//if both children are null but the level still has 1 node not null
				q.push(NULL);
				q.push(NULL);
			}
			nodeSize--;
		}
		std::cout << std::endl;
		h++;
	}
}
int main(){
	binary_tree_node<int> *tree=create_bst();
	orderLevel(printD<int>,tree,treeheight(tree));
	std::cout<<std::endl;
	print(tree,4);
	
	
	return 0;
}