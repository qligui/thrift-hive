#pragma once
#include <boost/lexical_cast.hpp>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>
#include "../gen-cpp/ThriftHiveMetastore.h"

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;
using namespace Apache::Hadoop::Hive;

class HiveClient
{
public:
	HiveClient(const char* hostname, const char* port);
	~HiveClient();
	bool HiveConnect();
	bool isHiveConnect();
private:
	boost::shared_ptr<TTransport> m_socket;
	boost::shared_ptr<TTransport> m_transport;
	boost::shared_ptr<TProtocol> m_protocol;
	ThriftHiveMetastoreClient m_client;
	bool m_isConnected;
};

