/******************************************
 * Copyright 2016/05 - 2021/07 
 * file	  :
 * author : tianyiheng
 * date   : 2016-05-19
 * brief  :
 *******************************************/

#include "pack_owner.h"

namespace tyh {

bool PackBufferOwner::PushPackBuffer(PackBufferPtr pack_buff_ptr) {
  //boost::unique_lock<boost::mutex> scoped_lock(mutex_);
  //pack_buffer_queue_.push_back(pack_buff_ptr);
#if 0	
	if (queue_write_index_ > 0)
	{
		queue_write_index_ %= pack_buffer_queue_.size();											
	}
	pack_buffer_queue_[queue_write_index_++] = pack_buff_ptr;	
#endif
  return true;
}

bool PackBufferOwner::PushPackBuffer(PackBufferCell * pack_buffer_pt)
{
	if (queue_write_index_ > 0)
	{
		queue_write_index_ %= pack_buffer_queue_.size();											
	}
	pack_buffer_queue_[queue_write_index_++] = pack_buffer_pt;	
  return true;
}


bool PackBufferOwner::IsEmpty() {
	/*
  boost::unique_lock<boost::mutex> scoped_lock(mutex_);
	
  return pack_buffer_queue_.empty();
	*/
	return queue_read_index_ == queue_write_index_;
}

bool PackBufferOwner::PopPackBuffer(PackBufferPtr & r_ptr_) {
  bool ret = false;
#if 0
	/*
  boost::unique_lock<boost::mutex> scoped_lock(mutex_);
  if (!pack_buffer_queue_.empty()) {
	r_ptr_ = pack_buffer_queue_.front();
	pack_buffer_queue_.pop_front();
	ret = true;
  }
	*/
	if (queue_read_index_ > 0)
	{
		queue_read_index_ %= pack_buffer_queue_.size();
	}
	if (queue_read_index_ == queue_write_index_)
		return false;
	r_ptr_ = pack_buffer_queue_[queue_read_index_];
	pack_buffer_queue_[queue_read_index_++].reset();
	//queue_read_index_ %= pack_buffer_queue_.size();
#endif
	ret = true;
  return ret;
}

PackBufferCell * PackBufferOwner::PopPackBuffer()
{
	if (queue_read_index_ > 0)
	{
		queue_read_index_ %= pack_buffer_queue_.size();
	}
	if (queue_read_index_ == queue_write_index_)
		return nullptr;
	PackBufferCell * ret_pt = pack_buffer_queue_[queue_read_index_++];
	
	return ret_pt;
}

}	// namespace tyh
