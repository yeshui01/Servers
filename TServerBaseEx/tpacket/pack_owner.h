/******************************************
 * Copyright (C) 2016/05 - 2021/07 
 * file	  :
 * author : tianyiheng
 * date   : 2016-05-09
 * brief  :
 *******************************************/

#ifndef __TYH_PACK_OWNER_H__
#define __TYH_PACK_OWNER_H__

#include <cassert>
#include <memory>
#include <deque>

#include "tbase/ttypedef.h"
#include "tpacket/base_pack.h"
#include "tbase/nocopyable.h"
#include "boost/shared_ptr.hpp"
#include "boost/thread/mutex.hpp"


namespace tyh {

//typedef boost::shared_ptr < PackBufferCell< NORMAL_PACK_BUFFER_SIZE > > PackBufferPtr;
typedef boost::shared_ptr < PackBufferCell > PackBufferPtr;
//typedef std::deque< PackBufferPtr > PacketBufferQueue;
//typedef std::vector< PackBufferPtr > PacketBufferQueue;
typedef std::vector< PackBufferCell* > PacketBufferQueue;

#define DEFAULT_PACK_QUEUE_SIZE (2000)

class PackBufferOwner : public Nocopyable {
public:
  PackBufferOwner() 
	{
		// 初始化数据包队列最大空间
		pack_buffer_queue_.resize(DEFAULT_PACK_QUEUE_SIZE);		
	}
  ~PackBufferOwner() {}
 
public:
	// do not use
  bool PushPackBuffer(PackBufferPtr pack_buff_ptr);
	// do not use
  bool PopPackBuffer(PackBufferPtr & r_ptr_);

  bool IsEmpty();
	bool PushPackBuffer(PackBufferCell * pack_buffer_pt);
	PackBufferCell * PopPackBuffer();
protected:
  PacketBufferQueue pack_buffer_queue_;
	
private:
  //boost::mutex mutex_;
	// 改用循环队列
	size_t queue_read_index_ = 0;	
	size_t queue_write_index_ = 0;	
};


} // namespace tyh

#endif	// __TYH_PACK_OWNER_H__
