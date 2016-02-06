#include "llistint.h"
#include <cstdlib>
#include <stdexcept>

LListInt::LListInt()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

LListInt::~LListInt()
{
  clear();
}

bool LListInt::empty() const
{
  return size_ == 0;
}

int LListInt::size() const
{
  return size_;
}

/**
 * Complete the following function
 */
void LListInt::insert(int loc, const int& val)
{
  if(size_>0){
    if(loc>0&&loc<size_){
      Item *nitem = new Item();
      Item *temp = getNodeAt(loc);
      nitem->val = val;
      nitem->prev = temp->prev; 
      temp->prev->next=nitem;
      temp->prev = nitem;
      nitem->next=temp;
      size_=size_+1;
    }
    else if(loc ==size_){
      Item *nitem = new Item();
      nitem->val = val;
      tail_->next=nitem;
      nitem->prev = tail_;
      nitem->next = NULL;
      tail_=nitem;
      size_=size_+1;

    }
    else if(loc == 0){
      Item *nitem = new Item();
      Item *temp = getNodeAt(0);
      nitem->val=val;
      temp->prev=nitem;
      nitem->next=temp;
      nitem->prev=NULL;
      head_=nitem;
      size_=size_+1;

    }
  }
  else{
      Item *nitem = new Item();
      nitem->val=val;
      nitem->prev=NULL;
      nitem->next=NULL;
      head_=nitem;
      tail_=nitem;
      size_=size_+1;
  }
}

/**
 * Complete the following function
 */
void LListInt::remove(int loc)
{
  int s = size_-1;
  if(size_>0){
    if(loc>0&&loc<(s)){
      Item *temp = getNodeAt(loc);
      temp->next->prev=temp->prev;
      temp->prev->next=temp->next;
      delete temp;
      size_=size_-1;
    }
    else if(loc == s){
      Item *temp = getNodeAt(loc);
      tail_=temp->prev;
      temp->prev->next=NULL;
      delete temp;
      size_=size_-1;
    }
    else if(loc == 0){
      Item *temp = getNodeAt(loc);
      head_=temp->next;
      temp->next->prev=NULL;
      delete temp;
      size_=size_-1;
    }
  }


}

void LListInt::set(int loc, const int& val)
{
  Item *temp = getNodeAt(loc);
  temp->val = val;
}

int& LListInt::get(int loc)
{
  if(loc < 0 || loc >= size_){
    throw std::invalid_argument("bad location");
  }
  Item *temp = getNodeAt(loc);
  return temp->val;
}

int const & LListInt::get(int loc) const
{
  if(loc < 0 || loc >= size_){
    throw std::invalid_argument("bad location");
  }
  Item *temp = getNodeAt(loc);
  return temp->val;
}

void LListInt::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}


/**
 * Complete the following function
 */
LListInt::Item* LListInt::getNodeAt(int loc) const
{
  Item* locat = head_;
  for(int i=0;i<loc;i++){
    locat=locat->next;
  }

  return locat;

}
