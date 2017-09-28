#include "HiveClient.h"


HiveClient::HiveClient(const char* server, const char* port):
			m_socket(new TSocket(server, boost::lexical_cast<int>(port))),
			m_transport(new TBufferedTransport(m_socket)),
			m_protocol(new TBinaryProtocol(m_transport)),
			m_client(m_protocol)
{
	m_isConnected = false;
}


HiveClient::~HiveClient()
{

}

bool HiveClient::HiveConnect()
{
	m_isConnected = false;
	try
	{
		m_transport->open();
		m_isConnected = true;
	}
	catch (const TException &tx)
	{
		std::cerr << "Error:" << tx.what() << std::endl;
	}
	return m_isConnected;
}

bool HiveClient::isHiveConnect()
{
	return m_isConnected;
}
