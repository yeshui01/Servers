/*
Copyright (c) 2008, 2014, Oracle and/or its affiliates. All rights reserved.

The MySQL Connector/C++ is licensed under the terms of the GPLv2
<http://www.gnu.org/licenses/old-licenses/gpl-2.0.html>, like most
MySQL Connectors. There are special exceptions to the terms and
conditions of the GPLv2 as it is applied to this software, see the
FLOSS License Exception
<http://www.mysql.com/about/legal/licensing/foss-exception.html>.

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published
by the Free Software Foundation; version 2 of the License.

This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin St, Fifth Floor, Boston, MA 02110-1301  USA
*/



#ifndef _MYSQL_CONNECTION_H_
#define _MYSQL_CONNECTION_H_

#include <cppconn/connection.h>
#include <boost/shared_ptr.hpp>
#include <boost/scoped_ptr.hpp>

namespace sql
{
namespace mysql
{

class MySQL_Savepoint : public sql::Savepoint
{
	sql::SQLString name;

public:
	MySQL_Savepoint(const sql::SQLString &savepoint);
	virtual ~MySQL_Savepoint() {}

	int getSavepointId();

	sql::SQLString getSavepointName();

private:
	/* Prevent use of these */
	MySQL_Savepoint(const MySQL_Savepoint &);
	void operator=(MySQL_Savepoint &);
};


class MySQL_DebugLogger;
struct MySQL_ConnectionData; /* PIMPL */
class MySQL_Statement;

namespace NativeAPI
{
class NativeConnectionWrapper;
}

class CPPCONN_PUBLIC_FUNC MySQL_Connection : public sql::Connection
{
	MySQL_Statement * createServiceStmt();

public:
	MySQL_Connection(Driver * _driver,
					::sql::mysql::NativeAPI::NativeConnectionWrapper & _proxy,
					const sql::SQLString& hostName,
					const sql::SQLString& userName,
					const sql::SQLString& password);

	MySQL_Connection(Driver * _driver, ::sql::mysql::NativeAPI::NativeConnectionWrapper & _proxy,
					std::map< sql::SQLString, sql::ConnectPropertyVal > & options);

	virtual ~MySQL_Connection();

	void clearWarnings();

	void close();

	void commit();

	sql::Statement * createStatement();

	sql::SQLString escapeString(const sql::SQLString &);

	bool getAutoCommit();

	sql::SQLString getCatalog();

	Driver *getDriver();

	sql::SQLString getSchema();

	sql::SQLString getClientInfo();

	void getClientOption(const sql::SQLString & optionName, void * optionValue);

	sql::SQLString getClientOption(const sql::SQLString & optionName);

	sql::DatabaseMetaData * getMetaData();

	enum_transaction_isolation getTransactionIsolation();

	const SQLWarning * getWarnings();

	bool isClosed();

	bool isReadOnly();

	bool isValid();

	bool reconnect();

	sql::SQLString nativeSQL(const sql::SQLString& sql);

	sql::PreparedStatement * prepareStatement(const sql::SQLString& sql);

	sql::PreparedStatement * prepareStatement(const sql::SQLString& sql, int autoGeneratedKeys);

	sql::PreparedStatement * prepareStatement(const sql::SQLString& sql, int columnIndexes[]);

	sql::PreparedStatement * prepareStatement(const sql::SQLString& sql, int resultSetType, int resultSetConcurrency);

	sql::PreparedStatement * prepareStatement(const sql::SQLString& sql, int resultSetType, int resultSetConcurrency, int resultSetHoldability);

	sql::PreparedStatement * prepareStatement(const sql::SQLString& sql, sql::SQLString columnNames[]);

	void releaseSavepoint(Savepoint * savepoint) ;

	void rollback();

	void rollback(Savepoint * savepoint);

	void setAutoCommit(bool autoCommit);

	void setCatalog(const sql::SQLString& catalog);

	void setSchema(const sql::SQLString& catalog);

	sql::Connection * setClientOption(const sql::SQLString & optionName, const void * optionValue);

	sql::Connection * setClientOption(const sql::SQLString & optionName, const sql::SQLString & optionValue);

	void setHoldability(int holdability);

	void setReadOnly(bool readOnly);

	sql::Savepoint * setSavepoint();

	sql::Savepoint * setSavepoint(const sql::SQLString& name);

	void setTransactionIsolation(enum_transaction_isolation level);

	virtual sql::SQLString getSessionVariable(const sql::SQLString & varname);

	virtual void setSessionVariable(const sql::SQLString & varname, const sql::SQLString & value);

	virtual void setSessionVariable(const sql::SQLString & varname, unsigned int value);

	virtual sql::SQLString getLastStatementInfo();

private:
	/* We do not really think this class has to be subclassed*/
	void checkClosed();
	void init(std::map< sql::SQLString, sql::ConnectPropertyVal > & properties);

	Driver * driver;
	boost::shared_ptr< NativeAPI::NativeConnectionWrapper > proxy;

	/* statement handle to execute queries initiated by driver. Perhaps it is
	   a good idea to move it to a separate helper class */
	boost::scoped_ptr< ::sql::mysql::MySQL_Statement > service;

	boost::scoped_ptr< ::sql::mysql::MySQL_ConnectionData > intern; /* pimpl */

	/* Prevent use of these */
	MySQL_Connection(const MySQL_Connection &);
	void operator=(MySQL_Connection &);
};

} /* namespace mysql */
} /* namespace sql */

#endif // _MYSQL_CONNECTION_H_

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
