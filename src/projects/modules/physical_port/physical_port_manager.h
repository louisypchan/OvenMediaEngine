//==============================================================================
//
//  OvenMediaEngine
//
//  Created by Hyunjun Jang
//  Copyright (c) 2018 AirenSoft. All rights reserved.
//
//==============================================================================
#pragma once

#include <memory>

#include "physical_port.h"
#include "physical_port_observer.h"

#define DEFAULT_PHYSICAL_PORT_WORKER_COUNT 4

class PhysicalPortManager : public ov::Singleton<PhysicalPortManager>
{
public:
	friend class ov::Singleton<PhysicalPortManager>;

	virtual ~PhysicalPortManager();

	std::shared_ptr<PhysicalPort> CreatePort(ov::SocketType type, 
											const ov::SocketAddress &address, 
											int send_buffer_size = 0, 
											int recv_buffer_size = 0, 
											int worker_count = DEFAULT_PHYSICAL_PORT_WORKER_COUNT);

	bool DeletePort(std::shared_ptr<PhysicalPort> &port);

protected:
	PhysicalPortManager();

	std::map<std::pair<ov::SocketType, ov::SocketAddress>, std::shared_ptr<PhysicalPort>> _port_list;

	std::mutex _port_list_mutex;
};
