#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::push_back(const std::string& val){
  if(!tail_ || tail_->last == 10){
    Item* update = new Item();
    update->prev = tail_;
    if (tail_) {
        tail_->next = update;
    }
    tail_ = update;
    if (!head_) {
        head_ = tail_; 
    }
  }
  tail_->val[tail_->last++] = val;
  size_++;
}

void ULListStr::push_front(const std::string& val){
    if(!head_ || head_->first == 0){
        Item* update = new Item();
        update->next = head_;
        if(head_){
            head_->prev = update;
        }
        head_ = update;
        if(!tail_) tail_ = head_;
        head_->first = ARRSIZE;
        head_->last = ARRSIZE; 
    }
    head_->val[--head_->first] = val;
    size_++;
}

void ULListStr::pop_back(){
    if(!tail_){
        return;
    }
    tail_->last--;
    size_--;
    if(tail_->first == tail_->last){
        Item* temp = tail_;
        tail_ = tail_->prev;
        if(tail_){
            tail_->next = NULL;
        }
        else{
            head_ = NULL;
        }
        delete temp;
    }

}

void ULListStr::pop_front(){
    if(!head_){
        return;
    }
    head_->first++;
    size_--; 
    if(head_->first == head_->last){
        Item* temp = head_;
        head_ = head_->next;
        if(head_){
            head_->prev = NULL;
        }
        else{
            tail_ = NULL;
        }
        delete temp;
    }
}
std::string const & ULListStr::back() const{
    return tail_->val[tail_->last-1];
}

std::string const & ULListStr::front() const{
    return head_->val[head_->first];
}

 std::string* ULListStr::getValAtLoc(size_t loc) const{
     if(loc >= size_){
        return NULL;
     } 
     Item* curr = head_;
     size_t index = loc;
     while(curr){
        size_t count = curr->last - curr->first;
        if(index < count){
            return &curr->val[curr->first + index];
        }
        index -= count;
        curr = curr->next;
     }
     return NULL;
 }

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
